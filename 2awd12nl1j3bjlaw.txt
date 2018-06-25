#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c {
	int sifra; 						//šifra studenta
	char prezimeIme[70 + 1]; 		//Prezime i ime studenta
	int logickiObrisan; 			//Je li zapis logièki obrisan
	struct c *sljed;
} cvor;

cvor *noviCvor(cvor tmp) {

	cvor *novi = (cvor *)malloc(sizeof(cvor));
	if (novi == NULL)
		return NULL;
	novi->sifra = tmp.sifra;
	strcpy(novi->prezimeIme, tmp.prezimeIme);
	novi->logickiObrisan = tmp.logickiObrisan;
	novi->sljed = NULL;

	return novi;
}

int dodaj(cvor **glava, cvor tmp)
{
	cvor *novi = noviCvor(tmp);
	if (novi == NULL)
		return -1;

	if (*glava == NULL) {
		*glava = novi;
		return 1;
	}

	cvor*pom = *glava;
	while (pom->sljed != NULL)
		pom = pom->sljed;
	pom->sljed = novi;
	return 1;
}

int upisi(int sifra, cvor novi, cvor **glava) {
	cvor *pom=(cvor*)malloc(sizeof(cvor));
	pom->sljed=0;
	pom->logickiObrisan=novi.logickiObrisan;
	pom->sifra=novi.sifra;
	strcpy(pom->prezimeIme,novi.prezimeIme);
	if((*glava)->logickiObrisan==1){
		pom->sljed=*glava;
		*glava=pom;
		return 1;
	}
	else{
		cvor *pp2=*glava;
		while(pp2->sljed!=NULL){
			if((pp2)->sljed->logickiObrisan==1){
				pom->sljed=(pp2)->sljed;
				(pp2)->sljed=pom;
				return 1;
			}
			else
				pp2=(pp2)->sljed;
		}
		pp2->sljed=pom;
		return 1;
	}

	return 0;
}
void ispis(cvor *glava){
	while(glava){
		printf("%d %s %d \n",glava->sifra,glava->prezimeIme,glava->logickiObrisan);
		glava=glava->sljed;
	}
}
int main() {
	cvor *glava = NULL;
	cvor novi={ 303,"Ivo Ivica", 1 };
	cvor c1={ 300,"Ivo Ivic", 0 };
	cvor c2={ 301,"Ante Anic", 1 };
	cvor c3={ 302,"Pero Peric", 0 };
	dodaj(&glava, c1);
	dodaj(&glava, c2);
	dodaj(&glava, c3);
	upisi(novi.sifra,novi,&glava);
	ispis(glava);
	return 0;
}
