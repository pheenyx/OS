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


struct tstamp {
        struct timeval     t1;  /* time 1 */
        struct timeval     t2;  /* time 2 */
};

void start(struct tstamp *t){
    gettimeofday(&t->t1, NULL); 
}; 

void stop(struct tstamp *t){
    gettimeofday(&t->t2, NULL); 
 //   printf("%li\n", t->t1->tv_sec);
 //   printf("%li\n", t->t2->tv_sec);
};

unsigned long extime(struct tstamp *t){
    unsigned long time1, time2;
    time1 = t->t1.tv_sec * 1000000 + t->t1.tv_usec;
    time2 = t->t2.tv_sec * 1000000 + t->t2.tv_usec;
    return time2-time1;
};

/*
 *  Hauptprogramm
 */
int main(int argc, char** argv) {
    
    //struct timeval *tv;
    
    
    
    
    struct tstamp t;
    //t = (struct tstamp*) malloc(2 * sizeof(*t));
    //t->t1 = malloc(sizeof(struct timeval));
    //t->t2 = malloc(sizeof(struct timeval)); 
    
   
    //times(buf);
    //printf("Ausgabe von times: %i", (int)buf->tms_utime);
    
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

