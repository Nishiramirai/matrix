#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdlib.h>

#define OK_CODE 0
#define INCORRECT_MATRIX_CODE 1
#define CALCULATE_ERROR_CODE 2
#define ALLOCATE_ERROR_CODE 3

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/**
 * @brief Создает матрицу указанного размера и выделяет для нее динамическую
 * память. Во избежание утечек удалить после использования при помощи
 * s21_remove_matrix
 * @param rows Количество строк в матрице
 * @param columns Количество столбцов в матрице
 * @param result Указатель на структуру matrix_t
 * @return
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Освобождает память, выделенную на матрицу
 * @param matrix_t Указатель на структуру matrix_t
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Сравнивает 2 матрицы и возвращает результат сравнения
 * @param A Указатель на первую матрицу matrix_t
 * @param B Указатель на вторую матрицу matrix_t
 * @return Результат сравнения SUCCESS или FAILURE
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Складывает 2 матрицы и записывает результат в переданную матрицу
 * result
 * @param A Указатель на первую матрицу в виде структуры matrix_t
 * @param B Указатель на вторую структуру в виде структуры matrix_t
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Считает разность двух переданных матриц и записывает результат в
 * переданную матрицу result
 * @param A Указатель на первую матрицу в виде структуры matrix_t
 * @param B Указатель на вторую структуру в виде структуры matrix_t
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Умножает матрицу на число и записывает результат в переданную матрицу
 * result
 * @param A Указатель на матрицу в виде структуры matrix_t
 * @param number Число типа double, на которое будет происходить умножение
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief Считает произведение двух переданных матриц и записывает результат в
 * переданную матрицу result
 * @param A Указатель на первую матрицу в виде структуры matrix_t
 * @param B Указатель на вторую структуру в виде структуры matrix_t
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Транспонирует матрицу и записывает результат в матрицу result
 * @param A Указатель на матрицу в виде структуры matrix_t
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief
 * @param
 * @param
 * @return
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Считает определитель квадратной матрицы и записывает результат в
 * переданный указатель result
 * @param A Указатель на матрицу в виде структуры matrix_t
 * @param result указатель на переменную типа double, в которую будет записан
 * результат
 * @return
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief Вычисляет обратную матрицу для переданной матрицы A и записывает в
 * матрицу result
 * @param A Указатель на матрицу в виде структуры matrix_t
 * @param result Указатель на структуру matrix_t, в которую будет записан
 * результат
 * @return
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

/**
 * @brief Сравнивает размеры двух переданных матриц
 * @param A Указатель на первую матрицу в виде структуры matrix_t
 * @param B Указатель на вторую матрицу в виде структуры matrix_t
 * @return 1(true) если размер матриц равен, 0(false) в противном случае
 */
int s21_equal_size_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Создает минор матрицы A, удаляя строку skip_row и столбец skip_col.
 * Предполагает, что память для minor уже выделена и размеры верны.
 * @param A Указатель на матрицу в виде структуры matrix_t
 * @param B Указатель на минор в виде структуры matrix_t
 * @return
 */
void s21_get_minor(matrix_t *A, matrix_t *minor, int skip_row, int skip_col);

// TODO: Delete at release
void debug_print_matrix(matrix_t matrix);

#endif