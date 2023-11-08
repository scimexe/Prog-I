/*
Programmare significa scrivere algoritmi per macchine di calcolo, nel nostro caso è la macchina di Von Neumann. 
Per quanto riguarda il linguaggio, esistono vari livelli di astrazione.
Ogni macchina ha un proprio codice assembler. Si rende necessario utilizzare linguaggi di "alto" livello affinché 
l'algoritmo scritto sia utilizzabile su più macchine.
Esso lavora modificando continuamente la memoria su cui opera.

Il C è un linguaggio modulare, utilizzabile in svariati ambiti:
* 	SW Embedded
* 	Web services
e molti altri
 
Tutti i programmi C contengono una funzione principale, il main()

Le parentesi graffe indicano lo scope.

Preprocessore --> Compilatore --> Assembler --> Linker

Una variabile è un nome simbolico per un'area di memoria. 
Il compilatore ha la necessità di sapere il tipo di variabile per allocare (assegnare) tot spazio di memoria.
Le variabili simboliche mascherano il meccanismo hardware di instradamento della RAM nella MdVN
La variabile è formata da

Tipo
Nome
Valore
Indirizzo

Al caricamento del programma, viene allocata un'area di memoria per il codice e per i dati. La dimensione dell'area del codice è fissa.
L'area dei dati è lo STACK e ha una dimensione massima predefinita.
Frame Pointer: Indirizzo di base da cui iniziare ad allocare la variabili della funzione main
Stack Pointer: Indirizzo a cui allocare la prossima variabile. 
Al caricamento, FP e SP coincidono.
Allocare una variabile di tipo int significa, in termini di memoria, consumare 4 bytes dall'area di dati disponibile.

 ________________ FP
|__var allocata__|SP
|      			 |
|				 |
|	 Area dati   |
|				 |
|				 |
|________________|
|___Area Codice__|				 


Tipi primitivi in C

Tipo	   Byte	    Indicato con

char		1 			%c
int 		4			%d
short		2			%d
long		8			%ld	
float		4			%f
double		8			%lf
*/

#include <stdio.h>							//istruzioni per il preprocessore

int main(int argc, char const *argv[])		//funzione main
{											//inizio blocco
	int number = 0;
	printf("Inserisci un numero: ");
	scanf("%d", &number);
	printf("Hai inserito il numero %d" , number);

	return 0;								//valore di ritorno della funzione
}											//fine blocco