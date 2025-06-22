#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error_code = SUCCESS;
  if (s21_equal_size_matrix(A, B)) {
    for (int i = 0; i < A->rows && error_code; i++) {
      for (int j = 0; j < B->columns && error_code; j++) {
        error_code = fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-07;
      }
    }
  } else {
    error_code = FAILURE;
  }
  return error_code;
}