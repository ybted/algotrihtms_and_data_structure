#include "..\include\binary_tree.h"

int main()
{
    yb::tree<int>* t = new yb::tree<int>();
    for (int i = 0; i < 10; i ++)
        t->insert((i * 10) % 7);
    t->BFS();
    t->preorder();
    t->inorder();
    t->postorder();
    std::cout << t->findmax()->val << std::endl;
    std::cout << t->findmin()->val << std::endl;
    t->remove(3);
    t->BFS();
}