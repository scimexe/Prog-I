#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    typedef struct
    {
        int qta;
        char tipo[50];
        float prezzo;
    } mercato;

    int nArt;

    printf("Quanti articoli vuoi inserire? ");
    scanf("%d", &nArt);

    mercato articoli[nArt];
    
    for (int i = 0; i < nArt; i++)
    {   
        printf("ARTICOLO %d\n", i+1);
        printf("Tipo: ");
        scanf("%s", &articoli[i].tipo);
        printf("Prezzo: ");
        scanf("%f", &articoli[i].prezzo);
        printf("Quantita': ");
        scanf("%d", &articoli[i].qta);
    }
    float totale = 0;
    for (int i = 0; i < nArt; ++i)
    {
        totale += articoli[i].prezzo*articoli[i].qta;
    }

    printf("TOTALE SPESA\n");
    printf("Il totale della spesa e' %.2f", totale);
    return 0;

}
