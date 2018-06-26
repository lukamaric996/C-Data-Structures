/*Napišite rekurzivnu funkciju za izbacivanje znamenki iz zadanog niza. Prototip funkcije treba biti: 
int IzbaciZnamenke (char *niz); Funkcija vraca broj izbacenih znamenki. Primjer: za ulazni niz 
"Godine 2008. je" funkcija mijenja niz u "Godine . je" i vraca 4 jer su izbacene 4 znamenke. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int izbaci_znamenke(char *niz){
      if(*niz=='\0')
       return 0;
       if(*niz>='0' && *niz<='9'){
        strcpy(niz,niz+1);
         return 1+izbaci_znamenke(niz-1);
         }
       return izbaci_znamenke(niz+1);
       }
int main(int argc, char *argv[])
{
    char string[165]="Godina 23322008 je . ";
  printf("%d ",izbaci_znamenke(string));
  printf("%s",string);
  system("PAUSE");	
  return 0;
}
