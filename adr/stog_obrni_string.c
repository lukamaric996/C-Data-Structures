#include <stdio.h>
#define MAX 10

typedef struct s {
	char polje[MAX];
	int vrh;
}Stog;

void init(Stog *stog)
{
	stog->vrh = -1;
}

int dodaj(Stog *stog, char element)
{
	if (stog->vrh == MAX -1)
		return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = element;
	return 1;
}

int skini(Stog *stog, char *element)
{
	if (stog->vrh < 0)
		return 0;
	*element = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}

int obrni(Stog *stog,char *rec){
    int i;
    char slovo;
    for(i=0;i<strlen(rec);i++)
    dodaj(stog,rec[i]);
    
    for(i=0;i<strlen(rec);i++){
     skini(stog,&slovo);
     rec[i]=slovo;
     }

    
}
   
int  main()
{
	Stog stog;
	init(&stog);
	
   char rec[50];
   scanf("%s",rec);
	obrni(&stog,&rec);
printf("%s",rec);
	

	
	system("pause>0");
}
