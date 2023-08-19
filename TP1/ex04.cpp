#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


/**
 *  reads and prints the file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
int print_file(string f){
    ifstream file(f);
    string c;
    if(!file){
        cout<<"Error! File Does not Exist";
        return -1;
    }
    while(file.eof()==0){
        getline(file, c);
        cout << c << endl;
    }
    cout << endl;
    return 0;
}

/**
 *  counts and prints the number of chars in file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
int count_characters(string f) {
    ifstream file(f);
    char c;
    int n=0;
    if(!file){
        cout<<"Error! File Does not Exist"<<'\n';
        return -1;
    }
    while(file.eof()==0){
        file.get(c);
        n++;
    }
    cout << "The total number of characters is " << n << '\n';
    return 0;
}


/**Test code. Do not change**/

int main() {
	print_file("grocery_list.txt");
    count_characters("grocery_list.txt");
    return 0;
}