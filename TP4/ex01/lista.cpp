#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main()
{

  // a) criar a lista 
  // b) inserir jogos na lista
  // c) imprimir tamanho da lista
  ifstream file("arquivo.txt");
  list<string> g;
  string c;
  int k=0;
  if(!file){
    cout<<"Error! File Does not Exist";
    return -1;
  }
  while(file.eof()==0){
    getline(file, c);
    g.push_back(c);
    k++;
  }
  cout << "Foram carregados " << k << " jogos."<< endl;

  // d) imprimir conteúdo da lista
  cout << "Conteúdo da Lista:" << endl;
  list<string>::iterator it;
  k=0;
  for(auto it : g){
    cout << "Pos " << k << " -> " << it << '\n';
    k++;
  }
  // e) ordenar lista e imprimir
  cout << "\nLista Ordenada:" << endl;
  g.sort();
    k=0;
  for(auto it : g){
    cout << "Pos " << k << " -> " << it << '\n';
    k++;
  }
  // f) remover "Mario Kart (Wii)" e imprimir
  cout << "\nLista sem o jogo Mario Kart (Wii):" << endl;
  for(it = g.begin(); it != g.end(); it++){
    if(it->find("Mario Kart (Wii)") != string::npos){
      it = g.erase(it);
    }
  }
  k=0;
  for(it = g.begin(); it != g.end(); it++){
    cout << "Pos " << k << " -> " << *it << '\n';
    k++;
  }
  // g) remover jogos PS2 e imprimir
  cout << "\nLista sem jogos da PS2:" << endl;
  for(it = g.begin(); it != g.end(); it++){
   if(it->find("PS2") != string::npos){
      it = g.erase(it);
    }
  }
  k=0;
  for(auto it : g){
    cout << "Pos " << k << " -> " << it << '\n';
    k++;
  }
  return 0;
}