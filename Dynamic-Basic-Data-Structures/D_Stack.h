/**
 * @file D_Stack.h
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, we declare data type of stack data structure and related operations (Interfaces).
 * @version 1.0
 * @date 2023-05-14
 * 
 */

#ifndef _D_Stack_H
#define _D_Stack_H

#include <stdlib.h>

/* user define */
typedef int stack_elem_t;

/********************* Data structure definition *************************/
typedef struct stacknode{
    stack_elem_t entry;
    struct stacknode *next;
}stackNode;

typedef struct {
    int size; 
    struct stacknode* top;
}stack_t;

/******************* Data structure definition end ***********************/

/******************* Function declaration ********************************/
void          createStack     (stack_t* a_stackPtr);
unsigned char stackPush       (stack_t* a_stackPtr, stack_elem_t* a_dataPtr);
unsigned char stackPop        (stack_t* a_stackPtr, stack_elem_t* a_dataPtr);
unsigned char stackTop        (stack_t* a_stackPtr, stack_elem_t* a_dataPtr);
int           stackIsEmpty    (stack_t* a_stackPtr);
int           stackSize       (stack_t* a_stackPtr);
void          stackPrint      (stack_t* a_stackPtr, void(*)(stack_elem_t));
void          clearStack      (stack_t* a_stackPtr);
/******************* Function declaration end ********************************/

#endif          // _D_Stack_H