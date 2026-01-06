#include<stdio.h>
enum week{
    sun=1,mon,tues,wed,thurs,fri,sat
};
enum month{
    jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};
int main()
{
    enum week day;
    enum month month;
    //printf("enter the day");
    //scanf("%S",&day);
    day=wed;
    month=aug;
    printf("index of the day = %d\n",day);
    printf("indewx of the month = %d",month);
    return 0;
}
