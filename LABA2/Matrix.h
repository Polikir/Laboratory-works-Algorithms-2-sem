

#include "ArraySequence.h"
#include "Complex.h"
#pragma once
template <typename T> class DiagonalMatrix {
private:
    ArraySequence<T> *matrix;
public:

    DiagonalMatrix() {
        matrix = new ArraySequence<T>;
    };

    DiagonalMatrix(int count) {
        matrix = new ArraySequence<T>(count);
    };

    DiagonalMatrix(T *items, int count) {
        matrix = new ArraySequence<T>(items, count);
    }

    DiagonalMatrix(ArraySequence<T> *new_matrix) {
        matrix = new_matrix;
    }

    DiagonalMatrix(DiagonalMatrix<T> *new_matrix) {
        matrix = new_matrix->matrix;
    }


    ~DiagonalMatrix() = default;

    T Get(int row, int col) {

            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw out_of_range("Index out of range!");
            if (row != col)
                throw out_of_range("Zero element");
            return matrix->Get(row);


    }

    int GetSize() {
        return matrix->GetSize();
    }


    void Append(T item) {
        return matrix->Append(item);
    };

    void Set(T item, int row, int col) {

            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw out_of_range("Index out of range!");
            if (row != col)
                throw out_of_range("Wrong position!");
            return matrix->Set(row, item);


    };
    //
    template<typename U>
    U MatrixNorm() {
        U sum = this->Get(0, 0) * this->Get(0, 0);
        for (int i = 1; i < this->GetSize(); i++)
            sum = sum + this->Get(i, i) * this->Get(i, i);
        return sqrt(sum);
    }

    DiagonalMatrix<T> *MultiplyOnScalar(float scalar) {
        T item;
        DiagonalMatrix<T> *new_Matrix = new DiagonalMatrix<T>(matrix);
        for (int i = 0; i < this->GetSize(); i++) {
            item = this->Get(i, i) * scalar;
            new_Matrix->matrix->Set(i, item);
        }
        return new_Matrix;
    };

    DiagonalMatrix<T> *SumOfMatrix(DiagonalMatrix<T> *matrix1) {

            if (this->GetSize() != matrix1->GetSize())
                throw length_error("Different size!");
            DiagonalMatrix<T> *new_Matrix = new DiagonalMatrix<T>();
            T item;
            for (int i = 0; i < this->GetSize(); i++) {
                item = this->Get(i, i) + matrix1->Get(i, i);
                new_Matrix->Append(item);
            }
            return new_Matrix;
    };

};

template<>
template<> inline
complex DiagonalMatrix<complex>::MatrixNorm<complex>() {
    complex sum = complex(0,0);
    for (int i = 0; i<this->GetSize(); i++) {
        sum = sum + ((this->Get(i,i))*(this->Get(i,i)));

    }
    return sum.sqrt_complex();
}


