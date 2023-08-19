#include <iostream>
#include <vector>
#include <fstream> 
#include <algorithm>

using namespace std;

int print_vec_componentes(vector<string> vec_comp)
{
    int size=vec_comp.size();
   
    for ( int i=0; i<size; i++ )
    {
        cout << vec_comp[i]<< endl;
    } 

    return 0;

}

int print_vec_custos(vector<float> vec_custos)
{
    int size=vec_custos.size();
   
   for ( int i=0; i<size; i++ )
    {
        cout << vec_custos[i]<< endl;
    } 

    return 0;

}

/*
 *Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos nomes das peças num vetor.
**/

vector<string> cria_vet_componentes(string f)
{
    ifstream file(f);
    vector<string> vec;
    string c;
    int n=1;
    if(!file){
        cout<<"Error! File Does not Exist";
        return {};
    }
    while(!file.eof()){
        getline(file, c);
        if(n%2==1){
            c.erase(c.size()-1);
            vec.push_back(c);
        }
        n++;
    }
    cout << endl;

    return vec;

}

/**
 * Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos respectivos valores das peças noutro vetor.
**/

vector<float> cria_vet_custos(string f)
{
    ifstream file(f);
    vector<float> vec;
    string c;
    float k=0;
    int n=0;
    if(!file){
        cout<<"Error! File Does not Exist";
        return {};
    }
    while(!file.eof()){
        getline(file, c);
        if(n%2==1){
            k = stof(c);
            vec.push_back(k);
        } 
        n++;
    }
    cout << endl;

    return vec;
}

/**
 * Apresenta no ecran o preço da peça str_componente.
 * Retorna 0 se conseguiu ou -1 se não conseguiu.
**/

int custo_componente(string str_componente, vector<string> vec_componentes, vector<float> vec_custos){
    int flag=-1, k=vec_componentes.size();
    for(int i=0; i<k; i++){
        if(vec_componentes[i].compare(str_componente)==0){
            cout << "O preço do componente " << str_componente << " é: " << vec_custos[i] << endl;
            flag=0; 
        }
    }
    if(flag==-1){
        cout << "Componente " << str_componente << " não encontrado." << endl;
    }
    return flag;
}

/**Test code. Do not change**/

int main() {

    vector<string> vec_compon;
    vector<float> vec_custos;
    int result;
   
    vec_compon = cria_vet_componentes("ex02.txt");
    print_vec_componentes(vec_compon);
    vec_custos = cria_vet_custos("ex02.txt");
    print_vec_custos(vec_custos);
    result = custo_componente("Jante", vec_compon, vec_custos);
    cout << "Return de Jante é: " << result << endl;
    result = custo_componente("Retrovisor", vec_compon, vec_custos);
    cout << "Return de Retrovisor é: " << result << endl;
    result = custo_componente("Roda", vec_compon, vec_custos);
    cout << "Return de Roda é: " << result << endl;
    result = custo_componente("Vidro traseiro", vec_compon, vec_custos);
    cout << "Return de Vidro traseiro é: " << result << endl; 
    
    return 0;
}