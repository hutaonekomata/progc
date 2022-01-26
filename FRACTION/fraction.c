#include <stdio.h>
#include <stdlib.h> // abs()関数を使用するために必要
#include "fraction.h"

int gcm(int m, int n);

// Fraction型で表される分数の分子の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分子の値
int frcGetNumerator(Fraction x)
{
  return(x.numerator);
}

// Fraction型で表される分数の分母の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分母の値
int frcGetDenominator(Fraction x)
{
  return(x.denominator);
}

// キーボードより、a/bの形で分数を入力する
//   [引　数] なし
//   [戻り値] Fraction型で表現される分数
Fraction getFraction(void)
{
  char buff[256];
  int n, d;
  do{

    fgets(buff, sizeof(buff), stdin);
    sscanf(buff,"%d/%d",&n,&d);
    if(d==0){
      printf("無効な数字です\n");
    }
  }while(d==0);
  return(frcCreate(n,d));
}

// 分子と分母の値からFraction型で表される分数を返す
//   [引　数] numerator   : 分子の値
//            denominator : 分母の値
//   [戻り値] Fraction型で表現される分数
Fraction frcCreate(int numerator, int denominator)
{
  Fraction x;
  x.numerator = numerator;
  x.denominator = denominator;
  return(x);
}

// 分数xとyの加算結果を返す
//   [引　数] x, y : 加算対象となる分数
//   [戻り値] x + y を計算して得られる分数
Fraction frcAdd(Fraction x, Fraction y)
{
  int xn,xm,yn,ym;
  xn = frcGetNumerator(x);
  xm = frcGetDenominator(x);
  yn = frcGetNumerator(y);
  ym = frcGetDenominator(y);
  int key = (xm * ym) / gcm(xm,ym);
  xn = xn * (key/xm);
  yn = yn * (key/ym);
  return(frcCreate(xn+yn,key));
}

// 分数xとyの減算結果を返す
//   [引　数] x, y : 減算対象となる分数
//   [戻り値] x - y を計算して得られる分数
Fraction frcSub(Fraction x, Fraction y)
{
  int xn,xm,yn,ym;
  xn = frcGetNumerator(x);
  xm = frcGetDenominator(x);
  yn = frcGetNumerator(y);
  ym = frcGetDenominator(y);
  int key = ( xm * ym ) / gcm(xm,ym);
  xn = xn * (key/xm);
  yn = yn * (key/ym);
  return(frcCreate(xn-yn,key));
}

// 分数xとyの乗算結果を返す
//   [引　数] x, y : 乗算対象となる分数
//   [戻り値] x * y を計算して得られる分数
Fraction frcMul(Fraction x, Fraction y)
{
  int xn,xm,yn,ym;
  xn = frcGetNumerator(x);
  xm = frcGetDenominator(x);
  yn = frcGetNumerator(y);
  ym = frcGetDenominator(y);
  return(frcCreate(xn*yn,xm*ym));
}

// 分数xとyの除算結果を返す
//   [引　数] x, y : 除算対象となる分数
//   [戻り値] x / y を計算して得られる分数
Fraction frcDiv(Fraction x, Fraction y)
{
  int xn,xm,yn,ym;
  xn = frcGetNumerator(x);
  xm = frcGetDenominator(x);
  yn = frcGetNumerator(y);
  ym = frcGetDenominator(y);
  return(frcCreate(xn*ym,xm*yn));
}

// 分数xの既約分数を返す
//   [引　数] x : 約分対象となる分数
//   [戻り値] xの既約分数
Fraction frcReduction(Fraction x)
{
  int xn,xm;
  xn = frcGetNumerator(x);
  xm = frcGetDenominator(x);
  if(xm==0||xn==0){
    return(x);
  }
  int key = gcm(xn,xm);
  return(frcCreate(xn/key,xm/key));
}

// mとnの最大公約数を正数で返す
//   [引　数] m, n : 最大公約数を求める対象となる整数
//   [戻り値] mとmの最大公約数
int gcm(int m, int n)
{
  int r;

  // 最大公約数を正数にするため、m,nの絶対値をとる
  m = abs(m);
  n = abs(n);

  r = m % n;
  while (r != 0) {
    m = n;
    n = r;
    r = m % n;
  }
  return(n);
}

// 分数xを a/b の形で表示する（分数の値が負になるとき、符号は分子につける）
//   [引　数] x : 表示する分数
void frcPrint(Fraction x)
{
  int n, d;

  n = frcGetNumerator(x);
  d = frcGetDenominator(x);

  if (n < 0 && d > 0) {
    n = -abs(n);
    d = abs(d);
  } else {
    n = abs(n);
    d = abs(d);
  }
  if (n == 0 || d == 1) {
  printf("%d",n);
  } else {
  printf("%d/%d",n,d);
  }

  return;
}
