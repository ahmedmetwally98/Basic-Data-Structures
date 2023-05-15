/**
 * @file S_Queue.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of queue data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 */
 
#include "S_Queue.h"

/**
 * @brief Create a Queue object.
 * 
 * @param a_queuePtr 
 */
void createQueue (queue_t* a_queuePtr)
{
    if(a_queuePtr != NULL)
    {
        a_queuePtr->front = 0;
        a_queuePtr->rear  = -1;
        a_queuePtr->size  = 0;
        for (int i = 0; i < QUEUE_MAX_SIZE; i++)
        {
            a_queuePtr->ptr_node[i] = NULL;
        }
    }
    else{
        /* Do nothing */
    }
}

/**
 * @brief used to add new element to the queue 
 * 
 * @param a_queuePtr 
 * @param a_dataPtr 
 * @return unsigned char 
 */
unsigned char queueAppend (queue_t* a_queuePtr, queue_elem_t* a_dataPtr)
{
    if(qeueuIsFull(a_queuePtr) || a_queuePtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        void* node = (void*)malloc(sizeof(queue_elem_t));             /* create new node to hold the new element */
        if(node == NULL)
        {
            return 0;
        }
        *(queue_elem_t*)node = *a_dataPtr;                            /* store the appended element in the location */
        a_queuePtr->rear = (a_queuePtr->rear + 1) % QUEUE_MAX_SIZE;   
        a_queuePtr->ptr_node[a_queuePtr->rear] = node;                /* add location to the queue structure */
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
        *a_dataPtr = *((queue_elem_t*)a_queuePtr->ptr_node[a_queuePtr->front]);
        free(a_queuePtr->ptr_node[a_queuePtr->front]);
        a_queuePtr->ptr_node[a_queuePtr->front] = NULL;           
        a_queuePtr->front = (a_queuePtr->front + 1) % QUEUE_MAX_SIZE;
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
        *a_dataPtr = *(queue_elem_t*)a_queuePtr->ptr_node[a_queuePtr->front];
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
 * @brief check if the queue is full or not
 * 
 * @param a_queuePtr 
 * @return 1 if queue is full and 0 otherwise 
 */
int qeueuIsFull (queue_t* a_queuePtr)
{
    return a_queuePtr->size == QUEUE_MAX_SIZE;
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
    if(a_queuePtr!=NULL && fptr!=NULL)
    {
        int idx = a_queuePtr->front;
        int size = a_queuePtr->size;
        int i;
        for(i = 0; i < size; i++)
        {
            fptr(*((queue_elem_t*)a_queuePtr->ptr_node[idx]));
            idx = (idx + 1) % QUEUE_MAX_SIZE;
        }
    }
}

/**
 * @brief this interface used to delete all element inside the given queue
 * 
 * @param a_queuePtr 
 */
void clearQueue (queue_t* a_queuePtr)
{
    if(a_queuePtr != NULL)
    {
        a_queuePtr->front = 0;
        a_queuePtr->rear  = -1;
        a_queuePtr->size  = 0;
        for (int i = 0; i < a_queuePtr->size; i++)
        {
            free(a_queuePtr->ptr_node[i]);
            a_queuePtr->ptr_node[i] = NULL;
        }
    }
    else{
        /* Do nothing */
    }
}