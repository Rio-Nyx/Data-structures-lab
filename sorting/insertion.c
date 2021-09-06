// insertion sort

#include <stdio.h>

void main(){
	int temp,n,i,j,arr[50],swaps,comps=0;
	printf("Enter the number of elements in array:  ");
	scanf("%d",&n);
	printf("Enter the array elements:  ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0){
			comps++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printf("The sorted array is:  ");
	for(int i=0;i<n;i++)
		printf(" %d ",arr[i]);
	printf("\nnumber of swaps and comparisons is %d\n",comps);
}
