#pragma once

#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class node
{
public:
	int value;
	node* ptrRight;
	node* ptrLeft;

	node(int aValue) { value = aValue; };
};

void SelectFile();
void ReadFile(string aFileName);

void insertNode(int aNum);
void printInOrder(node* aNode, int aWordCount);
void print(int aNum);