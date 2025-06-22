#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = OK_CODE;
  if (A == NULL || A->matrix == NULL || result == NULL) {
    error_code = INCORRECT_MATRIX_CODE;
  } else if (A->rows < 1 || A->columns < 1) {
    error_code = CALCULATE_ERROR_CODE;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return error_code;
}