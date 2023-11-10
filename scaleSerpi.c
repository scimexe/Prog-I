/*
Scale e serpi è un gioco tradizionale di origine indiana (Gyan Chauper o ज्ञान चौपड़ in Hindi) in cui dei giocatori (assumiamo 2) devono completare un percorso in un tabellone 10x10. I giocatori iniziano entrambi nella casella 1 e si alternano a turni, secondo queste regole:

All'inizio del turno il giocatore che ha il turno lancia un dado e procede ad avanzare della quantità indicata.
Dopo aver avanzato, il giocatore controlla in che casella è finito:
Se nella casella c'è la base di una 🪜scala, allora salta direttamente alla casella in cui si trova la cima della 🪜scala.
Se nella casella c'è la testa di una 🐍serpe, allora salta indietro fino alla casella con la coda della 🐍serpe.
Se il giocatore aveva ottenuto 6 dal lancio del dado, allora gioca anche il turno successivo, altrimenti il turno passa all'altro giocatore. Un giocatore continua a lanciare il dado e a muoversi fintanto che ottiene 6 dal lancio del dado.
Il primo giocatore che raggiunge o supera la casella 100 vince.

Le otto 🪜scale (base, cima) si trovano nelle seguenti caselle:
(1,38) (4,14) (8,30) (21,42) (28,76) (50,67) (71,92) (80,99)

mentre le sette 🐍serpi (testa, coda) si trovano nelle seguenti caselle:
(32,10) (36,6) (48,26) (62,18) (88,24) (95,56) (97,78)



Leggere il codice fornito e completarlo scrivendo la funzione muovi_giocatore, che deve realizzare il turno di un giocatore. La funzione muovi_giocatore ha i seguenti parametri formali:

dado = la quantità ottenuta dal lancio del dado (tra 1 e 6)
pos = puntatore ad un intero che contiene la casella del giocatore (maggiore di 1) all'inizio del turno, e che deve essere modificata opportunamente seguendo le regole del gioco.
La funzione muovi_giocatore deve restituire true se il giocatore gioca anche il turno successivo, false altrimenti.
*/

// Avanza la posizione del giocatore nella casella *pos
// in funzione del lancio del dado.
// Parametri:
//   dado   La quantità ottenuta dal lancio del dado (compresa tra 1 e 6)
//  *pos    La cella del giocatore che muove
// Ritorna true se il giocatore gioca ancora il prossimo turno, false altrimenti.
// Al ritorno, il valore di *pos è stato modificato aggiungendo il lancio 
// del dado, ed applicando tutte le rimanenti reole sulle scale e sulle serpi
#include <stdio.h>
#include <stdbool.h>

bool muovi_giocatore(int dado, int* pos) {
    
	bool again = false; //se true, il giocatore gioca un altro turno.
	
	return again;
}

//------------------------------------------------------------------------------
// LEGGERE MA NON MODIFICARE IL CODICE SEGUENTE

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