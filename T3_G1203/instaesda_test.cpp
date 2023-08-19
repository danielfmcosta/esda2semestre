#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "instaesda.hpp"
#include "instaesda.cpp"

using namespace std;

int verifica_NodeAccount_construtor(NodeAccount **n1)
{
    int er = 0;
    string username="LuisTe";
    string name="Luis Teixeira";
    bool type=true;

   
    *n1 = new NodeAccount(username,name,type);
    
    /*Teste 1*/
    if ((*n1) == nullptr)
    {
        cout << "...verifica_NodeAccount_construtor: NodeAnimal e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_NodeAccount_construtor: NodeAnimal nao e' NULL (ok)" << endl;

    /*Teste 2*/
    if ((*n1)->getUsername()!=username)
    {
        cout << "...verifica_NodeAccount_construtor: Username (= " << (*n1)->getUsername() << ") e' diferente do esperado (= LuisTe) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: Username coincide com o esperado (= LuisTe) (ok)" << endl;

    /*Teste 3*/
    if ((*n1)->getName()!=name) 
    {
        cout << "...verifica_NodeAccount_construtor: Nome  (= " << (*n1)->getName()<< ") e' diferente do esperado (=Luis Teixeira) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: Nome coincide com o esperado (= Luis Teixeira) (ok)" << endl;
    
    /*Teste 4*/
    if ((*n1)->getTypeAccount()!= type)
    {
        cout << "...verifica_NodeAccount_construtor: Tipo de conta (= " << (*n1)->getTypeAccount() <<") e' diferente do esperado (= true) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: Tipo de conta coincide com o esperado (= true) (ok)" <<endl;    
    
    /*Teste 5*/
    if ((*n1)->getListPosts().empty() != true )
    {
        cout << "...verifica_NodeAccount_construtor: A lista de posts não está vazia (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: A lista de posts está vazia (ok)" << endl;

        /*Teste 6*/
    if ((*n1)->getLikePosts().empty() != true )
    {
        cout << "...verifica_NodeAccount_construtor: O vetor de likes não está vazio (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: O vetor de likes  está vazio (ok)" << endl;

        /*Teste 7*/
    if ((*n1)->previous != nullptr )
    {
        cout << "...verifica_NodeAccount_construtor: Previous não é NULL (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: previous é NULL (ok)" << endl;

        /*Teste 8*/
    if ((*n1)->p != 0 )
    {
        cout << "...verifica_NodeAccount_construtor: p (= " << (*n1)->p <<") e' diferente do esperado (= 0) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_construtor: p coincide com o esperado (= 0) (ok)" <<endl;   

    return er;
}

int verifica_NodeAccount_setters(NodeAccount **n1)
{
    int er = 0; 
    if (!(*n1)) {
        cout << "...verifica_NodeAccount_setters: NodeAccount e' NULL (ERRO)" << endl;
        return 1;
    }

    (*n1)->setName("Miguel Silva");
    (*n1)->setTypeAccount(false);
    

 
    /*Teste 1*/
    if ((*n1)->getName()!="Miguel Silva") 
    {
        cout << "...verifica_NodeAccount_setters: Nome  (= " << (*n1)->getName()<< ") e' diferente do esperado (=Miguel Silva) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_setters: Nome coincide com o esperado (= Miguel Silva) (ok)" << endl;
    
      /*Teste 2*/
    if ((*n1)->getTypeAccount() != false )
    {
        cout << "...verifica_NodeAccount_setters: Tipo de conta (= "<< (*n1)->getTypeAccount() <<") e' diferente do esperado (=false) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_setters: getTypeAccount coincide com o esperado (= false) (ok)" << endl;




    return er;
}

int verifica_NodeAccount_addListPosts(NodeAccount **n1)
{
      int er = 0; 
    if (!(*n1)) {
        cout << "...verifica_NodeAccount_addListPosts: NodeAccount e' NULL (ERRO)" << endl;
        return 1;
    }
    Posts *p1=new Posts("post102343",'S',true);

    Posts *p2=new Posts("post453456",'R',true);

    (*n1)->addListPosts(p1);
    (*n1)->addListPosts(p2);
  //  (*n1)->addListPosts(p2);
    if ((*n1)->getListPosts().size() != 2 )
    {
        cout << "...verifica_NodeAccount_addListPosts: numero de entradas da lista de posts(= "<< (*n1)->getListPosts().size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_addListPosts:  numero de entradas da lista de posts coincide com o esperado (= 2) (ok)" << endl;

    if ((*n1)->getListPosts().size() == 0 )
    return er;
    string it=(*(*n1)->getListPosts().begin())->id;
    
 
    if (it!= p1->id)
    {
        cout << "...verifica_NodeAccount_addListPosts: O primeiro post (= "<< it <<") e' diferente do esperado (=post102343) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_addListPosts: O primeiro post coincide com o esperado (= post102343) (ok)" << endl;
/*
    (*n1)->removeListPosts(p1);
    (*n1)->removeListPosts(p2);
    delete(p1);
    delete(p2); */
    return er;
}

int verifica_NodeAccount_addLikePosts(NodeAccount **n1)
{
      int er = 0; 
    if (!(*n1)) {
        cout << "...verifica_NodeAccount_addLikePosts: NodeAccount e' NULL (ERRO)" << endl;
        return 1;
    }
    (*n1)->addLikePosts("post102343");
    (*n1)->addLikePosts("post453456");
    (*n1)->addLikePosts("post453456");
    if ((*n1)->getLikePosts().size() != 2 )
    {
        cout << "...verifica_NodeAccount_addLikePosts: numero de entradas de likes (= "<< (*n1)->getLikePosts().size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_addLikePosts:  numero de entradas de likes coincide com o esperado (= 2) (ok)" << endl;

    if ((*n1)->getLikePosts()[(*n1)->getLikePosts().size()-1] != "post453456" )
    {
        cout << "...verifica_NodeAccount_addLikePosts: O último like (= "<< (*n1)->getLikePosts()[(*n1)->getLikePosts().size()-1]  <<") e' diferente do esperado (=post453456) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_NodeAccount_addLikePosts: O último like coincide com o esperado (= post453456) (ok)" << endl;


    return er;
}



int verifica_Graph_construtor(Graph **g)
{
    int er = 0;

    *g = new Graph; 

    if (!(*g))
    {
        cout << "...verifica_Graph_construtor: Graph e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_Graph_construtor: Graph nao e' NULL (ok)" << endl;

       if ((*g)->getTotal()!=0)
    {
        cout << "...verifica_Graph_construtor: Total (= "<< (*g)->getTotal() <<") e' diferente do esperado (=0) (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_Graph_construtor: Total coincide com o esperado (= 0) (ok)" << endl;

     if ((*g)->getFollow().size()!=0)
    {
        cout << "...verifica_Graph_construtor: Tamanho do vector (= "<< (*g)->getFollow().size() <<") e' diferente do esperado (=0) (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_Graph_construtor: Tamanho do vector coincide com o esperado (= 0) (ok)" << endl;

    return er;
}



int verifica_Graph_setters(Graph **g)
{
    int er = 0, erro = 0;
       
    NodeAccount *na1 = new NodeAccount("anaf23", "Ana Fonseca", true);
    NodeAccount *na2 = new NodeAccount("DiogoT", "Diogo Tavares", false);


    
    /* Inserir Animal 1*/ 
    erro = (*g)->setAccounts(*na1);
    if (erro == -1)
    {
        cout << "...verifica_Graph_setters: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Animal 2 */
    erro = (*g)->setAccounts(*na2);
    if (erro == -1)
    {
        cout << "...verifica_Graph_setters: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Animal 2 novamente */
    erro = (*g)->setAccounts(*na2);
    if (erro != 1 )
    {
        cout << "...verifica_Graph_setters: nao conseguiu inserir corretamente (ERRO)" << endl;
        return 1;
    }

    erro=(*g)->setTotal(2);  
    /* Testes de Posições*/
    if (erro==-1)
    {
        cout << "...verifica_Graph_setters: não conseguiu inserir o total" << endl;
        er++;
        return er;
    }
    else if ((*g)->getTotal() != 2)
     {
        cout << "...verifica_Graph_setters: Total (= "<< (*g)->getTotal() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
       cout << "...verifica_Graph_setters: Total coincide com o esperado (=2) (ok)" << endl;

    if ((*g)->getAccounts()[1] != na2)
    {
        cout << "...verifica_Graph_setters: 2º conta (= "<< (*g)->getAccounts()[1]->getUsername()  <<") e' diferente do esperado (=DiogoT) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_setters: 2º conta coincide com o esperado (= DiogoT) (ok)" << endl;    
    
     
    return er;
}

int verifica_Graph_accountPosition(Graph **g)
{
    int er = 0, erro = 0;
       
    erro=(*g)->accountPosition("DiogoT2");  
   
    if (erro!=-1)
    {
        cout << "...verifica_Graph_accountPosition: Username que não existe(ERRO)" << endl;
        er++;
        return er;
    }
    
    erro=(*g)->accountPosition("DiogoT");  

      if (erro!=1)
    {
        cout << "...verifica_Graph_accountPosition: Posição (= "<< erro  <<") e' diferente do esperado (=1) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_accountPosition: Posição coincide com o esperado (= 1) (ok)" << endl;    
    
     
    return er;
}

int verifica_Graph_addFollow(Graph **g)
{
    int er = 0, erro = 0;
    NodeAccount *na1=(*g)->getAccounts()[0] ;   
    NodeAccount *na2=(*g)->getAccounts()[1] ;  
  
   erro=(*g)->addFollow(*na1,*na2);  
   
    if (erro==-1)
    {
        cout << "...verifica_Graph_addFollow: Não conseguiu inserir o follow (ERRO)" << endl;
        er++;
        return er;
    }
   
     string it=(*(*g)->getFollow()[0].begin())->getUsername();

    /*  if (it!="DiogoT")
    {
        cout << "...verifica_Graph_addFollow: anaf23 segue (= "<< it <<") e' diferente do esperado (=DiogoT) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_addFollow: anaf23 segue a conta esperada (= DiogoT) (ok)" << endl;    
    
     */
    return er;
}

int verifica_Graph_isFollowedBy(Graph **g)
{
    int er = 0;
    bool erro;
    NodeAccount *na1=(*g)->getAccounts()[0] ;  
    NodeAccount *na2=(*g)->getAccounts()[1] ;  
  
    erro=(*g)->isFollowedBy(*na1,*na2);  
   
    if (erro==false)
    {
        cout << "...verifica_Graph_isFollowedBy: Não conseguiu verificar se anaf23 segue DiogoT (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_isFollowedBy: Conseguiu verificar que anaf23 segue DiogoT(= true) (ok)" << endl;    
    
     
    return er;
}



int verifica_Graph_removeFollow(Graph **g)
{
    int er = 0, erro = 0;
    NodeAccount *na1=(*g)->getAccounts()[0] ;  
    NodeAccount *na2=(*g)->getAccounts()[1] ;  
  
    erro=(*g)->removeFollow(*na1,*na2);  
   
    if (erro==-1)
    {
        cout << "...verifica_Graph_removeFollow: Não conseguiu remover (ERRO)" << endl;
        er++;
        return er;
    }
    
     auto num=(*g)->getFollow()[0].size();

      if (num!=0)
    {
        cout << "...verifica_Graph_removeFollow: total de contas seguidas pela anaf23 (= "<< num   <<") e' diferente do esperado (=0) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_removeFollow: anaf23 não segue nenhuma conta (= 0) (ok)" << endl;    
    
     
    return er;
}


int verifica_Graph_importAccounts(Graph **g)
{
    int er = 0;
    cout << "A importar Graph accounts..." << endl;


    (*g)=new Graph;

    int  import_ok = (*g)->importAccounts("accounts.txt");

  
    if (import_ok == -1) {
        cout << "...verifica_Graph_importAccounts: Erro ao importar base de dados." << endl;
        return 1;
    }
    

    if (*g == NULL)
    {
        cout << "...verifica_Graph_importAccounts: falhou importacao do Graph (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_Graph_importAccounts: NodeAccounts importados com sucesso." << endl;
        }

        if ((*g)->getAccounts().size()!= 47)
        {
            cout << "...verifica_Graph_importAccounts: numero de NodeAccount  (="<< (*g)->getTotal() << ") e' diferente do esperado (= 47) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_Graph_importAccounts: numero de NodeAccount  coincide com o esperado (=47) (ok)" << endl;
    
      if ((*g)->getAccounts()[10]->getUsername() != "aileen90")
    {
        cout << "...verifica_Graph_importAccounts: 11ª conta do vetor (="<< (*g)->getAccounts()[10]->getUsername() << ") e' diferente do esperado (= aileen90) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_Graph_importAccounts: 11ª conta do vetor coincide com o esperado (= aileen90) (ok)" << endl;

  }    
  

  return er; 
}


int verifica_Graph_importfollows(Graph **g)
{
    int er = 0;
    cout << "A importar Graph followers..." << endl;


    
    int  import_ok = (*g)->importFollow("follows.txt");

  
    if (import_ok == -1) {
        cout << "...verifica_Graph_importfollows: Erro ao importar base de dados." << endl;
        return 1;
    }
    

    if (*g == NULL)
    {
        cout << "...verifica_Graph_importfollows: falhou importacao do Graph (ERRO)" << endl;
        return 1;
    }
    else
    {
        if(import_ok == 0) {
        cout << "...verifica_Graph_importfollows: Follows importados com sucesso." << endl;
        }

        if ((*g)->getFollow()[0].size()!= 8)
        {
            cout << "...verifica_Graph_importfollows: o numero de contas que o edenK segue  (="<< (*g)->getFollow()[0].size()<< ") e' diferente do esperado (= 8) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_Graph_importfollows: o numero de contas que o edenK segue coincide com o esperado (=8) (ok)" << endl;
    
      if ((*(*g)->getFollow()[2].begin())->getUsername()!= "aidenp")
    {
        cout << "...verifica_Graph_importfollows: O jules12 segue na primeira posição da lista (="<< (*(*g)->getFollow()[2].begin())->getUsername() << ") e' diferente do esperado (= aidenp) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_Graph_importfollows: O jules12 segue na primeira posição da lista (= aidenp) (ok)" << endl;

  }    
  

  return er; 
}

int verifica_Graph_numberOfFollowing(Graph **g)
{
    int er = 0, erro = 0;
       
    erro=(*g)->numberOfFollowing("scarlettLttt");  
   
    if (erro!=-1)
    {
        cout << "...verifica_Graph_numberOfFollowing: Username que não existe (= "<< erro  <<")  e' diferente do esperado (= -1) (ERRO)" << endl;
        er++;
       
    }
     else
        cout << "...verifica_Graph_numberOfFollowing: Username que não existe (= -1) (ok)" << endl;    
   
    
    erro=(*g)->numberOfFollowing("scarlettL");  

      if (erro!=4)
    {
        cout << "...verifica_Graph_numberOfFollowing:  o numero de contas que o scarlettL segue (= "<< erro  <<") e' diferente do esperado (=4) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_numberOfFollowing: o numero de contas que o scarlettL segue coincide com o esperado (= 4) (ok)" << endl;    
    
     
    return er;
}

int verifica_Graph_followers(Graph **g)
{
    int er = 0, erro = 0;
    list<NodeAccount*> lnova;   
      
   
    lnova=(*g)->followers("aileen90");  

      if (lnova.size()!=2)
    {
        cout << "...verifica_Graph_followers:  o numero de contas que seguem o aileen90 (= "<< erro  <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
    {
        cout << "...verifica_Graph_followers: o numero de contas que seguem aileen90 coincide com o esperado (= 2) (ok)" << endl;    
    if ((*(lnova.begin()))->getUsername()!="edenK")
    {
        cout << "...verifica_Graph_followers:   o aileen90 é seguido pelo (= "<< (*(lnova.begin()))->getUsername()  <<") que e' diferente do esperado (=edenK) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_followers: o aileen90 é seguido pelo (= edenK) (ok)" << endl; 
    } 
    return er;
}

int verifica_Graph_numberType(Graph **g)
{
    int er = 0, result;
    int p1=(*g)->accountPosition("edenK");
    if (p1<0)
    {
        cout << "...verifica_Graph_numberType:  A função accountPosition não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    NodeAccount *n=(*g)->getAccounts()[p1];
    if (n==nullptr)
     {
        cout << "...verifica_Graph_numberType:  Ou a setAccounts ou o getAccounts não estão a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    Posts *pt1=new Posts("post00001",'S',true);
    Posts *pt2=new Posts("post00002",'R',true);
    Posts *pt3=new Posts("post00003",'F',true);
    Posts *pt4=new Posts("post00004",'F',false);
    Posts *pt5=new Posts("post00005",'F',false);
    Posts *pt6=new Posts("post00006",'F',true);

    result=n->addListPosts(pt1);
    n->addListPosts(pt2);
    n->addListPosts(pt3);
    n->addListPosts(pt4);
    n->addListPosts(pt5);
    n->addListPosts(pt6);

    p1=(*g)->accountPosition("scarlettL");
  
    
    NodeAccount *n1=(*g)->getAccounts()[p1];

    Posts *pt7=new Posts("post00007",'S',true);
    Posts *pt8=new Posts("post00008",'S',true);
 

    n1->addListPosts(pt7);
    n1->addListPosts(pt8);

     if (result==-1)
    {
        cout << "...verifica_Graph_mostLikesGivenTo:  A função addListPosts não está a funcionar corretamente (ERRO)" << endl;
        return 1;
    }


    if (result==-1)
    {
        cout << "...verifica_Graph_numberType:  A função addListPosts não está a funcionar corretamente (ERRO)" << endl;
        return 1;
    }
    else
    {

    result=(*g)->numberType("edenK",'F');    
        
    if (result!=4)
    {
        cout << "...verifica_Graph_numberType:  O total de post do tipo F do edenK (= "<< result  <<") e' diferente do esperado (=4) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_numberType: O total de post do tipo F do edenK é o esperado (= 4) (ok)" << endl; 
    } 
    return er;
}

int verifica_Graph_mostLikedPost(Graph **g)
{
    int er = 0,result;
    int p1=(*g)->accountPosition("scarlettL");
    if (p1<0)
    {
        cout << "...verifica_Graph_mostLikedPost:  A função accountPosition não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    NodeAccount *n=(*g)->getAccounts()[p1];
    if (n==nullptr)
     {
        cout << "...verifica_Graph_mostLikedPost:  Ou a setAccounts ou o getAccounts não estão a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
  



    result=n->addLikePosts("post00004");
    result=n->addLikePosts("post00002");
   if (result==-1)
    {
        cout << "...verifica_Graph_mostLikedPost:  A função addLikePosts não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }

    p1=(*g)->accountPosition("aidenp");
    n=(*g)->getAccounts()[p1];
    result=n->addLikePosts("post00001");
    result=n->addLikePosts("post00002");
     p1=(*g)->accountPosition("edenK");
    n=(*g)->getAccounts()[p1];
    result=n->addLikePosts("post00007");
   

     p1=(*g)->accountPosition("rowanl6");
    n=(*g)->getAccounts()[p1];
    result=n->addLikePosts("post00001");
    result=n->addLikePosts("post00006");
    result=n->addLikePosts("post00003");
    result=n->addLikePosts("post00008");
    result=n->addLikePosts("post00007");
    Posts *pts=(*g)->mostLikedPost("edenK");
    if (pts->id!="post00001")
    {
        cout << "...verifica_Graph_mostLikedPost:   O post (= "<< pts->id  <<") e' diferente do esperado (=post00001) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_mostLikedPost: O post é o esperado (= post00001) (ok)" << endl; 

    
    return er;
}

int verifica_Graph_mostLikesGivenTo(Graph **g)
{
    int er = 0;
    int p1=(*g)->accountPosition("scarlettL");
    if (p1<0)
    {
        cout << "...verifica_Graph_mostLikesGivenTo:  A função accountPosition não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    NodeAccount *n=(*g)->getAccounts()[p1];
    if (n==nullptr)
     {
        cout << "...verifica_Graph_mostLikesGivenTo:  Ou a setAccounts ou o getAccounts não estão a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }

    

 
    p1=(*g)->accountPosition("rowanl6");
    n=(*g)->getAccounts()[p1];


    


    NodeAccount  *na=(*g)->mostLikesGivenTo("rowanl6");
    if (na->getUsername()!="edenK")
    {
        cout << "...verifica_Graph_mostLikesGivenTo:   A conta (= "<< na->getUsername() <<") e' diferente do esperado (=edenK) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_mostLikesGivenTo:  A conta é o esperado (= edenK) (ok)" << endl; 

    
    return er;
}

int verifica_Graph_commonFollowers(Graph **g)
{

     int er = 0;
    int p1=(*g)->accountPosition("edenK");
    if (p1<0)
    {
        cout << "...verifica_Graph_commonFollowers:  A função accountPosition não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    NodeAccount *n=(*g)->getAccounts()[p1];
    if (n==nullptr)
     {
        cout << "...verifica_Graph_commonFollowers:  Ou a setAccounts ou o getAccounts não estão a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    p1=(*g)->accountPosition("valentinag12");
    NodeAccount *n1=(*g)->getAccounts()[p1];
    list<NodeAccount*> lt;
    lt.push_back(n);
    lt.push_back(n1);
   
    vector<NodeAccount*> ve=(*g)->commonFollowers(lt);

    if (ve.empty())
    {
        cout << "...verifica_Graph_commonFollowers:   vetor vazio (ERRO)" << endl;
        return 1;
    }
     if (ve.size()!=2)
    {
        cout << "...verifica_Graph_commonFollowers:   O numero de contas no vetor (= "<< ve.size() <<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_commonFollowers:  O numero de contas no vetor é o esperado (= 2) (ok)" << endl; 


    bool r1;
    p1=(*g)->accountPosition("david45");
    n1=(*g)->getAccounts()[p1];
    if (find(ve.begin(),ve.end(),n1)==ve.end())
    r1=false; else
    r1=true;


    if (!r1)
    {
        cout << "...verifica_Graph_commonFollowers:   david45 devia estar no vetor (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_commonFollowers:  david45 esta no vetor (ok)" << endl; 
    p1=(*g)->accountPosition("scarlettL");
    n1=(*g)->getAccounts()[p1];
    if (find(ve.begin(),ve.end(),n1)==ve.end())
    r1=false; else
    r1=true;


    if (!r1)
    {
        cout << "...verifica_Graph_commonFollowers:   scarlettL devia estar no vetor (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_commonFollowers:  scarlettL esta no vetor (ok)" << endl; 
    
    return er;
}


int verifica_Graph_pathTo(Graph **g)
{

     int er = 0;
    int p1=(*g)->accountPosition("scarlettL");
    if (p1<0)
    {
        cout << "...verifica_Graph_pathTo:  A função accountPosition não está a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    
    NodeAccount *n=(*g)->getAccounts()[p1];
    if (n==nullptr)
     {
        cout << "...verifica_Graph_pathTo:  Ou a setAccounts ou o getAccounts não estão a funcionar corretamente (ERRO)" << endl;
        return 1; 
    }
    p1=(*g)->accountPosition("aidenp");
    NodeAccount *n1=(*g)->getAccounts()[p1];
 
    vector<NodeAccount*> ve=(*g)->pathTo("scarlettL","aidenp");

    if (ve.empty())
    {
        cout << "...verifica_Graph_pathTo:   vetor vazio (ERRO)" << endl;
        return 1;
    }
     if (ve.size()!=4)
    {
        cout << "...verifica_Graph_pathTo:   O numero de contas no vetor (= "<< ve.size() <<") e' diferente do esperado (=4) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_pathTo:  O numero de contas no vetor é o esperado (= 4) (ok)" << endl; 

     if (ve[0]!=n)
    {
        cout << "...verifica_Graph_pathTo:   A conta de origem (= "<< ve[0]->getUsername() <<") e' diferente do esperado (=scarlettL) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_pathTo:   A conta de origem é o esperado (= scarlettL) (ok)" << endl; 

    if (ve[ve.size()-1]!=n1)
    {
        cout << "...verifica_Graph_pathTo:   A conta de destino (= "<< ve[ve.size()-1]->getUsername() <<") e' diferente do esperado (=aidenp) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_pathTo:   A conta de destino é o esperado (= aidenp) (ok)" << endl;     

    bool r1=true;
    NodeAccount* naux, *nauxprox;
    
    
    list<NodeAccount*> lt;
    for ( int i=0;i<(int)ve.size()-1;i++)
    {
        naux=ve[i];
        nauxprox=ve[i+1];
        p1=(*g)->accountPosition(naux->getUsername());
        lt=(*g)->getFollow()[p1];
        if(find(lt.begin(),lt.end(),nauxprox)==lt.end())
        r1=false;
    }

    if (!r1)
    {
        cout << "...verifica_Graph_pathTo:   caminho não está correto (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_Graph_pathTo:  caminho correto (ok)" << endl; 
   
    return er;
}


int verifica_Graph_importPosts(Graph **g)
{
    int er = 0;
    cout << "A importar Graph posts..." << endl;


    (*g)=new Graph;

    int  import_ok = (*g)->importAccounts("accounts.txt");
   

  
    if (import_ok == -1) {
        cout << "...verifica_Graph_importPosts: Erro ao importar as contas." << endl;
        return 1;
    }
    import_ok = (*g)->importFollow("follows.txt");

    if (import_ok == -1) {
        cout << "...verifica_Graph_importPosts: Erro ao importar os follows." << endl;
        return 1;
    }
    import_ok = (*g)->importPosts("posts.txt");
     if (import_ok == -1) {
        cout << "...verifica_Graph_importPosts: Erro ao importar os posts." << endl;
        return 1;
    }


    if ((*g)->getAccounts()[0]->getListPosts().size() != 6)
    {
            cout << "...verifica_Graph_importPosts: numero de Posts do edenK  (="<< (*g)->getAccounts()[0]->getListPosts().size()<< ") e' diferente do esperado (= 6) (ERRO)" << endl;
            er++;
    }
    else
            cout << "...verifica_Graph_importPosts: numero de Posts do edenK coincide com o esperado (=6) (ok)" << endl;
    
      if ((*g)->getAccounts()[0]->getLikePosts().size() != 5)
    {
        cout << "...verifica_Graph_importPosts: numero de likes do edenK (="<< (*g)->getAccounts()[0]->getLikePosts().size()  << ") e' diferente do esperado (= 5) (ERRO)"<< endl;
        er++;
        
    }
    else
        cout << "...verifica_Graph_importPosts: numero de likes do edenK coincide com o esperado (= 5) (ok)" << endl;

   
  

  return er; 
}







int verifica_HashTable_construtor(HashTable **ht)
{
    int er = 0;

    *ht = new HashTable(7); 

    if (!(*ht))
    {
        cout << "...verifica_HashTable_construtor: HashTable e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_HashTable_construtor: HashTable nao e' NULL (ok)" << endl;

       if ((*ht)->getTableSize()!=7)
    {
        cout << "...verifica_HashTable_construtor: Total (= "<< (*ht)->getTableSize() <<") e' diferente do esperado (=7) (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_HashTable_construtor: Total coincide com o esperado (=7) (ok)" << endl;

    return er;
}

int verifica_HashTable_insertAccountStats(HashTable **ht)
{
    int er = 0; 
    if (!(*ht)) {
        cout << "...verifica_HashTable_insertAccountStats: HashTable e' NULL (ERRO)" << endl;
        return 1;
    }
    AccountStats *as1=new AccountStats("edenK",1,2,3,4,5,6,7);
    AccountStats *as2=new AccountStats("aidenp",12,22,32,42,52,62,72);
    AccountStats *as3=new AccountStats("jules12",1,12,13,14,15,16,17);
    AccountStats *as4=new AccountStats("david45",21,22,23,24,25,26,27);

    int r1=(*ht)->insertAccountStats(*as1);
     if (r1 != 4 )
    {
        cout << "...verifica_HashTable_insertAccountStats: Posição de edenK na tabela (= "<< r1 <<") e' diferente do esperado (=4) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_HashTable_insertAccountStats: Posição de edenK na tabela coincide com o esperado (= 4) (ok)" << endl;

    r1=(*ht)->insertAccountStats(*as2);
    r1=(*ht)->insertAccountStats(*as3);
    r1=(*ht)->insertAccountStats(*as4);

    
    
 if (r1 != 6 )
    {
        cout << "...verifica_HashTable_insertAccountStats: Posição de david45 na tabela (= "<< r1 <<") e' diferente do esperado (=6) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_HashTable_insertAccountStats: Posição de david45 na tabela coincide com o esperado (= 6) (ok)" << endl;
    return er;
}




int verifica_HashTable_searchAccountStats(HashTable **ht)
{
    int er = 0; 
    if (!(*ht)) {
        cout << "...verifica_HashTable_searchAccountStats: HashTable e' NULL (ERRO)" << endl;
        return 1;
    }
 

    int r1=(*ht)->searchAccountStats("david454");
     if (r1 != -1 )
    {
        cout << "...verifica_HashTable_searchAccountStats:(user inexistente) Retorno da função (= "<< r1 <<") e' diferente do esperado (=-1) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_HashTable_searchAccountStats:(user inexistente)  Retorno da função coincide com o esperado (= -1) (ok)" << endl;

    r1=(*ht)->searchAccountStats("jules12"); 
     if (r1 != 3 )
    {
        cout << "...verifica_HashTable_searchAccountStats:(user aidenp) Retorno da função (= "<< r1 <<") e' diferente do esperado (=3) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_HashTable_searchAccountStats:(user aidenp)  Retorno da função coincide com o esperado (= 3) (ok)" << endl;



    return er;
}

int verifica_HashTable_deleteAccountStats(HashTable **ht)
{
    int er = 0; 
    if (!(*ht)) {
        cout << "...verifica_HashTable_deleteAccountStats: HashTable e' NULL (ERRO)" << endl;
        return 1;
    }
 

    int r1=(*ht)->deleteAccountStats("aidenp");
     if (r1 != 0 )
    {
        cout << "...verifica_HashTable_deleteAccountStats: Retorno da função (= "<< r1 <<") e' diferente do esperado (=0) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_HashTable_deleteAccountStats: Retorno da função coincide com o esperado (= 0) (ok)" << endl;

  
    return er;
}

int verifica_HashTable_importFromGraph(HashTable **ht,Graph **g)
{
    int er = 0; 
    
    *ht = new HashTable(89); 

    if (!(*ht)) {
        cout << "...verifica_HashTable_importFromGraph: HashTable e' NULL (ERRO)" << endl;
        return 1;
    }
 

    int r1=(*ht)->importFromGraph(**g);
     if (r1 != 0 )
    {
        cout << "...verifica_HashTable_importFromGraph: Retorno da função (= "<< r1 <<") e' diferente do esperado (=0) (ERRO)" << endl;
        er++;
    }
    else
    {    cout << "...verifica_HashTable_importFromGraph: Retorno da função coincide com o esperado (= 0) (ok)" << endl; }

     if ((*ht)->totalAccounts != 47 )
    {
        cout << "...verifica_HashTable_importFromGraph: Total de contas na tabela (= "<<(*ht)->totalAccounts <<") e' diferente do esperado (=47) (ERRO)" << endl;
        er++;
    }
    else
    {    cout << "...verifica_HashTable_importFromGraph: Total de contas na tabela coincide com o esperado (= 47) (ok)" << endl;}
    
        if ((*ht)->getTable()[49] == nullptr  )
    {
        cout << "...verifica_HashTable_importFromGraph: Posição 49 da tabela devia estar preenchida (ERRO)" << endl;
        er++;
        return er;
    }
       if ((*ht)->getTable()[49]->username != "edenK"  )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) username (= "<<(*ht)->getTable()[49]->username<<") e' diferente do esperado (=edenK) (ERRO)" << endl;
        er++;
        
    }
    else
         cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) username  coincide com o esperado (= edenK) (ok)" << endl;
          
    if ((*ht)->getTable()[49]->followees != 8 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) followees (= "<<(*ht)->getTable()[49]->followees<<") e' diferente do esperado (=8) (ERRO)" << endl;
        er++;
        
    }
    else
         cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) followees  coincide com o esperado (= 8) (ok)" << endl;
    
   if ((*ht)->getTable()[49]->following != 2 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) following (= "<<(*ht)->getTable()[49]->followees<<") e' diferente do esperado (=2) (ERRO)" << endl;
        er++;
        
    }
    else
         cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) following  coincide com o esperado (= 2) (ok)" << endl;
    
    if ((*ht)->getTable()[49]->likes != 1 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) likes (= "<<(*ht)->getTable()[49]->likes<<") e' diferente do esperado (=1) (ERRO)" << endl;
        er++;
        
    }
    else
        cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) likes  coincide com o esperado (= 1) (ok)" << endl;
    
    if ((*ht)->getTable()[49]->posts != 6 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) posts (= "<<(*ht)->getTable()[49]->posts<<") e' diferente do esperado (=6) (ERRO)" << endl;
        er++;
        
    }
    else
        cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) posts  coincide com o esperado (= 6) (ok)" << endl;
    
    if ((*ht)->getTable()[49]->postsStories != 1 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsStories (= "<<(*ht)->getTable()[49]->postsStories<<") e' diferente do esperado (=1) (ERRO)" << endl;
        er++;
        
    }
    else
        cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsStories  coincide com o esperado (= 1) (ok)" << endl;
    
     if ((*ht)->getTable()[49]->postsFeeds != 4 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsFeeds (= "<<(*ht)->getTable()[49]->postsFeeds<<") e' diferente do esperado (=4) (ERRO)" << endl;
        er++;
        
    }
    else
        cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsFeeds  coincide com o esperado (= 4) (ok)" << endl;
    
    if ((*ht)->getTable()[49]->postsReels != 1 )
    {
       cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsReels (= "<<(*ht)->getTable()[49]->postsReels<<") e' diferente do esperado (=1) (ERRO)" << endl;
        er++;
        
    }
    else
        cout << "...verifica_HashTable_importFromGraph: (Posição 49 da tabela) postsReels  coincide com o esperado (= 1) (ok)" << endl;
    

    return er;
}


int main()
{
    int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;
    
    /* Verifica construtor do NodeAccount */
    NodeAccount *n1;
    cout << "-----" << n1 << "--------------------------------" << endl;
    error = verifica_NodeAccount_construtor(&n1);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_NodeAccount_construtor\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAccount_construtor passou\n\n" << endl;
    }  
  

    cout << "-----" << n1 << "--------------------------------" << endl;

    /*Verifica setters de NodeAccount */
   error = verifica_NodeAccount_setters(&n1);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_NodeAccount_setters\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAccount_setters passou\n\n" << endl;
    }
    cout << "-----" << n1 << "--------------------------------" << endl;
    /* Verifica addListPosts */
    error = verifica_NodeAccount_addListPosts(&n1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_NodeAccount_addListPosts\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAccount_addListPosts passou\n\n" << endl;
    }
cout << "-----" << n1 << "--------------------------------" << endl;
      /* Verifica addLikePosts */
    error = verifica_NodeAccount_addLikePosts(&n1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_NodeAccount_addLikePosts\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_NodeAccount_addLikePosts passou\n\n" << endl;
    }
cout << "-----" << n1 << "--------------------------------" << endl;

      /* Verifica construtor do Graph */
    Graph *g;
    error = verifica_Graph_construtor(&g);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_Graph_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_construtor passou\n\n" << endl;
    }


    /* Verifica setters */ 
    error = verifica_Graph_setters(&g);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_setters\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_setters passou\n\n" << endl;
    }


    
    /* Verifica accountPosition */ 
    error = verifica_Graph_accountPosition(&g);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_accountPosition\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_accountPosition passou\n\n" << endl;
    }


     error = verifica_Graph_addFollow(&g);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_addFollow\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_addFollow passou\n\n" << endl;
    }

   
        error = verifica_Graph_isFollowedBy(&g);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_isFollowedBy\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_isFollowedBy passou\n\n" << endl;
    }
    /* Verifica componente remove */
    error = verifica_Graph_removeFollow(&g);
     if (error)
     {
         cout << "ERRO: " << error << " erros encontrados em verifica_Graph_removeFollow\n\n" << endl;
         errorCount += error;
     }
     else
     {
         cout << "OK: verifica_Graph_removeFollow passou\n\n" << endl;
     }


    /* Verifica importa accounts*/ 
    Graph *g1;
    error = verifica_Graph_importAccounts(&g1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_Graph_importAccounts\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout<< "OK: verifica_Graph_importAccounts passou\n\n" << endl;
    }

        /* Verifica importa follows*/ 
  
    error = verifica_Graph_importfollows(&g1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_Graph_importfollows\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout<< "OK: verifica_Graph_importfollows passou\n\n" << endl;
    }
    /* Verifica numberOfFollowing*/

    error = verifica_Graph_numberOfFollowing(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_numberOfFollowing\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_numberOfFollowing passou\n\n" << endl;
    }

     
    error = verifica_Graph_followers(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_followers\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_followers passou\n\n" << endl;
    }

      error = verifica_Graph_numberType(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_numberType\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_numberType passou\n\n" << endl;
    }
    
    error = verifica_Graph_mostLikedPost(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_mostLikedPost\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_mostLikedPost passou\n\n" << endl;
    }
    

      error = verifica_Graph_mostLikesGivenTo(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_mostLikesGivenTo\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_mostLikesGivenTo passou\n\n" << endl;
    }

    error = verifica_Graph_commonFollowers(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_commonFollowers\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_commonFollowers passou\n\n" << endl;
    }


    error = verifica_Graph_pathTo(&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_pathTo\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_pathTo passou\n\n" << endl;
    }


    Graph *g2;
    error = verifica_Graph_importPosts(&g2);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_Graph_importPosts\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_Graph_importPosts passou\n\n" << endl;
    }

    HashTable *h;

    error = verifica_HashTable_construtor(&h);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_HashTable_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_HashTable_construtor passou\n\n" << endl;
    }


    error = verifica_HashTable_insertAccountStats(&h);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_HashTable_insertAccountStats\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_HashTable_insertAccountStats passou\n\n" << endl;
    }

  
      error = verifica_HashTable_deleteAccountStats(&h);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_HashTable_deleteAccountStats\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_HashTable_deleteAccountStats passou\n\n" << endl;
    }

    error = verifica_HashTable_searchAccountStats(&h);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_HashTable_searchAccountStats\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_HashTable_searchAccountStats passou\n\n" << endl;
    }
    

    HashTable *h1;

    error = verifica_HashTable_importFromGraph(&h1,&g1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_HashTable_importFromGraph\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_HashTable_importFromGraph passou\n\n" << endl;
    }



   // (*h1).mostrar();


    /* Fim dos testes */
    if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    delete n1;
    delete g;
    delete g1;
    delete g2;
    delete h;
    delete (h1);

    return 0;
}
