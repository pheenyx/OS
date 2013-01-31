#ifndef _timelib_h_
#define _timelib_h_
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>
struct tstamp {
        struct timeval     t1;  /* time 1 */
        struct timeval     t2;  /* time 2 */
};
void start(struct tstamp *t);
void stop(struct tstamp *t);
unsigned long extime(struct tstamp *t);
#endif /*!_timelib_h_*/
