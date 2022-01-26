#include<stdio.h>
#include"queue.h"

/**
 * @brief init Queue data
 *
 * @param q
 */
void initQueue(Queue *q){
	q->head = 0;
	q->tail = 0;
}

/**
 * @brief Input Data to QUEUE
 *
 * @param *q
 * @param data
 *
 * @return int
 *
 */
int enQueue(Queue *q, int data){
	if((q->tail +1) % QUEUE_SIZE == (q->head) % QUEUE_SIZE){
		return(0);
	}else{
		q->tail = (q->tail + 1) % QUEUE_SIZE;
		q->strage[q->tail] = data;
		return(1);
	}
}

/**
 *
 * @brief Output Data form QUEUE
 *
 * @param *q
 * @param *data
 *
 * @return int
 */
int deQueue(Queue *q, int *data){
	if(q->head == q->tail){
		return(0);
	}else{
		q->head = (q->head + 1) % QUEUE_SIZE;
		*data = q->strage[q->head];
		return(1);
	}
}