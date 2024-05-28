#include <iostream>
#include <windows.h>  // For colors and console manipulation
#include <chrono>
#include "HeashTable.h"

// Function to set console text color
void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to display loading animation
void ShowLoadingScreen(int duration) {
    cout << "Loading ";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        Sleep(duration);
    }
    cout << endl;
}

int main() {
    SetColor(11);  // Set console text color to light cyan

    cout << "Welcome to the Contact Manager!" << endl;
    Sleep(3000);  // Display welcome message for 3 seconds
    system("cls");  // Clear console screen

    HashTable contactManager(100);  // Create a hash table with a size of 100

    contactManager.insertFromFile("contacts.txt");  // Insert contacts from file into the hash table
    int choice;

    do {
        SetColor(15);  // Set console text color to white

        cout << "Enter a number to perform an action:" << endl;
        cout << "6. Display all contacts" << endl;
        cout << "5. Sort contacts and write to file" << endl;
        cout << "4. Delete a contact" << endl;
        cout << "3. Search for a contact" << endl;
        cout << "2. Add a contact" << endl;
        cout << "1.Read from a text file " << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        SetColor(11);  // Set console text color to light cyan

        switch (choice) {
        case 1:
            ShowLoadingScreen(500);
            contactManager.displayAll();
            contactManager.measureTimeComplexity();
            break;
        case 2:
            ShowLoadingScreen(500);
            contactManager.sortAndWriteToFile("sorted_contacts.txt");
            cout << "Contacts sorted and written to file." << endl;
            contactManager.measureTimeComplexity();
            break;
        case 3: {
            string name;
            cout << "Enter the name of the contact to delete: ";
            cin.ignore();
            getline(cin, name);
            ShowLoadingScreen(500);
            contactManager.remove(name);
            contactManager.measureTimeComplexity();
            break;
        }
        case 4: {
            string name;
            cout << "Enter the name of the contact to search: ";
            cin.ignore();
            getline(cin, name);
            ShowLoadingScreen(500);
            contactManager.searchAndDisplay(name);
            contactManager.measureTimeComplexity();
            break;
        }
        case 5: {
            string name, phoneNumber;
            cout << "Enter the name of the contact: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the phone number of the contact: ";
            getline(cin, phoneNumber);
            ShowLoadingScreen(500);
            contactManager.insert(name, phoneNumber);
            cout << "Contact added successfully." << endl;
            break;
        
        }
        case 6: {
            string filename;
            cout << "Enter the name of the file to read contacts from: ";
            cin.ignore();
            getline(cin, filename);

            ifstream inputFile(filename);
            if (!inputFile) {
                cout << "Error opening file. Please check the filename and try again." << endl;
            }
            else {
                string name, phoneNumber;
                int count = 0;
                while (inputFile >> name >> phoneNumber) {
                    contactManager.insert(name, phoneNumber);
                    count++;
                }
                inputFile.close();

                cout << count << " contacts read from file." << endl;
            }
            break;
        }
        case 7: {
                cout << "Exiting the program." << endl;
                break;}
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
