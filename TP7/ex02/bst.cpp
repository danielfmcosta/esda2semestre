#include <iostream>
#include <stdlib.h>
#include "bst.hpp"

using namespace std;

Tree::Tree()
{
    root = NULL;
}

Node *Tree::getRoot()
{
    return this->root;
}

void Tree::setRoot(Node *newRoot)
{
    this->root = newRoot;
}

void Tree::insert(string value)
{
    insert(root, value);
}

void Tree::insert(Node *treeNode, string value)
{
    /* Alinea b */

    if (!treeNode)
    {
        treeNode = new Node();
        treeNode->item = value;
        root = treeNode;
    }
    else
    {
        if (value < treeNode->item)
        {
            if (!treeNode->left)
            {
                Node *treeTemp = new Node();
                treeTemp->item = value;
                treeNode->left = treeTemp;
            }
            else
                insert(treeNode->left, value);
        }
        else
        {
            if (!treeNode->right)
            {
                Node *treeTemp = new Node();
                treeTemp->item = value;
                treeNode->right = treeTemp;
            }
            else
                insert(treeNode->right, value);
        }
    }
}

/* Calcula a altura da árvore a partir de um nó */
int Tree::getHeight(Node *treeNode)
{
    if (treeNode == NULL || (treeNode->left == NULL && treeNode->right == NULL))
        return 0;
    else
    {
        if (getHeight(treeNode->left) > getHeight(treeNode->right))
            return (1 + getHeight(treeNode->left));
        else
            return (1 + getHeight(treeNode->right));
    }
}

/* Imprime a arvore */
void Tree::printTree(Node *treeNode)
{
    if (treeNode != NULL)
    {
        //cout << treeNode->item << " " << treeNode->height << endl; Descomentar essa linha quando o novo atributo estiver definido
        printTree(treeNode->left);
        printTree(treeNode->right);
    }
}

/* Testa se a arvore está balanceada */
bool Tree::isBalanced(Node *treeNode)
{
  /* Alinea c */
}
