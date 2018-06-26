/* Napisati fju koja dodaje zapis u dat i vraca 0,1,-1 (jel dodana, dodana, preljev) */
#include <stdio.h>
#include <stdlib.h>
int dodaj(FILE *f,zapis z){
    zapis pretinac[C];
    int i,j,poc;
    i=adresa(z.sifra);
    poc=i;
    do{
          fseek(f,i*BLOK,SEEK_SET);
          fread(pretinac,sizeof(pretinac),1,f);
          for(j=0;j<C;j++){
             if(pretinac[j].sifra==0){
               pretinac[j]=z;
               fseek(f,i*BLOK,SEEK_SET);
               fwrite(pretinac,sizeof(pretinac),1,f);
               return i==poc?1:-1;
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
