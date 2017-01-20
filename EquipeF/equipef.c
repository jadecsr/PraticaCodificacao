#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {

	char stringEntrada[100];
	//char vetor[][];
	char vetor[1600][20];
	char datas[220][20];
	int k;
	FILE *entrada;
	entrada = fopen("entrada.txt", "r");
	int i = 0;

	if (entrada == NULL) {
		printf("Não encontrado");
		exit(EXIT_FAILURE);
	}

	while (1 > 0) {
		k = fscanf(entrada, "%s", stringEntrada);
		if (k != 1) break;

		strcpy(vetor[i], stringEntrada);
		i++;
		//printf("%s\n", stringEntrada);
	}
	
	// Printa as posições do vetor auxiliar
	for (int j = 0; j < i; j++){
		printf("%i\n", j);
	}

	for (int k = 0; k < i; k = k + 7) {
		printf("%s\n", vetor[k]);
	}

	fclose(entrada);

	return 0;
}
