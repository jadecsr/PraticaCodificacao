#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct voo
{
    char * data;
    char * hora;
    char * operacao;
    char * matricula;
    char * proced;
    char * destino;
    char * tipo;
};

void imprimeListaVoos(struct voo voos_arr[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("id: %d", n);
        printf("dt: %s ", voos_arr[n].data);
        printf("hr: %s ", voos_arr[n].hora);
        printf("op: %s ", voos_arr[n].operacao);
        printf("mt: %s ", voos_arr[n].matricula);
        printf("pcd: %s ", voos_arr[n].proced);
        printf("dst: %s ", voos_arr[n].destino);
        printf("tp: %s \n", voos_arr[n].tipo);          
    }
}

char *removeSpaces(char *str) {
    char *inp = str, *outp = str;
    int prevSpace = 0;

    while (*inp) {
        if (isspace(*inp)) {
            if (!prevSpace) {
                *outp++ = ' ';
                prevSpace = 1;
            }
        } else {
            *outp++ = *inp;
            prevSpace = 0;
        }
        ++inp;
    }
    *outp = '\0';
    return str;
}


struct voo voos_arr[217];

int main(){

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./entrada.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    getline(&line, &len, fp); // ignora a primeira linha

    int voo_idx = 0;

    while ((read = getline(&line, &len, fp)) != -1) {

        char * p_da_vez;

        // linha sem espacos
        line = removeSpaces(line);
        
        char * data;
        char * hora;
        char * operacao;
        char * matricula;
        char * proced;
        char * destino;
        char * tipo;
        

        data = strtok (line,", \n");
        printf("data -> %s", data);

        hora = strtok (NULL,", \n");
        printf(" hora -> %s", hora);

        operacao = strtok (NULL,", \n");
        printf(" operacao -> %s", operacao);

        matricula = strtok (NULL,", \n");
        printf(" matricula -> %s", matricula);
        
        proced = strtok (NULL,", \n");
        printf(" hora -> %s", hora);

        destino = strtok (NULL,", \n");
        printf(" destino -> %s", destino);

        tipo = strtok (NULL,", \n");
        printf(" tipo -> %s\n", tipo);

        /*voos_arr[voo_idx] = ( const struct voo){
            .data = strtok (line," "),
            .hora = strtok (NULL," "),
            .operacao = strtok (NULL," "),
            .matricula = strtok (NULL," "),
            .proced = strtok (NULL," "),
            .destino = strtok (NULL," "),
            .tipo = strtok (NULL," ")           
        };*/

        voo_idx++;
    }

    printf("%d\n",voo_idx);

    fclose(fp);
    if (line)
        free(line);

    return 0;    
}