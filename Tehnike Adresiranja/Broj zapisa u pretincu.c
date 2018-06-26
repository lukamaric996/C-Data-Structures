/*Napisati fju koja racuna broj zapisa u pretincu prosljedjenog kao parametar */
#include <stdio.h>
#include <stdlib.h>
#define M=1000
#define C=100
#define BLOK 512
typedef Struct{
        int sifra;
        char ime[20+1];
        char prezime [20+1];
        }zapis;
int broj_zapisa(FILE *f, int br_pretinca){
    zapis pretinci[C];
    int i,br=0;
    fseek(f,br_pretinca*BLOK,SEEK_SET);
    fread(pretinci,sizeof(pretinac),1,f);
    for(i=0;i<C;i++){
    if(pretinac[i].sifra!=0)
        br++
        }
     return br;
     }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
