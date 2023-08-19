#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/* No da arvore
    item - conteúdo do nó
    left - apontador para o nó a esquerda
    right - apontador para o nó a direita
*/
struct Node
{
    string cidade;
    string pais;
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
    void insert(Node *treeNode, string ci,string pa );
    int  getHeight(Node *treeNode);

public:
    Tree();
    Node *getRoot();
    void setRoot(Node *newRoot);
    void insert(string ci, string pa);
    Node *search_node(string ci);
    bool remove(string ci);
    void posOrder(Node *current);
    void preOrder(Node *current);
    int getHeight();
    int seeds(Node *current);
    int countNodes(Node *current);
    string getMinNode();
    string getMaxNode();
    bool isBalanced();
    bool isBalanced(Node *treeNode);
    Node *node_sucessor(Node *del);
    void inverso(Node *no, string valor);
    int numero_cidades(Node *treeNode, vector<string> paises);
    int numero_cidades2(Node *treeNode, char min, char max);
};

#endif
