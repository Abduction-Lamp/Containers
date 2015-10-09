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


struct List * addList(struct List *head, const char *string, int keyCount);
struct List * findItemList(struct List *head, int keyFind);
_Bool removeItemList(struct List **head, struct List **item);
_Bool deleteList(struct List *head);
void printList(struct List *head);

#endif //CONTAINERS_LIST_H

