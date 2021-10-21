#include<stdio.h>
#include "alu.h"

int bit_and(int a, int b)
{
int c = a&b;
return c;
}

int bit_or(int a, int b)
{
int c = a|b;
return c;
}

int bit_not(int a)
{
int b = ~a;
return b;
}
