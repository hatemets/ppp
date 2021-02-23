#include "../std_lib_facilities.h"

int main () {
	vector <int> nums; 
	vector <int> indexes;
	vector <int> occurs;
	int num;

	cout << "Enter some numbers: ";

	while (cin >> num)
		nums.push_back(num);
	
	sort(nums); // 2, 2, 2, 2, 3, 3

	int c = 1;

	for (int i = 0; i < nums.size(); ++i)
	{
		if ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
			++c;
		} else {
			occurs.push_back(c);
			indexes.push_back(i);
			c = 1;
		}
	}

	int max = 0;
	int max_num = 0;

	for (int i = 0; i < occurs.size(); ++i) {
		int n = indexes[i];

		if (occurs[i] >= max) {
			max = occurs[i];
			max_num = nums[n];
		} 

		cout << nums[n] << " -- occurrences: " << occurs[i] << endl;
	}

	cout << "Mode is " << max_num << endl;

	return 0;
}
