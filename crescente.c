#include <stdio.h>
#include <stdbool.h>
#define SIZE 7
void sequenzaCrescente(int a[SIZE]);

int main(){
    int N[SIZE];
    printf("Inserisci una sequenza di numeri: ");
    for(int i=0; i<SIZE; i++){
        scanf("%d", &N[i]);
    }
    sequenzaCrescente(N);
}
void sequenzaCrescente(int a[]){
  bool crescente=true;
    for(int i=0; i<SIZE-1; i++){
       if(a[i]>a[i+1]){
       crescente=false;
       }
    }
  if(crescente){
    printf("la sequenza e' crescente");
  }
}