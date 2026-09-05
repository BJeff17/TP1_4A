typedef struct 
{
    float temp;
    float dist;
    char lumn;
} DonneeCapteur;

DonneeCapteur acquerir_donnee(); 
void afficher_donnee(DonneeCapteur *d);

