// Online C compiler to run C program online#include <stdio.h>
#include<stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;

    int* ptr_arr[3] = { &num1, &num2, &num3 };

    for (int i = 0; i < 3; i++) {
        printf("Value of var%d: %d\tAddress: %p\n", i + 1, *ptr_arr[i], ptr_arr[i]);
    }
    return 0;
}