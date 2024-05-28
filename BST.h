#pragma once
#include"Node.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<windows.h>
#include<fstream>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<cmath>
#include<windows.h>
#include<fstream>
#include<dos.h>
#include<MMSystem.h>
#include "vfw.h"
#include <cstdio>
#pragma comment(lib, "Vfw32.lib")
#include"Node.h"
using namespace std;

class BinarySt
{
private:
    Node* root;

public:
    BinarySt();
    bool isempty();
    void insert(string value, string name);
    void inorder(Node* ROOT);
    void search(string d, Node* ROOT);
    Node* getroot();
    void deleteBST(Node* ROOT);
    int calculateallnodes(Node* root);
    bool dupliate(Node* root, string value);
    Node* deleteNode(Node* root, string value);
    Node* findMinNode(Node* node1);
    void modifydata(Node* root, string value,string n);
    void boldAccountdetails();
    void choice();
    void developersdetail();
    void clearscreen();
    void pic();
};

