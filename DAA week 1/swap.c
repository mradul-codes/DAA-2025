
#include <stdio.h>
int main(){
    int temp;
    int a=5;
    int b=4;

    temp = a;
    a = b;
    b= temp;

    printf("%d\n",a);
    printf("%d",b);

return 0;
}
