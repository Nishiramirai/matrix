#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK_CODE;
  if ((A == NULL || B == NULL || result == NULL) ||
      (A->matrix == NULL || B->matrix == NULL)) {
    error_code = INCORRECT_MATRIX_CODE;
  } else if (!s21_equal_size_matrix(A, B)) {
    error_code = CALCULATE_ERROR_CODE;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return error_code;
}