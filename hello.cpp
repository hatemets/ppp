#include "std_lib_facilities.h"

class Name_pairs {
    private:
        vector<string> name;
        /* vector<double> age; */
    public:
        Name_pairs();
        void read_names(istream&);
        void print_names(ostream&);
};

Name_pairs::Name_pairs () { }

void Name_pairs::read_names(istream& is) {
    while (true) {
        string n;
        is >> n;
        if (n == "q") return;
        name.push_back(n);
    }
}

void Name_pairs::print_names(ostream& os) {
    for (int i = 0; i < name.size(); i++) {
        os << name[i] << endl;
    }
}

int main () {
    Name_pairs a;
    a.read_names(cin);
    a.print_names(cout);
    return 0;
}

