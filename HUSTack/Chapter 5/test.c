#include <stdio.h>
#include <stdlib.h>

typedef struct interval
{
    int start;
    int end;
} interval;

int compare(const void* a, const void* b) {
    return ((interval*)a)->start - ((interval*)b)->start;
}

void swap(interval* a, interval* b) {
    interval temp = *a;
    *a = *b;
    *b = temp;
}

int partition(interval arr[], int low, int high) {
    int pivot = arr[high].start;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].start < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(interval arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int check(interval intervals[], int N) {
    quicksort(intervals, 0, N - 1);

    for (int i = 0; i < N - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int N, i;
    scanf("%d", &N);
    interval* intervals = (interval*)malloc(N * sizeof(interval));

    for (i = 0; i < N; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    if (check(intervals, N)) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }

    free(intervals);

    return 0;
}
