//10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void plotGraph(int n_values[], double time_taken[], int num_tests) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Error opening gnuplot\n");
        return;
    }
    fprintf(gnuplot,
            "set title 'Time Complexity of QuickSort'\n"
            "set xlabel 'Number of Elements (n)'\n"
            "set ylabel 'Time Taken (seconds)'\n"
            "plot '-' with linespoints title 'Time vs n'\n");
    for (int i = 0; i < num_tests; i++) {
        fprintf(gnuplot, "%d %lf\n", n_values[i], time_taken[i]);
    }
    fprintf(gnuplot, "e\n");
    pclose(gnuplot); // Use pclose for popen
}

int main() {
    srand(time(NULL));
    int n_values[] = {5000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    double time_taken[num_tests]; // VLA (C99 feature)

    for (int test = 0; test < num_tests; test++) {
        int n = n_values[test];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        for (int i = 0; i < n; i++) { // Inlined generateRandomArray
            arr[i] = rand() % 10000;
        }
        
        clock_t start_time = clock();
        quickSort(arr, 0, n - 1);
        clock_t end_time = clock();
        
        time_taken[test] = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, time_taken[test]);
        free(arr);
    }

    plotGraph(n_values, time_taken, num_tests);
    return 0;
}