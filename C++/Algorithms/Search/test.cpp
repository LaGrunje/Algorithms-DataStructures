#include <iostream>
#include <vector>
#include "linear_search.h"
#include "binary_search.h"

int main()
{
    std::vector<int> v = {7, 9, 8, 6, 21, 21, 21, 21, 21, 21, 21, 21, 54, 3, 1, 0, -5, 10, 2};
    auto it = linear_search(v.begin(), v.end(), 21);
    std::cout << *(it) << ' ';
    it = linear_search(v.begin(), v.end(), 25);
    if (it == v.end())
        std::cout << "boo" << ' ';
    it = bin_search(v.begin(), v.end(), 21);
    std::cout << it - v.begin() << ' ';
    it = bin_search(v.begin(), v.end(), 25);
    if (it == v.end())
        std::cout << "boo" << ' ';
    return 0;
}