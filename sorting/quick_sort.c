#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[20];
    float height;
    float weight;
}people;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int p, int r){
    int x,i,j;
    x = a[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}

void quick_sort(int a[], int p, int r){
    int q;
    if(p<r){
        q = partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

void display_arr(int a[],int size){
    for(int i=0;i<size;i++)
        printf(" %d ",a[i]);
}

void input_details(people *p ){
    printf("Enter the nane : ");
    fgets(p.name,20,stdin);
    printf("Enter the height: ");
    scanf("%f",p.height);
    printf("Enter the weight: ");
    scanf("%f",p.weight);
}

void main(){
    printf("program starts\n");
    int size;
    printf("enter the size of array: ");
    scanf("%d",&size);
    int a[size];
    input_arr(a,size);
    quick_sort(a,0,size-1);
    display_arr(a,size);
}
