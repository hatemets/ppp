#include "std_lib_facilities.h"

const char constant = 'c';
const char help = 'h';
const char let = 'l';
const char name = 'a';
const char number = '8';
const char power = 'p';
const char print = ';';
const char quit = 'q';
const char root = 'r';
const string prompt = "> ";
const string result = "= "; 

struct Variable {
    string name;
    double value;
    char type;
    Variable(string n, double v, char t) : name(n), value(v), type(t) { }
};

class Symbol_table {
    private:
        vector <Variable> var_table;
    public:
        void add_var (string, double, char);
        void set_value(string, double);
        double get_value(string);
        bool is_declared(string);
};

void Symbol_table::add_var (string var_name, double value, char type) {
    var_table.push_back(Variable(var_name, value, type));
}

void Symbol_table::set_value (string s, double d)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
            if (var_table[i].type == constant) error("set: reassigning a constant");
            var_table[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

double Symbol_table::get_value (string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined name ", s);
}

bool Symbol_table::is_declared (string s) {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return true;
    return false;
}

Symbol_table sym_table;

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) : kind(ch), value(0) { }
    Token(char ch, double val) : kind(ch), value(val) { }
    Token(char ch, string s) : kind(ch), name(s) { }
};

class Token_stream {
    private:
        bool full;
        Token buffer;
    public:
        Token_stream() : full(false), buffer(0) { }
        Token_stream(istream&);

        Token get();
        void unget(Token t) { buffer = t; full = true; }
        void ignore(char);
};

Token Token_stream::get()
{
    if (full) { full = false; return buffer; }
    char ch;
    cin.get(ch);

    if (ch == '\n') return Token(print);
    cin.unget();
    cin >> ch;

    switch (tolower(ch)) {
        case quit:
        case print:
        case '(':
        case ',':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                cin.unget(); // put the value back and get the full number
                double val;
                cin >> val;
                return Token(number, val);
            }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // add only nums, letters and underscores 
                cin.unget();
                if (s == "exit" || s == "quit") return Token(quit);
                if (s == "let") return Token(let);
                if (s == "help") return Token(help);
                if (s == "sqrt") return Token(root);
                if (s == "pow") return Token(power); 
                if (s == "const") return Token(constant);
                return Token(name, s);
            }
            error("Bad token");
    }
}

// remove everything up to char c
void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin >> ch) if (ch == c) return;
    return;
}

double expression(Token_stream& ts);

double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
        case root:
            {
                t = ts.get();
                if (t.kind != '(') error("( expected for function");
                double d = expression(ts);
                if (d < 0) error("negative value for sqrt");
                t = ts.get();
                if (t.kind != ')') error(") expected for function");
                return sqrt(d);
            }
        case power:
            {
                t = ts.get();
                if (t.kind != '(') error("( expected for function");
                double d = expression(ts);
                t = ts.get();
                if (t.kind != ',') error("comma expected");
                double e = expression(ts);
                t = ts.get();
                if (t.kind != ')') error(") expected for function");
                return pow(d, e); // returns the value inside the parentheses
            }
        case '(':
            {
                double d = expression(ts);
                t = ts.get();
                if (t.kind != ')') error("'(' expected");
                return d;
            }
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        case number:
            return t.value;
        case name:
            {
                string var_name = t.name;
                t = ts.get();
                if (t.kind == '=') {
                    double d = expression(ts);
                    sym_table.set_value(var_name, d);
                    return d;
                } 
                ts.unget(t);
                return sym_table.get_value(var_name);
            }
        default:
            error("primary expected");
    }
}

double term(Token_stream& ts)
{
    double left = primary(ts);

    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '*':
                left *= primary(ts);
                break;
            case '/':
                {
                    double d = primary(ts);
                    if (d == 0) error("divide by zero");
                    left /= d;
                    break;
                }
            default:
                ts.unget(t);
                return left;
        }
    }
}

double expression(Token_stream& ts)
{
    double left = term(ts);
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '+':
                left += term(ts);
                break;
            case '-':
                left -= term(ts);
                break;
            default:
                if (t.kind == '(') error("non-permitted symbol");
                ts.unget(t);
                return left;
        }
    }
}

double declaration(char type, Token_stream& ts)
{
    Token t = ts.get();
    if (t.kind != 'a') error("name expected in declaration");

    string name = t.name;
    if (sym_table.is_declared(name)) error(name, " declared twice");

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);

    double d = expression(ts);

    sym_table.add_var(name, d, type);
    return d;
}

double statement(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
        case constant:
            return declaration(t.kind, ts);
        default:
            {
                ts.unget(t);
                double ans = expression(ts);
                return ans;
            }
    }
}

void clean_up_mess(Token_stream& ts)
{
    ts.ignore(print);
}

void display_help () {
    cout << "This is the user manual for the application." << endl;
    cout << "Commands:\n\";\" prints the value\n\"q\" or \"quit\" exits the program" << endl;
    cout << "Square root: sqrt(a)\nN to the power of e: pow(n, e)" << endl; 
    cout << "Declare a variable: let var = value\nDeclare a constant: const con = value" << endl; 
    return;
}

void calculate(Token_stream& ts)
{
    while (true)
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get(); 
            if (t.kind == quit) return;
            if (t.kind == help) {
                display_help(); 
                continue;
            }
            ts.unget(t);
            double ans = statement(ts);
            cout << result << ans << endl;
        }
    catch (runtime_error& e) {
        cerr << "error: " << e.what() << endl;
        clean_up_mess(ts);
    }
}

int main() {
    try {
        Token_stream t_stream;
        sym_table.add_var("pi", 3.14159, constant);
        calculate(t_stream);
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}

