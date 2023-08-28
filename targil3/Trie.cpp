#include<iostream>
#include "Trie.h"

using namespace std;
int chToIn(char ab) { return (int)ab - (int)'a'; }
char intToCh(int ab) { return (char)ab + (char)'a'; }
void Trie::insertWord(string str) {

	if (searchtWord(str))//word exists
	{
		cout << " word exists, no need to insert\n";
		return;
	}
	TrieNode* ptr = root;
	int size = str.size();
	int i = 0;//begining
	while (i < size)
	{
		int index = chToIn(str[i]);//from char to int in abc
		if (ptr->children[index] == NULL)//no have this kodkod
			ptr->children[index] = new TrieNode(ptr);//so insert
		ptr = ptr->children[index];//if have so continue
		i++;
	}
	//end of word
	ptr->isEndWorde = true;
	return;
}
bool Trie::deletetWord(string str)
{
	TrieNode* ptr = root;
	int size = str.size();
	int index;
	int i = 0;//begining
	if (!searchtWord(str))
	{
		return false;
	}

	if (!existSon(str))
	{
		while (i < size)
		{
			index = chToIn(str[i]);//from char to int in abc
			if (ptr->children[index] == NULL)//no have this kodkod
			{
				return false;//mo have
			}
			ptr = ptr->children[index];//if have so continue
			i++;
		}
		ptr->father->children[index] = NULL;
		ptr = ptr->father;
		size--;
		while (size > 0)
		{
			if (ptr->isEndWorde)
			{
				return true;
			}
			for (int j = 0; j < 26; j++)
			{
				if ((ptr->children[j] != NULL) && (j != index))
				{
					return true;
				}
			}
			size--;
			index = chToIn(str[size - 1]);
			ptr = ptr->father->father->children[index];

		}

	}
	return true;
}
bool Trie::existSon(string str)
{
	TrieNode* ptr = root;//the trie
	int i = 0;//begining
	int size = str.size();
	while (i < size)
	{
		int index = chToIn(str[i]);//from char to int in abc
		ptr = ptr->children[index];//if have so continue
		i++;
	}
	if (ptr->isEndWorde)
	{
		for (int j = 0; j < 26; j++)
		{
			if (ptr->children[j] != NULL)
			{
				ptr->isEndWorde = false;
				return true;
			}
		}
		return false;
	}
}
bool Trie::havechildren(TrieNode* str)
{

	if (str->isEndWorde) {
		return false;
	}
	return true;
}



bool Trie::searchtWord(string str) {
	TrieNode* ptr = root;//the trie
	int i = 0;//begining
	int size = str.size();
	while (i < size)
	{
		int index = chToIn(str[i]);//from char to int in abc
		if (ptr->children[index] == NULL)//no have this kodkod
			return false;//mo have
		ptr = ptr->children[index];//if have so continue
		i++;
	}
	return ptr->isEndWorde;
}
Trie::TrieNode* Trie::searchtWordr(string str) {//get string and if have rerutn the str
	Trie::TrieNode* pt = root;
	Trie::TrieNode* ptr = root;
	int i = 0;//begining
	int size = str.size();
	while (i < size)
	{
		int index = chToIn(str[i]);//from char to int in abc
		if (pt->children[index] == NULL)//no have this kodkod
			return NULL;//mo have
		pt = pt->children[index];//if have so continue
		i++;
	}
	return pt;
}

int Trie::printAllWrd(string str) {
	if (searchtWordr(str) == NULL)//word exists
	{
		return 0;
	}
	else {

		printAllWrdd(str);
	}
}

void Trie::print(TrieNode*& pt, string str) {
	string tmp = str;
	if (pt->isEndWorde)//àí æä ñåó ùì îéìä(ðøàìé)
		cout << tmp << endl;
	if (havechildren(pt))//àí éù ìå áðéí
	{
		for (int i = 0; i < 26; i++)
		{
			if (pt->children[i] != 0)
			{
				tmp += (char)(i + 97);
				print(pt->children[i], tmp);
				tmp = str;
			}
		}

	}

}
void Trie::printAllWrdd(string str) {
	char tmp;
	TrieNode* t = root;
	for (int i = 0; i < str.length(); i++)
	{
		tmp = str[i];
		t = t->children[tmp - 97];
	}
	print(t, str);
}
