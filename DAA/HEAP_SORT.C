#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct min_heap
{
    int *array;
    int capacity;
    int head;
};

struct min_heap *create_min_heap(int capacity)
{
    struct min_heap *min_heap = (struct min_heap *)malloc(sizeof(struct min_heap));
    min_heap->capacity = capacity;
    min_heap->head = 0;
    min_heap->array = (int *)malloc(min_heap->capacity * sizeof(int));
    return min_heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct min_heap *min_heap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < min_heap->head && min_heap->array[left] < min_heap->array[smallest])
        smallest = left;

    if (right < min_heap->head && min_heap->array[right] < min_heap->array[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&min_heap->array[index], &min_heap->array[smallest]);
        min_heapify(min_heap, smallest);
    }
}

void insert_key(struct min_heap *min_heap, int key)
{
    if (min_heap->head == min_heap->capacity)
    {
        printf("Overflow: Could not insert key\n");
        return;
    }

    int i = min_heap->head;
    min_heap->array[i] = key;
    min_heap->head++;

    while (i != 0 && min_heap->array[(i - 1) / 2] > min_heap->array[i])
    {
        swap(&min_heap->array[i], &min_heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_min(struct min_heap *min_heap)
{
    if (min_heap->head <= 0)
        return 0;

    if (min_heap->head == 1)
    {
        min_heap->head--;
        return min_heap->array[0];
    }

    int root = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->head - 1];
    min_heap->head--;
    min_heapify(min_heap, 0);

    return root;
}

int main()
{
    struct min_heap *min_heap = create_min_heap(100);

    insert_key(min_heap, 6);
    insert_key(min_heap, 2);
    insert_key(min_heap, 7);
    insert_key(min_heap, 8);
    insert_key(min_heap, 4);

    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Extracted min: %d\n", extract_min(min_heap));

    free(min_heap->array);
    free(min_heap);

    return 0;
}
