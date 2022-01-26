#include <stdio.h>
#include <hamako.h>

int betweenSum(int left,int right);

main()
{
  int left, right;

  left = getint("left: ");
  right = getint("right: ");

  printf("%d～%d までの和: %d\n", left, right,betweenSum(left,right));

  return(0);
}

int betweenSum(int left, int right)
{
  int ans=0;
  /*for(int i=left;i<=right;i++){
    ans+=i;
  }*/
  ans=(left+right)*(right-left+1)/2;
  return(ans);
}
