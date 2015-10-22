//
// Created by Vladimir
//

#ifndef CONTAINERS_QUEUE_H
#define CONTAINERS_QUEUE_H


struct Node
{
	double 		val;
	struct Node *next;
};


struct Queue
{
	struct Node *head;
	struct Node *tail;
};



_Bool queuePush(struct Queue *queue, double x);
double queuePop(struct Queue *queue);
size_t queueSize(struct Queue *queue);
_Bool queueDelete(struct Queue *queue);


#endif //CONTAINERS_QUEUE_H
