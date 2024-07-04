#include <stdio.h>

void heapify(int heap[100][3], int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left][0] < heap[smallest][0])
        smallest = left;

    if (right < size && heap[right][0] < heap[smallest][0])
        smallest = right;

    if (smallest != index)
    {
        int tempWeight = heap[index][0];
        int tempSrc = heap[index][1];
        int tempDes = heap[index][2];
        heap[index][0] = heap[smallest][0];
        heap[index][1] = heap[smallest][1];
        heap[index][2] = heap[smallest][2];
        heap[smallest][0] = tempWeight;
        heap[smallest][1] = tempSrc;
        heap[smallest][2] = tempDes;
        heapify(heap, size, smallest);
    }
}

void buildHeap(int heap[100][3], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, size, i);
    }
}

void insert(int heap[100][3], int *size, int weight, int src, int des)
{
    (*size)++;
    int i = *size - 1;
    heap[i][0] = weight;
    heap[i][1] = src;
    heap[i][2] = des;
    while (i != 0 && heap[(i - 1) / 2][0] > heap[i][0])
    {
        int tempWeight = heap[i][0];
        int tempSrc = heap[i][1];
        int tempDes = heap[i][2];
        heap[i][0] = heap[(i - 1) / 2][0];
        heap[i][1] = heap[(i - 1) / 2][1];
        heap[i][2] = heap[(i - 1) / 2][2];
        heap[(i - 1) / 2][0] = tempWeight;
        heap[(i - 1) / 2][1] = tempSrc;
        heap[(i - 1) / 2][2] = tempDes;
        i = (i - 1) / 2;
    }
}

void removeMin(int heap[100][3], int *size)
{
    if (*size <= 0)
    {
        printf("Nothing to delete\n");
        return;
    }
    if (*size == 1)
    {
        (*size)--;
        return;
    }

    heap[0][0] = heap[*size - 1][0];
    heap[0][1] = heap[*size - 1][1];
    heap[0][2] = heap[*size - 1][2];
    (*size)--;
    heapify(heap, *size, 0);
}

int spanningTree(int V, int adj[][100][2])
{
    int heap[100][3];
    int size = 0;
    int vis[100] = {0};
    int sum = 0;

    insert(heap, &size, 0, 0, 0);
    while (size > 0)
    {
        int node = heap[0][2];
        int wt = heap[0][0];
        removeMin(heap, &size);

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;

        for (int i = 0; i < V; ++i)
        {
            if (adj[node][i][0] != -1)
            {
                int adjNode = adj[node][i][0];
                int edW = adj[node][i][1];
                if (!vis[adjNode])
                {
                    insert(heap, &size, edW, node, adjNode);
                }
            }
        }
    }

    return sum;
}

int main()
{
    int V = 5;
    int edges[][3] = {{0, 1, 5}, {0, 2, 7}, {1, 2, 2}, {2, 3, 5}, {3, 4, 1}, {4, 2, 2}};
    int adj[5][100][2];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            adj[i][j][0] = -1;
            adj[i][j][1] = -1;
        }
    }
    for (int i = 0; i < 6; ++i)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        int weight = edges[i][2];
        for (int j = 0; j < 100; ++j)
        {
            if (adj[node1][j][0] == -1)
            {
                adj[node1][j][0] = node2;
                adj[node1][j][1] = weight;
                break;
            }
        }
        for (int j = 0; j < 100; ++j)
        {
            if (adj[node2][j][0] == -1)
            {
                adj[node2][j][0] = node1;
                adj[node2][j][1] = weight;
                break;
            }
        }
    }

    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    int sum = spanningTree(V, adj);
    printf("The sum of all the edge weights: %d\n", sum);

    return 0;
}
