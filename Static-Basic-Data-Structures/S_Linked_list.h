/**
 * @file S_Linked_list.h
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, we declare data type of List data structure and related operations (Interfaces).
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#ifndef _S_LINKED_LIST_H
#define _S_LINKED_LIST_H

#include <stdlib.h>

/* user define */
#define LIST_MAX_SIZE           100
/* user define */
typedef int list_elem_t;

/********************* Data structure definition *************************/
typedef struct{
    int size;
    void* ptr_node[LIST_MAX_SIZE];
}list_t;
/******************* Data structure definition end ***********************/

/******************* Function declaration ********************************/
void          createList        (list_t* a_listPtr);
int           listSize          (list_t* a_listPtr);
unsigned char listIsEmpty       (list_t* a_listPtr);
unsigned char listIsFull        (list_t* a_listPtr);
unsigned char listInsertElement (list_t* a_listPtr, list_elem_t* a_dataPtr, int pos);
unsigned char list_push_front   (list_t* a_listPtr, list_elem_t* a_dataPtr);
unsigned char list_push_back    (list_t* a_listPtr, list_elem_t* a_dataPtr);
unsigned char listDeleteElement (list_t* a_listPtr, int pos);
unsigned char listRetriveElement(list_t* a_listPtr, list_elem_t* elem, int pos);
unsigned char listReplaceElement(list_t* a_listPtr, list_elem_t* elem, int pos);
void          listPrint         (list_t* a_listPtr, void (*fPtr)(list_elem_t), char order);
void          listDestroy       (list_t* a_listPtr);

 /******************* Function declaration end ********************************/

#endif      // _S_LINKED_LIST_H