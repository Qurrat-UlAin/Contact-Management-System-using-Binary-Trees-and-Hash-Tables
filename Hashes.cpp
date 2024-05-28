#include "HeashTable.h"
#include<chrono>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std; 
// HashTable constructor

HashTable::HashTable(int size) {
    tableSize = size;
    hashTable = new Node * [tableSize];
    for (int i = 0; i < tableSize; ++i) {
        hashTable[i] = nullptr;
    }
}

// HashTable destructor
HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] hashTable;
}

// HashTable function
int HashTable::HashTableFunction(const string& key) {
    // Simple HashTable function example (can be improved based on specific requirements)
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % tableSize;
}
// Insert a node into the linked list at the specified head
void HashTable::insertIntoList(Node* newNode, Node*& head) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Remove a node from the linked list
void HashTable::removeFromList(Node* node, int index) {
    if (node == nullptr) {
        return;
    }

    Node* current = hashTable[index];
    Node* prev = nullptr;

    while (current) {
        if (current == node) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                hashTable[index] = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}



// Insert all contacts from a text file into the HashTable table using chaining
void HashTable::insertFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    string name;
    string phoneNumber;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;  // Skip empty lines
        }
        if (name.empty()) {
            name = line;
        }
        else {
            phoneNumber = line;
            Node* newNode = new Node(Contacts(name, phoneNumber));
            int index = HashTableFunction(name);
            insertIntoList(newNode, hashTable[index]);
            name.clear();
            phoneNumber.clear();
        }
    }

    file.close();
}

// Insert a contact into the HashTable table using chaining
void HashTable::insert(const string& name, const string& phoneNumber) {
    int index = HashTableFunction(name);
    Node* newNode = new Node(Contacts(name, phoneNumber));
    insertIntoList(newNode, hashTable[index]);
}

// Delete a contact from the HashTable table
void HashTable::remove(const string& name) {
    int index = HashTableFunction(name);
    Node* current = hashTable[index];

    while (current) {
        if (current->data.Name == name) {
            removeFromList(current, index);
            return;
        }
        current = current->next;
    }
    cout << "Contact not found." << endl;
}

// Search for and display a contact from the HashTable table
void HashTable::searchAndDisplay(const string& name) {
    int index = HashTableFunction(name);
    Node* current = hashTable[index];

    while (current) {
        if (current->data.Name == name) {
            cout << "Contact found: " << current->data.Name << " " << current->data.PhNumber << endl;
            return;
        }
        current = current->next;
    }
    cout << "Contact not found." << endl;
}
void HashTable::displayAll() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        while (current) {
            cout << "Name: " << current->data.Name << "\tPhone Number: " << current->data.PhNumber << endl;
            current = current->next;
        }
    }
}

// Sort the contacts and write them into a new text file while preserving the same order
void HashTable::sortAndWriteToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    vector<Contacts> contacts;
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        while (current) {
            contacts.push_back(current->data);
            current = current->next;
        }
    }

    std::sort(contacts.begin(), contacts.end(), [](const Contacts& c1, const Contacts& c2) {
        return c1.Name < c2.Name;
        });

    for (const Contacts& contact : contacts) {
        file << contact.Name << "\n" << contact.PhNumber << "\n";
    }

    file.close();
}

// Measure the time complexity of each function using the <chrono> library
void HashTable::measureTimeComplexity() {
    auto start = chrono::high_resolution_clock::now();
    // Perform the function for which time complexity is to be measured
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}