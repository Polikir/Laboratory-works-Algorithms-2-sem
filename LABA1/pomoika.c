//#include <stdio.h>
//
////int main(int argc, char* argv[])
////{
////    printf("Hello, World!\n");
////    return 0;
////}
//#include <string.h>
//#include <stdint.h>
//#include "array.h"
//#include "strings.h"
//
//const int len=100; //max length of string
//
////STRING ARRAY CREATION FUNCTIONS
//
////copying string to the right address
//
//void copyElement(dynArr * arr, int count, int* input)
//{
//    void *pointer = (int *) arr->element + count * arr->elementSize;
//    memcpy(pointer, input, arr->elementSize);
//    free(input);
//}
//
////input string
//
//void setInteger(dynArr *arr, int i)
//{
//    int* input = (int *) malloc(len * sizeof(int));
//    printf("String %d:", i+1);
//    gets(input);
//    return copyElement(arr, i, input);
//}
//
////allocating memory for an array
//
//dynArr* arrayCreate(int size, int elemSize)
//{
//    dynArr *arr = (dynArr *) malloc(sizeof(dynArr));
//    arr->size = size;
//    arr->elementSize = elemSize;
//    arr->element = (int*)malloc(size * elemSize);
//    for (int i = 0; i < size; i++) {
//        setString(arr, i);
//    }
//    return arr;
//}
//
//
////setting array and element size
//
//dynArr* declareIntArray()
//{
//    int size;
//    printf("Set string array size:");
//    scanf("%d", &size);
//    getchar();
//    int sizeElement = len*sizeof(int);
//    return arrayCreate(size, sizeElement);
//}
//
////PRINT STR ARRAY FUNC
//
//void printIntArray(dynArr * array)
//{
//    printf("---------------------------------\n");
//    printf("Your string array size %d", array->size);
//    printf("\n");
//    for (int i = 0; i < array->size; i++) {
//        printf("String %d:", i+1);
//        puts((int*)(array->element + i*array->elementSize));
//    }
//    printf("---------------------------------\n");
//}
//
