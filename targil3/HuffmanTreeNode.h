#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
using namespace std;

class HuffmanNode
{
public:
	HuffmanNode()
	{
		str = "";
		frequency = 0;
		left = NULL;
		right = NULL;
	}
	HuffmanNode(string str1, int frequency1)
	{
		str = str1;
		frequency = frequency1;
		left = NULL;
		right = NULL;
	}
	HuffmanNode(string str1, int frequency1, HuffmanNode* right1, HuffmanNode* left1)
	{
		str = str1;
		frequency = frequency1;
		left = left1;
		right = right1;
	}
	~HuffmanNode()
	{
		if (left != NULL)
		{
			delete left;
			left = NULL;
		}
		if (right != NULL)
		{
			delete right;
			right = NULL;
		}

	}

	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;


	class CompareNode
	{
	public:
		CompareNode() {}
		~CompareNode() {}

		bool operator()(HuffmanNode* const& n, HuffmanNode* const& n2)
		{
			return n->frequency > n2->frequency;
		}
	};

};
