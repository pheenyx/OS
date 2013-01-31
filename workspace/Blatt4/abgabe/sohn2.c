/*
 * sohn2.c
 *
 *  Created on: 28.11.2012
 *      Author: Michael Mardaus
 */

/* Sohn 2 zum Aufgabenblatt 4 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[] ){
	int i,j;

	const int MAX_COUNT = 400000000;

	//prozessausgaben
	printf("Sohn_2:\t");
	printf("pid: %i\t", getpid());
	printf("ppid: %i\n", getppid());
	system("date");

	//schleife um beschaeftigt zu sein
	for (j = 0 ; j < 10 ; j++){
		for (i = 0 ; i<=MAX_COUNT ; i++){
			if (i == MAX_COUNT){
				printf(".");
				//fflush zum aktualisieren der consolenausgabe
				fflush(NULL);
			}
		}
	}
	printf("\n");
	//vereinbarter exit status zur wiedererkennung
	exit(2);
}
