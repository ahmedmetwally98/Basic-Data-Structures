/**
 * @file D_Stack.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of stack data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 */

#include "D_Stack.h"

/**
 * @brief Create a Stack object
 * 
 * @param a_stackPtr 
 */
void createStack(stack_t* a_stackPtr)
{
    a_stackPtr->top = NULL;
    a_stackPtr->size = 0;
}

/**
 * @brief insert element to the top of the stack
 * 
 * @param a_stackPtr 
 * @param a_dataPtr 
 * @return 1 if the function is executed successful and 0 otherwise
 */
unsigned char stackPush(stack_t* a_stackPtr, stack_elem_t* a_dataPtr)
{
    stackNode* ptrNode = (stackNode*)malloc(1 * sizeof(stackNode));
    if(NULL == ptrNode || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        ptrNode->entry = *a_dataPtr;
        if(a_stackPtr->top == NULL){
            ptrNode->next = NULL;
        }
        else{
            ptrNode->next = a_stackPtr->top;
        }
        a_stackPtr->top = ptrNode;
        a_stackPtr->size++;
    }
    return 1;
}

/**
 * @brief retrive the top element from the stack and deleting it.
 * 
 * @param a_stackPtr 
 * @param a_elem_ptr 
 * @return 1 if the function is executed successful and 0 otherwise 
 */
unsigned char stackPop(stack_t* a_stackPtr, stack_elem_t* a_elem_ptr)
{
    if(a_stackPtr == NULL || a_elem_ptr == NULL || stackIsEmpty(a_stackPtr)){
        return 0;
    }
    else{
        stackNode* ptrNode = a_stackPtr->top;
        *a_elem_ptr = ptrNode->entry;
        a_stackPtr->top = ptrNode->next;
        a_stackPtr->size--;
    }
    return 1;
}

/**
 * @brief retrive the top element from the stack without deleting it.
 * 
 * @param a_stackPtr 
 * @param a_elem_ptr 
 * @return 1 if the function is executed successful and 0 otherwise
 */
unsigned char stackTop(stack_t* a_stackPtr, stack_elem_t* a_elem_ptr)
{
    if (a_stackPtr == NULL || a_elem_ptr == NULL || stackIsEmpty(a_stackPtr))
    {
        return 0;
    }
    else{
        *a_elem_ptr = a_stackPtr->top->entry;
    }
    return 1;
}

/**
 * @brief check if the stack is empty or not
 * 
 * @param a_stackPtr 
 * @return 1 if the stack is empty and 0 otherwise
 */
int stackIsEmpty(stack_t* a_stackPtr)
{
    return (a_stackPtr->size == 0);
}

/**
 * @brief return the stack size of the given stack
 * 
 * @param a_stackPtr 
 * @return stack size
 */
int stackSize(stack_t* a_stackPtr)
{
    return a_stackPtr->size;
}

/**
 * @brief this interface used to print all stack elements
 * 
 * @param a_stackPtr 
 * @param fptr 
 */
void stackPrint (stack_t* a_stackPtr, void(*fptr)(stack_elem_t))
{
    stackNode* ptrNode = a_stackPtr->top;
    while(ptrNode != NULL)
    {
        fptr(ptrNode->entry);
        ptrNode = ptrNode->next;
    }
}

/**
 * @brief this interface used to delete all stack elements
 * 
 * @param a_stackPtr 
 */
void clearStack (stack_t* a_stackPtr)
{   
    stackNode* ptrNode = a_stackPtr->top;
    while(ptrNode != NULL)
    {
        a_stackPtr->top = ptrNode->next;
        free(ptrNode);
        ptrNode = a_stackPtr->top;
    }
    a_stackPtr->size = 0;
}