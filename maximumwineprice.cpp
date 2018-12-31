#include <stdio.h>
#include <vector>

unsigned int winePrice(unsigned int *pStart, unsigned int *pLeftMost, unsigned int *pRightMost, unsigned int yearMultiplier);

#define SPEED
#ifdef SPEED
unsigned int MaximumWinePriceCache[50][50];
#else
unsigned int MaximumWinePriceCache[5][5];
#endif
int MaximumWinePrice_Demo()
{
    printf("Dynamic programming\r\n");
#ifdef SPEED
    unsigned int p[50] = { 2, 3, 5 , 1, 4, 6, 1, 2 ,3, 10, 11, 12 ,13 ,14, 2, 3, 5 , 1, 4, 6, 1, 2 ,3, 10,15, \
                           2, 3, 5 , 1, 4, 6, 1, 2 ,3, 10, 11, 12 ,13 ,14, 2, 3, 5 , 1, 4, 6, 1, 2 ,3, 10,15};
#else
    unsigned int p[5] = { 2, 3, 5 , 1, 4 };
#endif
    unsigned int NMaximumWinePriceCacheElements = sizeof(MaximumWinePriceCache) / sizeof(unsigned int);
    unsigned int NEachRowElements = sizeof(MaximumWinePriceCache[0]) / sizeof(unsigned int);
    printf("NElements %d - ", NMaximumWinePriceCacheElements);
    printf("Each row %d \r\n", NEachRowElements);
    for(unsigned int i = 0; i < NMaximumWinePriceCacheElements; i++)
    {
        MaximumWinePriceCache[i / NEachRowElements][i % NEachRowElements] = 0;
    }

    printf("price: %d\r\n", winePrice(p, p, p + sizeof(p) / sizeof(unsigned int) - 1, 1));
    return 0;
}

inline
unsigned int max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

unsigned int winePrice(unsigned int *pStart, unsigned int *pLeftMost, unsigned int *pRightMost, unsigned int yearMultiplier)
{
    long be = pLeftMost - pStart;
    long en = pRightMost - pStart;
    if(MaximumWinePriceCache[be][en] == 0)
    {
        if(pRightMost == pLeftMost)
        {
            MaximumWinePriceCache[be][en] = *pLeftMost * yearMultiplier;
        }
        else
        {
            unsigned int leftmost = *pLeftMost;
            unsigned int rightmost = *pRightMost;
            unsigned int nextYearMultiplier = yearMultiplier + 1;
            unsigned int leftPrice = winePrice(pStart, pLeftMost + 1, pRightMost, nextYearMultiplier) + leftmost * yearMultiplier;
            unsigned int rightPrice = winePrice(pStart, pLeftMost, pRightMost - 1, nextYearMultiplier) + rightmost * yearMultiplier;
            MaximumWinePriceCache[be][en] = max(leftPrice,rightPrice);
        }
    }
    return MaximumWinePriceCache[be][en];
}
