#include <stdio.h>

#define ROW_X 10
#define COL_X 8
#define ROW_Y 10
#define COL_Y 12

void processMatrix(int rows, int cols, int matrix[rows][cols], int A, int B, int *count, long long *product) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] >= A && matrix[i][j] <= B) {
                (*count)++;
                (*product) *= matrix[i][j];
            }
        }
    }
}

int main() {
    int x[ROW_X][COL_X], y[ROW_Y][COL_Y];
    int A, B;
    int count = 0;
    long long product = 1;

    printf("Enter elements of matrix x (10x8):\n");
    for (int i = 0; i < ROW_X; i++)
        for (int j = 0; j < COL_X; j++)
            scanf("%d", &x[i][j]);

    printf("Enter elements of matrix y (10x12):\n");
    for (int i = 0; i < ROW_Y; i++)
        for (int j = 0; j < COL_Y; j++)
            scanf("%d", &y[i][j]);

    printf("Enter A and B (interval boundaries): ");
    scanf("%d %d", &A, &B);

    processMatrix(ROW_X, COL_X, x, A, B, &count, &product);
    processMatrix(ROW_Y, COL_Y, y, A, B, &count, &product);

    if (count > 0)
        printf("Count = %d, Product = %lld\n", count, product);
    else
        printf("No elements found in the interval [%d, %d]\n", A, B);

    return 0;
}
