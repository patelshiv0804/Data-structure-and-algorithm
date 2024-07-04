#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int display(struct queue *q){
    for(int i=0;i<=q->rear;i++){
        printf("%d\t",q->arr[i]);
    }printf("\n");
}


int isfull(struct queue *q){
    return q->rear==q->size-1;
}
int isempty(struct queue *q){
    return q->rear < q->front;
}
int enqueue(struct queue *q,int x){
    if(isfull(q)){
        printf("Queue is full\n");
        return -1;
    }
    q->rear=q->rear+1;
    q->arr[q->rear]=x;
    display(q);
}
int dequeue(struct queue *q){
    if (isempty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int value=q->arr[q->front];
    q->front=q->front+1;
    q->rear=q->rear-1;
    printf("The removed value is %d\n",value);
    for(int i=0;i<=q->rear;i++){
        q->arr[i]=q->arr[i+1];
    }
    q->front=q->front-1;
    return value;
    display(q); 
}
void function(struct queue *q){
  
    int val;
    if(!isempty(q)){
     val=dequeue(q);
     function(q);
     enqueue(q,val);
    //  display(q);
}
}  
int main(){
    struct queue *q;
    q->size=5;
    q->front=0;
    q->rear=-1;
    q->arr=(int*) malloc(q->size*sizeof(int));

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    function(q);
   
 return 0;
}
