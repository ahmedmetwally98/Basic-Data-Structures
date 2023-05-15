/**
 * @file S_Queue.h
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, we declare data type of queue data structure and related operations (Interfaces).
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _S_QUEUE_H
#define _S_QUEUE_H

#include <stdlib.h>
/* user define */
#define QUEUE_MAX_SIZE           100
/* user define */
typedef int queue_elem_t;
/********************* Data structure definition *************************/
typedef struct{
    int size;
    int front;
    int rear;
    void* ptr_node[QUEUE_MAX_SIZE];
}queue_t;
/******************* Data structure definition end ***********************/


/******************* Function declaration ********************************/
void          createQueue     (queue_t* a_queuePtr);
unsigned char queueAppend     (queue_t* a_queuePtr, queue_elem_t* a_dataPtr);
unsigned char queueServe      (queue_t* a_queuePtr, queue_elem_t* a_dataPtr);
unsigned char queueFront      (queue_t* a_queuePtr, queue_elem_t* a_dataPtr);
int           queueIsEmpty    (queue_t* a_queuePtr);
int           qeueuIsFull     (queue_t* a_queuePtr);
int           queueSize       (queue_t* a_queuePtr);
void          queuePrint      (queue_t* a_queuePtr, void(*)(queue_elem_t));
void          clearQueue      (queue_t* a_queuePtr);
/******************* Function declaration end ********************************/

#endif          // _S_QUEUE_H