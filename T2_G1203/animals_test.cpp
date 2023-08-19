#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "decisionTree.hpp"
#include "decisionTree.cpp"
#include "animals.hpp"
#include "animals.cpp"

using namespace std;

int verifica_NodeAnimal_construtor(NodeAnimal **n1)
{
    int er = 0;
    string name="Elefante";
    string nameSc="Loxodonta";
    string classification="Mammalia";

   
    *n1 = new NodeAnimal(name,nameSc,classification);
    
    /*Teste 1*/
    if ((*n1) == nullptr)
    {
        cout << "...verifica_NodeAnimal_construtor: NodeAnimal e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: NodeAnimal nao e' NULL (ok)" << endl;

    /*Teste 2*/
    if ((*n1)->getScientificName()!=nameSc)
    {
        cout << "...verifica_NodeAnimal_construtor: ScientificName (= " << (*n1)->getScientificName() << ") e' diferente do esperado (= Loxodonta) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: ScientificName coincide com o esperado (= Loxodonta) (ok)" << endl;

    /*Teste 3*/
    if ((*n1)->getName()!=name) 
    {
        cout << "...verifica_NodeAnimal_construtor: Nome do Animal (= " << (*n1)->getName()<< ") e' diferente do esperado (=Elefante) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: Nome do Animal coincide com o esperado (= Elefante) (ok)" << endl;
    
    /*Teste 4*/
    if ((*n1)->getClassification()!= classification)
    {
        cout << "...verifica_NodeAnimal_construtor: Classificação do Animal (= " << (*n1)->getClassification() <<") e' diferente do esperado (= Mammalia) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: Classificação do Animal coincide com o esperado (= Mammalia) (ok)" <<endl;    
    
    /*Teste 5*/
    if ((*n1)->getVertebrate() != false )
    {
        cout << "...verifica_NodeAnimal_construtor: vertebrate(= "<< (*n1)->getVertebrate() <<") e' diferente do esperado (=false) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: vertebrate coincide com o esperado (= false) (ok)" << endl;

        /*Teste 6*/
    if ((*n1)->getCharacteristics().empty() != true )
    {
        cout << "...verifica_NodeAnimal_construtor: O vetor characteristics não está vazio (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: O vetor characteristics  está vazio (ok)" << endl;

        /*Teste 7*/
    if ((*n1)->left != nullptr )
    {
        cout << "...verifica_NodeAnimal_construtor: Filho da esquerda não é NULL (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: Filho da esquerda é NULL (ok)" << endl;

        /*Teste 8*/
    if ((*n1)->right != nullptr )
    {
        cout << "...verifica_NodeAnimal_construtor: Filho da direita é NULL (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_construtor: Filho da direita é NULL (ok)" << endl;

    return er;
}

int verifica_NodeAnimal_setters(NodeAnimal **n1)
{
    int er = 0; 
    if (!(*n1)) {
        cout << "...verifica_NodeAnimal_setters: NodeAnimal e' NULL (ERRO)" << endl;
        return 1;
    }

    (*n1)->setName("Macaco");
    (*n1)->setClassification("Primates"); 
    (*n1)->setVertebrate(true);
    

 
    /*Teste 1*/
    if ((*n1)->getName()!="Macaco") 
    {
        cout << "...verifica_NodeAnimal_setters: Nome do Animal (= " << (*n1)->getName()<< ") e' diferente do esperado (=Macaco) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_setters: Nome do Animal coincide com o esperado (= Macaco) (ok)" << endl;
    
    /*Teste 2*/
    if ((*n1)->getClassification()!= "Primates")
    {
        cout << "...verifica_NodeAnimal_setters: Classificação do Animal (= " << (*n1)->getClassification() <<") e' diferente do esperado (= Primates) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_setters: Classificação do Animal coincide com o esperado (= Primates) (ok)" <<endl;    
    
    /*Teste 3*/
    if ((*n1)->getVertebrate() != true )
    {
        cout << "...verifica_NodeAnimal_setters: vertebrate (= "<< (*n1)->getVertebrate() <<") e' diferente do esperado (=true) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_setters: vertebrate coincide com o esperado (= true) (ok)" << endl;




    return er;
}
int verifica_NodeAnimal_addCharacteristic(NodeAnimal **n1)
{
      int er = 0; 
    if (!(*n1)) {
        cout << "...verifica_NodeAnimal_addCharacteristic: NodeAnimal e' NULL (ERRO)" << endl;
        return 1;
    }
    (*n1)->addCharacteristic("No Feathers");
    (*n1)->addCharacteristic("Fur/Hair");
    if ((*n1)->getCharacteristics().size() != 2 )
    {
        cout << "...verifica_NodeAnimal_addCharacteristic: numero de entradas das caraterísticas(= "<< (*n1)->getCharacteristics().size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_addCharacteristic:  numero de entradas das caraterísticas coincide com o esperado (= 2) (ok)" << endl;

    if ((*n1)->getCharacteristics()[(*n1)->getCharacteristics().size()-1] != "Fur/Hair" )
    {
        cout << "...verifica_NodeAnimal_addCharacteristic: A última caraterísticas (= "<< (*n1)->getCharacteristics()[(*n1)->getCharacteristics().size()-1]  <<") e' diferente do esperado (=Fur/Hair) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_addCharacteristic: A última caraterísticas coincide com o esperado (= Fur/Hair) (ok)" << endl;


    return er;
}

int verifica_TreeBST_construtor(TreeBST **tree)
{
    int er = 0;

    *tree = new TreeBST(); 

    if (!(*tree))
    {
        cout << "...verifica_TreeBST_construtor: TreeBST e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_TreeBST_construtor: TreeBST nao e' NULL (ok)" << endl;

       if ((*tree)->getRoot()!=nullptr)
    {
        cout << "...verifica_TreeBST_construtor: root não e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_TreeBST_construtor: root e' NULL (ok)" << endl;



    return er;
}



int verifica_NodeAnimal_insert(TreeBST **tree)
{
    int er = 0, erro = 0;
       
    NodeAnimal *n1 = new NodeAnimal("Elefante", "Loxodonta", "Mammalia");
    NodeAnimal *n2 = new NodeAnimal("Macaco", "Primates", "Primatomorpha");
    NodeAnimal *n3 = new NodeAnimal("Falcão", "Falco", "Aves");
    NodeAnimal *n4 = new NodeAnimal("Tubarão", "Selachimorpha", "Chondrichthyes");

    /* Inserir Animal 1*/ 
    erro = (*tree)->insert(n1);
    if (erro == -1)
    {
        cout << "...verifica_NodeAnimal_insert: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Animal 2 */
    erro = (*tree)->insert(n2);
    if (erro == -1)
    {
        cout << "...verifica_NodeAnimal_insert: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Animal 3 */
    erro = (*tree)->insert(n3);
    if (erro == -1)
    {
        cout << "...verifica_NodeAnimal_insert: nao conseguiu inserir corretamente (ERRO)" << endl;
        return 1;
    }

    /* Inserir Animal 4 */
    erro = (*tree)->insert(n4);
    if (erro == 1)
    {
        cout << "...verifica_NodeAnimal_insert: nao conseguiu inserir corretamente (ERRO)" << endl;
        return 1;
    }
  
    /* Testes de Posições*/
    if ((*tree)->getRoot()->getScientificName() != "Loxodonta")
    {
        cout << "...verifica_NodeAnimal_insert: o animal na root (="<<(*tree)->getRoot()->getScientificName()  <<") e' diferente do esperado (=Loxodonta) (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_NodeAnimal_insert: o animal na root coincide com o esperado (=Loxodonta) (ok)" << endl;

    if ((*tree)->getRoot()->left->getScientificName() != "Falco")
    {
        cout << "...verifica_NodeAnimal_insert: o animal à esquerda da root(= "<< (*tree)->getRoot()->left->getScientificName()  <<") e' diferente do esperado (=Falco) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAnimal_insert: o animal à esquerda da root coincide com o esperado (= Falco) (ok)" << endl;    
    
     if ((*tree)->getRoot()->right->right->getScientificName() != "Selachimorpha")
    {
        cout << "...verifica_NodeAnimal_insert: o animal à direita da direita da root(= "<< (*tree)->getRoot()->right->right->getScientificName()  <<") e' diferente do esperado (=Selachimorpha) (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_NodeAnimal_insert: o animal à direita da direita da root coincide com o esperado (= Selachimorpha) (ok)" << endl;
    
    return er;
}



int verifica_import(TreeBST **tree)
{
    int er = 0;
    cout << "A importar TreeBST..." << endl;

    int  import_ok = (*tree)->import("animals.txt");

  
    if (import_ok == -1) {
        cout << "...verifica_import: Erro ao importar base de dados." << endl;
        return 1;
    }
    

    if (*tree == NULL)
    {
        cout << "...verifica_import: falhou importacao do TreeBST (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_import: NoAnimal importados com sucesso." << endl;
        }

        if ((*tree)->getRoot()->getScientificName() != "Inia geoffrensis")
        {
            cout << "...verifica_import: NoAnimal na root (="<< (*tree)->getRoot()->getScientificName() << ") e' diferente do esperado (= Inia geoffrensis) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_import: NoAnimal na root coincide com o esperado (= Inia geoffrensis) (ok)" << endl;
    
      if ((*tree)->getRoot()->left->getScientificName() != "Geotrypetes seraphini")
    {
        cout << "...verifica_import: NoAnimal da esquerda da root (="<< (*tree)->getRoot()->left->getScientificName() << ") e' diferente do esperado (= Geotrypetes seraphini) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_import: NoAnimal da esquerda da root coincide com o esperado (= Geotrypetes seraphini) (ok)" << endl;

  }    
  

  return er; 
}


int verifica_size(TreeBST **tree)
{
    int er = 0;
    int idxs;

    idxs = (*tree)->size();


    if (idxs!=150)
    {
        cout << "...verifica_size : Total de animais: (= "<< idxs <<") e' diferente do esperado (=150) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_size : Total de animais: "<< idxs<< " (ok)" << endl;

   
    return er;
}

void set_vertebrate(TreeBST **tree)
{
    ifstream input_file("vertebrate.txt"); // read from text file

    string buffer, scientific_name, boolean;
    stringstream ss_buffer;
    while (getline(input_file, buffer)) {
        if (buffer[buffer.length() - 1] == '\r') buffer.pop_back();
        ss_buffer.clear();
        ss_buffer << buffer;
        getline(ss_buffer, scientific_name, ',');
        getline(ss_buffer, boolean, ',');
        NodeAnimal *node = (*tree)->searchNode(scientific_name);
        if (node) {
            if (boolean == "TRUE") node->setVertebrate(true);
        }
    }
    input_file.close();
}

void reset_vertebrate(NodeAnimal *treeNode)
{
    if (treeNode) {
        treeNode->setVertebrate(false);
        reset_vertebrate(treeNode->left);
        reset_vertebrate(treeNode->right);
    }
}

int verifica_totalAnimals(TreeBST **tree)
{
    int er = 0;
   
    int idxs;
    
    set_vertebrate(tree);

    idxs = (*tree)->totalAnimals(false);
    
    reset_vertebrate((*tree)->getRoot());  

    if (idxs!=47)
    {
        cout << "...verifica_totalAnimals : Total de NoAnimals não vertebrados: (= "<< idxs <<") e' diferente do esperado (=47) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_totalAnimals : Total de NoAnimals não vertebrados: "<< idxs<< " (ok)" << endl;

    
    return er;
}

int verifica_searchCharacteristic(TreeBST **tree)
{
    int er = 0;
  


    if(((*tree)->getRoot()==nullptr) || ((*tree)->getRoot()->right==nullptr) || ((*tree)->getRoot()->left->right==nullptr))
    {
        cout << "...verifica_searchCharacteristic: TreeBST não está preenchida (ERRO)" << endl;
        return 1;
    }
    
    (*tree)->getRoot()->addCharacteristic("Pele");
    (*tree)->getRoot()->left->addCharacteristic("No Pele");
    (*tree)->getRoot()->left->addCharacteristic("Pele");
    (*tree)->getRoot()->left->right->addCharacteristic("No Pele");

    vector<NodeAnimal*> aux;

    aux.clear();
    aux = (*tree)->searchCharacteristic("Pele");

    if (aux.size()!=2)
    {
         cout << "...verifica_searchCharacteristic : Numero de animais com a carateristica Pele: (= "<< aux.size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_searchCharacteristic : Numero de animais com a carateristica Pele: "<< aux.size()<< " (ok)" << endl;

    (*tree)->getRoot()->removeCharacteristic("Pele");
    (*tree)->getRoot()->left->removeCharacteristic("No Pele");
    (*tree)->getRoot()->left->removeCharacteristic("Pele");
    (*tree)->getRoot()->left->right->removeCharacteristic("No Pele");
    

    return er;
}

int verifica_commonCharacteristic(TreeBST **tree)
{
    int er = 0;
   
 if(((*tree)->getRoot()==nullptr) || ((*tree)->getRoot()->right==nullptr) || ((*tree)->getRoot()->left->right==nullptr))
    {
        cout << "...verifica_commonCharacteristic: TreeBST não está preenchida (ERRO)" << endl;
        return 1;
    }

    (*tree)->getRoot()->addCharacteristic("Pele");
    (*tree)->getRoot()->addCharacteristic("Cauda");
    (*tree)->getRoot()->left->addCharacteristic("No Pele");
    (*tree)->getRoot()->left->addCharacteristic("Pele");
    (*tree)->getRoot()->left->right->addCharacteristic("Pele");
    (*tree)->getRoot()->right->addCharacteristic("Pele");
    (*tree)->getRoot()->right->addCharacteristic("Cauda");
  
    int aux=(*tree)->commonCharacteristic("Pele","Cauda");

       if (aux!=2)
    {
         cout << "...verifica_commonCharacteristic : Numero de animais com a carateristica Pele e Cauda: (= "<< aux <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_commonCharacteristic : Numero de animais com a carateristica Pele e Cauda: "<< aux<< " (ok)" << endl;

    (*tree)->getRoot()->removeCharacteristic("Pele");
    (*tree)->getRoot()->removeCharacteristic("Cauda");
    (*tree)->getRoot()->left->removeCharacteristic("No Pele");
    (*tree)->getRoot()->left->removeCharacteristic("Pele");
    (*tree)->getRoot()->left->right->removeCharacteristic("No Pele");
    (*tree)->getRoot()->right->removeCharacteristic("Pele");
    (*tree)->getRoot()->right->removeCharacteristic("Cauda");
    return er; 
}


int verifica_positionDictionary(TreeBST **tree)
{
    int er = 0;
   
    int idxs;

    idxs = (*tree)->positionDictionary("Apteryx haastii");


    if (idxs!=11)
    {
        cout << "...verifica_positionDictionary : A posição de Apteryx haastii: (= "<< idxs <<") e' diferente do esperado (=11) (ERRO)" << endl;
        er++;
    }
    else{
        cout << "...verifica_positionDictionary : A posição de Apteryx haastii: "<< idxs<< " (ok)" << endl;
    }
    
    return er;
}


int verifica_updateCharacteristicsFromFile(DecisionTree **treeDT,TreeBST  **tree)
{
    int er = 0;
    if(((*tree)->getRoot()==nullptr))
    {
        cout << "...verifica_updateCharacteristicsFromFile: TreeBST não está preenchida (ERRO)" << endl;
        return 1;
    }
  


    int  import_ok = (*tree)->updateCharacteristicsFromFile((**treeDT),"classification_file.txt");

  
    if (import_ok == -1) {
        cout << "...verifica_updateCharacteristicsFromFile: Erro ao importar carateristicas da arvore de decisão." << endl;
        return 1;
    }
    

    if(import_ok == 0) {
        cout << "...verifica_updateCharacteristicsFromFile: Carateristicas importadas com sucesso." << endl;
        }

    if ((*tree)->getRoot()->getVertebrate() != true)
        {
            cout << "...verifica_updateCharacteristicsFromFile: Carateristica Vertebrado na root (="<< (*tree)->getRoot()->getVertebrate() << ") e' diferente do esperado (= true) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_updateCharacteristicsFromFile: Carateristica Vertebrado na root coincide com o esperado (= true) (ok)" << endl;
    
      if ((*tree)->getRoot()->left->left->getCharacteristics().size() != 8)
    {
        cout << "...verifica_updateCharacteristicsFromFile: Numero das carateristicas do NoAnimal da esquerda da esquerda da root (="<< (*tree)->getRoot()->left->left->getCharacteristics().size() << ") e' diferente do esperado (= 8) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_updateCharacteristicsFromFile: Numero das carateristicas do NoAnimal da esquerda da esquerda da root coincide com o esperado (= 8) (ok)" << endl;

   if ((*tree)->getRoot()->left->left->getClassification() != "Carnivore")
    {
        cout << "...verifica_updateCharacteristicsFromFile: Classificação do NoAnimal da esquerda da esquerda da root (= "<< (*tree)->getRoot()->left->left->getClassification()<<") e' diferente do esperado (=Carnivore) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_updateCharacteristicsFromFile: Classificação do NoAnimal da esquerda da esquerda da root coincide com o esperado (= Carnivore) (ok)" << endl;    
   
   //  (*tree)->print((*tree)->getRoot());
     return er; 
}



int verifica_updateCharacteristicsFromClassification(DecisionTree **treeDT,TreeBST  **tree)
{
    int er = 0;
    if(((*tree)->getRoot()==nullptr))
    {
        cout << "...verifica_updateCharacteristicsFromClassification: TreeBST não está preenchida (ERRO)" << endl;
        return 1;
    }
   

    NodeAnimal *animal;
            animal = (*tree)->searchNode("Cavia cobaya");
            animal->setClassification("Rodent");
   int  import_ok = (*tree)->updateCharacteristicsFromClassification((**treeDT),"Cavia cobaya");

   /* cout << animal->getCharacteristics().size()<<endl;

    for (int i=0;i<(int)animal->getCharacteristics().size();i++)
    {
        cout << animal->getCharacteristics()[i]<<endl;
    }

    cout << animal->getVertebrate()<<endl; */
    

  
    if (import_ok == -1) {
        cout << "...verifica_updateCharacteristicsFromClassification: Erro ao importar carateristicas da arvore de decisão." << endl;
        return 1;
    }
    

    if(import_ok == 0) {
        cout << "...verifica_updateCharacteristicsFromClassification: Carateristicas importadas com sucesso." << endl;
        }

    if (animal->getVertebrate() != true)
        {
            cout << "...verifica_updateCharacteristicsFromClassification: Carateristica Vertebrado do NoAnimal Cavia cobaya (="<< animal->getVertebrate() << ") e' diferente do esperado (= true) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_updateCharacteristicsFromClassification: Carateristica Vertebrado do NoAnimal Cavia cobaya coincide com o esperado (= true) (ok)" << endl;
    
      if (animal->getCharacteristics().size() != 9)
    {
        cout << "...verifica_updateCharacteristicsFromClassification: Numero das carateristicas do NoAnimal Cavia cobaya (="<< animal->getCharacteristics().size() << ") e' diferente do esperado (= 9) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_updateCharacteristicsFromClassification: Numero das carateristicas do NoAnimal Cavia cobaya coincide com o esperado (= 9) (ok)" << endl;

    if ((animal->getCharacteristics()[0] != "No Feathers") && (animal->getCharacteristics()[1] != "Fur/Hair"))
    {
        cout << "...verifica_updateCharacteristicsFromFile: 1ª e 2ª carateristicas do NoAnimal Cavia cobaya (= "<< animal->getCharacteristics()[0]<<","<<animal->getCharacteristics()[1]<<") e' diferente do esperado (=No Feathers,Fur/Hair) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_updateCharacteristicsFromFile: 1ª e 2ª carateristicas do NoAnimal Cavia cobaya  coincidem com o esperado (= No Feathers,Fur/Hair) (ok)" << endl;    

   //  (*tree)->print((*tree)->getRoot());
     return er; 
}

int main()
{
    int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    
    /* Verifica construtor do NodeAnimal */
    NodeAnimal *n1;
    error = verifica_NodeAnimal_construtor(&n1);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_NodeAnimal_construtor\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAnimal_construtor passou\n\n" << endl;
    }  
  

  

    /*Verifica setters de NodeAnimal */
    error = verifica_NodeAnimal_setters(&n1);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_NodeAnimal_setters\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAnimal_setters passou\n\n" << endl;
    }

    /* Verifica addCharacteristic */
    error = verifica_NodeAnimal_addCharacteristic(&n1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_NodeAnimal_addCharacteristic\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAnimal_addCharacteristic passou\n\n" << endl;
    }


 

      /* Verifica construtor do TreeBST */
    TreeBST *tree;
    error = verifica_TreeBST_construtor(&tree);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_TreeBST_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_TreeBST_construtor passou\n\n" << endl;
    }


    /* Verifica NodeAnimal insere*/ 
    error = verifica_NodeAnimal_insert(&tree);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_NodeAnimal_insert\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAnimal_insert passou\n\n" << endl;
    }


    /* Verifica componente remove */
    // error = verifica_NodeAnimal_remove(&tree);
    // if (error)
    // {
    //     cout << "ERRO: " << error << " erros encontrados em verifica_NodeAnimal_remove\n\n" << endl;
    //     errorCount += error;
    // }
    // else
    // {
    //     cout << "OK: verifica_NodeAnimal_remove passou\n\n" << endl;
    // }


    /* Verifica importa*/ 
   TreeBST *tree1 = new TreeBST;
    error = verifica_import(&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_import\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout<< "OK: verifica_import passou\n\n" << endl;
    }

    /* Verifica size*/
  
    error = verifica_size(&tree1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_size\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_size passou\n\n" << endl;
    }

     
    error = verifica_totalAnimals(&tree1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_totalAnimals\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_totalAnimals passou\n\n" << endl;
    }

 
    error = verifica_searchCharacteristic(&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_searchCharacteristic\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_searchCharacteristic passou\n\n" << endl;
    }

     error = verifica_commonCharacteristic(&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_commonCharacteristic\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_commonCharacteristic passou\n\n" << endl;
    }

         error = verifica_positionDictionary(&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_positionDictionary\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_positionDictionary passou\n\n" << endl;
    }

    cout << "A importar TreeDT..." << endl;
    DecisionTree *treeDT=new DecisionTree;
    treeDT->import("decision_tree.txt");


     error = verifica_updateCharacteristicsFromFile(&treeDT,&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_updateCharacteristicsFromFile\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_updateCharacteristicsFromFile passou\n\n" << endl;
    }

     error = verifica_updateCharacteristicsFromClassification(&treeDT,&tree1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_updateCharacteristicsFromClassification\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_updateCharacteristicsFromClassification passou\n\n" << endl;
    }

    /* Fim dos testes */
    if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    delete n1;
    delete tree;
    delete tree1;
    delete treeDT;

    return 0;
}
