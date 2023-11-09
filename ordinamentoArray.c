#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void stampaArray(int a[], int len);
void bubbleSort(int a[], int len);
void swapValues(int* a, int* b);
void centoNPrimi();

bool numeriPrimi(int a[], int len, int prime[]);
int main(){
    int len = 0;
    do{
        printf("Inserisci la lunghezza dell'array: ");
        scanf("%d", &len);
    }while(len <=0);

    int array[len];
    int primi[len];
    int scelta = 0;
    char uscita = ' ';

    for(int i=0; i<len; i++){
        printf("%d valore dell'array: ", i+1);
        scanf("%d", &array[i]);
    }

    puts("------------\nValori array:");
    stampaArray(array, len);

    do{
        do{
            printf("\n------------\nPremi\n1. Per ordinare l'array.\n2. Per controllare la presenza di numeri primi nell'array.\n3. Per stampare i primi 100 numeri primi.\n");
            fflush(stdin);
            scanf("%d", &scelta);
        }while(scelta<=0 || scelta>3);
        
        switch (scelta)
        {
        case 1:
            bubbleSort(array, len);
            puts("\n------------\nValori array ordinato:");
            stampaArray(array, len);
            break;

        case 2:
            if (numeriPrimi(array, len, primi)){
                puts("\n------------\nArray contenente numeri primi:");
                stampaArray(primi, len);
            } else
                puts("\n------------\nnNon sono presenti numeri primi nell'array.");
            break;

        case 3:
            centoNPrimi();
            break;

        default:
            break;
        }
        printf("\n\nPremi Y per uscire: ");
        fflush(stdin);
        scanf("%c", &uscita);
    } while(tolower(uscita)!= 'y');

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
        if(array[i]!=0){
            printf("%d ", array[i]);
        }
    }
}

bool numeriPrimi(int a[], int len, int prime[]){
    bool isprime = true;
    for (size_t i = 0; i < len; i++)
    {
        prime[i] = 0;
    }
    
    for (size_t i = 0; i < len; i++)
    {
        isprime = true;
        for (size_t j = 2; j < a[i] && (isprime); j++)
        {   
            if(a[i]%j==0 || (a[i]==0 && a[i]==1)){
                isprime= false;
            }
        }  
        if (isprime){
            prime[i] = a[i];
        }
    }
}

void centoNPrimi(){
    puts("\n------------\nPrimi 100 numeri primi:");
    for (size_t i=0; i <=100; i++)
    {
        int prime = true;
        for (size_t j = 2; j < i && prime; j++)
        {
            if(i%j==0){
                prime = false;
            }
        }
        if(prime){
            printf("%d ", i);
        }
    }
}