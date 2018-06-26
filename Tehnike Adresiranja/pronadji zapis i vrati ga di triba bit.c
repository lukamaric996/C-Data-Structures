/*Jedan zapis datoteke organizirane po nacelu raspršenog adresiranja definiran je strukturom:
typedef struct
{ 
        int sifra; 
        char naziv[50+1]; 
        double cijena; 
        }zapis; 
Zapis je prazan ako je na mjestu šifre vrijednost nula. Parametri za raspršeno adresiranje nalaze se u datoteci parametri.h i oni su:
       - BLOK .............. velicina bloka na disku 
       - MAXZAP ........ broj zapisa
       - C ...................... broj zapisa u jednom pretincu 
       - M ...................... broj pretinaca 
       Kljuc zapisa je šifra artikla, a transformacija kljuca u adresu obavlja se zadanom funkcijom: 
       int adresa(int sifra); 
       Napišite funkciju koja ce u pretincu x pronaci i vratiti prvi zapis koji je po svojoj šifri trebao završiti u pretincu
        y (ali je zbog preljeva završio u pretincu x). Funkcija preko svog imena vraca 1 ili 0 ovisno o tome postoji 
        li takav zapis u pretincu x ili ne. 
        Prototip funkcije je: int pronadji(FILE *f, zapis *z, int x, int y);
        */
#include <stdio.h>
#include <stdlib.h>

int pronadji(FILE *f, zapis *z, int x, int y){
    zapis pretinci[C];
    int i;
    fseek(f,x*BLOK,SEEK_SET);
    fread(pretinci,sizeof(pretinci),1,f);
    for(i=0;i<C;i++){
      if(pretinci[i].sifra!=0 && adresa(pretinci[i].sifra)==y){
         *z=pretinci[i];
         return 1;
         }
    return 0;
}
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
