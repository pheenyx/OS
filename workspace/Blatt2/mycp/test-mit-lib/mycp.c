/* Beispielprogramm zum Aufgabenblatt 2 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "timelib.h"

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[] ){

	int filefrom, fileto, sizeread, sizewritten;
        struct stat sb;
	struct tstamp t;

        if (argc != 4){
	    printf("Aufruf: mybcp fromfile tofile buffersize\n");
	    return -1;
	}

        if (stat(argv[1], &sb) == -1){
            perror("stat");
            exit(EXIT_FAILURE);
        }

        if (sb.st_mode &  S_IFMT != S_IFREG){
            printf("%s ist keine regulaere Datei\n", argv[1]);
            return -10;
        }

        int buffersize = atoi(argv[3]);
	char buffer[buffersize];

	filefrom = open(argv[1], O_RDONLY);
	if (filefrom < 0){
		printf("Datei nicht gefunden\n");
		return -2;
	}
	fileto = creat(argv[2], sb.st_mode );
	if (fileto < 0){
		printf("Datei konnte nicht geschrieben werden\n");
		return -3;
	}

	start(&t);
	do {
		sizeread = read(filefrom, buffer, buffersize);
		if (sizeread < 0){
			printf ("Fehler beim Lesen\n");
			return -5;
		}
		sizewritten = write(fileto, buffer, sizeread);
		if (sizewritten < 0){
			printf ("Fehler beim Schreiben\n");
			return -6;
		}
 	} while (sizeread > 0);
	stop(&t);

	printf("Datei %s kopiert nach %s in %d byte Schritten.\n",argv[1], argv[2], buffersize);
	printf("Dauer %li microsec\n", extime(&t));

	return 0;
}


