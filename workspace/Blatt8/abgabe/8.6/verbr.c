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
#include <string.h>

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int readend;
	int sizeread;
	int buffersize = 100;
	char buffer[buffersize];

	//eingabe checken
	if (argc != 2) {
		printf("Aufruf: verbr pipename\n");
		exit(EXIT_FAILURE);
	}

	//geerbten filedescriptor hernehmen
	readend = atoi(argv[1]);
	if (readend < 0) {
		perror("Pipe nicht gefunden\n");
		exit(EXIT_FAILURE);
	}

	//pipe auslesen
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
//alternative mit char buffer;
//	while( read(readend, &buffer, 1)>0 ){
//		write(STDOUT_FILENO, &buffer ,1);
//	}
//	write(STDOUT_FILENO,"\n", 1);


	//fertig also fd schliessen und raus
	close(readend);
	exit(1);
}

