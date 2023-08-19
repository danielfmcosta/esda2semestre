#include <iostream>
#include <string>
using namespace std;

int main() {

    // Asks user for the first string s1
    // Stores the first string
    string s1, s2, s3;
    cout << "First string: " << endl;
    cin >> s1;
    // Asks user for the second string s2
    // Stores the second string
    cout << "Second string: " << endl;
    cin >> s2;
    // (a) Create new string s3 that is the concatenation of s1 and s2.
    s3 = s1 + s2;
    cout << "Concatenation: " << s3 << '\n';
    // (b) Calculate and print number of chars in s3.
    cout << "The length of the string is: " << s3.size() << endl;
    // (c) Print char 2 of s3.
    cout << "2nd char: " << s3[1] << endl;
}  
