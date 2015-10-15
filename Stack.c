//
// Created by Vladimir
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Stack.h"


_Bool push(struct Stack **head, char x)
{
	struct Stack *stack = NULL;
	_Bool flag = false;

	stack = (struct Stack *)malloc(sizeof(struct Stack));
	if (stack != NULL)
	{
		stack->data = x;
		stack->next = *head;
		*head = stack;

		flag = true;	
	}
	else
	{
		flag = false;
	}

	return flag;
}


char pop(struct Stack **head)
{
	struct Stack *stack = NULL;
	char x;

	if (*head != NULL)
	{
		stack = *head;
		x = stack->data;
		*head = stack->next;
		
		free(stack);
	}
	else
	{
		x = '?';
	}

	return x;		
}


void deleteStack(struct Stack **head)
{
	struct Stack *stack = NULL;
	
	while (*head != NULL)
	{
		stack = *head;
		*head = stack->next;
		free(stack);
	}
}


size_t getSizeStack(struct Stack *head)
{
	size_t i = 0;
	
	while (head != NULL)
	{
		head = head->next;
		i++;
	}

	return i;
}

