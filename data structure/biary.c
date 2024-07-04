// #include<stdio.h>
// int linearsearch(int arr[],int size,int x)
// {
//     int i;
//     for(i=0; i<size;i++){
//         if(arr[i]==x){
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[]={1,2,3,4,5};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     int x=3;
//     int index=linearsearch(arr,size,x);
//     if(index==-1){
//         printf("element not found");
//     }
//     else{
//         printf("element found at index %d",index);
//     }
//     return 0;
// }


#include <stdio.h>

int binarySearch(int arr[], int size, int x) {
    int low= 0,
    int high= size - 1;
    int mid;
    while (low<= high) {
         mid = (low + high) / 2;

        if (arr[mid] == x){

            return mid;}

        else if(arr[mid] < x){
            low = mid + 1;
        }
            
        else{
            high = mid - 1;
        }
            
    }

    return -1; 
}

int main() {
    int arr[] = {1,3,23,24,40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x=3;

    int index = binarySearch(arr, size, x);

    if (index == -1){
        printf("Element not found\n");
    }
    else{
       printf("Element found at index %d\n", index); 
    }
    return 0;
}
