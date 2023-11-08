#include <stdio.h>
#include <stdbool.h>

void stampaArray(int a[], int len);
void bubbleSort(int a[], int len);
void swapValues(int* a, int* b);
bool numeriPrimi(int a[], int len, int prime[]);
int main(){
    int len = 0;
    do{
        printf("Inserisci la lunghezza dell'array: ");
        scanf("%d", &len);
    }while(len <=0);

    int array[len];
    int primi[len];

    for(int i=0; i<len; i++){
        printf("%d valore dell'array: ", i+1);
        scanf("%d", &array[i]);
    }
    puts("------------\nValori array:");
    stampaArray(array, len);
    bubbleSort(array, len);
    
    puts("\n------------\nValori array ordinato:");
    stampaArray(array, len);
    if (numeriPrimi(array, len, primi)){
        puts("\n------------\nArray contenente numeri primi:");
        stampaArray(primi, len);
    } else
        puts("\nNon sono presenti numeri primi nell'array.");

    return 0;
}

void bubbleSort(int a[], int len){
    bool eseguiCiclo = true;
    while (eseguiCiclo){
        eseguiCiclo = false;
        for(int i=0; i<len-1; i++){
            if (a[i] > a[i+1]){
                swapValues(&a[i], &a[i+1]);
                eseguiCiclo = true;
            }
        }
    }
}

void swapValues(int* a, int *b){
    int tmp= *a;
    *a = *b;
    *b = tmp;
}

void stampaArray(int array[], int len){
    for(int i=0; i<len; i++){
        printf("%d ", array[i]);
    }
}

bool numeriPrimi(int a[], int len, int prime[]){
    bool isprime = false;
    for (size_t i = 0; i < len; i++)
    {
        prime[i] = 0;
    }
    
    for (int i=0; i<len; i++){
        for (size_t j = 2; j < a[i]/2; j++)
        {
            if(a[i]%j!=0){
                prime[i] = a[i];
                isprime = true;
            }
        }
    }
    return isprime;
}