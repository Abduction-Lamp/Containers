//
// Created by Vladimir
//
                     
#include <stdlib.h>
#include <stdio.h>

#include "BinaryTree.h"



static size_t max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}


void binaryTreeAdd(struct BinaryTree **tree, int val)
{
	if ((*tree) == NULL)
	{
		*tree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
		if ((*tree) != NULL)
		{	
			(*tree)->data = val;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
		}
	}
	else
	{
		if (val < (*tree)->data)
		{
			binaryTreeAdd(&((*tree)->left), val);	
		}
		else
		{
                	binaryTreeAdd(&((*tree)->right), val);	
		}
	}
}


struct BinaryTree * binaryTreeSearch(struct BinaryTree *tree, int key)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else
	{
		if (key == tree->data)
		{
			return tree;
		}
		else
		{
			if (key < tree->data)
			{
				return binaryTreeSearch(tree->left, key);
			}
			else
			{
				return binaryTreeSearch(tree->right, key);
			}
		}
	}
}


void binaryTreePrintLRR(struct BinaryTree *tree)
{
	if (tree == NULL)
	{	
		return;
	}

	binaryTreePrintLRR(tree->left);
	
	printf("%d ", tree->data);
	
	binaryTreePrintLRR(tree->right); 	
}


void binaryTreePrintRRL(struct BinaryTree *tree)
{
	if (tree == NULL)
	{	
		return;
	}

	binaryTreePrintRRL(tree->right);
	
	printf("%d ", tree->data);
	
	binaryTreePrintRRL(tree->left); 	
}


struct BinaryTree * binaryTreeGetLeft(struct BinaryTree *tree)
{
	if (tree == NULL)
	{
		return	NULL;
	}
	else
	{
		if (tree->left == NULL)
		{
			return tree;
		}
		else
		{
			return binaryTreeGetLeft(tree->left);
		}
	}	
}


struct BinaryTree * binaryTreeGetRight(struct BinaryTree *tree)
{
	if (tree == NULL)
	{
		return	NULL;
	}
	else
	{
		if (tree->right == NULL)
		{
			return tree;
		}
		else
		{
			return binaryTreeGetRight(tree->right);
		}
	}
}


void binaryTreeDelete(struct BinaryTree **tree)
{
	if ((*tree) == NULL)
	{	
		return;
	}

	binaryTreeDelete(&((*tree)->left)); 	
	binaryTreeDelete(&((*tree)->right));
	
	free(*tree);
	*tree = NULL;
}


size_t binaryTreeGetHeight(struct BinaryTree *tree)
{
	if (tree == NULL)
	{
		return 0;
	}

	return 1 + max(binaryTreeGetHeight(tree->left), binaryTreeGetHeight(tree->right));
}
