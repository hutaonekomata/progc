#include<stdio.h>

typedef struct {
  int bunsi;   // 分子
  int bunbo; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int bunsi, int bunbo);
Fraction frcMul(Fraction x, Fraction y);
void frcPrint(Fraction x);

int main()
{
  Fraction a, b, c;

  a = getFraction();   // 分数aをキーボードより入力する

  printf("a = ");
  frcPrint(a);         // 入力した分数aを表示
  putchar('\n');

  b =frcCreate(2,3); // 分数bは2/3

  printf("b = ");
  frcPrint(b);         // 分数bを表示
  putchar('\n');

  c = frcMul(a,b);    // c = a * b

  printf("a * b = ");
  frcPrint(c);         // 乗算結果である分数cの表示
  putchar('\n');

  return(0);
}

/**
 * 機能：
 *
 * @brief Get the Fraction object
 *
 * @return Fraction
 *
 */
Fraction getFraction(void){
    Fraction a;
    char c[256];
    fgets(c,sizeof(c),stdin);
    sscanf(c,"%d/%d",&a.bunsi,&a.bunbo);
    return(a);
}
/**
 *機能：与えられた二数から、分数を構造体として返す
 *
 * @brief
 *
 * @param bunsi
 * @param bunbo
 * @return Fraction
 */
Fraction frcCreate(int bunsi, int bunbo){
    Fraction b;
    b.bunsi = bunsi;
    b.bunbo = bunbo;
    return(b);
}
/**
 * @brief
 *
 * @param x
 * @param y
 * @return Fraction
 */
Fraction frcMul(Fraction x, Fraction y){
  Fraction c;
  c.bunbo = x.bunbo * y.bunbo;
  c.bunsi = x.bunsi * y.bunsi;
  return(c);
}
/**
 * @brief
 *
 * @param x
 */
void frcPrint(Fraction x){
  printf("%d/%d",x.bunsi,x.bunbo);
}


