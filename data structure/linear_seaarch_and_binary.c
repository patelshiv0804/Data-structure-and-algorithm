#include <stdio.h>

int linearsearch(int arr[], int size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[] = {1, 2, 44, 56, 7, 5};
    int size;
    int num = 44;
    size = sizeof(arr) / sizeof(arr[0]);
    int result = linearsearch(arr, size, num);
    if (result != -1)
    {
        printf("Element %d found at index %d\n", num, result);
    }
    else
    {
        printf("Element %d not found in the array\n", num);
    }
    //  printf("%d\n",result);

    return 0;
}

// ---------------------------------->binary search<-----------------------------------------------

#include <stdio.h>

int binary(int a, int arr[50], int start_index, int end_index)
{

    while (start_index <= end_index)
    {
        int mid_index = (start_index + end_index) / 2;
        if (a == arr[mid_index])
        {
            return mid_index;
        }
        else if (a < arr[mid_index])
        {
            end_index = mid_index - 1;
        }
        else if (a > arr[mid_index])
        {
            start_index = mid_index + 1;
        }
    }
    return -1;
}

int main()
{

    int start_index = 0;
    int end_index;
    int arr[50];
    int a;
    printf("Enter the no. of total elements you want\n");
    scanf("%d", &end_index);
    printf("Enter the elements\n");
    for (int i = 0; i < end_index; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the no. from the array of which you want index \n");
    scanf("%d", &a);

    int result = binary(a, arr, start_index, end_index);

    printf("The Index is of %d is %d", a, result);
    return 0;
}

// #include <stdio.h>

// int binary_search(int arr[], int size, int target)
// {
//     int left = 0;
//     int right = size - 1;
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] == target)
//         {
//             return mid;
//         }

//         if (arr[mid] < target)
//         {

//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }

//     return -1; // Element not found
// }

// int main()
// {
//     int mySortedArray[] = {1, 3, 5, 7, 9};
//     int targetElement = 5;
//     int size = sizeof(mySortedArray) / sizeof(mySortedArray[0]);
//     int result = binary_search(mySortedArray, size, targetElement);

//     if (result != -1)
//     {
//         printf("Element %d found at index %d\n", targetElement, result);
//     }
//     else
//     {
//         printf("Element %d not found in the array\n", targetElement);
//     }

//     return 0;
// }
