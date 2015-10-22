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
    int j;
    int k;
    char str[52];


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
		j = i;
		while (	string[j] == '0' || string[j] == '1' ||	string[j] == '2' || string[j] == '3' ||	string[j] == '4' || string[j] == '5' ||	string[j] == '6' || string[j] == '7' ||	string[j] == '8' || string[j] == '9')
		{	  
			j++;
		}
		j = j - i;
		if (j < 50)
		{
                	for (k = 0; k < j; k++)
			{
				str[k] = string[i];
				i++;
			}
			str[k] = '\0';
	                i--;
                	pushRPN(&head, atof(str)); 			
		}
		else
		{
                	;       // exception
		}
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

//	printf("%d\n", getSizeStackRPN(head));
//      printRPN(head);
//    	getchar();
	
    }

    if (getSizeStackRPN(head) != 1)
    {
    	;       // exception	
    }

    return popRPN(&head);
}

