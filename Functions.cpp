#include "Functions.h"


node* rootNode = nullptr;
int printProg = 0;

void SelectFile()
{
	cout << "\nEnter the name of the file (ie words.txt)" << endl;
	string input;
	cin >> input;

	ReadFile(input);
}

void ReadFile(string aFileName)
{
	ifstream fin(aFileName);

	if (!fin.good())
	{
		cerr << "Could not open data file!\n";
		return;
	}

	for (string word; fin >> word;)
	{
		insertNode(stoi(word));
	}

	fin.close();

	cout << "Finished loading tree" << endl;
}

void insertNode(int aNum)
{
	if (rootNode == nullptr)
	{
		rootNode = new node(aNum);	//lets make a root
		return;
	}

	node* newNode = new node(aNum);
	node* node = rootNode;

	for (;;)
	{
		if (newNode->value < node->value)	//if less than
		{
			if (node->ptrLeft == nullptr)
			{
				cout << "putting " << newNode->value << " on left of " << node->value << endl;
				node->ptrLeft = newNode;
				break;
			}
			else
			{
				node = node->ptrLeft;
			}
		}
		else if (newNode->value > node->value)//if greater than
		{
			if (node->ptrRight == nullptr)
			{
				cout << "putting " << newNode->value << " on right of " << node->value << endl;
				node->ptrRight = newNode;
				break;
			}
			else
			{
				node = node->ptrRight;
			}
		}
		else if (newNode->value == node->value)//if same value
		{
			cout << newNode->value << " is already in the tree" << endl;
			delete newNode;
			break;
		}
	}
}

void printInOrder(node* aNode, int aWordCount)
{
	//this is so you can call PrintInOrder(nullptr,0) from anywhere
	if (aNode == nullptr) aNode = rootNode;	

	if (aNode->ptrLeft != nullptr)
	{
		printInOrder(aNode->ptrLeft, aWordCount);
	}

	print(aNode->value);

	if (aNode->ptrRight != nullptr)
	{
		printInOrder(aNode->ptrRight, aWordCount);
	}

	return;
}

void print(int aNum)
{
	cout << setw(5);
	if (printProg++ >= 9) 
	{
		cout << endl; 
		printProg = 0;
	}
	cout << aNum << ", ";
}