#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include "instaesda.hpp"

using namespace std;

/* ------------------------------ */
/* ------ CLASS NodeAccount ----- */
/* ------------------------------ */

/* CONSTRUTOR */

NodeAccount::NodeAccount(string username, string name, bool type)
{
    /* Função 1 */
    if(username.length()){ //se username válido atribui-o ao argumento
        this->username=username;
    }
    if(name.length()){ //se name válido atribui-o ao argumento
        this->name=name;
    }
    this->typeAccount=type; //atribui os restantes atributos aos respetivos argumentos
    this->p=0;
    this->previous=nullptr;
    this->likePosts.clear();
    this->listPosts.clear();
}

/* DESTRUTOR */

NodeAccount::~NodeAccount()
{
    /* Função 2*/
    while(!this->listPosts.empty()){ //enquanto não estiver vazio vai percorrer o loop
        delete (this->listPosts.back()); //delete aos apontadores
        this->listPosts.pop_back(); //clear a posição de cada apontader
    }
    while(!this->likePosts.empty()){
        this->likePosts.pop_back(); 
    }

}

/* MÉTODOS GET */

string NodeAccount::getUsername() const
{
    /* Função 3 */
    return this->username;
}

string NodeAccount::getName() const
{
    /* Função 4 */
    return this->name;
}

bool NodeAccount::getTypeAccount() const
{
    /* Função 5 */
    return this->typeAccount;
}

list<Posts*> NodeAccount::getListPosts() const
{
    /* Função 6 */
    return this->listPosts;
}

vector<string> NodeAccount::getLikePosts() const
{
    /* Função 7 */
    return this->likePosts;
}

/* MÉTODOS SET */

void NodeAccount::setName(string name)
{
    /* Função 8 */
    if(!name.empty()){
        this->name=name;
    }
}

void NodeAccount::setTypeAccount(bool type)
{
    /* Função 9 */
    this->typeAccount=type;
}

/* OUTROS MÉTODOS */

int NodeAccount::addListPosts(Posts *post)
{
    /* Função 10 */
    if(post == nullptr){
        return -1;
    }
    if(find(this->listPosts.begin(),this->listPosts.end(), post)!=listPosts.end()){
        return 1;
    }
    this->listPosts.push_back(post);
    return 0;
}

int NodeAccount::removeListPosts(Posts *post)
{
    /* Função 11 */
    if(post == nullptr){
        return -1;
    }
    if(find(this->listPosts.begin(),this->listPosts.end(), post) == listPosts.end()){
        return 1;
    }
    listPosts.erase(find(this->listPosts.begin(),this->listPosts.end(), post));
    if(find(this->listPosts.begin(),this->listPosts.end(), post) == listPosts.end()){
        return 0;
    }
    return -1;
}

int NodeAccount::addLikePosts(string id)
{
    /* Função 12 */
    string temp;
    temp.append(id);
    if(temp.empty()){
        return -1;
    }
    if(find(likePosts.begin(),likePosts.end(), temp) != likePosts.end()){
        return 1;
    }
    likePosts.push_back(temp);
    return 0;
}

int NodeAccount::removeLikePosts(string id)
{
    /* Função 13 */
    if(id.empty()){
        return -1;
    }
    if(find(likePosts.begin(), likePosts.end(), id) != likePosts.end()){
        return 1;
    }
    this->likePosts.erase(find(likePosts.begin(), likePosts.end(), id));
    return 0;
}

/* ------------------------------ */
/* -------- CLASS Graph --------- */
/* ------------------------------ */

/* CONSTRUTOR */

Graph::Graph()
{
    /* Função 14 */
    this->total=0;
    this->accounts.clear();
    this->follow.clear();
}

/* DESTRUTOR */

Graph::~Graph()
{
    /* Função 15 */
    while(!this->accounts.empty()){ // roda enquanto não estiver vazio
        delete (this->accounts.back()); //delete a cada apontador dentro das accounts
        this->accounts.pop_back();
    }

    while(!this->follow.empty()){ // roda enquanto não estiver vazio
        while(!this->follow.back().empty()){ //outro loop que roda até cada lista não estiver vazia
            follow.back().pop_back();
        }
        follow.pop_back();
    }
}

/* MÉTODOS GET */

int Graph::getTotal() const
{
    /* Função 16 */
    return this->accounts.size();
}

vector<NodeAccount*> Graph::getAccounts() const
{
    /* Função 17 */
    return this->accounts;
}

vector<list<NodeAccount*>> Graph::getFollow() const
{
    /* Função 18 */
    return this->follow;
}

/* MÉTODOS SET */

int Graph::setTotal(int total)
{
    /* Função 19 */
    if(total < 0){
        return -1;
    }
    this->total=total;
    return 0;
}

/* OUTROS MÉTODOS */

int Graph::setAccounts(NodeAccount &na) {
    /* Função 20 */
    if(na.getUsername().empty()){ //verifica se é válido
        return -1;
    }
    for(int i=0; i < (int)accounts.size(); i++){ //verifica se já existe
        if(accounts[i]->getUsername() == na.getUsername()){
            return 1;
        }
    }
    accounts.push_back(&na); //adiciona às accounts
    follow.resize(follow.size()+1); //atualiza tamanho da lista de adjacências
    total++; //incrementa o total de nós do grafo
    return 0;
}

int Graph::accountPosition(string user)
{
    /* Função 21 */
    if(user.empty()){ //verifica se é válido
        return -1;
    }
    for(int i=0; i < (int)accounts.size(); i++){ //encontra o user e retorna a sua posição
        if(accounts[i]->getUsername() == user){
            return i;
        }
    }
    return -1; // se não encontrar retorna -1
}

int Graph::addFollow(NodeAccount &na1, NodeAccount &na2)
{
    /* Função 22 */
    if((na1.getUsername().empty()) || (na2.getUsername().empty())){ //verifica se são válidos
        return -1;
    }
    if((accountPosition(na1.getUsername()) == -1) || (accountPosition(na2.getUsername()) == -1)){ //se não não estejam presentes no vetor de nós do grafo são adicionados ao grafo
        setAccounts(na1);
        setAccounts(na2);
    }
    int i1=accountPosition(na1.getUsername()); 
    if(find(follow[i1].begin(), follow[i1].end(), &na2)!=follow[i1].end()){ // verifica se a aresta já existe
        return 0;  
    }
    this->follow[i1].push_back(&na2); //adiciona a aresta
    return 1;   
}

int Graph::removeFollow(NodeAccount &na1, NodeAccount &na2)
{
    /* Função 23 */
    if((accountPosition(na1.getUsername()) == -1) || (accountPosition(na2.getUsername()) == -1)){ //verifica se são nós do grafo
        return -1;
    }
    int i1=accountPosition(na1.getUsername());
    if(find(follow[i1].begin(), follow[i1].end(), &na2) != follow[i1].end()){ //verifica se existe e elimina a aresta
        this->follow[i1].erase(find(follow[i1].begin(), follow[i1].end(), &na2));
    }
    return 0;
}

bool Graph::isFollowedBy(NodeAccount &na1, NodeAccount &na2)
{
    /* Função 24 */
    if((na1.getUsername().empty()) || (na2.getUsername().empty())){ //verifica se são válidos
        return false;
    }
    int i1=accountPosition(na1.getUsername());
    if(find(follow[i1].begin(), follow[i1].end(), &na2) != follow[i1].end()){ //se encontrar a aresta retorna true
        return true;
    }
    return false; 
}

int Graph::numberOfFollowing(string user)
{
    /* Função 25 */
    if(user.empty()){ //verifica se é válido 
        return -1;
    }
    int i=accountPosition(user); // buscar a posição nas accounts
    if(i == -1){ //verifica se é um nó do grafo
        return -1;
    }
    return (int)follow[i].size(); //retorna o numero de following
}

list<NodeAccount*> Graph::followers(string user)
{
    /* Função 26 */
    list<NodeAccount*> resultado;
    resultado.clear();
    int k=accountPosition(user);
    if((user.empty()) || (k==-1)){// verifica se é válido
        return resultado;
    }
    for(int i=0; i < (int)follow.size(); i++){ //precorre o vector follow
        if(find(follow[i].begin(), follow[i].end(), accounts[k]) != follow[i].end()){ //verifica se o user está na lista de follow, se sim adiciona à lista final de followers
            resultado.push_back(accounts[i]);
        }
    }
    return resultado;
}

int Graph::numberType(string user, char tp)
{
    /* Função 27 */
    if(user.empty()){ //verifica se é válido 
        return -1;
    }
    if((tp != 'F') && (tp != 'S') && (tp != 'R') && (tp != '0')){ // verifica se é válido
        return -1;
    }
    int k=0;
    list<Posts*> listatemporaria=accounts[accountPosition(user)]->getListPosts(); //copia a lista de posts do user para uma temporária
    while(!listatemporaria.empty()){ //enquanto não estiver vazia conta o número de posts do tipo pedido
        if(listatemporaria.back()->type == tp){
            k++;
        }
        listatemporaria.pop_back();
    }
    return k;
}

Posts* Graph::mostLikedPost(string user)
{
    /* Função 28 */
    if(user.empty()){ // verifica se o username é valido
        return NULL;
    }
    if(accountPosition(user) == -1){  // verifica se existe no grafo
        return NULL;
    }

    list<Posts*> postList1=accounts[accountPosition(user)]->getListPosts();
    list<Posts*> postList2=accounts[accountPosition(user)]->getListPosts();
    string maxPostId;
    int imax = -1;

    while(!postList1.empty()){ // loop roda enquanto não estiver vazio
        string postId=postList1.back()->id; 
        int n=0;
        for(int i=0; i < (int)accounts.size(); i++){ //percorre todas os users e verifica se algum tem o id do posts igual ao do liked post, se sim incrementa o valor de n
            vector<string> likes=accounts[i]->getLikePosts();
            for(int j=0; j < (int)likes.size(); j++){
                if(likes[j] == postId){
                    n++;
                }
            }
        }
        if(n >= imax){ //se n for maior que o máximo, esse passa a ser o novo maximo
            imax=n;
            maxPostId=postId;
        }
        postList1.pop_back();
    }
    while(!postList2.empty()){ //loop roda enquanto não estiver vazio
        if(postList2.back()->id == maxPostId){ // se o id do posts coincide com o post com mais likes retorna o ponteito do post
            return postList2.back();
        } else {
            postList2.pop_back();
        }
    }
    return NULL;
}

NodeAccount* Graph::mostLikesGivenTo(string user)
{
    /* Função 29 */
    if(user.empty()){  //verifica se o argumento é valido
        return nullptr;
    }
    if(accountPosition(user) == -1){ //verifica se o user está no grafo
        return nullptr;
    }

    vector<string> idVec=accounts[accountPosition(user)]->getLikePosts(); //variável com os likeposts do user
    vector<string> userVec;
    list<Posts*> postList;
    vector<int> repVec(accounts.size(), 0); //vector com o tamanho do numero de nós do grafo, e é tudo inicializado a 0
    int n=0;
    int k=-1;
    int kmax;

    for(int i=0; i < (int)idVec.size(); i++){ //precorre cada Id dos Posts
        for(int j=0; j < (int)accounts.size(); j++){ // precorre cada conta do usuário
            postList=accounts[j]->getListPosts(); //atribui à variável a conta atual
            while(!postList.empty()){ //loop roda enquanto não estiver vazio
                if((!postList.back()->id.empty()) && (postList.back()->id == idVec[i])){ //verifica se não está vazio e se corresponde ao atual vetor
                    userVec.push_back(accounts[j]->getUsername());
                }
                postList.pop_back();
            }
            postList.clear();
        }
    }
    for(int i=0; i<(int)accounts.size(); i++){ //loop para iterar as accounts
        for(int j=0; j<(int)userVec.size(); j++){ //loop para iterar o userVec
            if(accounts[i]->getUsername() == userVec[j]){ //se o nome atual das accounts é igual ao do uservec, e incrementa o n
                n++;
            }
        }
        repVec[i]=n; //guarda o n no vector para indicar o numero de vezes que o user atual interagiu com a conta atual de userVec
        n=0;
    }
    for(int i=0; i<(int)repVec.size(); i++){//loop para verificar a posição do user que recebeu mais likes
        if (repVec[i] > k) {
            k=repVec[i];
            kmax=i;
        }
    }
    return accounts[kmax];
}

vector<NodeAccount*> Graph::commonFollowers(list<NodeAccount*> l)
{
    /* Função 30 */
    vector<NodeAccount*> res; //resultado final
    list<NodeAccount*> listTemp = l; // passa a lista para uma temporaria
    res.clear(); // certifica se que está vazio 
    if(listTemp.empty()){ // verifica o argumento dado
        return res;
    }
    while(!listTemp.empty()){ // loop roda até estar vazio
        for(int i=0; i < (int)follow.size(); i++){ //vai iterar o vetor follow 
            if(find(follow[i].begin(), follow[i].end(), listTemp.back()) != follow[i].end()){// verifica se o ultimo elemento da lista temporária está na lista do follow[i]
                if(find(res.begin(), res.end(), accounts[i]) != res.end()){ // verifica se já está presente no resultado, se não estiver passa para o proximo i
                    continue;
                }
                res.push_back(accounts[i]); // insero no vecto resultado
            }
        }
        listTemp.pop_back();
    }
    return res;
}

/**
 *  @brief Função de comparação (custom) para fila de prioridade cujos elementos são apontadores para 'NodeAccount'.
 */
struct CompareP
{
    bool operator()(NodeAccount *na1, NodeAccount *na2)
    {
        return na1->p > na2->p;
    }
};

vector<NodeAccount*> Graph::pathTo(string user1, string user2)
{
    /* Função 31 */
    int posUser1=accountPosition(user1); // dá a posição do user1
    int posUser2=accountPosition(user2); // dá a posição do user2
    vector<NodeAccount*> path;
    path.clear();

    if ((posUser1 == -1) || (posUser2 == -1)){ //verifica se os users estão no grafo
        return path;
    }
    auto compareP=[](NodeAccount* a, NodeAccount* b){ // função lambda para comparar dois nodeaccounts, vai ser usada para definir a fila de prioridade
        return a->p > b->p;
    };

    vector<int> dist(total, (int)accounts.size()); //guarda a distância do user1 até as accounts
    vector<NodeAccount*> prev(total, nullptr); //guarda a account anterior para guardar o caminho mais curto
    dist[posUser1] = 0; //a distância no user1 é 0
    priority_queue<NodeAccount*, vector<NodeAccount*>, decltype(compareP)> minHeap(compareP); //cria a fila de prioridade
    minHeap.push(accounts[posUser1]);

    while(!minHeap.empty()){ //enquanto a fila de prioridade não encontrar user2 vai rodar o loop
        NodeAccount* current = minHeap.top(); 
        minHeap.pop();
        if(current->getUsername() == user2){ //dá break quando encontrar o user2
            break;
        }
        for(NodeAccount* neighbor : follow[accountPosition(current->getUsername())]){// para cada neighbour de cada account, este loop calcula a nova distância, se a nova distância for menor que a atual, essa passa a ser a nova atual
            int newDist=dist[accountPosition(current->getUsername())]+1;
            if (newDist < dist[accountPosition(neighbor->getUsername())]){
                dist[accountPosition(neighbor->getUsername())] = newDist;
                prev[accountPosition(neighbor->getUsername())] = current;
                neighbor->p=newDist;
                minHeap.push(neighbor);
            }
        }
    }
    NodeAccount* current=accounts[posUser2];
    while(current != nullptr){ //loop cria o caiminho mais curto 
        path.push_back(current);
        current=prev[accountPosition(current->getUsername())];
    }
    reverse(path.begin(), path.end()); //inverter o caminho, visto que foi guardado o caminho do user2 ao user1

    return path;

}

int Graph::importAccounts(const string filename)
{
    if (filename.empty()) return -1;

    ifstream f(filename);

    if (!f) return -1;

    string s, username, name, type;
    bool ty;
    NodeAccount *n;
    int result;
    stringstream ss, ssd;
    char delim = ',';

    while (getline(f, s)){
        s.pop_back();
        ss.clear();
        ss << s;

        getline(ss, username, delim);
        getline(ss, name, delim);
        getline(ss, type, delim);
        
        if (type == "true") ty = true;
        else ty = false;

        n = new NodeAccount(username, name, ty);

        if (!n) {
            delete n;
            f.close();
            return -1;
        }

        result = setAccounts(*n);
	    if (result == 1) delete n;

        if (result == -1) {
            delete n;
            f.close();
            return -1;
        }
    }
    f.close();

    return 0;
}

int Graph::importFollow(const string filename)
{
    if (filename.empty()) return -1;

    ifstream f(filename);

    if (!f) return -1;

    string s, user1, user2;
    NodeAccount *n1,*n2;
    int result, p1, p2;
    stringstream ss, ssd;
    char delim = ',';

    while (getline(f, s)) {
        s.pop_back();
        ss.clear();
        ss << s;

        getline(ss, user1, delim);
        getline(ss, user2, delim);
    
        p1 = accountPosition(user1);
        if (p1 != -1) {
            n1 = accounts[p1];

            if (n1) {
                p2 = accountPosition(user2);
        
                if (p2 != -1) {
                    n2 = accounts[p2];

                    if (n2) {
                        result = addFollow(*n1,*n2);

                        if (result == -1) {
                            f.close();
                            return -1;
                        }
                    }
                }
            }
        }
    }
    f.close();

    return 0;
}

int Graph::importPosts(const string filename)
{
    /* Função 32 */
    if (filename.empty()){ //verifica se o nome é válido
        return -1;
    }
    ifstream FILE(filename); //abre o ficheiro com o nome filename
    if (!FILE){ // verifcar se abriu o ficheiro
        return -1;
    }
    string l, username,post_id,post_type,post_imagVideo,liked; //variáveis com o nome do enunciado para guardar o que via ser lido
    vector<string> likedN; 
    stringstream string_stream;
    char limit = ','; //o limite para delimitar as diferentes variáveis em cada linha do ficheiro
    char tp; 
    bool imagVideo;
    string id;
    while(getline(FILE, l)){ // loop vai decorrer até acabar de ler todas as linhas do ficheiro e guarda cada linha na string l
        l.pop_back(); //remove o ultimo char da linha
        string_stream.clear(); // "limpa" o estado do string_stream para o preparar para processar as próximas linhas
        string_stream << l; // a linha que foi lida é inserida na stringstream para ser dividida em várias variáveis
        getline(string_stream, username, limit);  
        getline(string_stream, post_id, limit);
        getline(string_stream, post_type, limit);
        getline(string_stream, post_imagVideo, limit);
        likedN.clear(); // certifica que o vetor likedN está vazio para no próximo loop guardar todos os "liked" lidos
        while(getline(string_stream, liked, limit)){
            likedN.push_back(liked);
        }
        int account_Position = accountPosition(username); // guarda a posição do username 
        if(account_Position == -1){ // verifica que username existe 
            return -1;
        }
        id=post_id; //passar as variáveis lidas para os argumentos certos
        if(post_type == "R"){ 
            tp='R';
        }
        if(post_type == "S"){ 
            tp='S';
        }
        if(post_type == "F"){ 
            tp='F';
        }
        if(post_type == "O"){ 
            tp='O';
        }
        if(post_imagVideo == "true"){ 
            imagVideo=true;
        }
        if(post_imagVideo == "false"){ 
            imagVideo=false;
        }
        Posts *aux=new Posts(id, tp, imagVideo); // um post auxiliar com os argumentos lidos para adicionar à lista de posts do user
        accounts[account_Position]->addListPosts(aux);
        for(int i=0; i < (int)likedN.size(); i++){ //adicionar os posts que receberam likes às likeposts
            accounts[accountPosition(likedN[i])]->addLikePosts(id); 
        }
    }
    FILE.close(); //fecha o ficheiro que estava a ser lido
    return 0;
}

/* ------------------------------ */
/* ------ CLASS HashTable ------- */
/* ------------------------------ */

/* CONSTRUTOR */

HashTable::HashTable(int ts)
{
    /* Função 33 */
    if(ts <= 0){ //verifica se é válido
        this->tableSize=0;
    }else{
        this->tableSize=ts; 
    }
    table=new AccountStats*[tableSize]; //cria uma nova table to tamanho tableSize
    for(int i=0; i < tableSize; i++){ //certifica-se que são todos nullptrs
        this->table[i]=nullptr;
    }
    this->totalAccounts=0;
}

/* DESTRUTOR */

HashTable::~HashTable()
{
    /* Função 34 */
    for(int i=0; i < tableSize; i++){//itera a table e elimina cada elemento
        delete table[i];
    }
    delete[] table; //elimina a memória alocada pela tabela em si
}

/* MÉTODOS GET */

int HashTable::getTableSize() const
{
    /* Função 35 */
    return this->tableSize;
}

AccountStats** HashTable::getTable() const
{
    /* Função 36 */
    return this->table;
}

/* OUTROS MÉTODOS */

int HashTable::hashFunction(string key)
{
    if (!key.empty()) {
        int h = 7;
        for(int i = 0; key[i]; i++) h += (int)key[i];

        return h % tableSize;
    }
    return -1;
}

int HashTable::probingFunction(string key, int i)
{
    if (!key.empty()) {
        int h = hashFunction(key); 
        h += 23 * i * i;
        
        return h % tableSize;
    }
    return -1;
}

int HashTable::insertAccountStats(AccountStats &as)
{
    /* Função 37 */
    for(int i=0; i < tableSize; i++){ //precorre a table e verifica se já existe o user
        if((table[i] != nullptr) && (table[i]->username == as.username)){
            return -1;
        }
    }
    int i=hashFunction(as.username);
    int numb=i;
    while((table[numb] != nullptr) && (table[numb]->username!= "apagado")){//loop que tenta encontrar uma posição para o user, recorrendo à probing function
        numb=probingFunction(as.username, numb);
    }
    if((table[numb] != nullptr) && (table[numb]->username == "apagado")){ //se existir um elemento não nulo, mas com o username apagado, elimina esse elemento
        delete table[numb];
    }
    table[numb]=new AccountStats(as); //insere o user no elemento encontrado
    totalAccounts++; // aumenta o tamanho de contas efectivas
    return numb;
}

int HashTable::deleteAccountStats(string user)
{
    /* Função 38 */
    if(user.empty()){ //verifica se é válido
        return -1;
    }
    for(int i=0; i < tableSize; i++){ 
        if((table[i] != nullptr) && (table[i]->username == user)){//procura o user, elimina-o, e subsitui-o com o apagado, diminui tmb o número de contas efetivas
            delete table[i]; 
            table[i]=new AccountStats("apagado", 0, 0, 0, 0, 0, 0, 0);
            totalAccounts--;
            return 0;
        }   
    }
    return 1;
}

int HashTable::searchAccountStats(string user)
{
    /* Função 39 */
    if(user.empty()){ //verifica se é válido
        return -1;
    }
    for(int i=0; i < tableSize; i++){//encontra a posição do user e retorna-a
        if((table[i] != nullptr) && (table[i]->username == user)){
            return i;
        }   
    }
    return -1; //se der erro retorna -1;
}

int HashTable::importFromGraph(Graph &g)
{
    /* Função 40 */
    for(int i=0; i < g.getTotal(); i++){ //loop vai rodar até chegar ao tamanho do grafo
        int followees=g.followers(g.getAccounts()[i]->getUsername()).size(); // vai buscar ao grafo o número de followees
        int following=g.getFollow()[i].size(); // vai buscar ao grafo o número de following
        int post=g.getAccounts()[i]->getListPosts().size(); // vai buscar ao grafo o número de posts
        int postStories=g.numberType(g.getAccounts()[i]->getUsername(), 'S'); // vai buscar ao grafo o número de stories
        int postFeeds=g.numberType(g.getAccounts()[i]->getUsername(), 'F'); // vai buscar ao grafo o número de feeds
        int postReel=g.numberType(g.getAccounts()[i]->getUsername(), 'R'); // vai buscar ao grafo o número de reels
        int likes=g.getAccounts()[i]->getLikePosts().size(); // vai buscar ao grafo o número de likes
        string user=g.getAccounts()[i]->getUsername(); // vai buscar ao grafo o username

        AccountStats* temp=new AccountStats(user, likes, followees, following, post, postStories, postFeeds, postReel); //variável temporária para guardar os argumentos lidos

        if(insertAccountStats(*temp) == -1){ //insere a variável temporária, se der erro dá delete à variável e retorna -1
            delete temp;
            return -1;
        }
    }
    return 0;
}