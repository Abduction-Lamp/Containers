//
// Created by Vladimir
//

#ifndef STACK_H_
#define STACK_H_


struct Stack
{
	char 			data;
	struct Stack 	*next;
};


_Bool push(struct Stack **head, char x);
char pop(struct Stack **head);

void deleteStack(struct Stack **head);

size_t getSizeStack(struct Stack *head);


#endif //STACK_H_
