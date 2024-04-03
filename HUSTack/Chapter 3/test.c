#include <stdio.h>

#define MAX_N 1000

int heights[MAX_N];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int stack[MAX_N]; // Ngăn xếp để lưu trữ chỉ số của các cột
    int top = -1; // Đỉnh ngăn xếp

    int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            // Nếu ngăn xếp rỗng hoặc chiều cao của cột hiện tại lớn hơn chiều cao của cột ở đỉnh ngăn xếp
            stack[++top] = i++;
        } else {
            // Nếu chiều cao của cột hiện tại nhỏ hơn chiều cao của cột ở đỉnh ngăn xếp
            int height = heights[stack[top]];
            top--;

            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }
    }

    while (top != -1) {
        // Xử lý các cột còn lại trong ngăn xếp
        int height = heights[stack[top]];
        top--;

        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = height * width;

        maxArea = max(maxArea, area);
    }

    printf("%d\n", maxArea);

    return 0;
}