#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char c;
	struct Node *previous;
	struct Node *next;
}Node;

void insert(char,Node*);
int isPalindrome(Node*);

void insert(char c,Node *header){
	if(header==NULL){
		printf("error\n");
	}
	else if(c!='\n'){
		Node *ptr = (Node*)malloc(sizeof(Node));
		ptr->c = c;
		ptr->next = header->next ;
		ptr->previous = NULL;
		ptr->c  = c;
		header->next->previous = ptr;
		header->next = ptr;
	}
}

int isPalindrome(Node *header){
	if(header->next==NULL){
		printf("Empty string\n");
		return -1;
	}
	else{
		Node *ptr1,*ptr2;
		ptr1 = ptr2 = header->next;
		while(ptr2->next!=NULL)
			ptr2 = ptr2->next;
		ptr2 = ptr2->previous;
		while(ptr1!=ptr2){
			if(ptr1->c!=ptr2->c)
				return 0;
			ptr1 = ptr1->next;
			if(ptr1 == ptr2)
				return 1;
			ptr2 = ptr2->previous;
		}
	}
	return 1;
}

int main(){
	Node header;
	int i;
	char s[20];
	printf("Enter the string to check palindrome : ");
	fgets(s,20,stdin);
	i=0;
	while(s[i]!='\0'){
		insert(s[i],&header);
		++i;
	}
	if(isPalindrome(&header)==1)
		printf("it is palindrome\n");
	else if(isPalindrome(&header)==0)
		printf("it is not palindrome \n");
}
