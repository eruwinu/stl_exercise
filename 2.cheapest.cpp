#include <vector>
#include <algorithm>
#include <iostream>

namespace onhands
{

struct Product
{
    float price;
    explicit Product(float price) : price(price) {}
    // it is only allowed to add new context (modification of above is forbidden)
};

//TODO: return x cheapest products, where x is function param (num)
std::vector<Product> find_cheapest(std::vector<Product> const& v, unsigned num)
{
    // Please pay attention to performance.
    std::vector<Product> copy(v);

//    std::sort(copy.begin(), copy.end(), [](auto lhs, auto rhs){return (lhs.price < rhs.price);});
    std::nth_element(copy.begin(), copy.begin()+num, copy.end(), [](auto lhs, auto rhs){return lhs.price < rhs.price;});

    return std::vector<Product>(copy.begin(), copy.begin()+num);
}

} // namespace onhands

int main(int, char**)
{
    std::vector<onhands::Product> products;
    for (int i = 1; i < 100; ++i)
    {
        products.push_back(onhands::Product(static_cast<float>(i)));
    }
    std::random_shuffle(products.begin(), products.end());

    std::vector<onhands::Product> cheapest = find_cheapest(products, 20);
    // Print output without using loop.
    std::for_each(cheapest.begin(), cheapest.end(), [](auto in){std::cout << in.price << ", ";});
    std::cout << std::endl;
    //system("pause");
}

