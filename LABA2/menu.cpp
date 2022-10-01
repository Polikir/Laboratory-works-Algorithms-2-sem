#include "menu.h"
#pragma once
#include "stdlib.h"
using namespace std;

int chooseTypeMatrix(){
    int type;
    cout << "Select type of numbers: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> type;
    return type;
}

int chooseFunctionDiagonalMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Matrix Norm\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> func;
    cout<<endl;
    return func;
}

template <typename T>
DiagonalMatrix<T>* inputDiagonalMatrix(){
    int dim;
    cout << "Enter dimension of matrix:";
    cin >> dim;
    DiagonalMatrix<T>* matrix = new DiagonalMatrix<T>(dim);
    cout << "Enter Main Diagonal Values:" << endl;
    T coord;
    for(int i = 0; i < dim; i++){
        cin >> coord;
        matrix->Set(coord, i, i);
    }
    return matrix;
}

DiagonalMatrix<complex>* InputComplexDiagonalMatrix() {
    int dim;
    cout << "Enter dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new DiagonalMatrix<complex>(dim);
    cout << "Enter Main Diagonal Values (one by one):" << endl;
    complex coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        cout << "Enter Real and Imaginary part (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex(real, im);
        matrix->Set(coord,i,i);
    }
    return matrix;
}

void ComplexDiagonalMatrixPrint(DiagonalMatrix<complex>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            if (i==j) {
                matrix.Get(i, j).print_complex();
                cout << " ";
            }
            else complex(0,0).print_complex();
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void IntDiagonalMatrixPrint(DiagonalMatrix<int>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            if (i==j) {
                cout << matrix.Get(i, j);
                cout << " ";
            }
            else cout<< 0 << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void RealDiagonalMatrixPrint(DiagonalMatrix<float>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            if (i==j) {
                cout << matrix.Get(i, j);
                cout << " ";
            }
            else cout<< 0 << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MenuDiagonalMatrix(){
    while(true){
        int type = chooseTypeMatrix();
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = chooseFunctionDiagonalMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        IntDiagonalMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        IntDiagonalMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    IntDiagonalMatrixPrint(*sum);

                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntDiagonalMatrixPrint(*matrix);
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    IntDiagonalMatrixPrint(*MatrixMult);
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntDiagonalMatrixPrint(*matrix1);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
        else if (type == 2){
            while (true){
                int function = chooseFunctionDiagonalMatrix();
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = inputDiagonalMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        RealDiagonalMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        RealDiagonalMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    RealDiagonalMatrixPrint(*sum);
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = inputDiagonalMatrix<float>();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealDiagonalMatrixPrint(*matrix);
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    RealDiagonalMatrixPrint(*MatrixMult);
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = inputDiagonalMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealDiagonalMatrixPrint(*matrix1);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
        else if (type == 3){
            while (true){
                int function = chooseFunctionDiagonalMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        ComplexDiagonalMatrixPrint(*matrix1);
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        ComplexDiagonalMatrixPrint(*matrix2);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    ComplexDiagonalMatrixPrint(*sum);
                    cout << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexDiagonalMatrix();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexDiagonalMatrixPrint(*matrix);
                        cout << endl;
                        cout << "Scalar = ";
                        cout<<scalar;
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar( scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    ComplexDiagonalMatrixPrint(*MatrixMult);
                    cout << endl;
                }
                else if (function == 3){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexDiagonalMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexDiagonalMatrixPrint(*matrix1);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex>();
                    cout << "Matrix Norm = ";
                    matrixNorm.print_complex();
                }
                else if (function == 0) break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
    }
}



int ChooseFunctionSquareMatrix(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Sum of Matrices\n"
         << "\t2: Multiplication of scalar and matrix\n"
         << "\t3: Multiplication of two matrix\n"
         << "\t4: Matrix Norm\n"
         << "\t5: Multiplication of scalar and row\n"
         << "\t6: Addition of row and row\n"
         << "\t7: Multiplication of scalar and column\n"
         << "\t8: Addition of column and column\n"
         << "\t9: Swapping columns\n"
         << "\t10: Swapping rows\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> func;
    cout << endl;
    return func;
}


template <typename T>
SquareMatrix<T>* InputSquareMatrix(){
    int dim;
    cout << "Enter dimension of matrix:";
    cin >> dim;
    SquareMatrix<T>* matrix = new SquareMatrix<T>(dim);
    cout << "Enter Values:" << endl;
    T coord;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++) {
            cin >> coord;
            matrix->Set(coord, i, j);
        }
    }
    return matrix;
}

SquareMatrix<complex>* InputComplexSquareMatrix() {
    int dim;
    cout << "Enter dimension of Matrix:";
    cin >> dim;
    cout << endl;
    auto* matrix = new SquareMatrix<complex>(dim);
    cout << "Enter Main  Values (one by one):" << endl;
    complex coord;
    float real, im;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++) {
            cout << "Enter Real and Imaginary part (separated by a space): " << endl;
            cin >> real >> im;
            coord = complex(real, im);
            matrix->Set(coord, i, j);
        }
    }
    return matrix;
}

void ComplexSquareMatrixPrint(SquareMatrix<complex>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            matrix.Get(i, j).print_complex();
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void IntSquareMatrixPrint(SquareMatrix<int>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            cout << matrix.Get(i, j);
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void RealSquareMatrixPrint(SquareMatrix<float>& matrix) {
    for (int i=0; i<matrix.GetSize(); i++) {
        for (int j=0; j<matrix.GetSize(); j++) {
            cout << matrix.Get(i, j);
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void MenuSquareMatrix(){
    while(true){
        int type = chooseTypeMatrix();
        if(type == 0){
            break;
        }
        else if (type == 1){
            while (true){
                int function = ChooseFunctionSquareMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        IntSquareMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        IntSquareMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    IntSquareMatrixPrint(*sum);
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl << MatrixMult << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        IntSquareMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        IntSquareMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl;
                    IntSquareMatrixPrint(*mult);
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<int>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix1);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if(function == 5) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow( numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if(function == 6){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number of second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow( numRow1, numRow2);
                    cout << "Addition of row and row = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if(function == 7) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of column:" << endl;
                    int numCol;
                    cin >> numCol;
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyCol( numCol, scalar);
                    cout << "Multiplication of scalar and column = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if(function == 8){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddColToCol( numCol1, numCol2);
                    cout << "Addition of column and column = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if(function == 9){ //Swapping columns
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaCol( numCol1, numCol2);
                    cout << "Swapping matrix = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if(function == 10){ //Swapping rows
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<int>();
                    cout << "Enter number of first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number of second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        IntSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaRow( numRow1, numRow2);
                    cout << "Swapping matrix = " << endl;
                    IntSquareMatrixPrint(*matrix);
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
        else if (type == 2){
            while (true){
                int function = ChooseFunctionSquareMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        RealSquareMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        RealSquareMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    RealSquareMatrixPrint(*sum);
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                        cout << "Scalar = " << scalar << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    RealSquareMatrixPrint(*MatrixMult);
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        RealSquareMatrixPrint(*matrix1);
                        cout << "Second matrix = " << endl;
                        RealSquareMatrixPrint(*matrix2);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrix(matrix2);
                    cout << "Multiplication of first matrix and second matrix = " << endl;
                    RealSquareMatrixPrint(*mult);
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputSquareMatrix<float>();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix1);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<float>();
                    cout << "Matrix Norm = " << matrixNorm << endl;
                }
                else if(function == 5) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow( numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if(function == 6){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow( numRow1, numRow2);
                    cout << "Addition of row and row = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if(function == 7) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number of column:" << endl;
                    int numCol;
                    cin >> numCol;
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyCol( numCol, scalar);
                    cout << "Multiplication of scalar and column = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if(function == 8){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddColToCol( numCol1, numCol2);
                    cout << "Addition of column and column = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if(function == 9){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaCol(numCol1, numCol2);
                    cout << "Swapping matrix = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if(function == 10){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputSquareMatrix<float>();
                    cout << "Enter number of first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number of second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        RealSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaRow( numRow1, numRow2);
                    cout << "Swapping matrix = " << endl;
                    RealSquareMatrixPrint(*matrix);
                }
                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
        else if (type == 3){
            while (true){
                int function = ChooseFunctionSquareMatrix();
                if (function == 1){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexSquareMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexSquareMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix1);
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix2);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* sum = matrix1->SumOfMatrix(matrix2);
                    cout << "Sum of first matrix and second matrix = " << endl;
                    ComplexSquareMatrixPrint(*sum);
                    cout << endl;
                }
                else if (function == 2){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter scalar: " << endl;
                    float scalar;
                    cin >> scalar;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto MatrixMult = matrix->MultiplyOnScalar(scalar);
                    cout << "Multiplication of matrix and scalar = " << endl;
                    ComplexSquareMatrixPrint(*MatrixMult);
                    cout << endl;
                }
                else if (function == 3){
                    cout << "Enter first matrix:" << endl;
                    auto* matrix1 = InputComplexSquareMatrix();
                    cout << "Enter second matrix:" << endl;
                    auto* matrix2 = InputComplexSquareMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "First matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix1);
                        cout << endl;
                        cout << "Second matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix2);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto* mult = matrix1->MultiplyMatrixComplex(matrix2);
                    cout << "Multiplication first matrix and second matrix = " << endl;
                    ComplexSquareMatrixPrint(*mult);
                    cout << endl;
                }
                else if (function == 4){
                    cout << "Enter matrix:" << endl;
                    auto* matrix1 = InputComplexSquareMatrix();
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix1);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    auto matrixNorm = matrix1->MatrixNorm<complex>();
                    cout << "Matrix Norm = ";
                    matrixNorm.print_complex();
                    cout<< endl;
                }
                else if(function == 5) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number row:" << endl;
                    int numRow;
                    cin >> numRow;
                    cout << "Enter scalar: " << endl;
                    float x, y;
                    cin >> x;
                    cin >> y;
                    complex scalar = complex(x, y);
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyRow( numRow, scalar);
                    cout << "Multiplication of scalar and row = " << endl << matrix << endl;
                }
                else if(function == 6){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                        cout << endl;
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddRowToRow( numRow1, numRow2);
                    cout << "Addition of row and row = " << endl << matrix << endl;
                }
                else if(function == 7) {
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number of column:" << endl;
                    int numCol;
                    cin >> numCol;
                    cout << "Enter scalar: " << endl;
                    complex scalar;
                    float real, imag;
                    cin >> real >> imag;
                    scalar = complex(real, imag);
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->MultiplyCol( numCol, scalar);
                    cout << "Multiplication of scalar and column = " << endl;
                    ComplexSquareMatrixPrint(*matrix);
                }
                else if(function == 8){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->AddColToCol( numCol1, numCol2);
                    cout << "Addition of column and column = " << endl;
                    ComplexSquareMatrixPrint(*matrix);
                }
                else if(function == 9){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number of first column:" << endl;
                    int numCol1;
                    cin >> numCol1;
                    cout << "Enter number of second column:" << endl;
                    int numCol2;
                    cin >> numCol2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);}
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaCol(numCol1, numCol2);
                    cout << "Swapping matrix = " << endl;
                    ComplexSquareMatrixPrint(*matrix);
                }
                else if(function == 10){
                    cout << "Enter matrix:" << endl;
                    auto* matrix = InputComplexSquareMatrix();
                    cout << "Enter number of first row:" << endl;
                    int numRow1;
                    cin >> numRow1;
                    cout << "Enter number of second row:" << endl;
                    int numRow2;
                    cin >> numRow2;
                    cout << "Print it?\n\t1 - yes\n\t0 - no" << endl;
                    int buf;
                    cin >> buf;
                    if(buf == 1){
                        cout << "Matrix = " << endl;
                        ComplexSquareMatrixPrint(*matrix);
                    }
                    else if (buf != 0){
                        throw invalid_argument("Incorrect number");
                    }
                    matrix->SwaRow( numRow1, numRow2);
                    cout << "Swapping matrix = " << endl;
                    ComplexSquareMatrixPrint(*matrix);
                }


                else if (function == 0)
                    break;
                else
                    throw invalid_argument("Incorrect number");
            }
        }
    }
}

///Menu
int menu(){
    while(true){
        int classType;
        cout << " Diagonal matrix - 1 \n Square matrix - 2 \n Exit - 0 ->" << endl;
        cin >> classType;
        cout << endl;
        if (classType != 0 & classType != 1 & classType != 2){
            cout << "The number is incorrect. Please, enter the correct number" << endl;
        }
        if(classType == 1){
            MenuDiagonalMatrix();
        }
        else if (classType == 2){
            MenuSquareMatrix();
        }
        else if (classType == 0){
            break;
        }
    }
    return 0;
};
