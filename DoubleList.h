//
// Created by Vladimir
//

#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_

struct DoubleList
{
    char    *word;
    int     key;

    struct DoubleList *next;
    struct DoubleList *prev;

};


struct DoubleList * doubleListAddFirst(struct DoubleList *head, const char *string, int keyCount);
struct DoubleList * doubleListAddLast(struct DoubleList *head, const char *string, int keyCount);
		    
struct DoubleList * doubleListFindItem(struct DoubleList *head, int keyFind);
struct DoubleList * doubleListGetItem(struct DoubleList *head, int i);

_Bool doubleListRemoveItem(struct DoubleList **head, struct DoubleList **item);
_Bool doubleListDelete(struct DoubleList **head);

void doubleListPrint(struct DoubleList *head);
void doubleListPrintEnd(struct DoubleList *head);
int doubleListSize(struct DoubleList *head);


#endif //DOUBLELIST_H_

