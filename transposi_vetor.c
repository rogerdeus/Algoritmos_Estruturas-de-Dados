#include <stdio.h>

int main() {
    int matr_origi[2][3];
    int vetor_transp[3][2];

    // Read the original matrix
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matr_origi[%d][%d] = ", i, j);  // fixed: both indices
            scanf("%d", &matr_origi[i][j]);
        }
    }

    // Transpose: rows become columns
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            vetor_transp[j][i] = matr_origi[i][j];
        }
    }

    // Print original matrix
    printf("\nmatr_origi\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matr_origi[i][j]);
        }
        printf("\n");
    }

    // Print transposed matrix (3 rows × 2 columns)
    printf("\nvetor_transp\n");
    for (int i = 0; i < 3; i++) {          // 3 rows
        for (int j = 0; j < 2; j++) {      // 2 columns
            printf("%d\t", vetor_transp[i][j]);
        }
        printf("\n");
    }

    return 0;
}