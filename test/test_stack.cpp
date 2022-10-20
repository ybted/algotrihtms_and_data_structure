#include "..\include\stack.h"

int main()
{
    yb::stack<int> stk;
    stk.push(1);
    std::cout << stk.top() << std::endl;
    for (int i = 0; i < 99; i ++)
        stk.push(i);
    std::cout << stk.cap() << std::endl;
    for (int i = 0; i < 99; i ++)
        stk.push(i);
    std::cout << stk.cap() << std::endl; 
    for (int i = 0; i < 99; i ++)
        stk.push(i);
    std::cout << stk.cap() << std::endl;
    std::cout << stk.size() << std::endl;
}