#include "menu.h"

int choose() {
    int choice;
    printf("Enter a number:");
    scanf("%d", &choice);
    return choice;
}

void start()
{
    printf(":'######:'########:::'###:::'########:'########::::::::::::'##:::::::::'###:::'########::::'###::::::::'##:::\n");
    printf("'##... ##... ##..:::'## ##:::##.... ##... ##..::::::::::::::##::::::::'## ##:::##.... ##::'## ##:::::'####:::\n");
    printf(" ##:::..:::: ##::::'##:. ##::##:::: ##::: ##::::::::::::::::##:::::::'##:. ##::##:::: ##:'##:. ##::::.. ##:::\n");
    printf(" .######:::: ##:::'##:::. ##:########:::: ##::::::::::::::::##::::::'##:::. ##:########:'##:::. ##::::: ##::: \n");
    printf(":..... ##::: ##::::#########:##.. ##::::: ##::::::::::::::::##:::::::#########:##.... ##:#########::::: ##:::\n");
    printf("'##::: ##::: ##::::##.... ##:##::. ##:::: ##::::::::::::::::##:::::::##.... ##:##:::: ##:##.... ##::::: ##:::\n");
    printf(". ######:::: ##::::##:::: ##:##:::. ##::: ##::::::::::::::::########:##:::: ##:########::##:::: ##:::'######:\n");
    printf(":......:::::..::::..:::::..:..:::::..::::..::::::::::::::::........:..:::::..:........::..:::::..::::......::\n");
};

void end()
{
   printf("'########::'##::: ##::::'########::\n");
   printf(" ##.....::::###:: ##:::::##.... ##:\n");
   printf(" ##:::::::::####: ##:::::##:::: ##:\n");
   printf(" ######:::::## ## ##:::::##:::: ##:\n");
   printf(" ##...::::::##. ####:::::##:::: ##:\n");
   printf(" ##:::::::::##:. ###:::::##:::: ##:\n");
   printf(" ########:::##::. ##:::::########::\n");
   printf(" ........:::..::::..:::::........:::\n");
}

void menu()
{   start();
    printf("Choose data type\n");
    printf("1 - Integer\n");
    printf("2 - Complex\n");
    printf("3 - Test\n");
    int c = choose();
    if (c==1)
    {
        dynArr* array1 = declareIntArray();
        printf("\n");
        printf("Choose function:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concatenation\n");
        printf("\n");
        int b = choose();
        if (b==1)
        {
            printf("Choose map function\n");
            printf("1 - Plus 1\n");
            printf("2 - Minus 1\n");
            printf("3 - Multiplication on 2\n");
            printf("4 - Square\n");
            int a = choose();
            if (a==1)
            {
                    printf("Map function: Plus 1\n");
                    dynArr* array2 = mapArray(*plus_1, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printIntArray(array2);
                    }
            }
            if (a==2)
            {
                    printf("Map function: Minus 1\n");
                    dynArr* array2 = mapArray(*minus_1, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printIntArray(array2);
                    }

            }
            if (a==3)
            {
                    printf("Map function: Multiplication on 2 1\n");
                    dynArr* array2 = mapArray(*mult_2, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printIntArray(array2);
                    }

            }
            if (a==4)
            {
                    printf("Map function: Square \n");
                    dynArr* array2 = mapArray(*square, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printIntArray(array2);
                    }
            }
        }
        else if (b==2)
        {   printf("Choose where type\n");
            printf("1 - Checks if number  more than 2\n");
            printf("2 - Checks if number  less than 100\n");
            int d = choose();
            if (d==1)
            {   printf("Where function: Checks if number  more than 2\n");
                dynArr* array2 = whereArray(*more_2, array1);
                printf("Done\n");
                printf("\n");
                printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                if (choose()==1) {
                    printIntArray(array2);

                }

            };
            if (d==2)
            {   printf("Where function: Checks if number  less than 100\n");
                dynArr* array2 = whereArray(*less_100, array1);
                printf("Done\n");
                printf("\n");
                printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                if (choose()==1) {
                    printIntArray(array2);
                }
            };
        }
        else if (b==3)
        {
            printf("Make another array for concatenation\n");
            dynArr* array2 = declareIntArray();
            printf("Starting concatenation...\n");
            dynArr* array3 = concatArray(array1, array2);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1)
            {
                printIntArray(array3);
            }
        }
    }
    else if (c==2)
    {
        dynArr* array1 = declareComArray();
        printf("\n");
        printf("Choose function:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concatenation\n");
        printf("\n");
        int e = choose();
        if (e==1)
        {
            printf("Choose map type\n");
            printf("1 - Plus real 1\n");
            printf("2 - Minus real 1\n");
            printf("3 - Multiplication 2\n");
            printf("4 - Square\n");
            int f = choose();
            if (f==1)
            {
                    printf("Map function: Plus 1\n");
                    dynArr* array2 = mapArray(*plus_1c, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printComArray(array2);
                    }

            }
            if (f==2)
            {
                    printf("Map function: Minus 1\n");
                    dynArr* array2 = mapArray(*minus_1c, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printComArray(array2);
                    }

            }
            if (f==3)
            {
                    printf("Map function: Multiplication on 2 1\n");
                    dynArr* array2 = mapArray(*mult_2c, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printComArray(array2);
                    }
            }
            if (f==4)
            {
                    printf("Map function: Square \n");
                    dynArr* array2 = mapArray(*squarec, array1);
                    printf("Done\n");
                    printf("\n");
                    printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                    if (choose()==1)
                    {
                        printComArray(array2);
                    }
            }
        }
        else if (e==2)
        {   printf("Choose where type\n");
            printf("1 - Checks if real number  more than 2\n");
            printf("2 - Checks if real number  less than 100\n");
            int g = choose();
            if (g==1)
            {
                printf("Where function: Checks if number  more than 2\n");
                dynArr* array2 = whereArray(*more_2c, array1);
                printf("Done\n");
                printf("\n");
                printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                if (choose()==1) {
                    printComArray(array2);
                }
            };
            if (g==2)
            {
                printf("Where function: Checks if real number  less than 100\n");
                dynArr* array2 = whereArray(*less_100c, array1);
                printf("Done\n");
                printf("\n");
                printf("Do you want to print your array? 1 - Yes, 0 - No\n");
                if (choose()==1) {
                    printComArray(array2);
                }
            };
        }
        else if (e==3)
        {
            printf("Make another array for concatenation\n");
            dynArr* array2 = declareComArray();
            printf("Starting concatenation...\n");
            dynArr* array3 = concatArray(array1, array2);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1)
            {
                printComArray(array3);
            }

        }
    };
    if (c==3)
    {
        printf("Choose map type\n");
        printf("1 - Test 1 \n");
        printf("2 - Test 2 \n");
        printf("3 - Test 3 \n");
        printf("4 - Test 4\n");
        printf("5 - Test 5 \n");
        printf("6 - Test 6 \n");
        printf("7 - Test 7 \n");
        printf("8 - Test 8\n");
        int q = choose();
        if (q==1){test1();}else if (q==2){test2();}else if (q==3){test3();}else if (q==4){test4();}else if (q==5){test5();}else if (q==6){test6();}else if (q==7){test7();}else if (q==8){test8();}

    };
    end();
};

