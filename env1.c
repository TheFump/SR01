#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void)
{
char varenv [50] ;
char varenvcpy [100];
char buffer [50];
int i;
	printf("entrez le nom de la variable d'environnement : \n");
	scanf("%s", &varenv);
	printf("%s \n", varenv);
	puts(".");
 	strcpy(buffer, getenv(varenv));
	puts(".");
	printf("Valeur de la variable : %s\n", buffer);
	puts(".");
	strcpy(varenvcpy, varenv);
	strcat(varenvcpy, "= Un_exemple_de_variable_modifiee");
	putenv(varenvcpy);
	strcpy(buffer, getenv(varenv));
	printf("Valeur de la variable : %s\n", buffer);
	
return 0;
}

