/*Jedan zapis datoteke organizirane po na�elu raspr�enog adresiranja definiran je strukturom:
typedef struct{
int sifra;
char naziv[50+1];
double cijena;
} zapis;
Zapis je prazan ako je na mjestu �ifre vrijednost nula. Parametri za raspr�eno adresiranje nalaze se u datoteci
parametri.h i oni su:
- BLOK .................. velicina bloka na disku
- MAXZAP ......... broj zapisa
- C ........................... broj zapisa u jednom pretincu
- M ........................... broj pretinaca
Kljuc zapisa je �ifra artikla, a transformacija kljuca u adresu obavlja se zadanom funkcijom:
int adresa(int sifra);
Zadana je i funkcija upisiZapis koja zadani zapis upisuje u zadani pretinac ako u njemu ima mjesta.
int upisiZapis (FILE *f, zapis z, int adresaPretinca);
Funkcija vraca 1 ako je mjesto prona�eno i zapis zapisan, a u suprotnom vra�a 0.
Napisati funkciju urediHash koja ce preljeve s pomocu funkcije upisiZapis prebaciti u za njih
predvi�ene pretince ako tamo ima mjesta. Dovoljno je kroz sve pretince proci samo jednom (vec
provjerene preljeve ne treba ponovno provjeravati). Funkcija treba vratiti broj prebacenih preljeva.
Prototip funkcije treba biti:
int urediHash(FILE *f); */
#include <stdio.h>
#include <stdlib.h>
int uredi_hash(FILE *f){
    zapis pretinac[C];
    int i,j,ima_promjene;
    int br=0;
    for(i=0;i<M;i++){
       ima_promjene=0;
       fseek(f,i*BLOK,SEEK_SET);
       fread(pretinac,sizeof(pretinac),1,f);
       for(j=0;j<C;j++){
         if(pretinac[j].sifra!=0 && adresa(pretinac[j].sifra)!=i){
             if(upisizapis(f,pretinac[j],pretinac[j].sifra){
                 pretinac[j].sifra==0;
                 ima_promjene=1;
                 br++;
                 }
                 }
                 }
              if(ima_promjene){
                fseek(f,i*BLOK,SEEK_SET);
                fwrite(pretinac,sizeof(pretinac),1,f);
                }
                }
                }
                return br;
                }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
