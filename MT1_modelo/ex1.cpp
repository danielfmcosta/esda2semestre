#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int print_vet(vector<int> v)
{
  cout << "[ " ;   
  for(int i=0;i<(int)v.size();i++)
  {
     cout << v[i] << ' ';
  }
  cout<<"]" << endl;
  return 0;
}
int print_pilha(stack<int> s)
{
  cout << "cromoss:[ " ;   
 while (!s.empty())
  {   cout << s.top() << ' ';
        s.pop();
  }
  cout<<"]" << endl;
  return 0;
}

vector<int> junta_colecoes(vector<int>& cromoss1, vector<int>& cromoss2)
{
    vector<int> cromos3;
    cromos3.insert(cromos3.end(), cromoss1.begin(), cromoss1.end());
    cromos3.insert(cromos3.end(), cromoss2.begin(), cromoss2.end());
    sort(cromos3.begin(), cromos3.end());
    for(auto it=(cromos3.begin()+1); it < cromos3.end(); ){
        if(*it==*(it-1)){
            it = cromos3.erase(it);
        }
        else{
            it++;
        }
    }
    return cromos3;
}
void juntar_repetidos(stack<int>& cromoss, vector<int> acrescentar)
{
    stack<int> temp;
    while(!cromoss.empty()){
        for(int i=0; i< (int) acrescentar.size(); i++){
            if(cromoss.top()==acrescentar[i]){
                temp.push(acrescentar[i]);              
            }
        }
        temp.push(cromoss.top());
        cromoss.pop();
    }
    while(!temp.empty()){
        cromoss.push(temp.top());
        temp.pop();
    }
}

int main()
{
    // teste ao ex1.1
    vector<int>  colecao1{2,4,5,6,5,4,10,11,10,10};
	vector<int>  colecao2{3,4,6,9,12};
    vector<int>  ve;
    ve.clear();
    ve = junta_colecoes(colecao1, colecao2);
	if(!ve.empty()) { 
		if (ve.size()==9) cout << "\nNúmero de cromoss na nova coleção: 9 (Certo)"<<endl;
		else cout << "\nNúmero de cromoss na nova coleção :"<<ve.size()<<" (errado, tem que dar 9)"<<endl;
		cout << "Lista da nova coleção: ";
        print_vet(ve);
    }


    //teste ex1.2
    stack<int> cro;

    cro.push(24);
    cro.push(5);
    cro.push(35);
    cro.push(11);
    cro.push(6);
    cro.push(2);

	
	vector<int> repetidos{5,34,24};
		
	juntar_repetidos(cro, repetidos);
	stack<int> cro1;
	if(cro.size()==8)
	{
		int ele;
        cro1=cro;
        cro.pop();
        cro.pop();
        cro.pop();
        cro.pop();
        ele=cro.top();
        cro.pop();
		if (ele!=5 || cro.top()!=5) {
				cout<<"O cromos numero 5 não foi inserido no local correto"<<endl;

		} else {
			 cro.pop();
        ele=cro.top();
        cro.pop();
			if (ele!=24 || cro.top()!=24) {
				cout <<"O cromos numero 24 não foi inserido no local correto"<<endl;

			} else { cout<<"Os cromoss foram inseridos nos locais corretos"<<endl ;
                    print_pilha(cro1);
            }
		}			
	}
	else{
		cout<<"pilha com tamanho errado (tamanho: "<<cro.size()<<"; esperado: 8)"<<endl;
		print_pilha(cro1);
	}
}