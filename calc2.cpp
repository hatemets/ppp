#include "std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        Token(char ch) : kind(ch), value(0) { }
        Token(char ch, double val) : kind(ch), value(val) { }
};

class Token_stream {
    private:
        bool full;
        Token buffer;
    public:
        Token_stream () : full(false), buffer(0) {}
        Token get();
        void putback(Token);
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full) {
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
        case ';':
        case 'q':
        case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': case '!':
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token('8', val);
        }
        default:
            error("Bad token");
        }
}

Token_stream ts;

double expression();

double factorial (int num) {
    if (num < 0) error("negative value for factorial");
    else if (num == 0) return 1;
    else {
        double sum = 1;
        for (num; num > 1; --num) sum *= num;
        return sum;
    }
}

double primary()
{
    Token t = ts.get();

    switch (t.kind) {
        case '(':
            {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
        case '{':
            {
                double d = expression();
                t = ts.get();
                if (t.kind != '}') error("'}' expected");
                return d;
            }
        case '8':
            {
                int n = t.value;
                t = ts.get();
                if (t.kind == '!') return factorial(n);
                else ts.putback(t);
                return n;
            }
        default:
            error("primary expected");
        }
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
            }
    }
}

double expression()
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main() {
    try {
        cout << "welcome to calculator V2.0!\nYou can use *, /, +, - and ! operators.\nType ';' to show the result and 'q' to quit\n";
        double val = 0;

        while (cin) {
            Token t = ts.get();
            if (t.kind == 'q') break;
            if (t.kind == ';')
                cout << "ans: " << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
