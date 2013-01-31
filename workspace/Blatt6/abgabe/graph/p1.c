/*
 * p1.c
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

	int sem1,sem2,sem3;

	sem1 = sem_open(1);
	if (sem1 < 0){
		perror("Semaphore1 open Fehler");
		exit(-1);
	}
	sem2 = sem_open(2);
	if (sem2 < 0){
		perror("Semaphore2 open Fehler");
		exit(-1);
	}
	sem3 = sem_open(3);
	if (sem3 < 0){
		perror("Semaphore3 open Fehler");
		exit(-1);
	}

	//startteil
	printf("p1start\n");

	//sema P teil


	//work teil
	printf("work\n");
	srand(sem1);
	sleep((rand()%10)+1);

	//sema V teil
	printf("V(1)\n");
	if (-1==V(sem1)) {
		/* Fehler */
		perror("semop V1");
	}

	printf("V(2)\n");
	if (-1==V(sem2)) {
		/* Fehler */
		perror("semop V2");
	}

	printf("V(3)\n");
	if (-1==V(sem3)) {
		/* Fehler */
		perror("semop V3");
	}

	//endeteil
	printf("p1ende\n");

	exit(0);
}
