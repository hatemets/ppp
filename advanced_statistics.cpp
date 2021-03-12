#include "std_lib_facilities.h"

struct Values {
    public:
        double max;
        double min;
        double mean;
        double median;
        Values (double x, double m, double mn, double mdn) : max(x), min(m), mean(mn), median(mdn) { }
};

Values comp (vector<double>& v)
{
    double max = 0;
    double min = 0;
    double total = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        total += v[i];
        if (i == 0)
        {
            max = v[0];
            min = v[0];
        }
        else if (v[i] > max) max = v[i];
        else if (v[i] < min) min = v[i];
    }

    double mean = total / v.size();

    double median = (v.size() % 2 == 0) ? (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2 : v[v.size() / 2];

    return Values(max, min, mean, median);
}

int main () 
{
    vector<double> nums {1, 2, 3, 99, -99};
    Values vals = comp(nums);
    cout << "max: " << vals.max << endl;
    cout << "min: " << vals.min << endl;
    cout << "mean: " << vals.mean << endl;
    cout << "median: " << vals.median << endl;
    return 0;
}

