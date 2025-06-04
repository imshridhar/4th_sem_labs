//11
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2]; 

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    while (i < n1)  
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
}
 void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 void plotGraph(int n_values[], double time_taken[], int num_tests) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Error opening gnuplot\n");
        return;
    }
    fprintf(gnuplot,
            "set title 'Time Complexity of Merge Sort'\n"
            "set xlabel 'Number of Elements (n)'\n"
            "set ylabel 'Time Taken (seconds)'\n"
            "plot '-' with linespoints title 'Time vs n'\n");
    for (int i = 0; i < num_tests; i++) {
        fprintf(gnuplot, "%d %lf\n", n_values[i], time_taken[i]);
    }
    fprintf(gnuplot, "e\n");
    fclose(gnuplot);
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
        mergeSort(arr, 0, n - 1);
        clock_t end_time = clock();
        time_taken[test] = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, time_taken[test]);
        free(arr);
    }
    plotGraph(n_values, time_taken, num_tests);
    return 0;
}