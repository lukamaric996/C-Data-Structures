/*f 0 = 1,
f 1 = 2,
f 2 = 3,
f n = (f n-1 + f n-2)* f n-3 , za n > 2.
Napisati rekurzivnu funkciju koja æe izraèunati n-ti èlan niza.
Funkcija mora imati prototip: long f(int n);
*/
#include <stdio.h>
#include <stdlib.h>
long f(int n){
     printf("%d\n",n);
     if(n<=2)
      return n+1;
     return (f(n-1)+f(n-2))*f(n-3);
     }
int main(int argc, char *argv[])
{
 printf("%ld",f(4));
  system("PAUSE");	
  return 0;
}
