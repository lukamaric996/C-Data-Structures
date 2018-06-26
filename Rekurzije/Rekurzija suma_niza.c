/* Napisati fju koja pomocu rekurzije odredjuje sumu elementa prosljedjenog niza */

int suma_niza (int niz[],int n){
    if(n==0){
             return 0;
             }
    return niz[n-1]+suma_niza(niz,n-1);
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int array[10]={1,2,3,4,5,6};
  int n=6; /* broj elemenata */
  printf("%d",suma_niza(array,n));
  system("PAUSE");	
  return 0;
}
