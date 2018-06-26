#include <stdio.h>
#include <stdlib.h>
/* n-ti clan aritimetrickog niza */
int aNiz(int a0,int d, int n){
    if(n==0){
             return a0;
             }
    return d+aNiz(a0,d,n-1);
}
int main(int argc, char *argv[])
{
  printf("%d",aNiz(1,5,2));
  system("PAUSE");	
  return 0;
}
