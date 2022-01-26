#include <stdio.h>
#include <hamakou.h>

// Complex型の定義
typedef struct {
  double real;  // 実数部
  double imag;  // 虚数部
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
            printf(" %c %lgj",%c,fabs(cImag(x)));
        }
    }

    return;
}