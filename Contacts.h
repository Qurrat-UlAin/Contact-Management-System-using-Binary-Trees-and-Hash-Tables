#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Contacts {
public:
	string Name;
	string PhNumber;

	Contacts(){}
	Contacts(string n, string p){
		Name = n; PhNumber = p;
	}
};