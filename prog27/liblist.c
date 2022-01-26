!<arch>
/               1635116443  0     0     0       160       `
   
   �   �   �   �   �   �   �   �   �   �getEmptyList createCell setCellData setNextCell getCellData getNextCell isEmptyList insertHead removeHead printList list.o/         1634973822  18031 18000 100644  3616      `
ELF          >                    �
          @     @   UH��    ]�UH��H�� �}�H�u�   �    H�E�H�}� t*�U�H�E���H���    H�U�H�E�H��H���    H�E���    ��UH��H�}��u�H�E��U��]�UH��H�}�H�E�� ]�UH��H�}�H�u�H�E�H�U�H�P�]�UH��H�}�H�E�H�@]�UH��H��H�}��    H9E�u�   ��    ��UH��SH��H�}�u�H�E�H� H���    H��H�E�H� H�ƿ    �    �    H�E�H��E�H�։��    H��H�E�H�H�E�H� H���    H��H�E�H� H�ƿ    �    �    H�E�H��    H9�u�    ��   H��[]�UH��H�� H�}�H�E�H� H���    ��t�    �@H�E�H� H�E�H�E�H� H���    H��H�E�H� H��H���    H�E�H���    �   ��UH��SH��(H�}�H�E�H�E��cH�E�H���    �ƿ    �    �    H�E�H���    H���    H9�t�    �    �    H�E�H���    H��H�E�H��H���    H�E�H���    ��u��   H��([]�%d %d
 %d  ->   GCC: (GNU) 8.4.1 20200928 (Red Hat 8.4.1-1)             zR x�                A�CF      <       U    A�CP     \           A�CR      |           A�CK      �           A�CV      �           A�CM      �       %    A�C`       �       �    A�CE��             h    A�Cc      @      �    A�CE��                               ��                                                                                                                                                                                                          U                              '     `              3     �              ?     w              K     �              W     �       %       c     �       �       n                      u     �      h       �                      �     �      �        list.c getEmptyList createCell malloc setCellData setNextCell getCellData getNextCell isEmptyList insertHead printf removeHead free printList                ��������<             ��������O             ��������Z          	   ���������          	   ���������             ��������      
                          ��������$         
   ��������=            ��������O      
              Y            ��������e         	   ���������            ���������            ���������            ���������            ��������            ��������      
                         ��������%            ��������-         	   ��������7      
      
       A            ��������M            ��������_            ��������k            ��������                      @                    `             `       �             w       �             �       �             �       �             �                    �       $            �      D            �       .symtab .strtab .shstrtab .rela.text .data .bss .rodata .comment .note.GNU-stack .rela.eh_frame                                                                                              @                                          @                      �      
                    &                     �                                     ,                     �                                     1                     �                                    9      0               �      -                             B                      �                                     W                            `                             R      @               �	      �       
                                          `               	                 	                      p      �                                                    x
      a                              list.c/         1634983017  18031 18000 100644  2206      `
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
		// printf("%d\n%d\n",next,p);
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
 * @brief Set the Next Cell object
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
	printf("%d\n",*head);
	*head = createCell(data,*head);
	printf("%d %d\n",*head,getNextCell(*head));
	if(*head == getEmptyList()){
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
	setNextCell(*head,getNextCell(*head));
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
	int i=0;
	while(isEmptyList(p) == 0){
		printf("%d",getCellData(p));
		if(getNextCell(p) != getEmptyList()){
			printf(" -> ");
		}
		printf("\nBefore:%d\n",p);
		setNextCell(p,getNextCell(p));
		printf("\nAfter:%d\n",p);
		i++;
		if(i==2)break;
	}
	return(1);
}