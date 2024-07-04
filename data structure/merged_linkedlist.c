#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* MergeLists(struct Node* listA, struct Node* listB) {
    struct Node* mergedList = NULL;  
    struct Node* tail = NULL;        

    while (listA != NULL && listB != NULL) {
    
        if(listA->data < listB->data) {
          
            if (mergedList == NULL) {
                mergedList = tail = listA;
            } else {
                tail->next = listA;
                tail = listA;
            }
            listA = listA->next;  
        } 
        else {
            if (mergedList == NULL) {
                mergedList = tail = listB;
            } else {
                tail->next = listB;
                tail = listB;
            }
            listB = listB->next;  
        }
    }

    if (listA != NULL) {
        tail->next = listA;
    } else {
        tail->next = listB;
    }

    return mergedList;
}


void printList(struct Node* list) {
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
   
    struct Node* list1 = newNode(15);
    list1->next = newNode(20);
    list1->next->next = newNode(24);

    struct Node* list2 = newNode(4);
    list2->next = newNode(10);
    list2->next->next = newNode(26);

 
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);


    struct Node* mergedList = MergeLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
