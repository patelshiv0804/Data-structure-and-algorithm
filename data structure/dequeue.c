// #include <stdio.h>
// #include <stdlib.h>


// struct Deque {
//     int *arr;
//     int front,rear;
//     int size;
// };

// struct Deque* createDeque() {
//     struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
//     deque->front = -1;
//     deque->rear = -1;
//     return deque;
// }

// int isEmpty(struct Deque* deque) {
//     return (deque->front == -1);
// }

// int isFull(struct Deque* deque) {
//     return ((deque->front == 0 && deque->rear == deque-> size - 1) || deque->front == deque->rear + 1);
// }

// void insertFront(struct Deque* deque, int item) {
//     if (isFull(deque)) {
//         printf("Deque is full. Cannot insert at the front.\n");
//         return;
//     }

//     if (deque->front == -1) {
//         deque->front = 0;
//         deque->rear = 0;
//     } else if (deque->front == 0) {
//         deque->front = deque-> size - 1;
//     } else {
//         deque->front--;
//     }

//     deque->arr[deque->front] = item;
// }

// void insertLast(struct Deque* deque, int item) {
//     if (isFull(deque)) {
//         printf("Deque is full. Cannot insert at the rear.\n");
//         return;
//     }

//     if (deque->front == -1) {
//         deque->front = 0;
//         deque->rear = 0;
//     } else if (deque->rear == deque-> size - 1) {
//         deque->rear = 0;
//     } else {
//         deque->rear++;
//     }

//     deque->arr[deque->rear] = item;
// }

// void deleteFront(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty. Cannot delete from the front.\n");
//         return;
//     }

//     if (deque->front == deque->rear) {
//         deque->front = -1;
//         deque->rear = -1;
//     } else if (deque->front == deque-> size - 1) {
//         deque->front = 0;
//     } else {
//         deque->front++;
//     }
// }

// void deleteLast(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty. Cannot delete from the rear.\n");
//         return;
//     }

//     if (deque->front == deque->rear) {
//         deque->front = -1;
//         deque->rear = -1;
//     } else if (deque->rear == 0) {
//         deque->rear = deque-> size - 1;
//     } else {
//         deque->rear--;
//     }
// }

// void display(struct Deque* deque) {
//     if (isEmpty(deque)) {
//         printf("Deque is empty.\n");
//         return;
//     }

//     int i;
//     if (deque->front <= deque->rear) {
//         for (i = deque->front; i <= deque->rear; i++) {
//             printf("%d ", deque->arr[i]);
//         }
//     } else {
//         for (i = deque->front; i < deque->size; i++) {
//             printf("%d ", deque->arr[i]);
//         }
//         for (i = 0; i <= deque->rear; i++) {
//             printf("%d ", deque->arr[i]);
//         }
//     }
//     printf("\n");
// }

// int main() {
//     struct Deque* deque = createDeque();
//     deque->size=10;

//     insertFront(deque, 1);
//     insertFront(deque, 2);
//     insertLast(deque, 3);
//     insertLast(deque, 4);

//     printf("Deque: ");
//     display(deque);

//     deleteFront(deque);
//     deleteLast(deque);

//     printf("Deque after deleting front and rear elements: ");
//     display(deque);

//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front, rear, size;
};

void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
}

bool isFull(struct Deque *deque) {
    return (deque->size == MAX_SIZE);
}

bool isEmpty(struct Deque *deque) {
    return (deque->size == 0);
}

void insertFront(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    
    if (deque->front == -1){
        deque->front = 0;}
    
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    deque->arr[deque->front] = data;
    deque->size++;
}

void insertRear(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    
    deque->rear = (deque->rear + 1) % MAX_SIZE;
    deque->arr[deque->rear] = data;
    if (deque->front == -1)
        deque->front = 0;
    deque->size++;
}

int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->arr[deque->front];
}

int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->arr[deque->rear];
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);
    
    insertRear(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 0);
    
    printf("Front: %d\n", getFront(&deque));
    printf("Rear: %d\n", getRear(&deque));
    
    return 0;
}