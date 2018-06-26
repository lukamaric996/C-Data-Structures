/*Napisati funkciju koja ce u datoteci pronaci i vratiti zapis o artiklu sa zadanom �ifrom.
Funkcija preko imena mora vratiti broj dodatno pretra�enih pretinaca prilikom tra�enja zapisa
( 0 ako se zapis nalazi u svom pretincu, 1 ako je odmah u sljede�em pretincu, �, M ukoliko
se zapis ne nalazi u datoteci).
*/
/*Zapis je prazan ako je na mjestu �ifre vrijednost nula. Parametri za raspr�eno adresiranje
nalaze se u datoteci parametri.h i oni su:
- BLOK : veli�ina bloka na disku
- MAXZAP : broj zapisa
- C : broj zapisa u jednom pretincu
- M : broj pretinaca*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
int sifra;
char naziv[50+1];
int kolicina;
float cijena;
} zapis;

int trazi_zapis(FILE *f, int sifra, zapis *z){
    int i,j;
    int udaljenost=0;
    zapis pretinac[C];
    i=adresa(sifra);
    poc=i;
    do{
        fseek(f,i*BLOK,SEEK_SET);
        fread(pretinac,sizeof(pretinac),1,f);
        for(j=0;j<C;j++){
           if(pretinac[j].sifra==sifra){
                pretinac[j]=z;
                return udaljenost;
                }
                }
                udaljenost++;
                i=(i+1)%M;
                }while(i!=poc);
           return M;
           }
           
    
    
    
}
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
