/*
 * sohn1.c
 *
 *  Created on: 28.11.2012
 *      Author: Michael Mardaus
 */

/* Sohn 1 zum Aufgabenblatt 4 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[] ){
	//ausgaben zum prozess
	printf("Sohn_1:\t");
	printf("pid: %i\t", getpid());
	printf("ppid: %i\n", getppid());
	system("date");
	//10sec blockieren
	sleep(10);
	//vereinbarter exit status zum erkennen des sohns
	exit(1);
}
