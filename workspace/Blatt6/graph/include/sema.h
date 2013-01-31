/*
 * sema.h
 *
 *  Created on: 20.12.2012
 *      Author: Michael Mardaus
 */
/* LibHeader zum Aufgabenblatt 6 */
#ifndef SEMA_H_
#define SEMA_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
	int val;
	struct semid_ds *buf;
};

int P(int semid);

int V(int semid);

int sem_read(int semid);

int sem_create(int key, int start_value);

int sem_open(int key);

int sem_delete(int key);

#endif /* SEMA_H_ */
