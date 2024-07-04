// #include <stdio.h>

// int customSwap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int main()
// {
//     printf("Number Transformation Enigma\n");

//     int num1, num2;
//     printf("Enter the first enigma number: ");
//     scanf("%d", &num1);
//     printf("Enter the second enigma number: ");
//     scanf("%d", &num2);

//     customSwap(&num1, &num2);

//     printf("The enigma's hidden truth: %d\n", num1);
//     printf("The enigma's revealed secret: %d\n", num2);

//     return 0;
// }
#include <stdio.h>
int main()
{
    int size;
    printf("This is roll no 317!!\n");
    printf("Enter the size of array:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *ptr = arr;
    printf("The pointer to array is:%p", ptr);
    return 0;
}
