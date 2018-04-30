/*
Student ID: 2013113504
Student Name : KIM JIN BEOM

Problem 3.
Implement the red-black tree insertion algorithm and test problem 2 to compare the results with it. (Print the tree each time you insert a key)

Input:
20,15,14,12,13,1
*/
#include <iostream>
#include "red_black_tree.h"

using namespace std; 


int main() {
	RedBlackTree *rbt = new RedBlackTree;
	rbt->Insert(20);
	rbt->LevelOrder();

	rbt->Insert(15);
	rbt->LevelOrder();

	rbt->Insert(14);
	rbt->LevelOrder();

	rbt->Insert(12);
	rbt->LevelOrder();

	rbt->Insert(13);
	rbt->LevelOrder();

	rbt->Insert(1);
	rbt->LevelOrder();

	system("pause");
}