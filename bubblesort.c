#include <stdio.h>
#define MAXSIZE 100
void main(){
	int arr[MAXSIZE];
	int i,j,num,temp;
	printf("enter the value of num");
	scanf("%d",&num);
	printf("entr the elementds");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}

	//bubble sort begins
	for(i=0;i<num;i++){
		for(j=0;j<(num-i-1);j++)
		{
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	printf("sorted list");
	for(i=0;i<num;i++){
		printf("%d",arr[i]);
	
		}
	}
