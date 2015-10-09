#include <stdio.h>
#include <stdio.h>

#include "List.h"


int main(void)
{
    struct List *listHead = NULL;

    addList(listHead, "cosmos");
    addList(listHead, "star");
    addList(listHead, "physics");
    addList(listHead, "mathematics");

    if (listHead == NULL)
        puts("\n1");

    printList(listHead);


	
    //<
    getchar();
	
    return 0;
}
