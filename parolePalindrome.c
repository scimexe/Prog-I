#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50
void isPalindrome(char parola[]);

int main(void) {
    char parola [WORD_MAX];
    scanf("%s", parola);
    
    isPalindrome(parola);
    return 0;
}

void isPalindrome(char parola[]){

    bool palindroma = true;
        for (int j = 0; j < strlen(parola) && palindroma; j++)
        {
            if(parola[j] != parola[strlen(parola)-j-1]){
                palindroma = false;
            }
        }
    if (palindroma)
    {
        printf("PALINDROMA");
    } else {

        printf("%s ", parola);
        for (int i = strlen(parola)-1; i >= 0; i--)
        {
            printf("%c", parola[i]);
        }
    }
}
