#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(int, char**)
{
    // Find all differences between files `primes.txt` and `primes.corrupted.txt`.
    // Put them on stderr in following form:
    //  Position: X
    //  Valid value: Y
    //  Corrupted value: Z
    ifstream ifs1("primes.txt", ifstream::in);
    istream_iterator<int> start1(ifs1), end1;
    vector<int> primes(start1, end1);

    ifstream ifs2("primes.txt", ifstream::in);
    istream_iterator<int> start2(ifs2), end2;
    vector<int> corrupted_primes(start2, end2);

    ifs1.close();
    ifs2.close();
}

