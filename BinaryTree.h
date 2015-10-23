//
// Created by Vladimir
//

#ifndef CONTAINERS_BINARYTREE_H
#define CONTAINERS_BINARYTREE_H


struct BinaryTree
{
	int	data;
	
	struct BinaryTree *left;
	struct BinaryTree *right;	
};


void binaryTreeAdd(struct BinaryTree **tree, int val);

struct BinaryTree * binaryTreeSearch(struct BinaryTree *tree, int key);

void binaryTreePrintLRR(struct BinaryTree *tree);
void binaryTreePrintRRL(struct BinaryTree *tree);

struct BinaryTree * binaryTreeGetLeft(struct BinaryTree *tree);
struct BinaryTree * binaryTreeGetRight(struct BinaryTree *tree);

void binaryTreeDelete(struct BinaryTree **tree);


#endif //CONTAINERS_BINARYTREE_H
