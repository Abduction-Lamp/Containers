//
// Created by Vladimir
//
                     
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "List.h"



static void deleteItem(struct List *item)
{
	if (item->word != NULL)
    {
        free(item->word);
    }
}



struct List *addList(struct List *head, const char *string, int keyCount)
{
    struct List *list = NULL;

    if (strlen(string) > 0)
    {
        list = (struct List *)malloc(sizeof(struct List));

        list->word = (char *)malloc(sizeof(char) * (strlen(string) + 1));
        strcpy(list->word, string);
        list->key = keyCount;
        list->next = head;
    }

    return list;
}


void printList(struct List *head)
{
    int i = 0;

    puts("\n");
    while (head != NULL)
    {
        i++;
        printf("%d\t Key: %d \t%s\n", i, head->key, head->word);

        head = head->next;
    }
}


struct List * findItemList(struct List *head, int keyFind)
{
	struct List *current = head;
	
	while(current != NULL)
	{
		if (current->key == keyFind)
		{
			break;
		}
		current = current->next;
	}
	return current;
}


/*
 * The arguments to the function **head and **item take the address of a pointer to head and
 * address of a pointer to the deleted element List. This is required to return values through arguments.
 *
 * */
_Bool removeItemList(struct List **head, struct List **item)
{
	_Bool flag = false;
    struct List *current = *head;

	if (*head != NULL && *item != NULL)
	{
		if (*head == *item)
		{
			deleteItem(*item);

			*head = (*item)->next;
			(*item)->next = NULL;

			free(*item);
			*item = NULL;

			flag = true;
		}
		else
		{
			while (current->next != NULL)
			{
				if (current->next == *item)
				{
					deleteItem(*item);

					current->next = (*item)->next;
                    (*item)->next = NULL;

                    free(*item);
					*item = NULL;

					flag = true;
					break;					
				}
				current = current->next;
			}
		}     
	}
    else
    {
        flag = false;
    }

    return flag;
}


_Bool deleteList(struct List **head)
{
	struct List *current = *head;

	while (current->next != NULL)
	{
		while (current->next->next != NULL)
		{
			current = current->next;
		}                                         

		deleteItem(current->next);
		free(current->next);

		current->next = NULL;
		current = *head;
	}
                                   
	deleteItem(*head);
	free(*head);	
	
	*head = NULL;

    return true;  			// do the checkup
}


int getSizeList(struct List *head)
{
	int i = 0;
	if (head != NULL)
	{
		i++;
		while (head->next != NULL)
		{
			i++;
			head = head->next;
		}
	}

	return i;
}


struct List * getItemList(struct List *head, int i)
{
    int count = 0;

    if (i < getSizeList(head) && i > -1)
    {
        while (count != i)
        {
            head = head->next;
            count++;
        }
    }
    else
    {
        head = NULL;
    }

    return head;
}

