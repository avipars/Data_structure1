#pragma once
#include "HashTble.h"
#include <iostream>
#include "Client.h"
using namespace std;

class HashClient :public HashTble<Client, int>
{
public:
	HashClient(int size) : HashTble(size) {
	}

	int h1(int key) {
		return (key) % size;
	}

	int h2(int key) {
		return (key % (size - 1) + 1) % size;
	}
};
