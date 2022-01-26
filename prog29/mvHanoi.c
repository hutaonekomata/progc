#include <stdio.h>
#include "stdlib.h"

void mvHanoi(int n, char from, char work, char to);

int main(int argc, char *argv[])
{
  int n;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number of disk>\n", argv[0]);
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  mvHanoi(n, 'A','B','C');

  return(0);
}

void mvHanoi(int n, char from, char work, char to)
{
  if (0 < n) {
    mvHanoi(n-1,from,to,work);
    printf("%c -> %c\n", from, to);
    mvHanoi(n-1,work,from,to);
  }
  return;
}
