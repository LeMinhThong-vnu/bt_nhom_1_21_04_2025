#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows, cols;
        int** data;
    public:
        Matrix(int r, int c);
        ~Matrix();

        void input();

        void print() const;

        Matrix operator+(const Matrix& other);
};

Matrix::Matrix(int r, int c) {
    if (r > 0 && c > 0) {
        rows = r;
        cols = c;
        data = new int*[r];
    }
    else {
        throw length_error("Matrix cannot have negative or zero dimensions");
    }
}

Matrix::~Matrix() {
    for (int i = rows - 1; i >= 0; i--) {
        int* row = *(data + i);
        delete *(data + i);
    }
    delete data;
}

void Matrix::input() {
    printf("Input matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        int* row = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> *(row + j);
        }
        *(data + i) = row;
    }
}

void Matrix::print() const {
    printf("Printing matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        int* row = *(data + i);
        if (row != NULL) {
            for (int j = 0; j < cols; j++) {
                cout << row[j] << " ";
            }
            cout << endl;
        }
        else {
            throw range_error("Row does not exist. Maybe call input()?");
        }
    }
}

Matrix Matrix::operator+(const Matrix& other) {
    Matrix new_matrix = Matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        int* row1 = *(data + i);
        int* row2 = *(other.data + i);
        int* row = new int[cols];
        if (row1 != NULL && row2 != NULL) {
            for (int j = 0; j < cols; j++) {
                // printf("a: %d, b: %d", *(row1 + j), *(row2 + j));
                *(row + j) = *(row1 + j) + *(row2 + j);
            }
            *(new_matrix.data + i) = row;
        }
        else {
            throw range_error("Row does not exist. Maybe call input()?");
        }
    }
    return new_matrix;
}

int main() {
    int cols, rows;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;
    Matrix a = Matrix(rows, cols);
    Matrix b = Matrix(rows, cols);
    a.input();
    b.input();
    Matrix c = a + b;
    c.print();
    return 0;
}