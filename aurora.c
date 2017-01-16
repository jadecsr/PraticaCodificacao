#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct aviao {
	char indicativo[7];
	int nivel;
	int proa;
} Aviao ;

typedef struct conflito {
	char indicativo[7];
	int con1;        // 1 - conflito proa a proa, 2 - voando em nível incorreto pra proa, 3 - voando abaixo do 080 ou 410
	int con2;
	int con3;
}Conflito;

int main () {
	int n,i,aux,t,j;
	scanf("%d",&n);
	Aviao vet[n];
    Conflito  con[n];
    
    for(i=0; i<n; i++) {
    	con[i].con1 = 0;
    	con[i].con2 = 0;
    	con[i].con3 = 0;
    }
    
	aux = 0;
	int achou = 0;
	for(i=0; i<n; i++) {
		scanf("%s %d %d",vet[i].indicativo,&vet[i].nivel,&vet[i].proa);
		if ((vet[i].nivel < 80) || (vet[i].nivel > 410)) { // verificacao do conflito 3
			strcpy(con[aux].indicativo,vet[i].indicativo);
			con[aux].con3 = 1;
			achou = 1;
		}
		if ((vet[i].proa >=0) && (vet[i].proa <=179)) { // verificacao do conflito 2
			if ((vet[i].nivel/10) %2 == 0) {
				strcpy(con[aux].indicativo,vet[i].indicativo);
				con[aux].con2 = 1;
				achou = 1;
			}
		} else {
			if ((vet[i].nivel/10) %2 == 1) {
				strcpy(con[aux].indicativo,vet[i].indicativo);
				con[aux].con2 = 1;
				achou = 1;
			}
		}
		if (achou == 1) {
			aux++;
			achou = 0;
		}
			
	}
	
	for (i=0; i<n; i++) 
		for (j = i+1; j<n; j++) {
			if ((vet[i].nivel == vet[j].nivel) && ((vet[i].proa - vet[j].proa == 180) || (vet[j].proa - vet[i].proa == 180))) {
				for (t = 0; t < aux; t++) {
					if ((strcmp(con[t].indicativo,vet[i].indicativo))||(strcmp(con[t].indicativo,vet[j].indicativo)))
						if (con[t].con2 == 1) {
							con[t].con1 = 1;
							break;
						}
				}
			//	break;
			}					
		}
		
/*	if (aux == 0) {
		printf("\nCLEAR");
	} else {
		for (i = 0; i < aux; i++) {
			printf("%s ",con[i].indicativo);
			if (con[i].con1 == 1)
				printf("1 ");
			if (con[i].con2 == 1)
				printf("2 ");
			if (con[i].con3 == 1)
				printf("3 ");
			printf("\n");
		}
	}*/

	return 0;
}
