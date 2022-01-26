#include <stdio.h>
#include <math.h>
#include <hamakou.h>
#include "complex.h"

main()
{
    Complex l,c,r,z,one;
    double f,rad;
    f = 100 * pow(10,3);
    l = cCreate(0,2 * f * M_PI * 200 * pow(10,-6));
    c = cCreate(0,-1 / (2 * f * M_PI * 0.127 * pow(10,-6)));
    r = cCreate(25,0);
    one = cCreate(1,1);
    z = cDiv(one,cAdd(cDiv(one,cAdd(r,l)),cDiv(one,c)));
    printf("Z = ");
    cPrint(z);
    printf("[Ω]\n");

    printf("Zの大きさ = %lg[Ω]\n",cBig(z));

    rad = cRad(z);
    printf("Z の 位相角 = %lg[rad]\n",rad);
    return(0);
}