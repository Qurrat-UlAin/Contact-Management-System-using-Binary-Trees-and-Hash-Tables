#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "Contacts.h"

class HashTable {
private:
    Node** hashTable;
    int tableSize;

    // Private utility functions
    int HashTableFunction(const std::string& key);
    void insertIntoList(Node* newNode, Node*& head);
    void removeFromList(Node* node, int index);


public:
    // Constructor
    HashTable(int size);
    // Destructor
    ~HashTable();

    // Public member functions
    void insertFromFile(const std::string& filename);
    void insert(const std::string& name, const std::string& phoneNumber);
    void remove(const std::string& name);
    Node* search(const std::string& name);
    void searchAndDisplay(const std::string& name);
    void displayAll();
    void sortAndWriteToFile(const std::string& filename);
    void measureTimeComplexity();
};
