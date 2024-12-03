#include "header.h"

extern Partion_Marker p_m;


void initGpt()
{
    p_m.part_buf=calloc(128*7,sizeof(__uint8_t));
}

void cleanGpt()
{
    write(p_m.fd,p_m.part_buf,sizeof(*p_m.part_buf));
    free(p_m.part_buf);
    close(p_m.fd);
}