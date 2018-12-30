#include <stdbool.h>
#include <stdio.h>

typedef unsigned int _ui;

bool IsUglyNumber(_ui number);

int UglyNumber_Demo()
{
   printf("Is 300: %d \r\n",IsUglyNumber(299));
   return 0;
}

_ui DivideArg1ByGreatestDivisiblePowerOfArg2(_ui arg1, _ui arg2)
{
    while(arg1 % arg2 == 0)
    {
        arg1 /= arg2;
    }
    return arg1;
}

bool IsUglyNumber(_ui number)
{
    number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 2); number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 3);
    number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 5);
    return number == 1 ? true : false;
}
