/*

preprocessore --> compilatore  --> assemblatore  --> linker

gcc -c sorgente.c -o oggetto.o (sorgente non linkato

I compilati si possono decompilare (assembly) tramite il disassembler

*/

#include <stdio.h>


int main(){
	
	printf("Hello world!");
	return 0;
}