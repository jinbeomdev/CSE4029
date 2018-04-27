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
	Node* p = Parent(n);
	Node* g = Grandparent(n);
	if (g == nullptr) return nullptr;
	return Sibling(p);
}

void RedBlackTree::RotateLeft(Node * n) {
	Node* n_new = n->right;
	assert(n_new != LEAF);
	n->right = n_new->left;
	n_new->left = n;
	n_new->parent = n->parent;
	n->parent = n_new;
}

void RedBlackTree::RotateRight(Node * n) {
	Node* n_new = n->left;
	assert(n_new != LEAF);
	n->left = n_new->right;
	n_new->right = n;
	n_new->parent = n->parent;
	n->parent = n_new;
}

Node * RedBlackTree::Insert(Node * root, Node * n) {
	InsertRecurse(root, n);
	InsertRepairTree(n);
	root = n;
	while (Parent(root) != nullptr) {
		root = Parent(root);
	}
	return root;
}

Node * RedBlackTree::InsertRecurse(Node * root, Node * n) {
	if (root != nullptr && n->key < root->key) {
		if (root->left != LEAF) {
			InsertRecurse(root->left, n);
			return;
		}
		else {
			root->right = n;
		}
	}

	n->parent = root;
	n->left = LEAF;
	n->right = LEAF;
	n->color = RED;
}

void RedBlackTree::InsertRepairTree(Node * n) {
	if (Parent(n) == nullptr) {
		InsertCaseOne(n);
	} else if (Parent(n)->color == BLACK) {
		InsertCaseTwo(n);
	} else if (Uncle(n)->color == RED) {
		InsertCaseThree(n);
	} else {
		InsertCaseFour(n);
	}
}

void RedBlackTree::InsertCaseOne(Node * n) {
	if (Parent(n) == nullptr) n->color = BLACK;
}

void RedBlackTree::InsertCaseTwo(Node * n) {
	return;
}

void RedBlackTree::InsertCaseThree(Node * n) {
	Parent(n)->color = BLACK;
	Uncle(n)->color = BLACK;
	Grandparent(n)->color = RED;
	InsertRepairTree(Grandparent(n));
}

void RedBlackTree::InsertCaseFour(Node * n) {
	Node* p = Parent(n);
	Node* g = Grandparent(n);

	if (n == g->left->right) {
		RotateLeft(p);
		n = n->left;
	} else if (n == g->right->left) {
		RotateRight(p);
		n = n->right;
	}
}

void RedBlackTree::InsertCaseFourStepTwo(Node * n) {
	Node* p = Parent(n);
	Node* g = Grandparent(n);

	if (n == p->left) {
		RotateRight(g);
	} else {
		RotateLeft(g);
		p->color = BLACK;
		g->color = RED;
	}
}