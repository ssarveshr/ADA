#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n, int order) {
    int i, j, temp, min_or_max_index;

    for (i = 0; i < n - 1; i++) {
        min_or_max_index = i;

        
        for (j = i + 1; j < n; j++) {
            if ((order == 1 && arr[j] < arr[min_or_max_index]) ||
                (order == 2 && arr[j] > arr[min_or_max_index])) { 
                min_or_max_index = j;
            }
        }

        
        if (min_or_max_index != i) {
            temp = arr[min_or_max_index];
            arr[min_or_max_index] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randomizeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }
}

int main() {
    int n, order;
    srand(time(0));
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    
    randomizeArray(arr, n);
    
    printf("Original Array: ");
    //printArray(arr, n);
    clock_t start,end;
    double cpu_time_used;
    start=clock();

    printf("\nChoose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. Random (shuffling the array)\n");
    printf("Enter your choice: ");
    scanf("%d", &order);

    switch (order) {
        case 1:
            selectionSort(arr, n, 1);
            printf("\nArray sorted in Ascending order: ");
            break;
        case 2:
            selectionSort(arr, n, 2);
            printf("\nArray sorted in Descending order: ");
            break;
        case 3:
            randomizeArray(arr, n);
            printf("\nArray shuffled randomly: ");
            break;
        default:
            printf("Invalid choice! Exiting.\n");
            return 0;
    }
    end=clock();
    printf("sorted array");
    	printArray(arr, n);
    	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    	printf("Time taken to sort %d elements %f seconds\n",n,cpu_time_used);

    
    return 0;
}




























