/*
 * gibaus.c
 *
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
 */

/* Ausgabefunktion zum Aufgabenblatt 6 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

    char zeichen =(int)argv[1][0];
    int sleep_time = atoi(argv[2]);


    int i,j;
    for (i = 0; i < ITERATIONS; i++){
    	for (j = 0; j < ANZ_ZEICHEN; j++){
    		printf("%c",zeichen);
    		fflush(NULL);
    		sleep(sleep_time);
    	}
    	printf("\n");
    }

	exit(0);
}
