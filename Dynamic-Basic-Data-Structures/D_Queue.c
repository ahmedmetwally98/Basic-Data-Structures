/**
 * @file D_Queue.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of queue data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 */
 
#include "D_Queue.h"

/**
 * @brief Create a Queue object
 * 
 * @param a_queuePtr 
 */
void createQueue (queue_t* a_queuePtr)
{
    if(a_queuePtr != NULL)
    {
        a_queuePtr->front = NULL;
        a_queuePtr->rear = NULL;
        a_queuePtr->size = 0;
    }
}

/**
 * @brief used to add new element to the queue 
 * 
 * @param a_queuePtr 
 * @param a_dataPtr 
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char queueAppend (queue_t* a_queuePtr, queue_elem_t* a_dataPtr)
{
    queueNode* ptrNode = malloc(1*sizeof(queue_elem_t));
    if(NULL == ptrNode || a_dataPtr == NULL)
    {   /* malloc can't allocate new memory in the heap */
        return 0;
    }
    else{
        ptrNode->entry = *a_dataPtr;
        ptrNode->next = NULL;
        if(a_queuePtr->size == 0)
        {   /* adding the first node to the queue */
            a_queuePtr->front = ptrNode;
        }
        else{
            a_queuePtr->rear->next = ptrNode;
        }
        a_queuePtr->rear = ptrNode;
        a_queuePtr->size++;
    }
    return 1;
}

/**
 * @brief used to get the element that is ready to be served and delete that element from the queue
 * 
 * @param a_queuePtr 
 * @param a_dataPtr 
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char queueServe (queue_t* a_queuePtr, queue_elem_t* a_dataPtr)
{
    if (queueIsEmpty(a_queuePtr) || a_queuePtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        queueNode* ptrNode = a_queuePtr->front;     
        *a_dataPtr = a_queuePtr->front->entry;
        a_queuePtr->front = ptrNode->next;
        free(ptrNode);
        if(a_queuePtr->front == NULL)
        {   /* condition for empty queue */
            a_queuePtr->rear = NULL;
        }
        a_queuePtr->size--;
    }
    return 1;
}

/**
 * @brief used to get the element that is ready to be served.
 * 
 * @param a_queuePtr 
 * @param a_dataPtr 
 * @return  1 if the function executed successful and 0 otherwise
 */
unsigned char queueFront (queue_t* a_queuePtr, queue_elem_t* a_dataPtr)
{
    if (queueIsEmpty(a_queuePtr) || a_queuePtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        *a_dataPtr = a_queuePtr->front->entry;
    }
    return 1;
}

/**
 * @brief check if the queue is empty or not
 * 
 * @param a_queuePtr 
 * @return 1 if queue is empty and 0 otherwise 
 */
int queueIsEmpty (queue_t* a_queuePtr)
{
    return a_queuePtr->size == 0;
}

/**
 * @brief used to get the queue size
 * 
 * @param a_queuePtr 
 * @return size of the queue 
 */
int queueSize (queue_t* a_queuePtr)
{
    return a_queuePtr->size;
}

/**
 * @brief this interface used to print the entire queue with user defined display function
 * 
 * @param a_queuePtr 
 * @param fptr 
 */
void queuePrint (queue_t* a_queuePtr, void(*fptr)(queue_elem_t))
{
    if(queueIsEmpty(a_queuePtr) || fptr == NULL)
    {
        /* Do nothing */
    }
    else{
        queueNode* ptrNode = a_queuePtr->front;
        while(ptrNode != NULL)
        {
            fptr(ptrNode->entry);
            ptrNode = ptrNode->next;
        }
    }
}

/**
 * @brief this interface used to delete the given queue
 * 
 * @param a_queuePtr 
 */
void clearQueue (queue_t* a_queuePtr)
{
    queueNode* ptrNode = a_queuePtr->front;
    queueNode* temp = NULL;
    while(ptrNode != NULL)
    {
        temp = ptrNode;
        ptrNode = ptrNode->next;
        free(temp);
    }
    a_queuePtr->front = NULL;
    a_queuePtr->rear = NULL;
    a_queuePtr->size = 0;
}