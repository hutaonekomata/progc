#include<stdio.h>
#include<hamako.h>

void chLine(char c,int n);
void chRectangle(char c,int m,int n);
void chTriangle(char c, int m);

int main(){
    int m,n;
    char c;

    n = getint("列数: ");
    m = getint("行数: ");

    c = getcharacter("長方形を描く文字: ");
    printf("\n");
    chRectangle(c , m , n);

    c = getcharacter("三角形を描く文字: ");
    printf("\n");
    chTriangle(c , m);

    return(0);
}

void chLine(char c,int n){
    for(int i=0;i<n;i++){
        printf("%c",c);
    }
    return;
}

void chRectangle(char c,int m,int n){
    for(int i=0;i<m;i++){
        chLine(c,n);
        printf("\n");
    }
    return;
}

void chTriangle(char c,int m){
    int line=1;
    int limit=1+2*(m-1);
    for(int i=0;i<m;i++){
        chLine(' ',(limit-line)/2);
        chLine(c,line);
        printf("\n");
        line+=2;
    }
    return;
}
