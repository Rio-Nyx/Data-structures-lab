#include <stdio.h>
#include <stdlib.h>

typedef struct p_queue{
	int size;
	int* queue;
	int* priority;
	int front;
	int rear;
}p_queue;

void createPqueue(p_queue* pq){
	pq->size = 5;
	pq->queue = (int *)malloc(sizeof(int)*pq->size);
	pq->priority = (int *)malloc(sizeof(int)*pq->size);
	pq->front = -1;
	pq->rear = -1;
}

void display(p_queue* pq){
	if(pq->front ==-1)
		printf("queue is empty\n");
	else{
		printf("displaying queue....\n");
		for (int i = pq->front; i <= pq->rear; i++){
			printf("Element = %d , Priority = %d \n",pq->queue[i],pq->priority[i]);
		}
	}
}

void insert(int data,int pr, p_queue* pq){
	int i,j;
	i=0;
	if(pq->rear == pq->size-1)
		printf("queue is full\n");
	else{
		if(pq->front == -1){
			pq->front = pq->rear = 0;
			pq->queue[pq->rear] = data;
			pq->priority[pq->rear] = pr; 
		}
		// ordering the array in descending order
		else{
			while(i<=pq->rear && pr<=pq->priority[i]){ // searching for priority lower than than of input
				i++;
			}
			for(j = pq->rear;j>=i;j--){
				pq->queue[j+1]=pq->queue[j];
				pq->priority[j+1]=pq->priority[j];
			}
			pq->queue[i] = data;
			pq->priority[i] = pr;
			++pq->rear;
		}
		display(pq);
	}
}

int delete(p_queue* pq){
	int data =-1;
	if(pq->front==-1)
		printf("queue is empty\n");
	else{
		data = pq->queue[pq->front];
		if(pq->front ==pq->rear)
			pq->front = pq->rear = -1;
		else
			++pq->front;
		display(pq);
	}
	return data;
}

void operations(p_queue* pq){
	int op=1,data,pr;
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.INSERT\n2.DELETE\n3.EXIT\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to add:  ");
			scanf("%d",&data);
			printf("Enter the priority of above element:  ");
			scanf("%d",&pr);
			insert(data,pr,pq);
		}
		else if(op == 2){
			delete(pq);
		}
		else
			break ;
	}
}

void main(){
	p_queue pq;
	createPqueue(&pq);
	operations(&pq);
}
