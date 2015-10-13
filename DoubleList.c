//
// Created by Vladimir
//
                     
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "DoubleList.h"


struct DoubleList * addDoubleListFirst(struct DoubleList *head, const char *string, int keyCount)
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


struct DoubleList * addDoubleListLast(struct DoubleList *head, const char *string, int keyCount)
{
	struct DoubleList *doubleList = NULL;
	struct DoubleList *current = head;
	
	if (head == NULL)
	{
		head = addDoubleListFirst(head, string, keyCount);
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
					doubleList = NULL;	
				} 
			} 
		}
	}

	return head; 
}


struct DoubleList * findItemDoubleList(struct DoubleList *head, int keyFind)
{

}


_Bool removeItemDoubleList(struct DoubleList **head, struct DoubleList **item)
{

}


_Bool deleteDoubleList(struct DoubleList **head)
{

}


void printDoubleList(struct DoubleList *head)\
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


int getSizeDoubleList(struct DoubleList *head)
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

