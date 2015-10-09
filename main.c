#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "List.h"


int main(void)
{
    struct List *listHead = NULL;
    struct List *listFind = NULL;

    listHead = addList(listHead, "cosmos", 	strlen("cosmos"));
    listHead = addList(listHead, "star", 	strlen("star"));
    listHead = addList(listHead, "physics", 	strlen("physics"));
    listHead = addList(listHead, "mathematics", strlen("mathematics"));
    listHead = addList(listHead, "planet", 	strlen("planet"));
    listHead = addList(listHead, "algorithm", 	strlen("algorithm"));
    listHead = addList(listHead, "science", 	strlen("science"));

    
    system("cls");	

    printList(listHead);
/*
    if (listFind = findItemList(listHead, 4))
    {
    	printf("\nFIND key = %d: \t%s\n", listFind->key, listFind->word);
    }

    if (removeItemList(listHead, listFind))
    {
    	printList(listHead);	
    }
 */
    if (listFind = findItemList(listHead, 7))
    {
    	//printf("\nFIND key = %d: \t%s\n", listFind->key, listFind->word);
    }
    
    if (removeItemList(listHead, listFind))
    {
    	printList(listHead);	
    }
	
    //<
    puts("\n\nExit");
    getchar();
	
    return 0;
}
