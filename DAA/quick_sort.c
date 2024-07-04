#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }
        // IF I> J THEN IT SWAP THE ELEMENT OF
        // |161|  175   152   180  178
        // |161|  175I  152J  180  178
        // |161|  152I  175J  180  178

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // IF J<I THEN IT SWAP THE POSITION OF A[J] BY A[LOW];
    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int n;
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("before the sorting:");
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf("after the sorting:");
    printArray(A, n);
    return 0;
}
