#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define CAPACITY 1000
 struct stack
{
 int data;
 struct stack *next;
}
*top;
int size=0;
void push(int element);
int pop();
int main(){
	int choice,data;
	while(1){
		printf("1.push");
		printf("2.pop");
		printf("3.Display");
       		printf("4.exit");
		scanf("%d",choice);
	switch (choice){
		case 1:
			printf("enter data to push into stack");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			data = pop();
			if(data!=INT_MAIN)
			printf("data=>%d",size);
			break;
		case 3:
	               printf("stack size %d",size);
       			break;
 		case 4:
			printf("existing from app:");
                        exit(0);
                         break;
                  default:
                          printf("invalid choice,please try again");
                     }
                           printf("\n");
	}
                      return 0;
}
    
void push(int element);
{
	if(size>=capacity){
		printf("stack overflows cant add elements");
		return;


	}

	struct stack* newNode = ((struct stack*)malloc(sizeof struct stack));
        newNode->data=top;
	newNode->next=top;
         top = newNode;
	  size++;
	  printf("Data pushed to stack");



}
int pop()
{
	int data=0;
	struct stack* topNode;
	if(size<=0//!top){
		printf("stack is empty");
	          return INT_MIN;
}
topNode=top;
data = top->next;
free(topNode);
size--;
return data;
}


