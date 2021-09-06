// double ended queue using array

#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
	int size;
	int front;
	int rear;
	int* arr;
}deque;

void createDeque(deque* dq){
	dq->size = 5;
	dq->arr = (int *)malloc(sizeof(int)*dq->size);
	dq->front = -1;
	dq->rear = -1;
}

void display(deque* dq){
	int i;
	for(i=dq->front;i<=dq->rear;i++)
		printf(" %d ",dq->arr[i]);
	printf("\n");
}

void insert_End(int data, deque* dq){
	if(dq->rear == dq->size-1)
		printf("operation not possible\n");
	else{
		if(dq->front == -1)
			dq->front = 0;
		++dq->rear;
		dq->arr[dq->rear] = data;
	}
}

void insert_Front(int data,deque* dq){
/*	printf("before : %d***%d\n",dq->front,dq->rear);*/
	if((dq->front==0))
		printf("operation not possible\n");
	else{
		if(dq->front==-1 && dq->rear==-1){
			dq->rear = dq->front = 0;
			dq->arr[dq->front] = data;
		}
		else{
		--dq->front;
		dq->arr[dq->front] = data;
		}
	}
/*	printf("after : %d***%d\n",dq->front,dq->rear);*/
}

int delete_Front(deque* dq){
	int data = -1;
	if(dq->front == -1)
		printf("operation not possible\n");
	else{
		data = dq->arr[dq->front];
		if(dq->front==dq->rear)
			dq->front = dq->rear = -1;
		else 
			++dq->front;
	}
	return data;
}

int delete_End(deque* dq){
	int data = -1;
	if(dq->rear == -1)
		printf("operation not possible\n");
	else{
		data = dq->arr[dq->rear];
		if(dq->front == dq->rear)
			dq->front = dq->rear = -1;
		else
			--dq->rear;
	}
	return data;
}

void operations(deque* dq){
	int op=1,data;
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.INSERT_FRONT\n2.INSERT_END\n3.DELETE_FRONT\n4.DELETE_END\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to add:  ");
			scanf("%d",&data);
			insert_Front(data,dq);
		}
		else if(op == 2){
			printf("Enter the element to add at end:  ");
			scanf("%d",&data);
			insert_End(data,dq);
		}
		else if(op == 3){
			delete_Front(dq);
		}
		else if(op == 4){
			delete_End(dq);
		}
		if(op>=1 && op<=4)
			display(dq);
		else
			break ;
	}
}

void main(){
	deque dq;
	createDeque(&dq);
	operations(&dq);
}
