#include <stdio.h>
#include <stdlib.h>

struct PriorityQueueNode {
    int data;
    int priority;
};

struct PriorityQueue {
    struct PriorityQueueNode* queue;
    int capacity;
    int size;
};

struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->queue = (struct PriorityQueueNode*)malloc(sizeof(struct PriorityQueueNode) * capacity);
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

void swap(struct PriorityQueueNode* a, struct PriorityQueueNode* b) {
    struct PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct PriorityQueue* pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->queue[left].priority > pq->queue[largest].priority)
        largest = left;

    if (right < pq->size && pq->queue[right].priority > pq->queue[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&pq->queue[i], &pq->queue[largest]);
        heapify(pq, largest);
    }
}

void insert(struct PriorityQueue* pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full. Cannot insert.\n");
        return;
    }

    struct PriorityQueueNode newNode;
    newNode.data = data;
    newNode.priority = priority;

    int i = pq->size;
    pq->queue[i] = newNode;
    pq->size++;

    while (i > 0 && pq->queue[(i - 1) / 2].priority < pq->queue[i].priority) {
        swap(&pq->queue[i], &pq->queue[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty. Cannot extract.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->queue[0].data;
    }

    int root = pq->queue[0].data;
    pq->queue[0] = pq->queue[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue(10);

    insert(pq, 10, 3);
    insert(pq, 20, 2);
    insert(pq, 30, 4);
    insert(pq, 40, 1);

    printf("Highest priority element: %d\n", extractMax(pq));
    printf("Highest priority element: %d\n", extractMax(pq));

    free(pq->queue);
    free(pq);

    return 0;
}
