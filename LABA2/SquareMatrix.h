

#include "ArraySequence.h"

#pragma once

template <typename T> class SquareMatrix {
private:
    int size;
    ArraySequence<T>* array_sequence;
public:


    SquareMatrix() {
        array_sequence = new ArraySequence<T>;
        size = 0;
    }

    SquareMatrix(int size_m) {
        array_sequence = new ArraySequence<T>(size_m * size_m);
        size = size_m;
    }

    SquareMatrix(T *array, int size_m) {
        array_sequence = new ArraySequence<T>(array, size_m * size_m);
        size = size_m;
    }

    SquareMatrix(const ArraySequence<T> arraySequence, int size_m) {
        size = size_m;
        array_sequence = arraySequence;
    }

    ~SquareMatrix() = default;


    int GetSize() {
        return size;
    }

    T Get(int row, int col) {
        if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
            throw out_of_range("Index out of range!");
        return array_sequence->Get(row * size + col);
    }


    void Append(T item) {
        return array_sequence->Append(item);
    };

    void Set(T item, int row, int col) {
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw out_of_range("Index out of range!");
            return array_sequence->Set(row * size + col, item);

        };

    template<typename U> U MatrixNorm() {
            U sum = 0;
            for (int i = 0; i < this->GetSize(); i++)
                for (int j = 0; j < this->GetSize(); j++)
                    sum = sum + this->Get(i, j) * this->Get(i, j);
            return sqrt(sum);
        }

        SquareMatrix<T> *SumOfMatrix(SquareMatrix<T> *matrix) {
            if (size != matrix->size) {
                throw length_error("Different size!");
            }
            T *new_array = new T[size * size];
            for (int i = 0; i < size * size; i++) {
                new_array[i] = array_sequence->Get(i) + matrix->array_sequence->Get(i);
            }
            auto *newArray = new SquareMatrix<T>(new_array, size);
            return newArray;
        }

        SquareMatrix<T> *MultiplyOnScalar(float scalar) {
            T *new_array = new T[size*size];
            for (int i = 0; i < size*size; ++i) {
                new_array[i] = array_sequence->Get(i) * scalar;
            }
            auto *newArray = new SquareMatrix<T>(new_array, size);
            return newArray;
        }

        SquareMatrix<T> *MultiplyMatrix(SquareMatrix<T> *matrix) {
            if (size != matrix->size)
                throw length_error("Different size!");
            T *a = new T[size * size];
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    a[i * size + j] = 0;
                    for (int k = 0; k < size; ++k) {
                        a[i * size + j] = a[i * size + j] +
                                          array_sequence->Get(i * size + k) * matrix->array_sequence->Get(k * size + j);
                    }
                }
            }
            auto *newArray = new SquareMatrix<T>(a, size);
            return newArray;
        }



        void MultiplyRow( int row, T scalar) {
            if (row < 1 || row > size)
                throw out_of_range("Index out of range!");
            for (int i = 0; i < size; i++) {
                array_sequence->Set(size*(row - 1)+i,array_sequence->Get((row - 1) * size + i) * scalar);
            }
        }

    void AddRowToRow( int first, int second) {

        if (first < 1 || first > size || second < 1 || second > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            array_sequence->Set(size*(first-1)+i,array_sequence->Get((first - 1) * size + i) + array_sequence->Get((second - 1) * size + i));
        }
    }

    void MultiplyCol( int col, T scalar) {
        if (col < 1 || col > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++) {
            array_sequence->Set(i*size+ col - 1,array_sequence->Get(i * size + col - 1) * scalar);
        }
    }

    void AddColToCol( int first, int second) {

        if (first < 1 || first > size || second < 1 || second > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            array_sequence->Set(i*size+first-1,array_sequence->Get(i * size + first - 1) + array_sequence->Get(i * size + second - 1));
        }
    }


    void SwaCol( int coll1,int coll2) {
        T item;
        if (coll1 < 1 || coll1 > size||coll2 < 1 || coll2 > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++) {
            item = array_sequence->Get(i*size+coll1-1);
            array_sequence->Set( i*size + coll1 - 1,array_sequence->Get(i*size+coll2-1));
            array_sequence->Set( i*size + coll2 - 1,item);
        }
    }

    void SwaRow( int row1,int row2) {
        T item;
        if (row1 < 1 || row1 > size||row2 < 1 || row2 > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++) {
            item = array_sequence->Get(size*(row1-1)*i);
            array_sequence->Set(size*(row1 - 1)+i,array_sequence->Get(size*(row2-1)+i));
            array_sequence->Set(size*(row2 - 1)+i,item);
        }
    }


    SquareMatrix<complex> *MultiplyMatrixComplex(SquareMatrix<complex> *matrix) {
        if (size != matrix->size)
            throw length_error("Different size!");
        T *a = new T[size * size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                a[i * size + j] = complex(0,0);
                for (int k = 0; k < size; ++k) {
                    a[i * size + j] = a[i * size + j] +
                                      array_sequence->Get(i * size + k) * matrix->array_sequence->Get(k * size + j);
                }
            }
        }
        auto *newArray = new SquareMatrix<T>(a, size);
        return newArray;
    }
    };

template<>
template<> inline
complex SquareMatrix<complex>::MatrixNorm<complex>() {
    complex sum = complex(0,0);
    for (int i = 0; i<this->GetSize(); i++) {
        for (int j = 0; j < this->GetSize(); j++)
            sum = sum + ((this->Get(i,j))*(this->Get(i,j)));
    }
    return sum.sqrt_complex();
}


