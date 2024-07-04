#include <stdio.h>
int max(int x, int y)
{
    return (x > y) ? x : y;
}
typedef struct node
{
    int cost;
    int qty;
    int imp;
} node;
int top_down(int n, int profit[n], int wgt[n], int bug, int memo[bug + 1][n + 1])
{
    if (n == 0 || bug == 0)
        return 0;
    if (memo[bug][n] != -1)
        return memo[bug][n];
    if (wgt[n - 1] > bug)
    {
        return memo[bug][n] = top_down(n - 1, profit, wgt, bug, memo);
    }
    else
    {
        int x = top_down(n - 1, profit, wgt, bug, memo);
        int y = top_down(n - 1, profit, wgt, bug - wgt[n - 1], memo) + profit[n - 1];
        memo[bug][n] = max(x, y);
        return memo[bug][n];
    }
}
int main()
{
    int n;
    scanf("enter the value of n : %d", &n);
    int bug;
    scanf("enter the value of bug : %d", &bug);
    node a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].cost);
        scanf("%d", &a[i].qty);
        scanf("%d", &a[i].imp);
    }
    int profit[n];
    int wgt[n];
    for (int i = 0; i < n; i++)
    {
        profit[i] = a[i].imp;
        wgt[i] = a[i].qty * a[i].cost;
    }
    int memo[bug + 1][n + 1];
    for (int i = 0; i <= bug; i++)
    {
        for (int j = 0; j <= n; j++)
            memo[i][j] = -1;
    }
    printf("%d", top_down(n, profit, wgt, bug, memo));
}