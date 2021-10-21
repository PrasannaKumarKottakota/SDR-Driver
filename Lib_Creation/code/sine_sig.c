#include<stdio.h>
#include<math.h>
int main()
{
float Ts = 0.1;
float To = 2*22/7;
// To Fundamental Period
int n = To/Ts;
// n is the size of the array

float t[n];
t[0] = 0;
printf("t = \n%f \t", t[0]);
for(int i =1; i<n; i++)
{
t[i] = t[i-1] + Ts;
printf("%f \t", t[i]);
}
printf("\n\n");


printf("Sine_wave  = \n");
for(int i =0; i<n; i++)
{
 printf("%f \t", sin(t[i]));
}
printf("\n");

return 0;
}
