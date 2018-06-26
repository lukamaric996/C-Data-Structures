/* Napisati fju koja racuna sumu znamenki za prosljeðeni broj */
#include <stdio.h>
#include <stdlib.h>
int suma_znamenki (int n){
    if(n<10){ /*drugi nacin , if(n<=9) return n; */
             return n;
             }
    return n%10+suma_znamenki(n/10);
}
int main(int argc, char *argv[])
{
  printf("%d\n",suma_znamenki(999));
  system("PAUSE");	
  return 0;
}
