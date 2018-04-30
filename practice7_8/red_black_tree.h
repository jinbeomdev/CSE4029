#pragma once
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <cassert>
#include <queue>

enum Color { 
	RED, BLACK
};

struct Node {
	Node* parent;
	Node* left;
	int key;
	Node* right;
	bool color;

	Node(int n) {
		parent = nullptr;
		left = nullptr;
		key = n;
		right = nullptr;
		color = RED;
	}
};

class RedBlackTree {
private:	
	Node * root_;
	Node* LEAF;

	Node* Parent(Node* n);
	Node* Grandparent(Node* n);
	Node* Sibling(Node* n);
	Node* Uncle(Node* n);
	void RotateLeft(Node* n);
	void RotateRight(Node* n);
	Node* Insert(Node* root, Node* n);
	void InsertRecurse(Node* root, Node* n);
	void InsertRepairTree(Node* n);
	void InsertCaseOne(Node* n);
	void InsertCaseTwo(Node* n);
	void InsertCaseThree(Node *n);
	void InsertCaseFour(Node *n);
	void InsertCaseFourStepTwo(Node* n);
	void InOrder(Node* n);

public:
	RedBlackTree() {
		root_ = nullptr;
		LEAF = new Node(0);
		LEAF->color = BLACK;
	}

	void Insert(int n);
	void InOrder();
	void LevelOrder();
};

#endif