#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocWords(int *n);
void freeWords(char **words, int n);
int rbSearch(char *target, char *words[], int n);
int rbSearchRec(char *target, char *words[], int lower, int upper);

main(int argc, char *argv[])
{
  int pos, n;
  char **words;

  if (argc < 2) {
    fprintf(stderr, "検索する単語をコマンドライン引数で指定してください。\n");
    exit(1);
  }
  words = allocWords(&n);  // 単語データを動的領域に読み込む

  pos = rbSearch(argv[1], words, n);
  printf("Found: %d\n", pos);

  freeWords(words, n);	   // allocWords()で確保した領域を開放する

  return(0);
}
/**
 * @brief 二次元の文字列ポインタを引数に応じたサイズ分動的に確保する
 *
 * @param line_nums
 * @return char**
 */
char **allocWords(int *line_nums)
{
  char k[256];
  int n;
  int i = 0;
  fgets(k,sizeof(k),stdin);
  sscanf(k,"%d",&n);
  char s[256]={};
  char **p = (char **)malloc(sizeof(char *) * (n) + 1);

  if(p == NULL){
    *line_nums = 0;
    freeWords(p,*line_nums);
    return((char **)NULL);
  }

  for(i=0;i<n;i++){
    fgets(s,sizeof(s),stdin);
    sscanf(s,"%s\n",s);
    // scanf("%s",s);
    (*(p+i)) = (char *)malloc(sizeof(char) * strlen(s) + 1);

    if((*(p+i)) == NULL){
      free(p);
      *line_nums = 0;
      return((char **)NULL);
    }

    strcpy((*(p + i)),s);

  }

  *line_nums = i;
  (*(p+n)) = (char *)NULL;
  return(p);
}

/**
 * @brief 確保した二次元の文字列ポインタを開放する
 *
 * @param lines
 * @param line_nums
 */
void freeWords(char **lines, int line_nums){
  for(int i=0;i<line_nums;i++){
    free(*(lines + i));
  }
  free(lines);
  return;
}

int rbSearch(char *target, char *words[], int n)
{
  return(rbSearchRec(target, words, 0, n - 1));
}

int rbSearchRec(char *target, char *words[], int lower, int upper)
{
  int k = (lower+upper)/2;
  if(upper < lower){
    return -1;
  }else if(0 < strcmp((*(words+k)),target)){
    return rbSearchRec(target,words,lower,k-1);
  }else if(strcmp((*(words+k)),target) < 0){
    return rbSearchRec(target,words,k+1,upper);
  }else{
    return k;
  }

}
