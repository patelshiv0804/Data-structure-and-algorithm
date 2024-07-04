#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

struct Node
{
    int weight;
    int src; // source
    int des; // destination
};

struct MinHeap
{
    int size;
    int capacity;
    struct Node *array;
};

struct Node *createNode(int weight, int src, int des)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->weight = weight;
    newNode->src = src;
    newNode->des = des;
    return newNode;
}

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node *)malloc(capacity * sizeof(struct Node));
    return minHeap;
}

void swapNodes(struct Node *a, struct Node *b)
{
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].weight < minHeap->array[smallest].weight)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].weight < minHeap->array[smallest].weight)
        smallest = right;

    if (smallest != idx)
    {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

void insert(struct MinHeap *minHeap, int weight, int src, int des)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }

    int i = minHeap->size;
    minHeap->array[i].weight = weight;
    minHeap->array[i].src = src;
    minHeap->array[i].des = des;
    minHeap->size++;

    while (i && minHeap->array[i].weight < minHeap->array[(i - 1) / 2].weight)
    {
        swapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Node extractMin(struct MinHeap *minHeap)
{
    if (minHeap->size <= 0)
    {
        struct Node nullNode = {-1, -1, -1};
        return nullNode;
    }
    if (minHeap->size == 1)
    {
        minHeap->size--;
        return minHeap->array[0];
    }

    struct Node root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void printHeap(struct MinHeap *minHeap)
{
    for (int i = 0; i < minHeap->size; ++i)
    {
        printf("%d %d %d\n", minHeap->array[i].weight, minHeap->array[i].src, minHeap->array[i].des);
    }
    printf("\n");
}

int findRootParent(int node, int parent[])
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findRootParent(parent[node], parent);
}

void unionBySize(int u, int v, int parent[], int size[])
{
    int rootParentU = findRootParent(u, parent);
    int rootParentV = findRootParent(v, parent);
    if (rootParentU != rootParentV)
    {
        if (size[rootParentU] < size[rootParentV])
        {
            parent[rootParentU] = rootParentV;
            size[rootParentV] += size[rootParentU];
        }
        else
        {
            parent[rootParentV] = rootParentU;
            size[rootParentU] += size[rootParentV];
        }
    }
}

int main()
{
    int size = 0;
    int parent[HEAP_SIZE];
    int sizeArray[HEAP_SIZE];
    for (int i = 0; i <= HEAP_SIZE; i++)
    {
        parent[i] = i;
        sizeArray[i] = 1;
    }

    struct MinHeap *minHeap = createMinHeap(HEAP_SIZE);

    insert(minHeap, 3, 1, 3);
    insert(minHeap, 6, 3, 7);
    insert(minHeap, 5, 7, 4);
    insert(minHeap, 4, 4, 1);
    insert(minHeap, 10, 1, 2);
    insert(minHeap, 5, 2, 4);
    insert(minHeap, 1, 4, 6);
    insert(minHeap, 11, 2, 5);
    insert(minHeap, 3, 5, 6);
    insert(minHeap, 9, 6, 7);

    printHeap(minHeap);
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    int N = 7;
    printf("%d\n", minHeap->size);
    int mst = 0;
    while (N > 1)
    {
        struct Node minNode = extractMin(minHeap);
        int weight = minNode.weight;
        int src = minNode.src;
        int des = minNode.des;
        unionBySize(src, des, parent, sizeArray);
        mst += weight;
        N--;
    }

    printf("Minimum Spanning Tree weight: %d\n", mst);

    free(minHeap->array);
    free(minHeap);

    return 0;
}
