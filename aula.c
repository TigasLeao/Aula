#include "stdio.h"

int main(){

    int i;
    float n, ma, me, mg, acn;
    acn = 0;

    for(i=1;i<=5;i++)
    {
        printf("digite um numero: ");
        scanf("%f", &n);
        acn = acn + n;
        if(i==1){
            ma = n;
            me = n;
        }
        if(n > ma){
            ma = n;
        }
        if(n < me){
        me = n;
        }
    }
    mg = acn/5;

    printf("Média geral: %.2f\n", mg);
    printf("Maior nota: %.2f\n", ma);
    printf("Menor nota: %2.f", me);


    return 0;
}
