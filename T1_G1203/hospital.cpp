#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <sstream>
#include <list>
#include <chrono>
#include <iomanip>
#include <queue>
#include "hospital.hpp"

using namespace std;

Patient::Patient(string personId, string name)
{
  this -> personId = personId;
  this -> name = name;
  this -> patientId = "";
  this -> birthDate = 0;
  this -> sex = '\0';
  this -> discharged = false;
  this -> vemergency = {};
  this -> ventrance = {};
}

Patient::Patient(string personId, string name, string patientId, time_t birthDate, char sex, short int emergency, time_t ymd)
{
  this -> personId = personId;
  this -> name = name;
  this -> patientId = patientId;
  this -> birthDate = birthDate;
  this -> sex = sex;
  this -> discharged = false;
  this -> vemergency.push_back(emergency);
  this -> ventrance.push_back(ymd);
}

string Patient::getPersonId() const
{
  return (this -> personId);
}

string Patient::getName() const
{
  return (this -> name);
}

string Patient::getPatientId() const
{
  return (this -> patientId);
}

time_t Patient::getBirthDate() const
{
  return (this -> birthDate);
}

char Patient::getSex() const
{
  return (this -> sex);
}

bool Patient::getDischarged() const
{
  return (this -> discharged);
}

vector<short int> Patient::getVemergency() const
{
  return (this -> vemergency);
}

vector<time_t> Patient::getVentrance() const
{
  return (this -> ventrance);
}

void Patient::setName(string name)
{
  if(name != ""){
    this -> name = name;
  }
}

void Patient::setPatientId(string patientId)
{
  if(patientId != ""){
    this -> patientId = patientId;
  }
}

void Patient::setBirthDate(time_t birthDate)
{
  if(birthDate != 0){
    this -> birthDate = birthDate;
  }
}

void Patient::setSex(char sex)
{
  if(sex != '\0'){
    this -> sex = sex;
  }
}

void Patient::setDischarged(bool discharged)
{
  this -> discharged = discharged;
}

void Patient::addVentrance(time_t ymd)
{
  this -> ventrance.push_back(ymd);
}

void Patient::addVemergency(short int emergency)
{
  this -> vemergency.push_back(emergency);
}

PatientManagement::PatientManagement()
{
  if(this -> listPatient.empty() == false){
    this -> listPatient.clear(); //garante que a lista esta vazia
  }
}

PatientManagement::~PatientManagement()
{
  Patient *v;
  while(this -> listPatient.empty() == false){ //while loop que roda enquanto a lista não está vazia
    v = this -> listPatient.front();
    this -> listPatient.pop_front(); //eliminar o patient da lista
    delete v; //"destroi" o patient
  }
}

list<Patient *> PatientManagement::getListPatient() const
{
  return(this -> listPatient);
}

size_t PatientManagement::getSize() const
{
  return(this -> listPatient.size());
}

int PatientManagement::getSizeDay(time_t ymd) const
{
  list<Patient*>::const_iterator it;
  int k=0;
  for(it = this -> listPatient.begin(); it!= this -> listPatient.end(); it++){ //for loop que percorre a lista
      for(unsigned int i=0; i < (*it)->getVentrance().size();i++){ //for loop que percorre todas as entradas
        if((*it)->getVentrance()[i] == ymd){ //se a entrada é igual á entrada dada  
          k++;
        }
      }
    }
    return k;
}

int PatientManagement::patientInsert(Patient *p)
{
  if(p==NULL){ 
    return -1;
  }
  list<Patient*>::const_iterator it;
  for(it = this -> listPatient.begin(); it != this -> listPatient.end(); it++){ //for loop que percorre a lista
    if(p->getPersonId()==(*it)->getPersonId()){ //se o patient já existe
      (*it)->addVentrance(p->getVentrance().back()); //adicionar uma nova entrada
      (*it)->addVemergency(p->getVemergency().back()); //adicionar a nova emergencia
      return 1;
    }
  }
  listPatient.push_back(p); //adicionar o novo patient
  return 0;
}

Patient *PatientManagement::patientRemove(const string id)
{
  list<Patient*>::const_iterator it;
  for(it = this -> listPatient.begin(); it != this -> listPatient.end(); it++){ //for loop que percorre a lista
    if((*it)->getPersonId()==id){ //encontrar o patient pedido
      listPatient.remove(*it); //remover o patient
      return *it;
    }
  }
  return NULL; 
}

int PatientManagement::import(const string name_file)
{
  if (name_file.empty())
    return -1;
  
  ifstream f(name_file);
  if (!f)
    return -1;

  string PersonId, name, PatientId;
  int emergency;
  char sex;
  time_t ymd, birth;
  Patient *p;
  int result;
  string s;
  stringstream ss, ssd;
  char delim = ',';
  tm *timeptr = new tm{};
  string date_time_format = "%m/%d/%Y";

  while (getline(f, s)) {
    ss.clear();
    ss << s;
    getline(ss, PersonId, delim);
    getline(ss, name, delim);
    getline(ss, s, delim);
    sex = s[0];
    
    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    birth = mktime(timeptr);

    getline(ss, PatientId, delim);
    
    getline(ss, s, delim);
    emergency = stoi(s);

    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    ymd = mktime(timeptr);

    p = new Patient(PersonId, name, PatientId, birth, sex, emergency, ymd);

    if (!p) {
      delete p;
      f.close();
      return -1;
    }

    result = patientInsert(p);
    if (result == -1) {
      delete p;
      f.close();
      return -1;
    }
  }

  f.close();
  delete timeptr;
  return 0;
}
list<Patient*> *PatientManagement::searchEmergency(short int emergency)
{
  list<Patient*>::const_iterator it;
  list<Patient*> *listDoentes = new list<Patient*>;
  if(emergency<0 || emergency>4){
    return NULL;
  }
  for(it = this -> listPatient.begin(); it != this -> listPatient.end(); it++){ //for loop que percorre a lista
    if((*it)->getVemergency().back()==emergency && (*it)->getDischarged()==false){ //encontra o patient na lista com tipo de emergência correspondente a emergency que não tenham tido alta.
      (*listDoentes).push_back(*it); //colocar o patient na nova lista 
    }
  }
  if((*listDoentes).empty()){
    return NULL;
  }
  else{
    return listDoentes;
  }
}

EmergencyQueues::EmergencyQueues()
{ 
  for (int i = 0; i < 5; i++){
    queue<Patient*> Pat; //cria uma queue vazia
    vqueueEmergency.push_back(Pat); //coloca a queue no vector
  }
}

vector<queue<Patient *> > EmergencyQueues::getEmergencyQueues() const
{
  return(this -> vqueueEmergency);
}

size_t EmergencyQueues::getSize(short int emergency) const
{
  if(emergency<0 || emergency>4){
    return 0;
  } 
  return (this -> vqueueEmergency[emergency].size()); //retorna o tamanho da queue
}

int EmergencyQueues::patientInsert(Patient *p)
{
  if(p==NULL){
    return -1;
  }
  int emergency = p->getVemergency().back();
  if(emergency<0 || emergency>5){
    return -1;
  }
  this -> vqueueEmergency[emergency].push(p); //colocar o patient na queue
  return 0;
}

Patient *EmergencyQueues::patientRemove(short int emergency)
{

  if(emergency<0 || emergency>4){
    return NULL;
  }
  if(this -> vqueueEmergency[emergency].empty()){
    return NULL;
  }
  Patient* Pat = this -> vqueueEmergency[emergency].front(); //ir buscar o primeiro patient da queue
  this -> vqueueEmergency[emergency].pop(); //retirar o patient da queue
  Pat->setDischarged(true); //dar alta ao patient
  return Pat;
}

int EmergencyQueues::getPatientsFromList(list<Patient *> listPatient)
{
  list<Patient*>::const_iterator it; 
  for(it = listPatient.begin(); it != listPatient.end(); it++){ //for loop que passa pela lista toda
    if((*it)->getDischarged()==false){ //verificar se o patient não tem alta
      int emergency = (*it)->getVemergency().back();
      if(emergency>=0 && emergency<=4){ //verificar se a ultima emergencia do patient é válida
        vqueueEmergency[emergency].push((*it)); //inserir o patient na queue
      }
      else{
        return -1;
      }
    }
  }
  return 0;
}

int EmergencyQueues::importDischarged(const string name_file)
{
  ifstream file(name_file);
  string c;
  Patient* Pat;
  int num_vec, num_pat;
  if(!file){ //caso não abra o ficheiro, retorna -1
    return -1;
  }
  while(file.eof()==0){
    getline(file, c); //lê cada fila
    sscanf(c.c_str(), "%d,%d", &num_vec, &num_pat); //lê a fila e passa os valores para as variaveis
    for(int i=0; i<num_pat; i++){ //for loop que vai retirar o número de patients pedido 
      Pat = vqueueEmergency[num_vec].front(); 
      vqueueEmergency[num_vec].pop(); //retira o patient da queue
      Pat->setDischarged(true); //dar alta ao patient
    }
  }
  return 0;
}

int EmergencyQueues::changeQueue(const string id, short int new_E)
{
  Patient* Pat;
  queue<Patient*> qPat;
  if(new_E<0 || new_E>4){
    return -1;
  }
  for(int i=0; i<5; i++){ //for loop para ir a cada 5 queues
    qPat = vqueueEmergency[i];
    for(int k=0; k< (int)vqueueEmergency[i].size(); k++){ // ir a cada patient na queue
      Pat=qPat.front();
      if(Pat->getPersonId()==id){ //encontrar o patient 
        Pat->addVemergency(new_E); //mudar o tipo de emergência do patient
        vqueueEmergency[new_E].push(Pat); // passar o patient para a nova queue
        return 0;
      }
      qPat.pop(); //retirar o primeiro patient da queue para passar ao próximo
    }
  }
  return -1;
}