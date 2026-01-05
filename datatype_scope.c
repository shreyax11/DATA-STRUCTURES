#include<stdio.h>
void show()
{
    static int s;
    auto int a;
    s=0;
    a=0;
    s++;
    a++;
    printf("static=%d \n auto=%d",s,a);
}
int x=10;
int main()
{
    int i;
    extern int x;
    printf("extern = %d\n",x);
    for(i=0;i<2;i++)
    {
        show();
        printf("\n");
    }
    return 0;
}
