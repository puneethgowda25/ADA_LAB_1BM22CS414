#include<stdio.h>

void merge(int arr[],int low,int high){
    int k,s,i, mid,leng1,leng2, mainarrayindex, index1, index2;
    mid=(low+high)/2;



    leng1=mid-low+1;
    leng2=high-mid;

    int  first[leng1];
    int second[leng2];

     mainarrayindex=low;
    for( i=0;i<leng1;i++){
        first[i]=arr[mainarrayindex++];
    }

     mainarrayindex=mid+1;
     for(i=0;i<leng2;i++){
        second[i]=arr[mainarrayindex++];
    }

    //merge sorted arrays

     index1=0;
     index2=0;
     mainarrayindex=low;


    while(index1<leng1 && index2<leng2){
        if(first[index1]< second[index2]){
            arr[mainarrayindex++]=first[index1++];
        }
        else{
             arr[mainarrayindex++]=second[index2++];
        }
    }

   while(index1<leng1){
    arr[mainarrayindex++]=first[index1++];
   }

  while(index2<leng2){
    arr[mainarrayindex++]=second[index2++];
   }

}







void mergeSort(int arr[],int low,int high){
     int mid;
    if(low>=high){
        return;
    }
    mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,high);

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


    mergeSort(arr,0,n-1);
 printf("\nAfter sorting\n");
 for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
 }

}
