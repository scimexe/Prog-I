/*
Sono stati identificati NUM_PERS=24 soggetti sospetti, e le loro relative caratteristiche fisiognomiche sono state raccolte. 
I nomi e le caratteristiche sono già disponibili sotto forma di array in linguaggio C!

Scrivere un programma C che legge dall'input una sestupla di valori interi che rappresentano:

il primo intero vale 1 se il soggetto sospetto è calvo, altrimenti vale 0;
il secondo intero vale 1 se il soggetto sospetto ha il cappello, altrimenti vale 0;
il terzo intero vale 1 se il soggetto sospetto è donna, altrimenti vale 0;
il quarto intero vale 1 se il soggetto sospetto ha gli occhiali, altrimenti vale 0;
il quinto intero vale 1 se il soggetto sospetto ha gli occhi blu, altrimenti vale 0;
il sesto intero vale 1 se il soggetto sospetto ha i capelli neri, altrimenti vale 0.
Il programma deve stampare i nomi dei soggetti sospetti che corrispondono ai criteri letti in input, uno per riga. dopo la stampa dei nomi, 
il programma deve stampare un sommario formattato secondo una delle seguenti opzioni (mutualmente esclusive):

stampa "NO_SOSPETTI" se non sono stati trovati soggetti sospetti con le caratteristiche descritte;
stampa "TROVATO!" se è stato trovato un singolo soggetto sospetto con le caratteristiche descritte;
altrimenti stampa "TROVATI " seguito dal numero di soggetti sospetti con le caratteristiche descritte.
*/

#include <stdio.h>
#include <stdbool.h>
#define N_TRATTI 6
//-------------------------------------------------------
// Definizione del gioco - non modificare
//-------------------------------------------------------

#define NUM_PERS  24

const char* nomi[NUM_PERS] = {
	"Claire", "Eric", "Maria", "George", "Bernard", "Sam", 
	"Tom", "Paul", "Joe", "Frans", "Anne", "Max", 
	"Alex", "Philip", "Bill", "Anita", "David", "Charles", 
	"Herman", "Peter", "Susan", "Robert", "Richard", "Alfred"
};
const bool e_calvo[NUM_PERS] = {
	0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0,   0, 0, 1, 0, 0, 0,  1, 0, 0, 0, 1, 0, 
};
const bool ha_cappello[NUM_PERS] = {
	1, 1, 1, 1, 1, 0,   0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 
};
const bool e_donna[NUM_PERS] = {
	1, 0, 1, 0, 0, 0,   0, 0, 0, 0, 1, 0,   0, 0, 0, 1, 0, 0,  0, 0, 1, 0, 0, 0, 
};
const bool ha_occhiali[NUM_PERS] = {
	1, 0, 0, 0, 0, 1,   1, 1, 1, 0, 0, 0,   0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 
};
const bool ha_occhi_blu[NUM_PERS] = {
	0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 0, 0,   0, 0, 0, 1, 0, 0,  0, 1, 0, 1, 0, 1, 
};
const bool ha_capelli_neri[NUM_PERS] = {
	0, 0, 0, 0, 0, 0,   1, 0, 0, 0, 1, 1,   0, 1, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 
};

int trovaPersone(int mio[], const bool e_calvo[], const bool ha_cappello[], const bool e_donna[], 
                 const bool ha_occhiali[], const bool ha_occhi_blu[], const bool ha_capelli_neri[], bool tratti[]){
    int i = 0, n=0;
    puts("Sospettati: ");

    for (size_t j = 0; j < N_TRATTI; j++)
    {
        for (size_t i = 0; i < NUM_PERS; i++)
        {
            if ((e_calvo[j] == tratti[i]) && (ha_cappello[j] == tratti[i]) && (e_donna[j] == tratti[i]) && (ha_occhiali[j] == tratti[i]) && (ha_occhi_blu == tratti[i]) && (ha_capelli_neri[j] == tratti[i])){
            mio[i] = j;      // posizione 
            i++;             // numero di elementi trovati
            printf("%s ", nomi[j]);
        }
        }
        

    }    
    return i;
}

int main() {
    
    bool tratti[N_TRATTI];
    int calvi[NUM_PERS];
    int nCalvi = 0;

	puts("Indovina Chi?\n Tratti del sospettato...");
    for (size_t i = 0; i < N_TRATTI; i++)
    {
        scanf("%d", &tratti[i]);
    }
    trovaPersone(calvi, e_calvo, ha_cappello, e_donna, ha_occhiali, ha_occhi_blu, ha_capelli_neri, tratti);
}

