# School 21. Matrix

Implementation of the library for working with matrices in the C programming language.


## Project Structure

- The program is written in C language (C11 standard) using the `gcc` compiler.
- The project is a static library containing functions for working with matrices.
- The Makefile supports the following targets: `all`, `s21_matrix.a`, `clean`,`test`, `gcov_report`.


## Run Locally

### Prerequisites

- A C compiler (tested only on `gcc`).
- The `Check` library for unit testing.
- `gcov` and `lcov` for code coverage.

### Steps

1. **Clone the repository**

    ```bash
    git clone git@github.com:Nishiramirai/matrix.git
    ```

2. **Navigate to the project directory**

    ```bash
    cd matrix
    ```

3. **Build a static library**

    ```bash
    make
    ```

4. **Compile your code with functions from library**

    ```bash
    gcc your_code.c s21_matrix.a
    ```



### Tests
1. **Run tests**

    ```bash
    make test
    ```

2. **Generate code coverage report**

    ```bash
    make gcov_report
    ```
