#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = OK_CODE;
  if ((A == NULL || B == NULL || result == NULL) ||
      (A->matrix == NULL || B->matrix == NULL)) {
    error_code = INCORRECT_MATRIX_CODE;
  } else if (A->columns != B->rows) {
    error_code = CALCULATE_ERROR_CODE;
  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int row = 0; row < A->rows; row++) {
      for (int col = 0; col < B->columns; col++) {
        for (int n = 0; n < B->rows; n++) {
          result->matrix[row][col] += A->matrix[row][n] * B->matrix[n][col];
        }
      }
    }
  }

  return error_code;
}