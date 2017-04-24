#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_tests.h"
//#include "CUnit-2.1-3/CUnit/Headers/Basic.h"


/***************DEV NOTES**********************

-- Does not add leading zeros (doesn't work for
   small inputs) --working

-- Input not validated properly

-- Format output better

-- Allow user to enter other options to get 
   further data about the routine instance
   (difficult because getting integer)
   (may start new project with string input)

-- Test function which outputs stats
     (number of inputs checked)
     (stats of numbers of each run value)

-- CUnit test integration

**********************************************/



/*
Gets input as string; converts to int if input is correct
Returns -1 if 'quit' is entered
*/
int get_number()
{
    int var = -1;

    while( var <= 0 || var > 9999 )
    {
        printf("Input a four digit integer: \n");

        var = -1;
        int i = 0;
        char ch = '\0';
        char str[MAX_CHARS];

        for( ch = getchar(); ch != '\0' && ch != '\n'; ch = getchar() )
        {
            str[ i++ ] = ch;
            str[ i ] = '\0';
        }

        //stop immediately if user enters quit
        if( strcmp(str, "quit") == 0 )
        {
            return var;
        }

        //check string is proper length
        if( strlen(str) > DIGITS )
        {
            printf("Invalid input: inproper length\n");
            var = -2;
        }

        //check that every character entered is a number
        int j = 0;
        for( j = 0; j < strlen(str); j++ )
        {
            //character falls outside digit ascii values
            if( str[j] < 48 || str[j] > 57 )
            {
                printf("Invalid input: not integer\n");
                var = -2;                
                break;
            }
        }

        if( var != -2 )
        {
            var = (int) strtol(str, NULL, 10);
        } 
    }
    
    return var;
}

/*
Sorts an input integers digits.
  how --
      -- HIGH --> high to low (descending)
      -- LOW  --> low to high (ascending)
Returns the sorted integer.
*/
int sort_number(int num, int how)
{

    //add zeros if number is < 4 digits long
    while( num < 1000 )
    {
        num *= 10;
    }

    char sorted_str[DIGITS + 1] = ""; //used to store the sorted string of digits
    char str[DIGITS + 1];        //used to store the number as a string
    sprintf(str, "%d", num);     //convert number to string

    //printf("THE STRING: %s\n", str); 
    char target = str[0]; //used to store the current target digit (largest for HIGH, smallest for LOW)
    int remove_index = -1; //used to store the index of the largest digit (to be removed)

    /*
    Loop until string is consumed
    */
    while( str[0] != '\0' )
    {
        target = str[0]; //reset target
        remove_index = 0; //reset index

        // Find target digit in string and it's index
        int i;
        for( i = 0; str[i] != '\0'; i++)
        {
            if( how == HIGH && str[i] > target ||
                how == LOW && str[i] < target
              )
            {
                target = str[i];
                remove_index = i;
            }
        }

        //Remove target digit from original string
        int c;
        for( c = remove_index; c < strlen(str); c++ )
        {
            str[c] = str[c + 1];
        }
        str[strlen(str)] = '\0';

        //Add target to back of sorted list
        sorted_str[ strlen(sorted_str) ] = target;
        sorted_str[ strlen(sorted_str) ] = '\0'; 
    }
    
    //convert to integer
    int result = (int) strtol(sorted_str, NULL, 10); 
    return result;
}

/*
Preforms Kaprekar's routine and retunrs the number of 
times the routine had to be run to start looping.
This looping point means Kaprekar's constant has been reached.
*/
int run_routine(int num)
{
    int runs = 0;
    int diff = -1;
    int diff_prev = num;

    int s1 = sort_number(diff_prev, HIGH);
    int s2 = sort_number(diff_prev, LOW);

    diff = s1 - s2;

    while( diff != diff_prev )
    {
        diff_prev = diff;

        s1 = sort_number(diff_prev, HIGH);
        s2 = sort_number(diff_prev, LOW);

        diff = s1 - s2;

        runs++;
        printf("diff: %d\n", diff);
    }

    return runs;
}

int main(int argc, char **argv)
{
    //run test functionality by including "test"
    //as a command line argument
    if( argc > 1 && strcmp(argv[1], "test") == 0 )
    {
        test_all();
    }
    else
    {
        printf("Type quit to quit\n\n\n");

        int input = get_number();
        int runs = 0;

        while( input != -1 )
        {
            runs = run_routine( input );
            printf("runs: %i\n", runs);
        
            input = get_number();
        }
    }  

    return 0;
}

