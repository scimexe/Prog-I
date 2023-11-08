#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
    
    char password[20];
    bool P1 = false, P2= true, P3 = false, P4 = false, P5 = false;
    int upper = 0;
    
    scanf("%20s", password);
    
    int pwdLength = strlen(password);
    
    for(int i=0; i<pwdLength; i++){
        
        if(isdigit(password[i])){
            P1 = true;
            
            if(isdigit(password[i-1]))
                P4 = true;
        }
        if(!isalpha(password[i])){
            P2 = false;
        }
            
        if(isupper(password[i])){
            upper ++;
            if (upper >=2)
                P3 = true;
        }
    }
    if(ispunct(password[pwdLength-1]) && (ispunct(password[pwdLength-2]))){
        P5 = true;
    }
    printf("%s ", password);
    
    P1 ? printf("1 ") : printf("0 ");
    P2 ? printf("1 ") : printf("0 ");
    P3 ? printf("1 ") : printf("0 ");
    P4 ? printf("1 ") : printf("0 ");
    P5 ? printf("1 ") : printf("0 ");
    
    return 0;
}