#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

#define T int

typedef struct StackNode{
	int bin;
	struct StackNode* next;
}Node;

typedef struct Queue{
	//int data;
	Node* head;
	Node* tail;
}Queue;

void menu(void);
void push(Node **StackPtr, int data);
void pop(Node **StackPtr);
void pop1(Node **StackPtr);
void list(Node **StackPtr);
Node *copy(Node *StackPtr);
void print(Node **StackPtr);
void len(Node **StackPtr);
void add(Queue **Q, int n);
void del(Queue **Q);
void printq(Queue **Q);
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task6(void);


int main(int argc, char const *argv[]){
	//task1();
	//task2();
	//task3();
	//task4();
	//task5();
	//task6();
	menu();
	return 0;
}

void menu(void){
	int n;
	while(1){
		printf("task 1 - 1\ntask 2 - 2\ntask 3 - 3\ntask 4 - 4\ntask 5 - 5\ntask 6 - 6\nquit - 7");
		scanf("%d", &n);
		switch(n){
			case 1:
				task1();
				break;
			case 2:
				task2();
				break;
			case 3:
				task3();
				break;
			case 4:
				task4();
				break;
			case 5:
				task5();
				break;
			case 6:
				task6();
				break;
			case 7:
				exit(1);
				break;
		}
	}
}

void task1(void){
	printf("Hello World\n");
	Node *StackPtr = NULL;
	int dec;
	printf("Введите число в 10-ой системе\n");
	scanf("%d", &dec);
	while(dec != 0){
		push(&StackPtr ,dec % 2);
		dec /= 2;
	}

	printf("dec = %d bin = ", dec);
	while(StackPtr != NULL){
		pop(&StackPtr);
	}
	printf("\n");

}

void task2(void){
	int i = 0;
	Node *StackPtr = NULL;
	srand(time(NULL));
	while(i != 100){
		getchar();
		i++;
		int r = rand() % 100;
		push(&StackPtr ,r);
	}
	getchar();
}

void task3(void){
	Node *StackPtr = NULL;
	char buff[255];
	printf("vvedite posledovatelnost skobocheck\n");
	scanf("%s", buff);
	int i = 0;
	int status = 0;
	while (i != strlen(buff)){
		//printf("!%d - %c - S -\n", i, buff[i]);
		if ( (StackPtr == NULL) && (buff[i] == '(' || buff[i] == '{' || buff[i] == '[')){
			//printf("1\n");
			push(&StackPtr, (int)buff[i]);
		} else if ( (StackPtr != NULL) && (buff[i] == '(' || buff[i] == '{' || buff[i] == '[')){
			//printf("2\n");
			push(&StackPtr, (int)buff[i]);
		} else if (StackPtr != NULL && buff[i] == ')' && StackPtr->bin == '('){
			//printf("3\n");
			pop1(&StackPtr);
			//printf("33 %d - %c\n", StackPtr->bin, StackPtr->bin);
		} else if (StackPtr != NULL && buff[i] == '}' && StackPtr->bin == '{'){
			//printf("4\n");
			pop1(&StackPtr);
			//printf("33 %d - %c\n", StackPtr->bin, StackPtr->bin);
		} else if (StackPtr != NULL && buff[i] == ']' && StackPtr->bin == '['){
			//printf("5\n");
			pop1(&StackPtr);
			//printf("33 %d - %c\n", StackPtr->bin, StackPtr->bin);
		} else if ( (StackPtr == NULL) && (buff[i] == ')' || buff[i] == '}' || buff[i] == ']') ){
			//printf("break\n");
			status = 1;
			break;
		}
		i++;
		//printf("SP = %d - %c\n", StackPtr->bin, StackPtr->bin);
	}
	if (StackPtr == NULL && status == 0){
		printf("GOOD\n");
	} else {
		printf("NO GOOD\n");
	}
}

void task4(void){
	Node *StackPtr = NULL;
	while(1){
		printf("1 - push | 2 - pop | 3 - copy | 4 - len | menu - 5\n");
		int i;
		int n;
		scanf("%d", &i);
		switch(i){
			case 1:
				scanf("%d", &n);
				push(&StackPtr, n);
				break;
			case 2:
				pop(&StackPtr);
				break;
			case 3:
				printf("newList = \n");
				Node *newList = copy(StackPtr);
				print(&newList);
				break;
			case 4:
				len(&StackPtr);
				break;
			case 5:
				return;
				break;
		}
	}
}

void task5(void){
	Node *StackPtr = NULL;
	char buff[255];
	char outbuff[255];
	memset(buff, 0 ,255);
	memset(outbuff, 0 ,255);
	printf("введите выражение в инфиксной записи\n");
	scanf("%s", buff);
	strncat(buff, "&", 1);
	strncat(outbuff, "&", 1);
	strncat(outbuff, buff, strlen(buff));
	strncpy(buff, outbuff, strlen(outbuff));
	memset(outbuff, 0, 255);
	int len = strlen(buff);
	printf("buff = %s, len = %d\n", buff, len);
	int i = 0;
	while(i != len){
		if (i == 0 && buff[i] == '&'){
			printf("push\n");
			push(&StackPtr, (int)buff[i]);
		} else if (i != 0 && buff[i] >= 48 && buff[i] <= 57){ // mode 1
			strncat(outbuff, &buff[i], 1);
		} else if ( StackPtr->bin == '&' && i != 0 && (	buff[i] == '+' ||
														buff[i] == '-' || 
														buff[i] == '^' || 
														buff[i] == '*' ||
														buff[i] == '/' || 
														buff[i] == '('  )){
			push(&StackPtr, (int)buff[i]);
			strncat(outbuff, " ", 1);
		} else if ( ( StackPtr->bin == '-' || StackPtr->bin == '+' || StackPtr->bin ==  '^')
										&& (	buff[i] == '*' ||
												buff[i] == '/' ||
												buff[i] == '(' )){
			strncat(outbuff, " ", 1);
			push(&StackPtr, (int)buff[i]);
		} else if (buff[i] == '(' && (StackPtr->bin == '*' || StackPtr->bin == '/') ){
			strncat(outbuff, " ", 1);
			push(&StackPtr, (int)buff[i]);
		} else if ( StackPtr->bin == '(' && i != 0 && (	buff[i] == '+' ||
														buff[i] == '-' || 
														buff[i] == '^' || 
														buff[i] == '*' ||
														buff[i] == '/' || 
														buff[i] == '('  )){
			strncat(outbuff, " ", 1);
			push(&StackPtr, (int)buff[i]);
			//strncat(outbuff, " ", 1);
		} else if (buff[i] == ')' && StackPtr->bin == '('){ //mode 3
			pop(&StackPtr);
		} else if ( (buff[i] == '&' || buff[i] == '+' || buff[i] == '-' || buff[i] == '^') && //mode 2
					(StackPtr->bin == '+' || StackPtr->bin == '-' || StackPtr->bin == '^' || StackPtr->bin == '*' || StackPtr->bin == '/') ){
			char t = StackPtr->bin;
			strncat(outbuff, " " , 1);
			strncat(outbuff, &t , 1);
			pop(&StackPtr);
			i--;
		} else if ( (buff[i] == '*' || buff[i] == '/') &&
					(StackPtr->bin == '*' || StackPtr->bin == '/')){
			char t = StackPtr->bin;
			strncat(outbuff, " " , 1);
			strncat(outbuff, &t , 1);
			pop(&StackPtr);
			i--;
		} else if (buff[i] == ')' && (	StackPtr->bin == '+' ||
										StackPtr->bin == '-' || 
										StackPtr->bin == '^' || 
										StackPtr->bin == '*' || 
										StackPtr->bin == '/')){
			char t = StackPtr->bin;
			strncat(outbuff, " " , 1);
			strncat(outbuff, &t , 1);
			pop(&StackPtr);
			i--;
		} else if (buff[i] == '&' && StackPtr->bin == '&'){ //mode 4
			printf("outbuff = %s\n", outbuff);
			break;
		} else if ( (buff[i] == ')' || buff[i] == '&') && StackPtr->bin == '('){ //mode 5
			printf("ERROR\n");
			break;
		}

		i++;
	}

	//printf("outbuff = %s\n", outbuff);

	printf("stack = \n");
	while(StackPtr != NULL){
		pop(&StackPtr);
	}

}

void task6(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	while(1){
		printf("1 - add | 2 - del | 3 - print | 4 - quit\n");
		int i;
		int n;
		scanf("%d", &i);
		switch(i){
			case 1:
				scanf("%d", &n);
				add(&q, n);
				break;
			case 2:
				del(&q);
				break;
			case 3:
				printq(&q);
				break;
			case 4:
				return;
				break;
		}
	}

}

void push(Node **StackPtr, int data){
	Node *new = (Node*)malloc(sizeof(Node));
	if (new == NULL){
		printf("free\n");
		getchar();
		exit(0);
	} else {
		new->bin = data;
		new->next = *StackPtr;
		*StackPtr = new;
	}	
}

void pop(Node **StackPtr){
	if (*StackPtr == NULL){
		printf("Stack is empty\n");
	} else {
		Node *cur = *StackPtr;
		*StackPtr = (*StackPtr)->next;
		printf("%c\n", cur->bin);
		free(cur);
	}
}

void pop1(Node **StackPtr){
	if (*StackPtr == NULL){
		printf("Stack is empty\n");
	} else {
		//printf("test\n");
		Node *cur = *StackPtr;
		//printf("test1\n");
		*StackPtr = (*StackPtr)->next;
		//printf("test2\n");
		free(cur);
		//printf("test3\n");
	}
}

void list(Node **StackPtr){
	printf("%d\n", (*StackPtr)->bin);
}

Node *copy(Node *StackPtr){
	Node* current = StackPtr;
	if (StackPtr == NULL){
		return NULL;
	}else{
		Node *newList = malloc(sizeof(Node));
		newList->bin = current->bin;
		newList->next = copy(current->next);
		return(newList);
	}

}

void print(Node **StackPtr){
	while(*StackPtr != NULL){
		pop(StackPtr);
	}
}

void len(Node **StackPtr){
	int count = 0;
	Node *current = *StackPtr;
	while(current != NULL){
		current = current->next;
		count++;
	}
	printf("len = %d\n", count);
}

void add(Queue **q, int n){
	Node *node = (Node*)malloc(sizeof(Node));
	node->bin = n;
	node->next = NULL;
	if ( (*q)->head && (*q)->tail ){
		(*q)->tail->next = node;
		(*q)->tail = node;
	}else{
		(*q)->tail = node;
		(*q)->head = node;
	}
}

void del(Queue **q){
	if ((*q)->head){
		printf("%d\n", (*q)->head->bin);
		(*q)->head = (*q)->head->next;
	} else {
		printf("empty\n");
	}
}

void printq(Queue **q){
	Node *node = (*q)->head;
	for (; node; node = node->next){
      	printf("%d ", node->bin);
   	}
   	printf("\n");

}