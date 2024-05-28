#include "HeashTable.h"
#include "Node.h"

Hash::Hash() {
    capacity = 10; // Initial capacity of the hash table
    hashtable = new Contacts * [capacity];
    HashTsize = 0;

    for (int i = 0; i < capacity; i++) {
        hashtable[i] = nullptr; // Initialize the hash table with nullptr to indicate empty slots
    }
}

Hash::~Hash() {
    clearAll();
    delete[] hashtable;
}

int Hash::hashFunction1(string key) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % capacity; // First hash function using sum of ASCII values
}

int Hash::hashFunction2(string key) {
    int len = key.length();
    return capacity - (len % capacity); // Second hash function using length of the key
}

int Hash::quadraticProbe(int index, int attempt) {
    return (index + (attempt * attempt)) % capacity; // Find the next available slot using quadratic probing
}

void Hash::resize() {
    int newCapacity = primeGreaterThanOrEqual(capacity * 2); // Double the capacity and find the nearest prime number
    Contacts** newHashtable = new Contacts * [newCapacity];

    for (int i = 0; i < newCapacity; i++) {
        newHashtable[i] = nullptr; // Initialize the new hash table with nullptr to indicate empty slots
    }

    for (int i = 0; i < capacity; i++) {
        if (hashtable[i] != nullptr) {
            string& key = hashtable[i]->Name;
            int index = hashFunction1(key);
            int step = hashFunction2(key);
            int j = 0;

            while (newHashtable[(index + j * step) % newCapacity] != nullptr) {
                j++;
            }

            newHashtable[(index + j * step) % newCapacity] = hashtable[i];
        }
    }

    delete[] hashtable;
    hashtable = newHashtable;
    capacity = newCapacity;
}

bool Hash::checkDuplicate(string name) {
    int index = hashFunction1(name);
    int step = hashFunction2(name);
    int i = 0;

    while (hashtable[(index + i * step) % capacity] != NULL) {
        if (hashtable[(index + i * step) % capacity]->Name == name) {
            return true; 
        }
        i++;
    }

    return false;
}

void Hash::insert(string name,string phoneNumber) {
    if (HashTsize >= capacity / 2) {
        resize();
    }

    if (checkDuplicate(name)) {
        cout << "Contact with name " << name << " already exists. Duplicate entries are not allowed." << endl;
        return;
    }

    Contacts* Obj = new Contacts(name, phoneNumber);
    string key = Obj->Name;

    int index = hashFunction1(key);
    int step = hashFunction2(key);

    int i = 0;
    while (hashtable[(index + i * step) % capacity] != NULL) {
        int newIndex = quadraticProbe(index, i);
        i++;
    }

    hashtable[(index + i * step) % capacity] = Obj;
    HashTsize++;
}

void Hash::remove(string NameToRemove) {
    int index = hashFunction1(NameToRemove);
    int step = hashFunction2(NameToRemove);
    int i = 0;

    while (hashtable[(index + i * step) % capacity] != NULL) {
        if (hashtable[(index + i * step) % capacity]->Name == NameToRemove) {
            delete hashtable[(index + i * step) % capacity]; // Free the memory occupied by the contact object
            hashtable[(index + i * step) % capacity] = NULL; // Mark the slot as empty
            HashTsize--;
            return;
        }
        i++;
    }

    cout << "Contact with name " << NameToRemove << " not found." << endl;
}

Contacts* Hash::search(string name) {
    int index = hashFunction1(name);
    int step = hashFunction2(name);
    int i = 0;

    while (hashtable[(index + i * step) % capacity] != NULL) {
        if (hashtable[(index + i * step) % capacity]->Name == name) {
            return hashtable[(index + i * step) % capacity];
        }
        i++;
    }

    return NULL;
}

void Hash::clearAll() {
    for (int i = 0; i < capacity; i++) {
        if (hashtable[i] != NULL) {
            delete hashtable[i]; // Free the memory occupied by the contact objects
            hashtable[i] = NULL; // Mark the slots as empty
        }
    }
    HashTsize = 0;
}

void Hash::display() {
    for (int i = 0; i < capacity; i++) {
        if (hashtable[i] != NULL) {
            cout << "Index " << i << ": " << hashtable[i]->Name << ", " << hashtable[i]->PhNumber << endl;
        }
    }
}

float Hash::loadFactor() {
    return static_cast<float>(HashTsize) / capacity;
}


void Hash::readFromFile(string filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Failed to open the file: " << filename <<endl;
        return;
    }

    string name, phoneNumber;
    while (getline(inputFile, name) && getline(inputFile, phoneNumber)) {
        insert(name, phoneNumber);
    }
    cout << " " << " " << " " << "Contacts loaded from file." << endl;

    inputFile.close();
}


int Hash::primeGreaterThanOrEqual(int n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

bool Hash::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}



