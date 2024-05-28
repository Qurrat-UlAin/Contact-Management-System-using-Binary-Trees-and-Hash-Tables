#include"HeashTable.h"
#include<chrono>
#include<cmath>
#include<cstdlib>
#include"BST.h"
using namespace std;

void displayMenuHash()
{
    system("cls"); // Clear the screen
    cout <<" " << " " << "****************** CONTACT MANAGEMENT SYSTEM WIT HASH TABLES ******************" << endl;
    cout << " " << " " << "1. Read Contacts from File" << endl;
    cout << " " << " " << "2. Add Contact" << " " << endl;
    cout << " " << " " << "3. Remove Contact" <<  endl;
    cout << " " << " " << "4. Search Contact" << " " << endl;
    cout << " " << " " << "5. Display All Contacts" <<  endl;
    cout << " " << " " << "6. Exit" << " " << "  " << endl;
    cout << " " << " " << "*************************************************************" << endl;
    cout << " " << " " << "Enter your choice: ";
}
void loading(int milliseconds)
{
    cout << "Loading";
    for (int i = 0; i < 2; i++)
    {
        Sleep(milliseconds);
        cout << ".";
    }
    cout << endl;
    Sleep(milliseconds);
}
int main()
{
    system("color 70");
    cout << " " << " " << " " << "****************** WELCOME TO CONTACT MANAGEMENT SYSTEM ******************" << endl;
    int a;
    cout << "Would you like to proceed with Hash tables or Binary trees?" << endl;
    cout << "Press 1 for Binary Trees" << endl;
    cout << "Press 2 for Hash Tbles" << endl;
    while (true) {
        cin >> a;
        if (a == 1 || a == 2) {
            break;
        }
        else {
            cout << "Please enter a valid number (1 or 2): ";
        }
    }
    if (a == 2) {
        Hash hashTable;
        string filename;
        char choice;

        system("color 70");
        bool exitProgram = false;

        while (!exitProgram)
        {
            displayMenuHash();

            int option;
            cin >> option;

            switch (option)
            {
            case 1:
            {
                cout << "Enter the filename to read contacts from: ";
                cin >> filename;

                loading(200);
                auto start = chrono::high_resolution_clock::now();
                hashTable.readFromFile(filename);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;


                cout << "Contacts loaded from file succesfully." << endl;

                break;
            }
            case 2:
            {
                string name, phoneNumber;
                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter the phone number: ";
                getline(cin, phoneNumber);
                auto start = chrono::high_resolution_clock::now();
                hashTable.insert(name, phoneNumber);

                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

                cout << "Contact added." << endl;
                break;
            }
            case 3:
            {
                string name;
                cout << "Enter the name to remove: ";
                cin.ignore();
                getline(cin, name);
                auto start = chrono::high_resolution_clock::now();
                hashTable.remove(name);

                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;


                break;
            }
            case 4:
            {
                string name;
                cout << "Enter the name to search: ";
                cin.ignore();
                getline(cin, name);
                auto start = chrono::high_resolution_clock::now();
                Contacts* contact = hashTable.search(name);

                if (contact != nullptr)
                {
                    cout << "Contact found: " << contact->Name << ", " << contact->PhNumber << endl;
                }
                else
                {
                    cout << "Contact not found." << endl;
                }
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;


                break;
            }
            case 5:
            {
                cout << "Contacts in the Hash Table:" << endl;
                auto start = chrono::high_resolution_clock::now();

                hashTable.display();
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

                break;
            }
            case 6:
            {
                system("color 07"); // Change console color back to default
                auto start = chrono::high_resolution_clock::now();
                cout << "The load factor of the hash table is: " << hashTable.loadFactor() << endl;
                cout << "Exiting the program...";
                hashTable.clearAll();
                exitProgram = true;
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

                break;
            }
            default:
            {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
            }

            if (!exitProgram)
            {
                char continueChoice;
                cout << "Do you want to continue? (Y/N): ";
                cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y')
                    exitProgram = true;
            }
        }
    }
    else if (a == 1) {
        system("color 70");
        BinarySt Object;
        int option, totalcontacts;
        bool duplicatetest;
        string name, phone, name2, n;
        char a, b;
        Object.boldAccountdetails();
        cout << " \t\t\t\t\t WEILCOME TO OUR CONTACT BOOK LIST WITH BINARY SEARCH TREES" << endl << endl << endl << endl;
         system("pause");
         Object.clearscreen();
        do {
        Object.choice();
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
        {
            do
            {
                cout << "ENTER  NAME OF CONTACT  " << endl;
                cin >> name;
                cout << "ENTER PHONR NUMBER OF CONTACT" << endl;
                cin >> phone;
                auto start = chrono::high_resolution_clock::now();
                Object.insert(phone, name);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;
                cout << endl << endl;
                cout << "IF YOU WANT TO ENTER ANOTHER CONTACT PRESS Y" << endl;
                cin >> a;
                system("cls");
            } while (a == 'y');
            system("pause");
            break;
        }
        case 2:
        {
            auto start = chrono::high_resolution_clock::now();
            Object.inorder(Object.getroot());
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            cout << endl;


            system("pause");
            system("cls");
            break;
        }
        case 3: {
            cout << "ENTER PHONE NUMBER YOU WANT TO SEARCH" << endl;
            cin >> phone;

            auto start = chrono::high_resolution_clock::now();
            Object.search(phone, Object.getroot());
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            system("pause");
            system("cls");

            break;
        }
        case 4:
        {
            auto start = chrono::high_resolution_clock::now();
            totalcontacts = Object.calculateallnodes(Object.getroot());
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            cout << "TOTAL NUMBER OF CONTACTS ARE " << totalcontacts << endl;

            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            cout << "ENTER NUMBER TO SEE IT HAS DUPLICATE OR NOT" << endl;

            cin >> phone;
            auto start = chrono::high_resolution_clock::now();

            duplicatetest = Object.dupliate(Object.getroot(), phone);
            Object.clearscreen();

            if (duplicatetest == true)

            {
                cout << "YOUR DATA IS ALL READY PRESENT SO CANT ENTER DUPLICATE DATA" << endl;
            }
            else
            {
                cout << "DATA U ENTER IS NOT PRESENT IN FILE " << endl;
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;


            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            cout << "DELETING ALL DATA " << endl;

            Object.clearscreen();
            auto start = chrono::high_resolution_clock::now();

            Object.deleteBST(Object.getroot());
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            Object.clearscreen();
            cout << "ALL DATA IS DELETED" << endl;
            exit(0);
        }

        case 7:
        {
            Object.developersdetail();
            exit(0);
        }
        case 8:
        {auto start = chrono::high_resolution_clock::now();
        Object.pic();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

        Object.clearscreen();
        cout << "\t\t PIC HAS BEES TAKEN" << endl;
        system("pause");
        system("cls");
        break;
        }
        case 9:
        {

            cout << "ENTER NUM OF CONTACT YOU WANT TO DELETE" << endl;
            cin >> n;
            auto start = chrono::high_resolution_clock::now();
            Object.deleteNode(Object.getroot(), n);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            system("pause");
            Object.clearscreen();
            break;
        }
        case 10:
        {
            cout << "ENTER PHONE NUM YOU WANT TO REPLACE" << endl;
            cin >> phone;
            Object.clearscreen();
            cout << "ENTER NAME YOU WANT TO ENTER INSTEAD OF PREVIOUS NAME" << endl;
            cin >> name;
            auto start = chrono::high_resolution_clock::now();
            Object.modifydata(Object.getroot(), phone, name);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Time complexity of Function: " << duration.count() << " microseconds" << endl;

            Object.clearscreen();

            cout << "\n\n CONTACT IS UPDATED" << endl;
            system("pause");
            system("cls");
            break;
        }
        default:
            cout << "YOU ENTER WRONG NUM ENTER NUM BETWEEN 1-8" << endl;
        }

        cout << "ENTER  Y TO GO BACK TO INTERFACE" << endl;
        cin >> b;

        system("cls");
    } while (b == 'y');


    }

    return 0;
}
