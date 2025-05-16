#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[20], count;

// Function declarations
void queen(int row, int n);
int place(int row, int column);
void print(int n);

int main() {
    int n;

    printf(" - N Queens Problem Using Backtracking -\n\n");
    printf("Enter number of Queens: ");
    scanf("%d", &n);

    queen(1, n); // Start solving from row 1

    return 0;
}

// Function to check for proper positioning of queen using backtracking
void queen(int row, int n) {
    int column;

    for (column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column; // Place queen if no conflict
            if (row == n) {
                print(n); // Found a valid solution
            } else {
                queen(row + 1, n); // Recurse for next row
            }
        }
    }
}

// Function to check conflicts
// Returns 1 if no conflict, else 0
int place(int row, int column) {
    int i;

    for (i = 1; i <= row - 1; ++i) {
        if (board[i] == column || abs(board[i] - column) == abs(i - row)) {
            return 0; // Conflict found
        }
    }

    return 1; // No conflict
}

// Function for printing the solution
void print(int n) {
    int i, j;

    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i) {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j) {
            if (board[i] == j)
                printf("\tQ"); // Queen at position (i,j)
            else
                printf("\t-"); // Empty slot
        }
    }
    printf("\n");
}

