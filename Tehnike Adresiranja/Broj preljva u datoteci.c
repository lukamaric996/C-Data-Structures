/* Napisati fju koja racuna broj preljeva u zapisu */
int br_preljeva(FILE *f){
    zapis pretinci[C];
    int i,j,br=0;
    for(i=0;i<M;i++){
    fseek(f,i*BLOK,seek_set);
    fread(pretinci,sizeof(pretinci),1,f);
    for(j=0;j<C;j++){
    if(adresa(pretinci[j].sifra)!=i)
     br++;
     }
     }
     return br;
     }
     
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  system("PAUSE");	
  return 0;
}
