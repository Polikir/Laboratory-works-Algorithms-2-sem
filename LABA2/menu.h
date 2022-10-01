

#include "ArraySequence.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>
#include "Complex.h"
#include <ctime>
#pragma once
int chooseTypeMatrix();
int chooseFunctionDiagonalMatrix();
template <typename T> DiagonalMatrix<T>* inputDiagonalMatrix();
DiagonalMatrix<complex>* InputComplexDiagonalMatrix();
void MenuDiagonalMatrix();
template <typename T> SquareMatrix<T>* InputSquareMatrix();
SquareMatrix<complex>* InputComplexSquareMatrix();
int ChooseFunctionSquareMatrix();
void MenuSquareMatrix();
int menu();


