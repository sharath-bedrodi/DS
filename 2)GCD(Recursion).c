#include<stdio.h>
#include<math.h>
int GCD(int, int);
int main()
{
int m,n;
printf("\n\n Recursion: Find GCD of two numbers :\n");
printf("---------------------------------\n");
printf(" Input 1st number: ");
scanf("%d",&m);
printf("Input 2nd number: ");
scanf("%d",&n);
printf("\n The GCD of %d and %d is: %d\n\n",m,n,GCD(m,n));
return 0;
}
int GCD(int m, int n)
{
if(n==0) 
 return m;
if (m<n) 
 return GCD(n,m); 
else
 return GCD(n,m % n);
}