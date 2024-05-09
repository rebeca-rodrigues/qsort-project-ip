#include <stdio.h>
#include <time.h> 
//#include <string.h>


#include <unistd.h>
#define Sleep(x) usleep((x)*1000000)
const float DELAY = 1;


void main () {
  struct timespec t;
  struct timespec t2;
  clock_gettime(CLOCK_MONOTONIC, &t);
  printf ("%ld, %ld\n", t.tv_sec, t.tv_nsec);
  
  Sleep(DELAY);
  
  clock_gettime(CLOCK_MONOTONIC, &t2);
  printf ("%ld, %ld\n", (t2.tv_sec - t.tv_sec), (t2.tv_nsec - t.tv_nsec));
  
  
 }
