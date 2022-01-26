#include<stdio.h>
#include<stdlib.h>

int bit2int(int a,int n,int ans);

int main(int argc, char *argv[]){
	int d;
	if(argc < 2){
		printf("2進数を引数に指定してください");
		exit(1);
	}
	sscanf(argv[1],"%d",&d);
	printf("%d\n",bit2int(d,1,0));
	return(0);
}

int bit2int(int a,int n,int ans){
	if(0 < a){
		return(bit2int(a/10,n*2,ans+(a%10)*n));
	}else{
		return(ans);
	}
}