/*Napisat rekurzivnu funkciju koja �e obaviti operaciju modulo � ostatka cijelobrojnog
dijeljenja (%) integera a sa integerom b koriste�i se samo operacinom oduzimanja. */
#include <stdio.h>
#include <stdlib.h>
int modulo (int a, int b)
{
if( b > a )
return a;
return modulo(a-b, b);
}

int main(){
    printf("%d\n",modulo(15,4));
    system("pause");
}
