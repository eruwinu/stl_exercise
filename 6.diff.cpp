#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // Find all differences between files `primes.txt` and `primes.corrupted.txt`.
    // Put them on stderr in following form:
    //  Position: X
    //  Valid value: Y
    //  Corrupted value: Z
    ifstream ifs1("primes.txt", ifstream::in);
    istream_iterator<int> start1(ifs1), end1;
    vector<int> primes(start1, end1);

    ifstream ifs2("primes.corrupted.txt", ifstream::in);
    istream_iterator<int> start2(ifs2), end2;
    vector<int> corrupted(start2, end2);

    sort(primes.begin(), primes.end());
    sort(corrupted.begin(), corrupted.end());

    vector<int> diff;
    diff.resize(primes.size());
    transform(primes.begin(), primes.end(), corrupted.begin(), diff.begin(), minus<int>());

    vector<int>::iterator it = diff.begin() - 1;
    while((it = find_if(it+1, diff.end(), [](const int i){return (i!=0);})) != diff.end())
    {
        size_t pos = it - diff.begin();

        cout << "Position: " << pos+1 << endl;
        cout << "Valid value: " << primes[pos] << endl;
        cout << "Corrupted value: " << corrupted[pos] << endl << endl;
    }

    ifs1.close();
    ifs2.close();

    return 0;
}

