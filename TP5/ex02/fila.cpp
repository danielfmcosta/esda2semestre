/*****************************************************************/
/*                 Fila | ESDA | LEEC | 2022/23                  */
/*****************************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int pos_maior_elemento(queue<char> fila)
{ 
	// alínea a)
	// função que devolve a posição do maior elemento presente numa fila. 
	int k=1, i=0;
	char c = fila.front();
	while(!fila.empty()){
		if(fila.front() >= c){
			i=k;
			c=fila.front();
		}
		k++;
		fila.pop();
	}
	
	return i;
	
}

int insere_na_posicao(queue<char>* fila, char elem, unsigned int pos)
{ 
	// alínea b)
	// função que insere elemento elem na posicao pos numa fila.
	// retorna 0 se conseguiu, -1 se não conseguiu. 
	if(fila==NULL || (int)pos<1 || pos > fila->size()+1){
		return -1;
	}
	queue<char> temp;
	int i=1;
	while(!fila->empty()){
		temp.push(fila->front());
		fila->pop();
	}
	while(!temp.empty()){
		if(i==(int)pos){
			fila->push(elem);
		}
		fila->push(temp.front());
		temp.pop();
		i++;
	}
	if(pos==(fila->size()+1)){
		fila->push(elem);
	}
	return 0;
	
}