/*
 * erzeug.c
 *
 *  Created on: 24.01.2013
 *      Author: Michael Mardaus
 */

/* Erzeuger zu Blatt 8.4 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "sema.h"

const int ITERATIONS = 20;
const int SLEEP_TIME = 1;
const int PARTS = 3;

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int writeend, sizewritten;
	int pid = getpid();
	int buffersize = 100;
	char buffer[buffersize];
	int nummer, sleeptime1, sleeptime2;

	//eingabe checken
	if (argc != 5) {
		printf("Aufruf: erzeug pipename nummer sleeptime1 sleeptime2\n");
		exit(EXIT_FAILURE);
	}
	if ((nummer = atoi(argv[2])) == 0) {
		//kann man ueberhaupt etwas eingeben, was atoi nicht verarbeitet?
		printf("Fehler: %s ist nicht numerisch\n", argv[2]);
		printf("Aufruf: erzeug pipename nummer sleeptime1 sleeptime2\n");
		exit(EXIT_FAILURE);
	}
	if ((sleeptime1 = atoi(argv[3])) == 0) {
		printf("Fehler: %s ist nicht numerisch\n", argv[3]);
		printf("Aufruf: erzeug pipename nummer sleeptime1 sleeptime2\n");
		exit(EXIT_FAILURE);
	}
	if ((sleeptime2 = atoi(argv[4])) == 0) {
		printf("Fehler: %s ist nicht numerisch\n", argv[4]);
		printf("Aufruf: erzeug pipename nummer sleeptime1 sleeptime2\n");
		exit(EXIT_FAILURE);
	}

	printf("nummer = %i, s1 = %i, s2 = %i\n", nummer, sleeptime1, sleeptime2);

	writeend = open(argv[1], O_WRONLY);
	if (writeend < 0) {
		perror("Pipe nicht gefunden\n");
		exit(EXIT_FAILURE);
	}
	//eingabe gecheckt - los gehts

	//semaphore erstellen oder oeffnen
	//versuch eine neue semphore mit startwert 1 zu öffnen
	//wenn schon vorhanden dann nur öffnen
	int semid = sem_create(23, 1);
	if (semid < 0) {
		semid = sem_open(23);
		if (semid < 0) {
			perror("Semaphore open/create Fehler");
			exit(-1);
		}
	}

	//blankbar generieren
	int j;
	char blankbar[] = "";
	for (j = 0; j < nummer; j++) {
		strcat(blankbar, " ");
	}

	int i, p;
	for (i = 0; i < ITERATIONS; i++) {
		//P vor krit. Bereich
		if (-1 == P(semid)) {
			/* Fehler */
			perror("semop P");
		}
		//kritischer Bereich anfang

		for (p = 0; p < PARTS; p++) {
			sprintf(buffer, "%s%i:%i:%i\n", blankbar, pid, i, p);
			sizewritten = write(writeend, buffer, strlen(buffer));
			if (sizewritten < 0) {
				perror("Fehler beim Schreiben\n");
				exit(EXIT_FAILURE);
			}
			sleep(sleeptime2);
		} //msg #i komplett

		//kritischer Bereich ende, dann V
		if (-1 == V(semid)) {
			/* Fehler */
			perror("semop V");
		}
		sleep(sleeptime1);
	}

	exit(EXIT_SUCCESS);
}

