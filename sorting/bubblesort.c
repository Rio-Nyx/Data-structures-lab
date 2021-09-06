
#include <stdio.h>

int swaps,combs;
void bsort(int arr[],int len){	// bubble sort
	int temp;
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
			combs++;
			if(arr[j]>arr[j+1]){	//swapping
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swaps++;
			}
		}
	}
}

int main(){
	int arr[100],n;
	printf("Enter the size of array:  ");
	scanf("%d",&n);
	printf("Enter the elements:  ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bsort(arr,n);
	printf("the sorted array is :  ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("the number of swaps is %d\n",swaps);
	printf("The number of combinations is %d\n",combs);
	return 0;
}
