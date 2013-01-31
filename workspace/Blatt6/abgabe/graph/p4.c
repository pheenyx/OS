/*
 * p4.c
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

	int sem3,sem7,sem8;

	sem3 = sem_open(3);
	if (sem3 < 0){
		perror("Semaphore3 open Fehler");
		exit(-1);
	}
	sem7 = sem_open(7);
	if (sem7 < 0){
		perror("Semaphore7 open Fehler");
		exit(-1);
	}
	sem8 = sem_open(8);
	if (sem8 < 0){
		perror("Semaphore8 open Fehler");
		exit(-1);
	}


	//startteil
	printf("\t\t\tp4start\n");

	//sema P teil
	printf("\t\t\tP(3)\n");
	if (-1==P(sem3)) {
		/* Fehler */
		perror("semop P3");
	}


	//work teil
	printf("\t\t\twork\n");
	srand(sem3);
	sleep((rand()%10)+1);

	//sema V teil
	printf("\t\t\tV(7)\n");
	if (-1==V(sem7)) {
		/* Fehler */
		perror("semop V7");
	}

	printf("\t\t\tV(8)\n");
	if (-1==V(sem8)) {
		/* Fehler */
		perror("semop V8");
	}

	//endeteil
	printf("\t\t\tp4ende\n");

	exit(0);
}
