#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include "animals.hpp"

using namespace std;

/* ------------------------------ */
/* ------ CLASS NodeAnimal ------ */
/* ------------------------------ */

/* CONSTRUTORES */

NodeAnimal::NodeAnimal(string name, string scientificName, string classification)
{
    /* Função 1 */
    if(!name.empty()){ //só atribui o name caso seja valido
        this->name = name;
    }
    if(!scientificName.empty()){    //só atribui o scientificName caso seja valido
        this->scientificName = scientificName;
    }
    if(!classification.empty()){    // só atribui o classification caso seja valido
        this->classification = classification;
    }
    this->vertebrate=false;        //inicializa tudo vazio 
    this->right=nullptr;
    this->left=nullptr;
    this->characteristics = {};
}

NodeAnimal::NodeAnimal(string name, string scientificName)
{
    /* Função 2 */ 
    if(!name.empty()){   //só atribui o name caso seja valido
        this->name = name;
    }
    if(!scientificName.empty()){  //só atribui o scientificName caso seja valido
        this->scientificName = scientificName;
    }
    this->classification = "";  //inicializa tudo vazio 
    this->vertebrate=false;
    this->right=nullptr;
    this->left=nullptr;
    this->characteristics = {};
}

/* DESTRUTOR */

NodeAnimal::~NodeAnimal()
{
    /* Função 3 */
    delete this->right;  //deleta o filha da direita
    delete this->left;  //deleta o filha da esquerda
}

/* MÉTODOS GET */

string NodeAnimal::getName() const
{
    /* Função 4 */
    return this->name; //retorna o nome do animal
}

string NodeAnimal::getScientificName() const
{
    /* Função 5 */
    return this->scientificName; //retorna o scientificName do animal
}

string NodeAnimal::getClassification() const
{
    /* Função 6 */
    return this->classification;  //retorna o classification do animal
}

bool NodeAnimal::getVertebrate() const
{
    /* Função 7 */
    return this->vertebrate; //retorna o vertebrate do animal
}

vector<string> NodeAnimal::getCharacteristics() const
{
    /* Função 8 */
    return this->characteristics;  //retorna as characteristics do animal
}

/* MÉTODOS SET */

void NodeAnimal::setName(string name)
{
    /* Função 9 */
    if(!name.empty()){ //certifica se o nome é valido e atribui o dado pelo argumento
        this->name = name;
    }
}

void NodeAnimal::setClassification(string classification)
{
    /* Função 10 */
    if(!classification.empty()){ //certifica se o classification é valido e atribui o dado pelo argumento
        this->classification = classification;
    }
}

void NodeAnimal::setVertebrate(bool vertebrate)
{
    /* Função 11 */
    this->vertebrate = vertebrate; //atribui o vertebrate do animal
}

/* OUTROS MÉTODOS */

void NodeAnimal::addCharacteristic(string characteristic)
{
    /* Função 12 */
    if(!characteristic.empty()){ //certifica se o characteristic é valido e atribui o dado pelo argument
        this->characteristics.push_back(characteristic);
    }
}

int NodeAnimal::removeCharacteristic(string characteristic)
{
    /* Função 13 */
    if(characteristic.empty()){ //retorna -1 caso o argumento é vazio
        return -1;
    }
    if(find(this->characteristics.begin(), this->characteristics.end(), characteristic)==this->characteristics.end()){ // retorna 0 caso o argumento não existir
        return 0;
    }
    this->characteristics.erase(find(this->characteristics.begin(), this->characteristics.end(), characteristic)); // remove o argumento das characteristics
    return 1; // retorna 1 caso o argumento foi removido com sucesso
}

/* ------------------------------ */
/* ------- CLASS TreeBST -------- */
/* ------------------------------ */

/* CONSTRUTOR */

TreeBST::TreeBST()
{
    /* Função 14 */
    this->root=nullptr; //inicializa a root a nullptr
}

/* DESTRUTOR */

TreeBST::~TreeBST()
{
    /* Função 15 */
    delete this->root; // apaga a raíz
}

/* MÉTODOS GET */

NodeAnimal* TreeBST::getRoot()
{
    /* Função 16 */
    return this->root; // retorna a raíz
}

/* MÉTODOS SET */

void TreeBST::setRoot(NodeAnimal *newRoot)
{
    /* Função 17 */
    if(newRoot!=nullptr){  // verifica se o argumento é valido e atribui o argumento à raiz
        this->root = newRoot;
    }
}

/* OUTROS MÉTODOS */

int TreeBST::insert(NodeAnimal *treeNode, NodeAnimal *newNoA)
{
    /* Função 18 */
    if(newNoA==nullptr){ // verifica se o argumento não é valido e retorna -1
        return -1;
    }

    if(treeNode==nullptr){  // se a treeNode é vazia, passa o novo nó para a raiz
        root = newNoA;
        return 0;
    }
    
    if(newNoA->getScientificName()<treeNode->getScientificName()){ //se o scientificName for maior que o novo nó insere no filho da esquerda
        if(treeNode->left!=nullptr){ 
            insert(treeNode->left, newNoA);
        }
        else{
            treeNode->left = newNoA;
        }
    }
    if(newNoA->getScientificName()>treeNode->getScientificName()){ // se o scientificName for menor que o novo nó insere no filho da direita
        if(treeNode->right!=nullptr){
            insert(treeNode->right, newNoA);
        }
        else{
            treeNode->right = newNoA;
        }
    }

    return 0;
}

int TreeBST::insert(NodeAnimal *newNoA)
{
    if (newNoA == nullptr)
    {
        return(-1);
    }
    else
    /*Chama função recursiva com a raiz*/
    {
        return(insert(root, newNoA));
    }
}

NodeAnimal* TreeBST::searchNode(string scientificName)
{
    /* Função 19 */
    if(root==nullptr || scientificName.empty()){ // verifica se os argumentos são validos e retorna nullptr
        return(nullptr);
    }
    NodeAnimal *root_aux = root;
    while(root_aux->getScientificName() != scientificName){ // enquanto o nó auxiliar não for igual ao nó a ser pesquisado vai de ramo em ramo á procura do nó pedido
        if(root_aux->getScientificName() > scientificName){
            root_aux = root_aux->left;
        }
        else{
            root_aux = root_aux->right;
        }
        if(root_aux==nullptr){
            return(nullptr);
        }
    }
    return(root_aux);
}

int TreeBST::totalAnimals(NodeAnimal* root,bool vert)
{
    /* Função 20 */
    if (root == nullptr) { // verifica se os argumentos são validos e retorna -1
        return 0;
    }
    
    int sum = (root->getVertebrate() == vert) ? 1 : 0; //caso o animal no nó for vertebrado ou não, a soma vai ser inicializada a 1 ou 0

    sum += totalAnimals(root->left, vert); //recursão para ir pelos ramos da esquerda todos para somar os animais (in)vertebrados
    sum += totalAnimals(root->right, vert); //recursão para ir pelos ramos da direita todos para somar os animais (in)vertebrados

    return sum;
}

int TreeBST::totalAnimals(bool vert)
{
    return(totalAnimals(root, vert)); 
}

int TreeBST::size(NodeAnimal* root)
{
    /* Função 21 */
    int sum = 1; //é inicializado a 1 para que adicione o primeiro nó
    if (root->left!= nullptr){ //adicionar todos os animals da esquerda
        sum += size(root->left);
    }
    if(root->right!=nullptr){ //adicionar todos os animals da direita
        sum += size(root->right);
    }
    return sum;
}

int TreeBST::size()
{
    return(size(root));
}

vector<NodeAnimal*> TreeBST::searchCharacteristic(NodeAnimal* root, string charac)
{
    /* Função 22 */
    vector<NodeAnimal*> result, result_left, result_right; //criar variaveis para guardas os resultados e initializa-las vazias
    result.clear();
    result_left.clear();
    result_right.clear();
    if(root==nullptr || charac.empty()){ //verifica se os argumentos são validos e retorna o vector vazio
        return result;
    }
    for(int i=0; i < (int) root->getCharacteristics().size(); i++){ //loop q passa pelas caracteristicas todas e adiciona os que são pedidos aos resultados
        if(root->getCharacteristics()[i] == charac){
            result.push_back(root);
        }
    }
    result_left = searchCharacteristic(root->left, charac); //recursão para ir pelos ramos da esquerda todos para colocar no resultado os animals da esquerda 
    result_right = searchCharacteristic(root->right, charac); //recursão para ir pelos ramos da direita todos para colocar no resultado os animals da direita
    result.insert(result.end(), result_left.begin(), result_left.end()); //adiciona os resultados da esquerda na variaval resultado
    result.insert(result.end(), result_right.begin(), result_right.end()); //adiciona os resultados da direita na variaval resultado
    return(result);
}

vector<NodeAnimal*> TreeBST::searchCharacteristic(string charac)
{
    vector<NodeAnimal*> result;
    if(!charac.empty())
    {
        result = searchCharacteristic(root, charac);
    }
    else
    {
        result.clear();
    }
    return(result);
}

int TreeBST::commonCharacteristic(NodeAnimal* root, string charac1, string charac2)
{
    /* Função 23 */
    if(charac1.empty() || charac2.empty()){ //verifica se os argumentos não são validos e retorna -1
        return -1;
    }
    if(root==nullptr){ // se a root é vazia, retorna 0
        return 0;
    }
    int num=0, num_left=0, num_right=0;;
    vector<string> vec_aux = root->getCharacteristics();
    if(find(vec_aux.begin(), vec_aux.end(), charac1)!=vec_aux.end()){ //verifica se o charac1 foi encontrado 
        if(find(vec_aux.begin(), vec_aux.end(), charac2)!=vec_aux.end()){ //verifica se o charac2 foi encontrado
            num++; //caso ambos os charac1 e charac2 estão encontrados, incrementa o numero
        } 
    }
    num_left = commonCharacteristic(root->left, charac1, charac2); //recursão para ir pelos ramos da esquerda todos
    num_right = commonCharacteristic(root->right, charac1, charac2); //recursão para ir pelos ramos da direita todos
    num += num_left+num_right;
    return num;

}

int TreeBST::commonCharacteristic(string charac1, string charac2)
{
    int result;
    if(charac1.empty() || charac2.empty())
    {
        result = 0;
    }
    else
    {
        result = commonCharacteristic(root, charac1, charac2);
    }
    return(result);
}

int TreeBST::import(const string filename)
{
    if (filename.empty())
    {
        return -1;
    }
    
    ifstream f(filename);
    
    if (!f)
    {
        return -1;
    }
    
    string scientificName, name;
    
    NodeAnimal *n;
    int result;

    string s;
    stringstream ss, ssd;
    char delim = ',';

    while (getline(f, s))
    {
        s.pop_back();
        ss.clear();
        ss << s;
    
        getline(ss, scientificName, delim);
        getline(ss, name, delim);
    
        n = new NodeAnimal(name, scientificName );

        if (!n)
        {
            delete n;
            f.close();
            return -1;
        }

        result = insert(n);
    
        if (result == -1)
        {
            delete n;
            f.close();
            return -1;
        }
    }

    f.close();
    
    return 0;
}

priority_queue<string,vector<string>, greater<string>>* TreeBST::createDictionary(NodeAnimal* root)
{
    /* Função 24 */
    priority_queue<string,vector<string>, greater<string>>* newDict = new priority_queue<string,vector<string>, greater<string>>; //cria o dicionario a entregar
    if(root==nullptr){ //se a root é vazia, retorna o dicionario vazio
        return newDict;
    }
    newDict->push(root->getScientificName());
    priority_queue<string,vector<string>, greater<string>>* left = createDictionary(root->left); //recursão para ir pelos ramos da esquerda todos
    priority_queue<string,vector<string>, greater<string>>* right = createDictionary(root->right); //recursão para ir pelos ramos da direita todos
    while(!left->empty()){ //enquanto o ramo da esquerda não for vazio, adiciona as classificões da esquerda ao dicionario
        newDict->push(left->top());
        left->pop();
    }
    while(!right->empty()){ //enquanto o ramo da direita não for vazio, adiciona as classificões da direita ao dicionario
        newDict->push(right->top());
        right->pop();
    }
    return newDict;
}

int TreeBST::positionDictionary(string scientificName)
{
    /* Função 25 */
    if(scientificName.empty()){ //verifica se os argumentos não são validos e retorna -1
        return -1;
    }
    priority_queue<string,vector<string>, greater<string>>* newDict;
    newDict = createDictionary(root);
    int pos, k=0;
    while(!newDict->empty()){ //enquanto o dicionario não for vazio, procura o scientificName e guarda a posicao
        if(newDict->top() == scientificName){
            pos = k;
        }
        newDict->pop();
        k++;
    }
    return pos+1; //retorna o posicao do dicionario +1 por causa da posição da raiz
}

int TreeBST::updateCharacteristicsFromFile(DecisionTree &treeB, const string filename)
{
    /* Função 26 3*/
    if (filename.empty()) { //verifica se os argumentos não são validos e retorna -1
        return -1;
    }
    ifstream file(filename);
    if (!file) { //verifica se o arquivo foi encontrado
        return -1;
    }
    string line;
    while (getline(file, line)) { //lê o ficheiro e guarda linha a linha
        if (line.back() == '\r'){ 
            line.pop_back();
        }
        stringstream ss(line); //usa uma stringstream para dividir os caracteres da linha
        string scientificName; //variavel para guardar o primeiro string
        getline(ss, scientificName, ',');

        vector<string> decisionN;
        string decision;
        while (getline(ss, decision, ',')) { // guarda o resto dos strings no vector
            decisionN.push_back(decision);
        }
        
        NodeAnimal* node_animal = searchNode(scientificName);   // encontrar o node animal com o scientificName
        if(node_animal==NULL){ //se o node animal nao encontrado, retorna -1
            return -1;
        }
        Node* node_treeB = treeB.getRoot(); //guarda a raiz noutra variavel
        if (decisionN.empty()) { //se o vector de decisions é vazio, retorna -1
            return -1;
        }
        if (decisionN[0]=="Yes"){ //se a primeira decisão for sim passa a vertebrate a true e passa ao proximo nó
            node_animal->setVertebrate(true);
            node_treeB=node_treeB->getLeft();
        }
        if (decisionN[0]=="No"){ //se a primeira decisão for não passa a vertebrate a true e passa ao proximo nó
            node_animal->setVertebrate(false);
            node_treeB=node_treeB->getRight();
        }
        for(int i=1; i<(int)decisionN.size(); i++){ //faz o mesmo só para as outras decisôes e adiciona as características
            if(decisionN[i]=="Yes"){
                node_animal->addCharacteristic("Yes" + node_treeB->getData());
                
                node_treeB=node_treeB->getLeft();
            }
            if(decisionN[i]=="No"){
                node_animal->addCharacteristic("No" + node_treeB->getData());
                node_treeB=node_treeB->getRight();
            }
        }
        node_animal->setClassification(node_treeB->getData()); // adiciona a ultima característica que é a data da decision tree
    }
    return 0;
}

int TreeBST::updateCharacteristicsFromClassification(DecisionTree &treeB, string scientificName)
{
    /* Função 27 */
    if (scientificName.empty()) { //verifica se os argumentos não são validos e retorna -1
        return -1;
    }
    NodeAnimal* node_animal = searchNode(scientificName);
    string class_aux = node_animal->getClassification();
    queue<Node*> queueNodes;
    queue<vector<string>> nodePath;
    vector<string> path, elem_path_aux, elemPath;
    Node* elemNode; 
    queueNodes.push( treeB.getRoot());
    nodePath.push({});
    while(!queueNodes.empty()){ //um loop que vai rodar até dar break ou seja encontrar a classificação do animal
        elemNode = queueNodes.front();
        elemPath = nodePath.front();
        queueNodes.pop();
        nodePath.pop();
        if(elemNode->getData()==class_aux){ // quando encontra dá break
            path = elemPath;
            break;
        }
        if(elemNode->getLeft()!=NULL){ //passa pelos elementos todos da esquerda
            queueNodes.push(elemNode->getLeft());
            elem_path_aux=elemPath;
            elem_path_aux.push_back("Yes " + elemNode->getData()); //guarda as caracteristas e um sim na variavel
            nodePath.push(elem_path_aux);
        }
        if(elemNode->getRight()!=NULL){ //passa pelos elementos todos da direita
            queueNodes.push(elemNode->getRight());
            elemPath.push_back("No " + elemNode->getData()); //guarda as caracteristas e um não na variavel
            nodePath.push(elemPath);
        }
    }
    node_animal->setVertebrate(path[0] == "Yes Backbone"); //atribui a vertebrate como true caso o primeiro característica for yes backbone 
    for(int i=1; i<(int)path.size(); i++){
        node_animal->addCharacteristic(path[i]); //guarda nas caracteristas do animal todo que foi guardado no caminho até à classificação final 
    }
    return 0;
}