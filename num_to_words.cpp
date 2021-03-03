#include "std_lib_facilities.h"

int main () {
    try {
        int num = 0;
        int ones, tens, hundreds, thousands = 0;
        cout << "enter a value: ";
        cin >> num;
        
        if (num > 9999) error("number is out of range");
        else if (num < 0) error("positive numbers only");

        string o;
        ones = num % 10;
        if (ones == 1) o = "one";
        else if (ones > 1) o = "ones";

        cout << num << " is ";

        string t;
        if (num > 9) {
            tens = (num % 100 - ones) / 10;
            if (tens == 1) t = "ten";
            else t = "tens";
        }

            string h;
        if (num > 99) {
            hundreds = (num % 1000 - (10 * tens + ones)) / 100;
            if (hundreds == 1) h = "hundred";
            else h = "hundreds";
        } 

        string tt;
        if (num > 999) {
            thousands = (num - (100 * hundreds + 10 * tens + ones)) / 1000;
            if (thousands == 1) tt = "thousand";
            else tt = "thousands";
            
        } 

        if (num > 999) cout << thousands << " " << tt << " ";
        if (num > 99) cout << hundreds << " " << h << " ";
        if (num > 9) cout << tens << " " << t << " ";

        cout << ones << " " << o << " ";

        cout << endl;

        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch (...) {
        cerr << "unknown exception" << endl;
    }
}
