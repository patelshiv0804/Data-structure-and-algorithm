#include<stdio.h>

void printarray(int *a ,int n){
    for(int i=0 ; i<n ; i++){
      printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionsort(int *a,int n){
    int key , j ;
    
    for ( int i=1 ; i<n ; i++){
        key = a[i];
        j = i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main() {
    int n;
    
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("before the sorting:");
    printarray(a,n);
    insertionsort(a,n);
    printf("after the sorting:");
    printarray(a,n);
    return 0;
}
