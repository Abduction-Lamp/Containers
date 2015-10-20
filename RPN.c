//
// Created by Владимир on 20.10.15.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "RPN.h"


_Bool pushRPN(struct StackRPN **head, double x)
{
    struct StackRPN *stack = NULL;
    _Bool flag;

    stack = (struct StackRPN *)malloc(sizeof(struct StackRPN));
    if (stack != NULL)
    {
        stack->val = x;
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


double popRPN(struct StackRPN **head)
{
    struct StackRPN *stack = NULL;
    double x;

    if (*head != NULL)
    {
        stack = *head;
        x = stack->val;
        *head = stack->next;

        free(stack);
    }
    else
    {
        ;       // exception
    }

    return x;
}


void deleteStackRPN(struct StackRPN **head)
{
    struct StackRPN *stack = NULL;

    while (*head != NULL)
    {
        stack = *head;
        *head = stack->next;
        free(stack);
    }
}


size_t getSizeStackRPN(struct StackRPN *head)
{
    size_t i = 0;

    while (head != NULL)
    {
        head = head->next;
        i++;
    }

    return i;
}


void printRPN(struct StackRPN *head)
{
	while(head != NULL)
	{
		printf("%f ", head->val);
		head = head->next;
	}
	puts("\n");
}


double callRPN(char *string)
{
    struct StackRPN *head = NULL;

    double result = 0;
    double a;
    double b;

    int i;


    for (i = 0; i < strlen(string); i++)
    {
        switch (string[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                pushRPN(&head, string[i] - '0');
                break;

            case '-':
                b = popRPN(&head);
                a = popRPN(&head);
                result = a - b;
                pushRPN(&head, result);
                break;

            case '+':
                b = popRPN(&head);
                a = popRPN(&head);
                result = a + b;
                pushRPN(&head, result);
                break;

            case '*':
                b = popRPN(&head);
                a = popRPN(&head);
                result = a * b;
                pushRPN(&head, result);
                break;

            case '/':
                b = popRPN(&head);
                a = popRPN(&head);
                if (b != 0)
                {
                    result = a / b;
                    pushRPN(&head, result);
                }
		else
		{
                	;       // exception
		}
                break;
	    case '_':
		result = 0 - popRPN(&head);
		pushRPN(&head, result);
		break;

            default:
                ;       // exception
        }
    }

    if (getSizeStackRPN(head) != 1)
    {
    	;       // exception	
    }

    return popRPN(&head);
}

