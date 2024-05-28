#pragma once
#include<iostream>
#include<cstring>
#include "Contacts.h"
using namespace std;

class Node {
public:
	Contacts d1;
	Node* left;
	Node* right;
	Node(Contacts s);
	Node() {};
	
};