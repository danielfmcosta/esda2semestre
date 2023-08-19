#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <vector>
#include <string>
#include <queue>
#include "decisionTree.hpp"

using namespace std;

/* ------------------------------ */
/* ------ CLASS NodeAnimal ------ */
/* ------------------------------ */

class NodeAnimal
{
    private:
        /* ATRIBUTOS */
        
        /**
          * @brief Nome científico do animal (identificador único).
          */
        string scientificName;

        /**
          * @brief Nome comum do animal.
          */
        string name;

        /**
          * @brief Classificação (através da chave dicotómica) do animal.
          */
        string classification;

        /**
          * @brief Animal vertebrado ('true') ou invertebrado ('false').
          */
        bool vertebrate;

        /**
          * @brief Vetor com as características que descrevem o animal.
          */
        vector<string> characteristics;
  
    public:
        /* ATRIBUTOS */
        
        /**
          * @brief Filho esquerdo do nó.
          */
        NodeAnimal* left;

        /**
          * @brief Filho direito do nó.
          */
        NodeAnimal* right;


        /* CONSTRUTORES */

        /** 
         *  @brief Construtor (parametrizado)
         *  @param name nome do animal
         *  @param scientificName nome científico do animal
         *  @param classification classificação do animal
         *  @note  Inicializa os atributos com o correspondente argumento e 'vertebrate' a false.
         *  @note  Deve garantir-se que o vetor 'characteristics' se encontra vazio e os apontadores são inicializados a 'nullptr'.
         *  @note  O valor dos argumentos deve ser válido.
         */
        NodeAnimal(string name, string scientificName, string classification);

        /**
         *  @brief Construtor (parametrizado)
         *  @param name nome do animal
         *  @param scientificName nome científico do animal
         *  @note  Inicializa os atributos com o correspondente argumento, 'classification' a "" e 'vertebrate' a 'false'.
         *  @note  Deve garantir-se que o vetor 'characteristics' se encontra vazio e os apontadores são inicializados a 'nullptr'.
         *  @note  O valor dos argumentos deve ser válido.
         */
        NodeAnimal(string name, string scientificName);


        /* DESTRUTOR */

        /** 
         *  @brief Destrutor
         *  @note  Remove, em memória, o nó (apagar os apontadores).
         */
        ~NodeAnimal();


        /* MÉTODOS GET */

        /** 
         *  @brief  Obter o nome comum do animal.
         *  @param  none
         *  @return 'name'
         */
        string getName() const;

        /** 
         *  @brief  Obter o nome científico do animal.
         *  @param  none
         *  @return 'scientificName'
         */
        string getScientificName() const;

        /** 
         *  @brief  Obter a classificação do animal.
         *  @param  none
         *  @return 'classification'
         */
        string getClassification() const;

        /** 
         *  @brief  Obter se o animal é vertebrado ou invertebrado.
         *  @param  none
         *  @return 'vertebrate'
         */
        bool getVertebrate() const;

        /** 
         *  @brief  Obter o vetor com as características do animal.
         *  @param  none
         *  @return 'characteristics'
         */
        vector<string> getCharacteristics() const;


        /* MÉTODOS SET */

        /** 
         *  @brief  Definir o nome do animal.
         *  @param  name nome do animal
         *  @return void
         *  @note   Verificar se o argumento é válido.
         */
        void setName(string name);  

        /** 
         *  @brief  Definir a classificação do animal.
         *  @param  classification classificação do animal
         *  @return void
         *  @note   Verificar se o argumento é válido.
         */
        void setClassification(string classification);

        /** 
         *  @brief  Definir se o animal é vertebrado ou invertebrado.
         *  @param  vertebrate 'true' se vertebrado ou 'false' se invertebrado
         *  @return void
         */
        void setVertebrate(bool vertebrate);


        /* OUTROS MÉTODOS */

        /** 
         *  @brief  Adicionar ao vetor uma nova característica do animal.
         *  @param  characteristic novo elemento a inserir em 'characteristics'
         *  @return void
         *  @note   Verificar se o argumento é válido.
         */
        void addCharacteristic(string characteristic);

        /** 
         *  @brief  Remover do vetor uma característica do animal.
         *  @param  characteristic elemento a remover do vetor 'characteristics' 
         *  @return 1 em caso de sucesso || 0 caso o elemento não exista || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int removeCharacteristic(string characteristic);
};


/* ------------------------------ */
/* ------- CLASS TreeBST -------- */
/* ------------------------------ */

class TreeBST
{
    private:
        /* ATRIBUTOS */
        
        /**
          * @brief Raiz da árvore.
          */
        NodeAnimal* root;

    public:
        /* CONSTRUTOR */

        /** 
         *  @brief Construtor default
         *  @note  A raiz é inicializada a 'nullptr'.
         */
        TreeBST();


        /* DESTRUTOR */

        /** 
         *  @brief Destrutor
         *  @note  Remove, em memória, a árvore (apagar a raiz).
         */
        ~TreeBST();


        /* MÉTODOS GET */

        /** 
         *  @brief  Obter a raiz da árvore.
         *  @param  none
         *  @return 'root'
         */
        NodeAnimal* getRoot();


        /* MÉTODOS SET */

        /** 
         *  @brief  Definir a raiz da árvore.
         *  @param  newRoot nó que deverá corresponder à raiz da árvore
         *  @return void
         *  @note   Verificar se o argumento é válido.
         */
        void setRoot(NodeAnimal *newRoot);
        
        
        /* OUTROS MÉTODOS */

        /** 
         *  @brief  Adicionar à árvore um novo nó.
         *  @param  treeNode nó pai (tentativa) para inserção do novo nó
         *  @param  newNoA nó a inserir
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Verificar se os argumentos são válidos.
         */
        int insert(NodeAnimal *treeNode, NodeAnimal *newNoA);
        
        /** 
         *  @brief  Adicionar à árvore um novo nó.
         *  @param  newNoA nó a inserir
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Verificar se o argumento é válido.
         */
        int insert(NodeAnimal *newNoA);

        /** 
         *  @brief  Procurar determinado nó na árvore.
         *  @param  scientificName nome científico do animal cujo nó se pretende pesquisar
         *  @return apontador para o nó encontrado || NULL caso não seja encontrado ou em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        NodeAnimal* searchNode(string scientificName);

        /** 
         *  @brief  Determinar o número total de animais vertebrados ou invertebrados na árvore.
         *  @param  root apontador para nó da árvore
         *  @param  vert 'true' ou 'false'
         *  @return total de animais vertebrados (se 'vert' é 'true') ou invertebrados (se 'vert' é 'false') na árvore
         */
        int totalAnimals(NodeAnimal* root, bool vert);

        /** 
         *  @brief  Determinar o número total de animais vertebrados ou invertebrados na árvore.
         *  @param  vert 'true' ou 'false'
         *  @return total de animais vertebrados (se 'vert' é 'true') ou invertebrados (se 'vert' é 'false') na árvore
         *  @note   Invoca a função 'totalAnimals' a partir da raiz da árvore.
         */
        int totalAnimals(bool vert);

        /** 
         *  @brief  Determinar o tamanho da árvore (total de animais).
         *  @param  root apontador para nó da árvore
         *  @return número total de nós da árvore
         */
        int size(NodeAnimal* root);

        /** 
         *  @brief  Determinar o tamanho da árvore (total de animais).
         *  @param  none
         *  @return número total de nós da árvore
         */
        int size();
         
        /** 
         *  @brief  Procurar os animais da árvore que possuem determinada característica.
         *  @param  root apontador para nó da árvore
         *  @param  charac característica a procurar
         *  @return vetor com os animais que têm a característica 'charac' em comum
         *  @note   Verificar se o argumento é válido.
         */
        vector<NodeAnimal*> searchCharacteristic(NodeAnimal* root, string charac);
        
        /** 
         *  @brief  Procurar os animais da árvore que possuem determinada característica.
         *  @param  charac característica a procurar
         *  @return vetor com os animais que têm a característica 'charac' em comum
         *  @note   Verificar se o argumento é válido.
         */
        vector<NodeAnimal*> searchCharacteristic(string charac);

        /** 
         *  @brief  Determinar o número de animais da árvore que possuem determinado par de características.
         *  @param  root apontador para nó da árvore
         *  @param  charac1 característica a procurar
         *  @param  charac2 característica a procurar
         *  @return número total de animais que têm as características 'charac1' e 'charac2' em comum || 
         *  @return -1 em caso de erro
         *  @note   Verificar se os argumentos são válidos.
         */
        int commonCharacteristic(NodeAnimal* root, string charac1, string charac2);

        /** 
         *  @brief  Determinar o número de animais da árvore que possuem determinado par de características.
         *  @param  charac1 característica a procurar
         *  @param  charac2 característica a procurar
         *  @return número total de animais que têm as características 'charac1' e 'charac2' em comum || 
         *  @return -1 em caso de erro
         *  @note   Verificar se os argumentos são válidos.
         */
        int commonCharacteristic(string charac1, string charac2);  
        
        /** 
         *  @brief  Preencher a árvore, lendo o conteúdo de um ficheiro de texto.
         *  @param  filename nome do ficheiro de texto que contém a informação dos animais a importar
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Cada linha do ficheiro corresponde à informação (nomes) de um animal a adicionar à árvore.
         *  @note   O formato de cada linha é o seguinte: scientificName,name
         */
        int import(const string filename);

        /** 
         *  @brief  Construir uma heap com dicionário de uma árvore de animais.
         *  @param  root apontador para nó da árvore
         *  @return apontador para uma heap de nomes científicos de animais organizados alfabeticamente
         */
        priority_queue<string,vector<string>, greater<string>>* createDictionary(NodeAnimal* root);

        /** 
         *  @brief  Determinar a posição de determinado animal no dicionário.
         *  @param  scientificName nome científico do animal para o qual se pretende determinar a posição
         *  @return posição (número de animais que se encontram alfabeticamente atrás do animal em causa) || 
         *  @return 0 caso o animal não exista || -1 em caso de erro
         *  @note   Os nós da árvore devem ser adicionados a uma heap (criar o dicionário) para encontrar a posição do animal em causa.
         *  @note   A posição refere-se à ordem, ou seja, o primeiro animal no dicionário tem posição 1.
         */
        int positionDictionary(string scientificName);

        /** 
         *  @brief  Preencher o vetor 'characteristics', atualizando os atributos 'vertebrate' e 'classification'.
         *  @param  treeB árvore de decisão da chave dicotómica de classificação dos animais
         *  @param  filename nome do ficheiro de texto que contém a informação a importar
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Cada linha do ficheiro corresponde a um animal para o qual se pretende preencher a informação em questão.
         *  @note   O formato de cada linha é o seguinte: scientificName,decision1,decision2,...,decisionN
         *  @note   decision1,decision2,...,decisionN corresponde à sucessão de decisões a ser percorrida na árvore 'treeB'.
         *  @note   Cada decisão corresponde a "Yes" ou "No", para indicar que o ramo de um nó de 'treeB' a escolher é o esquerdo ou o direito, respetivamente.
         *  @note   Cada nó de 'treeB' é uma característica a inserir em 'characteristics', à exceção de:
         *  @note     - o nó de 'treeB' é a raiz da árvore, o que significa que a decisão a si associada traduz-se no valor a atribuir a 'vertebrate';
         *  @note     - o nó de 'treeB' é uma folha, o que significa que corresponde à classificação.
         *  @note   Caso a decisão seja "No", o valor a inserir no vetor deve ser iniciado por "No ".
         */
        int updateCharacteristicsFromFile(DecisionTree &treeB, const string filename);

        /** 
         *  @brief  Preencher o vetor 'characteristics'.
         *  @param  treeB árvore de decisão da chave dicotómica de classificação dos animais
         *  @param  scientificName nome científico do animal para o qual se irá preencher o vetor 'characteristics'
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   O animal deve ser encontrado na árvore BST para conhecer a sua classificação.
         *  @note   Com base na classificação, a árvore de decisão terá de ser percorrida para encontrar as características do animal.
         *  @note   Se o nó da árvore de decisão pertencer à subárvore da direita, o valor a inserir no vetor deve ser iniciado por "No ".
         *  @note   O atributo 'vertebrate' é atualizado através da decisão realizada na raiz de 'treeB':
         *  @note     - se for percorrida a subárvore da esquerda, o animal é vertebrado;
         *  @note     - se for percorrida a subárvore da direita, o animal é invertebrado. 
         *  @note   O vetor 'characteristics' deve estar organizado de modo que a primeira característica seja a mais próxima da raiz de treeB.
         */
        int updateCharacteristicsFromClassification(DecisionTree &treeB, string scientificName);

};

#endif