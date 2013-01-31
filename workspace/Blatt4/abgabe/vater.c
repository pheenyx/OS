/*
 * vater.c
 *
 *  Created on: 28.11.2012
 *      Author: Michael Mardaus
 */

/* Vaterprogramm zum Aufgabenblatt 4 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int pid_sohn1, pid_sohn2, pid_vater, pid_tmp1, pid_tmp2, i;
	int status1, status2;

	const int ITERATIONS = 11;
	const int SLEEP_TIME = 1;

	pid_tmp1 = fork();
	if (pid_tmp1 < 0){
		printf("Fehler beim ersten fork\n");
		exit(EXIT_FAILURE);
	} else if (pid_tmp1 == 0) {
		//return 0 dann bin ich im sohn1
		if (execve("sohn1", NULL, NULL ) < 0){
			printf("Fehler beim Start von Sohn1\n");
			exit(EXIT_FAILURE);
		}
	}

	// hier bin ich im vater
	pid_sohn1 = pid_tmp1;
	pid_tmp2 = fork();
    if (pid_tmp2 < 0){
    	printf("Fehler beim zweiten fork\n");
    	exit(EXIT_FAILURE);
    } else if (pid_tmp2 == 0) {
		//return 0 also sind wir im sohn2
		if (execve("sohn2", NULL, NULL ) < 0){
			printf("Fehler beim Start von Sohn2\n");
			exit(EXIT_FAILURE);
		}
	}

	//hier sind wir im vater
	pid_sohn2 = pid_tmp2;

	//ausgaben der pids
	printf("Vater: \t");
	printf("pid: %i\t", getpid());
	printf("pid sohn1: %i\t", pid_sohn1);
	printf("pid sohn2: %i\n", pid_sohn2);
	for ( i=0; i<ITERATIONS; i++){
		sleep(SLEEP_TIME); //blockieren
		system("date");
		system("ps -l -y"); //prozesse ausgeben

		//optional pstree ausgabe
		//char buffer[20];
		//snprintf(buffer, sizeof(buffer), "pstree -G %i ", getppid());
		//system(buffer);
	}
	system("date");

	//variable zum zaehlen wieviele soehne sich zurueck gemeldet haben
	int finished = 0;
	//warten bis 2 soehne fertig sind
	while (finished < 2){
		int pid_wait = wait(&status1);
		if (pid_wait < 0){
			printf("Fehler beim Warten auf Soehne.\n");
			exit(EXIT_FAILURE);
		} else {
			//wenn der vereinbarte status 1 kommt war es sohn1
			if (WEXITSTATUS(status1) == 1) {
				printf("Sohn 1 fertig, pid: %i\n", pid_wait);
				system("date");
				finished++;
			}
			//wenn der vereinbarte status 2 kommt war es sohn2
			if (WEXITSTATUS(status1) == 2) {
				printf("Sohn 2 fertig, pid: %i\n", pid_wait);
				system("date");
				finished++;
			}
		}
	}
	exit(0);

}
