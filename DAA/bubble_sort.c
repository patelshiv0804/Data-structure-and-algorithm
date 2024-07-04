#include<stdio.h>

void printarray(int a[], int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int a[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {

    printf("Name:Shiv Patel\n");
    printf("Roll No:22BCP317\n");

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    printarray(a, n);

    bubblesort(a, n);

    printf("Sorted array: ");
    printarray(a, n);

    return 0;
}
