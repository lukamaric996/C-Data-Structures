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

int prosjek(cvor *korijen){
  if(korijen == 0)
    return 0;
  else
    korijen->broj = korijen->broj + 1;

  return prosjek(korijen->lijevo) + prosjek(korijen->desno);
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

    ispis(korijen);
    prosjek(korijen);
    ispis(korijen);
  system("pause>0");
    return 0;
}
