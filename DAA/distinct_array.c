#include <stdio.h>

int findPeak(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int n;
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, n);

    printf("Peak element is at index %d\n", peakIndex);

    return 0;
}
