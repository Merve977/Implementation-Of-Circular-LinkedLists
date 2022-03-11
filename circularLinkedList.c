#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList{
    int data;
    struct SinglyLinkedList* next;
}SLLI;

SLLI* AddItemToEnd(SLLI* headOfTheList, int adding);
SLLI* AddItemInOrder(SLLI* headOfTheList, int adding);
SLLI* DeleteAnItem(SLLI* headOfTheList, int deletingItem);
void PrintList(SLLI* headOfTheList);


//Function that add items at the end of the circular linkedlist
SLLI* AddItemToEnd(SLLI* headOfTheList, int adding)
{
    SLLI* iter = headOfTheList;
    while(iter->next != headOfTheList){
        iter = iter->next;
    }
    iter->next = (SLLI*)malloc(sizeof(SLLI));
    iter->next->data = adding;
    iter->next->next = headOfTheList;
    
    return headOfTheList;
}


//A function that adds elements from small to large to the list 
SLLI* AddItemInOrder(SLLI* headOfTheList, int adding)
{
    //The linkedlist has no element but is circular
    if(headOfTheList == NULL){
        headOfTheList = (SLLI*)malloc(sizeof(SLLI));
        headOfTheList->data = adding;
        headOfTheList->next = headOfTheList;
        
        return headOfTheList;
    }
    
    //if member to be added is smaller than the root element
    if(headOfTheList->data > adding){
        SLLI* temp = (SLLI*)malloc(sizeof(SLLI));
        temp->data = adding;
        temp->next = headOfTheList;
        
        //process to make the list still circular
        SLLI* iter = headOfTheList;
        while(iter->next != headOfTheList){
            iter = iter->next;
        }
        iter->next = temp;
        return temp;
    }
    
    SLLI* iter = headOfTheList;
    while(iter->next != headOfTheList && iter->next->data < adding){
        iter = iter->next;
    }
    SLLI* temp = (SLLI*)malloc(sizeof(SLLI));
    temp->data = adding;
    temp->next = iter->next;
    iter->next = temp;
    return headOfTheList;
}


//Function that remove item
SLLI* DeleteAnItem(SLLI* headOfTheList, int deletingItem){
    SLLI* iter = headOfTheList;
    SLLI* temp;
    //Deleting the first item
    if(headOfTheList->data == deletingItem){
        while(iter->next != headOfTheList){
            iter = iter->next;
        }
        //changing the root element of the list
        iter->next = headOfTheList->next;
        
        //deleting the root element
        free(headOfTheList);
        
        return iter->next;
    }
    
    while(iter->next != headOfTheList && iter->next->data != deletingItem){
        iter = iter->next;
    }
    //if deletingItem is NOT found in the linkedList
    if(iter->next == headOfTheList){
        printf("There is no such %d in linked list!\n", deletingItem);
        return headOfTheList;
    }
    
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return headOfTheList;
}

//Printing the list
void PrintList(SLLI* headOfTheList){
    SLLI* iter = headOfTheList;
    //do-while can be used
    printf("%d ", iter->data);
    iter = iter->next;
    while(iter != headOfTheList){
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}


int main(){
    
    SLLI* headOfTheList;
    headOfTheList = NULL;
    
    headOfTheList = AddItemInOrder(headOfTheList, 88);
    headOfTheList = AddItemInOrder(headOfTheList, 30);
    headOfTheList = AddItemInOrder(headOfTheList, 20);
    headOfTheList = AddItemInOrder(headOfTheList, 12);
    headOfTheList = AddItemInOrder(headOfTheList, 2);
    headOfTheList = AddItemInOrder(headOfTheList, 67);
    headOfTheList = AddItemInOrder(headOfTheList, 400);
    headOfTheList = AddItemInOrder(headOfTheList, 98);
    headOfTheList = AddItemInOrder(headOfTheList, 3);
    
    PrintList(headOfTheList);
    
    
    headOfTheList = DeleteAnItem(headOfTheList, 67);
    PrintList(headOfTheList);
    
    headOfTheList = DeleteAnItem(headOfTheList, 250);
    PrintList(headOfTheList);
    
    headOfTheList = DeleteAnItem(headOfTheList, 900);
    PrintList(headOfTheList);
    
    
    
    return 0;
}