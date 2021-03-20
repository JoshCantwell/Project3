#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include "Time.h"

void Time::getTime() {
      
    long i;
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;
                
    
    printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
                    
    
    for (i = 0; i < 3000000000; i++) { 
                                
        if(i % 100000000 ==0) {
                              
            gettimeofday(t,NULL);
            
            printf("time is now seconds %d microseconds %d\n",t->tv_sec - startSec,t->tv_usec); 
            
        } 
        
    }
    gettimeofday(t,NULL);
    printf("Final: seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 

}
