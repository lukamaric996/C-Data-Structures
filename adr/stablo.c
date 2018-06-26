#include <stdio.h>
#include <stdlib.h>

typedef struct c {
	int broj;
	struct c *lijevo;
	struct c *desno;
}cvor;

void ispis(cvor *korijen)
{
   if(korijen>0){
     printf("%d ",korijen->broj);
     ispis(korijen->lijevo);
     ispis(korijen->desno);
     }
}

int trazi(cvor *korijen, int trazeni)
{

	if (korijen == 0)
		return 0;
	
	if (korijen->broj == trazeni)
		return 1;

	if (trazeni < korijen->broj)
		return trazi(korijen->lijevo, trazeni);
	else
		return trazi(korijen->desno, trazeni);

}

int brojElemenata(cvor *korijen)
{
	if (korijen == 0)
		return 0;
	


	return 1 + brojElemenata(korijen->lijevo) + brojElemenata(korijen->desno);
}

int sumaElemenata(cvor *korijen)
{
	if (korijen == 0)
		return 0;

	return korijen->broj + sumaElemenata(korijen->lijevo) + sumaElemenata(korijen->desno);
}

int brojListova(cvor *korijen)
{
	if (korijen == 0)
		return 0;

	if (korijen->lijevo == 0 && korijen->desno == 0)
		return 1;
    else
    return brojListova(korijen->lijevo)+brojListova(korijen->desno);

}

cvor *noviCvor(int element)
{
	cvor *novi;
	novi = (cvor *)malloc(sizeof(cvor));
	if (novi == 0)
		return 0;
	novi->broj = element;
	novi->lijevo = 0;
	novi->desno = 0;

	return novi;
}

cvor *dodaj(cvor *korijen, int novi)
{
	if (korijen == 0)
		return  noviCvor(novi);

	if (novi < korijen->broj)
		korijen->lijevo = dodaj(korijen->lijevo, novi);
	else 
		korijen->desno = dodaj(korijen->desno, novi);

	return korijen;
}
void ispis_do_razine (cvor *korijen,int x){/* ispis clanova do zadane razine */
     if(korijen!=0 && x>0){
      printf("%d ",korijen->broj);
      ispis_do_razine(korijen->lijevo,x-1);
      ispis_do_razine(korijen->desno,x-1); 
      }
     }
     
void ispis_parametra(cvor *korijen, int br){/* ispis svih clanova stabla vecih od prosljedjenoh broja*/
     
     if(korijen!=0){
       if(korijen->broj>br)
          printf("%d ",korijen->broj);
          
       ispis_parametra(korijen->lijevo,br);
       ispis_parametra(korijen->desno,br);
       }
       }

int suma_listova(cvor *korijen){/* funkcija racuna sumu listova stabla */
      
      if(korijen==NULL)
      return 0;
      
      if(korijen->lijevo==0 && korijen->desno==0)
         return korijen->broj;
         
       return suma_listova(korijen->lijevo)+ suma_listova(korijen->desno);
    
    
 }
 
void ispis_koji_nisu_listovi(cvor *korijen){/* funkcija ispisuje cvorove stabla koji nisu listovi */

 if(korijen!=0){
                
 if(korijen->lijevo!=0 || korijen->desno!=0){
      printf("%d ",korijen->broj);
      ispis_koji_nisu_listovi(korijen->lijevo);
      ispis_koji_nisu_listovi(korijen->desno);
}  
}
}


void ispis_listova(cvor *korijen){/* funkcija ispisuje sve listove*/
     
     if(korijen!=NULL){
       if(korijen->lijevo==0 && korijen->desno==0){
         printf("%d ",korijen->broj);
         }
       else{
         ispis_listova(korijen->lijevo);
         ispis_listova(korijen->desno);
         }
         }
           
     }

void ispis_manjih_listova(cvor *korijen,int max){ /* funkcija ispisuje listove koji su manji jednaki prosljedjenom parametru */

  if(korijen!=NULL){
                    
    if(korijen->broj<=max &&korijen->lijevo==0 && korijen->desno==0){
       printf("%d ",korijen->broj);
       }
       
    else{
      ispis_manjih_listova(korijen->lijevo,max);
      ispis_manjih_listova(korijen->desno,max);
      }
      
      }
      }
      
int broj_manjih_cvorova(cvor *korijen, int parametar){/* funkcija vraca broj cvorova manjih od prosljedjenog parametra */
      
      if(korijen==NULL)
        return 0;
      
      if(korijen->broj<parametar)
        return 1+broj_manjih_cvorova(korijen->lijevo,parametar)+broj_manjih_cvorova(korijen->desno,parametar);
        else
      return broj_manjih_cvorova(korijen->lijevo,parametar)+broj_manjih_cvorova(korijen->desno,parametar);
        
    
    
}

int broj_neparnih(cvor *korijen){/*broji neparne u stablu*/
   if(korijen){
    if(korijen->broj%2!=0)
      return 1+broj_neparnih(korijen->lijevo)+broj_neparnih(korijen->desno);
    else
    return broj_neparnih(korijen->lijevo)+broj_neparnih(korijen->desno);
} 
   else
   return 0;
}

int broj_negativnih(cvor *korijen){/*broji negativne u stablu */
    if(korijen){
     if(korijen->broj<0)
     return 1+broj_negativnih(korijen->lijevo)+broj_negativnih(korijen->desno);
     else 
     return broj_negativnih(korijen->lijevo)+broj_negativnih(korijen->desno);
     }
     else
     return 0;
     }
void ispisListovaVecihOd(cvor *korijen, int br){/*ispisuje listove vece od parametra*/
     if(korijen){
       if(!korijen->lijevo&&!korijen->desno&&korijen->broj>br)
       printf("%d\n",korijen->broj);
       
       ispisListovaVecihOd(korijen->lijevo,br);
       ispisListovaVecihOd(korijen->desno,br);
       }
       }
       
int maxList(cvor *korijen){/* najveci list*/
int maxlijevo, maxdesno;
if(korijen)
{
    if( !korijen->lijevo && !korijen->desno )
     return korijen->broj;

   maxlijevo=maxList(korijen->lijevo);
   maxdesno=maxList(korijen->desno);

}
   if(maxlijevo > maxdesno)
      return maxlijevo;
      else return maxdesno;

return 0;

}

void ispisZadanaDubina(cvor *korijen, int trenutnaDubina,int zadanaDubina)/* ispisuje sve do zadane dubine */
{
if(korijen)
{
if(trenutnaDubina==zadanaDubina)
printf("%d\n",korijen->broj);
ispisZadanaDubina(korijen->lijevo,trenutnaDubina+1,zadanaDubina);
ispisZadanaDubina(korijen->desno,trenutnaDubina+1,zadanaDubina);
}
}

int nadjiDubinu(cvor *korijen, int dubina, int broj){/*trazi na kojj je dubini broj*/
    if(korijen){
       if(broj>korijen->broj)
       return nadjiDubinu(korijen->desno,dubina+1,broj);
       else if(broj<korijen->broj)
       return nadjiDubinu(korijen->lijevo,dubina+1,broj);
       else
       return dubina;
       }
       else
       return 0;
       }
     
int preuredi (cvor *korijen, int razina,int zadanadubina){/*racuna sumu od zadane dubine prema kraju */
    if(korijen==0)
    return 0;
    else{
      if(razina<zadanadubina){
        return preuredi(korijen->lijevo,razina+1,zadanadubina)+preuredi(korijen->desno,razina+1,zadanadubina);
        }
      else  
      return korijen->broj+preuredi(korijen->lijevo,razina+1,zadanadubina)+preuredi(korijen->desno,razina+1,zadanadubina);
      }
      }


int main()
{
	cvor *korijen = 0;
	korijen = dodaj(korijen, 5);
    korijen = dodaj(korijen, 4);
    korijen = dodaj(korijen, 3);
    korijen = dodaj(korijen, 7);
    korijen = dodaj(korijen, 10);
    korijen = dodaj(korijen, 8);
    korijen = dodaj(korijen, 11);

    preuredi(korijen,0,3);
    ispis(korijen);
	system("pause>0");
    return 0;
}
