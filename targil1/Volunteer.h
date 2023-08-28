#pragma once
#include<iostream>
#include<string>
#include <cstring>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Volunteer
{
public:
	string name;
	int phone;
	string city;

	Volunteer(string name2, int phone2, string city2);
	Volunteer();
	~Volunteer();
	bool operator==(const Volunteer& v);
	Volunteer operator=(const Volunteer& v);
	friend istream& operator>>(istream& is, Volunteer& v);//why 
	friend ostream& operator<<(ostream& os, Volunteer& v);



};