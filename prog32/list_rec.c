#include<stdio.h>
#include<stdlib.h>
#include<hamako.h>
#include"list.h"

// 20220103CHANGED

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
 * @brief
 *
 * @param head
 * @return int
 */
int removeTail(List **head){
	if(isEmptyList(*head)){
		return(0);
	}
	if(isEmptyList(getNextCell(*head)) == 0){
		return(removeTail(getNextCellHead(*head)));
	}else{
		return(removeHead(head));
	}
}

/**
 * @brief print all data in List
 *
 * @param head
 * @return int
 */
void printList(List *head){
	if(isEmptyList(head)){
		printf("\n");
	}else{
		printf("%d",getCellData(head));
		if(!isEmptyList(getNextCell(head))){
			printf(" -> ");
		}
		printList(getNextCell(head));
	}
	return;
}

/**
 * @brief
 *
 * @param head
 * @param data
 * @return int
 */
int insertUpOrder(List **head,int data){
	if(isEmptyList(*head) == 0 && getCellData(*head) < data){
		return(insertUpOrder(getNextCellHead(*head),data));
	}else{
		return(insertHead(head,data));
	}
}

/**
 * @brief
 *
 * @param head
 * @param data
 * @return int
 */
int removeSearch(List **head,int data){
	if(isEmptyList(*head) || getCellData(*head) == data){ // 基底条件で考えた方が条件式が簡単になる
		return(removeHead(head));
	}else{
		return(removeSearch(getNextCellHead(*head),data));
	}
}

/**
 * @brief
 *
 * @param head
 * @return int
 */
int countCells(List *head){
	if(isEmptyList(head) == 0 && isEmptyList(getNextCell(head)) == 0){
		return(countCells(getNextCell(head)) + 1);
	}else{
		return 1;
	}
}

/**
 * @brief
 *
 * @param head
 * @return int
 */
int sumOfCellsData(List *head){
	List *next;
	if(isEmptyList(head) == 0 && isEmptyList(getNextCell(head)) == 0){
		next = getNextCell(head);
		return(getCellData(head) + sumOfCellsData(next));
	}else{
		return(getCellData(head));
	}
}

/**
 * @brief
 *
 * @param head
 */
void removeList(List **head){
	if(isEmptyList(*head) == 0 && isEmptyList(getNextCell(*head)) == 0){
		removeList(getNextCellHead(*head));
	}
	removeHead(head);
	return;
}

/**
 * @brief
 *
 * @param head
 * @param data
 * @return int
 */
int appendTail(List **head,int data){
	if(isEmptyList(*head) == 0){
		return(appendTail(getNextCellHead(*head),data));
	}else{
		return(insertHead(head,data));
	}
}

/**
 * @brief
 *
 * @param head
 * @return List*
 */
List *reverseList(List *head){
	if(isEmptyList(head) == 0){
		List* p = reverseList(getNextCell(head));
		if(appendTail(&p,getCellData(head)) == 0){
			removeList(&p);
		}
		return(p);
	}else{
		return(getEmptyList());
	}
}