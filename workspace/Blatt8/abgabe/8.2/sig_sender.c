/*
 * seg_sender.c
 *
 *  Created on: 22.01.2013
 *      Author: Michael Mardaus
 */

/* Signalsender zu Aufgabenblatt 8 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/* ------------------------------------ */
/* Hilfsoperationen                     */
/* ------------------------------------ */
void getarg(int * i) {
	char input[8];
	int val;
	printf("bitte einen int-Parameter eingeben! \n");
	scanf("%s", input);
	val = atoi(input);
	*i = val;
}

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main() {
	int erg;
	int sel_op;
	int signal1 = SIGUSR1;
	int signal2 = SIGUSR2;
	int delay = 5;
	int pid = 0;
	int ende = 0;

	do {
		printf("Gewuenschte Operation?   \n");
		printf("   0: signal aufstellung anzeigen\n");
		printf("   1: signal1 waehlen \t\t momentan gewaehlt: %i\n", signal1);
		printf("   2: signal2 waehlen \t\t momentan gewaehlt: %i\n", signal2);
		printf("   3: verzoegerung waehlen \t momentan gewaehlt: %i\n", delay);
		printf("   4: pid waehlen \t\t momentan gewaehlt: %i\n", pid);
		printf("   5: nur signal1 senden \n");
		printf("   6: beide signale senden \n");
		printf("  99: Programmende       \n\n");

		scanf("%d", &sel_op);
		switch (sel_op) {
		case 0:
			system("clear");
			printf(
					"1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP \n");
			printf(
					"6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1\n");
			printf(
					"11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM\n");
			printf(
					"16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP\n");
			printf(
					"21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ\n");
			printf(
					"26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR\n");
			printf(
					"31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3\n");
			printf(
					"38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8\n");
			printf(
					"43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13\n");
			printf(
					"48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12\n");
			printf(
					"53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7\n");
			printf(
					"58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2\n");
			printf("63) SIGRTMAX-1	64) SIGRTMAX	\n");
			break;
		case 1:
			system("clear");
			getarg(&signal1);
			break;
		case 2:
			system("clear");
			getarg(&signal2);
			break;
		case 3:
			system("clear");
			getarg(&delay);
			break;
		case 4:
			system("clear");
			getarg(&pid);
			break;
		case 5:
			system("clear");
			if (signal1 < 1 || signal1 > 64) {
				printf("Bitte gueltiges signal1 und pid waehlen\n");
				break;
			}

			erg = kill(pid, signal1);
			if (erg < 0) {
				perror("Fehler beim Senden von signal1");
			}
			printf("Signal1 gesendet\n");
			break;
		case 6:
			system("clear");
			if (signal1 < 1 || signal1 > 64 || delay < 1 || signal2 < 1
					|| signal2 > 64) {
				printf(
						"Bitte gueltige signal1, signal2, verzoegerung und pid waehlen\n");
				break;
			}

			erg = kill(pid, signal1);
			if (erg < 0) {
				perror("Fehler beim Senden von signal1");
			}
			printf("Signal1 gesendet\n");
			sleep(delay);
			erg = kill(pid, signal2);
			if (erg < 0) {
				perror("Fehler beim Senden von signal2");
			}
			printf("Signal2 gesendet\n");
			break;
		case 99:
			ende = 1;
			break;
		default:
			break;
		}
	} while (!ende);

	return 0;
}
