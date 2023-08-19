#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

/*** problema 2.1 ***/
int  contar_apelidos(queue<string> f)
{
	int count=0;
	while(!f.empty()){
		if(f.front().find(" ") < f.front().size()){
			count++;
		}
		f.pop();
	}
	
	return count;
}

/*** problema 2.2 ***/

list<string> lista_a_j (queue<string>& f )
{
    list<string> res;
	
    while(!f.empty()){
		if(f.front()[0] >='A' && f.front()[0] <= 'J'){
			res.insert(res.begin(), f.front());
		}
		f.pop();
	}
	return res;
} 

int print_list(list<string> l)
{
  if (l.empty())
  return -1;
  for(auto it=l.begin();it!=l.end();it++)
  {
     cout << (*it) << endl;
  }
 
  return 0;
}



int main()
{
	
	/* testes */
	queue<string> f;
	f.push("Maria");
	f.push("João Teixeira");
    f.push("Júlia Costa");
	f.push("Henrique");
	f.push("Afonso Costa");
	f.push("Nuno Antunes");


	int ve;
	/* inicio teste prob2.1 */
	ve = contar_apelidos(f);
	if(ve==4) { 
		cout <<"Numero de pessoas com apelidos correto: 4"<<endl;		
	} else
		cout <<"Numero de pessoas com apelidos errado (numero:"<< ve<<" esperado: 4)"<<endl;
	/* fim teste prob2.1 */

	/* inicio teste prob2.2 */
	list<string> l;
  l=lista_a_j (f);
   print_list(l);
		
	/* fim teste prob2.2 */


	return 0;
}
