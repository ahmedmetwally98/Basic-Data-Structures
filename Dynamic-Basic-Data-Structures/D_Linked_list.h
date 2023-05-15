/**
 * @file D_Linked_list.h
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, we declare data type of List data structure and related operations (Interfaces).
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#ifndef _D_LINKED_LIST_H
#define _D_LINKED_LIST_H

#include <stdlib.h>

/* user define data type of the structrue */
typedef int list_elem_t;

/********************* Data structure definition *************************/
typedef struct listnode {
    list_elem_t entry;
    struct listnode* next;
    struct listnode* prev;
}listNode;

typedef struct{
    int size;
    listNode* head;
    listNode* tail;
}list_t;

/******************* Data structure definition end ***********************/

/******************* Function declaration ********************************/
void          createList        (list_t* a_plist);
int           listSize          (list_t* a_plist);
unsigned char listIsEmpty       (list_t* a_plist);
unsigned char listInsertElement (list_t* a_plist, list_elem_t* a_pdata, int pos);
unsigned char list_push_back    (list_t* a_plist, list_elem_t* a_pdata);
unsigned char list_push_front   (list_t* a_plist, list_elem_t* a_pdata);
unsigned char listDeleteElement (list_t* a_plist, int pos);
unsigned char listRetriveElement(list_t* a_plist, list_elem_t* a_pdata, int pos);
unsigned char listReplaceElement(list_t* a_plist, list_elem_t* a_pdata, int pos);
void          listPrint         (list_t* a_plist, void (*fPtr)(list_elem_t), char order);
void          listDestroy       (list_t* a_plist);

/******************* Function declaration end ********************************/

#endif      // _D_LINKED_LIST_H