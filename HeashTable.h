
#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include<chrono>
#include<cmath>
#include <string>
#include "Contacts.h"
using namespace std;
class Hash {
public:
    Contacts** hashtable;
    int capacity;
    int HashTsize;

    Hash();
    ~Hash();

    int hashFunction1(string key);
    int hashFunction2(string key);
    
    int quadraticProbe(int index, int attempt);
    void resize();
    bool checkDuplicate(string name);
    void insert(string name,string phoneNumber);
    void remove(string name);
    Contacts* search(string name);
    void clearAll();
    void display();
    float loadFactor();
    int primeGreaterThanOrEqual(int n);
    bool isPrime(int n);
    void readFromFile(string filename);
    void measureTimeComplexity();
    void SortandSaveinFile();
};
