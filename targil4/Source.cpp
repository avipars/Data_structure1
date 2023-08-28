
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"


int main()
{
	char choice;

	priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::CompareNode> pQueue;

	HuffmanTree* aa;
	string word;
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		try
		{

			cin >> choice;
			switch (choice)
			{
			case 'E'://get string amd kidud

				cout << "enter the original text" << endl;
				cin >> word;
				aa = new HuffmanTree(word);
				aa->textToEncoding();

				break;
			case 'D'://get the list and pianuch
				cout << "enter n\n";
				int x;

				cout << "enter the letters\n";
				string str1;

				cout << "enter the encoded structure\n";
				string str2;

				cout << "enter the encoded text\n";
				string str3;

				cin >> x >> str1 >> str2 >> str3;

				aa = new HuffmanTree(str2, x, str1, str3);
				aa->encodingToText();

				break;

			}

		}
		catch (...)
		{
			cout << "ERROR\n";
		}
	} while (choice != 'X');


	cout << "bye\n";

	return 0;
}
