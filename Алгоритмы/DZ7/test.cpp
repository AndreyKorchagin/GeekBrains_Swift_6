//#include "stdafx.h"
#include <iostream>
using namespace std;
const int n = 5;
int i, j;
//матрица смежности графа
int GM[n][n] =
{
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{0, 1, 0, 0, 1},
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0}
};
//поиск в ширину
void BFS(bool *visited, int unit){
	int *queue=new int[n];
	int count, head;
	for (i = 0; i < n; i++){
		queue[i] = 0;
	}
	count = 0;
	head = 0;
	queue[count++] = unit;
	visited[unit] = true;
	while (head < count){
		unit = queue[head++];
		cout << unit + 1 << " ";
		for (i = 0; i < n; i++)
			if (GM[unit][i] && !visited[i]){
				queue[count++] = i;
				visited[i] = true;
			}
		}
	
	delete []queue;
	}
//главная функция
int main(){
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Стартовая вершина >> ";
	cin >> start;
	bool *visited = new bool[n];
	cout<<"Матрица смежности графа: "<<endl;
	for (i = 0; i < n; i++){
		visited[i] = false;
		for (j = 0; j<n; j++)
			cout<<" " << GM[i][j];
		cout << endl;
	}
	cout << "Порядок обхода: ";
	BFS(visited, start-1);
	delete []visited;
	//system("pause>>void");
}