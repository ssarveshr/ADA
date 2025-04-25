#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int*a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot =arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
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

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main()
{
    printf("enter number of ele : ");
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
    }

    clock_t t1,t2;
    double time;
    t1=clock();
    quicksort(arr,0,n-1);
    t2=clock();

    time=((double)(t2-t1))/CLOCKS_PER_SEC;
    printf("%lf",time);
}