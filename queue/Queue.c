#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int rear;
	int front;
	int size;
	int* arr;
}queue;

void enqueue(int ,queue*);
int dequeue(queue*);
void display(queue*);
void operations(queue*);

void enqueue(int x,queue *q){
	if(q->front==q->size-1){
		printf("queue is full\n");
		return;
	}else {
		if(q->rear==-1)	
			q->rear++;
		q->front++;
		q->arr[q->front] = x;
		printf("%d added to queue\n",x);
	}return;
}

int dequeue(queue *q){
	int n;
	if(q->rear==-1 ){
		printf("queue is empty\n");
		return -1;
	}else{
		printf("value of %d\n",q->rear);
		q->rear++;
		n = q->arr[q->rear-1];
		printf("%d is deleted\n",n);
		if(q->front>q->rear)
			q->front = q->rear = -1;
		return n;
	}
}

void operations(queue* q){
	int op=1,data,key;
	printf("-------program starts-------\n");
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.enque\n2..dequeu\n0.EXIT\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to push:  ");
			scanf("%d",&data);
			enqueue(data,q);
		}
		else if(op == 2){
			dequeue(q);
		}
		if(op>=1 && op<=2) 
			display(q);
		else
			break ;
	}
}

void display(queue* q){
	if(q->front==-1)
		printf("queue is empty");
	else{
		printf("displaying queue......\n");
		for(int i=q->rear;i<=q->front;i++)
			printf(" %d ",q->arr[i]);
	}
	printf("\n");
} 

void main(){
	queue  q ;
	q.rear = q.front = -1;
	q.size = 5;
	q.arr = (int *)malloc(sizeof(int)*q.size);
	operations(&q);
}
