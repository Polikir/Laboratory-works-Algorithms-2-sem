#include "Array.h"




dynArr* concatArray(dynArr *arr1, dynArr *arr2 )
{
    dynArr *arr3 = malloc(sizeof(dynArr));
    arr3->elementSize = arr1->elementSize;
    arr3->size = arr1->size+arr2->size;
    arr3->element = malloc(arr3->size*arr3->elementSize);
    for (int i =0; i<arr1->size; i++)
    {
        void *pointer =  arr3->element + i * arr3->elementSize;
        memcpy(pointer,  arr1->element+i*arr1->elementSize, arr1->elementSize);
    }
    for (int i=0; i<arr2->size; i++)
    {
        void *pointer =  arr3->element + i * arr3->elementSize + arr1->elementSize*arr1->size;
        memcpy(pointer,  arr2->element+ i*arr2->elementSize, arr2->elementSize);
    }
    return arr3;
}



dynArr* mapArray(void* (*function)(void *), dynArr *arr1)
{
    dynArr *arr2 = malloc(sizeof(dynArr));
    arr2->size = arr1->size;
    arr2->elementSize = arr1->elementSize;
    arr2->element = malloc(arr2->size*arr2->elementSize);
    for (int i=0; i<arr1->size; i++)
    {
        void *elem = malloc(arr1->elementSize);
        memcpy(elem, arr1->element+i*arr1->elementSize, arr1->elementSize);
        void *result = malloc(arr1->elementSize);
        void *a = arr1->element+i*arr1->elementSize;
        result = function(a);
        memcpy(arr2->element+i*arr2->elementSize, result, arr1->elementSize);
        free(elem);
        free(result);
    }
    return arr2;
}



dynArr* whereArray(int (*condition)(void*), dynArr *arr1)
{
    dynArr *arr2 = malloc(sizeof(dynArr));
    int count = 0;
    arr2->elementSize = arr1->elementSize;
    arr2->element = malloc(arr1->size*arr1->elementSize);
    for (int i=0; i<arr1->size; i++)
    {
        void* elem = malloc(arr1->elementSize);
        memcpy(elem, arr1->element+i*arr1->elementSize, arr1->elementSize);
        void* u = (arr1->element+i*arr1->elementSize);
        if (condition(u) == 1)
        {
            memcpy(arr2->element+count*arr2->elementSize, elem, arr1->elementSize);
            count++;
        }
        free(elem);
    }
    arr2->size = count;
    arr2->element = realloc(arr2->element, count*arr2->elementSize);
    return arr2;
}
