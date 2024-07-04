#include<stdio.h>
#include<stdlib.h>

struct node {
    int weight;
    int src;
    int des;
};

struct minheap{
    int size;
    int capacity;
    struct node* array;
};

struct node *creatnode(int weight,int src,int des){
  struct node * newnode = (struct node*)malloc(sizeof(struct node));
  newnode->weight = weight;
  newnode->src = src;
  newnode->des = des;
  return newnode;
}

struct minheap *creatheap(int capacity){
    int size = 0 ;
    int capacity = capacity;
    

}