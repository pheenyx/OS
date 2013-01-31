/* Beispielprogramm zum Aufgabenblatt 2 */

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[] ){

	int filefrom, fileto, sizeread, sizewritten;
	int buffersize = 1;
	char buffer[buffersize];
		

	if (argc != 3){
		printf("Aufruf: mybcp fromfile tofile\n");
		return -1;
	}
	filefrom = open(argv[1], O_RDONLY);
	if (filefrom < 0){
		printf("Datei nicht gefunden\n");
		return -2;
	}
	fileto = creat(argv[2], 00700 );
	if (fileto < 0){
		printf("Datei konnte nicht geschrieben werden\n");
		return -3;
	}

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


	
	printf("Datei %s kopiert nach %s in %d byte Schritten.\n",argv[1], argv[2], buffersize);

	return 0;
}
