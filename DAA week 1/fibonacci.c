#include <stdio.h>

int main(){
    int a; 
    int b=0;
    int c=1;

    for(int i=0;i<9;i++){
        if(i<=1){
            a=i;
        }else{
            a=b+c;
            b=c;
            c=a;
        }
        printf("%d ", a);
    }

    return 0;
}