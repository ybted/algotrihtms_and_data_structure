#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <iostream>
#define default_length 100
namespace yb{
    template <class object>
    class queue{
        private:
            object* q;
            int head;
            int rear;
        public:
            queue():q{new object[default_length]}, head{0}, rear{0}{}
            
            bool full()
            {
                return size() == default_length - 1;
            }

            bool empty(){
                return head == rear;
            }

            int size()
            {
                if ( rear >= head) return rear - head;
                else return rear + default_length - head; 
            }

            void push(object o)
            {
                if (full())
                {
                    std::cout << " The queue is full !" << std::endl;
                    return ;
                }
                else 
                {
                    q[rear] = o;
                    rear ++;
                    rear %= default_length;
                }
            }

            void pop()
            {
                if (empty())
                {
                    std::cout << "The queue is empty!" << std::endl;
                    return ;
                }
                else 
                {
                    head ++ ;
                    head %= default_length;
                }
            }

            object front()
            {
                return q[head];
            }
    };
}

#endif