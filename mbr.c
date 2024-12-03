#include "header.h"

extern Partion_Marker p_m;


//из 512 первые 440 как я понял код исполняемый мбр, до 444 уникальная сигнатура, до 446 не используется, до 510 таблица разделов, до 512 сигнатура мбр

//                                                                                                         ^каждая запись 16 байт
//1 активность 1 номер головки диска начало 2 номер цилиндра сектора начало 1 код типа раздела 1 номер головки диска  конец 2 номер цилиндра сектора конец 4 номер сектора раздела 4 число сектора раздела
void initMbr()
{
    p_m.part_buf=calloc(512,sizeof(__uint8_t));
}

void writeExecMbr()
{
    __uint8_t mbr_code[]={};

    for (int i = 0; i < 440; i++)
    {
        p_m.part_buf[i]=mbr_code[i];
    }

    for (int i = 440; i < 444; i++)
    {
        p_m.part_buf[i]=0b0;
    }
    for (int i = 444; i <446; i++)
    {
        p_m.part_buf[i]=0b0;
    }
}

void writeTableMbr()
{
    int count=446;
    for (int i = 0; i < 4; i++)
    {
        for (int i = 0; i < 16; i++)
        {

        }
        count+=16;
    }
}


void cleanMbr()
{
    write(p_m.fd,p_m.part_buf,sizeof(*p_m.part_buf));
    free(p_m.part_buf);
    close(p_m.fd);
}