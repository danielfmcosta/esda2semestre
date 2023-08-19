#ifndef INSTAESDA_HPP
#define INSTAESDA_HPP

#include <vector>
#include <string>
#include <list>

using namespace std;

/* ------------------------------ */
/* ----------- STRUCTS ---------- */
/* ------------------------------ */

struct Posts;
struct AccountStats;

/* ------------------------------ */
/* ------ CLASS NodeAccount ----- */
/* ------------------------------ */

class NodeAccount
{
    private:
        /* ATRIBUTOS */
        
        /**
         *  @brief Nome de utilizador da conta (identificador único).
         */
        string username;

        /**
         *  @brief Nome da conta.
         */
        string name;

        /**
         *  @brief Tipo de conta: pública ('true') ou privada ('false').
         */
        bool typeAccount;

        /**
         *  @brief Lista de posts da conta.
         */
        list<Posts*> listPosts;

        /**
         *  @brief Vetor com os IDs dos posts que receberam like.
         */
        vector<string> likePosts;

    public:
        /* ATRIBUTOS */
        
        /**
         *  @brief Peso acumulado a atribuir a cada nó do grafo para aplicar o algoritmo de Dijkstra.
         */
        int p;
        
        /**
         *  @brief Nó anterior, a ser usado no algoritmo de Dijkstra.
         */
        NodeAccount *previous;


        /* CONSTRUTOR */

        /** 
         *  @brief Construtor (parametrizado).
         *  @param username nome de utilizador da conta
         *  @param name nome da conta
         *  @param type tipo de conta
         *  @note  Inicializa os atributos com o correspondente argumento, 'p' a zero e 'previous' a 'nullptr'.
         *  @note  Deve garantir-se que 'listPosts' e 'likePosts' se encontram vazios.
         *  @note  O valor dos argumentos deve ser válido.
         */
        NodeAccount(string username, string name, bool type);


        /* DESTRUTOR */

        /** 
         *  @brief Destrutor.
         *  @note  Remove, em memória, o nó (apagar a lista de posts).
         */
        ~NodeAccount();


        /* MÉTODOS GET */

        /**
         *  @brief  Obter o nome de utilizador da conta.
         *  @param  none
         *  @return 'username'
         */
        string getUsername() const;

        /**
         *  @brief  Obter o nome da conta.
         *  @param  none
         *  @return 'name'
         */
        string getName() const;

        /**
         *  @brief  Obter o tipo de conta.
         *  @param  none
         *  @return 'typeAccount'
         */
        bool getTypeAccount() const;

        /**
         *  @brief  Obter a lista de posts da conta.
         *  @param  none
         *  @return 'listPosts'
         */
        list<Posts*> getListPosts() const;

        /**
         *  @brief  Obter o vetor de likes.
         *  @param  none
         *  @return 'likePosts'
         */
        vector<string> getLikePosts() const;


        /* MÉTODOS SET */

        /** 
         *  @brief  Definir o nome da conta.
         *  @param  name nome da conta
         *  @return void
         *  @note   Verificar se o argumento é válido.
         */
        void setName(string name);  

        /** 
         *  @brief  Definir o tipo de conta.
         *  @param  type 'true' se pública ou 'false' se privada
         *  @return void
         */
        void setTypeAccount(bool type);


        /* OUTROS MÉTODOS */

        /** 
         *  @brief  Adicionar um novo post.
         *  @param  post apontador para novo elemento a inserir em 'listPosts'
         *  @return 0 em caso de sucesso || 1 caso o elemento já exista || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int addListPosts(Posts *post);

        /** 
         *  @brief  Remover um post da conta.
         *  @param  post apontador para o elemento a remover de 'listPosts'
         *  @return 0 em caso de sucesso || 1 caso o elemento não exista || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int removeListPosts(Posts *post);

        /** 
         *  @brief  Adicionar um post ao qual foi dado like.
         *  @param  id novo elemento a inserir em 'likePosts'
         *  @return 0 em caso de sucesso || 1 caso o elemento já exista || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int addLikePosts(string id);

        /** 
         *  @brief  Remover um post ao qual foi dado like.
         *  @param  id elemento a remover de 'likePosts'
         *  @return 0 em caso de sucesso || 1 caso o elemento não exista || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int removeLikePosts(string id);
};

/* ------------------------------ */
/* -------- CLASS Graph --------- */
/* ------------------------------ */

class Graph
{
    private:
        /* ATRIBUTOS */
        
        /**
         *  @brief Número total de contas (nós) do instaESDA (grafo).
         */
        int total;

        /**
         *  @brief Vetor de contas (nós) do instaESDA (grafo).
         */
        vector<NodeAccount*> accounts;
        
        /**
         *  @brief Lista de adjacências do grafo (representativa das ligações entre as contas, ou seja, quem segue quem).
         */  
	    vector<list<NodeAccount*>> follow;

    public:
        /* CONSTRUTOR */

        /**
         *  @brief Construtor (default).
         *  @note  Inicializa o atributo 'total' a zero e garante que os vetores se encontram vazios.
         */
	    Graph();


        /* DESTRUTOR */

        /**
         *  @brief Destrutor.
         *  @note  Remove, em memória, o grafo (apagar os nós).
         */
        ~Graph();


        /* MÉTODOS GET */

        /**
         *  @brief  Obter o número de nós do grafo (total de contas).
         *  @param  none
         *  @return 'total'
         */
	    int getTotal() const;

        /**
         *  @brief  Obter os nós do grafo.
         *  @param  none
         *  @return 'accounts'
         */
	    vector<NodeAccount*> getAccounts() const;
        
        /**
         *  @brief  Obter a lista de adjacências.
         *  @param  none
         *  @return 'follow'
         */
	    vector<list<NodeAccount*>> getFollow() const;


        /* MÉTODOS SET */

        /**
         *  @brief  Definir o número de nós do grafo.
         *  @param  total número de nós
         *  @return 0 em caso de sucesso || -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int setTotal(int total);


        /* OUTROS MÉTODOS */

        /**
         *  @brief  Adicionar uma nova conta ao grafo.
         *  @param  na conta a adicionar em 'accounts'
         *  @return 0 em caso de sucesso || 1 caso o nó já exista || -1 em caso de erro
         *  @note   O número total de nós do grafo deve ser atualizado, bem como o tamanho da lista de adjacências.
         */
        int setAccounts(NodeAccount &na);

        /**
         *  @brief  Verificar qual a posição de determinado utilizador no vetor de nós do grafo.
         *  @param  user nome de utilizador a procurar em 'accounts'
         *  @return posição da conta no vetor (entre 0 e n-1, sendo n o tamanho do vetor) ou -1 em caso de erro
         *  @note   Verificar se o argumento é válido.
         */
        int accountPosition(string user);

        /**
         *  @brief  Adicionar uma nova aresta ao grafo.
         *  @param  na1 vértice do qual parte a aresta
         *  @param  na2 vértice no qual entra a aresta
         *  @return 0 em caso de sucesso || 1 caso a aresta já exista || -1 em caso de erro
         *  @note   Caso na1 ou na2 não estejam presentes no vetor de nós do grafo, devem ser, em primeiro lugar, adicionados ao vetor.
         *  @note   na1 é um novo seguidor de na2.
         */
	    int addFollow(NodeAccount &na1, NodeAccount &na2);

        /**
         *  @brief  Remover uma aresta do grafo.
         *  @param  na1 vértice do qual parte a aresta
         *  @param  na2 vértice no qual entra a aresta
         *  @return 0 em caso de sucesso ou -1 em caso de erro
         *  @note   Verificar se na1 e na2 são nós do grafo.
         *  @note   na1 deixa de ser seguidor de na2.
         */
        int removeFollow(NodeAccount &na1, NodeAccount &na2);

        /**
         *  @brief  Verificar se determinada conta é seguida por outra.
         *  @param  na1 vértice do qual parte a aresta
         *  @param  na2 vértice no qual entra a aresta
         *  @return 'true' caso na1 siga na2 || 'false' caso não siga ou em caso de erro
         *  @note   Verificar se na1 e na2 são nós do grafo.
         *  @note   na1 é seguidor de na2?
         */
        bool isFollowedBy(NodeAccount &na1, NodeAccount &na2);
	
        /**
         *  @brief  Determinar quantas contas segue determinada conta.
         *  @param  user nome de utlizador da conta
         *  @return número total de contas seguidas ou -1 em caso de erro
         *  @note   Verificar se o argumento é válido e se a conta é nó do grafo.
         */
        int numberOfFollowing(string user);

        /**
         *  @brief  Determinar quais as contas que seguem determinada conta.
         *  @param  user nome de utlizador da conta
         *  @return lista de apontadores para os nós das contas dos seguidores
         *  @note   Verificar se o argumento é válido e se a conta é nó do grafo.
         */
        list<NodeAccount*> followers(string user);

        /**
         *  @brief  Determinar quantos posts determinada conta tem de determinado tipo.
         *  @param  user nome de utlizador da conta
         *  @param  tp tipo de post
         *  @return número total de posts do tipo correspondente a 'tp' ou -1 em caso de erro
         *  @note   Verificar se os argumentos são válidos e se a conta é nó do grafo.
         */
        int numberType(string user, char tp);

        /**
         *  @brief  Determinar qual o post de determinada conta que tem mais likes.
         *  @param  user nome de utlizador da conta
         *  @return apontador para o post com mais likes ou 'nullptr' em caso de erro
         *  @note   Verificar se o argumento é válido e se a conta é nó do grafo.
         */
        Posts* mostLikedPost(string user);

        /**
         *  @brief  Determinar qual a conta a que determinada conta dá mais likes.
         *  @param  user nome de utlizador da conta
         *  @return apontador para a conta encontrada ou 'nullptr' em caso de erro
         *  @note   Verificar se o argumento é válido e se a conta é nó do grafo.
         */
        NodeAccount* mostLikesGivenTo(string user);

        /**
         *  @brief  Determinar quais as contas que seguem todas as contas de uma determinada lista.
         *  @param  l lista de contas
         *  @return vetor com as contas encontradas
         *  @note   Verificar se o argumento é válido.
         */
        vector<NodeAccount*> commonFollowers(list<NodeAccount*> l);

        /**
         *  @brief  Determinar o caminho mais curto entre dois nós do grafo.
         *  @param  user1 nome de utlizador da conta de origem
         *  @param  user2 nome de utlizador da conta de destino
         *  @return vetor com os nós do grafo pertencentes ao caminho percorrido
         *  @note   Verificar se os argumentos são válidos e se as contas são nós do grafo.
         *  @note   Sugestão: Utilizar min-heaps.
         */
        vector<NodeAccount*> pathTo(string user1, string user2);

        /**
         *  @brief  Preencher os nós do grafo, lendo o conteúdo de um ficheiro de texto.
         *  @param  filename nome do ficheiro de texto que contém a informação das contas a importar
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Cada linha do ficheiro corresponde a uma conta para a qual se pretende preencher a informação em questão.
         *  @note   O formato de cada linha é o seguinte: username,name,typeAccount
         */
        int importAccounts(const string filename);

        /**
         *  @brief  Criar as arestas do grafo, lendo o conteúdo de um ficheiro de texto.
         *  @param  filename nome do ficheiro de texto que contém a informação dos seguidores a importar
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Cada linha do ficheiro corresponde aos nomes de utilizadores de duas contas para as quais se pretende preencher a informação em questão.
         *  @note   O formato de cada linha é o seguinte: username_out,username_in
         *  @note   Para cada linha, pretende-se criar uma aresta de username_out para username_in.
         */
        int importFollow(const string filename);

        /**
         *  @brief  Criar novos posts e associá-los à conta correspondente, lendo o conteúdo de um ficheiro de texto.
         *  @param  filename nome do ficheiro de texto que contém a informação dos posts a importar
         *  @return -1 em caso de erro || 0 em caso de sucesso
         *  @note   Cada linha do ficheiro corresponde a um post para o qual se pretende preencher a informação em questão.
         *  @note   O formato de cada linha é o seguinte: username,post_id,post_type,post_imagVideo,liked1,...,likedN
         *  @note   liked1,...,likedN corespondem às contas que deram like ao post e não são obrigatórias.
         */
        int importPosts(const string filename);
};

/* ------------------------------ */
/* ------ CLASS HashTable ------- */
/* ------------------------------ */

class HashTable
{
    private:
        /* ATRIBUTOS */
        
        /**
         *  @brief Tamanho da tabela de dispersão.
         */
        int tableSize;

        /**
         *  @brief Tabela de dispersão (array de apontadores para elementos do tipo 'AccountStats').
         */
        AccountStats **table;

    public:
        /* ATRIBUTOS */

        /**
         *  @brief Número de contas (número efetivo de elementos) na tabela de dispersão.
         */
        int totalAccounts;


        /* CONSTRUTOR */

        /**
         *  @brief Construtor (parametrizado).
         *  @param ts tamanho da tabela de dispersão
         *  @note  Inicializa o atributo com o correspondente argumento e cria o array representativo da tabela de dispersão.
         *  @note  O valor do argumento deve ser válido.
         */
        HashTable(int ts);


        /* DESTRUTOR */

        /**
         *  @brief Destrutor.
         *  @note  Remove, em memória, a tabela de dispersão (apagar os elementos da tabela).
         */
        ~HashTable();


        /* MÉTODOS GET */

        /**
         *  @brief  Obter o tamanho da tabela de dispersão.
         *  @param  none
         *  @return 'tableSize'
         */
        int getTableSize() const;

        /**
         *  @brief  Obter a tabela de dispersão.
         *  @param  none
         *  @return 'table'
         */
        AccountStats** getTable() const;
        

        /* OUTROS MÉTODOS */

        /**
         *  @brief  Determinar o índice de determinada chave.
         *  @param  key chave do elemento
         *  @return índice calculado ou -1 em caso de erro
         *  @note   Função de dispersão: devolve a hash (h) -> somatório de h(i-1)+key[i], com i>=0 e i<key.length() (h(-1)=7).
         *  @note   O índice a retornar corresponde a h%tableSize.
         *  @note   O valor do argumento deve ser válido.
         */
        int hashFunction(string key);

        /**
         *  @brief  Determinar o índice de determinada chave para resolução de colisões.
         *  @param  key chave do elemento
         *  @param  i grau da colisão
         *  @return índice calculado ou -1 em caso de erro
         *  @note   Função de sondagem quadrática: devolve a hash (h) -> h+23*i^2.
         *  @note   O índice a retornar corresponde a h%tableSize.
         *  @note   O valor do argumento deve ser válido.
         */
        int probingFunction(string key, int i);
        
        /**
         *  @brief  Inserir um novo elemento na tabela de dispersão.
         *  @param  as elemento a inserir
         *  @return índice do elemento inserido || -1 caso o elemento já exista ou em caso de erro
         *  @note   A chave do elemento a inserir corresponde ao campo 'username'.
         *  @note   Atualizar o valor do número de elementos efetivos na tabela de dispersão.
         *  @note   No caso de ocorrer uma colisão, o elemento pode ser inserido numa posição livre ou numa posição da qual foi previamente eliminado um elemento (demarcada com a chave 'apagado').
         */
        int insertAccountStats(AccountStats &as);

        /**
         *  @brief  Remover um elemento da tabela de dispersão.
         *  @param  user chave do elemento a remover
         *  @return 0 em caso de sucesso || 1 caso a chave não exista || -1 em caso de erro
         *  @note   O valor do argumento deve ser válido.
         *  @note   Atualizar o valor do número de elementos efetivos na tabela de dispersão.
         *  @note   Ao remover o elemento, guardar nessa posição um elemento com chave 'apagado' e restantes campos nulos.
         */
        int deleteAccountStats(string user);

        /**
         *  @brief  Pesquisar determinado elemento na tabela de dispersão.
         *  @param  user chave do elemento a procurar
         *  @return índice do elemento || -1 caso não exista ou em caso de erro
         *  @note   O valor do argumento deve ser válido.
         */
        int searchAccountStats(string user);

        /**
         *  @brief  Construir a tabela de dispersão com base no instaESDA (grafo).
         *  @param  g grafo
         *  @return 0 em caso de sucesso ou -1 em caso de erro
         */
        int importFromGraph(Graph &g);

        /**
         *  @brief  Mostrar o conteúdo da tabela de dispersão.
         *  @param  none
         *  @return void
         */
        void show(void);
};

/* ------------------------------ */
/* -------- STRUCT Posts -------- */
/* ------------------------------ */

struct Posts
{
    /**
     *  @brief Identificador único do post.
     */
    string id;

    /**
     *  @brief Tipo de post (R -> reel, S -> story, F -> feed, O -> other).
     */
    char type;

    /**
     *  @brief Tipo de conteúdo do post (imagem -> 'true', vídeo -> 'false').
     */
    bool imagVideo;

    Posts(string id_, char type_, bool imagVideo_)
    {
        id = id_;
        type = type_;
        imagVideo = imagVideo_;
    }
};

/* ------------------------------ */
/* ----- STRUCT AccountStats ---- */
/* ------------------------------ */

struct AccountStats
{
    /**
     *  @brief Nome de utilizador da conta.
     */
    string username;

    /**
     *  @brief Número total de likes atribuídos aos posts da conta.
     */
    int likes;

    /**
     *  @brief Número de utilizadores que seguem a conta.
     */
    int followees;

    /**
     *  @brief Número de utilizadores que são seguidos pela conta.
     */
    int following;

    /**
     *  @brief Número total de posts da conta.
     */
    int posts;

    /**
     *  @brief Número total de stories da conta.
     */
    int postsStories;

    /**
     *  @brief Número total de feeds da conta.
     */
    int postsFeeds;

    /**
     *  @brief Número total de reels da conta.
     */
    int postsReels;

    AccountStats(string username_,int likes_, int followees_, int following_, int posts_, int postsStories_, int postsFeeds_, int postsReels_)
    {
        username = username_;
        likes = likes_;
        followees = followees_;
        following = following_;
        posts = posts_;
        postsStories = postsStories_;
        postsFeeds = postsFeeds_;
        postsReels = postsReels_;
    }
};

#endif
