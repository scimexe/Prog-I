/*Scrivere un programma alfabeto.c che crea un array di 27
caratteri.
• Il programma inizializza con un ciclo for i primi 26
caratteri con le lettere progressive dell’alfabeto dalla
‘A’ fino alla ‘Z’.
• Inserisce il terminatore della stringa.
• Stampa la stringa ottenuta con printf.*/


#include <stdio.h>

int main(int argc, char const *argv[])
{
    char alfabeto[27];
    alfabeto[0] = 'A';

    for (size_t i = 1; i < 26; i++)
    {
        alfabeto[i] = alfabeto[i-1]+1;
    }

    printf("%s", alfabeto);
    return 0;
}
