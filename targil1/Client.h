#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Volunteer.h"
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Client {
public:
	string name;
	int phone;//key
	string adrass;
public:
	vector<string> ThnNamesofthevolunteer;

	Client();//constractor
	Client(string  mytName, int  myPhone, string myDrass);
	~Client();
	string getName()const;
	int getPhone()const;
	void printList();
	bool searchNameVolunteer(string name);
	string getDrass()const;
	bool operator==(const Client& ms);
	//Client(const Client& ms);
	friend ostream& operator<<(ostream& os, Client& ms);//kelet
	friend istream& operator>>(istream& is, Client& ms);//pelet
	Client operator=(const Client& ms); //assignment operator
	Client(const Client& ms);
};

