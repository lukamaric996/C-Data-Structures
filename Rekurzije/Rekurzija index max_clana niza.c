/*Napisati rekurzivnu funkciju koja ce vratiti indeks najvecg clana polja A[ ] koje ima n clanova. */
#include <stdio.h>
#include <stdlib.h>
int  max(int a[],int i , int n){
    int imax;
    if(i>=(n-1))
     return n-1;
     
     imax=max(a,i+1,n);
     return a[i]>a[imax]?i:imax;
   
     }
int main(int argc, char *argv[])
{
  int niz[6]={5,9,78,2,1,7};

  printf("%d",max(niz,0,6));
  system("PAUSE");	
  return 0;
}
