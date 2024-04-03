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

int check(interval intervals[], int N) {
    int i;
    qsort(intervals, N, sizeof(interval), compare);
    for(i = 0; i < N - 1; i++) if(intervals[i].end > intervals[i + 1].start) return 1;
    return 0;
}

int main() {
    int N,i;
    scanf("%d", &N);
    interval* intervals = (interval*)malloc(N * sizeof(interval));
    for(i = 0; i < N; i++) scanf("%d %d", &intervals[i].start, &intervals[i].end);
    if(check(intervals, N)) printf("TRUE");
    else printf("FALSE");
    free(intervals);
}
