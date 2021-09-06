#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
	int top ;
	int size;
	int *arr;
}stack;

void push(stack* stack1,int x);
int pop(stack *stack1);
int isEmpty(stack *stack1);
int isFull(stack *stack1);
void show(stack *stack1);

void push(stack* stack1,int x){
	if(stack1->top>=stack1->size-1){
		printf("The stack is full, cannot add any more element");
		show(stack1);
	}
	else{
		printf("Element pushed in\n");
		stack1->arr[++stack1->top]=x;
		show(stack1);
	}
}

int pop(stack *stack1){
	if(isEmpty(stack1)){
		printf("Stack is empty so cannot pop element\n");
		show(stack1);
		return -1;
	}
	else{
		printf("Element popped out\n");
		--stack1->top;
		show(stack1);
		return stack1->arr[stack1->top];
	}
}

int isEmpty(stack *stack1){
	if(stack1->top<0)
		return 1;
	else
		return 0;
}

int isFull(stack *stack1){
	if(stack1->top >= stack1->size-1)
		return 1;
	else
		return 0;
}

void show(stack *stack1){
	printf("displaying the stack\n");
	if(stack1->top<0)
		printf("Stack is empty\n");
	else{
	for (int i = 0; i <= stack1->top; i += 1)
		printf("%d  ",stack1->arr[i]);
	printf("\n");
	}
}

void operations(stack* stack1){
	int op=1,data,key;
	printf("-------program starts-------\n");
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.PUSH\n2.POP\n3.SHOW\n0.EXIT\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to PUSH  ");
			scanf("%d",&data);
			push(stack1,data);
		}
		else if(op == 2){
			printf("poppping the  element   \n");
			pop(stack1);
		}
		else if(op == 3)
			show(stack1);
		else
			break ;
		}
}

void main(){
	stack stack1;
	stack1.size=5;
	stack1.top=-1;
	stack1.arr = (int* )malloc(stack1.size*sizeof(int));
	operations(&stack1);
}
