/*Napisati funkciju koja æe pronaæi prosjeènu „udaljenost“ zapisa od predviðenog pretinca.
Ukoliko pojedini zapis nije spremljen kao preljev njegova udaljenost je 0, a inaèe udaljenost
se definira kao broj pretinaca koje je dodatno potrebno proèitati da bi se zapis pronašao.
Primjerice, ukoliko je M=15, a adresa nekog zapisa 13, a zapis se nalazi u pretincu broj 4,
udaljenost je 6.
*/
/*Zapis je prazan ako je na mjestu šifre vrijednost nula. Parametri za raspršeno adresiranje
nalaze se u datoteci parametri.h i oni su:
- BLOK : velièina bloka na disku
- MAXZAP : broj zapisa
- C : broj zapisa u jednom pretincu
- M : broj pretinaca
Kljuè zapisa je šifra artikla, a transformacija kljuca u adresu se obavlja zadanom funkcijom:
int adresa(int sifra); */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
int sifra;
char naziv[50+1];
int kolicina;
float cijena;
} zapis;

float avg_udaljenost(FILE *f){
      zapis pretinci[C];
      int i,j;
      int br=0;
      int udaljenost=0;
      
     for(i=0;i<M;i++){
        fseek(f,i*BLOK,SEEK_SET);
        fread(pretinci,sizeof(pretinci),1,f);
        
        for(j=0;j<C;j++){
           if(pretinci[j].sifra!=0 && adresa(pretinci[j].sifra)!=i){
             /* ako zapis nije prazan i ako je preljev */
             udaljenost=udaljenost+M-adresa(pretinci[j].sifra+i;
             br++;
             }
           
           else{
                /*Ako nije preljev, onda se nalazi di i treba odnosno udaljenost ostaje ista, tj uvecjemo je za 0 */
                udaljenost+=0;
                br++;
                }
                }
                }
                return (float)udaljenost/br;
                }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
