#include <iostream>
#include <vector>
#include "bubble_sort.h"


int main()
{
  std::vector<int> v = {3, 5, 6, 9, 1, 56, 4, 8, 7};
  int a[10] = {7, 9, 23, 72, 47, 1, 89, 19, 1, 4};
  bubble_sort(v.begin(), v.end(), std::less<int>());
  bubble_sort(a, a + 10, std::less<int>{});
  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
  for (int i = 0; i < 10; ++i) {
    std::cout << a[i] << ' ';
  }
}