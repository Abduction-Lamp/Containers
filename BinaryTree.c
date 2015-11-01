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


void binaryTreeAdd(bTree *tree, int val)
{
	if ((*tree) == NULL)
	{
		*tree = (bTree)malloc(sizeof(struct BinaryTree));
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


bTree binaryTreeSearch(bTree tree, int key)
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


void binaryTreePrintLRR(bTree tree)
{
	if (tree == NULL)
	{	
		return;
	}

	binaryTreePrintLRR(tree->left);
	
	printf("%d ", tree->data);
	
	binaryTreePrintLRR(tree->right); 	
}


void binaryTreePrintRRL(bTree tree)
{
	if (tree == NULL)
	{	
		return;
	}

	binaryTreePrintRRL(tree->right);
	
	printf("%d ", tree->data);
	
	binaryTreePrintRRL(tree->left); 	
}


bTree binaryTreeGetLeft(bTree tree)
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


bTree binaryTreeGetRight(bTree tree)
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


void binaryTreeDelete(bTree *tree)
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


size_t binaryTreeGetHeight(bTree tree)
{
	if (tree == NULL)
	{
		return 0;
	}

	return 1 + max(binaryTreeGetHeight(tree->left), binaryTreeGetHeight(tree->right));
}
