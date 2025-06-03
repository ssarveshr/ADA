#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void swap(int *a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int arr[],int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        swap(&arr[min_idx],&arr[i]);
    }
}

int main()
{
    int n;
    printf("enter no of elemets to sort : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand()%10000;
    
    srand(time(0));
    clock_t start,end;;
    double cpu_time;
    start=clock();
    SelectionSort(arr,n);
    end=clock();

    cpu_time=(double)(end-start)/CLOCKS_PER_SEC;

    printf("time taken to sort %d elements is %f\n",n,cpu_time);

}