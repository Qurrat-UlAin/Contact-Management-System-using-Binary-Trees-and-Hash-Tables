#include"BST.h"

BinarySt::BinarySt() {
    root = nullptr;
}

bool BinarySt::isempty() {
    return (root == nullptr);
}

void BinarySt::insert(string value, std::string name) {
    Node* newNode = new Node;
    newNode->d1.PhNumber = value;
    newNode->d1.Name = name;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (isempty()) {
        root = newNode;
    }
    else {
        Node* temp = root;
        while (true) {
            if (value < (temp->d1.PhNumber)) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if (value > temp->d1.PhNumber) {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                std::cout << "Duplicate value. Ignoring insertion." << std::endl;
                break;
            }
        }
    }
}

void BinarySt::inorder(Node* ROOT) {
    if (ROOT != nullptr) {
        inorder(ROOT->left);
        std::cout << "Phone Number: " << ROOT->d1.PhNumber << ", Name: " << ROOT->d1.Name << std::endl;
        inorder(ROOT->right);
    }
}

void BinarySt::search(string d, Node* ROOT) {
    if (ROOT == nullptr) {
        std::cout << "Contact not found." << std::endl;
        return;
    }
    if (d == ROOT->d1.PhNumber) {
        std::cout << "Phone Number: " << ROOT->d1.PhNumber << ", Name: " << ROOT->d1.Name << std::endl;
    }
    else if (d < ROOT->d1.PhNumber) {
        search(d, ROOT->left);
    }
    else {
        search(d, ROOT->right);
    }
}

Node* BinarySt::getroot() {
    return root;
}

void BinarySt::deleteBST(Node* ROOT) {
    if (ROOT != nullptr) {
        deleteBST(ROOT->left);
        deleteBST(ROOT->right);
        delete ROOT;
    }
    root = nullptr;
}

int BinarySt::calculateallnodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return calculateallnodes(root->left) + calculateallnodes(root->right) + 1;
}

bool BinarySt::dupliate(Node* root, string value) {
    if (root == nullptr) {
        return false;
    }
    if (root->d1.PhNumber == value) {
        return true;
    }
    return (dupliate(root->left, value) || dupliate(root->right, value));
}

Node* BinarySt::deleteNode(Node* root, string value) {
    if (root == nullptr) {
        return root;
    }
    else if (value < root->d1.PhNumber) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->d1.PhNumber) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = findMinNode(root->right);
            root->d1 = temp->d1;
            root->right = deleteNode(root->right, temp->d1.PhNumber);
        }
    }
    return root;
}

Node* BinarySt::findMinNode(Node* node1) {
    Node* current = node1;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BinarySt::modifydata(Node* root, string value, string n) {
    if (root == nullptr) {
        std::cout << "Contact not found." << std::endl;
        return;
    }
    if (value == root->d1.PhNumber) {
        root->d1.Name = n;
        std::cout << "Contact modified successfully." << std::endl;
    }
    else if (value < root->d1.PhNumber) {
        modifydata(root->left, value, n);
    }
    else {
        modifydata(root->right, value, n);
    }
}

void BinarySt::boldAccountdetails() {
    static CONSOLE_FONT_INFOEX fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 220;
    fontex.dwFontSize.X = 25;
    fontex.dwFontSize.Y = 25;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}

void BinarySt::choice() {
    std::cout << "                       \n\t\tMAIN MENU" << std::endl;
    std::cout << "\n\t\t ENTER 1 TO INSERT CONTACT " << std::endl;
    std::cout << "\n\t\t ENTER 2 TO PRINT CONTACTS" << std::endl;
    std::cout << "\n\t\t ENTER 3 TO SEARCH CONTACT " << std::endl;
    std::cout << "\n\t\t ENTER 4 TO CALCULATE TOTAL CONTACTS " << std::endl;
    std::cout << "\n\t\t ENTER 5 FOR SEEING DUPLICATE " << std::endl;
    std::cout << "\n\t\t ENTER 6 TO RESET YOUR CONTACT BOOK " << std::endl;
    std::cout << "\n\t\t ENTER 7 TO EXIT CONTACT BOOK " << std::endl;
    std::cout << "\n\t\t ENETR 8 TO LET US TAKE YOUR PICTURE" << std::endl;
    std::cout << "\n\t\t ENTER 9 TO DELETE ANY CONTACT " << std::endl;
    std::cout << "\n\t\t ENTER 10 TO UPDATE ANY CONTACT " << std::endl << std::endl;
}

void BinarySt::developersdetail() {
    std::cout << "\t\t\t DEVELOPERS" << std::endl;
    std::cout << "\t\t 1) QURRAT UL AIN " << std::endl;
    std::cout << "\t\t 2) ABDUL MOIZ KHALID" << std::endl;
}

void BinarySt::clearscreen() {
    system("cls");
    std::cout << "JUST WAIT A SECOND......" << std::endl;
    Sleep(3000);
    system("cls");
}

void BinarySt::pic() {
    HWND hCam = capCreateCaptureWindow(
        L"hoven",
        WS_CHILD,
        0, 0, 0, 0,
        ::GetDesktopWindow(), 0);

    if (capDriverConnect(hCam, 0)) {
        capFileSaveDIB(hCam, L"shot.bmp");
        std::cout << ("PIC HAS BEEN TAKEN ") << std::endl << std::endl;
    }
    else {
        std::cout << ("Check camera?") << std::endl;
    }

    DestroyWindow(hCam);
}
