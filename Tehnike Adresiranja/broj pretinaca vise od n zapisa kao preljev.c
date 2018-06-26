/*Napisati funkciju koja æe vratiti broj pretinaca u kojima se nalazi više od n zapisa koji su
upisani kao preljev. */
/* Zapis je prazan ako je na mjestu šifre vrijednost nula. Parametri za raspršeno adresiranje
nalaze se u datoteci parametri.h i oni su:
- BLOK : velicina bloka na disku
- MAXZAP : broj zapisa
- C : broj zapisa u jednom pretincu
- M : broj pretinaca */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
int sifra;
char naziv[50+1];
int kolicina;
float cijena;
} zapis;

int broji (FILE *f, int m){
    int i,j,broj_preljeva_u_pretincu;
    int br=0;
    zapis pretinci[C];
    
    for(i=0;i<M;i++){
       broj_preljeva_u_pretincu=0;
       fseek(f,i*BLOK,SEEK_SET);
       fread(pretinci,sizeof(pretinci),1,f);
       fseek(f,i*BLOK,SEEK_SET);
       
            for(j=0;j<C;j++){
                if(adresa[pretinci[j].sifra)!=i && pretinci[j].sifra!=0){
                    broj_preljeva_u_pretincu++;
                    }
                    }
            if(broj_preljeva_u_pretincu>n){
               br++;
               }
               
               }
               return br;
               }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
