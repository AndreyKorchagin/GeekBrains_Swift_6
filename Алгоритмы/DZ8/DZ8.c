#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int *array;
int *sortarray;
int count;

void menu(void);
void task1(void);
void task2(void);
void task3(void);
void task4(void);
void printarry(int *array, int count);
void quickSort(int *array, int left, int right);
void mergeSort(int *numbers, int first, int last);
void merge(int *a, int n);

int main(int argc, char const *argv[]){
	menu();
	return 0;
}

void menu(void){
	int n;
	while(1){
		printf("task 1 - 1\ntask 2 - 2\ntask 3 - 3\ntask - 4\nquit - 5\n");
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
				free(array);
				free(sortarray);
				exit(1);
				break;
		}
	}
}

void task1(void){
	srand(time(NULL));
	printf("введите количество элементов\n");
	scanf("%d", &count);
	array = (int*)malloc(sizeof(int) * count);
	sortarray = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i){
		array[i] = rand() % count;
	}
	printarry(array, count);

	int min = array[0];
	int max = array[0];
	for (int i = 0; i < count; ++i){
		if(array[i] > max){
			max = array[i];
		}
		if(array[i] < min){
			min = array[i];
		}
	}

	printf("max - %d min - %d\n", max, min);
	int len = max - min + 1;
	int countarray[len];
	for (int i = 0; i < count; ++i){
		countarray[i] = 0;
	}

	for (int i = 0; i < count; ++i){
		countarray[array[i] - min]++;
	}
	printf("inputarray: ");
	printarry(array, count);
	printf("countarray: ");
	printarry(countarray, len);
	int k = 0;
	for (int i = 0; i < len; ++i){
		for (int j = 0; j < countarray[i]; ++j){
			sortarray[k++] = i + min;
		}
	}
	printf("sortarray: ");
	printarry(sortarray, count);
	free(array);
	free(sortarray);
}

void task2(void){
	srand(time(NULL));
	printf("введите количество элементов\n");
	scanf("%d", &count);
	array = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i){
		array[i] = rand() % count;
	}
	printf("inputarray: ");
	printarry(array, count);
	quickSort(array, 0, count);
	printf("sortarray: ");
	printarry(array, count);
	free(array);
}

void task3(void){
	srand(time(NULL));
	printf("введите количество элементов\n");
	scanf("%d", &count);
	array = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i){
		array[i] = rand() % count;
	}
	printf("inputarray: ");
	printarry(array, count);
	merge(array, count);
	printf("sortarray: ");
	printarry(array, count);
	free(array);
}

void task4(void){}

void printarry(int *array, int count){
	for (int i = 0; i < count; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void quickSort(int *numbers, int left, int right){
  	int pivot;
  	int l_hold = left;
  	int r_hold = right;
  	pivot = numbers[left];
  	while (left < right){
    	while ((numbers[right] >= pivot) && (left < right))
      		right--;
    	if (left != right){
      		numbers[left] = numbers[right];
      		left++;
    	}
    	while ((numbers[left] <= pivot) && (left < right))
      		left++;
    	if (left != right){
      		numbers[right] = numbers[left];
      	right--;
    	}
  	}
  	numbers[left] = pivot;
  	pivot = left;
  	left = l_hold; 
  	right = r_hold;
  	if (left < pivot)
    	quickSort(numbers, left, pivot - 1);
  	if (right > pivot)
    	quickSort(numbers, pivot + 1, right);
}

void merge(int *a, int n){
	int step = 1;  // шаг разбиения последовательности
  	int *temp = (int*)malloc(n * sizeof(temp)); // дополнительный массив
  	while (step < n)  // пока шаг меньше длины массива
  	{
    	int index = 0;    // индекс результирующего массива
    	int l = 0;      // левая граница участка
    	int m = l + step;  // середина участка
    	int r = l + step * 2;  // правая граница участка
    	do
    	{
      		m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
      		r = r < n ? r : n;
     		int i1 = l, i2 = m; // индексы сравниваемых элементов
      		for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
      		{
        		if (a[i1] < a[i2]){
        			temp[index++] = a[i1++];
        		} // заполняем участок результирующей последовательности
        		else {
        			temp[index++] = a[i2++];
        		}
      		}
      // Или i1 < m или i2 < r - только один из операторов while может выполниться
      		while (i1 < m) temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
      		while (i2 < r) temp[index++] = a[i2++]; // в результирующий массив
      		l += step * 2; // перемещаемся на следующий сортируемый участок
      		m += step * 2;
      		r += step * 2;
    	} while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
    	for (int i = 0; i < n; i++) // переносим сформированный массив обратно в a
      		a[i] = temp[i];
    	step *= 2; // увеличиваем в 2 раза шаг разбиения
  	}
}
