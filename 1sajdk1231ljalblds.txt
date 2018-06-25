#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct c {
	int sifra; 						//šifra studenta
	char prezimeIme[70 + 1]; 		//Prezime i ime studenta
	struct c *sljed;
} cvor;


typedef struct {
	cvor *ulaz;
	cvor *izlaz;

}Red;

void initRed(Red *red) {
	red->izlaz = NULL;
	red->ulaz = NULL;
}

cvor *noviCvor(int element,char *ime){
	cvor *novi;
	novi = (cvor *)malloc(sizeof(cvor));
	if (novi == 0)
        return 0;
	novi->sifra = element;
	strcpy(novi->prezimeIme,ime);
	novi->sljed = 0;
	return novi;
}

int dodaj(Red *red, int element,char *ime){
	cvor *novi = noviCvor(element,ime);
	if (novi == NULL) return 0;
	if (red->izlaz == NULL)
		red->ulaz = novi;
	else
		red->izlaz->sljed = novi;
	red->izlaz = novi;
	return 1;
}
int skini(Red *red, int *element,char **ime){
	cvor *pom;
	if (red->ulaz == NULL)
		return 0;
	pom = red->ulaz;
	*element = pom->sifra;
	*ime=(char*)malloc(sizeof(pom->prezimeIme)+1);
	strcpy(*ime,pom->prezimeIme);
	red->ulaz = red->ulaz->sljed;
    free(pom);
	if (red->ulaz == NULL)
		red->izlaz = NULL;
	return 1;
}

int main() {
	Red red;
	initRed(&red);
	int a;
	char *ime;
	dodaj(&red, 5,"Matic Toni");
	dodaj(&red,2,"Marusic Maja");
	dodaj(&red, 4,"Trale Pero");
	skini(&red,&a,&ime);
	printf("%d %s",a,ime);
	return 0;
}
