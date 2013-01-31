/*
 * File:   timelib.c
 * Author: pheenyx
 *
 * Created on November 21, 2012, 5:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/time.h>
#include "timelib.h"

/*
 *  Hauptprogramm
 */
int main(int argc, char** argv) {

    struct tstamp t;
    //t = (struct tstamp*) malloc(2 * sizeof(*t));
    //t->t1 = malloc(sizeof(struct timeval));
    //t->t2 = malloc(sizeof(struct timeval));

    int i;
    start(&t);
    for (i=1; i<=100; i++){
        //sleep(1);
        printf("i = %i\n",i);
    }
    stop(&t);

    printf("benoetigte Zeit: %li\n", extime(&t));

    return (EXIT_SUCCESS);
}

