//1. Write a C Program for Linear Search
#include<stdio.h>
int linear_search(int a[],int key,int n){
	int i;
	for(i=0;i<=n;i++){
		if (a[i]==key)
		return i;
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
	i=linear_search(a,key,n);
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
  Enter the elements you want to search: 66
  66 is not found
*/ 	
