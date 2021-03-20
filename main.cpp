#include <iostream>
#include <fstream>
#include "Permutations.h"
#include "Time.h"
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include "Time.h"



int main() {
    long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;
                
    
    printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
 
    Time *time;
    Permutations* perm;
    perm = new Permutations();
    time = new Time();


    perm->RunProgram();

    gettimeofday(t,NULL);
    printf("Final: seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 


}
