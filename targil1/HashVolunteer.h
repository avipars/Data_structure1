#pragma once
#include <iostream>
#include "HashTble.h"
#include "Volunteer.h"
using namespace std;
class HashVolunteer :public HashTble< Volunteer, string>
{
public:
	HashVolunteer(int size) :HashTble(size) {
	}
	int toInt(string slt) { return (int)slt[0] + (int)slt[1] + (int)slt[slt.length() - 1]; }//string to string
	//int h1(string key) {
	//	int newKey = 0;
	//	int x = 0;
	//	char c;
	//	
	//	while (key.empty() != true)
	//	{

	//		c = key[x];
	//		newKey += (int)c;
	//		x++;
	//	}
	//	return newKey % size;//îä àîåøéí ìùðåú ôä ëàéìå îä äî÷èøéú òùúä?
	//}


	//int h2(string key)
	//{
	//	int newKey = 0;
	//	int x = 0;
	//	char c;
	//	while (key.empty() != true)
	//	{
	//		c = key[x];
	//		newKey += (int)c;
	//		x++;
	//	}
	//	cout << "Ff";
	//	return newKey % (size - 1) + 1;
	//}
	int h1(string key) {
		return toInt(key) % size;
	}
	int h2(string key) {
		return (toInt(key) % (size - 1) + 1 % size);
	}

};

//HashVolunteer:HashTbls< Volunteer, string>::HashVolunteer:HashTbls< Volunteer, string>()
//{
//}
//
//HashVolunteer:HashTbls< Volunteer, string>::~HashVolunteer:HashTbls< Volunteer, string>()
//{
//}
