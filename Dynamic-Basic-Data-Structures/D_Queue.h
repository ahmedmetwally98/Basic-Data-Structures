/**
 * @file D_Queue.h
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, we declare data type of queue data structure and related operations (Interfaces).
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _D_QUEUE_H
#define _D_QUEUE_H

#include <stdlib.h>

/* user define */
typedef int queue_elem_t;

/********************* Data structure definition *************************/
typedef struct queuenode
{
    queue_elem_t entry;
    struct queuenode* next;
}queueNode;

typedef struct{
    queueNode* front;
    queueNode* rear;
    int size;
}queue_t;

/******************* Data structure definition end ***********************/

/******************* Function declaration ********************************/
void          createQueue     (queue_t* a_queue);
unsigned char queueAppend     (queue_t* a_queue, queue_elem_t* a_data);
unsigned char queueServe      (queue_t* a_queue, queue_elem_t* a_elem_ptr);
unsigned char queueFront      (queue_t* a_queue, queue_elem_t* a_elem_ptr);
int           queueIsEmpty    (queue_t* a_queue);
int           queueSize       (queue_t* a_queue);
void          queuePrint      (queue_t* a_queue, void(*)(queue_elem_t));
void          clearQueue      (queue_t* a_queue);
/******************* Function declaration end ********************************/


#endif          // _D_QUEUE_H