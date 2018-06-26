/* rekurzivno prosljedi broj, i djeljitlej(2), odredi je li broj prost */
#include <stdio.h>
#include <stdlib.h>
int prost(int n, int djeljitelj){
    if(djeljitelj==n){
                        return 1;
                        }
   if(n%djeljitelj==0)
   return 0;
   else return prost(n,djeljitelj+1);
}
int main(int argc, char *argv[])
{
  printf("%d",prost(14,2));
  system("PAUSE");	
  return 0;
}
