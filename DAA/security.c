#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    double first;
    int second;
};

int cmp(const struct Pair *a, const struct Pair *b)
{
    return (a->first < b->first) ? -1 : ((a->first > b->second) ? 1 : 0);
}

int main()
{
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Enter Number of licenses needed to Purchase : ");
    int n;
    scanf("%d", &n);
    struct Pair rates[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Growth Rate for %dth Licenses : ", i + 1);
        scanf("%lf", &rates[i].first);
        rates[i].second = i;
    }

    qsort(rates, n, sizeof(struct Pair), (int (*)(const void *, const void *))cmp);

    printf("Order in Which Licenses Should Be Bought :\n");
    int minCost = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d    ", rates[i].second);
        minCost = minCost + 100 * rates[i].first * (n - i);
    }

    printf("\nMinimum Cost to purchase N licenses : %d\n", minCost);

    return 0;
}
