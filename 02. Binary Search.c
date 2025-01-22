//2. Write a C Program for Binary Search
#include<stdio.h>
int binary_search(int a[],int key,int n){
	int mid,low=0,high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(key>a[mid])
		low=mid+1;
		else if(key<a[mid])
		high=mid-1;
		else
		return mid;
	}
	return -1;
}
int main(){
	int a[10],n,i,key;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the elements you want to search: ");
	scanf("%d",&key);
	i=binary_search(a,key,n);
	if(i==-1)
	printf("%d is not found",key);
	else
	printf("%d is found at %d position",key,i+1);
	return 0;
}
/*Output:
  Enter the number of elements: 5
  Enter the elements:
  11
  22
  33
  44
  55
  Enter the elements you want to search: 22
  22 is found at 2 position
*/
