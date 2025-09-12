# include<stdio.h>

int sum(int n);

int main()
{
    int n;
    printf("write no.:");
    scanf("%d",&n);
    printf("factorial  is:%d",sum(n));
    return 0;
}
int sum(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 1;
    }
    int x=sum(n-1);
    int y=n*x;
    return y;
}