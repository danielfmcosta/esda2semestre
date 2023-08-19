#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int TABLE_SIZE = 5; // fixed size of the hash table

// Hash table class using chaining
class HashTable {
private:
    vector<list<int>> table;

    // Hash function to get the index of the array where the key-value pair will be stored
    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        // Initialize the hash table with empty linked lists
        for (int i = 0; i < TABLE_SIZE; i++) {
            table.push_back(list<int>());
        }
    }

    // Insert a key-value pair into the hash table
    void insert(int key) {
        
        // alínea a)
        int index = hash(key);
        table[index].push_back(key);
    }

    // Delete a key-value pair from the hash table
    bool delete_key(int key) {
        
        //alínea b)
        int index = hash(key);
        table[index].remove(key);
        if(search(index)){
            return false;
        }
        return true;
    }

    // Search for a key in the hash table and return true if found, or false otherwise
    bool search(int key) {
        //alínea c)
        int index = hash(key);
        for(auto i : table[index]) {
            if(i == key){
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create a hash table
    HashTable ht;

    // Insert keys
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);

    cout << "Testing insert and search:" << endl;
    
    // Search for a key
    if (ht.search(1)) {
        cout << "Key 1 found!" << endl;
    } else {
        cout << "Key 1 not found!" << endl;
    }

    if (ht.search(2)) {
        cout << "Key 2 found!" << endl;
    } else {
        cout << "Key 2 not found!" << endl;
    }

    if (ht.search(3)) {
        cout << "Key 3 found!" << endl;
    } else {
        cout << "Key 3 not found!" << endl;
    }

    cout << endl << "Testing delete:" << endl;
    
    // Delete a key
    if (ht.delete_key(2)) {
        cout << "Key 2 deleted!" << endl;
    } else {
        cout << "Key 2 not found!" << endl;
    }

    // Search for a deleted key
    if (ht.search(2)) {
        cout << "Key 2 found!" << endl;
    } else {
        cout << "Key 2 not found!" << endl;
    }

    if (ht.search(1)) {
        cout << "Key 1 found!" << endl;
    } else {
        cout << "Key 1 not found!" << endl;
    }

    if (ht.search(3)) {
        cout << "Key 3 found!" << endl;
    } else {
        cout << "Key 3 not found!" << endl;
    }

    return 0;
}
