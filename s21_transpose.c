#include <stdio.h>

#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL) {
    return INCORRECT_MATRIX_CODE;
  }

  if (A->columns < 0 || A->rows < 0) {
    return CALCULATE_ERROR_CODE;
  }

  int rows = A->columns;
  int cols = A->rows;
  int error_code = s21_create_matrix(rows, cols, result);
  if (error_code == OK_CODE) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return error_code;
}