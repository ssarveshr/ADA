#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=high;
    int i=low-1;

    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main()
{
    int n;
    printf("enter no of elemts to sort : ");
    scanf("%d",&n);
    int arr[n];
    //srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]=rand()%10000;
    
    clock_t start,end;
    start=clock();
    quickSort(arr,0,n-1);
    end=clock();

    double cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time to sort %d ele is %f",n,cpu_time);
}