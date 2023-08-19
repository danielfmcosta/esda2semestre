#include <iostream>
#include "MediaMovel.h"
using namespace std;

MediaMovel::MediaMovel(double n_elem) : n_elementos(n_elem) {}

// Alínea a)
void MediaMovel::update(double valor)
{
  if(valores.empty()){
    n_elementos = 0;
  }
  valores.push_back(valor);
  n_elementos++;
  return;
}

// Alínea b)
double MediaMovel::getMediaMovel() const
{
  float sum=0;
  for(auto i : valores){
    sum += i;
  }
  return sum/n_elementos;
}
