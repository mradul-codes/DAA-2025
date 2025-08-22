
#include <stdio.h>

int main(){
    int arr[]={2,5,1,6,4};
    int t;
    int n = sizeof(arr)/sizeof(arr[0]);
    

    for(int j=0;j<n-1;j++) {
        for(int i=0;i<n-1-j;i++) {
            if(arr[i]>arr[i + 1]) {
                t=arr[i];
                arr[i]=arr[i + 1];
                arr[i+1]=t;
            }
        }
    }

    for(int k=0;k<n;k++) {
        printf("%d ",arr[k]);
    }

    return 0;
}
