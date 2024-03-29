#include <stdio.h>
#include <hamakou.h>

#define MAX_SIZE 50 // マップの最大サイズ

int readMap(char map[][MAX_SIZE+1]);
void showMap(int n,char map[][MAX_SIZE +1]);

main()
{
  char map[MAX_SIZE][MAX_SIZE + 1]; // マップを格納する２次元配列（１文字分はヌル文字のため）
  int n;                            // 入力したマップのサイズ

  n = readMap(map); // マップの入力
  putchar('\n');    // 見やすくするための改行

  printf("入力したマップのサイズ: %d\n\n", n); // 入力マップサイズの確認

  if (n > 0) {
    showMap(n, map);  // マップの表示
    putchar('\n');    // 見やすくするための改行
  }

  return(0);
}

//-------------------------------------------------------------------------------
//  ｎ行ｎ列のマップを引数で指定した２次元配列に読み込み、読み込んだマップの
//  サイズｎを返す。
//
//  但し、ｎの最大値は MAX_SIZE とし、これを超えるサイズのマップデータは一切
//  配列に読み込まず、-1 を返す。また、読み込んだマップデータ各行はヌル文字で
//  終端され、改行文字は含まない。
//
//    引数  map[][] ： マップを読み込む２次元配列
//    戻り値        ： 読み込んだマップのサイズ
//                     但し、MAX_SIZE を超えたときは -1 を返す
//-------------------------------------------------------------------------------
int readMap(char map[][MAX_SIZE + 1])
{
  int i, n;
  int len;
  n = getint("");

  if (n > MAX_SIZE) {
    return(-1);  // 最大サイズを超えるマップは読み込まない
  } else {
    for (i = 0; i < n; i++) {
      len = getstring("",map[i]);
    }
    return(n);   // マップのサイズを返す
  }
}

//-------------------------------------------------------------------------------
//  引数で指定したサイズｎのマップを表示する
//    第１引数  n       ： 表示するマップのサイズ
//    第２引数  map[][] ： マップが格納された２次元配列
//    戻り値            ： なし
//-------------------------------------------------------------------------------
void showMap(int n,char map[][MAX_SIZE + 1])
{
  int i, j;

  for (i = 0; i < n; i++) {
    printf("%s\n",map[i]);
  }

  return;
}
