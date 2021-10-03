#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void display(Node* );
void insert_front(int,Node* );
void insert_end(int,Node* );
void insert_afterKey(int,int,Node*);
int delete_front(Node*);
int delete_end(Node*);
int delete_atKey(int,Node*);
void operations(Node*);
void freeList(Node*);

void display(Node* header){
	if(header->next==NULL)
		printf("empty list\n");
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

void insert_front(int data, Node* header){
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

void insert_end(int data, Node* header){
	Node* node;
	node = (Node*) malloc (sizeof(Node));
	if(node==NULL){
		printf("no available memory\n");
		return;
	}
	Node* ptr = header;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = node;
	node->data = data;
	node->next = NULL;
}

void insert_afterKey(int data,int key,Node* header){
	Node* node;
	node = (Node*) malloc (sizeof(Node));
	if(node==NULL){
		printf("no available memory\n");
		return;
	}
	Node* ptr = header;
	while(ptr->data!=key && ptr->next!=NULL){
		ptr = ptr->next;
	}
	if(ptr->data!=key)
		printf("key not found \n");
	else{
		node->next = ptr->next;
		ptr->next = node;
		node->data = data;
	}
}

int delete_end(Node* header){
	if(header->next==NULL){
		printf("empty list\n");
		return -1;
	}
	else{
		Node* ptr = header;
		while(ptr->next ->next!=NULL){
			ptr = ptr->next;
		}
		int data = ptr->next->data;
		free(ptr->next);
		ptr->next = NULL;
		return data;
	}
}

int delete_front(Node* header){
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

int delete_atKey(int key,Node* header){
	if(header->next==NULL){
		printf("empty list\n");
		return -1;
	}
	else{
		Node* ptr = header;
		while(ptr->next->data!=key && ptr->next ->next!=NULL){
			ptr = ptr->next;
		}
		if(ptr->next->data != key){
			printf("Key not found\n");
			return 0;
		}
		else{
			Node* ptr1;
			int data = ptr->next->data;
			ptr1 = ptr->next;
			ptr->next = ptr->next->next;
			free(ptr1);
			return data;
		}
	}
}

void operations(Node* header){
	int op=1,data,key;
	printf("-------program starts-------\n");
	while(op != 0){
		printf("input the index number of operatin to perform\n");
		printf("1.INSERT_FRONT\n2.INSERT_END\n3.DELETE_FRONT\n4.DELETE_END\n5.INSERT_ATFERKEY\n6.DELETE_ATKEY\n0.EXIT\n");
		printf("operation index:  ");
		scanf("%d",&op);
		if(op == 1){
			printf("Enter the element to add to front:  ");
			scanf("%d",&data);
			insert_front(data,header);
		}
		else if(op == 2){
			printf("Enter the element to add at end:  ");
			scanf("%d",&data);
			insert_end(data,header);
		}
		else if(op == 3){
			delete_front(header);
		}
		else if(op == 4){
			delete_end(header);
		}
		else if(op == 5){
			printf("enter key: ");
			scanf("%d",&key);
			printf("Enter the element to add at end:  ");
			scanf("%d",&data);
			insert_afterKey(data,key,header);
		}
		else if(op == 6){
			printf("enter key: ");
			scanf("%d",&key);
			delete_atKey(key,header);
		}
		if(op>=1 && op<=6) 
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
