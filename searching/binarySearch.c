//binary search
#include <stdio.h>

int main(){
	int first,last,middle,search,n,comps,arr[50];
	comps=0;
	printf("Enter the number of elements in array:  ");
	scanf("%d",&n);
	printf("Enter the elements in array:  ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the search term:  ");
	scanf("%d",&search);
	first=0;last=n;
	while(first<last){
		comps++;
		middle = ( first + last	) / 2 ;
		if ( arr[middle] > search )
			last = middle ; 
		else if ( arr[middle] < search)
			first = middle + 1 ;
		else{
			printf("%d is found at %d index\n",search,middle);
			return 0;
		}
	}
	printf("%d is not found in array\n",search);
	printf("The number of comparisons is %d\n",comps);
	return 0;
}
