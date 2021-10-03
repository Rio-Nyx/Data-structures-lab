#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int coef;
	int exp;
	struct Node* next;
}Node;

void display(Node* );
void operations(Node*,Node*);
void freeList(Node*);
void insert_end(int,int,Node* );
void read_poly(Node*);
Node* sum(Node*,Node*);
int search(int,int, Node*);
Node* product(Node*,Node*);

Node* sum(Node *header1,Node *header2){
	Node *header3;
	header3 = (Node*)malloc(sizeof(Node));
	Node *ptr1 = header1->next;
	Node *ptr2 = header2->next;
	while(ptr1!=NULL || ptr2!=NULL){
		if(ptr1==NULL){
			insert_end(ptr2->coef,ptr2->exp,header3);
			ptr2 = ptr2->next;
		}
		else if(ptr2==NULL){
			insert_end(ptr1->coef,ptr1->exp,header3);
			ptr1 = ptr1->next;
		}
		else if(ptr1->exp==ptr2->exp){
			insert_end(ptr1->coef+ptr2->coef,ptr1->exp,header3);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1->exp>ptr2->exp){
			insert_end(ptr1->coef,ptr1->exp,header3);
			ptr1 = ptr1->next;
		}
		else{
			insert_end(ptr2->coef,ptr2->exp,header3);
			ptr2 = ptr2->next;
		}
	}
	return header3;
}

Node* product(Node *header1,Node *header2){
	int coef,exp;
	Node *ptr1,*ptr2,*header3;
	ptr1 = header1->next;
	ptr2 = header2->next;
	if(header1->next==NULL || header2->next==NULL){
		printf("product will be zero since one polynomial is empty\n");
		return;
	}
	header3 = (Node*)malloc(sizeof(Node));
	while(ptr1!=NULL){
		ptr2 = header2->next;
		while(ptr2!=NULL){
			exp = ptr1->exp + ptr2->exp;
			coef = ptr1->coef * ptr2->coef ;
			if(search(exp,coef,header3)!=1){
	/*			insert to header3 */
				insert_end(coef,exp,header3);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return header3;
}

void freeList(Node* header){
	header = header->next;
	while(header!=NULL){
		Node* ptr = header;
		header = header->next ;
		free(ptr);
	}
}

int search(int exp,int coef,Node *header){
	Node *ptr = header;
	if(ptr==NULL)
		printf("empty list\n");
	else{
		ptr = ptr->next;
		while(ptr!=NULL){
			if(ptr->exp == exp){
				ptr->coef +=coef;
				return 1;
			}
			ptr = ptr->next;
		}
		return 0;
	}
}

void operations(Node* header1,Node *header2){
	int op=1;
	Node *header5;
	printf("-------program starts-------\n");

	printf("first polynomial:\n");
	read_poly(header1);
	printf("second polynomial:\n");
	read_poly(header2);

	header5 = sum(header1,header2);
	printf("sum of ");
	display(header1);
	printf("  AND  ");
	display(header2);
	printf("  IS  ");
	display(header5);
	printf("\n");

	header5 = product(header1,header2);
	printf("product of ");
	display(header1);
	printf("  AND  ");
	display(header2);
	printf("  IS  ");
	display(header5);
	printf("\n");

	freeList(header5);
	freeList(header1);
	freeList(header2);
}

void read_poly(Node* header){
	int n,i=0;
	int coef,exp;
	printf("enter the number of terms in the polyomial:  ");
	scanf("%d",&n);
	Node *ptr;
	printf("enter the coeff and exp of polynomial\n");
	while(i<n){
		scanf("%d%d",&coef,&exp);
		insert_end(coef,exp,header);
		i++;
	}
}

void insert_end(int coef,int exp, Node* header){
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
	node->next = NULL;
	node->coef = coef;
	node->exp = exp;
}

void display(Node* header){
	if(header->next==NULL)
		printf("empty list\n");
	else{
		Node* ptr ;
		ptr = header->next;
		while(ptr!=NULL){
			printf(" %dx^%d + ",ptr->coef,ptr->exp);
			ptr = ptr->next;
		}
/*		printf("\n");*/
		free(ptr);
	}
}

void main(){
	Node header1;
	header1.coef= -5;
	header1.next = NULL;
	Node header2;
	header2.coef = -5;
	header2.next = NULL;
	operations(&header1,&header2);
}
