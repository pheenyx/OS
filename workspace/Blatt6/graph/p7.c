/*
 * p7.c
 *
 *  Created on: 20.12.2012
 *      Author: Michael Mardaus
 */


/* Ausgabefunktion zum Aufgabenblatt 6 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sema.h"

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int sem9,sem10;

	sem9 = sem_open(9);
	if (sem9 < 0){
		perror("Semaphore9 open Fehler");
		exit(-1);
	}
	sem10 = sem_open(10);
	if (sem10 < 0){
		perror("Semaphore10 open Fehler");
		exit(-1);
	}

	//startteil
	printf("\t\t\t\t\t\tp7start\n");

	//sema P teil
	printf("\t\t\t\t\t\tP(9)\n");
	if (-1==P(sem9)) {
		/* Fehler */
		perror("semop P9");
	}

	printf("\t\t\t\t\t\tP(10)\n");
	if (-1==P(sem10)) {
		/* Fehler */
		perror("semop P10");
	}

	//work teil
	printf("\t\t\t\t\t\twork\n");
	srand(sem9);
	sleep((rand()%10)+1);

	//sema V teil

	//endeteil
	printf("\t\t\t\t\t\tp7ende\n");

	exit(0);
}
