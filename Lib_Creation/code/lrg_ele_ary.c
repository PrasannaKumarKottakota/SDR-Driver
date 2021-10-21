
#include<stdio.h>
int main()
{
int arr[] = {20, 10, 20, 4, 100};
int n = sizeof(arr)/sizeof(int);
int lrg_elmt = arr[0];

for(int i = 0; i< n; i++)
{
if (arr[i] > lrg_elmt)
{ lrg_elmt = arr[i];}

}

printf("The largest element of the array is : %d\n", lrg_elmt);
return 0;
}
