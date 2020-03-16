#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int **graph;
int count;
int *visited;

void menu(void);
void task1(void);
void task2(void);
void task3(void);
//void readGraph(int **graph, int count, FILE *file);
void printGraph(int **graph, int count);
void deleteGraph(int **graph, int count);
void DFS(int start, int **graph, int count, int *visited);
void BFS(int start, int **graph, int count, int *visited);

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
				deleteGraph(graph, count);
				free(visited);
				exit(1);
				break;
		}
	}
}

void task1(void){
	printf("vvedite nazvanie faila\n");
	char file[255];
	//int count;
	//scanf("%s", file);
	memset(file, 0, 255);
	strncpy(file, "graph.txt", 9);
	FILE *fin = fopen(file, "r");
	if (!fin){
		perror("dont open");
	}

	fscanf(fin, "%d", &count);
	//readGraph(graph, count, fin);
	graph = (int**)malloc(sizeof(int*) * count);
	for (int i = 0; i < count; ++i){
		graph[i] = (int*)malloc(sizeof(int) * count);
		for (int j = 0; j < count; ++j){
			fscanf(fin, "%d", &graph[i][j]);
		}
	}
	printGraph(graph, count);
	fclose(fin);
}

void task2(void){
	printGraph(graph, count);
	printf("count = count %d\n", count);
	printf("введите начальную стартовую вершину\n");
	int start;
	scanf("%d", &start);
	visited = (int*)malloc(sizeof(int) * count);
	memset(visited, 0, count);
	DFS(start - 1, graph, count, visited);
	printf("\n");
}

void task3(void){
	printGraph(graph, count);
	printf("введите начальную стартовую вершину\n");
	int start;
	scanf("%d", &start);
	visited = (int*)malloc(sizeof(int) * count);
	memset(visited, 0, count);
	BFS(start - 1, graph, count, visited);
	printf("\n");

}

/*
void readGraph(int **graph, int count, FILE *file){
	graph = (int**)malloc(sizeof(int*) * count);
	for (int i = 0; i < count; ++i){
		graph[i] = (int*)malloc(sizeof(int) * count);
		for (int j = 0; j < count; ++j){
			fscanf(file, "%d", &graph[i][j]);
		}
	}
}*/


void printGraph(int **graph, int count){
	printf("%d\n", count);
	for (int i = 0; i < count; ++i){
		for (int j = 0; j < count; ++j){
			printf("%3d", graph[i][j]);
		}
		printf("\n");
	}
}

void deleteGraph(int **graph, int count){
	for (int i = 0; i < count; ++i){
		free(graph[i]);
	}
	free(graph);
}

void DFS(int start, int **graph, int count, int *visited){
	printf("%d ", start + 1);
	visited[start] = 1;

	for (int i = 0; i < count; ++i){
		if (graph[start][i] != 0 && !visited[i]){
			DFS(i, graph, count, visited);
		}
	}
}

void BFS(int start, int **graph, int count, int *visited){
	for (int i = 0; i < count; ++i){
		visited[i] = 0;
	}
	int queue[count];
	int Count = 0;
	int head = 0;
	queue[Count++] = start;
	visited[start] = 1;
	while(head < Count){
		start = queue[head++];
		printf("%d ", start + 1);
		for (int i = 0; i < count; ++i){
			if(graph[start][i] && !visited[i]){
				queue[Count++] = i;
				visited[i] = 1;
			}
		}
	}

}