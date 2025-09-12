# include<stdio.h>

int fibb(int n);

int main()
{
   printf("%d", fibb(6));
    return 0;
}
int fibb(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int x=fibb(n-1);
    int y=fibb(n-2);
    int z=x+y;
    printf("the fib  %d is%d\n",n,z);
    return z;
}
