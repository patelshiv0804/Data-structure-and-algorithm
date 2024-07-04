// ------------------------------------->linear queue<-------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// struct queue
// {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// void enqueue(struct queue *ptr, int value)
// {
//     if (isFull(ptr))
//     {
//         printf("the queue is full");
//     }
//     else
//     {
//         ptr->r = ptr->r + 1;
//         ptr->arr[ptr->r] = value;
//     }
// }

// int dequeue(struct queue *ptr)
// {
//     int a = -1;
//     if (isEmpty(ptr))
//     {
//         printf("your queue is empty");
//     }
//     else
//     {
//      ptr->f = ptr->f + 1;
//         a = ptr->arr[ptr->f];
//     }
//     return a;
// }

// int isFull(struct queue *ptr)
// {
//     if (ptr->r == ptr->size - 1)
//     {
//         printf("the queue is full");
//         return 1;
//     }
//     return 0;
// }

// int isEmpty(struct queue *ptr)
// {
//     if (ptr->r == ptr->f)
//     {
//         printf("the queue is empty");
//         return 1;
//     }
//     return 0;
// }


// int main()
// {
//     struct queue *ptr;
//     ptr->size = 10;
//     ptr->f = ptr->r = -1;
//     ptr->arr = (int *)malloc(ptr->size * sizeof(int));

//     enqueue(ptr, 2); // we write &q because it takes pointer
//     enqueue(ptr, 4);
//     printf("dequeue element is:%d \n", dequeue(ptr));
// // printf("dequeue element is:%d \n", dequeue(q));

//     enqueue(ptr, 56);

//     if (isEmpty(ptr))
//     {
//         printf("Queue is empty \n");
//     }
//     if (isFull(ptr))
//     {
//         printf("Queue is full \n");
//     }
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// void enqueue(struct node* ptr, int data){
//     if(isfull(ptr)){
//         printf("queue is full");
//     }
//     else{
//       ptr->r = ptr->r+ 1 ;
//       ptr->arr[ptr->r]= data ;
//     }
// }

// int dequeue (struct node* ptr){
//     int a = -1 ;
//     if(isempty(ptr)){
//         // printf("queue is dequeue");
//     }
//     else {
//         ptr->f = ptr->f + 1;
//         a = ptr->arr[ptr->f]; 
//     }
//     return a;
// }

// int isfull(struct node* ptr){
//     if(ptr->r == ptr->size-1){
//         printf("queue is full");
//         return 1;
//     }
//     return 0;
// }

// int isempty(struct node* ptr){
//     if(ptr->r == ptr->f ){
//         printf("queue is empty");
//         return 1;
//     }
//     return 0;
// }

// int main(){
//     struct node* ptr;
//     ptr->size=10;
//     ptr->r=ptr->f=-1;
//     ptr->arr=(int *)malloc(ptr->size * (sizeof(int)));
    
//     enqueue(ptr,2);
//     enqueue(ptr,4);
//     enqueue(ptr,6);
    
//     printf("dequeue element is: %d\n",dequeue(ptr));
//     printf("dequeue element is: %d\n",dequeue(ptr));
//     printf("dequeue element is: %d\n",dequeue(ptr));
//      printf("\ndequeue element is: %d\n",dequeue(ptr));
// }


// ------------------------------------------>circular queue by harry<-------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
 
 
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    enqueue(&q, 4); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
  printf("Dequeuing element %d\n", dequeue(&q)); 
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;
}






//               <------------------------>circular queue by dev patel<------------------------------->
// #include<stdio.h>
// #include<stdlib.h>

// struct queue{
//     int size;
//     int front;
//     int rear;
//     int *arr;
// };

// int display(struct queue *q){
//     for(int i=0;i<=q->rear;i++){
//         printf("%d\t",q->arr[i]);
//     }printf("\n");
// }

// int isfull(struct queue *q){
//     return q->rear==q->size-1;
// }
// int isempty(struct queue *q){
//     return q->rear==q->front;
// }
// int enqueue(struct queue *q,int x){
//     if(isfull(q)){
//         printf("Queue is full\n");
//         return -1;
//     }
//     q->rear=q->rear+1;
//     q->arr[q->rear]=x;
//     display(q);
// }
// int dequeue(struct queue *q){
//     if (isempty(q)){
//         printf("Queue is empty\n");
//         return -1;
//     }
// else{
//     q->front=q->front-1;
//     int value=q->arr[q->front];

//     // q->rear=q->rear-1;
//     // printf("The removed value is %d\n",value);
//     // for(int i=0;i<=q->rear;i++){
//     //     q->arr[i]=q->arr[i+1];
//     // }
//     // q->front=q->front+1;
//     display(q);
// }

// int main(){
//     struct queue *q;
//     q->size=5;
//     q->front=q->size;
//     q->rear=-1;
//     q->arr=(int*) malloc(q->size*sizeof(int));

//     enqueue(q,1);
//     enqueue(q,2);
//     enqueue(q,3);
//     enqueue(q,4);
//     enqueue(q,5);
//     dequeue(q);
//     // enqueue(q,1);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // enqueue(q,2);
    
//    return 0;
// }