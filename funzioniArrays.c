#include <stdio.h>
#include <stdbool.h>

#define maxEle 20

int leggi_array(int array[]);
int conta_univoci(int array[], int nEle);
void stampa_elementi_ripetuti(int array1[], int nEle1, int array2[], int nEle2);

int main(){

	int a[maxEle];
	int b[maxEle];

	int nEle1 = leggi_array(a);
	int nEle2 = leggi_array(b);
	printf("%d %d", conta_univoci(a, nEle1), conta_univoci(b, nEle2));
	puts("");
	stampa_elementi_ripetuti(a, nEle1, b, nEle2);
	return 0;
}

int leggi_array(int a[]){

	int nEle = 0;
	  scanf("%d", &nEle);

	for (int i = 0; i < nEle; ++i)
	{
		scanf("%d", &a[i]);
	}
	return nEle;
}

int conta_univoci(int array[], int nEle){

	int counter = 0;
	bool univoco;
	int j;

	for (int i = 0; i < nEle; i++)
	{
		univoco = true;
		for (j = 0; j < nEle && univoco; j++)
		{
			if(i!=j){						//esclude dal controllo se stesso
				if(array[i] == array[j]){
					univoco = false;
				}
			}
		}
		if (univoco)
		{
			counter++;
		}
	}
	return counter;
}

void stampa_elementi_ripetuti(int array1[], int nEle1, int array2[], int nEle2){
    bool check;
	for (int i = 0; i < nEle1; ++i)
	{
        check = true;
		for (int j = 0; j < nEle2 && check; ++j)
		{
			if(array1[i] == array2[j]){
				printf("%d ", array1[i]);
				check = false;
			}
		}
	}
}