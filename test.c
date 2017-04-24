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
/*
int arr[10] = {5, 4};

printf("SIZE OF ARRAY: %ld\n", sizeof(arr)/sizeof(int) );

return 0;
*/

printf("Enter four digit integer: \n");

int i = 0;
char ch;
char str[5];

for( ch = getchar(); ch != '\n'; ch = getchar() )
{
    //character falls outside digit ascii values
    if( ch < 48 || ch > 57 )
    {
        printf("Invalid input: not number\n");
        break;
    }
    else
    {
        str[ i++ ] = ch;
    }
    str[ i ] = '\0';
}
if( i < 4 )
{
    printf("Invalid input\n");
}
else
{
    int result = (int) strtol(str, NULL, 10); 
    printf("Result: %d\n", result);
}



}
