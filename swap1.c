#include <stdio.h>

int main(int argc, char const *argv[])
{	

	int a, b;
	printf("variabile A:\n");
	scanf("%d", &a);
	printf("variabile B:\n");
	scanf("%d", &b);	
	swap(a, b);
	return 0;
}

void swap (int a, int b){
	int c = 0;
	c = a;
	a = b;
	b = c;
	printf("Valori swappati:\nVariabile A: %d \nVariabile B: %d", a, b);
}