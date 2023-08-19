#include <iostream>
#include <string>
#include <vector>
#include "bst.hpp"

using namespace std;

int main()
{
    Tree obj_tree;

    /* Alínea b */
    cout << "\n Inserir elementos na árvore: " << endl;
    vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};
    for (int i = 0; i < vtr.size(); i++)
    {
        obj_tree.insert(vtr[i]);
    }
    cout << "\n Elementos inseridos com sucesso" << endl;
    Node *root = obj_tree.getRoot();
    obj_tree.printTree(root);

    /* Alínea c */
    cout << "\nVerfificar se a arvore esta balanceada: " << endl;
    if (obj_tree.isBalanced(root))
    {
        cout << "A arvore esta balanceada:" << endl;
    }
    else
    {
        cout << "A arvore nao esta balanceada" << endl;
    }
}