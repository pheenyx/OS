/*
 * p2.c
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

	int sem1,sem4,sem5;

	sem1 = sem_open(1);
	if (sem1 < 0){
		perror("Semaphore1 open Fehler");
		exit(-1);
	}
	sem4 = sem_open(4);
	if (sem4 < 0){
		perror("Semaphore4 open Fehler");
		exit(-1);
	}
	sem5 = sem_open(5);
	if (sem5 < 0){
		perror("Semaphore5 open Fehler");
		exit(-1);
	}

	//startteil
	printf("\tp2start\n");

	//sema P teil
	printf("\tP(1)\n");
	if (-1==P(sem1)) {
		/* Fehler */
		perror("semop P1");
	}

	//work teil
	printf("\twork\n");
	srand(sem4);
	sleep((rand()%10)+1);

	//sema V teil
	printf("\tV(4)\n");
	if (-1==V(sem4)) {
		/* Fehler */
		perror("semop V4");
	}

	printf("\tV(5)\n");
	if (-1==V(sem5)) {
		/* Fehler */
		perror("semop V5");
	}

	//endeteil
	printf("\tp2ende\n");

	exit(0);
}
