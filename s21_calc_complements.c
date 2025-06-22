#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX_CODE;
  if (A->rows != A->columns || A->rows < 1) return CALCULATE_ERROR_CODE;

  int status = OK_CODE;
  int size = A->rows;
  matrix_t minor = {0};
  int need_cleanup = 0;

  if (s21_create_matrix(size, size, result) == OK_CODE) {
    if (size == 1) {
      result->matrix[0][0] = 1.0;
    } else if (s21_create_matrix(size - 1, size - 1, &minor) == OK_CODE) {
      need_cleanup = 1;

      for (int i = 0; i < size && status == OK_CODE; i++) {
        for (int j = 0; j < size && status == OK_CODE; j++) {
          s21_get_minor(A, &minor, i, j);
          double det = 0;
          status = s21_determinant(&minor, &det);
          if (status == OK_CODE) {
            result->matrix[i][j] = ((i + j) % 2 ? -det : det);
          }
        }
      }
    } else {
      status = CALCULATE_ERROR_CODE;
    }

    if (status != OK_CODE && need_cleanup) {
      s21_remove_matrix(&minor);
    }
    if (status != OK_CODE) {
      s21_remove_matrix(result);
    }
  } else {
    status = CALCULATE_ERROR_CODE;
  }

  if (need_cleanup && status == OK_CODE) {
    s21_remove_matrix(&minor);
  }
  return status;
}