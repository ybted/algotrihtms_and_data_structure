#ifndef __LIST_H_
#define __LIST_H_
#include <iostream>

namespace yb{
    template <class object>
    class listnode{
    public:
        object val;
        listnode* next;
        listnode(object o = object{}, listnode* _next = nullptr):val{o}, next{_next} {}
    };

    template <class object>
    class list{
        private:
            listnode<object>* head;
            listnode<object>* rear;
            int _size;
        public:
            list();
            ~list();
            void print();

            bool empty(){ return head == rear;}

            //insert the new node after the last node
            void insert(object o);

            //insert the new node after the numth node
            void insert(object o, int num);

            //delete the last node
            void pop_back();

            //remove the numth node
            void remove(int num);
            
            //searcht the list for node n
            listnode<object>* search(object o);

            int size();

    };

    template <typename object>
    listnode<object>* list<object>::search(object o)
    {
        listnode<object>* p = head->next;
        while (p != nullptr)
        {
            if (p->val == o)
            {
                return p;
            }
            p = p->next;
        }
        std::cout << "Not Found ! " << std::endl;
        return nullptr;
    }

    template <typename object>
    void list<object>::remove(int num)
    {
        if (num < 1 || num > _size)
        {
            std::cout << "There is not a numth node !" << std::endl;
        }
        listnode<object> *p = head;
        int index = 1;
        while (index != num)
        {
            p = p->next;
            index ++;
        }
        listnode<object>* temp = p->next;
        p->next = p->next->next;
        delete temp;

    }

    template <typename object>
    void list<object>::pop_back()
    {
        if (empty())
        {
            std::cout << "The list has no nodes! " << std::endl;
        }
        else 
        {
            listnode<object>* temp = head;
            while (temp->next != rear )
            {
                temp = temp->next;
            }
            rear = temp;
            temp = rear->next;
            rear->next = nullptr;
            delete temp;
        }
    }

    template <typename object>
    int list<object>::size()
    {
        return this->_size;
    } 

    template <typename object>
    list<object>::list()
    {
        head = new listnode<object>();
        rear = head;
        _size = 0;
    }

    template <typename object>
    list<object>::~list()
    {
        listnode<object>* p1 = head;
        listnode<object>* p2 = p1->next;
        while (p2 != nullptr)
        {
            p1 = p2;
            p2 = p2->next;
            delete p1;
        }        
        delete head;
        delete rear;
    }

    template <typename object>
    void list<object>::insert(object o)
    {
        listnode<object>* new_node = new listnode<object>(o);
        rear->next = new_node;
        rear = rear->next;
        _size ++;
    }

    template <typename object>
    void list<object>::insert(object o, int num)
    {
        if (num < 0 || num > _size) 
        {
            std::cout << " The position is wrong! " << std::endl;
        }
        int index = 0;
        listnode<object>* cur = head;
        listnode<object>* new_node = new listnode<object>(o);
        while (index != num)
        {
            cur = cur->next;
            index ++;
        }
        new_node->next = cur->next;
        cur->next = new_node;
        _size ++;
    
    }


    template <typename object>
    void list<object>::print()
    {
        listnode<object>* p = head->next;
        while( p != nullptr)
        {
            std::cout << p->val <<  " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}
#endif