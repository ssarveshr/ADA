#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int*a,int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void selectionSort(int arr[],int n)
{
    int min_index;
    for (int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        swap(&arr[i],&arr[min_index]);
    }
}

int main()
{
    printf("Enter number of ele to be sorted : ");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
    }
    clock_t t1,t2;
    t1=clock();
    selectionSort(arr,n);
    t2=clock();
    double time_cpy=((double)(t2-t1)/CLOCKS_PER_SEC);
    printf("time take %lf\n",time_cpy);
    
}