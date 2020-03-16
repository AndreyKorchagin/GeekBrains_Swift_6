#include "stdio.h"
#include "string.h"
#include "stdlib.h"


typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

void menu(void);
void task1(void);
void task2(void);
void task3(void);
void printTree(Node *root);
Node* getFreeNode(int value, Node *parent);
void insert(Node **head, int value);
void preOrderTravers(Node* root);
void inOrderTravers(Node* root);
void postOrderTravers(Node* root);
void treeSearch(Node* root, int value);


#define LEN 255

int main(int argc, char const *argv[]){
	menu();
	return 0;
}

void menu(void){
	int n;
	while(1){
		printf("task 1 - 1\ntask 2 - 2\ntask 3 - 3\nquit - 4\n");
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
				exit(1);
				break;
		}
	}
}

void task1(void){
	char buff[255];
	printf("vvedite stroky\n");
	scanf("%s", buff);
	int len = strlen(buff);
	unsigned int hash = 0;
	for (int i = 0; i < len; ++i){
		hash += buff[i];
	}
	printf("hash = 0x%X\n", hash);
}

void task2(void){
	Node *Tree = NULL;

	int count;
	printf("vvedite colichesto potomkov\n");
	scanf("%d", &count);          // Считываем количество записей
	int i;
	//int value[7] = {8, 6, 1, 3, 10, 20, 40};
	count = 7;
	for (i = 0; i < count; i++){
		int value;
		scanf("%d", &value);
		insert(&Tree, value);
	}
	printTree(Tree);
	//test(Tree);
	printf("\nPreOrderTravers:\n");
	preOrderTravers(Tree);
	printf("\n");
	printf("\nInOrderTravers:\n");
	inOrderTravers(Tree);
	printf("\n");
	printf("\nPostOrderTravers:\n");
	postOrderTravers(Tree);
	printf("\n");
	printf("vvedite chislo dlay poiska\n");
	int x;
	scanf("%d", &x);
	treeSearch(Tree, x);
	getchar();
}

void task3(void){

}

void printTree(Node *root){
	if (root){
		printf("%d", root->data);
		if (root->left || root->right){
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

Node* getFreeNode(int value, Node *parent){
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

void insert(Node **head, int value){
	Node *tmp = NULL;
	if (*head == NULL){
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp){
		if (value > tmp->data){
			if (tmp->right){
				tmp = tmp->right;
				continue;
			}else{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data){
			if (tmp->left){
				tmp = tmp->left;
				continue;
			}else{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else{
			exit(2);                                // дерево построено неправильно
		}
	}
}

void preOrderTravers(Node* root){
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(Node* root){
	if (root) {
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(Node* root){
	if (root) {		
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

void treeSearch(Node* root, int value){
	if (root){
		if(value == root->data){
			printf("chislo naydeno - %d\n", root->data);
			return;
		} else if(value > root->data){
			treeSearch(root->right, value);
		} else{
			treeSearch(root->left, value);
		}
	}else {
		printf("derevo pustoe\n");
		return;
	}
}