#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct s{
    int broj;
    struct s* sljed;
}cvor;


 cvor *noviCvor(int element){/* funkcija za kreiranje novog cvora */
 
      cvor *novi;
      novi=(cvor *)malloc(sizeof(cvor));
      
      if(novi==NULL)
         return 0;
         
      novi->broj=element;
      novi->sljed=NULL;
      
      return novi;
      
      
      }

 int dodaj(cvor **glava, int element){/* funkcija koja dodaje novi cvor */
 
      cvor *novi=noviCvor(element);
      
      if(novi==NULL)
         return 0;
         
      cvor *pom=*glava;
      if(pom==NULL){
              *glava=novi;
                return 1;    
                    }
      
      while(pom->sljed!=NULL)
           pom=pom->sljed;
      
      pom->sljed=novi;
      
      return 1;
 
 
   }
 
 int dodajnapocetak(cvor**glava,int element){/*funkcija dodaje novi cvor na prvo mjesto u listi */
     cvor *novi;
     novi=noviCvor(element);
     if(novi==0)
     return 0;
     if(*glava==0){
     *glava=novi;
     return 1;
     }
     novi->sljed=*glava;
     *glava=novi;
     return 1;
     
     }
   
 void ispis (cvor **glava){/* ispis elemenata liste*/
        
        cvor *pom=*glava;
        if(*glava==NULL)
          return ;
        printf("elementi liste su : \n",pom->broj);
        while(pom!=0){
              printf("%d ",pom->broj);
              pom=pom->sljed;
               }
               printf("\n");
               }    
                         
 void ispis_predzadnjeg(cvor *glava){
       if(!glava|| !(glava->sljed))
       return;
    while(glava->sljed->sljed)
      glava=glava->sljed;
    printf("%d",glava->broj);
}
 int izbrisiPrvi(cvor **glava) {/* brisanje prvog cvora liste*/
 
       cvor *pom=*glava;
       
       if(*glava==NULL)
         return 0;
         
       *glava=(*glava)->sljed;
       free(pom);
       return 1;
     }
 
 
 int  izbrisiZadnji(cvor **glava){/* brisanje posljednjeg cvora liste*/
       
       cvor *pom=*glava;
       
       if(*glava==NULL)
          return 0;
          
       if(pom->sljed==NULL){
                free(pom);
                *glava=0;
                return 1;                  
                            }
       while(pom->sljed->sljed!=0){
             pom=pom->sljed;
             }
             free(pom->sljed);
             pom->sljed=0;
             return 1;
          
      }
      
 int suma(cvor *glava){/* suma elemenata liste */
    int suma=0;
    
    if(glava==0)
      return 0;
      
    while(glava!=0){
          suma+=glava->broj;
          glava=glava->sljed;
          }    
                    
       return suma;
     
     }
     
  int uvecajprvi(cvor *glava, int povecanje){/* funkcija uvecaje prvi cvor */
      if(glava==0)
         return 0;
         
      glava->broj+=povecanje;
      
      return 1;
      
      }
   
  int uvecajposljednji (cvor *glava, int povecanje){/* funkcija uvecaje posljednji clan liste */
        
        if(glava==0)
           return 0;
           
       while(glava->sljed!=0)
            glava=glava->sljed;
            
       glava->broj+=povecanje;
       
       return 1;
        
       }      
       
  int uvecajSve(cvor *glava, int povecanje){/* funkcija uvecaje sve clanove liste */

	if (glava == 0)
		return 0;
		
	while (glava!= 0) {
		glava->broj += povecanje;
		glava = glava->sljed;
	}
	
	return 1;
   }   
   
    
 int dodajnapoziciju(cvor **glava, int element,int n){/* dodaje element na proizvoljnu poziciju  */
     
   cvor *novi=noviCvor(element);
   
   if(n==1){
        novi->sljed=*glava;
        *glava=novi;    
        return 1;
            }
   
   cvor *pom=*glava;
   int i;
   
   for(i=0;i<n-2;i++)
      pom=pom->sljed;
      
     novi->sljed=pom->sljed;
     pom->sljed=novi;
   
	return 1;
}  

  int obrisisve(cvor **glava){/* brise sve elemente sa liste */
       
       cvor *pom=*glava;
       
       if(glava==0)
          return 0 ;
         
       while( (*glava)!=0){
              pom=*glava;
              *glava=(*glava)->sljed;
              free(pom);          
                        }
        return 1; 
                        }
                        
  int obrisisapozicije(cvor **glava, int n){/* brise element na proizvoljnu poziciju  */
      
      if(glava==0)
         return 0;  
      
      cvor *pom=*glava,*pom2;
      int i;
      
      for(i=0;i<n-2;i++){
           pom=pom->sljed;          
                         }
                          
      pom2=pom->sljed;
      pom->sljed=pom2->sljed;
      free(pom2);
      return 1;
      }
      
  void mijenjaj(cvor **glava){/* mijenja prvi element sa drugim */
  
  cvor*pom=*glava;
  
  pom=pom->sljed;
  (*glava)->sljed=pom->sljed;
  pom->sljed=*glava;
  *glava=pom;
  
  }
  
  
int brisiminuse(cvor **glava){/* brise sve negativne  elemente liste */
       
       cvor*pom=*glava;
       
       if(*glava==0)
          return 0;
          
       while((*glava)->broj<0){
              pom=*glava;
              *glava=(*glava)->sljed;
              free(pom);
              }            
        cvor *pom2=*glava;
        pom=*glava;
        while(pom->sljed!=0){
                             
                if(pom->sljed->broj<0){
                        pom2=pom->sljed;;
                        pom->sljed=pom2->sljed;
                        free(pom2);
                        }
                  
                 else
                    pom=pom->sljed;                                   
                             
                             }                                                
         return 1;
      }
      
  int  izbacisveosimprvog(cvor **glava){/* brise sve cvorove osim prvog */
	cvor *pom = *glava;
	if(*glava == NULL)
		return 0;
		
	pom = (*glava)->sljed;
	
	while(pom != NULL){
		(*glava)->sljed = pom->sljed;
		free(pom);
		pom = (*glava)->sljed;
	}
	 return 1;
}

 int brisiposljednji(cvor **glava){/* brise posljednji cvor */
 
      cvor *pom=*glava;
      cvor *pom2=*glava;
        
      if(*glava==0)
        return 0 ;
        
      while(pom->sljed!=0){
         pom2=pom;
         pom=pom->sljed;
         }
        free(pom);
        pom2->sljed=0;
        return 1;
        }
        
  int  brisi_prosljedjenji ( cvor ** glava, int element){/* funkcija brise element koji se prosljedi funkciji */
       
       if(*glava==NULL)
          return 0;
        
        cvor *pom;
        
       if((*glava)->broj==element){
                 pom=*glava;
                 *glava=(*glava)->sljed;
                 free(pom);
                 return 1;                                             
                                   }
     cvor *pom2;
     pom=*glava;
     
     while(pom->sljed!=NULL){
           
           if(pom->sljed->broj==element){
               pom2=pom->sljed;
               pom->sljed=pom2->sljed;
               free(pom2);
               return 1;
               } 
             pom=pom->sljed;                
                             
                             }
       return 0;
       
       
       }
   
  int brisineparne(cvor **glava){/*brise neparne iz liste */
      cvor *pom=*glava;
      cvor *pom2=*glava;
      if(pom==0)
      return 0;
     while(pom!=0 && pom->broj%2!=0){
        (*glava)=(*glava)->sljed;
        free(pom);
        pom=*glava;
        }
        
      if(*glava==0)
      return 1;
      
     while(pom->sljed!=0){
        if(pom->sljed->broj%2!=0){
         pom2=pom->sljed;
         pom->sljed=pom2->sljed;
         free(pom2);
         }
        else 
         pom=pom->sljed;
         }
     return 1;
     
}
       
  int dodajsortirano(cvor **glava, int br){/* dodaje cvor sortirano u listu */
      
      cvor *novi=noviCvor(br);
      if(*glava==NULL || (*glava)->broj>br){
            novi->sljed=*glava;
            *glava=novi;
            return 1;
            }
       cvor *pom=*glava;  
       while(pom->sljed!=NULL){
             
             if(pom->sljed->broj>br){
                     novi->sljed=pom->sljed;
                     pom->sljed=novi;
                     return 1;
                     }
                     pom=pom->sljed;
                     }
                     pom->sljed=novi;
                     novi->sljed=0;
                     return 1;                                                       
                      
      }
      
  void ispisi_rekurzivno(cvor *glava){
         
         if(glava!=NULL){
            printf("%d ",glava->broj);
            ispisi_rekurzivno(glava->sljed);
            }
       
       
       }
       
  float prosjek(cvor *glava){/* naci prosjek liste*/
        int suma=0;
        int br=0;
        if(glava==NULL)
          return 0;
        while(glava!=NULL){
           br++;
           suma+=glava->broj;
           glava=glava->sljed;
           }
        return (float)suma/br;
        
        }
        
 int brisi_prosljedjenog(cvor **glava,int parametar){/*izbrisati cvor sa prosljedjenim parametrom */
     
     if(*glava==NULL)
       return 0;
       
     cvor *pom=*glava;
     
     if(pom->broj==parametar){
           *glava=pom->sljed;
           free(pom);   
           return 1;                                     
                              }
                              
     cvor *pp;
     while(pom!=NULL){
            pp=pom;
            pom=pom->sljed;
            if(pom->broj==parametar){
                pp->sljed=pom->sljed;
                free(pom);
                return 1;
                }
                }
                return 0;         
                      
                      }
                      
 int brisi_rekurzivno(cvor **glava){/* brise listu pomocu rekurzije */
      
      cvor *pom; 
     if(*glava==NULL)
        return 0 ;
     
     pom=*glava;
     *glava=pom->sljed;
     free(pom);
      brisi_rekurzivno(glava);
      return 1;
     }
     
 int suma_rekurzivno(cvor *glava){/* rekurzivni zborji listu */
 
      if(glava==NULL)
        return 0;
      return glava->broj+suma_rekurzivno(glava->sljed);
      }
      
 int brisi_najveci(cvor **glava){/*brise najveci clan liste*/
     int max;
     cvor *pom=*glava;
     if(pom==0)
     return 0;
     if(pom->sljed==0){
      *glava=(*glava)->sljed;
      return 0;
      }
      
     max=pom->broj;
     while(pom->sljed!=0){
      if(max<pom->sljed->broj)
      max=pom->sljed->broj;
      pom=pom->sljed;
      }
     cvor *pp=*glava;
     pom=*glava;
     while(pom->sljed!=0){
         if(pom->sljed->broj!=max)
         pom=pom->sljed;
         else{
           pp=pom->sljed;
           pom->sljed=pp->sljed;
           free(pp);
           return 1;
           }
           }
           return 0;
           }
 void pronadjiIprebaciNaKraj(cvor **glava, int trazeni){/*nadji element i dodaj na kraj */
      if(glava==0|| (*glava)->sljed==0)
      return ;
     
     cvor *pom=*glava;
     cvor *pp2;
     cvor *novi;
     novi=noviCvor(trazeni);
     if(novi==0)
     return;
     if(pom->broj==trazeni){
      pp2=*glava;
      *glava=(*glava)->sljed;
      free(pp2);
      pom=*glava;
       while(pom->sljed!=0)
           pom=pom->sljed;
       pom->sljed=novi;
       novi->sljed=0;
       return;
       }  
     while(pom->sljed!=0){
         if(pom->sljed->broj!=trazeni)
         pom=pom->sljed;
         else{
              trazeni=pom->sljed->broj;
              pp2=pom->sljed;
              pom->sljed=pp2->sljed;
              free(pp2);
              }
              }
     pom=*glava;
     while(pom->sljed!=0)
     pom=pom->sljed;
     pom->sljed=novi;
     novi->sljed=0;
     }
     
 int brisi_osim_prvog(cvor **glava){
     if(*glava==0 || (*glava)->sljed==0)
     return 0;
     
     cvor *pom=(*glava)->sljed;
     cvor *p=pom;
     while(p->sljed!=0){
           p=p->sljed;
           free(pom);
           pom=p;
           }
          (*glava)->sljed=0;
           }
 

        
int main(int argc, char *argv[])
{
    cvor *glava=0;

      dodaj(&glava,3);
      dodaj(&glava,5);
      dodaj(&glava,7);
      dodajnapoziciju(&glava,3,1);
      dodajnapoziciju(&glava,1,5);
      ispis(&glava);


    printf("\n");
  system("PAUSE");	
  return 0;
}
