#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) {
    return INCORRECT_MATRIX_CODE;
  }
  if (A->rows != A->columns || A->rows < 1) {
    return CALCULATE_ERROR_CODE;
  }

  double det = 0;
  int status = s21_determinant(A, &det);

  if (status != OK_CODE || fabs(det) < 1e-6) {
    return CALCULATE_ERROR_CODE;
  }

  if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
    return OK_CODE;
  }

  matrix_t complements, transposed;
  status = s21_calc_complements(A, &complements);
  if (status == OK_CODE) {
    status = s21_transpose(&complements, &transposed);
    if (status == OK_CODE) {
      status = s21_create_matrix(A->rows, A->columns, result);
      if (status == OK_CODE) {
        double inv_det = 1.0 / det;
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = transposed.matrix[i][j] * inv_det;
          }
        }
      }
      s21_remove_matrix(&transposed);
    }
    s21_remove_matrix(&complements);
  }

  return status;
}