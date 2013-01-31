/*
 * erzeug.c
 *
 *  Created on: 24.01.2013
 *      Author: Michael Mardaus
 */

/* Erzeuger zu Blatt 8.4 */

#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

const int ITERATIONS = 20;
const int SLEEP_TIME = 1;

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int writeend, sizewritten;
	int pid = getpid();
	int buffersize = 20;
	char buffer[buffersize];

	if (argc != 2) {
		printf("Aufruf: erzeug pipename\n");
		exit(EXIT_FAILURE);
	}


	writeend = open(argv[1], O_WRONLY);
	if (writeend < 0) {
		perror("Pipe nicht gefunden\n");
		exit(EXIT_FAILURE);
	}

	int i;
	for (i = 0; i < ITERATIONS; i++) {
		sprintf(buffer, "<%i>:<%i>\n",pid,i);
		sizewritten = write(writeend, buffer, strlen(buffer));
		if (sizewritten < 0) {
			perror("Fehler beim Schreiben\n");
			exit(EXIT_FAILURE);
		}
		sleep(SLEEP_TIME);
	}

	exit(EXIT_SUCCESS);
}

