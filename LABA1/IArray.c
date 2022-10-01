#include <stdint.h>
#include "Array.h"
#include "IArray.h"





void copyElement(dynArr * arr, int count, int input)
{
    void *pointer = arr->element + count * arr->elementSize;
    memcpy(pointer, input, arr->elementSize);
    free(input);
}


dynArr* arrayCreate(int size, int elemSize)
{
    dynArr *arr = (dynArr *) malloc(sizeof(dynArr));
    arr->size = size;
    arr->elementSize = elemSize;
    arr->element = (int*)malloc(size * elemSize);
    for (int i = 0; i < size; i++) {
        setInteger(arr, i);
    }
    return arr;
}


void setInteger(dynArr *arr, int i)
{
    int input;
    printf("Integer number %d:", i+1);
    scanf("%d",&input);
    return copyElement(arr, i, &input);
}

dynArr* declareIntArray()
{
    int size;
    printf("Enter the size of the Integer array:");
    scanf("%d", &size);
    int sizeElement = sizeof(int);

    return arrayCreate(size, sizeElement);
}



void printIntArray(dynArr * array)
{   int *t;
    printf("---------------------------------\n");
    printf("Your integer array size: %d", array->size);
    printf("\n");
    for (int i = 0; i < array->size; i++) {
        t = array->element + i*array->elementSize;
        printf("%d \n",*t);
    }
    printf("---------------------------------\n");
}

void* plus_1(int* elem)
{   int* number = (int *) malloc(sizeof(int));
    *number = *elem+1;
    return number;

}

void* mult_2(int *elem)
{
    int* number = (int *) malloc(sizeof(int));
    *number = *elem*2;
    return number;
}

void* minus_1(int *elem)
{
    int* number = (int *) malloc(sizeof(int));
    *number = *elem-1;
    return number;
}

void* square(int *elem)
{
    int* number = (int *) malloc(sizeof(int));
    *number = (*elem)*(*elem);
    return number;
}



int more_2(int *elem)
{
    return (*elem>2) ? 1 : 0;
}

int less_100(int *elem)
{
    return (*elem<100) ? 1 : 0;
}

































































































////funcs for creating a string array with user's input
//void copyElement(dynArr * arr, int count, char* input);
//void setCompl(dynArr *arr, int i);
//dynArr* arrayCreate(int size, int elemSize);
//dynArr* declareComplArray();
//
//
////funcs to print str array
//void printComplArray(dynArr * array);
//
////func to use with map
//void* plus1(void* elem);//void* reverseStr(void* elem);
//void* minus1(void* elem);//void* reverseStr(void* elem);
//void* mult2(void* elem);//void* reverseStr(void* elem);
//void* abs(void* elem);
//
//
////func to use with where
//int more0(void* elem);
//int absmore20(void* elem);
