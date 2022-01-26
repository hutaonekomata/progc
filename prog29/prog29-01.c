#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hamakou.h>

void rotate(char *word, int n);
void anagram(char *word, int n);

main(int argc, char *argv[])
{
  int pos, n;
  char *word;

  if (argc < 2) {
    fprintf(stderr, "アナグラムを作る文字列をコマンドライン引数で指定して下さい。\n");
    exit(1);
  }
  word = argv[1];
  anagram(word, strlen(word));

  return(0);
}

// 文字列wordの右からn文字分を左回りで1文字回転させる
void rotate(char *word, int n)
{
  int Wsize = strlen(word) - n;
  char k = *(word + Wsize);
  // printf("! %d %d %c\n",n,Wsize,k);
  for(int i=0;i < n - 1;i++){
    *(word + Wsize + i) = *(word + Wsize + i + 1);
  }
  *(word + strlen(word) - 1) = k;
  return;
}

void anagram(char *word, int n)
{
  if(n <= 1){
    printf("%s\n",word);
    return;
  }
  for(int i=0;i<n;i++){
    anagram(word,n-1);
    rotate(word,n);
  }
}
