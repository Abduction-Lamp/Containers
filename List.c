//
// Created by Vladimir
//

#include <MacTypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "List.h"

struct List *addList(struct List *head, const char *string)
{
    struct List *list = NULL;

    if (strlen(string) > 0)
    {
        list = (struct List *)malloc(sizeof(struct List));

        list->word = (char *)malloc(sizeof(char) * (strlen(string) + 1));
        strcpy(list->word, string);

        list->key = 1;

        list->next = head;
        head = list;

        printf("%s", head->word);
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
        printf("%d\t Key: %d\t%s\n", i, head->key, head->word);

        head = head->next;
    }
}
