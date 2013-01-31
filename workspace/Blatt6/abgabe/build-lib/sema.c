/*
 * sema.c
 *  Created on: 19.12.2012
 *  Author: Michael Mardaus
 */

/* Lib zum Aufgabenblatt 6 */

#include "sema.h"

int P(int semid){
	//semop vorbereiten
	struct sembuf sops;
	sops.sem_num = 0; //id der semaphore im set
	sops.sem_op = -1;  //operation proberen = -1
	//sops.sem_flg = SEM_UNDO;  //OS raeumt auf falls proc stirbt

	return semop(semid, &sops, 1);
}

int V(int semid){
	//semop vorbereiten
	struct sembuf sops;
	sops.sem_num = 0; //id der semaphore im set
	sops.sem_op = 1;  //operation verhogen = 1
	//sops.sem_flg = SEM_UNDO;  //OS raeumt auf falls proc stirbt

	return semop(semid, &sops, 1);
}

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

