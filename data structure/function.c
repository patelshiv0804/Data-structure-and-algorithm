


#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

void display(struct queue *q){
    for(int i=0;i<=q->r;i++){
        printf("%d\t",q->arr[i]);
    }printf("\n");
}
int isFull(struct queue *q){
    if(q->r == q->size-1){
        printf("the queue is full");
        return 1;
    }
    
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r < q->f){
        printf("the queue is empty");
        return 1;
    }
    return 0;
}

void function(struct queue *q){
  
    int val;
if(!isEmpty(q)){
     val=dequeue(q);
     function(q);
     enqueue(q,val);
    //  display(q);
}
}  


void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("the queue is full\n");
    }
    else{
        q->r = q->r+1;
        q->arr[q->r]=val;
         
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("your queue is empty\n");
    }
    else {
        q->f=q->f+1;
        a= q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=3;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size *sizeof(int));

    enqueue(&q, 2);  //we write &q because it takes pointer 
    enqueue(&q, 44);
    enqueue(&q,56);
    function(&q);
    display(&q);

    // if(isEmpty(&q)){
    //     // printf("Queue is empty\n");
    // }
    // if(isFull(&q)){
    //     // printf("Queue is full\n");
    // }
    return 0;
}

