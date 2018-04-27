/*
Student ID : 2013113504
Student Nmae : KIM JIN BEOM

Question 1:
Implement binary search tree using Linked List and Let's try search,
insertion and seletion

1) Make an empty tree and insert 20, 6, 2, 4, 16, 10, 8, 12, 14, 9
to make a tree T1. Search  10 in the tree T1 and print right and left
child of 10.

2) After deleting 6 from T1, search 10 and print the value of the right
and left nodes of 10.(Print the result after using the program.)

3) Submit the code for creating an empty tree, search, insertion, and
deletion.
*/

#include<iostream>
using namespace std;

bool c = false;

struct node
{
	int data;
	node* left;
	node* right;
};

struct node* getNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

node* findMin(node*root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

struct node* Insert(struct node* root, int data)
{
	if (root == NULL)
		return getNode(data);

	if (data < root->data)
		root->left = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);

	return root;
}

node* Search(node*root, int value)
{
	if (root == NULL)
		return false;
	else if (root->data == value)
	{
		return root;
	} else if (value < root->data)
		Search(root->left, value);
	else if (value > root->data)
		Search(root->right, value);
}


node* Delete(node* root, int value)
{
	c = Search(root, value);
	if (root == NULL)
		return root;
	else if (value< root->data)
	{
		root->left = Delete(root->left, value);
	} else if (value> root->data)
	{
		root->right = Delete(root->right, value);
	}

	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}
		else if (root->left == NULL)
		{
			struct node* temp = root;
			root = root->right;
			delete temp;
			return root;
		} else if (root->right == NULL)
		{
			struct node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else
		{
			struct node*temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;

}


int main()
{
	node* root = NULL;
	root = Insert(root, 20);
	Insert(root, 6);
	Insert(root, 2);
	Insert(root, 4);
	Insert(root, 16);
	Insert(root, 10);
	Insert(root, 8);
	Insert(root, 12);
	Insert(root, 14);
	Insert(root, 9);
	node* temp = Search(root, 10);
	cout << temp->left->data << " " << temp->right->data << endl;

	Delete(root, 6);
	Search(root, 10);
	temp = Search(root, 10);
	cout << temp->left->data << " " << temp->right->data << endl;
	system("pause");
}