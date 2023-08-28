#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTreeNode.h"
using namespace std;

class HuffmanTree
{
public:
	HuffmanNode* root;
	string encodingChar[26];
	string treeStructure;
	int mone; // mone how many characters there are.
	string oretters;// Characters In the order in which they appear in the tree
	string tEncoding;
	string tText;
public:
	HuffmanTree(string str)
	{
		root = NULL;
		textToEncoding(str);
	}
	HuffmanTree(string treeStructure1, int countChar1, string OrderOfLetters1, string encoding1) {

		treeStructure = treeStructure1;
		mone = countChar1;
		oretters = OrderOfLetters1;

		EncodingToText(encoding1);
	}
	~HuffmanTree() { root->~HuffmanNode(); }
	void insertToPriorityQueue(priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode>& pQueue, int freq[26]);// insert all characters to the priority queue.
	void buildTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode>& queue);// Build the tree with the prioruty queue.
	void fillArrayEncoding(HuffmanNode* p, string encoding);
	int* frequencys(string str);
	void fillTheTreeStructure(HuffmanNode* ptr);
	void fillTheEncoding(string ptr);
	void reseteAllVariable();//resete all variable for the next input.
	void buildTreeWithEncoding(HuffmanNode* p, int& indexOfTreeStructure, int& indexOfOrderOfLetters);// Get encoding and build tree with it.
	void fillTheText(string e); //fill variable 'TheText'
	int searchEncoding(string e);//Return 'i' (index) if have the enco (encoding) in the array 'encodingOfEachChar', else -1.
	void EncodingToText(string e);
	void textToEncoding(string str);

	void textToEncoding();
	void encodingToText();

};
void HuffmanTree::insertToPriorityQueue(priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode>& queue, int freq[26])

{
	for (int i = 0; i < 26; i++)
	{
		if (freq[i] != 0)
		{
			string s(1, (char)i + 97);
			HuffmanNode* huff = new HuffmanNode(s, freq[i]);

			queue.push(huff);

			s = "";
		}
	}

}
int indexOfChar(char c) { return (int)c - 97; }
void HuffmanTree::buildTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode>& pQueue)

{
	while (!pQueue.empty())
	{
		HuffmanNode* sanLeft = pQueue.top();
		pQueue.pop();
		if (!pQueue.empty())
		{
			HuffmanNode* SanRight = pQueue.top();
			pQueue.pop();

			string str = sanLeft->str + SanRight->str;
			int frequency = sanLeft->frequency + SanRight->frequency;
			HuffmanNode* huff3 = new HuffmanNode(str, frequency, SanRight, sanLeft);
			pQueue.push(huff3);

			SanRight = NULL;

		}
		else
		{
			root = sanLeft;
			sanLeft = NULL;
		}


	}

}
void HuffmanTree::fillArrayEncoding(HuffmanNode* ptr, string e)

{// (string) Encoding of each char is Huffman's codding.
		// Any recursion add to (string)encoding the new 'encoding', if left add '0' else add '1'. 
		// (string) Encoding is holder the char's encoding.

		// Fill the array 'encodingOfEachChar'.		 
	try
	{
		if (ptr->left != NULL)
		{
			fillArrayEncoding(ptr->left, e + "0");


			fillArrayEncoding(ptr->right, e + "1");
		}
		else
		{
			encodingChar[indexOfChar(ptr->str[0])] = e;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}


}
int* HuffmanTree::frequencys(string str)

{
	int freq[26];
	for (size_t i = 0; i < 26; i++)
		freq[i] = 0;


	for (int i = 0; i < str.size(); i++)
	{
		freq[indexOfChar(str[i])]++;
	}

	return freq;
}
void HuffmanTree::fillTheTreeStructure(HuffmanNode* p)

{
	if (p == NULL) return;

	if (p->left == NULL)
		treeStructure += "1";
	else
	{
		treeStructure += "0";
		fillTheTreeStructure(p->left);
		fillTheTreeStructure(p->right);
	}
}
void HuffmanTree::fillTheEncoding(string str)

{
	for (int i = 0; i < str.size(); i++)
	{
		string a = encodingChar[indexOfChar(str[i])];
		tEncoding += a;
	}
}
void HuffmanTree::reseteAllVariable()

{
	if (root != NULL)
		delete root;

	for (size_t i = 0; i < 26; i++)
		encodingChar[i] = "";
	treeStructure = "";
	mone = 0;
	tEncoding = "";
	oretters = "";
	tText = "";
}
void HuffmanTree::buildTreeWithEncoding(HuffmanNode* p, int& indexOfTreeStructure, int& indexOfOrderOfLetters)

{
	if (treeStructure[indexOfTreeStructure] == '0')
	{
		p->left = new HuffmanNode();
		p->right = new HuffmanNode();

		buildTreeWithEncoding(p->left, ++indexOfTreeStructure, indexOfOrderOfLetters);
		buildTreeWithEncoding(p->right, ++indexOfTreeStructure, indexOfOrderOfLetters);

	}
	else
	{
		if (indexOfOrderOfLetters >= oretters.size())
			throw " ";

		p->str = oretters[indexOfOrderOfLetters++];
	}

}
void HuffmanTree::fillTheText(string encoding)

{
	string character = "";
	for (size_t i = 0; i < encoding.size(); i++)
	{
		character += encoding[i];
		int index = searchEncoding(character);
		if (index != -1)
		{
			tText += (char)(index + 97);
			character = "";
		}
	}
}
int HuffmanTree::searchEncoding(string enco)

{
	for (size_t i = 0; i < 26; i++)
		if (encodingChar[i] == enco)
			return i;

	return -1;
}
void HuffmanTree::EncodingToText(string encoding)
{
	if (treeStructure.size() < 2)
		return;

	root = new HuffmanNode();

	int inindexOfTreeStructuredex = 0;
	int indexOfOrderOfLetters = 0;
	buildTreeWithEncoding(root, inindexOfTreeStructuredex, indexOfOrderOfLetters);

	fillArrayEncoding(root, "");
	fillTheText(encoding);

}
void HuffmanTree::textToEncoding(string str)
{
	reseteAllVariable();
	int freq[26] = { 0 };

	for (int i = 0; i < str.size(); i++)
	{
		freq[indexOfChar(str[i])]++;
	}

	priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode> pQueue;

	insertToPriorityQueue(pQueue, freq);
	buildTree(pQueue);
	fillArrayEncoding(root, "");
	fillTheTreeStructure(root);
	fillTheEncoding(str);


	for (size_t i = 0; i < 26; i++)
		if (freq[i] != 0) mone++;

	oretters = root->str;

}



void HuffmanTree::textToEncoding()
{
	if (tText == "")
	{
		cout << "The encoded string is\n";
		cout << mone << endl << oretters << endl;
		cout << treeStructure << endl << tEncoding << endl;
	}
}
void HuffmanTree::encodingToText()
{
	if (tEncoding == "")
	{

		cout << "The decoded string is\n";
		cout << " " << tText << endl;

		reseteAllVariable();
	}

}

