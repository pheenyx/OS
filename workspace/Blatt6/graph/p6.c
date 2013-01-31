/*
 * p6.c
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

	int sem5,sem6,sem8,sem10;

	sem5 = sem_open(5);
	if (sem5 < 0){
		perror("Semaphore5 open Fehler");
		exit(-1);
	}
	sem6 = sem_open(6);
	if (sem6 < 0){
		perror("Semaphore6 open Fehler");
		exit(-1);
	}
	sem8 = sem_open(8);
	if (sem8 < 0){
		perror("Semaphore8 open Fehler");
		exit(-1);
	}
	sem10 = sem_open(10);
	if (sem10 < 0){
		perror("Semaphore10 open Fehler");
		exit(-1);
	}

	//startteil
	printf("\t\t\t\t\tp6start\n");

	//sema P teil
	printf("\t\t\t\t\tP(5)\n");
	if (-1==P(sem5)) {
		/* Fehler */
		perror("semop P5");
	}

	printf("\t\t\t\t\tP(6)\n");
	if (-1==P(sem6)) {
		/* Fehler */
		perror("semop P6");
	}

	printf("\t\t\t\t\tP(8)\n");
	if (-1==P(sem8)) {
		/* Fehler */
		perror("semop P8");
	}

	//work teil
	printf("\t\t\t\t\twork\n");
	srand(sem8);
	sleep((rand()%10)+1);

	//sema V teil
	printf("\t\t\t\t\tV(10)\n");
	if (-1==V(sem10)) {
		/* Fehler */
		perror("semop V10");
	}

	//endeteil
	printf("\t\t\t\t\tp6ende\n");

	exit(0);
}
