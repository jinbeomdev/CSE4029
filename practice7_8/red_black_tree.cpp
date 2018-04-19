#include "red_black_tree.h"

Node * RedBlackTree::Parent(Node * n)
{
	return n->parent;
}

Node * RedBlackTree::Grandparent(Node * n) {
	Node* p = Parent(n);
	if (p == nullptr) return nullptr;
	return Parent(p);
}

Node * RedBlackTree::Sibling(Node * n) {
	Node* p = Parent(n);

	if (p == nullptr) return nullptr;
	if (p == p->left) {
		return p->right;
	} else {
		return p->left;
	}
}

Node * RedBlackTree::Uncle(Node * n) {
	return nullptr;
}

void RedBlackTree::RotateLeft(Node * n) {
}

void RedBlackTree::RotateRight(Node * n) {
}

Node * RedBlackTree::Insert(Node * root, Node * n) {
	return nullptr;
}

Node * RedBlackTree::InsertRecurse(Node * root, Node * n) {
	return nullptr;
}

void RedBlackTree::InsertRepairTree(Node * n) {
}

void RedBlackTree::InsertCaseOne(Node * n) {
}

void RedBlackTree::InsertCaseTwo(Node * n) {
}

void RedBlackTree::InsertCaseThree(Node * n) {
}

void RedBlackTree::InsertCaseFour(Node * n) {
}

void RedBlackTree::InsertCaseFourStepTwo(Node * n) {
}

void RedBlackTree::Insert(Node * n) {
}
