#include"Client.h"
#include <cstring>
#include <string>
#include <vector>
using namespace std;

Client::Client() {
	name = "";
	phone = 0;
	adrass = "";

}//defult consractor
Client::Client(string  mytName, int  myPhone, string myDrass)//constractor
{

	name = mytName;
	phone = myPhone;
	adrass = myDrass;
}
Client:: ~Client()//destructor
{
	name = "";
	phone = 0;
	adrass = "";
	ThnNamesofthevolunteer.clear();
}
string Client::getName()const
{
	return name;
}
int Client::getPhone()const
{
	return phone;
}
string Client::getDrass()const
{
	return adrass;
}
bool Client:: operator==(const Client& ms) {

	if (ms.phone != phone)
		return false;
	return true;
}
ostream& operator<<(ostream& os, Client& r)//pelet
{
	os << r.phone << ":" << "client name :" << r.name;

	os << " phone: " << r.phone;

	os << " adrass: " << r.adrass;
	if (r.ThnNamesofthevolunteer.size() > 0)
		os << " helped by: "; r.printList();
	return os;

}


istream& operator>>(istream& is, Client& r)//kolet
{
	cout << "please enter name and phone and address of client " << endl;;
	is >> r.name;
	is >> r.phone;
	is >> r.adrass;
	return is;
}

Client Client:: operator=(const Client& cc) //copy constructor
{

	name = cc.name;
	phone = cc.phone;
	adrass = cc.adrass;
	ThnNamesofthevolunteer.clear();
	vector<string>::const_iterator it = cc.ThnNamesofthevolunteer.begin();
	while (it != cc.ThnNamesofthevolunteer.end()) {
		ThnNamesofthevolunteer.push_back(*it);
		it++;
	}

	return *this;
}
//ThnNamesofthevolunteer = ms.ThnNamesofthevolunt
void Client::printList() {
	vector<string>::iterator it = ThnNamesofthevolunteer.begin();
	while (it != ThnNamesofthevolunteer.end()) {
		cout << *it << " ";
		it++;

	}
	//cout << endl;
}

bool Client::searchNameVolunteer(string name) {//return true if in list of valunteer ahve tha name
	vector<string>::iterator it = ThnNamesofthevolunteer.begin();
	while (it != ThnNamesofthevolunteer.end()) {
		if (*it == name)
			return true;
		it++;

	}
	return false;
}

Client::Client(const Client& ms)
{

	name = ms.name;
	phone = ms.phone;
	adrass = ms.adrass;
	ThnNamesofthevolunteer.clear();
	vector<string>::const_iterator it = ms.ThnNamesofthevolunteer.begin();
	while (it != ms.ThnNamesofthevolunteer.end()) {
		ThnNamesofthevolunteer.push_back(*it);
		it++;
	}

}