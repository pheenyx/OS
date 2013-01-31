/*
 * readsems.c
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
 */

/* Hilfsfktfunktion zum Aufgabenblatt 8 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sema.h"

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("usage readsems semid");
		exit(EXIT_FAILURE);
	}

	int semID;
	semID = sem_open(atoi(argv[1]));
	if (semID < 0) {
		perror("Semaphore open Fehler");
		exit(EXIT_FAILURE);
	} else {
		printf("Semaphor mit key %s und semID %i hat Wert %i\n", argv[1], semID,
				sem_read(semID));
	}
	exit(EXIT_SUCCESS);
}

