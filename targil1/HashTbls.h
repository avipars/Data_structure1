#pragma once
#include "HashTble.h"
#include "HashVolunteer.h"
#include "HashClient.h"
class HashTbls {
	HashVolunteer* vo;
	HashClient* cl;
public:
	HashTbls();
	~HashTbls();
	void addVolunteer(Volunteer c);
	void delVolunteer(Volunteer c);
	void addClient(Client c);
	void delClient(Client c);
	void print();

	void addVolunteerToClient(Volunteer& v, Client& c);
	void listOfVolunteers(Client c);
	void listOfClients(Volunteer vl);
	//HashTbls(int a) :HashTble(a) {}
	//int h1(int key) { return key % size; };
	//int h2(int key) { return (key % (size - 1) + 1 % size); };

};


