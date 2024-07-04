#include <stdio.h>

void maxItems(int n, int m, int food_quantity[], int food_cost[], int decoration_quantity[], int decoration_rate[], int budget)
{
    int max_food = 0, max_decoration = 0;
    int food_indices[n], decoration_indices[m];
    int i, j;

    // Greedy approach for food items
    for (i = 0; i < n; i++)
    {
        if (food_cost[i] <= budget)
        {
            max_food += food_quantity[i];
            budget -= food_cost[i];
            food_indices[i] = 1; // Mark as bought
        }
        else
        {
            food_indices[i] = 0; // Mark as not bought
        }
    }

    // Greedy approach for decoration items
    for (j = 0; j < m; j++)
    {
        if (decoration_rate[j] <= budget)
        {
            max_decoration += decoration_quantity[j];
            budget -= decoration_rate[j];
            decoration_indices[j] = 1; // Mark as bought
        }
        else
        {
            decoration_indices[j] = 0; // Mark as not bought
        }
    }

    printf("Maximum food items bought: %d\n", max_food);
    printf("Food indices: ");
    for (i = 0; i < n; i++)
    {
        if (food_indices[i] == 1)
            printf("%d ", i + 1);
    }
    printf("\n");

    printf("Maximum decoration items bought: %d\n", max_decoration);
    printf("Decoration indices: ");
    for (j = 0; j < m; j++)
    {
        if (decoration_indices[j] == 1)
            printf("%d ", j + 1);
    }
    printf("\n");
}

int main()
{
    // Test case
    int food_quantity[] = {2, 1, 2, 1};
    int food_cost[] = {10, 20, 30, 40};
    int decoration_quantity[] = {1, 3, 2};
    int decoration_rate[] = {20, 50, 30};
    int budget = 150;
    int n = sizeof(food_quantity) / sizeof(food_quantity[0]);
    int m = sizeof(decoration_quantity) / sizeof(decoration_quantity[0]);

    maxItems(n, m, food_quantity, food_cost, decoration_quantity, decoration_rate, budget);

    return 0;
}

