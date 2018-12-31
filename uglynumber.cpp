#include <stdbool.h>
#include <stdio.h>
#include <timer.h>
typedef unsigned int _ui;
#define xDP

#ifndef DP
bool IsUglyNumber(_ui number);
#else
_ui Cache[3000];
_ui min(_ui a, _ui b, _ui c)
{
    if(a < b)
    {
        return a < c ? a : c;
    }
    else
    {
        return b < c ? b : c;
    }
}
#endif
_ui GetNthUglyNumber(_ui n);

int UglyNumber_Demo()
{
   printf("Starting\r\n");
   Timer *pTimer = new Timer();
   _ui n = 999;
   printf("%dth ugly number is %d\r\n", n, GetNthUglyNumber(n));
   printf("End, elapsed time = %f ms\r\n", pTimer->elapsed() );
   return 0;
}

_ui GetNthUglyNumber(_ui n)
{
#ifndef DP
    _ui i = 1;
    _ui count = 1;   /* ugly number count */
    /*Check for all integers until ugly count
      becomes n*/
    while (n > count)
    {
      i++;
      if (IsUglyNumber(i))
        count++;
    }
    return i;
#else
    _ui i2 = 0;
    _ui i3 = 0;
    _ui i5 = 0;
    Cache[0] = 1;
    _ui count = 1;
    while(n > count)
    {
        _ui NextMultiply2 = 2 * Cache[i2];
        _ui NextMultiply3 = 3 * Cache[i3];
        _ui NextMultiply5 = 5 * Cache[i5];
        _ui NextUgly = min(NextMultiply2, NextMultiply3, NextMultiply5);
        if(NextUgly == Cache[count - 1])
        {
            count = count - 1;
        }
        Cache[count] = NextUgly;

        count++;
        if(NextMultiply2 == NextUgly)
        {
            i2++;
        }
        else if(NextMultiply3 == NextUgly)
        {
            i3++;
        }
        else
        {
            i5++;
        }
    }
    return Cache[n - 1];
#endif
}

#ifndef DP
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
    number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 2);
    number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 3);
    number = DivideArg1ByGreatestDivisiblePowerOfArg2(number, 5);
    return number == 1 ? true : false;
}
#else
#endif
