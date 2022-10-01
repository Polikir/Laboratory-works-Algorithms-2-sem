#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#pragma once

typedef struct dynArray{
    int size;
    void *element;
    int elementSize;
}dynArr;

dynArr* concatArray(dynArr *arr1, dynArr *arr2 );



dynArr* mapArray(void* (*function)(void*), dynArr *arr1);



dynArr* whereArray(int (*condition)(void*), dynArr *arr1);


