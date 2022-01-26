#include <stdio.h>
#include <math.h>
#include <hamakou.h>

// Complex型の定義
typedef struct {
    double cmplx[2];
} Complex;

// 抽象データ型として扱うために必要になる関数群
Complex cAdd(Complex x, Complex y);   // x + y
Complex cSub(Complex x, Complex y);   // x - y
Complex cMul(Complex x, Complex y);   // x * y
Complex cDiv(Complex x, Complex y);   // x / y
void    cPrint(Complex x);            // 複素数の表示
Complex cCreate(double a, double b);  // a + bj の設定
double  cReal(Complex x);             // 実数部の取得
double  cImag(Complex x);             // 虚数部の取得
int cJudge(Complex y);                // 0除算にならないかを確認
double cRad(Complex z);               // 位相角を求める
double cBig(Complex z);               // 複素数から複素数の大きさを求める

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
    Com.cmplx[0] = a;
    Com.cmplx[1] = b;
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
    return(x.cmplx[0]);
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
    return(x.cmplx[1]);
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