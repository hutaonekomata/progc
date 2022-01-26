//cc -c stack2.c ; ar crv libstack2.a stack2.o ; cc prog22-03.c -o STACK2 -L . -l stack2
//cc -shared -fPIC -o libstack.so stack.c ; cc prog22-03.c -L . -l stack
#include<stdio.h>
#include "stack.h"

/**
 * @brief
 *  => 配列の初期化
 *
 * @param s
 *  => Stack型の変数のポインタ
 */
void initStack(Stack *s){
	// if(s->sp<0){
	// 	return;
	// }
	// while(s->sp+1){
	// 	s->sp--;
	// 	s->strage[s->sp] = NUM_INIT;
	// }
	s->sp = SP_INIT2;
	return;
}

/**
 * @brief
 * 	=> 指定されたスタックに指定したデータを追加する
 * @param s
 * 	=> データ追加対象のスタック
 * @param data
 * 	=> 追加したいデータ
 * @return int
 */
int push(Stack *s,int data){
	if((s->sp)+2 > STACK_SIZE ){
		return(FAIL);
	}
	s->sp++;
	s->strage[s->sp] = data;
	return(SUCCESS);
}

/**
 * @brief
 * 	=> スタックからデータを取り出す
 * @param s
 * 	=> データを取り出したいスタックのポインタ
 * @param data
 * 	=> 取り出したデータを格納する変数のポインタ
 * @return int
 */
int pop(Stack *s,int *data){
	if((s->sp) > SP_INIT2){
		*data = s->strage[s->sp];
		s->sp--;
		return(SUCCESS);
	}
	return(FAIL);
}