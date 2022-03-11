# Implementation-Of-Circular-LinkedLists
In this repo, implemantation(adding item, adding item in order, deleting item, printing the list) of circular linked list is coded.

## ATTENTION
* Even though AddItemInOrder function has been created, it has not been called in the main function. 
* In case you want to use it, in the main function instead of using AddItemToEnd function, you may use it.

### AddItemInOrder() function
~~~bash

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

~~~


### In case you want to use this function, use this piece of code 

~~~bash
 headOfTheList = AddItemInOrder(headOfTheList, 88);
    headOfTheList = AddItemInOrder(headOfTheList, 30);
    headOfTheList = AddItemInOrder(headOfTheList, 20);
    headOfTheList = AddItemInOrder(headOfTheList, 12);
    headOfTheList = AddItemInOrder(headOfTheList, 2);
    headOfTheList = AddItemInOrder(headOfTheList, 67);
    headOfTheList = AddItemInOrder(headOfTheList, 400);
    headOfTheList = AddItemInOrder(headOfTheList, 98);
    headOfTheList = AddItemInOrder(headOfTheList, 3);
    
~~~


### How to Run These Code
It does not matter which IDE you use but i personally prefer [DEVC++](https://www.dev-cpp.com/). Installing this IDE, you can run this program quickly!
