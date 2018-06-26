/*Jedan zapis datoteke organizirane po nacelu raspršenog adresiranja definiran je strukturom:
typedef struct{
int sifra;
char naziv[50+1];
double cijena;
} zapis;
Zapis je prazan ako je na mjestu šifre vrijednost nula. Parametri za raspršeno adresiranje
nalaze se u datoteci parametri.h i oni su:
- BLOK ............... velicina bloka na disku
- MAXZAP .......... broj zapisa
- C ....................... broj zapisa u jednom pretincu
- M ....................... broj pretinaca
Napisati funkciju koja ce vratiti broj punih pretinaca unutar datoteke. Funkcija treba imati prototip:
int broj_popunjenih (FILE *f); */
#include <stdio.h>
#include <stdlib.h>
int broj_popunjenih(FILE *f){
    int i,j,br=0,kont;
    zapis pretinac[C];
    for(i=0;i<M;i++){
      fseek(f,i*BLOK,SEEK_SET);
      fread(pretinac,sizeof(pretinac),1,f);
      kont=1; /*pretpostavka da je pretinac pun */
      for(j=0;j<C;j++)
        if(pretinac[j].sifra==0)
          kont=0; /* ako je neki zapis prazan*/
      if(kont)/*ako je pretinac pun*/
       br++;
       }
       return br;
       }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
