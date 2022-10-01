#include <stdint.h>
#include "Array.h"
#include "CArray.h"
#pragma once






void copyElementc(dynArr * arr, int count, com_num * input)
{
    void *pointer = arr->element + count * arr->elementSize;
    memcpy(pointer, input, arr->elementSize);
    free(input);
}

void setComplex(dynArr *arr, int i)
{
    com_num* input = (com_num *) malloc(sizeof(com_num));
    printf("Complex number %d:", i+1);
    int re1,im1;
    scanf("%d %di",&re1,&im1);
    input->im = im1;
    input->re = re1;
    return copyElementc(arr, i, input);
}



dynArr* arrayCreatec(int size, int elemSize)
{
    dynArr *arr = (dynArr *) malloc(sizeof(dynArr));
    arr->size = size;
    arr->elementSize = elemSize;
    arr->element = (com_num*)malloc(size * elemSize);
    for (int i = 0; i < size; i++) {
        setComplex(arr, i);
    }
    return arr;
}




dynArr* declareComArray()
{
    int size;
    printf("Enter the size of the complex array:");
    scanf("%d", &size);
    int sizeElement = sizeof(com_num);

    return arrayCreatec(size, sizeElement);
}



void printComArray(dynArr * array)
{   com_num *t;
    printf("-----------------------------\n");
    printf("Your complex array size: %d\n", array->size);
    printf("Enter the numbers in the format: a b for (a + bi)\n");
    for (int i = 0; i < array->size; i++) {
        t = array->element + i*array->elementSize;
        printf("%d %di\n",t->re,t->im);
    }
    printf("-----------------------------\n");
}

void* plus_1c(com_num* elem)
{
    com_num* pom = (com_num *) malloc(sizeof(com_num));
    pom->re = elem->re+1;
    pom->im = elem->im;
    return pom;
}

void* mult_2c(com_num* elem)
{
    com_num* pom = (com_num *) malloc(sizeof(com_num));
    pom->re = elem->re*2;
    pom->im = elem->im*2;
    return pom;
}

void* minus_1c(com_num* elem)
{
    com_num* pom = (com_num *) malloc(sizeof(com_num));
    pom->re = elem->re-1;
    pom->im = elem->im;
    return pom;
}

void* squarec(com_num* elem)
{
    com_num* pom = (com_num *) malloc(sizeof(com_num));
    pom->re = (elem->re)*(elem->re)-(elem->im)*(elem->im);
    pom->im = 2*(elem->im)*(elem->re);
    return pom;
}



int more_2c(com_num* elem)
{
    return (elem->re>2) ? 1 : 0;
}

int less_100c(com_num* elem)
{
    return (elem->re<100) ? 1 : 0;
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
