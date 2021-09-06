#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void display(Node* );
void push(int,Node* );
int pop(Node*);
void operations(Node*);
void freeList(Node*);

void display(Node* header){
	if(header->next==NULL)
		printf("empty stack\n");
	else{
		Node* ptr ;
		ptr = header->next;
		while(ptr!=NULL){
			printf(" %d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
		free(ptr);
	}
}

void push(int data, Node* header){
	Node* node;
	node = (Node*) malloc (sizeof(Node));
	if(node==NULL){
		printf("no available memory\n");
		return;
	}
	node->next = header->next;
	header->next = node;
	node->data = data;
}

int pop(Node* header){
	if(header->next==NULL){
		printf("empty list\n");
		return -1;
	}
	else{
		int data = header->next->data;
		Node* ptr = header->next->next;
		free(header->next);
		header->next = ptr;
		return data;
	}
}

void operations(Node* header){
	int op=1,data,key;
	printf("-------program starts-------\n");
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.PUSH\n2..POP\n0.EXIT\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to push:  ");
			scanf("%d",&data);
			push(data,header);
		}
		else if(op == 2){
			pop(header);
		}
		if(op>=1 && op<=2) 
			display(header);
		else
			break ;
	}
		freeList(header);
}

void freeList(Node* header){
	header = header->next;
	while(header!=NULL){
		Node* ptr = header;
		header = header->next ;
		free(ptr);
	}
}

void main(){
	Node header;
	header.data = -5;
	header.next = NULL;
	operations(&header);
}
