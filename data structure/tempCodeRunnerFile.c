ude <stdio.h>

// int linearsearch(int arr[], int size, int num)
// {
//     int i;
//     for (i = 0; i < size; i++)
//     {
//         if (arr[i] == num)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[] = {1, 2, 44, 56, 7, 5};
//     int size;
//     int num = 44;
//     size = sizeof(arr) / sizeof(arr[0]);
//     int result = linearsearch(arr, size, num);
//     if (result != -1)
//     {
//         printf("Element %d found at index %d\n", num, result);
//     }
//     else
//     {
//         printf("Element %d not found in the array\n", num);
//     }
//     //  printf("%d\n",result);

//     return 0;
// }