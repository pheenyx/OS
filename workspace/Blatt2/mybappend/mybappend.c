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
            printf("Aufruf: mybappend filetoappend appendixfile\n");
            return -1;
	}
	filefrom = open(argv[1], O_WRONLY|O_RDONLY|O_APPEND);
	if (filefrom < 0){
            printf("Datei nicht gefunden\n");
            return -2;
	}
	fileto = open(argv[2], O_RDONLY );
	if (fileto < 0){
            printf("Datei 2 konnte nicht gefunden werden\n");
            return -3;
	}
        
        int filesize = lseek(fileto, 0, SEEK_END);
        printf( "Laenge: %i\n", filesize);
        
	for (int i = 0 ; i<= filesize; i++) {
            int tmp = lseek(fileto, i, SEEK_SET);
            sizeread = read(fileto, buffer, buffersize);
            if (sizeread < 0){
                printf ("Fehler beim Lesen\n");
		return -5;
            }
            printf( "Position %i gelesenes byte %s\n", tmp, buffer);
            sizewritten = write(filefrom, buffer, sizeread);
            if (sizewritten < 0){
                printf ("Fehler beim Schreiben\n");
                return -6;
            }
 	} 

	
	printf("Datei %s erweitert um %s in %d byte Schritten.\n",argv[1], argv[2], buffersize);

	return 0;
}
