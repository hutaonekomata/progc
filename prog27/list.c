#include<stdio.h>
#include<stdlib.h>
#include<hamako.h>
#include"list.h"

/**
 * @brief Get the Empty List object
 *
 * @return List*
 */
List *getEmptyList(void){
	return( (List *)NULL );
}

/**
 * @brief Create a Cell object
 *
 * @param data
 * @param next
 * @return Cell*
 */
Cell *createCell(int data,List *next){
	Cell *p;
	p = (Cell *)malloc(sizeof(Cell));
	if(p != NULL){
		setCellData(p,data);
		setNextCell(p,next);
		// printf("####%d\t%d\n",p,getNextCell(p));
		return(p);
	}else{
		return(getEmptyList());
	}
}

/**
 * @brief Set the Cell Data object
 *
 * @param cell
 * @param data
 */
void setCellData(Cell *cell, int data){
	cell->data = data;
	return;
}

/**
 * @brief Get the Cell Data object
 *
 * @param cell
 * @return int
 */
int getCellData(Cell *cell){
	return(cell->data);
}

/**
 * @brief Set the Next Cell object to head Pointer
 *
 * @param cell
 * @param next
 */
void setNextCell(Cell *cell,List *next){
	cell->next = next;
	return;
}

/**
 * @brief Get the Next Cell object
 *
 * @param cell
 * @return List*
 */
List *getNextCell(Cell *cell){
	return((cell->next));
}

/**
 * @brief Judge the List object is Empty or Not
 *
 * @param head
 * @return int
 */
int isEmptyList(List *head){
	if(head == getEmptyList()){
		return(1);
	}else{
		return(0);
	}

}

/**
 * @brief Insert Data to Head of List
 *
 * @param head
 * @param data
 * @return int
 */
int insertHead(List **head,int data){
	*head = createCell(data,*head);
	if(isEmptyList(*head)){
		return(0);
	}
	// setNextCell(*head,new);
	return(1);
}

/**
 * @brief Remove data from list
 *
 * @param head
 * @return int
 */
int removeHead(List **head){
	Cell *trush;
	if(isEmptyList(*head)){
		return(0);
	}
	trush = *head;
	*head = getNextCell(*head);
	free(trush);
	return(1);
}

/**
 * @brief print out the List Data
 *
 * @param head
 * @return int
 */
int printList(List *head){
	List *p = head;
	while(isEmptyList(head) == 0){
		printf("%d",getCellData(head));
		if(isEmptyList(getNextCell(head)) == 0){
			printf(" -> ");
		}
		head = getNextCell(head);
	}
	head = p;
	return(1);
}

/**
 * @brief  insert Cell to head
 *
 * @param head
 * @param data
 * @return int
 */
int insertUpOrder(List **head,int data){
	while(isEmptyList(*head) == 0 && getCellData(*head) < data){
		head = getNextCellHead(*head);
	}
	return(insertHead(head,data));
}

/**
 * @brief get Next Cell Head
 *
 * @param cell
 *
 * @return List
 */
List **getNextCellHead(Cell *cell){
	return(&cell->next);
}

/**
 * @brief remove List's data of tail
 *
 * @param head
 * @return int
 */
int removeTail(List **head){
	while(isEmptyList(*head) == 0 && isEmptyList(getNextCell(*head)) == 0/*getNextCell(*head) != getEmptyList()*/){
		head = getNextCellHead(*head);
	}
	return(removeHead(head));
}

/**
 * @brief remove all List's data
 *
 * @param head
 */
void removeList(List **head){
	while(isEmptyList(*head) == 0){
		removeHead(head);
	}
	return;
}