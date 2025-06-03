#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int main()
{
    int numElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    srand(time(NULL));
    int array[numElements];

    for (int i = 0; i < numElements; i++)
    {
        array[i] = rand() % 10000;
    }

    clock_t startTime, endTime;
    double elapsedTime;

    startTime = clock();
    mergeSort(array, 0, numElements - 1);
    endTime = clock();

    elapsedTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", numElements, elapsedTime);

    return 0;
}