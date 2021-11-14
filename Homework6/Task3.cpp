#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	long key;
	Node* right, * left;
	Node();
	Node(const long& key);
};

Node::Node()
	: key(NULL)
	, right(NULL)
	, left(NULL)
{
}

Node::Node(const long& key)
	: key(key)
	, right(NULL)
	, left(NULL)
{
}
class BST {

	Node* root;

	Node* Insert(Node* current, const long& key);
	Node* Delete(Node* current, const long& key);
	Node* inorderSuccessor(Node* node);
	long Height(Node* node);
	void PrintLevels(Node* root);
	void PrintLevel(Node* root, long level);
	void Inorder(Node* current, vector<long>& sequence);

public:
	BST();
	BST(const long& key);

	void Input(const long& n);
	void Insert(const long& key);
	void Delete(const long& key);
	void Inorder(vector<long>& sequence);
	void Print();
};


BST::BST()
{
	root = new Node();
}

BST::BST(const long& key)
{
	root = new Node(key);
}

void BST::Input(const long& n)
{
	for (long i = 0; i < n; i++)
	{
		long key;
		cin >> key;
		Insert(key);
	}
}

void BST::Insert(const long& key)
{
	root = Insert(root, key);
}

void BST::Delete(const long& key)
{
	root = Delete(root, key);
}

void BST::Inorder(vector<long>& sequence)
{
	Inorder(root, sequence);
}

void BST::Print()
{
	PrintLevels(this->root);
}

//insertion function returning reference to the new leaf
Node* BST::Insert(Node* current, const long& key)
{
	//Base
	if (current == NULL || current->key == NULL)
	{
		return new Node(key);
	}

	if (current->key < key)
	{
		current->right = Insert(current->right, key);
	}

	else
	{
		current->left = Insert(current->left, key);
	}

	return current;
}

//deleting function returning reference to the deleted leaf
Node* BST::Delete(Node* current, const long& key)
{
	//Base
	if (current == NULL)
	{
		return current;
	}

	if (current->key > key)
	{
		current->left = Delete(current->left, key);
	}

	else if (key > current->key)
	{
		current->right = Delete(current->right, key);
	}

	else
	{
		//For leaves without childer
		if (current->left == NULL && current->right == NULL)
		{
			return NULL;
		}

		//For leaves with only one shild
		else if (current->left == NULL)
		{
			Node* temp = current->right;
			delete(current);
			return temp;
		}

		else if (current->right == NULL)
		{
			Node* temp = current->left;
			delete(current);
			return temp;
		}

		//For leaves with two children
		//Getting he inorder successor
		Node* temp = inorderSuccessor(current->right);

		current->key = temp->key;

		current->right = Delete(current->right, temp->key);
	}

	return current;
}

Node* BST::inorderSuccessor(Node* root)
{
	Node* current = root;

	while (current != NULL && current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

long BST::Height(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else {
		long height1 = Height(node->left);
		long height2 = Height(node->right);

		return max(height1, height2) + 1;
	}
}

void BST::PrintLevels(Node* root)
{
	long height = Height(root);

	for (long i = 1; i <= height; i++)
	{
		PrintLevel(root, i);
	}
}

void BST::PrintLevel(Node* current, long level)
{
	if (current == NULL)
	{
		return;
	}
	if (level == 1)
	{
		cout << current->key << " ";
	}
	else
	{
		PrintLevel(current->left, level - 1);
		PrintLevel(current->right, level - 1);
	}
}

void BST::Inorder(Node* current, vector<long>& sequence) {

	if (current != NULL)
	{
		Inorder(current->right, sequence);
		long key = current->key;
		sequence.push_back(key);
		Inorder(current->left, sequence);
	}
}

int Task3() {

	long n;
	cin >> n;

	long indexK;
	cin >> indexK;

	BST tree;

	tree.Input(n);

	vector<long> orderedTree;
	tree.Inorder(orderedTree);

	long keyToDelete = orderedTree[indexK - 1];

	tree.Delete(keyToDelete);

	tree.Print();

	return 0;
}