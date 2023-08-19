#include <iostream>

using namespace std;

class Aluno
{
public: // Porque e', para ja', importante? Experimente comentar a linha...
  string nome;
  string curso;
  int numero;
  float media;
  
  Aluno(string nom)
  { /* completar (alinea a)) */
    nome = nom;
    numero=0;
    media=0;
    curso="";
  }
  
  Aluno(string nom, string cur, int num)
  { /* completar (alinea a)) */
    nome=nom;
    curso=cur;
    numero=num;
  }

  /* completar (alinea b)) */
  void setCurso(string cur){
    curso=cur;
  }
  void setNumero(int num){
    numero=num;
  }
  void setMedia(float med){
    media=med;
  }
  float getMedia(){
    return media;
  }
  /* completar (alinea c)) */
  void imprimirAluno(ostream & os) const{
      os << "Nome: " << nome << endl;
      os << "Curso: " << curso << endl;
      os << "Numero: " << numero << endl;
      os << "Media: " << media << endl;
  }

  /* completar (alinea d)) */
  string sigla() const{
    string sig;
    int flag=0;
    sig = sig + nome[0];
    for( auto c : nome){
      if(flag == 1){
        sig = sig + c;
        flag=0;
      }
      if( c == ' '){
        flag=1;
      }
    }

    return sig;
  }
};

int main()
{
  string c;
  Aluno a1("Pedro Ferreira");
  Aluno a2("Ana Martins", "Direito", 2022045);
  Aluno a3("Manuel Silva", "Arquitetura", 2021033);
  Aluno al("Alberto Mateus", "Engenharia", 2019197);

  /* completar (alinea b)) */
  a1.setCurso("ELetro");
  a1.setNumero(2022069);
  a1.setMedia(15);
  a2.setMedia(17);
  a3.setMedia(12);
  al.setMedia(20);
  a1.getMedia();
  a2.getMedia();
  a3.getMedia();

  cout << "Lista de alunos: (nome | curso | numero | media)" << endl;
  cout << "\t" << a1.nome << "\t| " << a1.curso << "\t| " << a1.numero << "\t| " << a1.media << endl;
  cout << "\t" << a2.nome << "\t| " << a2.curso << "\t| " << a2.numero << "\t| " << a2.media << endl;
  cout << "\t" << a3.nome << "\t| " << a3.curso << "\t| " << a3.numero << "\t| " << a3.media << endl;

  /* completar (alinea c)) */ 
  al.imprimirAluno(cout); 


  /* completar (alinea d) */
  cout << "A sigla do Alberto Mateus é " << al.sigla() << endl;
  return 0;
}
