#include<stdio.h>
#include<hamako.h>

double sComResistance(double r1, double r2);
double pComResistance(double r1, double r2);

int main(){
    double r1=15,r2=20,r3=35;
    printf("直列合成抵抗 : %.2f[Ω]\n",sComResistance(r1,pComResistance(r2,r3)));
    return(0);
}

double sComResistance(double r1,double r2){
    double ans=r1+r2;
    return(ans);
}

double pComResistance(double r1,double r2){
    double ans=(r1*r2)/(r1+r2);
    return(ans);
}