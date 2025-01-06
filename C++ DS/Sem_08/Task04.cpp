#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct Node
{
	T data;

	Node* left;
	Node* right;

	Node(const T& data) : data(data), left(nullptr), right(nullptr)
	{}
};

template <typename T>
int getHeight(Node<T>* root)
{
	if (!root)
		return -1;

	return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main()
{
	Node<int>* root = new Node<int>(2);
	Node<int>* n1 = new Node<int>(7);
	Node<int>* n2 = new Node<int>(5);
	Node<int>* n3 = new Node<int>(2);
	Node<int>* n4 = new Node<int>(6);
	Node<int>* n5 = new Node<int>(9);
	Node<int>* n6 = new Node<int>(5);
	Node<int>* n7 = new Node<int>(11);
	Node<int>* n8 = new Node<int>(4);

	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->right = n5;
	n4->left = n6;
	n4->right = n7;
	n5->left = n8;

	cout << getHeight(root);
}