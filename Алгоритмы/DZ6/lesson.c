#include <stdio.h>
#include <stdlib.h>
/* Int int data type you need */
typedef int T; /* type of stored data */
typedef int hashTableIndex; /* index in the hash table */
#define compEQ(a, b) (a==b) // Define a directive for comparing two values

typedef struct Node_ {
	T data; /* struc */
	struct Node_ * next; /* next node */
} Node;

//typedef struct Node_ Node;
Node **hashTable;
int hashTableSize;

hashTableIndex hash(T data) {
	/*************************************
	* X e sh - f u nk c i n m e n d a n d a n d a n * * ********* **************************/ 
		return (data % hashTableSize);
}

Node *insertNode (T data) {
	Node *p, *p0; //struct
	hashTableIndex bucket; //int
	/************************************************** * * Distribute the node for the data and put in the table * * ******************** ******************************/
	/* Insert a node at the beginning of the table */
	bucket = hash(data); // calculate the block number 
	p = (Node *)malloc(sizeof (Node));
	if (p == 0) {
		//In the standard error stream, we display a message about insufficient memory 
		fprintf (stderr, "out of memory (insertNode) \n");
		exit (1);
	}

//Remember the current value of the pointer of the found block
	p0 = hashTable[bucket];
//In the found block, write the new element 
	hashTable[bucket] = p;
//We connect the new element with the old
	p->next = p0;
// Write data to a new element 
	p->data = data;
	return p;
}

/* Delete node */
void deleteNode (T data) {
	Node *p0, *p;
	hashTableIndex bucket;
	/********************************************** * delete the node containing the data from the table * * ****************************** **************/
	/* Find the node */
	p0 = 0;
	bucket = hash(data);
	p = hashTable[bucket];
	while(p && !compEQ(p->data, data)){
		p0 = p;
		p = p->next;
	}
	if (!p)
		return;
	/* P found node to delete, delete it from the list */ 
	if(p0)
		// not the first, p0 points to the previous one
		p0->next = p->next;
	else
		// first in the chain
		hashTable [bucket] = p->next;
		free (p);
}

Node * findNode (T data) {
	Node * p;
/**************************************** * location of the node containing Data * * ***************************************/
	p = hashTable [hash (data)];
	while(p &&! compEQ(p-> data, data))
		p = p->next; 
	return p;
} 

void printTable (int size) {
	Node *p;
	for (int i = 0; i <size; i ++) {
		p = hashTable[i];
		while (p){
			printf ("% 5d", p-> data);
			p = p-> next;
		}
		printf ("\n");
	}
}

int main (int argc, char * * argv) {
	int i, *a, maxnum, random;
	if (argc < 2) {
		printf("incorrect command line \ncommand line maxnum hashTableSize[random] \nSample: \n");
		printf("hashTable 2000 100 \n");
		printf("Create 2000 records, hastTable = 100, fill sequense numbers \n");
		printf("or 4000 200 r \n");
		printf("Create 4000 records, hastTable = 200, fill random numbers \n");
		exit(0); //Exit without error
	}
	maxnum = atoi (argv [1]);
	hashTableSize = atoi (argv [2]);
	random = argc > 3;
	printf("random = %d\n", random);
	if ((a = (int *) malloc (maxnum * sizeof (*a))) == 0) {
		fprintf (stderr, "out of memory (a) \n");
		exit (1);
	}
	if ((hashTable = (Node **) calloc (hashTableSize, sizeof (Node *))) == 0) {
		fprintf (stderr, "out of memory (hashTable) \n");
		exit (1);
	}
	if (random) {/* random */
		// fill "a" with random numbers
		for (i = 0; i <maxnum; i ++)
			a [i] = rand ()% 100;
		printf ("ran ht,%d items,%d hashTable \n", maxnum, hashTableSize);
	}else{ // Fill with serial data
		for (i = 0; i <maxnum; i ++)
			a[i] = i;
		printf ("seq ht,%d items,%d hashTable \n", maxnum, hashTableSize);
	}
	for (i = 0; i <maxnum; i ++)
		insertNode(a[i]);

	printTable (hashTableSize);
	for (i = maxnum - 1; i >= 0; i--)
		findNode (a [i]);

	for (i = maxnum - 1; i>= 0; i--)
		deleteNode (a [i]);
	getchar ();
	return 0; 
}
