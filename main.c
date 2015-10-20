#include <stdio.h>
#include <string.h>

#include "List.h"
#include "DoubleList.h"
#include "Stack.h"
#include "RPN.h"


int main(void)
{

    struct List *listHead = NULL;
    struct List *listFind = NULL;

    struct DoubleList *doubleListHead = NULL;
    struct DoubleList *doubleListFind = NULL;

    struct Stack *stackHead = NULL;

    double result;



    // <<<<<<<<<< List <<<<<<<<<<

    listHead = addList(listHead, "cosmos",      (int)strlen("cosmos"));
    listHead = addList(listHead, "star", 	    (int)strlen("star"));
    listHead = addList(listHead, "physics", 	(int)strlen("physics"));
    listHead = addList(listHead, "mathematics", (int)strlen("mathematics"));
    listHead = addList(listHead, "planet", 	    (int)strlen("planet"));
    listHead = addList(listHead, "algorithm", 	(int)strlen("algorithm"));
    listHead = addList(listHead, "science", 	(int)strlen("science"));


    printList(listHead);


    // Remove element in the middle
    if ((listFind = findItemList(listHead, 4)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s\n", listFind->key, listFind->word);
    }
    if (removeItemList(&listHead, &listFind))
    {
    	printList(listHead);	
    }

    // Remove element in the head
    if ((listFind = findItemList(listHead, 7)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s\n", listFind->key, listFind->word);
    }
    if (removeItemList(&listHead, &listFind))
    {
        printList(listHead);
    }

    printf("\nSize List = %d", getSizeList(listHead));


    // Delete all List
    deleteList(&listHead);





    // <<<<<<<<<< Double List <<<<<<<<<<
       	                                                                                      
    doubleListHead = addDoubleListLast(doubleListHead,  "HabraHabr",	(int)strlen("HabraHabr"));
    doubleListHead = addDoubleListFirst(doubleListHead, "Yandex",	    (int)strlen("Yandex"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Google",	    (int)strlen("Google"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Instagram",	(int)strlen("Instagram"));
    doubleListHead = addDoubleListFirst(doubleListHead, "Apple",	    (int)strlen("Apple"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Facebook",	    (int)strlen("Facebook"));
    doubleListHead = addDoubleListFirst(doubleListHead, "vk",		    (int)strlen("vk"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Microsoft",	(int)strlen("Microsoft"));
    doubleListHead = addDoubleListFirst(doubleListHead, "Twitter",	    (int)strlen("Twitter"));
   	
    // Print DoubleList
    puts("\n\n");
    printDoubleList(doubleListHead);
    printEndDoubleList(doubleListHead);

    // Print Size DoubleList
    printf("\nSize DoubleList = %d\n", getSizeDoubleList(doubleListHead));


    // Find
    if ((doubleListFind = findItemDoubleList(doubleListHead, 2)) != NULL)
    {
    	printf("\nFIND key = %d: \t%s", doubleListFind->key, doubleListFind->word);
    }

    // Remove element in the middle (Find == Get)
    if ((doubleListFind = getItemDoubleList(doubleListHead /*NULL*/, 5)) != NULL)
    {
    	printf("\nGET DoubleList: \t%d\t%s", doubleListFind->key, doubleListFind->word);
    }
    if (removeItemDoubleList(&doubleListHead, &doubleListFind))
    {
	printDoubleList(doubleListHead);
	printEndDoubleList(doubleListHead);
    }
 
    // Delete All DoubleList	                              
    deleteDoubleList(&doubleListHead);







    // <<<<<<<<<< Stack <<<<<<<<<<

    push(&stackHead, '9');
    push(&stackHead, '4');
    push(&stackHead, '#');
    push(&stackHead, 'G'); 
    push(&stackHead, '*');
    push(&stackHead, 'W');

	
    puts("\n\n\n");	
    printf("Size Stack = %d\n\n", (int)getSizeStack(stackHead));

    while (stackHead != NULL)
    {
        printf("\t%c\n", pop(&stackHead));
    }

    printf("\nSize Stack = %d\n\n", (int)getSizeStack(stackHead));


    push(&stackHead, '9');
    push(&stackHead, '4');
    push(&stackHead, '#');
    push(&stackHead, 'G'); 
    push(&stackHead, '*');
    push(&stackHead, 'W');

    deleteStack(&stackHead);
    printf("\nSize Stack = %d\n\n", (int)getSizeStack(stackHead));
	



    result = callRPN("752-4*+");
    printf("\nresult = %f\n", result);

    //<
    puts("\n\nExit");
    getchar();
	
    return 0;
}
