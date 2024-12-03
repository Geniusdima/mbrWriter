#ifndef LIB
#define LIB
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct 
{
    __uint8_t * part_buf;
    int fd;
} Partion_Marker;

extern Partion_Marker p_m;

extern void initGpt();

extern void cleanGpt();

extern void initMbr();

extern void writeExecMbr();

extern void writeTableMbr();

extern void cleanMbr();


#endif


