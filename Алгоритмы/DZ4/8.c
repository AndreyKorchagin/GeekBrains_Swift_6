#include "stdio.h"
#include "math.h"
#define N 3
#define M 3

// Доска для ферзей.
// 0 - клетка пустая
// число - номер ферзя
int count = 0;
int board[N][M];
int SearchSolution(int n);
int CheckBoard(int n);
int CheckQueen(int x, int y);
int CheckQueen1(int x, int y, int n);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
void Pause(int key);

int main(){
	Zero(N, M, board);
	SearchSolution(1);
	printf("\n\n");
	Print(N, M, board);
	//getch();
	return 0;
}

int SearchSolution(int n){
	// Если проверка доски возвращает 0, то эта расстановка не подходит
	if (CheckBoard(n) == 0){
		return 0;
	}
	// 9 ферзя не ставим. Решение найдено
	if (n == 5){
		return 1;
	}
	int row;
	int col;
	for (row = 0; row < N; row++){
		for (col = 0; col < M; col++){
			if (board[row][col] == 0){
				// Расширяем test_solution
				board[row][col] = n;
				// Рекурсивно проверяем, ведет ли это к решению.
				printf("SearchSolution - %d\n", n + 1);
				if (SearchSolution(n + 1)){
					return 1;	
				}
				Print(N, M, board);
				// Если мы дошли до этой строки, данное частичное решение
				// не приводит к полному.
				board[row][col] = 0;
			}
		}
	}
	return 0;
}


// Проверка всей доски
int CheckBoard(int n){
	printf("CheckBoard - %d\n", n);
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (board[i][j] != 0){
				//if (CheckQueen(i, j) == 0){
				printf("CheckQueen - %d\n", n);
				if (CheckQueen1(i, j, n) == 0){
					return 0;
				}
			}
		}
	}
	return 1;
}


int CheckQueen1(int x, int y, int n){
	//x, y - передаваемые координаты
	printf("n = %d\n", n);
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			// Если нашли фигуру
			//if (board[i][j] == n - 1 && board[i][j] != 0){
			if (board[i][j] != 0){
				printf("count = %d i = %d j = %d board = %d\n", count, i, j, board[i][j]);
				printf("count = %d x = %d y = %d board = %d", count, x, y, board[i][j]);
				if (!(i == x && j == y)){ // Если это не наша фигура
					printf("\nN =====%d\n", n);
					if (board[i][j] == n - 2){
						printf("\nn - 1\n");
						if ( !(fabs((float)(i - x)) == 1 && fabs((float)(j - y)) == 2) || (fabs((float)(i - x)) == 2 && fabs((float)(j - y)) == 1) ){
							return 0;
						}
						//if ( fabs((float)(i - x)) != 2 && fabs((float)(j - y)) != 1){
						//	return 0;
						//}
					}
					// Лежат на одной вертикали или горизонтали
					printf(" - BAD\n");
				} else {
					printf(" - GOOD1\n\n");
					//return 0;
					//Print(N, M, board);
				}
			}
		}
	}				
	// Если дошли до сюда, то всё в порядке
	count++;
	printf(" - GOOD2\n\n");
	Print(N, M, board);
	return 1;
}

// Проверка определённого ферзя
int CheckQueen(int x, int y){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			// Если нашли фигуру
			if (board[i][j] != 0){
				if (!(i == x && j == y)){ // Если это не наша фигура
					// Лежат на одной вертикали или горизонтали
					if (i - x == 0 || j - y == 0){
						return 0;
					}
					// Лежат на одной диагонали
					if (fabs( (float)(i - x) ) == fabs( (float)(j - y) )){
						return 0;
					}
				}
			}
		}
	}				
	// Если дошли до сюда, то всё в порядке
	count++;
	return 1;
}


// Выводим доску на экран
void Print(int n, int m, int a[N][M]){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

// Очищаем доску
void Zero(int n, int m, int a[N][M]){
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = 0;
		}
	}		
}