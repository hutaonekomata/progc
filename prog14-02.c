#include <stdio.h>
#include <hamakou.h>

#define MAX_SIZE 50 // マップの最大サイズ


int readMap(char map1[][MAX_SIZE+1]);
void showMap(int n,char map1[][MAX_SIZE +1]);
void transformMap(int method,int n,char map1[][MAX_SIZE +1],char map2[][MAX_SIZE +1]);

main()
{
  char map1[MAX_SIZE][MAX_SIZE + 1]; // 元のマップを格納する２次元配列
  char map2[MAX_SIZE][MAX_SIZE + 1]; // 変換後のマップを格納する２次元配列
  int n;                             // 入力したマップのサイズ

  n = readMap(map1);
  if (n < 0) {
    printf("マップサイズが上限を超えています。\n");
  } else {
    printf("\n元の図形\n");
    showMap(n, map1);

    printf("\n90゜右回転\n");
    transformMap(1, n, map1, map2);
    showMap(n, map2);

    printf("\n90゜左回転\n");
    transformMap(2, n, map1, map2);
    showMap(n, map2);

    printf("\n左右反転\n");
    transformMap(3, n, map1, map2);
    showMap(n, map2);

    printf("\n上下反転\n");
    transformMap(4, n, map1, map2);
    showMap(n, map2);
    putchar('\n');  // 見やすくするための改行
  }

  return(0);
}

//-------------------------------------------------------------------------------
//  サイズｎのマップmap1[][]を第２引数で指定した方法で変換し、map2[][]に格納する
//  但し、読み込んだ変換後のマップデータはヌル文字で終端され、改行文字は含まない
//
//    第１引数  method   ： 変換方法
//                          1:90゜右回転, 2:90゜左回転, 3:左右反転, 4:上下反転
//    第２引数  n        ： 表示するマップのサイズ
//    第３引数  map1[][] ： 変換元のマップが格納された２次元配列
//    第４引数  map2[][] ： 変換後のマップを格納する２次元配列
//    戻り値             ： なし
//
//  ※ 変換後、map1の内容は変化しない。
//     但し、map1とmap2の配列が同一の場合、変換後のmap1とmap2の内容は不定
//-------------------------------------------------------------------------------
void transformMap(int method,int n,char map1[][MAX_SIZE +1],char map2[][MAX_SIZE +1])
{
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      switch(method){
        case 1:
          map2[j][n-i-1]=map1[i][j];
          break;
        case 2:
          map2[n-j-1][i]=map1[i][j];
          break;
        case 3:
          map2[i][n-j-1]=map1[i][j];
          break;
        case 4:
          map2[n-i-1][j]=map1[i][j];
      }
    }
    map2[i][n]='\0';
  }
  return;
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
int readMap(char map1[][MAX_SIZE + 1])
{
  int i, n;
  int len;
  n = getint("");

  if (n > MAX_SIZE) {
    return(-1);  // 最大サイズを超えるマップは読み込まない
  } else {
    for (i = 0; i < n; i++) {
      len = getstring("",map1[i]);
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
void showMap(int n,char map1[][MAX_SIZE + 1])
{
  int i, j;

  for (i = 0; i < n; i++) {
    printf("%s\n",map1[i]);
  }

  return;
}

