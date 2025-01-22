//5. Write a C Program for Selection Sort.
#include<stdio.h>
void selection_sort(int a[],int n){
    int i,j,min,p,temp;
    for(i=0;i<n-1;i++){
        min=a[i];
        p=i;
        for(j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                p=j;
            }
        }
        if(p!=i){
            temp=a[i];
            a[i]=a[p];
            a[p]=temp;
        }
    }
}
int main(){
    int a[20],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    printf("Sorted array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
/*Output:
  Enter the number of elements: 5
  Enter 5 elements:
  25
  14
  49
  32
  63
  Sorted array:
  14 25 32 49 63 
*/
