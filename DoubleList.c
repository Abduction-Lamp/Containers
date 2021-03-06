//
// Created by Vladimir
//
                     
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "DoubleList.h"



struct DoubleList * doubleListAddFirst(struct DoubleList *head, const char *string, int keyCount)
{
	struct DoubleList *doubleList = NULL;

	if (strlen(string) > 0)
	{
		doubleList = (struct DoubleList *)malloc(sizeof(struct DoubleList));		
		if (doubleList != NULL)
		{
			doubleList->word = (char *)malloc(sizeof(char) * (strlen(string) + 1));	
			if (doubleList->word != NULL)
			{
				strcpy(doubleList->word, string);
				doubleList->key = keyCount;
				
				doubleList->next = head;
				doubleList->prev = NULL;

				if (head != NULL)
				{
					head->prev = doubleList;
				}
			}
			else
			{
				free(doubleList);
				doubleList = NULL;	
			} 
		} 
	}

	return doubleList;
}


struct DoubleList * doubleListAddLast(struct DoubleList *head, const char *string, int keyCount)
{
	struct DoubleList *doubleList = NULL;
	struct DoubleList *current = head;
	
	if (head == NULL)
	{
		head = doubleListAddFirst(head, string, keyCount);
	}
	else
	{
		if (strlen(string) > 0)
		{     	
			doubleList = (struct DoubleList *)malloc(sizeof(struct DoubleList));
			if (doubleList != NULL)
			{
				doubleList->word = (char *)malloc(sizeof(char) * (strlen(string) + 1));
				if (doubleList->word != NULL)
				{
			
					strcpy(doubleList->word, string);
					doubleList->key = keyCount;
				
					while (current->next != NULL)
					{
						current = current->next;
					}
                                
					doubleList->next = NULL;
					doubleList->prev = current;
					current->next = doubleList;
				}
				else
				{                         
					free(doubleList);
//					doubleList = NULL;
				} 
			} 
		}
	}

	return head; 
}


struct DoubleList * doubleListFindItem(struct DoubleList *head, int keyFind)
{
	while (head != NULL)
	{
		if (head->key == keyFind)
		{                   
			break;
		}
		head = head->next;
	}
	
	return head;
}


struct DoubleList * doubleListGetItem(struct DoubleList *head, int i)
{
	int count = 0;

	if (i < doubleListSize(head) && i > -1)
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


_Bool doubleListRemoveItem(struct DoubleList **head, struct DoubleList **item)
{
	struct DoubleList *current = *head;
	_Bool flag = false;

	if (*head != NULL && *item != NULL)
	{
		if (*head == *item)
		{
			if ((*head)->word != NULL)
			{
				free((*head)->word);
			}

			*head = (*item)->next;
			if (*head != NULL)
			{
				(*head)->prev = NULL;
			}

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
					if (current->next->word != NULL)
					{
						free(current->next->word);
					}
	
					current->next = (*item)->next;  // current->next->next
					if (current->next != NULL)
					{
						current->next->prev = current;
					}
					
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


_Bool doubleListDelete(struct DoubleList **head)
{
	struct DoubleList *current = *head;
//	_Bool flag = false;

	while (current->next != NULL)
	{       		
		current = current->next;
		if (current->prev->word != NULL)
		{
			free(current->prev->word);
		}
		free(current->prev);
//		*head = current;
	}
	if (current->word != NULL)
	{
		free(current->word);
	}
	free(current);
	*head = NULL;

	return true;	
}


void doubleListPrint(struct DoubleList *head)
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


void doubleListPrintEnd(struct DoubleList *head)
{
	int i = 0;

	puts("\n");
	while (head->next != NULL)
	{
		head = head->next;
	}
	
	while (head != NULL)
	{
		i++;
		printf("%d\t Key: %d \t%s\n", i, head->key, head->word);
		
		head = head->prev;
	}
}


int doubleListSize(struct DoubleList *head)
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

