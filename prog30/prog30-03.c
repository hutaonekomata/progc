#include <stdio.h>

#define MAP_SIZE 25

int countPath(int x, int y);

int map[MAP_SIZE][MAP_SIZE] = {{0}};  // この配列で、各交差点を通る道筋の総数をメモしておく

int main(void)
{
  int a, b, n, x, y, i;

  scanf("%d %d", &a, &b);   // 南北方向の道路の本数，東西方向の道路の本数を入力
  scanf("%d", &n);          // 工事中の交差点の数を入力

  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y); // n個の工事中の交差点の位置を入力し、
    map[x][y] = -1;         // 通行できないことを-1で表す
  }
  printf("%d\n", countPath(a, b));

  return(0);
}

int countPath(int x, int y)
{
  if(x == 1 && y == 1){
    return 1;
  }
  if(x <= 0 || y <= 0){
    return 0;
  }
  if(map[x][y] != -1){
    if(map[x][y] != 0){
      return map[x][y];
    }else{
      map[x][y] = countPath(x-1,y) + countPath(x,y-1);
      return map[x][y];
    }
  }else{
    return 0;
  }
}
