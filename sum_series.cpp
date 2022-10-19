#include<stdio.h>
int series(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	fact=fact*i;
	return fact;
}
int main()
{
int n,sum=0,i;
printf("ENTER THE LAST DIGIT OF THE SERIES(OR VALUE OF N)::");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	sum=sum+series(i);
}
printf("THE SUM OF THE SERIES::%d",sum);
}
