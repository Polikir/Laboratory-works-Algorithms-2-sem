#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "DinamicArray.h"
#include "LinkedList.h"
#include "Matrix.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"
#include "SquareMatrix.h"
#include <iostream>
#include <cassert>
#pragma once
using namespace std;

int arr[] = {1, 2, 3, 4};
int *pointer = arr;



void Test(){

    DynamicArray<int> darray = DynamicArray<int>();
    assert(darray.GetSize() == 0);

    DynamicArray<int> darray1 = DynamicArray<int>(6);
    assert(darray1.GetSize() == 6);

    DynamicArray<int> darray2 = DynamicArray<int>(pointer, 4);
    assert(darray2.Get(0) == 1);

    DynamicArray<int> darrayc = DynamicArray<int>(darray2);
    assert(darrayc.GetSize() ==  darray2.GetSize());
    assert(darrayc.Get(0) ==  darray2.Get(0));

    assert(darray2.Get(1) ==  2);

    darray2.Set(0, 12);
    assert(darray2.Get(0)==12);

    darray2.Resize(2);
    assert(darray2.GetSize() ==  2);

    LinkedList<int> listn = LinkedList<int>();
    assert(listn.GetLength() == 0);

    LinkedList<int> list = LinkedList<int>(pointer, 4);
    assert(list.GetLength() == 4);
    assert(list.Get(0) == 1);

    LinkedList<int> list1 = LinkedList<int>(list);
    assert(list.GetLength() == list1.GetLength());
    assert(list.Get(0) == list1.Get(0));

    assert(list.GetFirst() ==  1);
    assert(list.GetLast() ==  4);


    auto* lists = list.GetSublist(1,3);
    assert(lists->GetLength() == 3);
    assert(lists->GetFirst() ==  2);
    assert(lists->GetLast() == 4);


    list1.Append(12);
    assert(list1.Get(4) == 12);

    list1.Prepend(12);
    assert(list1.Get(0)== 12);

    list1.InsertAt(12, 2);
    assert(list1.Get(2) ==  12);


    LinkedList<int>* listc = new LinkedList<int>();
    listc = list.Concat(&list);
    assert(listc->GetLength() == 8);

    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);

    assert(seq.GetFirst() == 1);
    assert(seq.GetLast() == 4);

    ArraySequence<int> *seq1 = new ArraySequence<int>();
    seq1 = seq.GetSubSequence(1, 2);
    assert(seq1->GetFirst() ==  2);
    assert(seq1->GetLast() == 3);

    seq1->Append(12);
    assert(seq1->GetLast() ==  12);

    seq1->Prepend(12);
    assert(seq1->Get(0) ==  12);

    seq1->InsertAt(25, 1);
    assert(seq1->Get(1) ==  25);

    ArraySequence<int> *conseq = new ArraySequence<int>();
    conseq = seq.Concat(&seq);
    assert(conseq->GetSize() == 8);

    LinkedList<int> ll = LinkedList<int>(pointer, 4);
    ListSequence<int> lseq = ListSequence<int>(&ll);
    assert(lseq.GetSize() == 4);
    assert(lseq.GetFirst() ==  1);
    assert(lseq.GetLast() == 4);

    ListSequence<int> *lseq1 = new ListSequence<int>();
    lseq1 = lseq.GetSubSequence(1, 2);
    assert(lseq1->GetFirst() == 2);
    assert(lseq1->GetLast() == 3);


    lseq1->Append(25);
    lseq1->Prepend(24);
    assert(lseq1->GetFirst()==24);
    assert(lseq1->GetLast() == 25);

    lseq1->InsertAt(20,1);
    assert(lseq1->Get(1)==20);

    delete lseq1;
    lseq1 = new ListSequence<int>();
    lseq1 = lseq.Concat(&lseq);
    assert(lseq1->GetSize() == 8);

    DiagonalMatrix<int> matrix0 = DiagonalMatrix<int>();
    assert(matrix0.GetSize() == 0);

    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
    assert(matrix.GetSize() == 4);
    assert(matrix.Get(0, 0) == 1);
    assert(matrix.Get(2, 2) == 3);

    matrix.Set(5,0,0);
    assert(matrix.Get(0,0) == 5);
    matrix.Set(1,0,0);

    assert(matrix.MatrixNorm<float>() - 5.47<0.01);

    DiagonalMatrix<int> matrix2 = DiagonalMatrix<int>(pointer, 4);
    auto* matrixsum = matrix.SumOfMatrix(&matrix2);
    assert(matrixsum->Get(0,0) == 2);
    assert(matrixsum->Get(3,3) == 8);

    auto* matrixmult = matrix.MultiplyOnScalar(2);
    assert(matrix.Get(0,0) == 2);

    complex c0 = complex(1,2);
    complex c1 = complex(2,1);
    complex c2 = complex(3,3);
    complex c3 = complex(-4,-2);
    complex arr_com[] = {c0,c1,c2,c3};
    complex *com_pointer = arr_com;

    DiagonalMatrix<complex> matrix_com = DiagonalMatrix<complex>(com_pointer,4);
    assert(matrix_com.GetSize() == 4);
    assert(matrix_com.Get(0,0) == c0);

    SquareMatrix<int> matrix_s = SquareMatrix<int>(pointer,2);

    assert(matrix_s.GetSize() == 2);
    assert(matrix_s.Get(1,1) == 4);
    assert(matrix_s.Get(0,1) == 2);

    matrix_s.Set(5,0,0);
    assert(matrix_s.Get(0,0) == 5);
    matrix_s.Set(1,0,0);

    assert(matrix_s.MatrixNorm<float>() - 5.47 <0.01);

    auto* s_matrix_s = matrix_s.SumOfMatrix(&matrix_s);
    assert(s_matrix_s->Get(0,0) == 2);
    assert(s_matrix_s->GetSize()==2);
    matrix_s.AddColToCol(1,2);
    assert(matrix_s.Get(0,0) == 3);


    matrix_s =  SquareMatrix<int>(pointer,2);
    matrix_s.SwaCol(1,2);
    assert(matrix_s.Get(0,1) == 1);

    matrix_s =  SquareMatrix<int>(pointer,2);
    matrix_s.SwaRow(1,2);
    assert(matrix_s.Get(0,1) == 4);

    matrix_s =  SquareMatrix<int>(pointer,2);
    int arr1[] = {1,0,0,1};
    int* pointer1 = arr1;
    SquareMatrix<int> matrix_s1 = SquareMatrix<int>(pointer1,2);

    SquareMatrix<int>* matrix_sm = matrix_s.MultiplyMatrix(&matrix_s1);

    assert(matrix_sm->GetSize() == 2);
    assert(matrix_sm->Get(1,1)==4);


    matrix_s.AddRowToRow(2,1);
    assert(matrix_s.Get(1,0)==4);

    matrix_s =  SquareMatrix<int>(pointer,2);
    matrix_s.SwaRow(2,1);
    assert(matrix_s.Get(1,0)==1);

    matrix_s =  SquareMatrix<int>(pointer,2);
    matrix_s.MultiplyCol(1,2);
    assert(matrix_s.Get(0,0) == 2);

    matrix_s =  SquareMatrix<int>(pointer,2);
    matrix_s.MultiplyCol(2,2);
    assert(matrix_s.Get(1,1) == 8);
    cout<<"Tests completed"<<endl;
    cout<<""<<endl;
}

#endif // TESTS_H_INCLUDED
