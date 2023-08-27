#include <stdio.h>
#include <time.h>
#define SIZE 20

void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}
void heapify(int arr[], int N, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < N && arr[left] > arr[largest])

largest = left;
if (right < N && arr[right] > arr[largest])

largest = right;
if (largest != i) {
swap(&arr[i], &arr[largest]);
heapify(arr, N, largest);
}
}

void heapSort(int arr[], int N)
{
for (int i = N / 2 - 1; i >= 0; i--)
heapify(arr, N, i);
for (int i = N - 1; i >= 0; i--)
    {
swap(&arr[0], &arr[i]);
heapify(arr, i, 0);
}
}

void printArray(int arr[], int N)
{
for (int i = 0; i < N; i++)
printf("%d ", arr[i]);
printf("\n\n");
}


int main()
{
int arr[SIZE];
int n;
clock_t start,end;
double time_taken;
    printf("ENTER THE SIZE OF THE ARRAY: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    printf("THE GIVEN ARRAY IS:\n");
    printArray(arr,n);
    start=clock();
heapSort(arr, n);
end=clock();
printf("SORTED ARRAY IS\n");
printArray(arr, n);
time_taken=(double)(end-start);
time_taken=(time_taken/CLOCKS_PER_SEC);
printf("THE TIME TAKEN TO SORT AN ARRAY OF SIZE %d is: %f seconds",n,time_taken);
}
