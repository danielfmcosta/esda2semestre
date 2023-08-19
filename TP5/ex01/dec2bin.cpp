#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

string dec2bin(int n_decimal)
{
  // alinea b)
  stack<int> c;
  string str;
  while(n_decimal>=2){
    c.push(n_decimal%2);
    n_decimal=n_decimal/2;
  }
  c.push(n_decimal);
  while (!c.empty()) {
    str += to_string(c.top());
    c.pop();
  }
  return str;
}

// Não alterar:
int main()
{
  string n_decimal;

  cout << "Introduza número decimal: ";
  getline(cin, n_decimal);

  cerr << "Representação binária: " << dec2bin(stoi(n_decimal)) << endl;

  return 0;
}
