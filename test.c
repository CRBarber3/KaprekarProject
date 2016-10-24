#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
/*
int input = 5;

while( input < 1000 )
{
    input *= 10;
}

char str[5];

sprintf(str, "%d", input);

printf("CONVERTED TO STR: %s\n", str);
*/

int arr[10] = {5, 4};

printf("SIZE OF ARRAY: %ld\n", sizeof(arr)/sizeof(int) );

return 0;

}
