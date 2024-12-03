#include "header.h"

Partion_Marker p_m;

int main(int count,char * args[])
{
    if (count > 2)
    {
        p_m.fd=open(args[1], O_WRONLY);
        if (p_m.fd==-1)
        {
            fprintf(stderr,"open fd is failed\n");   
            return 1;
        }
    } else
    {
        printf("enter disk f exp: /dev/sdX\n");
        return 1;
    }

    if (args[2]=="mbr")
    {
        initMbr();
        writeExecMbr();
        writeTableMbr();
        cleanMbr();
    }
    else 
    {

    }
    
    return 0;
}