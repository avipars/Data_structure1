#include "Volunteer.h"
#include <string>
#include <cstring>
using namespace std;
Volunteer::Volunteer()
{
	name = "";
	phone = 0;
	city = "";
}

Volunteer::~Volunteer()
{
	name = "";
	phone = 0;
	city = "";

}
Volunteer::Volunteer(string name2, int phone2, string city2)
{
	name = name2;
	phone = phone2;
	city = city2;
}

bool Volunteer::operator==(const Volunteer& v)//äùàìä àí îñôé÷ ø÷ ìäùååú àú äùí
{
	if (name == v.name)
	{
		return true;
	}
	return false;

}
Volunteer Volunteer::operator=(const Volunteer& v)
{
	name = v.name;
	phone = v.phone;
	city = v.city;
	return*this;
}
istream& operator>>(istream& is, Volunteer& v)
{
	cout << "Enter volunteer name phone address " << endl;
	is >> v.name;
	is >> v.phone;
	is >> v.city;
	return is;
}
ostream& operator<<(ostream& os, Volunteer& v)
{

	os << v.name << ":" << "volunteer name=" << v.name << " ";

	os << " phone=" << v.phone;

	os << " address=" << v.city;

	return os;
}