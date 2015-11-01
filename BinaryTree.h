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

typedef struct BinaryTree * bTree;



void binaryTreeAdd(bTree *tree, int val);

bTree binaryTreeSearch(bTree tree, int key);

void binaryTreePrintLRR(bTree tree);
void binaryTreePrintRRL(bTree tree);

bTree binaryTreeGetLeft( bTree tree);
bTree binaryTreeGetRight(bTree tree);
size_t binaryTreeGetHeight(bTree tree);

void binaryTreeDelete(bTree *tree);


#endif //CONTAINERS_BINARYTREE_H
