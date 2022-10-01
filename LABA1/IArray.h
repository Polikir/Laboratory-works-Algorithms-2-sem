#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "Array.h"


void copyElement(dynArr * arr, int count, int input);
void setInteger(dynArr *arr, int i);
dynArr* arrayCreate(int size, int elemSize);
dynArr* declareIntArray();
void printIntArray(dynArr * array);


void* plus_1(int *elem);
void* minus_1(int *elem);
void* mult_2(int *elem);
void* square(int *elem);


int more_2(int *elem);
int less_100(int *elem);
