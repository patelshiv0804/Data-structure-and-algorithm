
#include <stdio.h>
#include <stdlib.h>

//FOR PRINTING THE ARRAY 
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to find the maximum number in the array
int findMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Function to perform counting sort on a specific digit's place value
void countingSort(int A[], int n, int exp){
    const int base = 10; // Radix/base is 10 for decimal numbers
    int output[n];
    int count[base];

    // Manually initialize each element of the count array to zero
    for (int i = 0; i < base; i++){
        count[i] = 0;
    }

    // Count occurrences of each digit at the current place value
    for (int i = 0; i < n; i++){
        count[(A[i] / exp) % base]++;
    }

    // Adjust the count array to store actual position of the digits in output
    for (int i = 1; i < base; i++){
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--){
        output[count[(A[i] / exp) % base] - 1] = A[i];
        count[(A[i] / exp) % base]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++){
        A[i] = output[i];
    }
}

// Radix Sort function using Most Significant Digit (MSD) approach
void radixSort(int A[], int n){
    // Find the maximum number to know the number of digits
    int max = findMax(A, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(A, n, exp);
    }
}

// Driver program to test the radixSort function
int main() {
    int n; 
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, n);

    radixSort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
