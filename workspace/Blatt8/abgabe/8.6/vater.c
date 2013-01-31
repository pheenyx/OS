/*
 * vater.c
 *
 *  Created on: 28.01.2013
 *      Author: Michael Mardaus
 */

/* Vaterprogramm zum Aufgabenblatt 8 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {

	int pid_tmp1, pid_tmp2;
	int status1;
	char buf1[20];
	char buf2[20];

	int pipefd[2];
	int pipeerror;

	//anon pipe erzeugen
	pipeerror = pipe(pipefd);
	if (pipeerror < 0) {
		perror ("Fehler beim anlegen der pipe\n");
	}

	//aufruf parameter erzeugen
	sprintf(buf1, "%i", pipefd[0]);
	sprintf(buf2, "%i", pipefd[1]);
	char *argv1[] = { "verbr", buf1 , NULL};
	char *argv2[] = { "erzeug", buf2, "10", "3", "1" , NULL } ;

	//printf("leseende %i und schreibende %i\n",pipefd[0], pipefd[1] );

	//forken und programme ausführen
	pid_tmp1 = fork();
	if (pid_tmp1 < 0){
		perror("Fehler beim ersten fork\n");
		exit(EXIT_FAILURE);
	} else if (pid_tmp1 == 0) {
		//return 0 dann bin ich im verbr-sohn also schreibende schliessen
		close (pipefd[1]);
		if (execv("verbr", argv1 ) < 0){
			perror ("Fehler beim Start von verbr\n");
			exit(EXIT_FAILURE);
		}
	}

	// hier bin ich im vater
	pid_tmp2 = fork();
    if (pid_tmp2 < 0){
    	perror("Fehler beim zweiten fork\n");
    	exit(EXIT_FAILURE);
    } else if (pid_tmp2 == 0) {
		//return 0 also sind wir im erzeug-sohn also leseende schliessen
    	close (pipefd[0]);
		if (execv("erzeug", argv2 ) < 0){
			perror("Fehler beim Start von erzeug\n");
			exit(EXIT_FAILURE);
		}
	}

	//hier sind wir wieder im vater
    //vater muss seine fd schliessen damit die pipe nicht mehr offen bleibt
    // und der verbraucher auch zu geht
    close(pipefd[0]);
    close(pipefd[1]);

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
				printf("verbr fertig, pid: %i\n", pid_wait);
				system("date");
				finished++;
			}
			//wenn der vereinbarte status 2 kommt war es sohn2
			if (WEXITSTATUS(status1) == 2) {
				printf("erzeug fertig, pid: %i\n", pid_wait);
				system("date");
				finished++;
			}
		}
	}
	exit(0);

}
