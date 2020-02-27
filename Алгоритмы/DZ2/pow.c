#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


void zadanie1(void);
void zadanie2(void);
void dectobin(int number, char *bin);
int pow1(int number, int power);
int pow2(int number, int power);

int main(int argc, char const *argv[]){

	zadanie1();
	zadanie2();
	return 0;
}

void zadanie1(void){
	printf("zadanie 1\n");
	int number;
	printf("vvedite chislo\n");
	scanf("%d", &number);
	char *bin = (char*)malloc(64);
	dectobin(number, bin);
	printf("dec = %d bin = %s\n", number, bin);
}

void zadanie2(){
	printf("zadanie 2\n");
	int number;
	int power;
	printf("vvedite chislo i stepen\n");
	scanf("%d %d", &number, &power);

	printf("zadanie2a // %d^%d = %f\n", number, power, pow(number, power));
	printf("zadanie2b // %d^%d = %d\n", number, power, pow1(number, power));
	printf("zadanie2c // %d^%d = %d\n", number, power, pow2(number, power));

}

void dectobin(int number, char *bin){
	if (number / 2 != 0){
		dectobin(number / 2, bin);
	}
	if (number % 2 == 0){
		strncat (bin, "0", 1); 
	}else{
		strncat (bin, "1", 1);
	}
}

int pow1(int number, int power){
	return power == 1 ? number : number * pow1(number, --power);
}

int pow2(int number, int power){
	if(power == 0){
		return 1;
	}
	int x = power % 2 ? number : 1;
	int c = pow2(number, power / 2);
	return x * c * c;
}

