#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "decisionTree.hpp"

using namespace std;

/* ------------------------------ */
/* --------- CLASS Node --------- */
/* ------------------------------ */

/* CONSTRUCTORS */

Node::Node() : data(""), left(nullptr), right(nullptr) {};

Node::Node(string data) : data(data), left(nullptr), right(nullptr) {};

/* DESTRUCTOR */

Node::~Node()
{
    delete left;
    delete right;
}

/* GET METHODS */

string Node::getData() const
{
    return data;
}

Node* Node::getLeft() const
{
    return left;
}

Node* Node::getRight() const
{
    return right;
}

/* SET METHODS */

void Node::setData(string data)
{
    this->data = data;
}

void Node::setLeft(Node* left)
{
    this->left = left;
}

void Node::setRight(Node* right)
{
    this->right = right;
}

/* ------------------------------ */
/* ----- CLASS DecisionTree ----- */
/* ------------------------------ */

/* CONSTRUCTOR */

DecisionTree::DecisionTree() : root(nullptr) {};

/* DESTRUCTOR */

DecisionTree::~DecisionTree()
{
    delete root;
}

/* GET METHODS */

Node* DecisionTree::getRoot() const
{
    return root;
}

/* SET METHODS */

void DecisionTree::setRoot(Node* root)
{
    this->root = root;
}

/* OTHER METHODS */

Node* DecisionTree::searchNode(Node* search, string value)
{
    if (!search) return nullptr;
    if (search->getData() == value) return search;

    Node* predecessor = nullptr;
    // Search left subtree
    if (search->getLeft()) predecessor = searchNode(search->getLeft(), value);
    // Search right subtree
    if (!predecessor) {
        if (search->getRight()) predecessor = searchNode(search->getRight(), value);
    }
    return predecessor;
}

int DecisionTree::insert(string predecessor, string value, string decision)
{
    if (value.empty() || !(decision == "Yes" || decision == "No")) return -1;
    
    Node *new_node = new Node(value);
    
    if (!root) root = new_node;
    else {
        Node* current_node = searchNode(root, predecessor);
        if (decision == "Yes") current_node->setLeft(new_node);
        else current_node->setRight(new_node);
    }
    return 0;
}

void DecisionTree::preOrderTraversal(Node* tree_node)
{
    if (tree_node) {
        cout << tree_node->getData() << endl;
        preOrderTraversal(tree_node->getLeft());
        preOrderTraversal(tree_node->getRight());
    }
}

int DecisionTree::import(const string filename)
{
    if (filename.empty()) return -1;

    ifstream input_file(filename); // read from text file
    if (!input_file) return -1; // error

    string buffer, name, prev, option;
    stringstream ss_buffer;
    int result;
    while (getline(input_file, buffer)) {
        if (buffer[buffer.length() - 1] == '\r') buffer.pop_back();
        ss_buffer.clear();
        ss_buffer << buffer;
        getline(ss_buffer, name, '\t');
        getline(ss_buffer, prev, '\t');
        getline(ss_buffer, option, '\t');
        result = insert(prev, name, option);
        if (result == -1) {
            input_file.close();
            return -1;
        }
    }
    input_file.close();
    
    return 0;
}