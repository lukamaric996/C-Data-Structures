/* Napisati fju koja racuna sumu neparnih brojeva za prosljeðeni interval */
#include <stdio.h>
#include <stdlib.h>
int suma_neparnih (int a, int b){
    if(a>b){ /* ne ide a==b jer ako prosljedimo npr 13,13, suma bi tribala bit 13 13 */
             return 0;
             }
    if(a%2!=0)
     return a+suma_neparnih(a+1,b);
    
    return suma_neparnih(a+1,b);
}
int main(int argc, char *argv[])
{
  printf("%d\n",suma_neparnih(1,10));
  system("PAUSE");	
  return 0;
}
