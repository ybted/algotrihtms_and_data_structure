#include "include\list.h"
#include <iostream>
int main()
{
    yb::list<int> l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    std::cout << l1.size() << std::endl;
    l1.insert(4);
    l1.print();
    l1.insert(5, 0);
    l1.insert(6, 3);
    l1.print();
    l1.remove(l1.size());
    l1.print();
    l1.remove(3);
    l1.print();
    l1.remove(1);
    l1.print();
    std::cout << l1.search(3)->val << std::endl;

}