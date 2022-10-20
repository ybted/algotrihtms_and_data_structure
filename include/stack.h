#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#define default_length 100
namespace yb{
    template <class object>
    class stack{
        private:
            object* s;
            int _top;
            int capacity;
            bool full()
            {
                return _top == capacity;
            }
        public:
            stack() : s{new object[default_length]}, _top{-1}, capacity{default_length}{}

            int size()
            {
                return _top + 1;
            }

            int cap()
            {
                return capacity;
            }
            bool empty()
            {
                return _top == -1;
            }

            void push(object o)
            {
                if (!full())
                {
                    _top ++;
                    s[_top] = o;
                }
                else 
                {
                    object* new_s = new object[capacity * 2];
                    for (int i = 0; i < capacity; i++)
                        new_s[i] = s[i];
                    capacity *= 2;
                    object* temp = s;
                    s = new_s;
                    delete temp;
                    std::cout << " Success !" << std::endl;
                    _top ++;
                    s[_top] = o;
                }
            }

            void pop()
            {
                if (empty())
                {
                    std::cout << " The stack is empty !" << std::endl;
                    return ;
                }
                else 
                {
                    _top --;
                }
            }

            object top()
            {
                return s[_top];
            }
    };
}

#endif