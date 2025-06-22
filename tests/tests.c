#include <check.h>

#include "../s21_matrix.h"

// Передача NULL вместо указателя на матрицу
START_TEST(test_s21_create_matrix1) {
  int result_code = s21_create_matrix(2, 2, NULL);
  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
}
END_TEST

// Размер матрицы меньше 1
START_TEST(test_s21_create_matrix2) {
  matrix_t mat;
  int result_code = s21_create_matrix(0, 0, &mat);
  ck_assert_int_eq(result_code, CALCULATE_ERROR_CODE);
}
END_TEST

// Успешное создание матрицы с корректными данными
START_TEST(test_s21_create_matrix3) {
  matrix_t mat;
  int result_code = s21_create_matrix(2, 2, &mat);
  ck_assert_int_eq(result_code, OK_CODE);
  ck_assert_int_eq(mat.rows, 2);
  ck_assert_int_eq(mat.columns, 2);
  s21_remove_matrix(&mat);
}
END_TEST

// Успешное сравнение двух одниковых матриц
START_TEST(test_s21_eq_matrix1) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 3;
  matrix2.matrix[1][1] = 4;

  int result_code = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result_code, SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

// Cравнение двух матриц с разными значениями
START_TEST(test_s21_eq_matrix2) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 4;
  matrix2.matrix[0][1] = 3;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 1;

  int result_code = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

// Cравнение двух матриц с разными размерами
START_TEST(test_s21_eq_matrix3) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[0][2] = 3;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = 5;
  matrix2.matrix[1][2] = 6;
  matrix2.matrix[2][0] = 7;
  matrix2.matrix[2][1] = 8;
  matrix2.matrix[2][2] = 9;

  int result_code = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_sum_matrix1) {
  int result = s21_sum_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(result, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_sum_matrix2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[0][2] = 3;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = 5;
  matrix2.matrix[1][2] = 6;
  matrix2.matrix[2][0] = 7;
  matrix2.matrix[2][1] = 8;
  matrix2.matrix[2][2] = 9;

  int result_code = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(result_code, CALCULATE_ERROR_CODE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_sum_matrix3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 3;
  matrix2.matrix[1][1] = 4;

  int result_code = s21_sum_matrix(&matrix1, &matrix2, &result);

  ck_assert_int_eq(result_code, OK_CODE);

  ck_assert_int_eq(result.matrix[0][0], 2);
  ck_assert_int_eq(result.matrix[0][1], 4);
  ck_assert_int_eq(result.matrix[1][0], 6);
  ck_assert_int_eq(result.matrix[1][1], 8);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix1) {
  int result_code = s21_sub_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_sub_matrix2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[0][2] = 3;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = 5;
  matrix2.matrix[1][2] = 6;
  matrix2.matrix[2][0] = 7;
  matrix2.matrix[2][1] = 8;
  matrix2.matrix[2][2] = 9;

  int result_code = s21_sub_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(result_code, CALCULATE_ERROR_CODE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_sub_matrix3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 3;
  matrix2.matrix[1][1] = 4;

  int result_code = s21_sub_matrix(&matrix1, &matrix2, &result);

  ck_assert_int_eq(result_code, OK_CODE);

  ck_assert_int_eq(result.matrix[0][0], 0);
  ck_assert_int_eq(result.matrix[0][1], 0);
  ck_assert_int_eq(result.matrix[1][0], 0);
  ck_assert_int_eq(result.matrix[1][1], 0);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

// NULL вместо матрицы
START_TEST(test_s21_mult_number1) {
  matrix_t result;
  int result_code = s21_mult_number(NULL, 2, &result);
  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
}
END_TEST

// NULL вместо указателя на матрицу куда будет записан результат
START_TEST(test_s21_mult_number2) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 1;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 1;

  int result_code = s21_mult_number(&matrix, 2, NULL);

  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_mult_number3) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;

  int result_code = s21_mult_number(&matrix, 2, &result);

  ck_assert_int_eq(result_code, OK_CODE);

  ck_assert_int_eq(result.matrix[0][0], 2);
  ck_assert_int_eq(result.matrix[0][1], 4);
  ck_assert_int_eq(result.matrix[1][0], 6);
  ck_assert_int_eq(result.matrix[1][1], 8);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix1) {
  int result_code = s21_mult_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_mult_matrix2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[0][2] = 3;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = 5;
  matrix2.matrix[1][2] = 6;
  matrix2.matrix[2][0] = 7;
  matrix2.matrix[2][1] = 8;
  matrix2.matrix[2][2] = 9;

  int result_code = s21_mult_matrix(&matrix1, &matrix2, &result);

  ck_assert_int_eq(result_code, CALCULATE_ERROR_CODE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_mult_matrix3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[1][0] = 3;
  matrix1.matrix[1][1] = 4;

  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 2;
  matrix2.matrix[1][0] = 3;
  matrix2.matrix[1][1] = 4;

  int result_code = s21_mult_matrix(&matrix1, &matrix2, &result);

  ck_assert_int_eq(result_code, OK_CODE);
  ck_assert_int_eq(result.matrix[0][0], 7);
  ck_assert_int_eq(result.matrix[0][1], 10);
  ck_assert_int_eq(result.matrix[1][0], 15);
  ck_assert_int_eq(result.matrix[1][1], 22);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose1) {
  int result_code = s21_transpose(NULL, NULL);
  ck_assert_int_eq(result_code, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_transpose2) {
  matrix_t mat;
  matrix_t res;

  s21_create_matrix(2, 2, &mat);
  mat.matrix[0][0] = 1;
  mat.matrix[0][1] = 2;
  mat.matrix[1][0] = 3;
  mat.matrix[1][1] = 4;

  int result_code = s21_transpose(&mat, &res);

  ck_assert_int_eq(result_code, OK_CODE);

  ck_assert_int_eq(res.matrix[0][0], 1);
  ck_assert_int_eq(res.matrix[0][1], 3);
  ck_assert_int_eq(res.matrix[1][0], 2);
  ck_assert_int_eq(res.matrix[1][1], 4);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_s21_transpose3) {
  matrix_t mat;
  matrix_t res;

  s21_create_matrix(3, 2, &mat);

  mat.matrix[0][0] = 1;
  mat.matrix[0][1] = 2;

  mat.matrix[1][0] = 3;
  mat.matrix[1][1] = 4;

  mat.matrix[2][0] = 5;
  mat.matrix[2][1] = 6;

  int result_code = s21_transpose(&mat, &res);

  ck_assert_int_eq(result_code, OK_CODE);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 3);

  ck_assert_int_eq(res.matrix[0][0], 1);
  ck_assert_int_eq(res.matrix[0][1], 3);
  ck_assert_int_eq(res.matrix[0][2], 5);

  ck_assert_int_eq(res.matrix[1][0], 2);
  ck_assert_int_eq(res.matrix[1][1], 4);
  ck_assert_int_eq(res.matrix[1][2], 6);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_s21_calc_complements1) {
  matrix_t result;
  int code = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_calc_complements2) {
  matrix_t mat, result;
  s21_create_matrix(2, 3, &mat);

  int code = s21_calc_complements(&mat, &result);
  ck_assert_int_eq(code, CALCULATE_ERROR_CODE);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_calc_complements3) {
  matrix_t mat, result;
  s21_create_matrix(1, 1, &mat);
  mat.matrix[0][0] = 5.0;

  int code = s21_calc_complements(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);
  ck_assert_double_eq(result.matrix[0][0], 1.0);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements4) {
  matrix_t mat, result;
  s21_create_matrix(2, 2, &mat);
  double values[2][2] = {{1.0, 2.0}, {3.0, 4.0}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  int code = s21_calc_complements(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);

  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], -3.0);
  ck_assert_double_eq(result.matrix[1][0], -2.0);
  ck_assert_double_eq(result.matrix[1][1], 1.0);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements5) {
  matrix_t mat, result;
  s21_create_matrix(3, 3, &mat);
  double values[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {5.0, 2.0, 1.0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  int code = s21_calc_complements(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);

  ck_assert_double_eq_tol(result.matrix[0][0], 0.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -14.0, 1e-6);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_determinant1) {
  double result;
  int code = s21_determinant(NULL, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_determinant2) {
  matrix_t mat;
  double result;
  s21_create_matrix(2, 3, &mat);

  int code = s21_determinant(&mat, &result);
  ck_assert_int_eq(code, CALCULATE_ERROR_CODE);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant3) {
  matrix_t mat;
  double result;
  s21_create_matrix(1, 1, &mat);
  mat.matrix[0][0] = 42.0;

  int code = s21_determinant(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);
  ck_assert_double_eq(result, 42.0);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant4) {
  matrix_t mat;
  double result;
  s21_create_matrix(2, 2, &mat);
  mat.matrix[0][0] = 1.0;
  mat.matrix[0][1] = 2.0;
  mat.matrix[1][0] = 3.0;
  mat.matrix[1][1] = 4.0;

  int code = s21_determinant(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);
  ck_assert_double_eq(result, -2.0);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant5) {
  matrix_t mat;
  double result;
  s21_create_matrix(3, 3, &mat);
  double values[3][3] = {{2.0, -1.0, 3.0}, {1.0, 2.0, 1.0}, {0.0, -3.0, 4.0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  int code = s21_determinant(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);
  ck_assert_double_eq_tol(result, 17.0, 1e-6);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant6) {
  matrix_t mat;
  double result;
  s21_create_matrix(3, 3, &mat);
  double values[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  int code = s21_determinant(&mat, &result);
  ck_assert_int_eq(code, OK_CODE);
  ck_assert_double_eq(result, 0.0);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_inverse_matrix1) {
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), INCORRECT_MATRIX_CODE);
  ck_assert_int_eq(s21_inverse_matrix(&result, NULL), INCORRECT_MATRIX_CODE);
}
END_TEST

START_TEST(test_s21_inverse_matrix2) {
  matrix_t mat, result;
  s21_create_matrix(2, 3, &mat);
  ck_assert_int_eq(s21_inverse_matrix(&mat, &result), CALCULATE_ERROR_CODE);
  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_inverse_matrix3) {
  matrix_t mat, result;
  s21_create_matrix(1, 1, &mat);
  mat.matrix[0][0] = 5.0;

  ck_assert_int_eq(s21_inverse_matrix(&mat, &result), OK_CODE);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.2, 1e-6);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix4) {
  matrix_t mat, result;
  s21_create_matrix(2, 2, &mat);
  double values[2][2] = {{4, 7}, {2, 6}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  ck_assert_int_eq(s21_inverse_matrix(&mat, &result), OK_CODE);

  ck_assert_double_eq_tol(result.matrix[0][0], 0.6, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -0.7, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], -0.2, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.4, 1e-6);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix5) {
  matrix_t mat, result;
  s21_create_matrix(2, 2, &mat);
  double values[2][2] = {{1, 2}, {2, 4}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat.matrix[i][j] = values[i][j];
    }
  }

  ck_assert_int_eq(s21_inverse_matrix(&mat, &result), CALCULATE_ERROR_CODE);
  s21_remove_matrix(&mat);
}
END_TEST

SRunner *create_runner() {
  SRunner *suit_runner;
  Suite *suit;
  TCase *tcase_create_matrix;
  TCase *tcase_eq_matrix;
  TCase *tcase_sum_matrix;
  TCase *tcase_sub_matrix;
  TCase *tcase_mult_number;
  TCase *tcase_mult_matrix;
  TCase *tcase_transpose;
  TCase *tcase_calc_complements;
  TCase *tcase_determinant;
  TCase *tcase_inverse_matrix;

  suit = suite_create("s21_matrix_test");
  suit_runner = srunner_create(suit);

  tcase_create_matrix = tcase_create("create_matrix");
  tcase_add_test(tcase_create_matrix, test_s21_create_matrix1);
  tcase_add_test(tcase_create_matrix, test_s21_create_matrix2);
  tcase_add_test(tcase_create_matrix, test_s21_create_matrix3);

  tcase_eq_matrix = tcase_create("equal_matrix");
  tcase_add_test(tcase_eq_matrix, test_s21_eq_matrix1);
  tcase_add_test(tcase_eq_matrix, test_s21_eq_matrix2);
  tcase_add_test(tcase_eq_matrix, test_s21_eq_matrix3);

  tcase_sum_matrix = tcase_create("sum_matrix");
  tcase_add_test(tcase_sum_matrix, test_s21_sum_matrix1);
  tcase_add_test(tcase_sum_matrix, test_s21_sum_matrix2);
  tcase_add_test(tcase_sum_matrix, test_s21_sum_matrix3);

  tcase_sub_matrix = tcase_create("sub_matrix");
  tcase_add_test(tcase_sub_matrix, test_s21_sub_matrix1);
  tcase_add_test(tcase_sub_matrix, test_s21_sub_matrix2);
  tcase_add_test(tcase_sub_matrix, test_s21_sub_matrix3);

  tcase_mult_number = tcase_create("mult_number");
  tcase_add_test(tcase_mult_number, test_s21_mult_number1);
  tcase_add_test(tcase_mult_number, test_s21_mult_number2);
  tcase_add_test(tcase_mult_number, test_s21_mult_number3);

  tcase_mult_matrix = tcase_create("mult_matrix");
  tcase_add_test(tcase_mult_matrix, test_s21_mult_matrix1);
  tcase_add_test(tcase_mult_matrix, test_s21_mult_matrix2);
  tcase_add_test(tcase_mult_matrix, test_s21_mult_matrix3);

  tcase_transpose = tcase_create("transpose");
  tcase_add_test(tcase_transpose, test_s21_transpose1);
  tcase_add_test(tcase_transpose, test_s21_transpose2);
  tcase_add_test(tcase_transpose, test_s21_transpose3);

  tcase_calc_complements = tcase_create("calc_complements");
  tcase_add_test(tcase_calc_complements, test_s21_calc_complements1);
  tcase_add_test(tcase_calc_complements, test_s21_calc_complements2);
  tcase_add_test(tcase_calc_complements, test_s21_calc_complements3);
  tcase_add_test(tcase_calc_complements, test_s21_calc_complements4);
  tcase_add_test(tcase_calc_complements, test_s21_calc_complements5);

  tcase_determinant = tcase_create("determinant");
  tcase_add_test(tcase_determinant, test_s21_determinant1);
  tcase_add_test(tcase_determinant, test_s21_determinant2);
  tcase_add_test(tcase_determinant, test_s21_determinant3);
  tcase_add_test(tcase_determinant, test_s21_determinant4);
  tcase_add_test(tcase_determinant, test_s21_determinant5);
  tcase_add_test(tcase_determinant, test_s21_determinant6);

  tcase_inverse_matrix = tcase_create("inverse_matrix");
  tcase_add_test(tcase_inverse_matrix, test_s21_inverse_matrix1);
  tcase_add_test(tcase_inverse_matrix, test_s21_inverse_matrix2);
  tcase_add_test(tcase_inverse_matrix, test_s21_inverse_matrix3);
  tcase_add_test(tcase_inverse_matrix, test_s21_inverse_matrix4);
  tcase_add_test(tcase_inverse_matrix, test_s21_inverse_matrix5);

  suite_add_tcase(suit, tcase_create_matrix);
  suite_add_tcase(suit, tcase_eq_matrix);
  suite_add_tcase(suit, tcase_sum_matrix);
  suite_add_tcase(suit, tcase_sub_matrix);
  suite_add_tcase(suit, tcase_mult_number);
  suite_add_tcase(suit, tcase_mult_matrix);
  suite_add_tcase(suit, tcase_transpose);
  suite_add_tcase(suit, tcase_calc_complements);
  suite_add_tcase(suit, tcase_determinant);
  suite_add_tcase(suit, tcase_inverse_matrix);

  return suit_runner;
}

int main(void) {
  SRunner *suit_runner = create_runner();
  srunner_run_all(suit_runner, CK_VERBOSE);
  int failed_quantity = srunner_ntests_failed(suit_runner);
  srunner_free(suit_runner);
  return (failed_quantity == 0);
}