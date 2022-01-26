#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define DECK 53
#define JOKER 53

void readyDeck(int *deck);
void shuffleNum(Stack p[],int deck[]);
char BGjudge(int data1,int data2);
void setMark(int data,char *mark);

int main()
{
	int data[2];
	int ans[2] = {0,0};
	int origin[DECK];
	Stack p[2];
	for(int i=0;i<2;i++){
		initStack(&p[i]);
	}
	char c;
	char mark[2];
	// -------Function of readyDeck------------
	readyDeck(origin); // 一つの山をシャッフル
	// -------Fuction of shuffleNum---------
	shuffleNum(p,origin); // 二つの山にシャッフル済みの山を仕分ける
	// 10回ループを回す
	// // 表示する
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++){
			pop(&p[j],&data[j]);
			ans[j] += (data[j] % 13);
		}
		// ------Function of BGjudge----------
		c = BGjudge(data[0],data[1]);
		for(int j=0;j<2;j++){
			setMark(data[j],&mark[j]);
		}
		printf("(%2d回目) ",i+1);
		// printf("Player1 : %c[%2d] %c Player2 : %c[%2d] ",mark1,data1,c,mark2,data2);
		for(int j=0;j<2;j++){
			printf("Player%d : ",j+1);
			if(mark[j] == 'J'){
				printf("%c     ",mark[j]);
			}else{
				printf("%c[%2d] ",mark[j],data[j]%13);
			}
			if(j == 0){
				printf("%c ",c);
			}
		}
		printf("総得点 - Player1 : %3d, Player2 : %3d\n",ans[0],ans[1]);
	}
	// ２人の総得点を出力する
	for(int i=0;i<2;i++){
		printf("Player%dの得点 : %d\n",i+1,ans[i]);
	}
	return(0);
}

/**
 * @brief 値の初期化かつ、デッキのシャッフル
 *
 * @param mout [pointer]
 */
void readyDeck(int *mout){
	for(int i=0;i<DECK;i++){
		mout[i] = i+1;
	}
	int temp,k;
	// SHUFFLE
	for(int i=0;i<DECK;i++){
		k = rand() % DECK;
		temp = mout[k];
		mout[k] = mout[DECK-k];
		mout[DECK-k] = temp;
	}
	return;
}


/**
 * @brief シャッフルされたデッキを二つの山に分ける
 *
 * @param p
 * @param deck
 */
void shuffleNum(Stack p[],int deck[]){
	for(int i=0;i<DECK;i++){
		if(i%2==0){
			push(&p[i%2],deck[i]);
			// printf("0\n");
		}else{
			push(&p[i%2],deck[i]);
			// printf("1\n");
		}
	}
	return;
}

/**
 * @brief 与えられた2数を比べて、大小関係の記号を返す
 *
 * @param data1
 * @param data2
 */
char BGjudge(int data1,int data2){
	int c;
	if(data1 == JOKER || data2 == JOKER) // JOKERの場合別処理
	{
		if(data1 == JOKER)
		{
			c = '>';
		}
		else
		{
			c = '<';
		}
	}
	else
	{
		if((data1 % 13) > (data2 % 13))
		{
			c = '>';
		}
		else if((data1 % 13) < (data2 % 13))
		{
			c = '<';
		}
		else
		{
			c = '=';
		}
	}
	return(c);
}

/**
 * @param 与えられた値から記号を求め第二引数のポインタを通して記号を返す
 *
 * @param data
 * @param *mark
 */
void setMark(int data,char *mark){
	if(data == JOKER){
		*mark = 'J';
		return;
	}
	switch((data-1)/13){
		case 0:
			*mark = 'D';
			break;
		case 1:
			*mark = 'H';
			break;
		case 2:
			*mark = 'S';
			break;
		case 3:
			*mark = 'C';
	}
	return;
}