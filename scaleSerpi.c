/*
 
Scale e serpi è un gioco tradizionale di origine indiana (Gyan Chauper o ज्ञान चौपड़ in Hindi) in cui dei giocatori (assumiamo 2) devono completare un percorso in un tabellone 10x10. 
I giocatori iniziano entrambi nella casella 1 e si alternano a turni, secondo queste regole:

All'inizio del turno il giocatore che ha il turno lancia un dado e procede ad avanzare della quantità indicata.     OK
Dopo aver avanzato, il giocatore controlla in che casella è finito:
Se nella casella c'è la base di una 🪜scala, allora salta direttamente alla casella in cui si trova la cima della 🪜scala.
Se nella casella c'è la testa di una 🐍serpe, allora salta indietro fino alla casella con la coda della 🐍serpe.

Se il giocatore aveva ottenuto 6 dal lancio del dado, allora gioca anche il turno successivo, altrimenti il turno passa all'altro giocatore. Un giocatore continua a lanciare il dado e a muoversi fintanto che ottiene 6 dal lancio del dado. OK
Il primo giocatore che raggiunge o supera la casella 100 vince.

Le otto 🪜scale (base, cima) si trovano nelle seguenti caselle:
(1,38) (4,14) (8,30) (21,42) (28,76) (50,67) (71,92) (80,99)

mentre le sette 🐍serpi (testa, coda) si trovano nelle seguenti caselle:
(32,10) (36,6) (48,26) (62,18) (88,24) (95,56) (97,78)

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool muovi_giocatore(int dado, int* pos);
int lancia_dado(void);
void scale_e_serpi(void);

int main()
{
    scale_e_serpi();
    return 0;
}

bool muovi_giocatore(int dado, int* pos) {

    int baseScale [] = {1, 4, 8, 21, 28, 50, 71, 80};
    int cimaScale [] = {38, 14, 30, 42, 76, 67, 92, 99};
    int testaSerpi [] = {32, 36, 48, 62, 88, 95, 97};
    int codaSerpi [] = {10, 6, 26, 18, 24, 56, 78};

	bool again = false; //se true, il giocatore gioca un altro turno.

    if (dado == 6) {
        again = true;
    }

	*pos +=dado;
    
    //check posizione in base scala
    for (size_t j = 0; j < 8; j++)
    {
        if (*pos == baseScale[j]){
            *pos = cimaScale[j];
        }
    }

    //check posizione in testa serpe
    for (size_t i = 0; i < 7; i++)
    {
        if(*pos == testaSerpi[i]){
            *pos = codaSerpi[i];
        }
    }

	return again;
}

// Simula il lancio di un dado a 6 facce
int lancia_dado() {
	return (rand() % 6) + 1;
}

// Realizza i turni del gioco delle scale e delle serpi
void scale_e_serpi(void) {
	int pos1 = 1, pos2 = 1; // la posizione dei due giocatori, inizialmente 1
	int turno = 1; 			// puo' valere 1 o 2

	// Esegui i turni
	while (pos1<100 && pos2<100) {
		// il giocatore lancia il dado
		int dado = lancia_dado();
		// muovi il giocatore attivo, e determina chi gioca il prossimo turno
		if (turno == 1) { 
			// muove il giocatore 1
			if (muovi_giocatore(dado, &pos1) == false)
				turno = 2; // passa il turno al giocatore 2
		}
		else { 
			// muove il giocatore 2
			if (muovi_giocatore(dado, &pos2) == false)
				turno = 1; // passa il turno al giocatore 1
		}
	}
	// Stampa il vincitore e le posizioni finali dei due giocatori
	printf("%d %d %d\n", turno, pos1, pos2);
}