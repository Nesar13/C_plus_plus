#include <iostream>
using namespace std; 

template <class T>
struct Node
{
	T data;
	Node* left; //for left side of node
	Node* right;
	Node(T data)
		: data(data)
		, left(nullptr)
		, right(nullptr) {}
};


template <class T>
class BinarySearchTree
{
private:
	Node<T> *root;
public:
	BinarySearchTree(T value)
	{
		root->data = value;
		root->left = nullptr;
		root->right = nullptr;
	}

	BinarySearchTree(const BinarySearchTree &right_t)
	{
		root->data = right_t.root->data;
		root->right = nullptr;
		root->left = nullptr;
		if (nullptr != right_t.root->right)
			root->right = new BinarySearchTree(*(right_t.root->right));
		if (nullptr != right_t.root->left)
			root->left = new BinarySearchTree(*(right_t.root->left));
	}

	T operator = (const BinarySearchTree<T>  &right_t)
	{
		if (this != &right)


	}
	~BinarySearchTree() {
		while ((root->left != nullptr) &&
			(root->right != nullptr))
			delete root->left, root->right;
	}
	bool isLeaf() {
		if ((nullptr == left) && (nullptr == right))
			return true;
		else
			return false;
	}
	int getLevel(T value) { //get level for node with key=value
	}
	void add(T value) {
	}
	void deleteNode(T value) {
	}
	void printTree() {
	}
	
};

int main() {

	cout << "What is the employee name?:  \n"; 
	 
	return 0; 
}

//couldn't get the recursion part
/*Create a class structure of nodes representing employees. 
Each employee node has a name, and then can have zero or more employees working for them.

1. Prompt the user for an employee name.
2. Create a node for that employee.
3. Ask how many employees work for that employee.
4. Repeat steps 1-3 for each employee that works for the employee. 
	Each new employee node should be stored as a child node of the employee node for whom they work. 
	This will be recursive -- i.e. you may end up inputting employees of employees of employees of employees of ...
5. You may not store any additional information beyond what was mentioned above this line.
6. Display a list of all employees that have 3+ employees working for them (including all "descendant" employees).
7. Find all employees that do not have any employees working for them. Display each one's name, 
	and a list of their supervisors in order from direct manager to top employee.*/