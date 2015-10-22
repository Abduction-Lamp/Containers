//
// Created by Vladimir
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Queue.h"


_Bool queuePush(struct Queue *queue, double x)
{
	_Bool flag;
	struct Node *qNode = NULL;

	qNode = (struct Node *)malloc(sizeof(struct Node));
	if (qNode != NULL)
	{
		qNode->val = x;
		qNode->next = NULL;

		if (queue->tail != NULL)
		{
			queue->tail->next = qNode;
		}

		queue->tail = qNode;

		if (queue->head == NULL)
		{
			queue->head = qNode;
		}

		flag = true;
	}	
	else
	{
		flag = false;	
	}

	return flag;
}


double queuePop(struct Queue *queue)
{
	double x = 0;
	struct Node *qNode = queue->head;

	if (queue->head != NULL)
	{
		x = queue->head->val;
		queue->head = queue->head->next;

		if (queue->head == NULL)
		{
			queue->tail = NULL;
		}

		free(qNode); 		
	}
	else
	{
		;       // exception 
	}

	return x;
}


size_t queueSize(struct Queue *queue)
{
	int count = 0;
	struct Node *qNode = queue->head;

	while (qNode != NULL)
	{
		count++;
		qNode = qNode->next;
	}

	return count;
}


_Bool queueDelete(struct Queue *queue)
{
	_Bool flag = true;
	struct Node *qNode = queue->head;
	struct Node *delNode = qNode;

	while (qNode != NULL)
	{
		qNode = qNode->next;
		free(delNode);
		delNode = qNode;
	}

	queue->head = NULL;
	queue->tail = NULL;

	return flag;
}
