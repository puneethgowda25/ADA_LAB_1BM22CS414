#include<stdio.h>
#include<time.h>

void swap(int *xp, int *yp)
{
  int temp;
  temp = *xp;
  *xp = *yp;
  *yp = temp;
}
int partition(int arr[],int s,int e){
    int pivot;
    int k=0;
    pivot=arr[s];

    int cnt=0;
    for(k=s+1;k<=e;k++){
        if(pivot>=arr[k]){
            cnt++;
        }
    }

     int pivotIndex;
     pivotIndex=s+cnt;
     swap(&arr[pivotIndex],&arr[s]);

  int i=s;
  int j=e;

  while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }

    if(i<pivotIndex && j>pivotIndex){
        swap(&arr[i++],&arr[j--]);
    }
  }
return pivotIndex;

}
void quicksort(int arr[],int s,int e){

//base case
if(s>=e){
    return;
}
//partition
int p;
p=partition(arr,s,e);

//recursive cases
quicksort(arr,s,p-1);
quicksort(arr,p+1,e);

}
int main(){
     int n; int i=0;
    printf("Enter the no of the elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter the %d th element\n",i+1);
        scanf("%d",&arr[i]);
    }

  int start=clock();
 quicksort(arr,0,n-1);
   int end=clock();
  printf("\nAfter sorting\n");

 for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
 }
double sort_time=(double)(end-start)/CLOCKS_PER_SEC;
 printf("\n sort time is %f s",sort_time);

}
