 /* Napisati fju koja nalazi zapis sa zadanom sifrom. Fja vraca 0 ako zapise nije nadjen, 1 ako je nadjen, -1 ako je preljev */
#include <stdio.h>
#include <stdlib.h>
int trazi( FILE *f, int sifra, zapis *z){
    zapis pretinac[C];
    int i,j,poc;
    i=adresa(sifra);
    poc=i;
    do{
          fseek(f,i*BLOK,SEEK_SET);
          fread(pretinac,sizeof(pretinac),1,f);
          for(j=0;j<C;j++){
           if(pretinac[j].sifra==sifra{
              *z=pretinac[j];
              return i=poc?1:-1;
              }
              }
          i=(i+1)%M;
          }while(i!=poc);
          return 0;
          }
int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
