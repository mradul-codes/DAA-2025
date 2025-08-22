
#include <stdio.h>

int main() {
    int arr[] = {1,4,3,6,2,9,21};
    int i;
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    int min=arr[0];

    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min) {
            min=arr[i];
        }
    }

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}
