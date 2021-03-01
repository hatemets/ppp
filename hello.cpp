#include "std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        Token (char ch) : kind(ch), value(0) {}
        Token (char ch, double v) : kind(ch), value(v) {}
};

Token get_token () {
    char c;
    cin >> c;

    /* cout << "char: " << c << endl; */

    switch (c) {
        case ';':
            return Token (';'); // quit
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token (c);
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            cin.putback(c);
            double val;
            cin >> val;
            return Token ('8', val);
        default:
            error("Bad token");
    }
}

double expression();
double term();

double primary () {
    // num
    Token t = get_token();

    /* cout << "num: " << t.kind << ", " << t.value << endl; */

    switch (t.kind) {
        case '(':
            {
                double d = expression(); // "(" exp ")"
                t = get_token();
                if (t.kind != ')') error("')' expected");
                return d;
            }
        case '8':
            return t.value;
        default:
            error("enter a primary");
    }
}

double term () {
    // prim, prim * term, prim / term
    double left = primary();
    Token t = get_token();

    while (true) {
        /* cout << "term: " << t.kind << ", " << t.value << endl; */
        switch (t.kind) {
            case '*': 
                {
                    left *= primary();
                    t = get_token();
                    if (t.kind == ';' || t.kind == '-' || t.kind == '+' || t.kind == ')') cin.putback(t.kind);
                    if (t.kind != '*' && t.kind != '/') return left;
                    break;
                }
            case '/':
                {
                    double d = primary();
                    if (d == 0) error("division by zero");
                    left /= d;
                    t = get_token();
                    if (t.kind == ';' || t.kind == '-' || t.kind == '+') cin.putback(t.kind);
                    if (t.kind != '*' && t.kind != '/') return left;
                    break;
                }
            case '8':
                cin.putback(t.value);
                break;
            default:
                cin.putback(t.kind);
                return left;
        }
    }
}

double expression () {
    // term, exp + term, exp - term
    double left = term();
    Token t = get_token();

    /* cout << "exp: " << t.kind << ", " << t.value << endl; */
    
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = get_token();
                if (t.kind == ';') return left;
                else if (t.kind == ')') {
                    cin.putback(t.kind);
                    return left;
                }
                break;
            case '-':
                left -= term();
                t = get_token();
                if (t.kind == ';') return left;
                else if (t.kind == ')') {
                    cin.putback(t.kind);
                    return left;
                }
                break;
            case ')':
                cin.putback(t.kind);
                return left;
            case '8':
                cin.putback(t.value);
                return left;
            case ';':
                return left;
            default:
                error("unknown token kind value in expression");
        }
    }
};

int main () {
    try {
        while (cin) {
            cout << expression() << endl;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
