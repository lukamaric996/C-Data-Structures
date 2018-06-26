/* Napisati fju koja racuna produkt znamenki za prosljeðeni broj */
#include <stdio.h>
#include <stdlib.h>
int produkt_znamenki (int n){
    if(n==0){ /*drugi nacin , if(n/10==0) return n; */
             return 1;
             }
    return n%10*produkt_znamenki(n/10);
}
int main(int argc, char *argv[])
{
  printf("%d\n",produkt_znamenki(253));
  system("PAUSE");	
  return 0;
}
