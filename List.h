//
// Created by Vladimir
//

#ifndef CONTAINERS_LIST_H
#define CONTAINERS_LIST_H

/*
 * In the main program you want to implement the head element points to the start of the list
 *
 * For example:
 *  List *listHead = NULL;
 *
 * */

struct List
{
    char    *word;
    int     key;

    struct List *next;
};


struct List * listAdd(struct List *head, const char *string, int keyCount);

struct List * listFindItem(struct List *head, int keyFind);
struct List *listGetItem(struct List *head, int i);

_Bool listRemoveItem(struct List **head, struct List **item);
_Bool listDelete(struct List **head);

void listPrint(struct List *head);
int listSize(struct List *head);

#endif //CONTAINERS_LIST_H

