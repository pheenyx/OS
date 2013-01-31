/* 
 * File:   timelib.c
 * Author: Michael Mardaus
 *
 * Created on November 21, 2012, 5:43 PM
 */

#include "timelib.h"

void start(struct tstamp *t){
    gettimeofday(&t->t1, NULL);
};

void stop(struct tstamp *t){
    gettimeofday(&t->t2, NULL);
};

unsigned long extime(struct tstamp *t){
    unsigned long time1, time2;
    time1 = t->t1.tv_sec * 1000000 + t->t1.tv_usec;
    time2 = t->t2.tv_sec * 1000000 + t->t2.tv_usec;
    return time2-time1;
};

