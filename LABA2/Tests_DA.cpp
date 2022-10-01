////#include <gtest/gtest.h>
//#include "DinamicArray.h"
//#include "LinkedList.h"
//#include "Matrix.h"
//#include "ArraySequence.h"
//#include "LinkedListSequence.h"
//#include "Complex.h"
//#include "SquareMatrix.h"
//
//int arr[] = {1, 2, 3, 4};
//int *pointer = arr;
//
//TEST(DynamicArray, Constructor_1) {
//    DynamicArray<int> array = DynamicArray<int>();
//    EXPECT_EQ(array.GetSize(), 0);
//}
//
//TEST(DynamicArray, Constructor_2) {
//    DynamicArray<int> array = DynamicArray<int>(6);
//    EXPECT_EQ(array.GetSize(), 6);
//    EXPECT_THROW(DynamicArray<int>(-1), length_error);
//}
//
//TEST(DynamicArray, Constructor_3) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
////Creting an Dynamic Array from int array : it will look like
//// elements { 1 2 3 4 5 }
//// index      0 1 2 3 4
//    EXPECT_EQ(array.GetSize(), 4);
//    EXPECT_EQ(array.Get(0), 1);
//    EXPECT_EQ(array.Get(3), 4);
//    EXPECT_THROW(DynamicArray<int>(pointer, -1), length_error);
//}
//
//TEST(DynamicArray, Constructor_4) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    DynamicArray<int> array1 = DynamicArray<int>(array);
//    EXPECT_EQ(array.GetSize(), array1.GetSize());
//    EXPECT_EQ(array.Get(0), array1.Get(0));
//    EXPECT_EQ(array.Get(3), array1.Get(3));
//}
//
//TEST(DynamicArray, GetSize) {
//    DynamicArray<int> array = DynamicArray<int>( 4);
//    EXPECT_EQ(array.GetSize(), 4);
//}
//
//TEST(DynamicArray, Get) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    EXPECT_EQ(array.Get(1), 2);
//    EXPECT_THROW(array.Get(-1), out_of_range);
//    EXPECT_THROW(array.Get(5), out_of_range);
//}
//
//TEST(DynamicArray, Set) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    array.Set(0, 12);
//    EXPECT_EQ(array.Get(0), 12);
//    EXPECT_THROW(array.Set(-1, 12), out_of_range);
//    EXPECT_THROW(array.Set(5, 12), out_of_range);
//}
//
//TEST(DynamicArray, Resize) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    array.Resize(2);
//    EXPECT_EQ(array.GetSize(), 2);
//    EXPECT_THROW(array.Resize(-1), length_error);
//}
//
////______________________
//
//TEST(LinkedList, Constructor_1) {
//    LinkedList<int> list = LinkedList<int>();
//    EXPECT_EQ(list.GetLength(), 0);
//}
//
//TEST(LinkedList, Constructor_2) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
////Creting an Dynamic Array from int array : it will look like
//// elements { 1 2 3 4 5 }
//// index      0 1 2 3 4
//    EXPECT_EQ(list.GetLength(), 4);
//    EXPECT_EQ(list.Get(0), 1);
//    EXPECT_EQ(list.Get(3), 4);
//    EXPECT_THROW(LinkedList<int>(pointer, -1), length_error);
//}
//
//TEST(LinkedList, Constructor_3) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    LinkedList<int> list1 = LinkedList<int>(list);
//    EXPECT_EQ(list.GetLength(), list1.GetLength());
//    EXPECT_EQ(list.Get(0), list1.Get(0));
//    EXPECT_EQ(list.Get(3), list1.Get(3));
//}
//
//TEST(LinkedList, GetSize) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    EXPECT_EQ(list.GetLength(), 4);
//}
//
//TEST(LinkedList, Get) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    EXPECT_EQ(list.Get(1), 2);
//    EXPECT_THROW(list.Get(-1), out_of_range);
//    EXPECT_THROW(list.Get(5), out_of_range);
//}
//
//TEST(LinkedList, GetFirst) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    EXPECT_EQ(list.GetFirst(), 1);
//    LinkedList<int> list1 = LinkedList<int>();
//    EXPECT_THROW(list1.GetFirst(), out_of_range);
//}
//
//TEST(LinkedList, GetLast) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    EXPECT_EQ(list.GetLast(), 4);
//    LinkedList<int> list1 = LinkedList<int>();
//    EXPECT_THROW(list1.GetLast(), out_of_range);
//}
//
//TEST(LinkedList, GetSublist) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    LinkedList<int>* list1 = new LinkedList<int>();
//    list1 = list.GetSublist(1,3);
//    EXPECT_EQ(list1->GetLength(), 3);
//    EXPECT_EQ(list1->GetFirst(), 2);
//    EXPECT_EQ(list1->GetLast(), 4);
//    EXPECT_THROW(list.GetSublist(-1,3), out_of_range);
//    EXPECT_THROW(list.GetSublist(1,5), out_of_range);
//}
//
//TEST(LinkedList, Appened) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    list.Append(12);
//    EXPECT_EQ(list.Get(4), 12);
//}
//
//TEST(LinkedList, Prepend) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    list.Prepend(12);
//    EXPECT_EQ(list.Get(0), 12);
//}
//
//TEST(LinkedList, Insert_at) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    list.InsertAt(12, 2);
//    EXPECT_EQ(list.Get(2), 12);
//}
//
//TEST(LinkedList, Concat) {
//    LinkedList<int> list = LinkedList<int>(pointer, 4);
//    LinkedList<int>* list1 = new LinkedList<int>();
//    list1 = list.Concat(&list);
//    EXPECT_EQ(list1->GetLength(), 8);
//    EXPECT_EQ(list1->Get(4), 1);
//}
//
//TEST(ArraySequence, Get) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    EXPECT_EQ(seq.Get(0), 1);
//    EXPECT_THROW(seq.Get(-1), out_of_range);
//}
//
//TEST(ArraySequence, GetFirst_GetLast) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    EXPECT_EQ(seq.GetFirst(), 1);
//    EXPECT_EQ(seq.GetLast(), 4);
//}
//
//TEST(ArraySequence, GetSubSequence) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    EXPECT_THROW(seq.GetSubSequence(-1, 2), out_of_range);
//    ArraySequence<int> *seq1 = new ArraySequence<int>();
//    seq1 = seq.GetSubSequence(1, 2);
//    EXPECT_EQ(seq1->GetFirst(), 2);
//    EXPECT_EQ(seq1->GetLast(), 3);
//}
//
//TEST(ArraySequence, GetSize) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    EXPECT_EQ(seq.GetSize(), 4);
//}
//
//TEST(ArraySequence, Append) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    seq.Append(12);
//    EXPECT_EQ(seq.Get(4), 12);
//}
//
//TEST(ArraySequence, Prepend) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    seq.Prepend(12);
//    EXPECT_EQ(seq.Get(0), 12);
//}
//
//TEST(ArraySequence, InsertAt) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    EXPECT_THROW(seq.InsertAt(-1, 12), out_of_range);
//    seq.InsertAt(12, 1);
//    EXPECT_EQ(seq.Get(1), 12);
//}
//
//TEST(ArraySequence, Concat) {
//    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
//    ArraySequence<int> seq = ArraySequence<int>(&array);
//    ArraySequence<int> *newseq = new ArraySequence<int>();
//    newseq = seq.Concat(&seq);
//    EXPECT_THROW(seq.InsertAt(-1, 12), out_of_range);
//    seq.InsertAt(12, 1);
//    EXPECT_EQ(newseq->GetSize(), 8);
//    EXPECT_EQ(newseq->Get(4), 1);
//}
//
//TEST(ListSequence, Get) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    EXPECT_EQ(seq.Get(0), 1);
//    EXPECT_THROW(seq.Get(-1), out_of_range);
//}
//
//TEST(ListSequence, GetFirst_GetLast) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    EXPECT_EQ(seq.GetFirst(), 1);
//    EXPECT_EQ(seq.GetLast(), 4);
//}
//
//TEST(ListSequence, GetSubSequence) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    EXPECT_THROW(seq.GetSubSequence(-1, 2), out_of_range);
//    ListSequence<int> *seq1 = new ListSequence<int>();
//    seq1 = seq.GetSubSequence(1, 2);
//    EXPECT_EQ(seq1->GetFirst(), 2);
//    EXPECT_EQ(seq1->GetLast(), 3);
//}
//
//TEST(ListSequence, GetSize) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    EXPECT_EQ(seq.GetSize(), 4);
//}
//
//TEST(ListSequence, Append) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    seq.Append(12);
//    EXPECT_EQ(seq.Get(4), 12);
//}
//
//TEST(ListSequence, Prepend) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    seq.Prepend(12);
//    EXPECT_EQ(seq.Get(0), 12);
//}
//
//TEST(ListSequence, InsertAt) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    EXPECT_THROW(seq.InsertAt(-1, 12), out_of_range);
//    seq.InsertAt(12, 1);
//    EXPECT_EQ(seq.Get(1), 12);
//}
//
//TEST(ListSequence, Concat) {
//    LinkedList<int> array = LinkedList<int>(pointer, 4);
//    ListSequence<int> seq = ListSequence<int>(&array);
//    ListSequence<int> *newseq = new ListSequence<int>();
//    newseq = seq.Concat(&seq);
//    EXPECT_THROW(seq.InsertAt(-1, 12), out_of_range);
//    seq.InsertAt(12, 1);
//    EXPECT_EQ(newseq->GetSize(), 8);
//    EXPECT_EQ(newseq->Get(4), 1);
//}
//
//TEST(DiagonalMatrix, Constructor_1) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>();
//    EXPECT_EQ(matrix.GetSize(), 0);
//}
//
//TEST(DiagonalMatrix, Constructor_2) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
//    EXPECT_EQ(matrix.GetSize(), 4);
//    EXPECT_EQ(matrix.Get(0, 0), 1);
//    EXPECT_THROW(matrix.Get(0, 1), out_of_range);
//}
//
//TEST(DiagonalMatrix, GetSize) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
//    EXPECT_EQ(matrix.GetSize(), 4);;
//}
//
//TEST(DiagonalMatrix, Get) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
//    EXPECT_EQ(matrix.Get(0, 0), 1);
//    EXPECT_THROW(matrix.Get(0, 1), out_of_range);
//    EXPECT_EQ(matrix.Get(3, 3), 4);
//    EXPECT_THROW(matrix.Get(0, -1), out_of_range);
//}
//
//TEST(DiagonalMatrix, Set) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
//    matrix.Set(12, 0, 0);
//    EXPECT_EQ(matrix.Get(0, 0), 12);
//    EXPECT_THROW(matrix.Set(12, 0, 1), out_of_range);
//    EXPECT_THROW(matrix.Set(12, -1, 3), out_of_range);
//}
//
//TEST(DiagonalMatrix, Norm) {
//    DiagonalMatrix<int> matrix = DiagonalMatrix<int>(pointer, 4);
//    EXPECT_TRUE(matrix.MatrixNorm<float>() - 5.47 < 0.01);
//}
//
//int a1[] = {1, 2, 3, 4, 5};
//int *pointer1 = a1;
//
//TEST(DiagonalMatrix, SumOfMatrix) {
//    auto* matrix1 = new DiagonalMatrix<int>(pointer, 4);
//    auto* matrix2 = new DiagonalMatrix<int>(pointer, 4);
//    auto* matrix3 = new DiagonalMatrix<int>(pointer1, 5);
//    auto* Sum = matrix1->SumOfMatrix(matrix2);
//    EXPECT_EQ(Sum->Get(0, 0), 2);
//    EXPECT_THROW(matrix1->SumOfMatrix(matrix3), length_error);
//}
//
//TEST(DiagonalMatrix, MultiplyOnScalar) {
//    auto* matrix = new DiagonalMatrix<int>(pointer, 4);
//    auto* mult = matrix->MultiplyOnScalar(2);
//    EXPECT_EQ(mult->Get(1, 1), 4);
//    EXPECT_EQ(mult->Get(2, 2), 6);
//}
//
//TEST(DiagonalMatrix_complex, Tests) {
//    complex c1 = complex(1,5);
//    complex c2 = complex(3,9);
//    complex c3 = complex(-1,-3);
//    complex c4 = complex(-5,3);
//    complex c5 = complex(0,1);
//    complex c6 = complex(6,0);
//    complex c_arr[]={c1, c2, c3, c4, c5, c6};
//    complex *c_pointer = c_arr;
//    DiagonalMatrix<complex> matrixC = DiagonalMatrix<complex>(c_pointer, 6);
//    complex norm = matrixC.MatrixNorm<complex>();
//    EXPECT_TRUE(norm.real() - 2.58 < 0.01);
//    EXPECT_TRUE(norm.imag() - 4.32 < 0.01);
//}
//
//
//TEST(SquareMatrix, Constructor_1) {
//    SquareMatrix<int> matrix = SquareMatrix<int>();
//    EXPECT_EQ(matrix.GetSize(), 0);
//}
//
//TEST(SquareMatrix, Constructor_2) {
//    SquareMatrix<int> matrix = SquareMatrix<int>(pointer, 2);
//    EXPECT_EQ(matrix.GetSize(), 2);
//    EXPECT_EQ(matrix.Get(0, 0), 1);
//    EXPECT_EQ(matrix.Get(0, 1), 2);
//}
//
//TEST(SquareMatrix, GetSize) {
//    SquareMatrix<int> matrix = SquareMatrix<int>(pointer, 2);
//    EXPECT_EQ(matrix.GetSize(), 2);
//}
//
//TEST(SquareMatrix, Get) {
//    SquareMatrix<int> matrix = SquareMatrix<int>(pointer, 2);
//    EXPECT_EQ(matrix.Get(0, 0), 1);
//    EXPECT_EQ(matrix.Get(0, 1), 2);
//    EXPECT_EQ(matrix.Get(1, 1), 4);
//    EXPECT_THROW(matrix.Get(0, -1), out_of_range);
//}
//
//TEST(SquareMatrix, Set) {
//    SquareMatrix<int> matrix = SquareMatrix<int>(pointer, 2);
//    matrix.Set(12, 0, 0);
//    EXPECT_EQ(matrix.Get(0, 0), 12);
//    EXPECT_THROW(matrix.Set(12, -1, 3), out_of_range);
//}
//
//TEST(SquareMatrix, Norm) {
//    SquareMatrix<int> matrix = SquareMatrix<int>(pointer, 2);
//    EXPECT_TRUE(matrix.MatrixNorm<float>() - 5.47 < 0.01);
//}
//
//int a[] = {1};
//int *pointer3 = a;
//
//TEST(SquareMatrix, SumOfMatrix) {
//    auto* matrix1 = new SquareMatrix<int>(pointer, 2);
//    auto* matrix2 = new SquareMatrix<int>(pointer, 2);
//    auto* matrix3 = new SquareMatrix<int>(pointer3, 1);
//    auto* Sum = matrix1->SumOfMatrix(matrix2);
//    EXPECT_EQ(Sum->Get(0, 0), 2);
//    EXPECT_EQ(Sum->Get(0, 1), 4);
//    EXPECT_THROW(matrix1->SumOfMatrix(matrix3), length_error);
//}
//
//TEST(SquareMatrix, MultiplyOnScalar) {
//    auto* matrix = new SquareMatrix<int>(pointer, 2);
//    auto* mult = matrix->MultiplyOnScalar(2);
//    EXPECT_EQ(mult->Get(0, 0), 2);
//    EXPECT_EQ(mult->Get(1, 1), 8);
//    EXPECT_EQ(mult->Get(0, 1), 4);
//}
//
//TEST(SquareMatrix, MultiplyMatrix) {
//    auto* matrix1 = new SquareMatrix<int>(pointer, 2);
//    auto* matrix2 = new SquareMatrix<int>(pointer, 2);
//    auto* Sum = matrix1->MultiplyMatrix(matrix2);
//    EXPECT_EQ(Sum->Get(0, 0), 7);
//}
//
//TEST(SquareMatrix, AddRowToRow) {
//    auto* matrix = new SquareMatrix<int>(pointer, 2);
//    matrix->AddRowToRow(matrix, 1, 2);
//    EXPECT_EQ(matrix->Get(0, 0), 4);
//    EXPECT_EQ(matrix->Get(0, 1), 6);
//    EXPECT_THROW(matrix->AddRowToRow(matrix, -1, 2), out_of_range);
//}
//
//TEST(SquareMatrix, multiplyRow) {
//    auto* matrix = new SquareMatrix<int>(pointer, 2);
//    matrix->MultiplyRow(matrix, 1, 2);
//    EXPECT_EQ(matrix->Get(0, 0), 2);
//    EXPECT_EQ(matrix->Get(0, 1), 4);
//    EXPECT_THROW(matrix->MultiplyRow(matrix, -1, 2), out_of_range);
//}
//
//TEST(SquareMatrix, AddColToCol) {
//    auto* matrix = new SquareMatrix<int>(pointer, 2);
//    matrix->AddColToCol(matrix, 1, 2);
//    EXPECT_EQ(matrix->Get(0, 0), 3);
//    EXPECT_EQ(matrix->Get(1, 0), 7);
//    EXPECT_THROW(matrix->AddColToCol(matrix, -1, 2), out_of_range);
//}
//
//TEST(SquareMatrix, multiplyCol) {
//    auto* matrix = new SquareMatrix<int>(pointer, 2);
//    matrix->MultiplyCol(matrix, 1, 2);
//    EXPECT_EQ(matrix->Get(0, 0), 2);
//    EXPECT_EQ(matrix->Get(1, 0), 6);
//    EXPECT_THROW(matrix->MultiplyRow(matrix, -1, 2), out_of_range);
//}
