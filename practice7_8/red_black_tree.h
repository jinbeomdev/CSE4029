#pragma once
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

enum Color { 
	RED, BLACK
};

struct Node {
	Node* parent;
	Node* left;
	int key;
	Node* right;
	Color color;
};

class RedBlackTree {
private:	
	Node * root_;

	RedBlackTree() {
		root_ = nullptr;
	}

	Node* Parent(Node* n);
	Node* Grandparent(Node* n);
	Node* Sibling(Node* n);
	Node* Uncle(Node* n);
	void RotateLeft(Node* n);
	void RotateRight(Node* n);
	Node* Insert(Node* root, Node* n);
	Node* InsertRecurse(Node* root, Node* n);
	void InsertRepairTree(Node* n);
	void InsertCaseOne(Node* n);
	void InsertCaseTwo(Node* n);
	void InsertCaseThree(Node *n);
	void InsertCaseFour(Node *n);
	void InsertCaseFourStepTwo(Node* n);

public:
	void Insert(Node* n);
};

#endif