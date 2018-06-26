#include <stdio.h>
#include <stdlib.h>

typedef struct c {
	int broj;
	struct c *sljed;
}cvor;

typedef struct r{
	cvor *pocetak;
	cvor *kraj;
}Red;

void init(Red *red)
{
	red->kraj = NULL;
	red->pocetak = NULL;
}

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

int dodaj(Red *red, int element)
{
	cvor *novi = noviCvor(element);
	if (novi == NULL)
		return 0;
	if (red->kraj == NULL) 
		red->pocetak = novi;
	else
		red->kraj->sljed = novi;
	red->kraj = novi;
	return 1;
}

int skini(Red *red, int *element)
{
	cvor *pom;
	if (red->pocetak == NULL)
		return 0;
	pom = red->pocetak;
	*element = pom->broj;
	red->pocetak = red->pocetak->sljed;
	free(pom);
	if (red->pocetak == NULL)
		red->kraj = NULL;
	return 1;
}

void izbaciNajveci(Red *red)
{
	int max;
	int element;
	Red pom;
	init(&pom);
	skini(red, &max);
	dodaj(&pom, max);
	while (skini(red, &element) == 1) {
		dodaj(&pom, element);
		if (element > max)
			max = element;
	}

	while (skini(&pom, &element) == 1)
		if(element != max)
			dodaj(red, element);

}


void ispis(Red *red){
     Red pom;
     init(&pom);
     int x;
     while(skini(red,&x)){
      printf("%d\n",x);
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

int main()
{
	int element;
	Red red;
	init(&red);
	dodaj(&red, 5);
	dodaj(&red, 10);
	dodaj(&red, 1644);
	dodaj(&red, 603);
	dodaj(&red, 606);
	izbaciNajveci(&red);
	ispis(&red);
    system("pause");
}
