#include <stdio.h>
#include <stdlib.h>

#include "stack27.h"

/**
 * @brief init the Stack data
 *
 * @param Stack
 *
 * @return void
 */
void initStack(Stack *s){
	*s = getEmptyList();
	return;
}

/**
 * @brief add a data to Stack
 *
 * @param Stack
 * @param data
 *
 * @return int
 */
int push(Stack *s,int data){
	return(insertHead(s,data));
}

/**
 * @brief take a data from Stack
 *
 * @param Stack
 * @param data
 *
 * @return int
 */
int pop(Stack *s,int *data){
	if(isEmptyList(*s)){
		return(0);
	}
	*data = getCellData(*s);
	return(removeHead(s));
}

/**
 * @brief free all of the data from Stack
 *
 * @param Stack
 *
 * @return void
 */
void freeStack(Stack *s){
	removeList(s);
	return;
}