#include "capteurs.h"
#include <stdio.h>



void afficher_donnee(DonneeCapteur *d){
    printf("Voici les donnees du capteur : ");
    printf("\tTempérature : %f degree celcius\n\tdistance : %f m\n\tluminosité : %d %", d->temp, d->dist, d->lumn);
}


DonneeCapteur acquerir_donnee(){
    // Ici on simule une acquisition de données
    int lumn=0;
    float temp, dist;
    
    printf("Entrez La temperature mesure en degre celcius: ");
    scanf("%f", &temp);

    do{
        printf("\nEntrez la distance mesure : ");
        scanf("%f", &dist);
    }while(0>dist);
    
    do
    {
        printf("Entrez la luminosite mesure (entier entre 1-100): ");
        scanf("%d", &lumn);
    }while(1>lumn || 100<lumn);
    
    return (DonneeCapteur){ temp, dist, lumn};

    
}