#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int bin2dec(string n_binario)
{
  // alinea a)
  stack<int> st;
  int k=0;
  int n=0;
  for (char c : n_binario) {
    int num = c - '0';
    st.push(num);
  }
  k=st.size()-1;
  while (!st.empty()){
    n = n + (st.top()*pow(2,k));
    st.pop();
    k--;
  }
  return n;
}

// Não alterar:
int main()
{
  string n_binario;

  cout << "Introduza número binário: ";
  getline(cin, n_binario);

  cerr << "Representação decimal: " << bin2dec(n_binario) << endl;

  return 0;
}
