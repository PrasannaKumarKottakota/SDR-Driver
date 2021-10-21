#include<stdio.h>
#include"alu.h"

int main()
{
int a, b, c;
printf("Enter the value of a : ");
scanf("%d", &a);
printf("Enter the value of b : ");
scanf("%d", &b);

c = addition(a, b);
printf("Addition Operation of a and b : %d\n", c);

c = substraction(a, b);
printf("Difference of a and b : %d\n", c);

c = bit_and(a, b);
printf("Bitwise and operation between a, b : %d\n", c);

c = bit_or(a, b);
printf("Bitwise or operation between a, b : %d\n", c);

c = bit_not(a);
printf("Bitwise not operation of a : %d\n", c);

return 0;
}
