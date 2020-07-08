#include "stdio.h"

int main()
{
	   int a,b,c,r;
   	scanf("%d%d",&a,&b);
	
	   if(a>=b)
   	{
       while(a%b!=0)
	       {
		          r=a%b;
		          a=b;
		          b=r;
	       }
   	}
   	else
   	{
       		c=a;a=b;b=c;
	       while(a%b!=0)
	       {
		          r=a%b;
		          a=b;
		          b=r;
	       } 
   	}
	
	   printf("%d",r);
	   return 0;
	} 
