/**
 * @file D_Linked_list.c
 * @author Ahmed Metwally (ahmedmetwally577@gmail.com)
 * @brief In this file, the static impelementaion of List data structure is introduced.
 * @version 1.0
 * @date 2023-05-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#include "D_Linked_list.h"

/**
 * @brief Create a List object
 * 
 * @param a_listPtr 
 */
void createList(list_t* a_listPtr)
{   // initialize list with size = 0
    a_listPtr->head = NULL;
    a_listPtr->tail = NULL;
    a_listPtr->size = 0;
}

/**
 * @brief        get the list size 
 * 
 * @param a_plist pointer to the created list by the user
 * @return       the size of the given lisr
 */
int listSize(list_t* a_plist)
{
    return a_plist->size;
}

/**
 * @brief        Check if list is empty or not
 * 
 * @param a_plist pointer to the created list by the user
 * @return       1-> if list is empty and 0 otherwise 
 */
unsigned char listIsEmpty(list_t* a_plist)
{
    return (a_plist->size == 0);
}

/**
 * @brief        this fuction is used to insert a given element in a given location
 * @param a_plist pointer to the created list by the user
 * @param a_list_entry element to be inserted in the list
 * @param pos    The location where the element is going to be inserted. 
 * @return       1 if the function executed successful and 0 otherwise
 */
unsigned char listInsertElement (list_t* a_plist, list_elem_t* a_pdata, int pos)
{
    int i = a_plist->size;
    if(pos > a_plist->size || a_plist == NULL || a_pdata == NULL)
    {
        return 0;
    }
    else{
        listNode* ptrNode = (listNode*)malloc(sizeof(list_elem_t));
        ptrNode->entry = *a_pdata;
        if(pos == 0)
        {   /* case 1: insert element at the start of the list */
            ptrNode->next = a_plist->head;
            ptrNode->prev = NULL;
            if(ptrNode->next != NULL)
                a_plist->head->prev = ptrNode;
            a_plist->head = ptrNode;
        }
        else
        {   /* case 2: insert element at any position except first one */
            listNode* pnTemp = a_plist->head;
            int i = 0;
            while(i < pos - 1){
                pnTemp = pnTemp->next;
                i++;
            }
            ptrNode->next = pnTemp->next;
            ptrNode->prev = pnTemp;
            pnTemp->next = ptrNode;
            if(ptrNode->next != NULL)
                ptrNode->next->prev = ptrNode;
        }
        if(ptrNode->next == NULL)
        {
            a_plist->tail = ptrNode;
        }
    }
    (a_plist->size)++;
    return 1;
}

/**
 * @brief this interface used to insert new element to the list at the end.
 * 
 * @param a_plist 
 * @param a_pdata 
 * @return 1 if the function executed successful and 0 otherwise 
 */
unsigned char list_push_back (list_t* a_plist, list_elem_t* a_pdata)
{
    listNode* ptrNode = (listNode*)malloc(sizeof(list_elem_t));
    if(a_plist == NULL || a_pdata == NULL || ptrNode == NULL)
    {
        return 0;
    }
    else
    {
        ptrNode->entry = *a_pdata;
        ptrNode->next = NULL;
        ptrNode->prev = NULL;
        if(a_plist->tail == NULL)
        {
            a_plist->head = ptrNode;
            a_plist->tail = ptrNode;
        }
        else{
            a_plist->tail->next = ptrNode;
            ptrNode->prev = a_plist->tail;
            a_plist->tail = ptrNode;
        }
        a_plist->size++;
    }
    return 1;
}

/**
 * @brief this interface used to insert new element to the list at the front.
 * 
 * @param a_plist 
 * @param a_pdata 
 * @return 1 if the function executed successful and 0 otherwise  
 */
unsigned char list_push_front   (list_t* a_plist, list_elem_t* a_pdata)
{
    listNode* ptrNode = (listNode*)malloc(sizeof(list_elem_t));
    if(a_plist == NULL || a_pdata == NULL || ptrNode == NULL)
    {
        return 0;
    }
    else
    {
        ptrNode->entry = *a_pdata;
        ptrNode->next = NULL;
        ptrNode->prev = NULL;
        if(a_plist->head == NULL)
        {
            a_plist->head = ptrNode;
            a_plist->tail = ptrNode;
        }
        else{
            ptrNode->next = a_plist->head;
            a_plist->head->prev = ptrNode;
            a_plist->head = ptrNode;
        }
        a_plist->size++;
    }
    return 1;
}

/**
 * @brief  this funtion is used to retrive the value of element located in the list, then delete it.     
 * 
 * @param a_plist pointer to the created list by the user
 * @param elem element to hold the deleted element value
 * @param pos  The location of the deleted element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listDeleteElement(list_t* a_listPtr, int pos)
{
    int i = 0;
    if(pos >= a_listPtr->size || a_listPtr == NULL)
    {
        return 0;
    }
    else{
        listNode* ptrNode = a_listPtr->head;
        int i = 0;
        while(i < pos)
        {
            ptrNode = ptrNode->next;
            i++;
        }
        if(ptrNode->prev != NULL)
        {   /* case 1: delete node no the first */ 
            ptrNode->prev->next = ptrNode->next;
            if(ptrNode->next != NULL)
            {   // deleting node between first and last node.
                ptrNode->next->prev = ptrNode->prev;
            }
            else{   // deleting the last node
                a_listPtr->tail = ptrNode->prev;
            }
        }
        else if(ptrNode->prev == NULL)
        {   /* case 2: delete first node */
            a_listPtr->head = ptrNode->next;
            if(ptrNode->next != NULL)
            {
                ptrNode->next->prev = NULL;
            }
            else{
                a_listPtr->tail = NULL;
            }
        }
        free(ptrNode);
    }
    (a_listPtr->size)--;
    return 1;
}

/**
 * @brief this funtion is used to retrive the value of element located in the list, 
 * 
 * @param a_plist pointer to the created list by the user
 * @param elem element to hold the value of required element.
 * @param pos The location of the retrived element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listRetriveElement(list_t* a_listPtr, list_elem_t* a_pdata, int pos)
{
    if(pos >= a_listPtr->size || listIsEmpty(a_listPtr))
    {
        return 0;
    }
    else{
        listNode* ptrNode = a_listPtr->head;
        int i = 0;
        while(i < pos)
        {
            ptrNode = ptrNode->next;
            i++;
        }
        *a_pdata = ptrNode->entry;
    }
    return 1;
}

/**
 * @brief this funtion is used to replace the value of element located in the list with a given value.
 * 
 * @param a_plist pointer to the created list by the user
 * @param a_pdata poitner to element used for replacing the value of another located element.
 * @param pos The location of the replaced element
 * @return 1 if the function executed successful and 0 otherwise
 */
unsigned char listReplaceElement(list_t* a_plist, list_elem_t* a_pdata, int pos)
{
    if(pos > a_plist->size || listIsEmpty(a_plist))
    {
        return 0;
    }
    else{
        listNode* ptrNode = a_plist->head;
        int i = 0;
        while(i < pos && ptrNode != NULL)
        {
            ptrNode = ptrNode->next;
            i++;
        }
        ptrNode->entry = *a_pdata;
    }
    return 1;
}

/**
 * @brief  this function is used to traverse all the list from index 0 to the size of the list
 * 
 * @param a_plist pointer to the created list by the user
 * @param fPtr   pointer to a function that take the element from the list
 *               and print it using the desired specifier.
 * @param order  this parameter determine whether printing from front or end
 *               1 -> means printing from front to end. -1 means printing from end to front.
 */
void listPrint(list_t* a_listPtr, void (*fptr)(list_elem_t), char order)
{
    if(listIsEmpty(a_listPtr) || fptr == NULL)
    {
        /* Do nothing */
    }
    else{
        if(order == 1)
        {
            listNode* ptrNode = a_listPtr->head;
            while(ptrNode != NULL)
            {
                fptr(ptrNode->entry);
                ptrNode = ptrNode->next;
            }
        }
        else if(order == -1)
        {
            listNode* ptrNode = a_listPtr->tail;
            while(ptrNode != NULL)
            {
                fptr(ptrNode->entry);
                ptrNode = ptrNode->prev;
            }
        }
    } 
}

/**
 * @brief this interface used to delete all elements inside the given list
 * 
 * @param a_plist 
 */
void listDestroy (list_t* a_plist)
{
    if(listIsEmpty(a_plist))
    {
        listNode* ptrNode = a_plist->head;
        listNode* ptrNodeNext;
        while(ptrNode != NULL)
        {
            ptrNodeNext = ptrNode->next;
            free(ptrNode);
            ptrNode = ptrNodeNext;
        }
    }
    else{
        /* Do nothing */
    }
    /* Initial Conditions */
    a_plist->size = 0;
    a_plist->head = NULL;
    a_plist->tail = NULL;
}
