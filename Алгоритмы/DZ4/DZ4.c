#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define N 4
#define M 4

void Print2(int n, int m, int a[N][M]);
void Print3(int n, int m, int a[N][M], char s1[], char s2[]);
void ex1(void);
void ex2(void);

int main(int argc, char *argv[]){
	ex1();
	ex2();
	return 0;
}

void Print2(int n, int m, int a[n][m]){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}

void Print3(int n, int m, int a[n][m], char s1[], char s2[]){
	int i, j;

	printf("      ");
	for (int i = 0; i < strlen(s1); ++i){
		printf("%6c", s1[i]);
	}

	printf("\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < m + 1; j++){
			if (j == 0){
				printf("%6c", s2[i]);

			}else{
				printf("%6d", a[i][j - 1]);
			}
		}
		printf("\n");
	}
}

void ex1(void){

	int MAP[N][M] = {	1, 1, 1, 1,
						0, 1, 1, 1,
						1, 1, 1, 1,
						1, 1, 1, 1	};

	int A[N][M];
	int i, j;
	int stop_x = 1;
	int stop_y = 1;

	for (j = 0; j < M; j++){
		if (MAP[0][j] == 1 && stop_x == 1){
			A[0][j] = 1;
		} else {
			A[0][j] = 0;
			stop_x = 0;
		}
	}

	for (i = 1; i < N; i++){
		if (MAP[i][0] == 1 && stop_y == 1){
			A[i][0] = 1;
		} else {
			A[i][0] = 0;
			stop_y = 0;
		}
		for (j = 1; j < M; j++){
			if (MAP[i][j] == 1){
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			} else {
				A[i][j] = 0;
			}
		}	
	}

	printf("\n\t\t\tMAP\n");
	Print2(N, M, MAP);
	printf("\n\t\t\tANSWER\n");
	Print2(N, M, A);
	printf("\n");
}

void ex2(void){

	char s1[] = "geekbrains";
	char s2[] = "GEekminds";
	char out[20];
	int N1 = strlen(s1);
	int M1 = strlen(s2);
	int Matrix[M1][N1];

	for (int i = 0; i < N1; ++i){
		s1[i] = toupper(s1[i]);
	}
	for (int i = 0; i < M1; ++i){
		s2[i] = toupper(s2[i]);
	}

	for (int i = 0; i < M1; ++i){
		for (int j = 0; j < N1; ++j){
			Matrix[i][j] = 0;
		}
	}

	int point = 0;
	int stop_x = 0;
	for (int i = 0; i < M1; ++i){
		for (int j = 0; j < N1; ++j){
			if(s2[i] == s1[j] && stop_x == 0 && i <= j){
				stop_x = 1;
				out[point] = s1[j];
				point++;
				Matrix[i][j] = point;
				//printf("i = %d j = %d\n", i, j);
			} else {
				Matrix[i][j] = point;
			}
		}
		//printf("\n");
		stop_x = 0;
	}

	Print3(M1, N1, Matrix, s1, s2);
	printf("out = %s\n", out);
}