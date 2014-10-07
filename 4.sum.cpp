#include <iostream>
#include <iterator>
#include <cassert>
#include <fstream>
#include <algorithm>

namespace onhands
{

class Results
{
public:
    int min, max, sum;
    unsigned size;
    double average;

    bool check() const
    {
        return min == 49 &&
            max == 32754 &&
            sum == 31858542 &&
            size == 2048 &&
            average - 15555.9 <= 0.03;
    }
};

}

using namespace std;

int main()
{
    // Open file sum.txt, print min, max, and avg value from it to stderr.
    ifstream ifs("sum.txt", ifstream::in);
    istream_iterator<int> start(ifs), end;
    vector<int> num(start, end);

    int min, max, sum;
    double avg;
    min = *min_element(num.begin(), num.end());
    max = *max_element(num.begin(), num.end());
    sum = accumulate(num.begin(), num.end(), 0);
    avg = double(sum/num.size());

    cerr << min << " " << max << " " << avg << endl;

    // Fill Results structure with your results for check
    onhands::Results r{min, max, sum, static_cast<unsigned>(num.size()), avg};
    ifs.close();
    assert(r.check());
    return 0;
}
