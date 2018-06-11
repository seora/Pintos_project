#include <stdio.h>
#include <string.h>

#include "threads/thread.h"
#include "threads/malloc.h"
#include "threads/palloc.h"
#include <bitmap.h>
#include "projects/memalloc/memalloctest.h"




void run_memalloc_test(char **argv UNUSED)
{
	size_t i;
	char* dynamicmem[11];
							// allocate pages 3-3-4-2-4-2-2-3

	dynamicmem[0] = (char *) malloc (4027*3);			
	if (dynamicmem[0] != NULL)  {
	memset(dynamicmem[0], 0x00, (4027*3));
	printf("3 pages are allocated\n");
	palloc_get_status(0);
	}

	dynamicmem[1] = (char *) malloc (4027*(3));			
	if (dynamicmem[1] != NULL)  {
	memset(dynamicmem[1], 0x00, (4027*3));
	printf("3 pages are allocated\n");
	palloc_get_status(0);
	}
	
	dynamicmem[2] = (char *) malloc (4027*(4));
	if (dynamicmem[2] != NULL) {
	memset (dynamicmem[2],0x00, 4027*(4));
	printf ("4 pages are allocated \n");
	palloc_get_status (0);
	}

	dynamicmem[3] = (char *) malloc (4027*(2));
	if (dynamicmem[3] != NULL) {
	memset (dynamicmem[3],0x00, 4027*(2));
	printf ("2 pages are allocated \n");
	palloc_get_status (0);
	}

	dynamicmem[4] = (char *) malloc (4027*(4));
	if (dynamicmem[4] != NULL) {	
	memset (dynamicmem[4],0x00, 4027*(4));
	printf ("4 pages are allocated \n");
	palloc_get_status (0);
	}

	dynamicmem[5] = (char *) malloc (4027*(2));
	if (dynamicmem[5] != NULL) {	
	memset (dynamicmem[5],0x00, 4027*(2));
	printf ("2 pages are allocated \n");
	palloc_get_status (0);
	}

	dynamicmem[6] = (char *) malloc (4027*(2));
	if (dynamicmem[6] != NULL) {	
	memset (dynamicmem[6],0x00, 4027*(2));
	printf ("2 pages are allocated \n");
	palloc_get_status (0);
	}

	dynamicmem[7] = (char *) malloc (4027*(3));
	if (dynamicmem[7] != NULL) {	
	memset (dynamicmem[7],0x00, 4027*(3));
	printf ("3 pages are allocated \n");
	palloc_get_status (0);
	}

	for(int j=0; j<8;j = j+2){			//Release even index pages
	free(dynamicmem[j]);
	thread_sleep(100);

	}
	printf("page status \n");
	palloc_get_status (0);
	
							//Allocate pages 4-2-3
	dynamicmem[8] = (char *) malloc (4027*(4));
	if (dynamicmem[8] != NULL) {	
	memset (dynamicmem[8],0x00, 4027*(4));
	//printf ("4 pages are allocated \n");
	//palloc_get_status (0);
	}


	dynamicmem[9] = (char *) malloc (4027*(2));
	if (dynamicmem[9] != NULL) {	
	memset (dynamicmem[9],0x00, 4027*(2));
	//printf ("2 pages are allocated \n");
	//palloc_get_status (0);
	}

	dynamicmem[10] = (char *) malloc (4027*(3));
	if (dynamicmem[10] != NULL) {	
	memset (dynamicmem[9],0x00, 4027*(3));
	//printf ("3 pages are allocated \n");
	palloc_get_status (0);
	}


	
	

}



