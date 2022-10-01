#include "test.h"

void test1()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    int *num = (int *) malloc(sizeof(int));
    *num = -5;
    arrt->elementSize = sizeof(int);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        *num=*num+1;
    };
    printf("            Test 1\n");
    printf("----------------------------\n");
    printf("|  Map(+1) for integer numbers  |\n");
    printf("--------------------------------\n");
    printf("|       Input Data              |\n");
    printIntArray(arrt);
    printf("|       Output Data             |\n");
    dynArr *arrto = mapArray(plus_1,arrt);
    printIntArray(arrto);
    printf("|       Correct Data            |\n");
    printf("-4\n-3\n-2\n-1\n0\n1\n2\n");
};


void test2()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    int *num = (int *) malloc(sizeof(int));
    *num = -5;
    arrt->elementSize = sizeof(int);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        *num=*num+1;
    };
    printf("            Test 2\n");
    printf("----------------------------\n");
    printf("|Map(Square) for integer numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printIntArray(arrt);
    printf("|       Output Data         |\n");
    dynArr *arrto = mapArray(square,arrt);
    printIntArray(arrto);
    printf("|       Correct Data        |\n");
    printf("25\n16\n9\n4\n1\n0\n1\n");
};


void test3()
{
    dynArr *arrt1 = malloc(sizeof(dynArr));
    dynArr *arrt2 = malloc(sizeof(dynArr));
    int *num = (int *) malloc(sizeof(int));
    *num = 1;
    arrt1->elementSize = sizeof(int);
    arrt1->size = 7;
    arrt1->element = malloc(arrt1->size*arrt1->elementSize);
    arrt2->elementSize = sizeof(int);
    arrt2->size = 7;
    arrt2->element = malloc(arrt2->size*arrt2->elementSize);
    for(int i=0;i<arrt1->size;i++)
    {
        memcpy(arrt1->element+ i*arrt1->elementSize,num, arrt1->elementSize);
        *num=*num+1;
    };
    for(int i=0;i<arrt2->size;i++)
    {
        memcpy(arrt2->element+ i*arrt2->elementSize,num, arrt2->elementSize);
        *num=*num-1;
    };
    printf("            Test 3\n");
    printf("----------------------------\n");
    printf("|Ñoncatenation for integer numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printIntArray(arrt1);
    printIntArray(arrt2);
    printf("|       Output Data         |\n");
    dynArr *arrto = concatArray(arrt1,arrt2);
    printIntArray(arrto);
    printf("|       Correct Data        |\n");
    printf("1\n2\n3\n4\n5\n6\n7\n8\n7\n6\n5\n4\n3\n2\n");
};



void test4()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    int *num = (int *) malloc(sizeof(int));
    *num = -1;
    arrt->elementSize = sizeof(int);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        *num=*num+1;
    };
    printf("            Test 4\n");
    printf("----------------------------\n");
    printf("|Where(>2) for integer numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printIntArray(arrt);
    printf("|       Output Data         |\n");
    dynArr *arrto = whereArray(more_2,arrt);
    printIntArray(arrto);
    printf("|       Correct Data        |\n");
    printf("3\n4\n5\n");
};


void test5()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    com_num *num = (com_num *) malloc(sizeof(com_num));
    num->re = 0;
    num->im = 0;
    arrt->elementSize = sizeof(com_num);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        num->im += 1;
    };
    printf("            Test 5\n");
    printf("----------------------------\n");
    printf("|  Map(+1) for complex numbers  |\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printComArray(arrt);
    printf("|       Output Data         |\n");
    dynArr *arrto = mapArray(plus_1c,arrt);
    printComArray(arrto);
    printf("|       Correct Data        |\n");
    printf("1 0i\n1 1i\n1 2i\n1 3i\n1 4i\n1 5i\n1 6i\n");
};



void test6()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    com_num *num = (com_num *) malloc(sizeof(com_num));
    num->re = 1;
    num->im = 2;
    arrt->elementSize = sizeof(com_num);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        num->im += 1;
    };
    printf("            Test 6\n");
    printf("----------------------------\n");
    printf("|Map(Square) for complex numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printComArray(arrt);
    printf("|       Output Data         |\n");
    dynArr *arrto = mapArray(squarec,arrt);
    printComArray(arrto);
    printf("|       Correct Data        |\n");
    printf("-3 4i\n-8 6i\n-15 8i\n-24 10i\n-35 12i\n-48 14i\n-63 16i\n");
};



void test7()
{
    dynArr *arrt = malloc(sizeof(dynArr));
    com_num *num = (com_num *) malloc(sizeof(com_num));
    num->re = 0;
    num->im = 2;
    arrt->elementSize = sizeof(com_num);
    arrt->size = 7;
    arrt->element = malloc(arrt->size*arrt->elementSize);
    for(int i=0;i<arrt->size;i++)
    {
        memcpy(arrt->element+ i*arrt->elementSize,num, arrt->elementSize);
        num->re+=1;
    };
    printf("            Test 7\n");
    printf("----------------------------\n");
    printf("|Where(Real>2) for integer numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printComArray(arrt);
    printf("|       Output Data         |\n");
    dynArr *arrto = whereArray(more_2c,arrt);
    printComArray(arrto);
    printf("|       Correct Data        |\n");
    printf("3 2i\n4 2i\n5 2i\n6 2i\n");
};

void test8()
{
    dynArr *arrt1 = malloc(sizeof(dynArr));
    dynArr *arrt2 = malloc(sizeof(dynArr));
    com_num *num = (com_num *) malloc(sizeof(com_num));
    num->re = 1;
    num->im = 1;
    arrt1->elementSize = sizeof(com_num);
    arrt1->size = 7;
    arrt1->element = malloc(arrt1->size*arrt1->elementSize);
    arrt2->elementSize = sizeof(com_num);
    arrt2->size = 7;
    arrt2->element = malloc(arrt2->size*arrt2->elementSize);
    for(int i=0;i<arrt1->size;i++)
    {
        memcpy(arrt1->element+ i*arrt1->elementSize,num, arrt1->elementSize);
        num->re+=2;
        num->im+=1;
    };
    for(int i=0;i<arrt2->size;i++)
    {
        memcpy(arrt2->element+ i*arrt2->elementSize,num, arrt2->elementSize);
        num->re-=2;
        num->im-=1;
    };
    printf("            Test 8\n");
    printf("----------------------------\n");
    printf("|Concatenation for complex numbers|\n");
    printf("--------------------------------\n");
    printf("|       Input Data          |\n");
    printComArray(arrt1);
    printComArray(arrt2);
    printf("|       Output Data         |\n");
    dynArr *arrto = concatArray(arrt1,arrt2);
    printComArray(arrto);
    printf("|       Correct Data        |\n");
    printf("1 1i\n3 2i\n5 3i\n7 4i\n9 5i\n11 6i\n13 7i\n15 8i\n13 7i\n11 6i\n9 5i\n7 4i\n5 3i\n3 2i\n");
};


