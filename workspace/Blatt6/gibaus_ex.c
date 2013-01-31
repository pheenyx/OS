/*
 * gibaus_ex.c
 *
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
 */

/* Ausgabefunktion zum Aufgabenblatt 6 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
union semun {
	int val;
	struct semid_ds *buf;
};


const ITERATIONS=10;
const ANZ_ZEICHEN = 20;


int P(int semid){
	//semop vorbereiten
	struct sembuf sops;
	sops.sem_num = 0; //id der semaphore im set
	sops.sem_op = -1;  //operation proberen = -1
	sops.sem_flg = SEM_UNDO;  //OS raeumt auf falls proc stirbt

	return semop(semid, &sops, 1);
}

int V(int semid){
	//semop vorbereiten
	struct sembuf sops;
	sops.sem_num = 0; //id der semaphore im set
	sops.sem_op = 1;  //operation verhogen = 1
	sops.sem_flg = SEM_UNDO;  //OS raeumt auf falls proc stirbt

	return semop(semid, &sops, 1);
}

//int init_sem(int semid, int init_value){
//	//semctrl vorbereiten
//	struct ipc_perm perm;
//	perm.uid = getuid();
//	perm.gid = getgid();
//	perm.mode = 0400|0200;
//
//	struct semid_ds ds;
//	ds.sem_perm = perm;
//	ds.sem_nsems = 1;
//
//	union semun un;
//	un.val = init_value;
//	un.buf = &ds;
//
//	return semctl(semid, 0, IPC_SET, un);
//}

int sem_read(int semid){
	//semctl vorbereiten und auslesen
	unsigned short out[1];
	if (0==semctl(semid, 1, GETALL, out)){
		return out[0];
	} else {
		perror("semctl getall");
		return -1;
	}
}

int sem_create(int key, int start_value){
	//semaphore erstellen
	int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
	printf("semid %i\n\n",semid);
	if (semid >= 0){
		//create war ok, semaphore befüllen
		unsigned short init[1];
		init[0]=start_value; //startwert setzen
		if (0 == semctl(semid, 1, SETALL, init)){
			return semid;
		} else {
			perror("semget ctl setall");
			return -1;
		}
	} else {
		perror("semget create");
		return -1;
	}
}

int sem_open(int key){
	int semid = semget(key,1,0666);
	if (semid >= 0){
		return semid;
	} else {
		perror("semget open");
		return -1;
	}
}

int sem_delete(int key){
	int semid = semget(key, 1, 0666);
	if (semid >= 0) {
		/* zerstöre die Semaphore */
		return semctl(semid, 0, IPC_RMID, 0);
	} else { /* semctl lief schief */
		perror("semget delete");
		return -1;
	}
}

/* ------------------------------------ */
/* Hauptprogramm                        */
/* ------------------------------------ */

int main(int argc, char* argv[]) {
	if (argc != 3){
		printf("Usage: gibaus single_character sleep_time\n");
		exit(-1);
	}

	//versuch eine neue semphore mit startwert 1 zu öffnen
	//wenn schon vorhanden dann nur öffnen
	int semid = sem_create(23,1);
	if (semid < 0){
		semid = sem_open(23);
		if (semid < 0){
			perror("Semaphore open/create Fehler");
			exit(-1);
		}
	}

	printf("wert nach create/open %i\n",sem_read(semid));

	char zeichen =(int)argv[1][0];
	int sleep_time = atoi(argv[2]);


	int i,j;
	for (i = 0; i < ITERATIONS; i++){
		printf("vor krit %i\n",sem_read(semid));
		//P vor krit. Bereich
		if (-1==P(semid)) {
			/* Fehler */
			perror("semop P");
		}
		//kritischer Bereich anfang
		printf("in krit %i\n",sem_read(semid));
		for (j = 0; j < ANZ_ZEICHEN; j++){
			printf("%c",zeichen);
			fflush(NULL);
			sleep(sleep_time);
		}
		printf("\n");
		//kritischer Bereich ende, dann V
		if (-1==V(semid)) {
			/* Fehler */
			perror("semop V");
		}
		printf("nach krit %i\n",sem_read(semid));
	}

	//semaphore wird nicht mehr gebraucht
	//sem_delete(23);

	exit(0);
}
