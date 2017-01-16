#include <stdio.h>
#define TAM 8

int mat[TAM][TAM];
int i, j;

void verifica11(int i,int j){
	if  ((i+2 < TAM) && (i+1 < TAM))
		if ((mat[i+1][j] == 1) && (mat[i+2][j] == 1)) //verificar sul
			mat[i][j] = 0;
	if ((i-2 >= 0) && (i-1 >=0))
		if ((mat[i-1][j] == 1) && (mat[i-2][j] == 1)) //verificar norte
			mat[i][j] = 0;
	if ((j+2 < TAM) && (j+1 < TAM))
		if ((mat[i][j+1] == 1) && (mat[i][j+2] == 1)) //verificar leste
			mat[i][j] = 0;
	if ((j-2 >= 0) && (j-1 >= 0))
		if ((mat[i][j-1] == 1) && (mat[i][j-2] == 1)) //verificar oeste
			mat[i][j] = 0;
}

void verifica00(int i,int j){
	if ((i+2 < TAM) && (i+1 < TAM))
		if ((mat[i+1][j] == 0) && (mat[i+2][j] == 0)) //verificar sul
			mat[i][j] = 1;
	if ((i-2 >= 0) && (i-1 >=0))
		if ((mat[i-1][j] == 0) && (mat[i-2][j] == 0)) //verificar norte
			mat[i][j] = 1;
	if ((j+2 < TAM) && (j+1 < TAM))
		if ((mat[i][j+1] == 0) && (mat[i][j+2] == 0)) //verificar leste
			mat[i][j] = 1;
    if ((j-2 >= 0) && (j-1 >= 0))
		if ((mat[i][j-1] == 0) && (mat[i][j-2] == 0)) //verificar oeste
			mat[i][j] = 1;
}

void verifica1x1(int i, int j) {
	if ((j-1 >= 0) && (j+1 <TAM))
		if ((mat[i][j-1] == 1) && (mat[i][j+1] == 1)) //verifica horizontalmente
			mat[i][j] = 0;
	if ((i-1 >= 0) && (i+1 <TAM))
		if ((mat[i-1][j] == 1) && (mat[i+1][j] == 1)) //verifica verticalmente
			mat[i][j] = 0;	
}

void verifica0x0(int i, int j) {
	if ((j-1 >= 0) && (j+1 <TAM))
		if ((mat[i][j-1] == 0) && (mat[i][j+1] == 0)) //verifica horizontalmente
			mat[i][j] = 1;
	if ((i-1 >= 0) && (i+1 <TAM))
		if ((mat[i-1][j] == 0) && (mat[i+1][j] == 0)) //verifica verticalmente
			mat[i][j] = 1;	
}

void resolveJogo(){
    int aux;
	int k;
    for (k = 0; k < TAM; k++){
		for(i = 0; i < TAM; i++) {	
			int cont0l = 0;
   		    int	cont0c = 0;
    		int cont1l = 0;
    		int cont1c = 0;
			for(j = 0; j < TAM; j++){		
				if (mat[i][j] == 2)	{
					verifica11(i, j);
       			    verifica00(i, j);
					verifica0x0(i, j);
        			verifica1x1(i, j);
				}
				if (mat[i][j] == 0)
					cont0l++;
				else if (mat[i][j] == 1)
					cont1l++;
				if (mat[j][i] == 0)
					cont0c++;
				else if (mat[j][i] == 1)
					cont1c++;
			}
			if (cont0l == (int) TAM/2)
				for (aux = 0; aux < TAM; aux++)
					if (mat[i][aux] == 2)
						mat[i][aux] = 1;
			if (cont1l == (int) TAM/2)
				for (aux = 0; aux < TAM; aux++)
					if (mat[i][aux] == 2)
						mat[i][aux] = 0;
			if (cont0c == (int) TAM/2)
				for (aux = 0; aux < TAM; aux++)
					if (mat[aux][i] == 2)
						mat[aux][i] = 1;
			if (cont1c == (int) TAM/2)
				for (aux = 0; aux < TAM; aux++)
					if (mat[aux][i] == 2)
						mat[aux][i] = 0;
		}
	}
}

void imprimeJogo() {
	printf("\n\n\n");
	for(i = 0; i < TAM; i++) {	
		for(j = 0; j < TAM; j++){	
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

int main()  {
	for(i = 0; i < TAM; i++) {	
		for(j = 0; j < TAM; j++){	
			scanf("%d ",&mat[i][j]);
		}
	}
	
	resolveJogo();
    imprimeJogo();
    return 0;
}
