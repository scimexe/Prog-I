#include <stdio.h>
#include <limits.h>

int main(){
    char nome_montagna[50];
    char montagna_min[50];
    int altezza = 0;
    int max= INT_MIN;
    
    while(scanf("%s %d", nome_montagna, &altezza) == 2){
        if (altezza >= max){
           max = altezza; 
            for(int i=0; i<50; i++){
                montagna_min[i] = nome_montagna[i];
            }
        }
        
    } 
    printf("%s", montagna_min);
    
    return 0;
}
