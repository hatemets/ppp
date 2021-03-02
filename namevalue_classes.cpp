#include "std_lib_facilities.h"

class Name_token {
    public:
        Name_token (string n, double s) : name(n), score(s) {}
        string name;
        double score;
};

bool exists (string name, vector <Name_token> values) {
    for (int i = 0; i < values.size(); ++i)
        if (name == values[i].name) return true;
    return false;
}

int main () {
    try {
        vector <Name_token> pairs;
        string name;
        double score;
        bool e;
        cout << "Please enter values: " << endl;
        cout << "> ";
        while (cin >> name >> score) {
            cout << "> ";
            if (name == "noname" && score == 0) break;
            if (exists(name, pairs) == true) error("name already in array");
            Name_token t(name, score);
            pairs.push_back(t);
        }
    
        cout << endl << "Values: " << endl;
        for (Name_token value : pairs)
            cout << value.name << ": " << value.score << endl;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "unknown exception" << endl;
    }
    return 0;
}
