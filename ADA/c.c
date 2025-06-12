// 1 Design and implement C Program to find Minimum Cost Spanning Tree of a given connected
// undirected graph using Kruskal's algorithm.

// 2 Design and implement C Program to find Minimum Cost Spanning Tree of a given connected
// undirected graph using Prim's algorithm. 

// 3 a. Design and implement C Program to solve All-Pairs Shortest Paths problem using Floyd's
// algorithm.

// 3 b. Design and implement C Program to find the transitive closure using Warshal's
// algorithm.

// 4 Design and implement C Program to find shortest paths from a given vertex in a weighted
// connected graph to other vertices using Dijkstra's algorithm.

// 5 Design and implement C Program to obtain the Topological ordering of vertices in a given
// digraph. 

// 6 Design and implement C Program to solve 0/1 Knapsack problem using Dynamic
// Programming method.

// 7 Design and implement C Program to solve discrete Knapsack and continuous Knapsack
// problems using greedy approximation method.

// 8 Design and implement C Program to find a subset of a given set S = {sl , s2,.....,sn} of n
// positive integers whose sum is equal to a given positive integer d.

// 9 Design and implement C Program to sort a given set of n integer elements using Selection
// Sort method and compute its time complexity. Run the program for varied values of n> 5000 and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.

// 10 Design and implement C Program to sort a given set of n integer elements using Quick Sort
// method and compute its time complexity. Run the program for varied values of n> 5000 and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.

// 11 Design and implement C Program to sort a given set of n integer elements using Merge Sort
// method and compute its time complexity. Run the program for varied values of n> 5000, and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.

// 12 Design and implement C Program for N Queen's problem using Backtracking.



//1
#include<stdio.h>
#define INF 999
#define MAX 100
int p[MAX], c[MAX][MAX], t[MAX][2];
int find(int v)
{
    while (p[v])
        v = p[v];
    return v;
}
void union1(int i, int j)
{
    p[j] = i;
}
void kruskal(int n)
{
    int i, j, k, u, v, min, res1, res2, sum = 0;
    for (k = 1; k < n; k++)
    {
        min = INF;
        for (i = 1; i < n - 1; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (c[i][j] < min)
                {
                    u = find(i);
                    v = find(j);
                    if (u != v)
                    {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }
        union1(res1, find(res2));
        t[k][1] = res1;
        t[k][2] = res2;
        sum = sum + min;
    }
    printf("\nCost of spanning tree is=%d", sum);
    printf("\nEdgesof spanning tree are:\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][1], t[i][2]);
}
int main()
{
    int i, j, n;
    printf("\nEnter the n value:");
    scanf("%d", & n);
    for (i = 1; i <= n; i++)
        p[i] = 0;
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", & c[i][j]);
    kruskal(n);
    return 0;
 }


 //2
#include<stdio.h>
#define INF 999
int prim(int c[10][10],int n,int s)
{
    int v[10],i,j,sum=0,ver[10],d[10],min,u;
    for(i=1; i<=n; i++)
    {
        ver[i]=s;
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=1; i<=n-1; i++)
    {
        min=INF;
        for(j=1; j<=n; j++)
            if(v[j]==0 && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        v[u]=1;
        sum=sum+d[u];
        printf("\n%d -> %d sum=%d",ver[u],u,sum);
        for(j=1; j<=n; j++)
            if(v[j]==0 && c[u][j]<d[j])
            {
                d[j]=c[u][j];
                ver[j]=u;
            }
    }
    return sum;
}
void main()
{
    int c[10][10],i,j,res,s,n;
    printf("\nEnter n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&c[i][j]);
    printf("\nEnter the source node:");
    scanf("%d",&s);
    res=prim(c,n,s);
    printf("\nCost=%d",res);
    getchar();
 }


// 3a
#include <stdio.h>
#define INF 999
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void floyd(int p[][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
 void main()
{
    int a[10][10], n, i, j;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    floyd(a, n);
    printf("\nShortest path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
         printf("\n");
    }
     getchar();
 }


 // 3b
#include <stdio.h>
void warsh(int p[][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = p[i][j] || p[i][k] && p[k][j];
}
 int main()
{
    int a[10][10], n, i, j;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    warsh(a, n);
    printf("\nResultant path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
 }


 // 4
#include <stdio.h>
#define INF 999
void dijkstra(int c[10][10], int n, int s, int d[10])
{
    int v[10], min, u, i, j;
    for (i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;
    for (i = 1; i <= n; i++)
    {
        min = INF;
        for (j = 1; j <= n; j++)
            if (v[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        v[u] = 1;
        for (j = 1; j <= n; j++)
            if (v[j] == 0 && (d[u] + c[u][j]) < d[j])
                d[j] = d[u] + c[u][j];
    }
}
 int main()
{
    int c[10][10], d[10], i, j, s, sum, n;
    printf("\nEnter n value:");
    scanf("%d", &n);
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    printf("\nEnter the souce node:");
    scanf("%d", &s);
    dijkstra(c, n, s, d);
    for (i = 1; i <= n; i++)
        printf("\nShortest distance from %d to %d is %d", s, i, d[i]);
    return 0;
 }


 // 5
#include <stdio.h>
int temp[10], k = 0;
void sort(int a[][10], int id[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (id[i] == 0)
        {
            id[i] = -1;
            temp[++k] = i;
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] == 1 && id[j] != -1)
                    id[j]--;
            }
            i = 0;
        }
    }
}
 void main()
{
    int a[10][10], id[10], n, i, j;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        id[i] = 0;
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                id[j]++;
        }
    sort(a, id, n);
    if (k != n)
        printf("\nTopological ordering not possible");
    else
    {
        printf("\nTopological ordering is:");
        for (i = 1; i <= k; i++)
            printf("%d ", temp[i]);
    }
}


// 6
#include <stdio.h>
int w[10], p[10], n;
int max(int a, int b)
{
    return a > b ? a : b;
}
int knap(int i, int m)
{
    if (i == n)
        return w[i] > m ? 0 : p[i];
    if (w[i] > m)
        return knap(i + 1, m);
    return max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]);
}
 int main()
{
    int m, i, max_profit;
    printf("\nEnter the no. of objects:");
    scanf("%d", &n);
    printf("\nEnter the knapsack capacity:");
    scanf("%d", &m);
    printf("\nEnter profit followed by weight:\n");
    for (i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]);
    max_profit = knap(1, m);
    printf("\nMax profit=%d", max_profit);
    return 0;
 }


 // 7
 #include <stdio.h>
 #define MAX 50
 int p[MAX], w[MAX], x[MAX];
 double maxprofit;
 int n, m, i;
void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX];
    for (i = 0; i < n; i++){
        ratio[i] = (double)p[i] / w[i];
    }
    for (i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (ratio[i] < ratio[j]){
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }
    int currentWeight = 0;
    maxprofit = 0.0;
    for (i = 0; i < n; i++){
        if (currentWeight + w[i] <= m){
            x[i] = 1;
            currentWeight += w[i];
            maxprofit += p[i];
        }
        else{
            x[i] = (m - currentWeight) / (double)w[i];
            maxprofit += x[i] * p[i];
            break;
        }
    }
    printf("Optimal solution for greedy method: %.1f\n", maxprofit);
    printf("Solution vector for greedy method: ");
    for (i = 0; i < n; i++)
        printf("%d\t", x[i]);
}
int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the objects' weights: ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the objects' profits: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    greedyKnapsack(n, w, p, m);
    return 0;
}


// 8
#include <stdio.h>
#define MAX 10
int s[MAX], x[MAX], d;
void sumofsub(int p, int k, int r)
{
    int i;
    x[k] = 1;
    if ((p + s[k]) == d)
    {
        for (i = 1; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("\n");
    }
    else if (p + s[k] + s[k + 1] <= d)
        sumofsub(p + s[k], k + 1, r - s[k]);
    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d))
    {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}
 int main()
{
    int i, n, sum = 0;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the set in increasing order:");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    printf("\nEnter the max subset value:");
    scanf("%d", &d);
    for (i = 1; i <= n; i++)
        sum = sum + s[i];
    if (sum < d || s[1] > d)
        printf("\nNo subset possible");
    else
        sumofsub(0, 1, sum);
    return 0;
}

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
        quickSort(arr, 0, n - 1);
        clock_t end_time = clock();
        
        time_taken[test] = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, time_taken[test]);
        free(arr);
    }
    plotGraph(n_values, time_taken, num_tests);
    return 0;
}


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


//12
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