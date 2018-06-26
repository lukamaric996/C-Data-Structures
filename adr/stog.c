#include <stdio.h>
#define MAX 10

typedef struct s {
	int polje[MAX];
	int vrh;
}Stog;

void init(Stog *stog)
{
	stog->vrh = -1;
}

int dodaj(Stog *stog, int element)
{
	if (stog->vrh == MAX -1)
		return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = element;
	return 1;
}

int skini(Stog *stog, int *element)
{
	if (stog->vrh < 0)
		return 0;
	*element = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}

int zbroj(Stog *stog)
{
	int z = 0;
	int element;
	Stog pomStog;
	init(&pomStog);

	while (skini(stog, &element)){
		z += element;
		dodaj(&pomStog, element);
	}

	while (skini(&pomStog, &element))
		dodaj(stog, element);

	return z;
}

void izbaciNegativne(Stog *stog)/* izbacuje sve negativne elemente sa stoga */
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

void preuredi(Stog *stog){/* pozitivne elemente staviti iznad negativnih */
    Stog pomp,pomn;
    init(&pomp);
    init(&pomn);
    int x;
    while(skini(stog,&x)){
             if(x>0)
             dodaj(&pomp,x);
             else
             dodaj(&pomn,x);         
                         } 
    while(skini(&pomn,&x))
        dodaj(stog,x);
        
    while(skini(&pomp,&x))
          dodaj(stog,x);

}

int izbaci_neparne(Stog *stog){/* izbacuje neparne i vraca broj izbacenih*/
    
    Stog pom;
    init(&pom);
    int x,br=0;
    while(skini(stog,&x)){
      if(x%2==0)
        dodaj(&pom,x);
      else
        br++;
        }
    while(skini(&pom,&x))
        dodaj(stog,x);
        
        return br;
        }
        
 int prebroji_vece(Stog *stog,int broj){/* funkcija broji koliko u stogu ima elemenata koji su veci od prosljedjenog parametra */
    int br=0,x;
    if(stog->vrh==-1)
       return 0;
    
    Stog pom;
    init(&pom);
    
    while(skini(stog,&x)){
       if(x>broj)
         br++;
         
    dodaj(&pom,x);
    }
    
    while(skini(&pom,&x))
      dodaj(stog,x);
      
    return br;
}

void poduplaj_stog(Stog *stog){/*sve clanove stavi dva puta u stog */
     int x;
     Stog pom;
     init(&pom);
     while(skini(stog,&x)){
       dodaj(&pom,x);
       dodaj(&pom,x);
       }
     while(skini(&pom,&x))
         dodaj(stog,x);
         }

int skini_dva(Stog *stog){/*funkcija skida 2 elementa sa stoga ako je moguce, vraca broj skinutih elemenata */
      int x;
     if(skini(stog,&x)==0)
       return 0;
     else if(skini(stog,&x)==0)
         return 1;
     else
      return 2;
      }

int poke(Stog *stog, int m){/* zapisuje element na vrh stoga, broj elemenata ostaje nepromjenjen*/
    
    int x;
    if(skini(stog,&x)==0)
      return 0;
      
    dodaj(stog,m);
    return 1;
}

int izbacizadnji(Stog *stog){/* funkcija brise zadnji element sa stoga */
         
    if(stog->vrh==-1)
      return 0;
     
    int x; 
    Stog pom;
    init(&pom);
    
    while(skini(stog,&x))
         dodaj(&pom,x);
    
    skini(&pom,&x);
    
    while(skini(&pom,&x))
         dodaj(stog,x);
    
    return 1; 
    }
    
    int zamjena (Stog *stog){/* funkcija mijenja priv i zadnji element na stogu */
    
         if(stog->vrh<=0) /* ako stog ima manje od jendog elementa    */
            return 0;
            
         Stog pom;
         init(&pom);
         
         int prvi,zadnji,x;
         
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
    Stog pom;
    init(&pom);
    int element,k=0;
    if(stog->vrh==-1)
      return 0;
    while(skini(stog,&element)){
      if(element==0)
        k=1;
      if(k==0){
        element+=10;
        dodaj(&pom,element);
        }
      else{
           element-=10;
           dodaj(&pom,element);
           }
           }
     while(skini(&pom,&element))
       dodaj(stog,element);
      return 1;
      }
      
 int skini_negativne_uvecaj_pozitivne(Stog *stog){/* izbacuje negativne elemente, pozitivne uvecaje za 1*/
    Stog pom;
    int element;
    init(&pom);
    if(stog->vrh==-1)
       return 0;
    
   while(skini(stog,&element)){
      if(element>0){
        element+=1;
        dodaj(&pom,element);
        }
      else if(element==0)
        dodaj(&pom,element);
        }
   while(skini(&pom,&element))
      dodaj(stog,element);
      }
   Stog *urediStog(Stog *stog){
                    int x,suma=0,br=0;
                    float arit;
                    Stog pom;
                    init(&pom);
                    while(skini(stog,&x)){
                        dodaj(&pom,x);
                        }
                   while(skini(&pom,&x)){
                         suma+=x;
                         br++;
                         arit=(float)suma/br;
                         if(x>arit){
                         dodaj(stog,x);
                         }
                         }
                         return &pom;
                         }
int  main()
{
	Stog stog;
	init(&stog);
	
    dodaj(&stog, 1);
    dodaj(&stog, 5);
    dodaj(&stog, 3);
    dodaj(&stog, 7);
	dodaj(&stog, 9);
	dodaj(&stog, 2);
	dodaj(&stog, 6);
	dodaj(&stog, 0);
	dodaj(&stog, 3);
	dodaj(&stog,2);
    urediStog(&stog);
	ispis(&stog);
	

	
	system("pause>0");
}
