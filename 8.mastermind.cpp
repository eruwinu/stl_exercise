#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

enum Color { Red, Orange, Yellow, Green, Blue, Violet};
std::vector<std::string> ColorName { "Red", "Orange", "Yellow", "Green", "Blue", "Violet"};

std::ostream& operator<<(std::ostream& os, Color c)
{
    os << ColorName[c];
    return os;
}

bool construct(std::vector<Color>& code, const std::string& guess)
{
    if (guess.length() != 4)
        return false;

    for(size_t i=0; i<code.size(); ++i)
    {
        switch(guess[i])
        {
            case 'r':
            case 'R':
                code[i] = Red;
                break;
            case 'o':
            case 'O':
                code[i] = Orange;
                break;
            case 'y':
            case 'Y':
                code[i] = Yellow;
                break;
            case 'g':
            case 'G':
                code[i] = Green;
                break;
            case 'b':
            case 'B':
                code[i] = Blue;
                break;
            case 'v':
            case 'V':
                code[i] = Violet;
                break;
            default:
                return false;
        }
    }

    return true;
}

bool evaluate(std::vector<Color> code, std::vector<Color>& guess)
{
    std::cout << "\t\t\tHint: ";

    std::vector<int> result;
    result.resize(code.size());
    std::transform(code.begin(), code.end(), guess.begin(), result.begin(), std::minus<int>());
    int blacks = std::count(result.begin(), result.end(), 0); // correct color, correct position = 0 numeric difference
    std::cout << blacks << " blacks, ";

    std::sort(code.begin(), code.end());
    std::sort(guess.begin(), guess.end());
    std::vector<int>::iterator it;
    it = std::set_difference(code.begin(), code.end(), guess.begin(), guess.end(), result.begin());
    result.resize(it - result.begin()); // sorted set difference = appears in code but doesn't appear in guess
    int whites = code.size() - result.size() - blacks; // complement of sorted set difference minus those that are in the correct position (blacks) = correct color, wrong position = whites
    std::cout << whites << " whites" << std::endl;

    return (blacks == 4);
}

int main()
{
    std::cout << "Color choices: ";
    for(auto name : ColorName)
    {
        name.insert(0, "(");
        name.insert(2, ")");
        std::cout << name << ", ";
    }
    std::cout << std::endl;

    std::vector<Color> code{Red, Orange, Yellow, Green, Blue, Violet};
    code.insert(code.end(), code.begin(), code.end()); // 1x2 = 2
    code.insert(code.end(), code.begin(), code.end()); // 2x2 = 4
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(code.begin(), code.end(), std::default_random_engine(seed));
    code.resize(4);

    int turnsLeft = 10;
    std::vector<Color> guess;
    guess.resize(code.size());
    do
    {
        std::string s;
        do
        {
            std::cout << "Guess " << 11 - turnsLeft << "/10: ";
            std::cin >> s;
        } while (!construct(guess, s));

        turnsLeft--;
    } while ((turnsLeft > 0) && !evaluate(code, guess));

    std::cout << "Code: ";
    for(const auto& color : code)
        std::cout << color << ", ";
    std::cout << std::endl;

    return 0;
}
