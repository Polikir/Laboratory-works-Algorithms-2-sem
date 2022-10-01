#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "Array.h"
#pragma once


typedef struct Complex_number{
    int re;
    int im;
}com_num;


void copyElementc(dynArr * arr, int count, com_num * input);
void setComplex(dynArr *arr, int i);
dynArr* arrayCreatec(int size, int elemSize);
dynArr* declareComArray();


void printIntArray(dynArr * array);


void* plus_1c(com_num* elem);
void* minus_1c(com_num* elem);
void* mult_2c(com_num* elem);
void* squarec(com_num* elem);


int more_2c(com_num* elem);
int less_100c(com_num* elem);
