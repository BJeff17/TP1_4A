#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * read_file(char path[]){
    FILE *f;
    f = fopen(path, 'r');
    char text[2500];
    char buff[MAX_BUFF_LEN];
    while (feof(f))
    {
        fget(buff, MAX_BUFF_LEN-1, f);
        buff[MAX_BUFF_LEN-1] = 0;
        strncat(text, buff, MAX_BUFF_LEN*sizeof(char));
    }
        
    
    return text;

}

void override_file(char path[], char text[]){
    FILE *f;
    f = fopen(path, 'w');
    fprintf(f, text);
    fclose(f);
}

void write_at_the_end(char path[], char text[]){
    FILE *f;
    f = fopen(path, 'a');
    fwrite(text, sizeof(char), sizeof(char)*(strlen(text)+1), f);
    fclose(f);
}

char* donneeCapteurToString(DonneeCapteur *d){
    char buff[MAX_BUFF_LEN];
    sprintf(buff, "%f,%f,%d\n", d->temp, d->dist, d->lumn);
    return buff;
}
DonneeCapteur stringToDonneeCapteur(char * str_d){
    char *temp;
    do{
        temp = strtok(str_d,",");
    }while(temp);
    
}


void sauvegarder_mesures(const char *nom_fichier, DonneeCapteur *tab, int n){
    for(int i=0;i<n;i++)
    write_at_the_end(nom_fichier, donneeCapteurToString(&tab[i]));
}
int lire_mesures(const char *nom_fichier, DonneeCapteur *tab, int max){

}

