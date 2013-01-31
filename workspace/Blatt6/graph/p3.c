/*
 * p3.c
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

	int sem2,sem6;

	sem2 = sem_open(2);
	if (sem2 < 0){
		perror("Semaphore2 open Fehler");
		exit(-1);
	}
	sem6 = sem_open(6);
	if (sem6 < 0){
		perror("Semaphore6 open Fehler");
		exit(-1);
	}


	//startteil
	printf("\t\tp3start\n");

	//sema P teil
	printf("\t\tP(2)\n");
	if (-1==P(sem2)) {
		/* Fehler */
		perror("semop P2");
	}

	//work teil
	printf("\t\twork\n");
	srand(sem2);
	sleep((rand()%10)+1);

	//sema V teil
	printf("\t\tV(6)\n");
	if (-1==V(sem6)) {
		/* Fehler */
		perror("semop V6");
	}

	//endeteil
	printf("\t\tp3ende\n");

	exit(0);
}
