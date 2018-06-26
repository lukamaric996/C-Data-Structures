/*Niz brojeva definiran je rekurzivno na slijedeæi naèin:
fn = n + 1 , za n <= 1
fn = (fn-1 + 1)* fn-2 , za n > 1.
Napisati rekurzivnu funkciju koja æe izraèunati n-ti clan niza. O!*/
#include <stdio.h>
#include <stdlib.h>
long  fn(int n){
      printf("%d\n",n);
      if(n<=1){
     
        return n+1;
        
        }
      return (fn(n-1)+1)*fn(n-2);
      
      
      }
int main(int argc, char *argv[])
{
  long k;
printf("%d",fn(4));
  system("PAUSE");	
  return 0;
}
