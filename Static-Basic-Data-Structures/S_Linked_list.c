/**
 * @file S_Linked_list.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of List data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#include "S_Linked_list.h"

/**
 * @brief Create a List object
 * 
 * @param a_listPtr 
 */
void createList(list_t* a_listPtr)
{   // initialize list with size = 0
    if(a_listPtr != NULL)
    {
        a_listPtr->size = 0;
        for (int i = 0; i < LIST_MAX_SIZE; i++)
        {
            a_listPtr->ptr_node[i] = NULL;
        }
    }
    else{
        /* Do nothing */
    }
}

/**
 * @brief        get the list size 
 * 
 * @param a_listPtr pointer to the created list by the user
 * @return       the size of the given lisr
 */
int listSize(list_t* a_listPtr)
{
    return a_listPtr->size;
}

/**
 * @brief        Check if list is empty or not
 * 
 * @param a_listPtr pointer to the created list by the user
 * @return       1-> if list is empty and 0 otherwise 
 */
unsigned char listIsEmpty(list_t* a_listPtr)
{
    return (a_listPtr->size == 0);
}

/**
 * @brief        check if the list is full or not
 *  
 * @param a_listPtr pointer to the created list by the user
 * @return       1-> if list is full and 0 otherwise
 */
unsigned char listIsFull(list_t* a_listPtr)
{
    return (a_listPtr->size == LIST_MAX_SIZE);
}

/**
 * @brief        this fuction is used to insert a given element in a given location
 * @param a_listPtr pointer to the created list by the user
 * @param a_dataPtr element to be inserted in the list
 * @param pos    The location where the element is going to be inserted. 
 * @return       1 if the function executed successful and 0 otherwise
 */
unsigned char listInsertElement(list_t* a_listPtr, list_elem_t* a_dataPtr, int pos)
{
    int i = a_listPtr->size;
    if(pos > a_listPtr->size || pos < 0 || listIsFull(a_listPtr) || a_listPtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        while(i != pos)
        {
            i--;
            *(list_elem_t*)a_listPtr->ptr_node[i+1] =  *(list_elem_t*)a_listPtr->ptr_node[i];
        }
        void* node = (void*)malloc(sizeof(list_elem_t));    /* create new node */
        if(node == NULL)
        {
            return 0;
        }
        *((list_elem_t*)node) = *a_dataPtr;                 /* store the data inside the created node*/
        a_listPtr->ptr_node[i] = node;                      /* linking the node with the list */
    }
    (a_listPtr->size)++;
    return 1;
}

/**
 * @brief this interface used to insert new element to the list fro the end.
 * 
 * @param a_listPtr 
 * @param a_dataPtr 
 * @return 1 if the function executed successful and 0 otherwise 
 */
unsigned char list_push_back(list_t* a_listPtr, list_elem_t* a_dataPtr)
{
    if(listIsFull(a_listPtr) || a_listPtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        // insert the new element
        void* node = (void*)malloc(sizeof(list_elem_t));        /* create new node */
        if(node == NULL)
        {
            return 0;
        }
        *((list_elem_t*)node) = *a_dataPtr;                     /* store the data inside the created node*/
        a_listPtr->ptr_node[a_listPtr->size] = node;            /* linking the node with the list */
        (a_listPtr->size)++;
    }
    return 1;
}

/**
 * @brief this interface used to insert new element to the list from front.
 * 
 * @param a_listPtr 
 * @param a_dataPtr 
 * @return 1 if the function executed successful and 0 otherwise  
 */
unsigned char list_push_front(list_t* a_listPtr, list_elem_t* a_dataPtr)
{
    if(listIsFull(a_listPtr) || a_listPtr == NULL || a_dataPtr == NULL)
    {
        return 0;
    }
    else{
        // shift all elements by 1
        int i;
        for(i = (a_listPtr->size); i > 0; i--)
        {
            a_listPtr->ptr_node[i] = a_listPtr->ptr_node[i-1];
        }
        // insert the new element
        void* node = (void*)malloc(sizeof(list_elem_t));            /* create new node */
        if(node == NULL)
        {
            return 0;
        }
        *((list_elem_t*)node) = *a_dataPtr;                         /* store the data inside the created node*/
        a_listPtr->ptr_node[0] = node;                              /* linking the node with the list */
        (a_listPtr->size)++;
    }
    return 1;
}

/**
 * @brief  this funtion is used to retrive the value of element located in the list, then delete it.     
 * 
 * @param a_listPtr pointer to the created list by the user
 * @param a_dataPtr element to hold the deleted element value
 * @param pos  The location of the deleted element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listDeleteElement(list_t* a_listPtr, int pos)
{
    int i = 0;
    if(pos >= a_listPtr->size || pos < 0 || listIsEmpty(a_listPtr) || a_listPtr == NULL)
    {
        return 0;
    }
    else{
        i = pos;
        while (i < (a_listPtr->size - 1))
        {
            *((list_elem_t*)a_listPtr->ptr_node[i]) = *((list_elem_t*)a_listPtr->ptr_node[i+1]);
            i++;
        }
        free(a_listPtr->ptr_node[a_listPtr->size - 1]);   // free the last location in the list as all elements are shifted.
        a_listPtr->ptr_node[a_listPtr->size - 1] = NULL;
    }
    a_listPtr->size--;
    return 1;
}

/**
 * @brief this funtion is used to retrive the value of element located in the list, 
 * 
 * @param a_listPtr pointer to the created list by the user
 * @param a_dataPtr element to hold the value of required element.
 * @param pos The location of the retrived element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listRetriveElement(list_t* a_listPtr, list_elem_t* a_dataPtr, int pos)
{
    if(pos >= a_listPtr->size ||  pos < 0 || listIsEmpty(a_listPtr) || a_listPtr==NULL || a_dataPtr==NULL)
    {
        return 0;
    }
    else{
        *a_dataPtr = *(list_elem_t*)a_listPtr->ptr_node[pos];
    }
    return 1;
}

/**
 * @brief this funtion is used to replace the value of element located in the list with a given value.
 * 
 * @param a_listPtr pointer to the created list by the user
 * @param a_dataPtr element used for replace the value of another located variable.
 * @param pos The location of the replaced element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listReplaceElement(list_t* a_listPtr, list_elem_t* a_dataPtr, int pos)
{
    if(pos >= a_listPtr->size || pos < 0 || listIsEmpty(a_listPtr) || a_listPtr==NULL || a_dataPtr==NULL)
    {
        return 0;
    }
    else{
        *(list_elem_t*)(a_listPtr->ptr_node[pos]) = *a_dataPtr;
    }
    return 1;
}

/**
 * @brief  this interface used to print the entire list with user defined display function
 * 
 * @param a_listPtr pointer to the created list by the user
 * @param fPtr   pointer to a function that take the element from the list
 *               and print it using the desired specifier.
 */
void listPrint(list_t* a_listPtr, void (*fPtr)(list_elem_t), char order)
{
    if((a_listPtr!=NULL) && (fPtr!=NULL))
    {
        if(order == 1)
        {
            int i = 0;
            while ((a_listPtr->ptr_node[i] != NULL) && (i < a_listPtr->size))
            {
                fPtr(*((list_elem_t*)(a_listPtr->ptr_node[i])));
                i++;
            }
        }
        else if(order == -1)
        {
            int i = a_listPtr->size - 1;
            while(i >= 0)
            {
                fPtr(*((list_elem_t*)(a_listPtr->ptr_node[i])));
                i--;
            }
        }
    }
}

/**
 * @brief this interface used to delete all element inside the given list
 * 
 * @param a_listPtr 
 */
void listDestroy(list_t* a_listPtr)
{
    if(a_listPtr != NULL)
    {
        for (int i=0; i<a_listPtr->size; i++)
        {
            free(a_listPtr->ptr_node[i]);
            a_listPtr->ptr_node[i] = NULL;
        }
        a_listPtr->size = 0;
    }
    else{
        /* Do nothing */
    }
}
