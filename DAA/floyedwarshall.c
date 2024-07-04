// #include <stdio.h>

// #define INF 1000000000

// void initializeGraph(int N, int matrix[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             int wt;
//             printf(" edge weight vertex %d to vertex %d (-1 to skip it): ", i, j);
//             scanf("%d", &wt);
//             matrix[i][j] = (wt == -1) ? INF : wt;
//         }
//     }
// }

// void floydWarshall(int N, int matrix[N][N])
// {
//     for (int k = 0; k < N; k++)
//     {
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 if (matrix[i][k] < INF && matrix[k][j] < INF)
//                 {
//                     if (matrix[i][j] > matrix[i][k] + matrix[k][j])
//                     {
//                         matrix[i][j] = matrix[i][k] + matrix[k][j];
//                     }
//                 }
//             }
//         }
//     }
// }

// int detectNegativeCycle(int N, int matrix[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         if (matrix[i][i] < 0)
//         {
//             return 1; // Graph contains a negative edge weight cycle
//         }
//     }
//     return 0; // No negative cycle found
// }

// void printGraph(int N, int matrix[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int N;
//     printf("name: Shiv Patel\n");
//     printf("Roll No: 22BCP317\n");
//     printf("Enter number of vertices in graph: ");
//     scanf("%d", &N);

//     int matrix[N][N];

//     initializeGraph(N, matrix);

//     for (int i = 0; i < N; i++)
//     {
//         matrix[i][i] = 0;
//     }

//     floydWarshall(N, matrix);

//     if (detectNegativeCycle(N, matrix))
//     {
//         printf("Graph contains a negative edge weight cycle.\n");
//     }
//     else
//     {
//         printf("Shortest path matrix:\n");
//         printGraph(N, matrix);
//     }

//     return 0;
// }

#include <stdio.h>

#define INFINITY_VAL 1000000000

int main()
{
    int numVertices;
    printf("Name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Please input the number of vertices in the graph: \n");
    scanf("%d", &numVertices);

    int graph[numVertices][numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            int weight;
            printf("Enter weight of edge from vertex %d to vertex %d (-1 to skip): ", i, j);
            scanf("%d", &weight);
            graph[i][j] = weight;
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] == -1)
                graph[i][j] = INFINITY_VAL;
            if (i == j)
                graph[i][j] = 0;
        }
    }

    for (int k = 0; k < numVertices; k++)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (graph[i][k] < INFINITY_VAL && graph[k][j] < INFINITY_VAL)
                {
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    printf("Shortest path matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}