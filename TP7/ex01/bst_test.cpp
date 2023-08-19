#include <iostream>
#include <string>
#include <vector>
#include "bst.cpp"

using namespace std;

int main()
{
    Tree obj_tree;

    int option;
    cout << ("\n Programa Arvore binaria de string");
    do
    {
        cout << "\n***********************************";
        cout << "\nEntre com a opcao:";
        cout << "\n ----1: Inserir";
        cout << "\n ----2: Calcular altura";
        cout << "\n ----3: Caminhar em pre-ordem";
        cout << "\n ----4: Caminhar em pos-ordem";
        cout << "\n ----5: Remover";
        cout << "\n ----6: Sair do programa";
        cout << "\n***********************************";
        cout << "\n-> ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            /* Alinea a */
            vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};
            for(int i=0; i < (int) vtr.size(); i++){
                obj_tree.insert(vtr[i]);
            }
            cout << "\n Elementos inseridos com sucesso" << endl;
            break;
        }
        case 2:
        {
            Node *root = obj_tree.getRoot();
            cout << "\n\n Altura da árvore: " << obj_tree.getHeight() << endl;
            break;
        }
        case 3:
        {
            cout << "\n\n Travessia em pre-ordem da árvore BST: ";
            Node *root = obj_tree.getRoot();
            obj_tree.preOrder(root);
            delete root;
            break;
        }
        case 4:
        {
            cout << "\n\n Travessia em pos-ordem da arvore BST: ";
            Node *root = obj_tree.getRoot();
            obj_tree.posOrder(root);
            delete root;
            break;
        }
        case 5:
        {
            string value = "N";
            /* Alinea e */
            
            break;
        }
        }
    } while (option != 6);

    return 0;
}