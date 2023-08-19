#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int adicionar(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, string file_name)
{
  // alínea a)
  if(file_name.empty()){
    return -1;
  }
  ifstream file(file_name);
  if(!file){
    return -1;
  }
  int k=1;
  string c;
  while(getline(file, c)){
    pq->push(make_pair(k++, c));
  }

  return k;
}

void imprimir(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, int pos_ini, int pos_fin)
{
  // alínea b)
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> temp(*pq);
  int var = (pos_fin - pos_ini) + 1;
  cout << "Primeiros "<< var << " pilotos: " << endl;
  for(int i=1; i<pos_ini; i++){
    temp.pop();
  }
  for(int i=1; i<=(var); i++){
    cout << "#" << temp.top().first << "\t" << temp.top().second << endl;
    temp.pop();
  }
}

string seleciona_por_ordem(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, int k)
{
  // alínea c)
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> temp(*pq);
  if(k> (int) pq->size() || k<0){
    return "";
  }
  int i = 1;
  if(k > (int) temp.size() || k < 1){
    return "";
  }
  while(i<k){
    temp.pop();
    i++;
  }

  return temp.top().second;
}

int coloca_na_ordem(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, string piloto, int k)
{
  // alínea d)
  if (k < 1 || piloto.empty() || k> (int) pq->size()) {
      return 0;
  }

  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> temp;
  
  for(int i=1; i<k; i++) {
    temp.push(pq->top());
    pq->pop();
  }
  temp.push(make_pair(k, piloto));
  while(!pq->empty()) {
    temp.push(make_pair(pq->top().first+1, pq->top().second));
    pq->pop();
  }
  while(!temp.empty()){
    pq->push(temp.top());
    temp.pop();
  }
  return 1;
}

int main()
{

 priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> drivers;

  int n_pilotos = adicionar(&drivers, "drivers.txt");
  cout << "Foram adicionados " << n_pilotos << " pilotos." << endl; 

  imprimir(&drivers, 1, 10);

  cout << "Teste seleciona_por_ordem:" << endl;

  vector<int> positions{1, 7, 9, 34, 65, 120, 700, 1345, 0};

  string piloto;
  for(int i = 0; i < (int) positions.size(); i++)
  {
    piloto = seleciona_por_ordem(&drivers, positions[i]);
    if(piloto == "")
    {
      cout << "Posição " <<  positions[i] << " da lista não existe." << endl;
    }
    else
    {
      cout << "Posição " <<  positions[i] << " da lista é: " << seleciona_por_ordem(&drivers, positions[i]) << endl;
    }
  }

  cout << "Teste coloca_na_ordem:" << endl;
  
  vector<pair<int, string>> novas_colocacoes{{89, "Piloto 1"}, {93, "Piloto 2"}, {101, "Piloto 3"}, {1016, "Piloto 4"}};

  int resultado;

  for(int i = 0; i < (int) novas_colocacoes.size(); i++)
  {
    resultado = coloca_na_ordem(&drivers, novas_colocacoes[i].second, novas_colocacoes[i].first);
    if(resultado)
    {
      cout << "Colocação do piloto " << novas_colocacoes[i].second << " na posição " << novas_colocacoes[i].first << " conseguida" << endl;
      imprimir(&drivers, novas_colocacoes[i].first-5, novas_colocacoes[i].first+5);
    }
    else
    {
      cout << "Colocação do piloto " << novas_colocacoes[i].second << " na posição " << novas_colocacoes[i].first << " não conseguida" << endl;
    }

  }
  cout << "Tamanho final da lista de prioridades de pilotos: " << drivers.size() << endl;

  return 0;
}

