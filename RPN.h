//
// Created by Владимир on 20.10.15.
//

#ifndef CONTAINERS_RPN_H
#define CONTAINERS_RPN_H

struct StackRPN
{
    double			    val;
    struct StackRPN 	*next;
};


static _Bool pushRPN(struct StackRPN **head, double x);
static double popRPN(struct StackRPN **head);

static void deleteStackRPN(struct StackRPN **head);

static size_t getSizeStackRPN(struct StackRPN *head);


double callRPN(char *string);


#endif //CONTAINERS_RPN_H

