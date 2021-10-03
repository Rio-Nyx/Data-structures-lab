//linear search

#include <stdio.h>
void main(){
	int search,flag,comps,i,n,arr[50];
	printf("Enter the number of elements in array:  ");
	scanf("%d",&n);
	printf("Enter the array elements:  ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the search term:  ");
	scanf("%d",&search);
	printf("searching for the element..........\n");
	for(i=0;i<n;i++){
		comps++;
		if(arr[i]==search){
			flag=1;
			break;
		}
	}
	if(flag)
		printf("%d found at index %d\n",search,i);
	else
		printf("%d was not found in the array\n",search);
	printf("%d is the number of comparisons\n",comps);
}
