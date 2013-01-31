/*
 * gibaus_ex.c
 *
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
 */

/* Ausgabefunktion zum Aufgabenblatt 6 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sema.h"

const ITERATIONS=10;
const ANZ_ZEICHEN = 20;


/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {
	if (argc != 3){
		printf("Usage: gibaus single_character sleep_time\n");
		exit(-1);
	}

	//versuch eine neue semphore mit startwert 1 zu öffnen
	//wenn schon vorhanden dann nur öffnen
	int semid = sem_create(23,1);
	if (semid < 0){
		semid = sem_open(23);
		if (semid < 0){
			perror("Semaphore open/create Fehler");
			exit(-1);
		}
	}

	//printf("wert nach create/open %i\n",sem_read(semid));

	char zeichen =(int)argv[1][0];
	int sleep_time = atoi(argv[2]);


	int i,j;
	for (i = 0; i < ITERATIONS; i++){
		//P vor krit. Bereich
		if (-1==P(semid)) {
			/* Fehler */
			perror("semop P");
		}
		//kritischer Bereich anfang
		for (j = 0; j < ANZ_ZEICHEN; j++){
			printf("%c",zeichen);
			fflush(NULL);
			sleep(sleep_time);
		}
		printf("\n");
		//kritischer Bereich ende, dann V
		if (-1==V(semid)) {
			/* Fehler */
			perror("semop V");
		}
	}

	//semaphore wird nicht mehr gebraucht
	//sem_delete(23);

	exit(0);
}
