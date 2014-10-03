#include <cassert>
#include <iostream>
#include <set>
#include <vector>

namespace onhands
{

template <typename T>
std::vector<T> unique(std::vector<T> const& first, std::vector<T> const& second)
{
    // TODO: This function should join input vectors and return only unique elements.
    // Important: STL algorithms cannot be used!

    std::vector<T> joined(first);
    joined.insert(joined.end(), second.begin(), second.end());

    std::set<T> unique(joined.begin(), joined.end());

    return std::vector<T>(unique.begin(), unique.end());
}

} // namespace onhands

int main(int, char**)
{
    using std::vector;
    vector<double> d1 = {1.1, 2.1, 3.1, 1.0, 1.1, 0.56, 0.44, 4.445, 0.001, 9.996, 0.001};
    vector<double> d2 = {0.001, 0.002, 0.0003, 1.1, 0.44, 0.99, 0.996, 3.1, 3.12};

    vector<double> result = onhands::unique(d1, d2);

    for (auto const& element : result)
    {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    return 0;
}

