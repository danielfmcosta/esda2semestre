#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include "fila.cpp"

// Código para teste
// Não modificar 

using namespace std;

void imprime_fila(queue<char> fila)
{ 
	// imprime fila
    cout << "Fila: ";
    cout << "[";
	
	while (!fila.empty())
    {
        cout << "   " << fila.front();
        fila.pop();
    }
    cout << "  ]" << endl;
}


void imprime_pos_do_maior(int pos)
{ 
	// imprime posição elemento
	
	if (pos == 0) cout << "Fila vazia!\n" << endl;
    else cout << "O maior elemento da fila encontra-se na " << to_string(pos) << "ª posição.\n" << endl; 
    
    return;
}

void imprime_res_insercao(int res)
{ 
	if (res == -1) cout << "Erro ao inserir!" << endl;  
    else if (res == 0) cout << "Inserção conseguida!" << endl;
	
    return;
}


int main()
{
    queue<char> f1;
    queue<char> f2;
    queue<char> f3;

    f1.push('A');
    f1.push('B');
    f1.push('C');
    f1.push('D');
    f1.push('E');
    f1.push('F');
    f3.push('~');
    f3.push('.');
    f3.push(' ');
    f3.push('+');
    f3.push('y');
    f3.push('2');
    f3.push('f');
    f3.push('B');
    f3.push('<');
    f3.push('&');

    cout << "\nTeste à função <pos_maior_elemento>\n" << endl;
    int res;
    
    imprime_fila(f2);
    res = pos_maior_elemento(f2);
    imprime_pos_do_maior(res);
    
    imprime_fila(f1);
    res = pos_maior_elemento(f1);
    imprime_pos_do_maior(res);
    
    imprime_fila(f3);
    res = pos_maior_elemento(f3);
    imprime_pos_do_maior(res);
     
    cout << "\nTeste à função <insere_na_posicao>\n";
    
    cout << endl;

    cout << "Fila: NULL" << endl;
    cout << "Inserir elemento X na posição 1: " << endl;
    res = insere_na_posicao(NULL, 'X', 1);
    imprime_res_insercao(res);
    	
    cout << endl;

    imprime_fila(f1);
    cout << "Inserir elemento H na posição 8: " << endl;
    res = insere_na_posicao(&f1, 'H', 8);
    imprime_res_insercao(res);
    imprime_fila(f1);
    cout << endl;
    
    imprime_fila(f1);
    cout << "Inserir elemento G na posição 7: " << endl;
    res = insere_na_posicao(&f1, 'G', 7);
    imprime_res_insercao(res);
    imprime_fila(f1);
    cout << endl;
    
    imprime_fila(f1);
    cout << "Inserir elemento Y na posição 1: " << endl;
    res = insere_na_posicao(&f1, 'Y', 1);
    imprime_res_insercao(res);
    imprime_fila(f1);
    cout << endl;
    
    imprime_fila(f1);
    cout << "Inserir elemento Z na posição 4: " << endl;
    res = insere_na_posicao(&f1, 'Z', 4);
    imprime_res_insercao(res);
    imprime_fila(f1);
    cout << endl;
    
    return 0;
    
}