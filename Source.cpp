#pragma once
#include <iostream>

using namespace std;

template<typename T>
class TreeNode
{
public:
	T value; 
	TreeNode<T>* pRight = nullptr;
	TreeNode<T>* pLeft = nullptr;
};
template<typename T>
class IterativeBinaryTree
{
private:
	TreeNode<T>* Root = nullptr;
public:
	void addValue(T value);
	void findValue(T value);
};
template<typename T>
void IterativeBinaryTree<T>::addValue(T value)
{
	TreeNode<T>* NewNode = new TreeNode<T>;
	NewNode->value = value;

	if (Root == nullptr)
	{
		//tree is empty because the root is equal to nullptr
		Root = NewNode; //therefore the new node will be the first one in the tree so it will 
		//be the root
		return;
	}

	TreeNode<T>* CurrentNode = Root;
	TreeNode<T>* PreviousNode = nullptr;

	while (CurrentNode != nullptr)//keep going until the end of the tree
	{
		if (CurrentNode->value == NewNode->value)
		{
			//the value already exists in the tree
			//duplicates are not allowed in the tree
			delete NewNode; // get rid of the node we created because it already exists
			return;
		}

		PreviousNode = CurrentNode;

		if (CurrentNode->value > NewNode->value)
		{
			CurrentNode = CurrentNode->pLeft; // new value is lower so it should go left of the node we are on
		}
		else
		{
			CurrentNode = CurrentNode->pRight; //must be higher and we know it's not the same
		}
	}
	//add node
	if (PreviousNode->value > NewNode->value) PreviousNode->pLeft = NewNode;
	else PreviousNode->pRight = NewNode;
}
template<typename T>
void IterativeBinaryTree<T>::findValue(T value)
{
	int searchcount = 1;
	TreeNode<T>* CurrentNode = Root; // start at the top
	 
	while (CurrentNode != nullptr)//Keep going until fall off tree
	{
		if (CurrentNode->value == value)
		{
			cout << "Found! Number of node search operations = " << searchcount << endl;
			return;//the value has been found
		}
		if (value < CurrentNode->value) CurrentNode = CurrentNode->pLeft;//less so go left 
		else CurrentNode = CurrentNode->pRight;//else, go right
		searchcount++;
	}
	cout << "Not found! Number of node serach operations = " << searchcount << endl;
}
int main()
{
	IterativeBinaryTree<int> MyTree;
	IterativeBinaryTree<int> MyTree2;
	int numbers[] = { 4, 2, 6, 1, 3, 5, 7 };

	for (int count = 1; count <= 7; count++) MyTree.addValue(count);

	for (int count = 0; count < 7; count++) MyTree2.addValue(numbers[count]);

	cout << "Array to find 7:" << endl;
	for (int searchcount = 1; searchcount <= 7; searchcount++)
	{
		if (numbers[searchcount - 1] == 7)
		{
			cout << searchcount << endl;
			break;
		}
	}
	cout << endl << "MyTree to find 7: " << endl;
	MyTree.findValue(7);

	cout << endl << "MyTree2 to find 7: " << endl;
	MyTree2.findValue(7);

	return 0;
}