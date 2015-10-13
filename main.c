#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "List.h"
#include "DoubleList.h"


int main(void)
{

    struct List *listHead = NULL;
    struct List *listFind = NULL;

    struct DoubleList *doubleListHead = NULL;
    struct DoubleList *doubleListFind = NULL;




    // <<<<<<<<<< List <<<<<<<<<<

    listHead = addList(listHead, "cosmos",      strlen("cosmos"));
    listHead = addList(listHead, "star", 	    strlen("star"));
    listHead = addList(listHead, "physics", 	strlen("physics"));
    listHead = addList(listHead, "mathematics", strlen("mathematics"));
    listHead = addList(listHead, "planet", 	    strlen("planet"));
    listHead = addList(listHead, "algorithm", 	strlen("algorithm"));
    listHead = addList(listHead, "science", 	strlen("science"));


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
       	                                                                                      
    doubleListHead = addDoubleListLast(doubleListHead,  "HabraHabr",	strlen("HabraHabr"));	                                                                                      
    doubleListHead = addDoubleListFirst(doubleListHead, "Yandex",	    strlen("Yandex"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Google",	    strlen("Google"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Instagram",	strlen("Instagram"));
    doubleListHead = addDoubleListFirst(doubleListHead, "Apple",	    strlen("Apple"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Facebook",	    strlen("Facebook"));
    doubleListHead = addDoubleListFirst(doubleListHead, "vk",		    strlen("vk"));
    doubleListHead = addDoubleListLast(doubleListHead, 	"Microsoft",	strlen("Microsoft"));    
    doubleListHead = addDoubleListFirst(doubleListHead, "Twitter",	    strlen("Twitter"));
   	

    printDoubleList(doubleListHead);
    printf("\nSize DoubleList = %d", getSizeDoubleList(doubleListHead));




    //<
    puts("\n\nExit");
    getchar();
	
    return 0;
}
