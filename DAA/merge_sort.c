#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            i++;
            k++;
        }
        else
        {
            B[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = a[j];
        k++;
        j++;
    }
    // for printing the b[] into a[]
    for (int i = low; i <= high; i++)
    {
        a[i] = B[i];
    }
}

void mergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int n;
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements for the array:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("before the sorting:");
    printArray(a, n);
    mergeSort(a, 0, n);
    printf("after the sorting:");
    printArray(a, n);
    return 0;
}
