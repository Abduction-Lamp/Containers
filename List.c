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
		free(item->word);
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
        head = list;
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


_Bool removeItemList(struct List *head, struct List *item) 
{
	_Bool flag = false;
	struct List *current = head;

	if (head != NULL)
	{
		if (head == item)
		{
			puts("\n123");
			printf("\n%S", head->word);
			printf("\n%S", head->next->word);

			head = item->next;
			deleteItem(item);			
			item->next = NULL;
			item = NULL;

			flag = true;
		}
		else
		{
                	while (current->next != NULL)
			{
				if (current->next == item)
				{
					deleteItem(item);
					current->next = item->next;
					item->next = NULL;
                                        item = NULL;

					flag = true;
					break;					
				}
				current = current->next;
			}
		}     
	}
	

	return flag;	
}

_Bool deleteList(struct List *head) {}
        