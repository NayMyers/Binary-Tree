#pragma once
#include <iostream>

using namespace std;

template<typename T>
class TreeNode
{
public:
	T value; 
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
	TreeNode<T>* New Node = new TreeNode<T>;
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
int main()
{
	
	return 0;
}