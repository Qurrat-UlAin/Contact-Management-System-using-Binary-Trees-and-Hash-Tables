#pragma once
#include<iostream>
#include<cstring>
#include "Contacts.h"
using namespace std;

class Node {
public:
	Contacts data;
	Node* next;

	Node(Contacts c) {
		data = c;
		next = NULL;
	}
};