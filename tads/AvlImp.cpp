#ifndef AVL_IMP 
#define AVL_IMP 

#include "AVL.h"  
#include "ListImp.cpp"  
#include <cassert> 
#include <algorithm>

template <class T>           
class AVLImp : public AVL<T> 
{
private:       
    class Node 
    {
    public:
        T element;
        Node *left;
        Node *right;
        int height;
      
        Node(T element, Node *left, Node *right)
            : element(element), left(left), right(right), height(1) {}
    };

    Node *root; 

public: 

    AVLImp() : root(NULL) {}
    void insertar(T element)
    {
        root = ALTA(root, element);
    }

    Node *ALTA(Node *node, T element)
    {
      
        if (node == NULL)
            return new Node(element, NULL, NULL);
        if (element < node->element)
            node->left = ALTA(node->left, element);
        else if (element > node->element)
            node->right = ALTA(node->right, element);
        else 
            return node;

       
        node->height = 1 + std::max(height(node->left), height(node->right));

    
        int balance = getBalance(node);

     

        if (balance < -1 && element < node->left->element)
            return rightRotate(node);


        if (balance > 1 && element > node->right->element)
            return leftRotate(node);

        
        if (balance < -1 && element > node->left->element)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

    
        if (balance > 1 && element < node->right->element)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

       
        return node;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
       y->left = x;
        x->right = T2;

     
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;

        return y;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

       
        x->right = y;
        y->left = T2;

     
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;

      
        return x;
    }

    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return height(node->right) - height(node->left);
    }

    bool buscar(T element)
    {
        return buscarEnAvl(root, element);
    }

    bool buscarEnAvl(Node *node, T elem)
    {
        if (node == NULL)
            return false;
        if (elem == node->element)
            return true;

        if (elem < node->element)
            return buscarEnAvl(node->left, elem);
        else
            return buscarEnAvl(node->right, elem);
    }

    List<T> *rango(T desde, T hasta)
    {
        ListImp<T> *registro = new ListImp<T>();
        rangoEnAvl(root, desde, hasta, *registro);
        return registro;
    }

    void rangoEnAvl(Node *node, T desde, T hasta, ListImp<T> &registro)
    {
        if (node == NULL)
            return ;

        if (node->element > desde)
        {
            rangoEnAvl(node->left, desde, hasta, registro);
        }

        if (node->element >= desde && node->element <= hasta)
        {
            registro.insert(node->element);
        }

        if (node->element < hasta)
        {
            rangoEnAvl(node->right, desde, hasta, registro);
        }
    }
};

#endif
