
#include <stdio.h>
int swaps,combs;
 // selection sort program
 void slsort(int arr[],int n){
	int pos,min;
 	for(int i=0;i<n;i++){
		min = arr[i];
		pos=i;
		for(int j=i+1;j<n;j++){
			combs++;	// number of  combinations
			if(min>arr[j]){   //swapping
				swaps++;
				min=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[i];
		arr[i]=min;
	}
 }

int main(){
	int arr[100],n;
	printf("Enter the number of elements of array:  ");
	scanf("%d",&n);
	printf("Enter the elements in array:  ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	slsort(arr,n);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
printf("\nnumber of swaps=%d\n",swaps);
printf("Number of combinations=%d\n",combs);
}
