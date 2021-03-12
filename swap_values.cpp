#include "std_lib_facilities.h"

vector <string> swap_ref (vector<string>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        string tmp = v[i];
        if (i == v.size() - (1 + i)) break;
        v[i] = v[v.size() - (1 + i)];
        v[v.size() - (1 + i)] = tmp;
    }

    return v;
}

vector<string> swap_cp (vector<string> v)
{
    vector<string> sv;
    for (int i = 0; i < v.size(); ++i)
        sv.push_back(v[v.size() - (1 + i)]);
    return sv;
}

int main () 
{
    vector<string> words {"a", "b", "c", "b", "u"};
    swap_ref(words);

    cout << "{";
    for (int i = 0; i < words.size(); ++i)
    {
        cout << words[i];
        (i != words.size() - 1) ? cout << ", " : cout << "}";
    }

    return 0;
}

