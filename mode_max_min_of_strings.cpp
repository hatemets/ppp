#include "../std_lib_facilities.h"

int main () {
	vector <string> strings = {"hi", "baby", "hi", "hi", "yo"};
	vector <int> indexes;
	vector <int> occurs;
	string max_string = "";
	string min_string = "";
	int max_string_length = 0;
	int min_string_length;

	sort(strings); 

	int c = 1;

	for (int i = 0; i < strings.size(); ++i)
	{
		if ((i + 1) < strings.size() && strings[i] == strings[i + 1]) {
			++c;
		} else {
			occurs.push_back(c);
			indexes.push_back(i);
			c = 1;
		}

		if (strings[i].length() > max_string_length) {
			max_string_length = strings[i].length();
			max_string = strings[i];
		} else if (strings[i].length() < min_string_length || i == 0) {
			min_string_length = strings[i].length();
			min_string = strings[i];
		}
	}

	int max = 0;
	string mode_string = "";

	for (int i = 0; i < occurs.size(); ++i) {
		int n = indexes[i];

		if (occurs[i] >= max) {
			max = occurs[i];
			mode_string = strings[n];
		} 

		cout << strings[n] << " -- occurrences: " << occurs[i] << endl;
	}

	cout << "Mode is " << mode_string << endl;
	cout << "Max string: " << max_string << endl;
	cout << "Min string: " << min_string << endl;

	return 0;
}
