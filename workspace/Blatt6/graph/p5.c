/*
 * p5.c
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

	int sem4,sem7,sem9;

	sem4 = sem_open(4);
	if (sem4 < 0){
		perror("Semaphore4 open Fehler");
		exit(-1);
	}
	sem7 = sem_open(7);
	if (sem7 < 0){
		perror("Semaphore7 open Fehler");
		exit(-1);
	}
	sem9 = sem_open(9);
	if (sem9 < 0){
		perror("Semaphore9 open Fehler");
		exit(-1);
	}

	//startteil
	printf("\t\t\t\tp5start\n");

	//sema P teil
	printf("\t\t\t\tP(4)\n");
	if (-1==P(sem4)) {
		/* Fehler */
		perror("semop P4");
	}

	printf("\t\t\t\tP(7)\n");
	if (-1==P(sem7)) {
		/* Fehler */
		perror("semop P7");
	}

	//work teil
	printf("\t\t\t\twork\n");
	srand(sem7);
	sleep((rand()%10)+1);

	//sema V teil
	printf("\t\t\t\tV(9)\n");
	if (-1==V(sem9)) {
		/* Fehler */
		perror("semop V9");
	}

	//endeteil
	printf("\t\t\t\tp5ende\n");

	exit(0);
}
