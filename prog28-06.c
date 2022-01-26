#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n);

int main(int argc, char *argv[])
{
  int m, n;

  if (argc < 3) {
    fprintf(stderr, "引数に２つの整数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &m);
  sscanf(argv[2], "%d", &n);

  printf("%d\n", gcd(m, n));

  return(0);
}

int gcd(int m, int n)
{
  if(n == 0){
    return(m);
  }else if(0 < n){
    return(gcd(n,m%n));
  }
}
