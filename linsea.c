//c program for linear search
#include <stdio.h>
int main()
	{ int a[20],i,x,n;
	printf("how many elements");
         scanf("%d",&n);
       printf("enter array elements");
      for(i=0;i<n;i++){
       scanf("%d",&a[i]);
      }
 printf("etner elemtns to search");
 scanf("%d",&x);
 for(i=0;i<n;i++)
	 if(a[i]==x)
		 break;
   if(i<n)
	   printf("element fount at %d",i);
   else
	   printf("elemtt not found");
   return 0;
	}
