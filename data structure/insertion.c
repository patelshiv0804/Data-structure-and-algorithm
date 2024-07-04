#include<stdio.h>

int main()
{
int a[]={64,34,1,12,22,11,90};
int n=sizeof(a)/sizeof(a[0]);
int i,j,key;

for(j=1;j<n;j++){
    key=a[j];
    i=j-1;

    while(i>0 && a[i]>key){
        a[i+1]=a[i];
        i=i-1;

    }
    a[i+1]=key;
}
   printf("your sorted array:");

for(int i=0; i<n ; i++){
    printf("%d",a[i]);
}
    return 0;
}