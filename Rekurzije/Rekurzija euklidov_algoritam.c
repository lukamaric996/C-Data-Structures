/* Napisati fju koja nalazi najvecu zajednicku mjeru rekurzivno pomocu euklidovog algoritma */
#include <stdio.h>
#include <stdlib.h>
int euklid (int a, int b){
    if(b==0){ 
             return a;
             }
    return euklid(b,a%b);
}
int main(int argc, char *argv[])
{
  printf("%d\n",euklid(15,45));
  system("PAUSE");	
  return 0;
}
