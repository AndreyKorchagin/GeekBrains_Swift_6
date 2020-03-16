#include "stdio.h"
#include "math.h"

void zadanie1(void){
	printf("zadanie1\n");
	int m;
	int h;
	printf("vvedite rost - ");
	scanf("%d", &h);
	printf("vvedite ves - ");
	scanf("%d", &m);
	printf("index massi tels = %.3f\n", (float)m/(h * h));
}

void zadanie2(void){
	printf("zadanie2\n");
	int a, b, c, d, max;
	printf("vvedite 4 числа");
	printf("\na - ");
	scanf("%d", &a);
	printf("\nb - ");
	scanf("%d", &b);
	printf("\nc - ");
	scanf("%d", &c);
	printf("\nd - ");
	scanf("%d", &d);
	printf("vi vveli a = %d b = %d c = %d d = %d\n", a, b , c ,d);
	max = a;
	if (b > max){
		max = b;
		if (c > max){
			max = c;
			if (d > max){
				max = d;
			}
		}
	}
	printf("max = %d\n", max);
}

void zadanie3(void){
	printf("zadanie3\n");
	int a, b, tmp;
	printf("vvedite a - ");
	scanf("%d", &a);
	printf("vvedite b - ");
	scanf("%d", &b);
	printf("a - %d b - %d\n", a, b);
	printf("change a and b\n");
	tmp = a;
	a = b;
	b = tmp;
	printf("a - %d b - %d\n", a, b);
	printf("change a and b\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a - %d b - %d\n", a, b);

}

void zadanie4(void){
	printf("zadanie4\n");
	int a, b, c;
	float x1, x2, D;
	printf("vvedite a, b, c -");
	scanf("%d %d %d", &a, &b, &c);
	printf("a - %d b - %d c - %d\n", a, b, c);
	D = sqrt(pow(b, 2) - 4*a*c);
	x1 = (float)(-b + D)/(2*a);
	x2 = (float)(-b - D)/(2*a);
	printf("x1 = %.2f x2 = %.2f\n", x1, x2);

}

void zadanie5(void){
	printf("zadanie5\n");
	int m;
	printf("vvedite nomer month - ");
	scanf("%d", &m);
	switch(m){
		case 1:
			printf("January\n");
			break;
		case 2:
			printf("February\n");
			break;
		case 3:
			printf("March\n");
			break;
		case 4:
			printf("April\n");
			break;
		case 5:
			printf("May\n");
			break;
		case 6:
			printf("June\n");
			break;
		case 7:
			printf("July\n");
			break;
		case 8:
			printf("August\n");
			break;
		case 9:
			printf("September\n");
			break;
		case 10:
			printf("October\n");
			break;
		case 11:
			printf("November\n");
			break;
		case 12:
			printf("December\n");
			break;
		default:
			printf("NO\n");
			break;
	}

}

void zadanie6(void){
	printf("zadanie6\n");
	int age;
	printf("vvedite vozrast - ");
	scanf("%d", &age);
	if (age % 10 == 1){
		if (age == 11 || age == 111){
			printf("%d let\n", age);
		} else {
			printf("%d god\n", age);
		}
	} else if ((age % 10 >= 2 && age % 10 <= 4) && (age <= 150)){
		if(age >= 12 && age <= 14){
			printf("%d let\n", age);
		} else {
			printf("%d goda\n", age);
		}
	} else if ( (age >= 5 && age <= 19) || (age >= 105 && age <= 119) || ((age % 10 >= 5 && age % 10 <= 9)  && (age <= 150)) ){
		printf("%d let\n", age);
	} else {
		printf("NO\n");
	}
}

void zadanie7(void){
	printf("zadanie7\n");
	int y1, y2;
	char x1, x2;
	int a, b;
	printf("vvedite x1 y1 x2 y2\n");
	scanf("%c %d %c %d", &x1, &y1, &x2, &y2);
	printf("x1 - %c y1 - %d x2 - %c y2 - %d\n", x1, y1, x2, y2);
	if ( ((x1 >= 65 && x1 <= 72) || (x1 >= 97 && x1 <= 102)) && (y1 >= 1 && y1 <= 8) ){
		if( ((int)x1 % 2 == 0) && (y1 % 2 == 0) ){
			a = 0;
		} else if( ((int)x1 % 2 == 1) && (y1 % 2 == 1) ){
			a = 0;
		} else if( ((int)x1 % 2 == 0) && (y1 % 2 == 1) ){
			a = 1;
		} else if( ((int)x1 % 2 == 1) && (y1 % 2 == 0) ){
			a = 1;
		}
	}

	if ( ((x2 >= 65 && x2 <= 72) || (x2 >= 97 && x2 <= 102)) && (y2 >= 1 && y2 <= 8) ){
		if( ((int)x2 % 2 == 0) && (y2 % 2 == 0) ){
			b = 0;
		} else if( ((int)x2 % 2 == 1) && (y2 % 2 == 1) ){
			b = 0;
		} else if( ((int)x2 % 2 == 0) && (y2 % 2 == 1) ){
			b = 1;
		} else if( ((int)x2 % 2 == 1) && (y2 % 2 == 0) ){
			b = 1;
		}
	}

	if (a == b){
		printf("odin zvet\n");
	} else {
		printf("razniy zvet\n");
	}

}

void zadanie8(void){
	printf("zadanie8\n");
	int a, b;
	printf("vvedite a i b\n");
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; ++i){
		printf("%d ", i * i);
	}
	printf("\n");
	for (int i = a; i <= b; ++i){
		printf("%d ", i * i * i);
	}
	printf("\n");

}

void zadanie9(void){

}

int main(int argc, char const *argv[]){
	zadanie1();
	zadanie2();
	zadanie3();
	zadanie4();
	zadanie5();
	zadanie6();
	zadanie7();
	zadanie8();
	zadanie9();

	return 0;
}