#include "std_lib_facilities.h"

bool is_correct (string word, vector <string> list) {
    for (string w : list)
        if (word == w) return true;
    return false;
}

class Adder {
    public:
        Adder ();
        int i = 0;
        bool is_okay = true;
        void add ();
};

void Adder::add () {
    ++i;
}

bool clause (vector <string> parts) {
    vector <string> verbs = {"flies", "walks", "runs"};
    vector <string> nouns = {"bird", "dog", "man", "cat"};
    vector <string> articles = {"a", "the"};

    if (parts.size() != 3) error("size of parts is not 3");
    for (int i = 0; i < parts.size(); ++i) {
        switch (i) {
            case 0:
                if (is_correct(parts[i], articles) == false) return false;
                break;
            case 1:
                if (is_correct(parts[i], nouns) == false) return false;
                break;
            case 2:
                if (is_correct(parts[i], verbs) == false) return false;
                break;
        }
    }
    return true;
}

bool sentence (vector <string> words) {
    // part or part + conj + part
    vector <string> conjunctions = {"and", "but"};
    vector <string> clause_parts;
    if (words.size() % 4 != 0) return false;
    else if (words.size() == 4)
    {
        for (int i = 0; i < 3; ++i) clause_parts.push_back(words[i]); 
        bool clause_okay = clause(clause_parts);
        if (!clause_okay) return false;
    }
    else if (words.size() > 4)
    {
        int counter = 0;
        for (int i = words.size() - 5; i > 2; i -= 4) {
            if (!is_correct(words[i], conjunctions)) return false;

            if (words[i] == "but") {
                ++counter;
                if (counter > 1) return false;
            }
        }

        for (int j = 0; j < words.size() / 4; ++j) {
            for (int c = 0; c < 3; ++c) clause_parts.push_back(words[4 * j + c]);

            bool clause_okay = clause(clause_parts);
            if (!clause_okay) return false;
            else clause_parts.clear();
        }
    }
    return (words.back() == ".");
}

int main () {
    try {
        string text;
        vector <string> words;
        cout << "enter a sentence (one sentence at a time): ";


        while (cin >> text)
        {
            words.push_back(text);
            if (text == ".") break;
        }

        if (sentence(words)) cout << "OK" << endl;
        else cout << "Not OK" << endl;
    
        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch (...) {
        cerr << "unknown exception" << endl;
    }
}
