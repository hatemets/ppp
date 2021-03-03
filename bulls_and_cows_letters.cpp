#include "std_lib_facilities.h"

int main () {
    try {
        vector <char> vals = {'a', 'b', 'c', 'd'};
        vector <char> guesses;
        string guess;
        int bulls, cows = 0;

        bool correct = false;

        while (!correct) {
            bulls = 0;
            cows = 0;
            cout << "guess the letters: ";
            cin >> guess;
            
            if (guess.length() != 4) error("there must be 4 letters");

            for (int i = 0; i < 4; ++i) {
                bool cow = false;

                if (guess[i] == vals[i]) ++bulls;
                else {
                    for (char c : vals)
                        if (guess[i] == c) cow = true;
                    if (cow) ++cows;
                }
            }

            /* for (char c : guesses) cout << c << endl; */
            if (bulls == 4) correct = true;
            else cout << "bulls: " << bulls << "\ncows: " << cows << endl;
        }

        cout << "Correct answer, good job!" << endl;

        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch (...) {
        cerr << "unknown exception" << endl;
    }
}
