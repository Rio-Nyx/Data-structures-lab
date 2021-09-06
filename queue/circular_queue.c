// circular queue
/*
	rear -- end of queue
	front -- start of queue
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int size;
	int front ;
	int rear;
	int *arr;
}queue;

void createQueue(queue* q){
	q->size = 3;
	q->arr = (int *)malloc(sizeof(int)*q->size);
	q->front = -1;
	q->rear = -1;
	printf("Circular queue is successfully created\nMaximum size of queue %d\n",q->size);
}

void display(queue* q){
	int i;
	if(q->front==-1)
		printf("queue is empty\n");
	else{
		printf("displaying queue...........\n");
		for (i = q->front; i != q->rear; i=(i+1)%q->size){
			printf(" %d ",q->arr[i]);
		}
		printf("%d\n",q->arr[i]);
	}
}

void enqueue(int data, queue* q){
/*	if(q->front+q->rear==q->size-1)*/
	if(q->rear+1 == q->front || (q->front==0 && q->rear==q->size-1))
		printf("queue is full. Cannot add more elements\n");
	else{
		if(q->rear == -1)
			q->front = 0;
		q->rear = (q->rear+1)%q->size;
		q->arr[q->rear] = data;
		printf("%d is added tot circular queue\n",data);
		display(q);
	}
}

int dequeue(queue* q){
	int val;
	int isOne = 0;
	if(q->front == -1)
		printf("Inavlid operation. Queue is empty\n");
	else{
		val = q->arr[q->front];
		if(q->front==q->rear)
			isOne = 1;
		q->front = (q->front+1)%q->size;
		if(isOne)
			q->front = q->rear = -1;
		display(q);
		return val;
	}
	return -1;
}

int peek(queue* q){
	if(q->front==-1){
		printf("queue is empty \n");
		return -1;
	}
	else
		return q->arr[q->front];
}

void operations(queue* q){
	dequeue(q);	// tring to dequeue an empty queue
	enqueue(5,q);
	enqueue(6,q);
	enqueue(7,q);
	enqueue(9,q);	// trying to add an element to an full queue
	dequeue(q);
	dequeue(q);
	dequeue(q);		// emptying a queue
	dequeue(q);		// trying to dequeue an empty queue
	enqueue(8,q);
}

void main(){
	queue q;
	createQueue(&q);
	operations(&q);
}
