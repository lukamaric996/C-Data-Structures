/*Jedan zapis datoteke organizirane po principu raspršenog adresiranja sadrži maticni broj studenta (int), ime i prezime (50+1 znak), 
godinu na kojoj trenutno studira (int) te trenutni prosjek ocjena (float). Prazni se zapis prepoznaje po maticnom broju jednakom 0. 
Velicina bloka na disku je 2048. Ocekuje se najviše 120000 zapisa, a tablica je dimenzionirana za 25% veci kapacitet. 
Kod upisa se primjenjuje metoda ciklickog preljeva. Kljuc zapisa je maticni broj, a transformacija kljuca u adresu se obavlja zadanom funkcijom
int adresa(int matbr);
Napisati funkciju koja ce pronaci i vratiti zapis o studentu sa zadanim maticnim brojem.
Funkcija preko imena treba vratiti 1 ako se zapis nalazi u "svom" pretincu, 2 ako je zapisan kao preljev, a 0 ako zapis ne postoji u datoteci. 
Funkcija treba imati prototip:	
int fun(FILE *f, int matbr, zapis *student);
*/
#include <stdio.h>
#include <stdlib.h>
#DEFINE BLOK 2048
#DEFINE MAXZAP 120000
#DEFINE C (Int)BLOK/Sizeof(zapis)
#DEFINE M (int)(MAXZAP*1.25/C)

int fun(FILE *f, int matbr, zapis *student){
    int i,j,poc;
    zapis pretinac[C];
    i=adresa(matbr);
    poc=i;
    do{
          fseek(f,i*BLOK,SEEK_SET);
          fread(pretinac,sizeof(pretinac),1,f);
          for(j=0;j<C;j++){
            if(pretinac[j].matbr==matbr){
               *student=pretinac[j];
               return i==poc?1:2;
               }
               }
               i=(i+1)%M;
               }while(i!=poc);
               return 0;
               }
    
    
}
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
