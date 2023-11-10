// Scrivere un programma che legge una serie di sequenze di numeri interi positivi terminati dallo zero.
// Per ciascuna sequenza letta, il main deve stampare, su di una linea di testo, i seguenti elementi:

// la somma degli elementi della sequenza
// la somma dei quadrati degli elementi della sequenza
// il massimo degli elementi della sequenza
// Se la sequenza letta non ha elementi (cioè é subito terminata dallo zero), il programma termina.

// SUGGERIMENTO: scrivere una funzione leggi_sequenza, che si occupa di leggere una singola sequenza terminata da 0 e ritorna al main le tre quantità da stampare. La funzione ritorna true se la sequenza letta non è vuota.

// Scrivere nel main un ciclo che chiama leggi_sequenza() e poi stampa le tre quantità richieste.
// Il ciclo nel main termina quando viene letta la sequenza vuota.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define rows 10
#define columns 15

void scriviSeq(int seq[rows][columns], int nRighe, int nColonne);
bool leggiSeq(int riga[], int nColonne, int* somma, int* sommaQuadrati, int* massimo);

int main()
{	
	int seq [rows] [columns] = {{0}};
	int somma = 0, sommaQuadrati = 0, massimo = 0;

	scriviSeq(seq, rows, columns);
	for(int k=0; k<rows; k++){
		if (leggiSeq(seq[k], columns, &somma, &sommaQuadrati, &massimo)){
			printf("%d %d %d", somma, sommaQuadrati, massimo);
		}
		puts("");
	}

	return 0;
}

void scriviSeq(int seq[rows][columns], int nRighe, int nColonne){

	bool eseguiCiclo;

	for (int i = 0; i < nRighe; i++)
	{
		eseguiCiclo = true;
		for (int j = 0; j < nColonne && eseguiCiclo; j++)
		{	
			scanf("%d", &seq[i][j]);

			if(seq[i][j]==0){
				eseguiCiclo=false;
			}
		}
	}
}

bool leggiSeq(int rigaSeq[], int nColonne, int* somma, int* sommaQuadrati, int* massimo){

	bool notEmpty = true;
	*massimo = INT_MIN;
	*somma = 0;
	*sommaQuadrati = 0; 

	for (int i = 0; i < nColonne && notEmpty; ++i)
	{
		if (i==0 && rigaSeq[i] == 0){
			notEmpty = false;
		} 
		else 
		{
			*somma+=rigaSeq[i];
			*sommaQuadrati+= pow(rigaSeq[i], 2);
			if(*massimo<rigaSeq[i])
			{
				*massimo=rigaSeq[i];
			}
		}
	}
	return notEmpty;
}

