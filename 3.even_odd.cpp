#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use one of stl algorithms to create one linear returning string stating if values are even or odd
    // than print this string on screen
    std::string s = std::accumulate(v1.begin(), v1.end(), std::string(), [](auto p, auto i){return (p + (i%2? "odd " : "even "));});

    assert("odd even odd even odd even odd even odd even " == s);
}
