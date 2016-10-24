#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_tests.h"

#define max_tests (2)

int test_sort_number()
{
    int high_input[max_tests] =    {5341, 9831 };
    int high_expected[max_tests] = {5431, 9831 };

    int low_input[max_tests] =    {5341, 9831 };
    int low_expected[max_tests] = {1345, 1389 };

    int fail_count = 0;
    
    int i = 0;
    for(i = 0; i < sizeof(high_input)/sizeof(int); i++)
    { 
        if( sort_number(high_input[i], HIGH) != high_expected[i] )
        {
            printf("FAILURE: sort_number on HIGH\n");
            printf("i: %d\n", high_input[i]);
            printf("e: %d\n", high_expected[i]);
            printf("r: %d\n", sort_number(high_input[i], HIGH) );
            fail_count++; 
        }
        else
        {
            printf("sort_number on HIGH: PASS\n");
        }
    }

    int j = 0;
    for(j = 0; j < sizeof(low_input)/sizeof(int); j++)
    {
        if( sort_number(low_input[j], LOW) != low_expected[j] )
        {
            printf("FAILURE: sort_number on LOW\n");
            printf("i: %d\n", low_input[j]);
            printf("e: %d\n", low_expected[j]);
            printf("r: %d\n", sort_number(low_input[j], LOW) );
            fail_count++; 
        }
        else
        {
            printf("sor_number on LOW: PASS\n");
        }
    }

    return fail_count;

}

int test_run_routine(int num)
{

}

int test_get_number()
{

}


void test_all()
{
    printf( "\n\n ----------TESTING SORT_NUMBER---------- \n\n");
    printf( "\n\nfail_count for sort number: %d\n", test_sort_number() );
}
