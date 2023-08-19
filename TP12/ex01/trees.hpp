#ifndef TREES_HPP
#define TREES_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

/* No da arvore
    item - conteúdo do nó
    left - apontador para o nó a esquerda
    right - apontador para o nó a direita
*/
class Node
{
    public:
        string item;
        Node *left;
        Node *right;
        int height;
        Node(string item);  // Constructor that creates a new node with the given item as its content, and initializes the left and right pointers to NULL
};

class BSTree
{
    
    private:
        /* ATRIBUTOS
            root - raiz da árvore
        */
        Node *root;
        void insert(Node *treeNode, string value);

    public:
        BSTree();
        Node *getRoot();
        void setRoot(Node *newRoot);
        void insert(string value);
        void printTree(Node *treeNode);
        int getHeight(Node *treeNode);
        int getDepth(string item);
        int getDepth(Node* treeNode, string item);
        Node* searchItem(string item);
        Node* searchItem(Node* treeNode, string item);
        bool isSuccessor(string item1, string item2);
        string getLongestBranch();
        string getLongestBranch(Node* treeNode);
};

class AVL
{
    private:
        Node *root;
        int getBalance(Node *N); // A method to get the balance factor of a node (the difference between the heights of its left and right subtrees). If the node is NULL, it returns 0.
        Node* rightRotate(Node *node);  //A method that performs a right rotation on the node and returns a pointer to the new root.
        Node* leftRotate(Node *node); //A method that performs a left rotation on the node and returns a pointer to the new root.
        string maxString(string a, string b); //A utility function to get maximum of two strings
        void countItemsStartingWith(Node* node, char letter, int& count, vector<int>& letterCounts);  //A helper method that counts the number of nodes in the subtree rooted at the node that have an item starting with the given letter. Stores the count in the given count parameter, and updates the counts of each letter in the letterCounts vector.
    
    public: 
        int getHeight(Node *treeNode); //A method that returns the height of the node. If the node is NULL, it returns 0.
        void insert(string item);//A  method that inserts a  new item into the AVL tree.
        Node* insert(Node* node, string item); //A  method that inserts a  new item into the AVL tree rooted at node.
        void printTree(Node *node); // method to print the AVL tree
        Node* getRoot(); //A getter method that returns a pointer to the root of the AVL tree.
        AVL(); //Constructor that initializes the root pointer to NULL
        int getDepth(string item);
        int getDepth(Node* treeNode, string item);
        Node* searchItem(string item);
        Node* searchItem(Node* treeNode, string item);
        bool isSuccessor(string item1, string item2);
        string getLongestBranch();
        string getLongestBranch(Node* treeNode);
};

#endif
