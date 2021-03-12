#include "std_lib_facilities.h"

int find_val (string s, vector<string>& vs, vector<int>& vn)
{
    for (int i = 0; i < vs.size(); ++i)
        if (vs[i] == s) return vn[i];
}

int main () 
{
    vector<string> names;
    vector<int> ages;
    vector<int> matching_ages;
    string name = "";
    int age = 0;

    cout << "enter some names: ";
    while (cin >> name) 
    {
        if (name == "quit") break;
        names.push_back(name);
    }

    vector<string> names_copy = names;

    for (int i = 0; i < names.size(); ++i)
    {
        cout << names[i] << "'s age: ";
        cin >> age;
        ages.push_back(age);
    }

    cout << "initially: " << endl;
    for (int i = 0; i < names.size(); ++i)
        cout << "name: " << names[i] << ", age: " << ages[i] << endl;

    sort(names.begin(), names.end());

    for (int i = 0; i < names.size(); ++i)
    {
        int val = find_val(names[i], names_copy, ages);
        matching_ages.push_back(val);
    }

    cout << "\nafter sorting: " << endl;
    for (int i = 0; i < names.size(); ++i)
        cout << "name: " << names[i] << ", age: " << matching_ages[i] << endl;

    return 0;
}

