#include "..\include\queue.h"


int main()
{
    yb::queue<int> q;
    q.push(1);
    std::cout << q.front() << std::endl;
    for (int i = 0; i < 98; i ++)
        q.push(i + 2);
    std::cout << q.size() << std::endl;
    q.push(100);
    for (int i = 0; i < 99; i ++)
        q.pop();
    std::cout << q.empty() << std::endl;
}