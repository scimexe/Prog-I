/*Ad un campione di 20 soggetti è stato somministrato un questionario,
con una domanda che richiede una risposta da 1 a 5 stelle.
Risposta: ★★★☆☆
Le risposte ottenute dai 20 questionari hanno questi valori:
*/

#include <stdio.h>

#define NUM_RISP 20

int main(int argc, char const *argv[])
{ 
    int risposte[NUM_RISP] = {
    1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
    4, 3, 3, 3, 2, 3, 3, 2, 2, 5
    };

    int freq [5] = {0};

    for (size_t i = 0; i < NUM_RISP; i++)
    {
        freq[risposte[i]] ++;
    }
    puts("Sommario");

    for (size_t i = 1; i <= 5; i++)
    {
        printf("Valutazione: %d Occorrenze: %d ",i, freq[i]);

        for (size_t j = 0; j < freq[i]; j++)
        {
            printf("#");
        }
        puts("");
    }
    
    
    return 0;
}

