/*
 * seg_empf1.c
 *
 *  Created on: 17.01.2013
 *      Author: Michael Mardaus
 */

/* Signalempfänger zu Aufgabenblatt 8 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

const int ALARM_PERIOD = 3;

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

//handler funktion fuer signale
static void hdl(int sig, siginfo_t *siginfo, void *context) {
	//extra infos ausgeben
	printf("Sending PID: %ld, UID: %ld\n", (long) siginfo->si_pid, (long) siginfo->si_uid);
	if (sig == SIGUSR1) {
		printf("Signal SIGUSR1 empfangen\n");
	}
	if (sig == SIGUSR2) {
		printf("Signal SIGUSR2 empfangen\n");
	}
	if (sig == SIGTERM) {
		printf("Programm terminiert\n");
		exit(0);
	}
	if (sig == SIGALRM) {
		alarm(ALARM_PERIOD);
		printf("Timer neu gestellt\n");
	}
}

int main(int argc, char *argv[]) {

	//sigaction funktionshandler definieren
	struct sigaction act;
	act.sa_sigaction = hdl;
	act.sa_flags = SA_SIGINFO;

	//listener fuer signale registrieren
	if (sigaction(SIGUSR1, &act, NULL ) < 0) {
		perror("sigaction Fehler USR1");
		return 1;
	}
	if (sigaction(SIGUSR2, &act, NULL ) < 0) {
		perror("sigaction Fehler USR2");
		return 2;
	}
	if (sigaction(SIGTERM, &act, NULL ) < 0) {
		perror("sigaction Fehler Term");
		return 3;
	}
	if (sigaction(SIGALRM, &act, NULL ) < 0) {
		perror("sigaction Fehler Alarm");
		return 4;
	}

	//erstmaliges wecker stellen
	alarm(ALARM_PERIOD);
	printf("Wecker gestellt\n");

	//endlosschleife um das programm am leben zu halten
	while (1) {
		sleep(1000);
	}

	return 0;
}
