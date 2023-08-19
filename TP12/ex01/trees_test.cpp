#include <iostream>
#include <string>
#include <vector>
#include "trees.cpp"

using namespace std;

int main()
{
    BSTree obj_bstree;
    AVL obj_avl;

    /* Alínea a */

    vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};
    for (int i = 0; i < (int) vtr.size(); i++)
    {
        obj_bstree.insert(vtr[i]);
    }

    Node* node_found;
    
    cout << "\nTeste searchItem: Elementos da árvore BST:" << endl;
    for (int i = 0; i < (int) vtr.size(); i++)
    {
        node_found = obj_bstree.searchItem(vtr[i]);
        if(node_found)
        {
            cout << "Element " << vtr[i] << " found. Height: " << node_found->height << endl;
        }
        else
        {
            cout << "Element " << vtr[i] << " not found." << endl;
        }
    }
    node_found = obj_bstree.searchItem("X");
    
    if(node_found)
    {
        cout << "Element X found. Height: " << node_found->height << endl;
    }
    else
    {
        cout << "Element X not found." << endl;
    }

    for (int i = 0; i < (int) vtr.size(); i++)
    {
        obj_avl.insert(vtr[i]);
    }
    
    cout << "\nTeste searchItem: Elementos da árvore AVL:" << endl;
    for (int i = 0; i < (int) vtr.size(); i++)
    {
        node_found = obj_avl.searchItem(vtr[i]);
        if(node_found)
        {
            cout << "Element " << vtr[i] << " found. Height: " << node_found->height << endl;
        }
        else
        {
            cout << "Element " << vtr[i] << " not found." << endl;
        }
    }
    node_found = obj_avl.searchItem("Y");
    if(node_found)
    {
        cout << "Element Y found. Height: " << node_found->height << endl;
    }
    else
    {
        cout << "Element Y not found." << endl;
    }

    cout << "\nTeste isSuccessor na árvore BST:" << endl;

    for(int i = 0; i < (int) vtr.size(); i++)
    {
        if(obj_bstree.isSuccessor(vtr[i+1], vtr[i]))
        {
            cout << vtr[i+1] << " é sucessor de " << vtr[i] << endl;
        }
        else
        {
            cout << vtr[i+1] << " não é sucessor de " << vtr[i] << endl;
        }
        i++;
    }


    cout << "\nTeste isSuccessor na árvore AVL:" << endl;

    for(int i = 0; i < (int) vtr.size(); i++)
    {
        if(obj_avl.isSuccessor(vtr[i+1], vtr[i]))
        {
            cout << vtr[i+1] << " é sucessor de " << vtr[i] << endl;
        }
        else
        {
            cout << vtr[i+1] << " não é sucessor de " << vtr[i] << endl;
        }
        i++;
    }

        
    cout << "\nTeste getDepth: Profundidades na árvore BST (Pre-order):" << endl;
    
    Node *root = obj_bstree.getRoot();
    obj_bstree.printTree(root);

    cout << "\nTeste getDepth: Profundidades na árvore AVL (Pre-order):" << endl;
    
    root = obj_avl.getRoot();
    obj_avl.printTree(root);

    cout << "\nTeste getLongestBranch na árvore BST:" << endl;

    cout << "O ramo mais longo da árvore BST é: " << obj_bstree.getLongestBranch() << endl;

    cout << "\nTeste getLongestBranch na árvore AVL:" << endl;

    cout << "O ramo mais longo da árvore AVL é: " << obj_avl.getLongestBranch() << endl;
}