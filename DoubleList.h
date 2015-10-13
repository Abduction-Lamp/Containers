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


struct DoubleList * addDoubleListFirst(struct DoubleList *head, const char *string, int keyCount);
struct DoubleList * addDoubleListLast(struct DoubleList *head, const char *string, int keyCount);
		    
struct DoubleList * findItemDoubleList(struct DoubleList *head, int keyFind);
_Bool removeItemDoubleList(struct DoubleList **head, struct DoubleList **item);
_Bool deleteDoubleList(struct DoubleList **head);
void printDoubleList(struct DoubleList *head);

#endif //DOUBLELIST_H_

