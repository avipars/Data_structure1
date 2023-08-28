#pragma once
#include <string>
#include <iostream>


#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

template <class T, class K>
class HashTble {
public:
	int size;
	enum state { empty, full, deleted };
	class Item
	{
	public:
		T data;
		K key;
		state flag;
		Item() {}

		Item(T d, K k, state f) { data = d; key = k; flag = f; }
		//print() { cout << data; }
	};

public:

	Item* table;
	HashTble(int s);//v ctor
	HashTble() { table = new Item[0]; };
	~HashTble() { delete[] table; size = 0; };//v
	int hash(K key, int i);//return index in hash in nisom i

	int search(K key);//search v
	//T searchItem(K key);//search v
	void insert(K& key, T& table);//insert
	void del(K key);//delete v
	void print();//print

	virtual int h1(K key) = 0;//âéáåá
	virtual int h2(K key) = 0;//ãéìåâ

	bool prime(int sizz) {//chack if mispar rishoni
		for (int i = 2; i < sizz - 1; i++) {
			if (sizz % i == 0)
				return true;
		}
		return false;
	}

	T getData() { return table->data; }
	Item* getTable() { return table; }
	int getSize() { return size; }
	friend class HashTbls;

};


#include "HashTble.h"
template <class T, class K>
HashTble<T, K>::HashTble(int sizz) {

	while (prime(sizz) == true)//mispar rishoni
	{
		sizz++;
	}
	size = sizz;
	table = new Item[size];

}

template <class T, class K>
int HashTble<T, K>::hash(K key, int i) {
	return((h1(key) + i * h2(key)) % size);
}

template <class T, class K>
void HashTble<T, K>::insert(K& key, T& tt) {
	for (int i = 0; i < size; i++) {
		int j = hash(key, i);
		if (table[j].flag != (state)full) {
			table[j].key = key;
			table[j].data = tt;
			table[j].flag = full;
			return;
		}

	}
}

template <class T, class K>
int HashTble<T, K>::search(K key) {
	for (int i = 0; i < size; i++) {
		int index = (h1(key) + i * h2(key)) % size;
		if (table[index].flag == 0)//not have it
			return -1;
		if ((table[index].key == key) & (table[index].flag == 1))//is found
			return index;
	}
	return -1;
}
//template <class T, class K>
//T HashTble<T, K>::searchItem(K key) {
//	for (int i = 0; i < size; i++) {
//		int index = (h1(key) + i * h2(key)) % size;
//		if (table[index].flag == 0)//not have it
//			return NULL;
//		if ((table[index].key == key) & (table[index].flag == 1))//is found
//			table[index];
//	}
//	return NULL;
//}


template <class T, class K>
void HashTble<T, K>::del(K key) {//delet from data
	int ind = search(key);
	if (ind == -1 || table[ind].flag == 2 || table[ind].flag == 0)
		return;//throw "The Key not found ";
	size--;
	table[ind].flag = deleted;

}

template <class T, class K>
void HashTble<T, K>::print()//print
{

	for (int i = 0; i < size; i++)
	{
		if (table[i].flag == full)
		{
			cout << table[i].data << endl;;
		}

	}


}

