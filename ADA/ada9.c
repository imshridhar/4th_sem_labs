//9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}
void plotGraph(int n_values[], double time_taken[], int num_tests) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Error opening gnuplot\n");
        return;
    }
    fprintf(gnuplot,
            "set title 'Time Complexity of Selection Sort'\n"
            "set xlabel 'Number of Elements (n)'\n"
            "set ylabel 'Time Taken (seconds)'\n"
            "plot '-' with linespoints title 'Time vs n'\n");
    for (int i = 0; i < num_tests; i++) {
        fprintf(gnuplot, "%d %lf\n", n_values[i], time_taken[i]);
    }
    fprintf(gnuplot, "e\n");
    pclose(gnuplot); 
}
 int main() {
    srand(time(NULL));
    int n_values[] = {5000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    double time_taken[num_tests]; 

    for (int test = 0; test < num_tests; test++) {
        int n = n_values[test];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        for (int i = 0; i < n; i++) { 
            arr[i] = rand() % 10000;
        }
        
        clock_t start_time = clock();
        selectionSort(arr, n);
        clock_t end_time = clock();
        
        time_taken[test] = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to sort an array of size %d: %f seconds\n", n, time_taken[test]);
        free(arr);
    }

    plotGraph(n_values, time_taken, num_tests);
    return 0;
}