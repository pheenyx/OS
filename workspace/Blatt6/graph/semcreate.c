/*
 * semcreate.c
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
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

	//0 bleibt leer um papierkompatibel zu sein
	int semID[11];
	int i;
	for (i = 1; i <= 10; i++){
		//erst vorhandene loeschen
		if (sem_open(i)>=0) {
			sem_delete(i);
		}

		//dann neue anlegen
		semID[i] = sem_create(i,0);
		if (semID[i] < 0){
			perror("Semaphore create Fehler");
			exit(-1);
		} else {
			printf("Semaphor mit key %i und semID %i und Wert %i erstellt.\n",i,semID[i],sem_read(semID[i]));
		}
	}
	exit(0);
}


