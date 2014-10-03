#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(int, char**)
{
    // Using file sum.txt divide values into even and odd
    // find median value and percentiles: 25% and 75% of each group
    ifstream ifs("sum.txt", ifstream::in);
    istream_iterator<int> start(ifs), end;
    vector<int> num(start, end);

    auto divider = partition(num.begin(), num.end(), [](auto i)->bool{return i%2;});

    nth_element(num.begin(), divider, divider);
    auto diff = distance(num.begin(), divider);

    cout << "odds median: " << *(num.begin() + int(diff/2)) << endl;
    cout << "odds 25th percentile: " << *(num.begin() + int(diff/4)) << endl;
    cout << "odds 75th percentile: " << *(num.begin() + int(num.size()*3/4)) << endl;

    nth_element(divider, num.end(), num.end());
    diff = distance(divider, num.end());
    cout << "evens median: " << *(divider + int(diff/2)) << endl;
    cout << "evens 25th percentile: " << *(divider + int(diff/4)) << endl;
    cout << "evens 75th percentile: " << *(divider + int(diff*3/4)) << endl;

    ifs.close();
}

