#include "stack.h"
#include <iostream>


int main()
{
    Stack<int> s;
    s.push(5);
    s.push(6);
    s.push(8);
    std::cout << s.size() << ' ' << s.top() << ' ';
    return 0;
}