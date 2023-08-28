#pragma once
#include<iostream>
#include <string>

using namespace std;
//const int ALPHABET = 26;
//int chToInd(char ab) { return (int)ab - (int)'a'; }
class Trie {
public:
	class TrieNode {
	public:
		TrieNode* children[26] = { 0 };
		TrieNode* father;
		bool isEndWorde = false;
	public:
		TrieNode() {  };
		TrieNode(TrieNode* dad) { father = dad; };
	};
	TrieNode* root;
public:
	Trie() { root = new TrieNode(NULL); };
	void insertWord(string str);
	bool deletetWord(string str);
	bool searchtWord(string str);
	TrieNode* searchtWordr(string str);
	int printAllWrd(string str);
	void print(TrieNode*& pt, string str);
	void printAllWrdd(string str);
	bool existSon(string str);
	bool havechildren(TrieNode* str);
	//void searchtWord(string str, TrieNode* node);
};
