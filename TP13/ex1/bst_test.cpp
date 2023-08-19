#include <iostream>
#include <string>
#include <vector>
#include "bst.cpp"


using namespace std;

int main()
{
  Tree bst;
  bst.insert("Lisboa","Portugal");
  bst.insert("Porto","Portugal");
  bst.insert("Braga","Portugal");
  bst.insert("Madrid","Espanha");
  bst.insert("Barcelona","Espanha");
  bst.insert("Vigo","Espanha");
  bst.insert("Sevilha","Espanha");
  bst.insert("Paris","França");
  bst.insert("Lille","França");
  bst.insert("Munique","Alemanha");
  bst.insert("Berlin","Alemanha");
  bst.insert("Colônia","Alemanha");
  bst.insert("Hamburgo","Alemanha");

 vector<string> paises={"Espanha","França"};

 cout <<"1 - Numero de cidades= "<< bst.numero_cidades(bst.getRoot(),paises)<< endl;

cout <<"2 - Numero de cidades= "<< bst.numero_cidades2(bst.getRoot(),'C', 'H')<< endl;
    return 0;
}