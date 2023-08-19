#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

/* No da arvore
    item - conteúdo do nó
    left - apontador para o nó a esquerda
    right - apontador para o nó a direita
*/
struct Node
{
    /* Alínea a */
    string item;

    Node *left;
    Node *right;
};

class Tree
{
    
private:
    /* ATRIBUTOS
        root - raiz da árvore
    */
    Node *root;
    void insert(Node *treeNode, string value);

public:
    Tree();
    Node *getRoot();
    void setRoot(Node *newRoot);
    void insert(string value);
    void printTree(Node *treeNode);
    int getHeight(Node *treeNode);
    bool isBalanced(Node *treeNode);
};

#endif
