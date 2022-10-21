#ifndef __TREE_H
#define __TREE_H
#include "queue.h"
#include <iostream>

namespace yb{
    template <class object>
    class tree{
    private:
        struct treenode{
            object val;
            treenode* left;
            treenode* right;
            treenode() : val{object{}}, left{nullptr}, right{nullptr}{}
            treenode(object o) : val{o}, left{nullptr}, right{nullptr}{}
        };

        treenode* root;
    
    protected:
        treenode* insert(object o, treenode* root)
        {
            if (root == nullptr)
                root = new treenode(o);
            else if (o < root->val)
                root->left = insert(o, root->left);
            else if (o > root->val)
                root->right = insert(o, root->right);
            return root;
        }

        void preorder(treenode* root)
        {
            if (root == nullptr) return ;
            std::cout << root->val << " " ;
            preorder(root->left);
            preorder(root->right);
        }

        void inorder(treenode* root)
        {
            if (root == nullptr) return ;
            inorder(root->left);
            std::cout << root->val << " ";
            inorder(root->right);
        }

        void postorder(treenode* root)
        {
            if (root == nullptr) return ;
            postorder(root->left);
            postorder(root->right);
            std::cout << root->val << " ";
        }

        treenode* find(object o, treenode* root)
        {
            if (root == nullptr) return nullptr;
            if (root->val == o)
                return root;
            if (o < root->val)
                return find(o, root->left);
            if (o > root->val)
                return find(o, root->right);
        }

        treenode* findmin(treenode* root)
        {
            if (root->left == nullptr) return root;
            else return findmin(root->left);
        }

        treenode* findmax(treenode* root)
        {
            if (root->right == nullptr) return root;
            else return findmax(root->right);
        }

        treenode* remove(object o, treenode* root)
        {
            if (root == nullptr) {
                std::cout << "NOT FOUND !" << std::endl;
                return nullptr;
            }
            if (o < root->val)
                root->left = remove(o, root->left);
            else if (o > root->val)
                root->right = remove(o, root->right);
            else 
            {
                if (!root->left && !root->right)
                {
                    delete root;
                    return nullptr;
                }
                else if (root->left && root->right)
                {
                    treenode* p = findmin(root->right);
                    root->val = p->val;
                    root->right = remove(p->val, root->right);
                }
                else 
                {
                    if (root->left) 
                    {
                        treenode* p = root->left;
                        delete root;
                        return p;
                    }
                    if (root->right)
                    {
                        treenode* p = root->right;
                        delete root;
                        return p;
                    }
                }
            }
            return root;
        }

    public:
        tree() : root{nullptr}{}
        tree(object o): root{new treenode(o)}{}

        void insert(object o)
        {
            root = insert(o, root);
        }

        void preorder()
        {
            preorder(root);
            std::cout << std::endl;
        }

        void inorder()
        {
            inorder(root);
            std::cout << std::endl;
        }

        void postorder()
        {
            postorder(root);
            std::cout << std::endl;
        }

        
        void BFS()
        {
            queue<treenode*> q;
            if (root == nullptr) return ;
            q.push(root);
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i ++)
                {
                    auto t = q.front(); q.pop();
                    std::cout << t->val << " ";
                    if (t->left) q.push(t->left);
                    if (t->right) q.push(t->right);
                }
                std::cout << std::endl;
            }


        }  
        
        treenode* find(object o)
        {
            return find(o, root);
        }  

        treenode* findmax()
        {
            return findmax(root);
        }

        treenode* findmin()
        {
            return findmin(root);
        }

        void remove(object o)
        {
            root = remove(o, root);
        }
    };
}


#endif