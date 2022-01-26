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

main()
{
    Complex x, y, z;
    double a, b;

    printf("x <- 実数部 虚数部："); // 実数部と虚数部の入力
    scanf("%lg %lg", &a, &b);
    x = cCreate(a, b);              // 複素数ｘの初期化

    printf("y <- 実数部 虚数部："); // 実数部と虚数部の入力
    scanf("%lg %lg", &a, &b);
    y = cCreate(a, b);              // 複素数ｙの初期化

    putchar('\n');
    printf("複素数 x = "); cPrint(x); putchar('\n');
    printf("複素数 y = "); cPrint(y); putchar('\n');
    printf("の四則演算\n");

    z = cAdd(x, y); // 加算
    printf("x + y = "); cPrint(z); putchar('\n');
    z = cSub(x, y); // 減算
    printf("x - y = "); cPrint(z); putchar('\n');
    z = cMul(x, y); // 乗算
    printf("x * y = "); cPrint(z); putchar('\n');
    z = cDiv(x, y); // 徐算
    printf("x / y = "); cPrint(z); putchar('\n');


    return(0);
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
    double a,b,c,d,z;
    a = cReal(x);
    b = cImag(x);
    c = cReal(x);
    d = cImag(x);
    z = c * c + d * d;
    return(cCreate((a * c + b * d)/z,(b * c - a * d) / z));
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
    double a,b;
    a = cReal(x);
    b = cImag(x);

    if(b == 0){
        printf("%g",a);
    }else if(a == 0 && b != 0){
        printf("%gj",b);
    }else if(b < 0){
        printf("%g - %gj",a,-b);
    }else if(b > 0){
        printf("%g + %gj",a,b);
    }else{
        printf("NaN");
    }
    return;
}