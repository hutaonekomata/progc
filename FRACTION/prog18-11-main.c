#include <stdio.h>
// #include <stdlib.h> // abs()関数を使用するために必要 <- fraction.cで使うため
#include "fraction.h"

void frcPrintOperation(char op, Fraction x, Fraction y);
int gcm(int m, int n);

main()
{
  Fraction a, b, c;
  int i;
  char op[] = "+-*/";

  // 2つの分数をキーボードより入力する
  printf("a: ");
  a = getFraction();
  printf("b: ");
  b = getFraction();
  printf("c: ");
  c = getFraction();
  a = frcMul(a,a);
  a = frcSub(a,b);
  frcPrintOperation(op[3],a,c);
  putchar('\n'); // 見やすくするために改行

  return(0);
}

// 分数xと分数yに、2項演算(x op y)を実行した結果を表示する
//   [引　数] op   : 2項演算子（+, -, *, /)
//            x, y : 演算対象となる分数
//   [表示例] 1/2 + 1/4 = 3/4
void frcPrintOperation(char op, Fraction x, Fraction y)
{
  Fraction a;

  switch (op) {
  case '+':
    a =frcAdd(x,y); break;
  case '-':
    a =frcSub(x,y); break;
  case '*':
    a =frcMul(x,y); break;
  case '/':
    a =frcDiv(x,y); break;
  default:
    printf("%c: 演算子が不正です。\n", op);
    return;
  }
  a = frcReduction(a);
  frcPrint(x); printf(" %c ", op); frcPrint(y); printf(" = "); frcPrint(a);
  putchar('\n');

  return;
}