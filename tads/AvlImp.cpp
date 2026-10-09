#ifndef AVL_IMP // si NO está definida la etiqueta AVL_IMP...
#define AVL_IMP // ...la defino ahora (include guard: evita incluir 2 veces)

#include "AVL.h"   // trae la interfaz base AVL<T> que esta clase implementa
#include "List.h"  // trae la interfaz de listas List<T>
#include <cassert> // trae assert(...) para chequear condiciones en ejecucion
#include <algorithm>

template <class T>           // clase generica: T puede ser long long, string, etc.
class AVLImp : public AVL<T> // AVLImp hereda de AVL<T> (implementa sus metodos)
{
private:       // desde aca, todo es privado (no se ve desde afuera)
    class Node // clase interna: el nodo del arbol
    {
    public: // campos public para que AVLImp los use libremente
        T element;
        Node *left;
        Node *right;
        int height;
        // constructor del nodo: recibe dato + los dos hijos.
        // la lista de inicializacion (despues de los :) copia cada parametro a su campo.
        // height arranca en 1 porque un nodo nuevo es una hoja
        Node(T element, Node *left, Node *right)
            : element(element), left(left), right(right), height(1) {}
    };

    Node *root; // puntero a la raiz. Si es NULL, el arbol esta vacio.

public: // desde aca, lo que se ve desde afuera
    // constructor del arbol: arranca vacio (root en NULL)
    AVLImp() : root(NULL) {}
    void insertar(T element)
    {
        root = ALTA(root, element);
    }

    Node *ALTA(Node *node, T element)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return new Node(element, NULL, NULL);
        if (element < node->element)
            node->left = ALTA(node->left, element);
        else if (element > node->element)
            node->right = ALTA(node->right, element);
        else // Equal elements are not allowed in BST
            return node;

        /* 2. Update height of this ancestor AVLnode */
        node->height = 1 + std::max(height(node->left), height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance < -1 && element < node->left->element)
            return rightRotate(node);

        // Right Right Case
        if (balance > 1 && element > node->right->element)
            return leftRotate(node);

        // Left Right Case
        if (balance < -1 && element > node->left->element)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance > 1 && element < node->right->element)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;

        // Return new root
        return y;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left),
                             height(y->right)) +
                    1;
        x->height = std::max(height(x->left),
                             height(x->right)) +
                    1;

        // Return new root
        return x;
    }

    int *height(Node *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int *getBalance(Node *node)
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

    List<T>* rango(T desde, T hasta)
    {
        ListImp<T> *registro = new ListImp<T>();
        rangoEnAvl(root, desde, hasta, *registro);
        return registro;
    }

    void rangoEnAvl(Node *node, T desde, T hasta, ListImp<T> &registro)
    {
        if (node == NULL)
            return ;

        if (node->element > hasta)
        {
            rangoEnAvl(node->left, desde, hasta, registro);
        }

        if (node->element >= desde && node->element <= hasta)
        {
            registro.insert(node->element);
        }

        if (node->element < desde)
        {
            rangoEnAvl(node->right, desde, hasta, registro);
        }
    }
};

#endif // cierra el include guard abierto arriba