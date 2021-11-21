#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node {
	int key;
	Node* left, * right;
	Node();
	Node(const int& key);
};

Node::Node()
	:key(NULL)
	, left(NULL)
	, right(NULL)
{
}

Node::Node(const int& key)
	: key(key)
	, left(NULL)
	, right(NULL)
{
}

class BST {

	Node* root;

	Node* Insert(Node* current, const long& key, int neighbours[]);
	int minXOR(int key, int neighbours[]);

public:
	BST();
	BST(const long& key);

	void Insert(const long& key, int neighbours[]);
};

void BST::Insert(const long& key, int neighbours[])
{
	root = Insert(root, key, neighbours);
}

BST::BST()
{
	root = new Node();
}

BST::BST(const long& key)
{
	root = new Node(key);
}

//insertion function returning reference to the new leaf
Node* BST::Insert(Node* current, const long& key, int neighbours[])
{
	//Base
	if (current == NULL)
	{
		return new Node(key);
	}

	if (current->key < key)
	{
		neighbours[0] = current->key;
		current->right = Insert(current->right, key, neighbours);
	}

	else if (current->key > key)
	{
		neighbours[1] = current->key;
		current->left = Insert(current->left, key, neighbours);
	}

	return current;
}

int main() {

	int q;
	cin >> q;

	BST tree(0);

	vector<int> mins;

	int min = INT_MAX;

	for (int i = 0; i < q; i++)
	{
		int neighbours[2] = { -1, -1 };
		int n;
		cin >> n;
		tree.Insert(n, neighbours);

		if (neighbours[0] != -1 && min > (n ^ neighbours[0]))
		{
			min = n ^ neighbours[0];
		}
		if (neighbours[1] != -1 && min > (n ^ neighbours[1]))
			min = n ^ neighbours[1];

		mins.push_back(min);
	}

	int length = mins.size();

	for (int i = 0; i < length; i++)
	{
		cout << mins[i] << endl;
	}

	return 0;
}

