#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;
struct elemento
{	
    /* prioridade do elemento da heap*/
    int prioridade;  
    /* valor do elemento da heap*/
    string valor;   

    elemento(int pri,string va)
    {prioridade=pri;
    valor=va;
    }

} ;

struct CompareP {
    bool operator () (elemento na1, elemento na2)
    {

        return na1.prioridade > na2.prioridade;
    }
}  ;
           
/****************************************************/
int atribui_prioridade_maxima(priority_queue<elemento, vector<elemento>, CompareP> &pq , string valor)
{
	/*responder aqui*/
    if(valor.empty()){
        return -1;
    }
    priority_queue<elemento, vector<elemento>, CompareP> temp(pq);
    while(!pq.empty()){
        pq.pop();
    }
    bool exist = false;
    while(!temp.empty()){
        if(temp.top().valor == valor){
            pq.push(elemento(1, valor));
            temp.pop();
            bool exist = true;
            continue;
        }
        pq.push(temp.top());
        temp.pop();
    }
    if(!exist){
        return 1;
    }

    return 0;
}


	



/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

#define MAX_STR 500
#define MAX_LINE 100
#define MAX_SIZE 1000

int main()
{
	
    priority_queue<elemento, vector<elemento>, CompareP> pq;
    elemento e1(23,"Porto");
    pq.push(e1);
    elemento e2(25,"Lisboa");
    pq.push(e2);
    elemento e3(5,"Coimbra");
    pq.push(e3);
    elemento e4(8,"Braga");
    pq.push(e4);
    elemento e5(12,"Faro");
    pq.push(e5);
    elemento e6(23,"Sesimbra");
    pq.push(e6);
    elemento e7(26,"Vila Real");
    pq.push(e7);
    elemento e8(8,"Leiria");
    pq.push(e8);

    int i=atribui_prioridade_maxima(pq,"Vila Real");

    cout << pq.top().valor << "- "<<pq.top().prioridade<<endl;
	return 0;
}
