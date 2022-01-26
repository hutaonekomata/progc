#include <stdio.h>
#include <math.h>
#include <hamakou.h>
#include "complex.h"

/**
 * @brief
 * 与えられた複素数から、複素数の大きさを求める
 * @param z
 * @return double
*/
double cBig(Complex z){
    return(sqrt( cReal(z) * cReal(z) + cImag(z) * cImag(z)));
}

/**
 * @brief
 * 与えられた複素数から位相角を求める
 * @param z
 * @return double
*/
double cRad(Complex z){
    double rad;
    if(0 < cReal(z) && 0 < cImag(z)){
        rad = atan(cImag(z)/cReal(z));
    }else if(cReal(z) < 0 && 0 < cImag(z)){
        rad = M_PI - atan(cImag(z)/cReal(z));
    }else if(cReal(z) < 0 && cImag(z) < 0){
        rad = atan(cImag(z)/cReal(z)) - M_PI;
    }else{
        rad = atan(cImag(z)/cReal(z));
    }
    return(rad);
}

/**
 * @brief
 * 与えられた実数a,bから複素数a+jbを初期化する
 * @param a
 * @param b
 *
 * @return Complex
*/
Complex cCreate(double a, double b){
    Complex Com;
    Com.real = a;
    Com.imag = b;
    return(Com);
}

/**
 * @brief
 * x = a + jb　の実数部aを取り出す
 * @param x
 *
 * @return double
 *
*/
double cReal(Complex x){
    return(x.real);
}

/**
 * @brief
 * x = a + jb　の虚数部bを取り出す
 * @param x
 *
 * @return double
 *
*/
double cImag(Complex x){
    return(x.imag);
}

/**
 * @brief
 * x = a + jb , y = c + jd　の時、x + y を計算する
 * @param x
 * @param y
 *
 * @return Complex
*/
Complex cAdd(Complex x, Complex y){
    double suba,subb;
    suba = cReal(x) + cReal(y);
    subb = cImag(x) + cImag(y);
    return(cCreate(suba,subb));
}
/**
 * @brief
 * x = a + jb , y = c + jd　の時、x - y を計算する
 * @param x
 * @param y
 *
 * @return Complex
 *
*/
Complex cSub(Complex x, Complex y){
    return(cAdd(x,cCreate(-cReal(y),-cImag(y))));
}


/**
 * @brief
 * x = a + jb , y = c + jd　の時、x * y を計算する
 * @param x
 * @param y
 *
 * @return Complex
 *
*/
Complex cMul(Complex x, Complex y){
    double suba,subb;
    suba = cReal(x) * cReal(y) - cImag(x) * cImag(y);
    subb = cReal(x) * cImag(y) + cImag(x) * cReal(y);
    return(cCreate(suba,subb));
}

/**
 * @brief
 * x = a + jb , y = c + jd　の時、x / y を計算する
 * @param x
 * @param y
 *
 * @return Complex
 *
*/
Complex cDiv(Complex x,Complex y){
    Complex suba,rev;
    double subb;
    rev = cCreate(cReal(y),-cImag(y));
    suba = cMul(x,rev);
    subb = cReal(y)*cReal(y) + cImag(y) * cImag(y);
    suba = cCreate(cReal(suba) / subb , cImag(suba) / subb);
    return(suba);
}

/**
 * @brief
 * 0除算にならないかを確認
 * @param y
 * @return int
 */
int cJudge(Complex y){
    int a;
    if(cReal(y) == 0 && cImag(y) == 0){
        printf("---<!>---\n0除算です\n---<!>---\n");
        a = 0;
    }else{
        a = 1;
    }
    return(a);
}

/**
 * @brief
 * 複素数x を a + bj のように表示する
 * @param x
 */
void cPrint(Complex x){
    // char c = '+';
    // if(cImag(x) < 0){
    //     c = '-';
    // }
    // printf("%lg %c %lgj",cReal(x),c,cImag(x));
    if(cReal(x) == 0 && cImag(x) == 0){
        printf("0");
    }else{
        if(cReal(x) != 0){
            printf("%lg",cReal(x));

        }
        if(cImag(x) != 0){
            char c = '+';
            if(cImag(x) < 0){
                c = '-';
            }
            printf(" %c %lgj",c,fabs(cImag(x)));
        }
    }

    return;
}