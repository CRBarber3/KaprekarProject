#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "CUnit-2.1-3/CUnit/Headers/Basic.h"

#define HIGH   (4321)
#define LOW    (1234)
#define DIGITS (4)

/***************DEV NOTES**********************

-- Does not add leading zeros (doesn't work for
   small inputs)

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
Does not account for decimal (5.5)
*/
int get_number()
{
    int var = -1;

    while( var <= 0 || var > 9999 )
    {
        printf("Input a four digit integer: \n");
        scanf("%i", &var);

        if( var == -1 )
        {
            break;
        }
    }

    return(var);
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
    char sorted_str[DIGITS + 1] = ""; //used to store the sorted string of digits
    char str[DIGITS + 1];        //used to store the number as a string
    sprintf(str, "%d", num);     //convert number to string
    
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
    int result = strtol(sorted_str, NULL, 10); 

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
    int diff = 0;
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
    }

    return runs;
}

int main()
{
    printf("Enter -1 to quit\n\n\n");

    int input = get_number();
    int runs = 0;

    while( input != -1 )
    {
        runs = run_routine( input );
        printf("runs: %i\n", runs);
    
        input = get_number();
    }
    
    return 0;
}
