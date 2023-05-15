/**
 * @file S_Stack.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of stack data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 */

#include "S_Stack.h"


/**
 * @brief Create a Stack object
 * 
 * @param a_stachPtr 
 */
void createStack(stack_t* a_stachPtr)
{
    if(a_stachPtr != NULL)
    {
        a_stachPtr->top = 0;
        a_stachPtr->size = 0;
        int i = 0;
        for(i = 0; i < STACK_MAX_SIZE; i++)
        {
            a_stachPtr->ptr_node[i] = NULL;
        }
    }
    else{
        /* Do nothing */
    }
}

/**
 * @brief insert element to the top of the stack
 * 
 * @param a_stachPtr 
 * @param a_data 
 * @return 1 if the function is executed successful and 0 otherwise
 */
unsigned char stackPush(stack_t* a_stachPtr, stack_elem_t* a_dataPtr)
{
    if(stackIsFull(a_stachPtr) || a_stachPtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        void* node = (void*)malloc(sizeof(stack_elem_t));       /* create new node to hold the new element */
        if(node == NULL)
        {
            return 0;
        }
        *(stack_elem_t*)node = *a_dataPtr;                      /* store the pushed element in the location */
        a_stachPtr->ptr_node[a_stachPtr->top] = node;           /* add location to the stack structure */
        a_stachPtr->top++;
        a_stachPtr->size++;
    }
    return 1;
}

/**
 * @brief retrive the top element from the stack and deleting it.
 * 
 * @param a_stachPtr 
 * @param a_dataPtr 
 * @return 1 if the function is executed successful and 0 otherwise 
 */
unsigned char stackPop(stack_t* a_stachPtr, stack_elem_t* a_dataPtr)
{
    if(stackIsEmpty(a_stachPtr) || a_stachPtr == NULL || a_dataPtr == NULL){
        return 0;
    }
    else{
        a_stachPtr->top--;
        *a_dataPtr = *(stack_elem_t*)a_stachPtr->ptr_node[a_stachPtr->top];
        free(a_stachPtr->ptr_node[a_stachPtr->top]);
        a_stachPtr->ptr_node[a_stachPtr->top] = NULL;
        a_stachPtr->size--;
    }
    return 1;
}

/**
 * @brief retrive the top element from the stack without deleting it.
 * 
 * @param a_stachPtr 
 * @param a_dataPtr 
 * @return 1 if the function is executed successful and 0 otherwise
 */
unsigned char stackTop(stack_t* a_stachPtr, stack_elem_t* a_dataPtr)
{
    if (stackIsEmpty(a_stachPtr) || a_dataPtr == NULL || a_stachPtr == NULL)
    {
        return 0;
    }
    else{
        *a_dataPtr = *(stack_elem_t*)a_stachPtr->ptr_node[a_stachPtr->top - 1];
    }
    return 1;
}

/**
 * @brief check if the stack is empty or not
 * 
 * @param a_stachPtr 
 * @return 1 if the stack is empty and 0 otherwise
 */
int stackIsEmpty(stack_t* a_stachPtr)
{
    return (a_stachPtr->size == 0);
}

/**
 * @brief check if the stack is full or not
 * 
 * @param a_stachPtr 
 * @return 1 -> if the stack is full and 0 otherwise.
 */
int stackIsFull(stack_t* a_stachPtr)
{
    return (a_stachPtr->size == STACK_MAX_SIZE);
}

/**
 * @brief return the stack size of the given stack
 * 
 * @param a_stachPtr 
 * @return stack size
 */
int stackSize(stack_t* a_stachPtr)
{
    return a_stachPtr->size;
}

/**
 * @brief this interface used to print the entire queue with user defined display function
 * 
 * @param a_stachPtr 
 * @param fptr 
 */
void stackPrint (stack_t* a_stachPtr, void(*fptr)(stack_elem_t))
{
    if(a_stachPtr != NULL && fptr != NULL)
    {
        int i;
        for (i = a_stachPtr->top - 1; i >= 0; i--)
        {
            fptr(*((stack_elem_t*)a_stachPtr->ptr_node[i]));
        }
    }
}

/**
 * @brief this interface used to delete all element inside the given stack
 * 
 * @param a_stachPtr 
 */
void clearStack (stack_t* a_stachPtr)
{   
    if(a_stachPtr != NULL)
    {
        for(int i = 0; i < a_stachPtr->size; i++)
        {
            free(a_stachPtr->ptr_node[i]);
            a_stachPtr->ptr_node[i] = NULL;
        }
        a_stachPtr->size = 0;
        a_stachPtr->top = 0;
    }
    else{
        /* Do nothing */
    }
}