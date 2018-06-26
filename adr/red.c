#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct s {
	int polje[MAX];
	int pocetak;
	int kraj;
}Red;

void init(Red *red){
	red->pocetak = 0;
	red->kraj = 0;
}

int dodaj(Red *red, int element)
{
	if ((red->kraj + 1) % MAX == red->pocetak)
		return 0;
	red->kraj = (red->kraj + 1) % MAX;
	red->polje[red->kraj] = element;
	return 1;
}

int skini(Red *red, int *element)
{
	if (red->kraj == red->pocetak)
		return 0;
	red->pocetak = (red->pocetak + 1) % MAX;
	*element = red->polje[red->pocetak];
	return 1;
}

int brisinegativne(Red *red){
    if(red->kraj==red->pocetak)
      return 0;
    Red pom;
    int x;
    init(&pom);
    while(skini(red,&x)){
      if(x>0)
      dodaj(&pom,x);
      }
    while(skini(&pom,&x))
    dodaj(red,x);
}
int zaviri(int *element, Red *red)
{
	int el;
	Red pom;
	init(&pom);

	if (skini(red, &el) == 0)
		return 0;
	dodaj(&pom, el);
	*element = el;

	while (skini(red, &el) == 1)
		dodaj(&pom, el);

	while (skini(&pom, &el) == 1)
		dodaj(red, el);

	return 1;
}

int velicina(Red *red)
{
	int element;
	int br = 0;
	Red pom;
	init(&pom);

	while (skini(red, &element) == 1) {
		br++;
		dodaj(&pom, element);
	}

	while (skini(&pom, &element) == 1) {
		dodaj(red, element);
	}
	return br;
}

int prazni(Red *red)
{
	int element;
	while (skini(red, &element) == 1);
	return 0;
}
void ispis(Red *red){
     int x;
     Red pom;
     init(&pom);
     while(skini(red,&x)){
       printf("%d\n",x);
       dodaj(&pom,x);
       }
     while(skini(&pom,&x))
     dodaj(red,x);
     
     }

int brojslobodnih(Red *red){
    int brelem=0;
     if(red->kraj>=red->pocetak)
       brelem=red->kraj-red->pocetak;
     else
     brelem=MAX-(red->pocetak-red->kraj);
     
     return MAX-brelem-1;
     }
float popunjenost(Red *red){
         int brelem=0;
     if(red->kraj>=red->pocetak)
       brelem=red->kraj-red->pocetak;
     else
     brelem=MAX-(red->pocetak-red->kraj);
     
     return ((float)brelem/(MAX-1))*100;
     }
float omjer(Red *red){
      int brelem=0;
      if(red->kraj>=red->pocetak)
      brelem=red->kraj-red->pocetak;
      else
      brelem=MAX-(red->kraj-red->pocetak);
      return((float)(MAX-brelem-1)/brelem);
      }
int suma(Red *red){
    if(red->kraj==red->pocetak)
    return 0;
    int sabiranje=0,x;
    Red pom;
    init(&pom);
    while(skini(red,&x)){
      sabiranje+=x;
      dodaj(&pom,x);
      }
    while(skini(&pom,&x))
      dodaj(red,x);
      
    return sabiranje;
}

void preuredi(Red *red){/* pozitivne elemente staviti iznad negativnih */
if(red->kraj==red->pocetak)
    return 0;
 Red pomn,pomp;
 init(&pomp);
 init(&pomn);
 int x;
 while(skini(red,&x)){
    if(x>0)
    dodaj(&pomp,x);
    else
    dodaj(&pomn,x);
}
 while(skini(&pomp,&x))
 dodaj(red,x);
 
 while(skini(&pomn,&x))
 dodaj(red,x);
}

int izbaci_neparne(Red *red){/* izbacuje neparne i vraca broj izbacenih*/
if(red->kraj==red->pocetak)
    return 0;
Red pom;
int br=0;
init(&pom);
int x;
while(skini(red,&x)){
if(x%2==0)
dodaj(&pom,x);
else
br++;
}
while(skini(&pom,&x))
dodaj(red,x);

return br;
}

int skini_dva(Red *red){
    int x;
    if(!skini(red,&x))
    return 0;
    else if(!skini(red,&x))
    return 1;
    else
    return 2;
}
int f1(Red *red){/* funkcija uvecaje sve elemente za 10 dok ne dodje do 0, taj broj i sve ostale smanji za 10*/
if(red->kraj==red->pocetak)
    return 0;
Red pom;
init(&pom);
int x;
int k=0;
while(skini(red,&x)){
  if(x==0)
  k=1;
  if(k==0){
         x+=10;
         dodaj(&pom,x);
         }
  else{
       x=x-10;
       dodaj(&pom,x);
       }
       }
  while(skini(&pom,&x))
  dodaj(red,x);
}
int skini_negativne_uvecaj_pozitivne(Red *red){/* izbacuje negativne elemente, pozitivne uvecaje za 1*/
if(red->kraj==red->pocetak)
    return 0;
    Red pom;
    init(&pom);
    int x;
    while(skini(red,&x)){
     if(x>0){
             x+=1;
             dodaj(&pom,x);
             }
             }
    while(skini(&pom,&x))
    dodaj(red,x);
}
int main()
{
	int element;
	Red red;
	init(&red);
	dodaj(&red, 4);
	dodaj(&red, -2);
	dodaj(&red, 0);
	dodaj(&red, 0);
	dodaj(&red, 7);
    ispis(&red);

	system("pause");
}
