#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"

int main(){

int i, nr, c1, c2, c3;
nr=0; c1=0; c2=0; c3=0;
srand(time(NULL));

for(i=1;i<=20;i++)
{
    nr=rand() % 3 + 1;
    printf("%d ", nr);
    if(nr==1)
    {
        c1++;
    }
    if(nr==2)
    {
        c2++;
    }
    if(nr==3)
    {
        c3++;
    }
}
printf("\nC1: %d\n", c1);
printf("c2: %d\n", c2);
printf("c3: %d", c3);
return 0;

}
