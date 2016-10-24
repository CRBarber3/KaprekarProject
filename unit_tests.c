#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_tests.h"

int test_sort_number(/*int num, int how*/)
{
    int fail_count = 0;
    
    if( sort_number(5341, HIGH) != 5431 )
    {
        printf("FAILURE: sort_number on HIGH\n");
        printf("i: %d\n", 5341);
        printf("e: %d\n", 5431);
        printf("r: %d\n", sort_number(5241, HIGH) );
        fail_count++; 
    }

    if( sort_number(9831, HIGH) != 9831 )
    {
        printf("FAILURE: sort_number on HIGH\n");
        printf("i: %d\n", 9831);
        printf("e: %d\n", 9831);
        printf("r: %d\n", sort_number(9831, HIGH) );
        fail_count++; 
    }

    if( sort_number(9831, LOW) != 1389 )
    {
        printf("FAILURE: sort_number on LOW\n");
        printf("i: %d\n", 9831);
        printf("e: %d\n", 1389);
        printf("r: %d\n", sort_number(9831, LOW) );
        fail_count++; 
    }

    return fail_count;

}

int test_run_routine(int num)
{

}

int test_get_number()
{

}
