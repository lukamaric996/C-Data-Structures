/* rekurzivno prebroji koliko se trazena znamenka javlja u nekom broju */
#include <stdio.h>
#include <stdlib.h>
int broji(int n,int trazeni){
    int d;
    if(n==0)
       d=0;
      
   if(trazeni==n%10){
          d=1;
          } 
    return d+broji(n/10,trazeni);
}
int main(){
    int n;
    int d;
  printf("%d",broji(599329,9));
  getch();
    return 0;
}
