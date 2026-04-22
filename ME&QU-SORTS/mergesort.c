#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = temp[k];
    }
}
void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main() {
    int n, i;
    clock_t start, end;
    double time_taken;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        a[i] = rand() % n;
    }
    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken: %f seconds\n", time_taken);
    return 0;
}
