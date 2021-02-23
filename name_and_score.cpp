#include "../std_lib_facilities.h"

int main () {
	string name;
	int num;
	vector <string> names;
	vector <int> nums;

	cout << "enter a name and a number: ";

	while (cin >> name >> num) {
		if (name == "NoName" && num == 0)
			break;
		
		bool name_valid = true;

		for (string n : names) {
			if (name == n) {
				name_valid = false;
				cout << "error: name already exists" << endl;
			}
		}

		if (name_valid == true) {
			names.push_back(name);
			nums.push_back(num);
		}
	}

	int query;
	vector <string> corr_names;
	cout << "search for a score: ";

	while (cin >> query) {
		for (int i = 0; i < names.size(); ++i) {
			if (nums[i] == query)
				corr_names.push_back(names[i]);
		}
		
		if (corr_names.size() == 0)
			cout << "there is noone with that score" << endl;
		else {
		cout << "names:" << endl;
		for (string name : corr_names)
			cout << name << endl;
		}
	}

	return 0;
}
