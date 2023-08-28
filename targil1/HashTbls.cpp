#include"HashTbls.h"
#include"HashClient.h"
#include"HashVolunteer.h"
#include <iostream>
#include <string>
#include <vector>
const int len = 100;
HashTbls::HashTbls() {
	vo = new HashVolunteer(100);
	cl = new HashClient(len);

}
HashTbls:: ~HashTbls() {

	delete vo;
	delete cl;
}
void HashTbls::addVolunteer(Volunteer c) {

	vo->insert(c.name, c);
}
void HashTbls::delVolunteer(Volunteer c) {
	if (vo->search(c.name) != -1)
		vo->del(c.name);
	else
		cout << "ERROR" << endl;
}
void HashTbls::addClient(Client c) {
	cl->insert(c.phone, c);
}
void HashTbls::delClient(Client c) {
	cl->del(c.phone);
}


void HashTbls::addVolunteerToClient(Volunteer& v, Client& c) {//add volunteer to client list volunteer
	bool flag = true;
	if ((vo->search(v.name) != -1) && (cl->search(c.getPhone()) != -1))
	{
		int f = vo->search(v.name);
		int i = cl->search(c.getPhone());

		if (cl->table[i].data.searchNameVolunteer(v.name) == false)
			cl->table[i].data.ThnNamesofthevolunteer.push_back(v.name);
		else
			cout << "ERROR\n";
	}

	else
		cout << "ERROR\n";
}

void HashTbls::listOfVolunteers(Client c) {//print list of name volunteer
	if (cl->search(c.getPhone()) != -1) {
		cout << "The volunteers that helped to client " << c.getPhone() << ": ";
		int i = cl->search(c.getPhone());
		cl->table[i].data.printList();
	}
	else
		cout << "The volunteers that helped to client " << c.getPhone() << ":  ";
	cout << endl;
}
void HashTbls::listOfClients(Volunteer v)//print
{

	cout << "The clients that were helped by volunteer " << v.name << ":  ";
	for (int i = 0; i < cl->getSize(); i++) {
		if (cl->table[i].data.searchNameVolunteer(v.name) == true) {
			cout << cl->table[i].data.getName() << " ";
		}
	}

	cout << endl;
}
void HashTbls::print() {
	cout << "Volunteers:" << endl;
	vo->print();
	cout << endl;
	cout << "Clients:" << endl;
	cl->print();
}