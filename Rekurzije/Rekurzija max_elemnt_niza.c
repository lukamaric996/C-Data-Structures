/* Napisati fju koja ce pomocu rekurzije odrediti najveci element niza */
#include <stdio.h>
#include <stdlib.h>
int max(int niz[],int n){
    int maximum;
    if(n==1)
            return niz[0];
   maximum=max(niz,n-1);
    return maximum>niz[n-1]?maximum:niz[n-1];
}
int main(int argc, char *argv[])
{
  int array[5]={2,5,4,7,5};
  printf("%d\n",max(array,5));
  system("PAUSE");	
  return 0;
}
