#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int array[],int left,int mid,int right)
{
    int i,j,k;
    int left_size=mid-left+1;
    int right_size=right-mid;

    int left_arr[left_size],right_arr[right_size];

    for(i=0;i<left_size;i++)
        left_arr[i]=array[left+i];

    for(j=0;j<right_size;j++)
        right_arr[j]=array[mid+j+1];

    i=0;
    j=0;
    k=left;

    while(i<left_size && j<right_size)
    {
        if(left_arr[i]<=right_arr[j])
        {
            array[k]=left_arr[i];
            i++;
        }
        else
        {
            array[k]=right_arr[j];
            j++;
        }
        k++;
    }

    while(i<left_size)
    {
        array[k]=left_arr[i];
        i++;
        k++;
    }
    while(j<right_size)
    {
        array[k]=right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int array[],int left,int right)
{
    if(left<right)
    {
        int mid= left + (right-left)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid+1,right);

        merge(array,left,mid,right);
    }
}


int main()
{
    srand(time(0));
    printf("enter no of ele to sort : ");
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand() % 10000;

    clock_t start,end;
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();

    double cpu_time=(double)(end-start)/CLOCKS_PER_SEC;

    printf("time taken to sort %d ele is %f",n,cpu_time);
    
    

}