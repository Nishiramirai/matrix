#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL)
    return INCORRECT_MATRIX_CODE;
  if (A->rows != A->columns || A->rows <= 0) return CALCULATE_ERROR_CODE;

  int n = A->rows;

  if (n == 1) {
    *result = A->matrix[0][0];
    return OK_CODE;
  }

  if (n == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK_CODE;
  }

  *result = 0;
  matrix_t minor;
  if (s21_create_matrix(n - 1, n - 1, &minor) != OK_CODE)
    return CALCULATE_ERROR_CODE;

  for (int col = 0; col < n; col++) {
    for (int i = 1, mi = 0; i < n; i++, mi++) {
      for (int j = 0, mj = 0; j < n; j++) {
        if (j != col) {
          minor.matrix[mi][mj++] = A->matrix[i][j];
        }
      }
    }

    double minor_det;
    int status = s21_determinant(&minor, &minor_det);
    if (status != OK_CODE) {
      s21_remove_matrix(&minor);
      return status;
    }

    *result += (col % 2 ? -1 : 1) * A->matrix[0][col] * minor_det;
  }

  s21_remove_matrix(&minor);
  return OK_CODE;
}