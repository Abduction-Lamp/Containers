#include <stdio.h>
#include <string.h>

#include "List.h"
#include "DoubleList.h"
#include "Stack.h"
#include "RPN.h"
#include "Queue.h"
#include "BinaryTree.h"



int main(void)
{

    struct List *listHead = NULL;
    struct List *listFind = NULL;

    struct DoubleList *doubleListHead = NULL;
    struct DoubleList *doubleListFind = NULL;

    struct Stack *stackHead = NULL;

    double result;

    struct Queue que;

    bTree treeRoot = NULL;
    bTree treeSearch = NULL;




    // <<<<<<<<<< List <<<<<<<<<<

    puts("\n\n***\tList");

    listHead = listAdd(listHead, "cosmos", (int) strlen("cosmos"));
    listHead = listAdd(listHead, "star", (int) strlen("star"));
    listHead = listAdd(listHead, "physics", (int) strlen("physics"));
    listHead = listAdd(listHead, "mathematics", (int) strlen("mathematics"));
    listHead = listAdd(listHead, "planet", (int) strlen("planet"));
    listHead = listAdd(listHead, "algorithm", (int) strlen("algorithm"));
    listHead = listAdd(listHead, "science", (int) strlen("science"));

    listPrint(listHead);

    // Remove element in the middle
    if ((listFind = listFindItem(listHead, 4)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s", listFind->key, listFind->word);
    }
    if (listRemoveItem(&listHead, &listFind))
    {
        listPrint(listHead);
    }

    // Remove element in the head
    if ((listFind = listFindItem(listHead, 7)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s", listFind->key, listFind->word);
    }
    if (listRemoveItem(&listHead, &listFind))
    {
        listPrint(listHead);
    }

    printf("\nSize List = %d", listSize(listHead));

    // Delete all List
    listDelete(&listHead);





    // <<<<<<<<<< Double List <<<<<<<<<<

    puts("\n\n\n***\tDouble List");

    doubleListHead = doubleListAddLast(doubleListHead, "HabraHabr", (int) strlen("HabraHabr"));
    doubleListHead = doubleListAddFirst(doubleListHead, "Yandex", (int) strlen("Yandex"));
    doubleListHead = doubleListAddLast(doubleListHead, "Google", (int) strlen("Google"));
    doubleListHead = doubleListAddLast(doubleListHead, "Instagram", (int) strlen("Instagram"));
    doubleListHead = doubleListAddFirst(doubleListHead, "Apple", (int) strlen("Apple"));
    doubleListHead = doubleListAddLast(doubleListHead, "Facebook", (int) strlen("Facebook"));
    doubleListHead = doubleListAddFirst(doubleListHead, "vk", (int) strlen("vk"));
    doubleListHead = doubleListAddLast(doubleListHead, "Microsoft", (int) strlen("Microsoft"));
    doubleListHead = doubleListAddFirst(doubleListHead, "Twitter", (int) strlen("Twitter"));
   	
    // Print DoubleList
    doubleListPrint(doubleListHead);
    doubleListPrintEnd(doubleListHead);

    // Print Size DoubleList
    printf("\nSize DoubleList = %d\n", doubleListSize(doubleListHead));

    // Find
    if ((doubleListFind = doubleListFindItem(doubleListHead, 2)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s\n", doubleListFind->key, doubleListFind->word);
    }

    // Remove element in the middle (Find == Get)
    if ((doubleListFind = doubleListGetItem(doubleListHead /*NULL*/, 5)) != NULL)
    {
    	printf("\nGET DoubleList: \t%d\t%s", doubleListFind->key, doubleListFind->word);
    }
    if (doubleListRemoveItem(&doubleListHead, &doubleListFind))
    {
        doubleListPrint(doubleListHead);
        doubleListPrintEnd(doubleListHead);
    }
 
    // Delete All DoubleList	                              
    doubleListDelete(&doubleListHead);





    // <<<<<<<<<< Stack <<<<<<<<<<

    puts("\n\n\n***\tStack\n");

    push(&stackHead, '9');
    push(&stackHead, '4');
    push(&stackHead, '#');
    push(&stackHead, 'G'); 
    push(&stackHead, '*');
    push(&stackHead, 'W');
    printf("Size Stack = %d\n", (int)getSizeStack(stackHead));

    while (stackHead != NULL)
    {
        printf("\t%c\n", pop(&stackHead));
    }
    printf("\nSize Stack = %d", (int)getSizeStack(stackHead));

    push(&stackHead, '9');
    push(&stackHead, '4');
    push(&stackHead, '#');
    push(&stackHead, 'G'); 
    push(&stackHead, '*');
    push(&stackHead, 'W');

    deleteStack(&stackHead);
    printf("\nSize Stack = %d", (int)getSizeStack(stackHead));





    // <<<<<<<<<< RPN <<<<<<<<<<
    puts("\n\n\n***\tRPN + Stack");

    result = callRPN("36 7 204 + * 77 55 - 11 * / 1_ 3 + +");
    printf("\nresult = %f\n", result);

    result = callRPN("3 8 + 5 * 7 9 3 - * +");
    printf("\nresult = %f\n", result);





    // <<<<<<<<<< Queue <<<<<<<<<
    puts("\n\n***\tQueue");

    que.head = NULL;
    que.tail = NULL;	

    queuePush(&que, 65.0);
    queuePush(&que, 5.8);
    queuePush(&que, -77.7);
    queuePush(&que, 211.005);
    queuePush(&que, 0.1041985);

    printf("\nSize Queue = %d\n\n", (int)queueSize(&que));
    while (que.head != NULL)
    {
        printf("\t%f\n", queuePop(&que));
    }

    queuePush(&que, -4.306);
    queuePush(&que, 15.18);
    queuePush(&que, -9.2);
    queuePush(&que, 0.005);
    queuePush(&que, 99.999);
    queuePush(&que, -958.0);
    queuePush(&que, -77.7);
    queuePush(&que, 1.0);
    queuePush(&que, 0.1041985);

    queueDelete(&que);





    // <<<<<<<<<< Binary Tree <<<<<<<<<
    puts("\n\n***\tBinary Tree");

    binaryTreeAdd(&treeRoot, 58);
    binaryTreeAdd(&treeRoot, 17);
    binaryTreeAdd(&treeRoot, 96);
    binaryTreeAdd(&treeRoot, 35);
    binaryTreeAdd(&treeRoot, 5);
    binaryTreeAdd(&treeRoot, 8);
    binaryTreeAdd(&treeRoot, 100);
    binaryTreeAdd(&treeRoot, 77);
    binaryTreeAdd(&treeRoot, 70);
    binaryTreeAdd(&treeRoot, 45);
    binaryTreeAdd(&treeRoot, 59);
    binaryTreeAdd(&treeRoot, 5);
    binaryTreeAdd(&treeRoot, 18);
    binaryTreeAdd(&treeRoot, 8);
    binaryTreeAdd(&treeRoot, 58);
    binaryTreeAdd(&treeRoot, 0);
    binaryTreeAdd(&treeRoot, 88);
    binaryTreeAdd(&treeRoot, 99);
    binaryTreeAdd(&treeRoot, 86);

    treeSearch = binaryTreeSearch(treeRoot, 0);
    if (treeSearch != NULL)
    {
    	printf("Search: %d\n", treeSearch->data);
    }

    puts("");
    binaryTreePrintLRR(treeRoot);
    puts("");
    binaryTreePrintRRL(treeRoot);

    treeSearch = binaryTreeGetLeft(treeRoot);
    if (treeSearch != NULL)
    {
    	printf("\n\nLeft (min): %d\n", treeSearch->data);
    }
    treeSearch = binaryTreeGetRight(treeRoot);
    if (treeSearch != NULL)
    {
    	printf("Right (max): %d\n", treeSearch->data);
    }

    printf("Height Tree = %lu\n", binaryTreeGetHeight(treeRoot));

    treeSearch = NULL;	
    binaryTreeDelete(&treeRoot);


    binaryTreeAdd(&treeRoot, 7);
    binaryTreeAdd(&treeRoot, 3);
    binaryTreeAdd(&treeRoot, 5);
    binaryTreeAdd(&treeRoot, 1);
    binaryTreeAdd(&treeRoot, -1);
    binaryTreeAdd(&treeRoot, 9);

    printf("Height Tree = %lu\n", binaryTreeGetHeight(treeRoot));
    binaryTreeDelete(&treeRoot);



    //<
    puts("\n\nExit");
    getchar();
	
    return 0;
}
