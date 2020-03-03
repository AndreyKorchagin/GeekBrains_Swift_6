#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define COUNT 10

void swap(int *a, int *b);
void printa(int *array, int count, char text[]);

int bobblesort(int *array, int count);
int bobblesortnew(int *array, int count);
int shakesort(int *array, int count);
int binsearch(int *array, int count, int key);
void bs(int *array, int count);

int main(int argc, char const *argv[]){

	srand(time(0));
	int count = COUNT;
	int *array = (int*)malloc(sizeof(count));

	for (int i = 0; i < count; ++i){
		array[i] = rand() % 100;
		//printf("%d ", array[i]);
	}
	printa(array, count, "array");

	int tic1 = bobblesort(array, count);
	int tic2 = bobblesortnew(array, count);
	int tic3 = shakesort(array, count);
	printf("\ntic1 = %d\ntic2 = %d\ntic3 = %d\n", tic1, tic2, tic3);
	binsearch(array, count, 10);
	return 0;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printa(int *array, int count, char text[]){
	printf("\n");
	for (int i = 0; i < count; ++i){
		printf("%d ", array[i]);
	}
	printf("= %s", text);
}

int  bobblesort(int *array, int count){
	int tic = 0;
	int sortarray[count];

	for (int i = 0; i < count; ++i){
		sortarray[i] = array[i];
	}

	for (int i = 0; i < count - 1; ++i){
		for (int j = 0; j < count - 1 - i; ++j){
			if (sortarray[j] > sortarray[j + 1]){
				swap(&sortarray[j], &sortarray[j + 1]);
				tic++;
			}
		}
	}
	printa(sortarray, count, "bobblesort");
	return tic;
}

int bobblesortnew(int *array, int count){
	int tic = 0;
	int swapped;
	int sortarray[count];

	for (int i = 0; i < count; ++i){
		sortarray[i] = array[i];
	}

	for (int i = 0; i < count - 1; ++i){
		swapped = 0;
		for (int j = 0; j < count - 1 - i; ++j){
			if (sortarray[j] > sortarray[j + 1]){
				swap(&sortarray[j], &sortarray[j + 1]);
				swapped = 1;
				tic++;
			}
		}
		if (swapped == 0){
			break;
		}
	}
	printa(sortarray, count, "bobblesortnew");

	return tic;
}

int shakesort(int *array, int count){
	int tic = 0;
	int left = 0;
	int right = count - 1;
	//int flag = 1;
	int sortarray[count];

	for (int i = 0; i < count; ++i){
		sortarray[i] = array[i];
	}

	while(left <= right){
		for (int i = left; i <= right; ++i){
			if(sortarray[i - 1] > sortarray[i]){
				swap(&sortarray[i - 1], &sortarray[i]);
				tic++;
			}
		}
		right--;

		for (int i = right; i >= left; i--){
			if(sortarray[i - 1] > sortarray[i]){
				swap(&sortarray[i - 1], &sortarray[i]);
				tic++;
			}
		}
		left++;
	}

	printa(sortarray, count, "shake");

	return tic;
}

int binsearch(int *array, int count, int key){
	int tic = 0;
	int left = 0;
	int right = count;
	int search = -1;
	int sortarray[count];

	for (int i = 0; i < count; ++i){
		sortarray[i] = array[i];
	}

	bs(sortarray, count);
	printf("\n");
	//printf("key = %d\n", key);
	while(left <= right){
		int mid = (left + right) / 2;
		if (key == sortarray[mid]){
			search = mid;
			break;
		}

		if (key < sortarray[mid]){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	if (search == -1){
		printf("эллемент не найден\n");
	} else {
		printf("индекс искомого элемента = %d\n", search);
	}

	return tic;
}

void bs(int *array, int count){
	int tic = 0;
	for (int i = 0; i < count - 1; ++i){
		for (int j = 0; j < count - 1 - i; ++j){
			if (array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
				tic++;
			}
		}
	}
}
