// Design C/C++ programm for N Queen Problem  using backtracking method

#include <stdio.h>

#include <stdlib.h>

#define MAX 50

int can_place(int c[], int r) {

    for (int i = 0; i < r; i++) {

        if (c[i] == c[r] || abs(c[i] - c[r]) == abs(i - r))

            return 0;

    }

    return 1;

}

void display(int c[], int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (c[i] == j)

                printf("Q ");

            else

                printf("- ");

        }

        printf("\n");

    }

    printf("\n\n");

}

void n_queens(int n) {

    int r = 0;

    int c[MAX];

    c[0] = -1;

    while (r >= 0) {

        c[r]++;

        while (c[r] < n && !can_place(c, r))

            c[r]++;

        if (c[r] < n) {

            if (r == n - 1) {

                display(c, n);

            } else {

                r++;

                c[r] = -1;

            }

        } else {

            r--;

        }

    }

}

int main() {

    int n;

    printf("Enter the number of queens (max %d): ", MAX);

    scanf("%d", &n);

    if (n <= 0 || n > MAX) {

        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);

        return 1;

    }

    n_queens(n);

    return 0;

}

