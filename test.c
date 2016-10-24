#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

int input = 5;

while( input < 1000 )
{
    input *= 10;
}

char str[5];

sprintf(str, "%d", input);

printf("CONVERTED TO STR: %s\n", str);

return 0;

}
