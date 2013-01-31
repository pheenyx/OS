/*
 * verbr.c
 *
 *  Created on: 24.01.2013
 *      Author: Michael Mardaus
 */

/* Verbraucher zu Blatt 8.4 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int readend, sizeread;
	int buffersize = 100;
	char buffer[buffersize];

	if (argc != 2) {
		printf("Aufruf: verbr pipename\n");
		exit(EXIT_FAILURE);
	}

	readend = open(argv[1], O_RDONLY);
	if (readend < 0) {
		perror("Pipe nicht gefunden\n");
		exit(EXIT_FAILURE);
	}

	do {
		sizeread = read(readend, buffer, 1);
		if (sizeread < 0) {
			printf("Fehler beim Lesen\n");
			exit(EXIT_FAILURE);
		}

		if (sizeread > 0){
			printf("%s",buffer);
		}
	} while (sizeread > 0);

	exit(EXIT_SUCCESS);
}

