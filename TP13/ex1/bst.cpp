// Arvore Binária em C++ usando Classe e Struct

#include <iostream>
#include <stdlib.h>
#include "bst.hpp"

using namespace std;

Tree::Tree()
{ // inicializa arvore
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

void Tree::insert(string ci, string pa)
{
  insert(root, ci, pa);
}

void Tree::insert(Node *treeNode, string ci, string pa)
{
  if (!treeNode)
  {
    treeNode = new Node();
    treeNode->left=NULL;
    treeNode->right=NULL;
    treeNode->cidade = ci;
    treeNode->cidade = pa;
    root = treeNode;
  }
  else
  {
    if (ci < treeNode->cidade)
    {
      if (!treeNode->left)
      {
        Node *treeTemp = new Node();
        treeTemp->cidade = ci;
        treeTemp->pais = pa;
        treeTemp->left=NULL;
    treeTemp->right=NULL;
        treeNode->left = treeTemp;
      }
      else
        insert(treeNode->left, ci, pa);
    }
    else
    {
      if (!treeNode->right)
      {
        Node *treeTemp = new Node();
         treeTemp->left=NULL;
    treeTemp->right=NULL;
        treeTemp->cidade = ci;
        treeTemp->pais = pa;
        treeNode->right = treeTemp;
      }
      else
        insert(treeNode->right, ci, pa);
    }
  }
}

Node *Tree::search_node(string ci)
{
  if (root == NULL)
    return NULL;        // se arvore vazia
  Node *current = root; // começa a procurar desde raiz
  while (current->cidade != ci)
  { // enquanto nao encontrou
    if (ci < current->cidade)
    {
      current = current->left; // caminha para esquerda
    }
    else
    {
      current = current->right; // caminha para direita
    }
    if (current == NULL)
    {
      return NULL; // encontrou uma folha -> sai
    }
  }               // fim laço while
  return current; // terminou o laço while e chegou aqui é pq encontrou item
}

bool Tree::remove(string ci)
{
  if (root == NULL)
    return false; // se arvore vazia
  Node *current = root;
  Node *father = root;
  bool left_child = true;
  // ****** Buscando o valor **********
  while (current->cidade != ci)
  { // enquanto nao encontrou

  cout << ci<<endl;
    father = current;
    if (ci < current->cidade)
    { // caminha para esquerda
      cout << ci <<" - "<< current->cidade <<endl;
      current = current->left;
      left_child = true; // é filho a esquerda? sim
    }
    else
    { // caminha para direita
     cout << ci <<" - "<< current->cidade <<endl;
      current = current->right;
      left_child = false; // é filho a esquerda? NAO
    }
    if (current == NULL)
      return false; // encontrou uma folha -> sai
  }                 // fim laço while de busca do valor

  // **************************************************************
  // se chegou aqui quer dizer que encontrou o valor (v)
  // "atual": contem a referencia ao No a ser eliminado
  // "pai": contem a referencia para o pai do No a ser eliminado
  // "filho_esq": é verdadeiro se atual é filho a esquerda do pai
  // **************************************************************

  // Se nao possui nenhum filho (é uma folha), elimine-o
  if (current->left == NULL && current->right == NULL)
  {
    if (current == root)
      root = NULL; // se raiz
    else if (left_child)
      father->left = NULL; // se for filho a esquerda do pai
    else
      father->right = NULL; // se for filho a direita do pai
  }

  // Se é pai e nao possui um filho a direita, substitui pela subarvore a esquerda
  else if (current->right == NULL)
  {
    if (current == root)
      root = current->left; // se raiz
    else if (left_child)
      father->left = current->left; // se for filho a esquerda do pai
    else
      father->right = current->left; // se for filho a direita do pai
  }

  // Se é pai e nao possui um filho a esquerda, substitui pela subarvore a direita
  else if (current->left == NULL)
  {
    if (current == root)
      root = current->right; // se raiz
    else if (left_child)
      father->left = current->right; // se for filho a esquerda do pai
    else
      father->right = current->right; // se for  filho a direita do pai
  }

  // Se possui mais de um filho, se for um avô ou outro grau maior de parentesco
  else
  {
    Node *sucessor = node_sucessor(current);
    remove(sucessor->cidade);
    // Usando sucessor que seria o Nó mais a esquerda da subarvore a direita do No que deseja-se remover
    if (current == root)
      root = sucessor; // se raiz
    else if (left_child)
      father->left = sucessor; // se for filho a esquerda do pai
    else
      father->right = sucessor;     // se for filho a direita do pai
    sucessor->left = current->left; 
     sucessor->right = current->right; // acertando o ponteiro a esquerda do sucessor agora que ele assumiu
                                    // a posição correta na arvore
  }
  return true;
}

/* Caminha em pos-ordem */
void Tree::posOrder(Node *current)
{
  if (current != NULL)
  {
    posOrder(current->left);
    posOrder(current->right);
    cout << current->cidade << " ";
  }
}

/* Caminha em pre-ordem */
void Tree::preOrder(Node *current)
{
  if (current != NULL)
  {
    cout << current->cidade << " ";
    preOrder(current->left);
    preOrder(current->right);
  }
}

int Tree::getHeight()
{
  return getHeight(root);
}

/* Calcula a altura da árvore a partir de um nó */
int Tree::getHeight(Node *treeNode)
{
  if(treeNode == NULL || (treeNode->left == NULL && treeNode->right == NULL))
       return 0;
     else {
   	if (getHeight(treeNode->left) > getHeight(treeNode->right))
   	   return (1 + getHeight(treeNode->left));
   	else
	   return (1 + getHeight(treeNode->right));
     }
}

/* Calcula a quantidade de folhas */
int Tree::seeds(Node *current)
{
  if (current == NULL)
    return 0;
  if (current->left == NULL && current->right == NULL)
    return 1;
  return seeds(current->left) + seeds(current->right);
}

/* Conta a quantidade de nos */
int Tree::countNodes(Node *current)
{
  if (current == NULL)
    return 0;
  else
    return (1 + countNodes(current->left) + countNodes(current->right));
}

/* Encontra o no de menor valor */
string Tree::getMinNode()
{
  Node *current = root;
  Node *previous = NULL;
  while (current != NULL)
  {
    previous = current;
    current = current->left;
  }
  return previous->cidade;
}

/* Encontra o nó de maior valor */
string Tree::getMaxNode()
{
  Node *current = root;
  Node *previous = NULL;
  while (current != NULL)
  {
    previous = current;
    current = current->right;
  }
  return previous->cidade;
}

bool Tree::isBalanced()
{
  return isBalanced(root);
}

bool Tree::isBalanced(Node *treeNode)
{
  if (!treeNode)
    return false;
  int leftHeight = getHeight(treeNode->left);
  int rightHeight = getHeight(treeNode->right);

  if (abs(leftHeight - rightHeight) > 1)
    return false;
  return true;
}

/* O sucessor é o No mais a esquerda da subarvore a direita do No que foi passado como parametro do metodo */
Node *Tree::node_sucessor(Node *del)
{ // O parametro é a referencia para o No que deseja-se apagar
  Node *sucessor_father = del;
  Node *sucessor = del;
  Node *current = del->right; // vai para a subarvore a direita

  while (current != NULL)
  { // enquanto nao chegar no Nó mais a esquerda
    sucessor_father = sucessor;
    sucessor = current;
    current = current->left; // caminha para a esquerda
  }
  // *********************************************************************************
  // quando sair do while "sucessor" será o Nó mais a esquerda da subarvore a direita
  // "sucessor_father" será o o pai de sucessor e "del" o Nó que deverá ser eliminado
  // *********************************************************************************

  if (sucessor != del->right)
  {                                                 // se sucessor nao é o filho a direita do Nó que deverá ser eliminado
    sucessor_father->left = sucessor_father->right; // pai herda os filhos do sucessor que sempre serão a direita
    // lembre que o sucessor nunca poderá ter filhos a esquerda, pois, ele sempre será o
    // Nó mais a esquerda da subarvore a direita do Nó del.
    // lembrando também que sucessor sempre será o filho a esquerda do pai

    sucessor->right = del->right; // guardando a referencia a direita do sucessor para
                                  // quando ele assumir a posição correta na arvore
  }
  return sucessor;
}
int Tree::numero_cidades(Node *treeNode, vector<string> paises)
{
  /*responder aqui*/
  if(treeNode == nullptr){
    return 0;
  }
  int count = 0;
  for(auto it : paises){
    if(it == treeNode->pais){
      count++;
    }
  }
  count += numero_cidades(treeNode->left, paises);
  count += numero_cidades(treeNode->right, paises);

  return count;
}
int Tree::numero_cidades2(Node *treeNode, char min, char max)
{
    /*responder aqui*/
    if(treeNode == nullptr){
      return 0;
    }
    int count=0;
    if(treeNode->cidade[0] <= max && treeNode->cidade[0] >= min){
      count++;
    }

    count += numero_cidades2(treeNode->left, min, max);
    count += numero_cidades2(treeNode->right, min, max);

    return count;
}