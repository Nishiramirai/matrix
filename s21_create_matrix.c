#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL) {
    return INCORRECT_MATRIX_CODE;
  }

  if (rows < 1 || columns < 1) {
    return CALCULATE_ERROR_CODE;
  }

  int error_code = OK_CODE;
  result->matrix = calloc(rows, sizeof(double *));
  result->rows = 0;
  result->columns = 0;

  if (result->matrix != NULL) {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows && !error_code; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        s21_remove_matrix(result);
        error_code = CALCULATE_ERROR_CODE;
      }
    }
  } else {
    error_code = CALCULATE_ERROR_CODE;
  }

  return error_code;
}