#include <stdio.h>
#include <stdbool.h>

#define N_MAX 10

int N;
int adjacency[N_MAX][N_MAX];
int finalPath[N_MAX + 1];
bool visited[N_MAX];
int minCost = __INT_MAX__;

void copyPathToFinal(int currentPath[])
{
    for (int i = 0; i < N; i++)
        finalPath[i] = currentPath[i];
    finalPath[N] = currentPath[0];
}

int firstMinimum(int i)
{
    int minimum = __INT_MAX__;
    for (int k = 0; k < N; k++)
        if (adjacency[i][k] < minimum && i != k)
            minimum = adjacency[i][k];
    return minimum;
}

int secondMinimum(int i)
{
    int first = __INT_MAX__, second = __INT_MAX__;
    for (int j = 0; j < N; j++)
    {
        if (i == j)
            continue;
        if (adjacency[i][j] <= first)
        {
            second = first;
            first = adjacency[i][j];
        }
        else if (adjacency[i][j] <= second && adjacency[i][j] != first)
        {
            second = adjacency[i][j];
        }
    }
    return second;
}

void tspRec(int currentBound, int currentWeight, int level, int currentPath[])
{

    if (level == N)
    {
        if (adjacency[currentPath[level - 1]][currentPath[0]] != 0)
        {
            int currentResult = currentWeight + adjacency[currentPath[level - 1]][currentPath[0]];
            if (currentResult < minCost)
            {
                copyPathToFinal(currentPath);
                minCost = currentResult;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {

        if (adjacency[currentPath[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = currentBound;
            currentWeight += adjacency[currentPath[level - 1]][i];

            if (level == 1)
                currentBound -= ((firstMinimum(currentPath[level - 1]) + firstMinimum(i)) / 2);
            else
                currentBound -= ((secondMinimum(currentPath[level - 1]) + firstMinimum(i)) / 2);

            if (currentBound + currentWeight < minCost)
            {
                currentPath[level] = i;
                visited[i] = true;
                tspRec(currentBound, currentWeight, level + 1, currentPath);
            }

            currentWeight -= adjacency[currentPath[level - 1]][i];
            currentBound = temp;
            for (int j = 0; j <= level - 1; j++)
                visited[currentPath[j]] = true;
        }
    }
}

void tspSolver()
{
    int currentPath[N_MAX + 1];
    int currentBound = 0;

    for (int i = 0; i < N; i++)
        currentBound += (firstMinimum(i) + secondMinimum(i));
    currentBound = (currentBound == 1) ? currentBound / 2 + 1 : currentBound / 2;
    visited[0] = true;
    currentPath[0] = 0;
    tspRec(currentBound, 0, 1, currentPath);
}

int main()
{
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &adjacency[i][j]);
        }
    }

    tspSolver();

    printf("\nMinimum cost: %d\n", minCost);
    printf("Final Path:\n");
    for (int i = 0; i <= N; i++)
    {
        printf("%d ", finalPath[i]);
    }
    printf("\n");
    return 0;
}
