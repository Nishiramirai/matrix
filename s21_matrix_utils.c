#include "s21_matrix.h"

int s21_equal_size_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if ((A == NULL || B == NULL) || (A->rows != B->rows) ||
      (A->columns != B->columns)) {
    result_code = FAILURE;
  }
  return result_code;
}

void s21_get_minor(matrix_t *A, matrix_t *minor, int skip_row, int skip_col) {
  if (A == NULL || minor == NULL || A->rows <= 0 || A->columns <= 0 ||
      minor->rows != A->rows - 1 || minor->columns != A->columns - 1 ||
      skip_row < 0 || skip_row >= A->rows || skip_col < 0 ||
      skip_col >= A->columns) {
    return;
  }

  int minor_i = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i != skip_row) {
      int minor_j = 0;

      for (int j = 0; j < A->columns; j++) {
        if (j != skip_col) {
          minor->matrix[minor_i][minor_j] = A->matrix[i][j];
          minor_j++;
        }
      }
      minor_i++;
    }
  }
}
