#include "fichier.h"

char * read_file(const char path[]){
    FILE *f;
    f = fopen(path, "r");
    char *text=(char *)malloc(2500*sizeof(char));
    *text = 0;
    char buff[MAX_BUFF_LEN];
    while (fgets(buff, MAX_BUFF_LEN-1, f))
    {
        buff[MAX_BUFF_LEN-1] = 0;
        strncat(text, buff, MAX_BUFF_LEN*sizeof(char));
    }
    fclose(f);
    return text;

}

void override_file(const char path[], char text[]){
    FILE *f;
    f = fopen(path, "w");
    fprintf(f, text);
    fclose(f);
}

void write_at_the_end(const char path[], char text[]){
    FILE *f;
    f = fopen(path, "a");
    fprintf(f, text);
    fclose(f);
}

char* donneeCapteurToString(DonneeCapteur *d){
    char *buff = (char *)malloc(MAX_BUFF_LEN*sizeof(char));
    *buff = 0;
    sprintf(buff, "%f,%f,%d\n", d->temp, d->dist, d->lumn);
    return buff;
}

DonneeCapteur stringToDonneeCapteur(char * str_d){
    char *temp;
    int count = 0;
    DonneeCapteur d = {0,0,0};
    do{
        temp = strtok(str_d,",");
	if (count==0) d.temp = parse(temp);
	if (count == 1) d.dist = parse(temp);
	if (count ==2) d.lumn=parse_int(temp);
	count ++;
    }while(count <=2);
    return d;
}


int sauvegarder_mesures(const char *nom_fichier, DonneeCapteur *tab, int n){
    for(int i=0;i<n;i++)
    write_at_the_end(nom_fichier, donneeCapteurToString(&tab[i]));
    return n;
}

int lire_mesures(const char *nom_fichier, DonneeCapteur *tab, int max){
	char *file_content = read_file(nom_fichier);
	char *next_line;
	int count = 0;
	while((next_line = strtok(file_content, "\n")) && count < max){
		if(count<max){
			*(tab+count*sizeof(DonneeCapteur)) = stringToDonneeCapteur(next_line);
			count++;
		}
	}
	return count;
}
