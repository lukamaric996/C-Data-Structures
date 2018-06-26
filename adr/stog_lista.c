#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct c {
	int broj;
	struct c *sljed;
}cvor;

typedef struct s {
	cvor *vrh;
}Stog;

cvor *noviCvor(int element)
{
	cvor *novi;
	novi = (cvor *)malloc(sizeof(cvor));
	if (novi == 0)
		return 0;
	novi->broj = element;
	novi->sljed = 0;
	return novi;
}

void init(Stog *stog)
{
	stog->vrh = 0;
}

int dodaj(Stog *stog, int element)
{
	cvor *pom = noviCvor(element);
	if (pom == 0)
		return 0;
	pom->sljed = stog->vrh;
	stog->vrh = pom;
	return 1;
}

int skini(Stog *stog, int *element)
{
	if (stog->vrh == 0)
		return 0;

	*element = stog->vrh->broj;
	cvor *pom = stog->vrh;
	stog->vrh = stog->vrh->sljed;
	free(pom);
	return 1;
}

int zbroj(Stog *stog)
{
	int z = 0;
	int element;
	Stog pomStog;
	init(&pomStog);

	while (skini(stog, &element) != 0) {
		z += element;
		dodaj(&pomStog, element);
	}

	while (skini(&pomStog, &element) != 0)
		dodaj(stog, element);

	return z;
}

void izbaciNegativne(Stog *stog)
{
	Stog pom;
	init(&pom);
	int element;
	while (skini(stog, &element)) {
		if (element > 0)
			dodaj(&pom, element);
	}

	while (skini(&pom, &element))
		dodaj(stog, element);
}


void obrniStog(Stog *stog)
{
	int element;
	Stog pom, pom2;
	init(&pom);
	init(&pom2);

	while (skini(stog, &element))
		dodaj(&pom, element);

	while (skini(&pom, &element))
		dodaj(&pom2, element);

	while (skini(&pom2, &element))
		dodaj(stog, element);
}

void umanji(Stog *stog, int umanjenje)
{
	Stog pom;
	init(&pom);
	int element;
	while (skini(stog, &element)) {
		element = element - umanjenje;
		dodaj(&pom, element);
	}

	while (skini(&pom, &element))
		dodaj(stog, element);
}

int peek(Stog *stog)
{
	int element;
	if (skini(stog, &element) == 0)
		return 0;
	element += 2;
	dodaj(stog, element);
	return 1;
}

void izbrisiStog(Stog *stog)
{
	int element;
	while (skini(stog, &element));
}

void ispis(Stog *stog)
{
	int element;
	Stog pom;
	init(&pom);

	while (skini(stog, &element) == 1) {
		printf("\n%d", element);
		dodaj(&pom, element);
	}

	while (skini(&pom, &element) == 1)
		dodaj(stog, element);
}

void preuredi (Stog *stog){/* pozitivne elemente staviti iznad negativnih */
   if(stog->vrh==0)
       return 0;
Stog pomn,pomp;
init(&pomp);
init(&pomn);
int element;
while(skini(stog,&element)){
  if(element>0)
     dodaj(&pomp,element);
  else
  dodaj(&pomn,element);
}
while(skini(&pomn,&element))
dodaj(stog,element);

while(skini(&pomp,&element))
dodaj(stog,element);
}

int izbaci_neparne(Stog *stog){/*funkcija izbacuje neparne elemente sa stoga i vraca broj izbacenih */
   if(stog->vrh==0)
       return 0;
int br=0;
int element;
Stog pom;
init(&pom);
while(skini(stog,&element)){
  if(element%2==0)
     dodaj(&pom,element);
  else
  br++;
}
while(skini(&pom,&element))
dodaj(stog,element);

return br;
}

 int zamjena (Stog *stog){/* funkcija mijenja priv i zadnji element na stogu */
  
  if(stog->vrh==0)
  return 0;
  int prvi,zadnji,x;
  Stog pom;
  init(&pom);
  skini(stog,&prvi);
  while(skini(stog,&x))
   dodaj(&pom,x);
  
  skini(&pom,&zadnji);
 
 dodaj(stog,prvi);
 while(skini(&pom,&x))
 dodaj(stog,x);
 
 dodaj(stog,zadnji);
 return 1;
}

int f1(Stog *stog){/* funkcija uvecaje sve elemente za 10 dok ne dodje do 0, taj broj i sve ostale smanji za 10*/

int x,k=0;
Stog pom;
if(stog->vrh==0)
return 0;
init(&pom);
while(skini(stog,&x)){
   if(x==0)
   k=1;
   if(k==0){
   x=x+10;
   dodaj(&pom,x);
}
else{
     x=x-10;
     dodaj(&pom,x);
     }
     }
while(skini(&pom,&x))
dodaj(stog,x);
return 1;
}
void main()
{
	//int element;
	Stog stog;
	init(&stog);

	dodaj(&stog, 5);
	dodaj(&stog, -0);
	dodaj(&stog, 46);
    f1(&stog);
	ispis(&stog);


	system("pause");
}
