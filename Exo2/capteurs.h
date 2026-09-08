#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "utils.h"

typedef struct 
{
    float temp;
    float dist;
    char lumn;
} DonneeCapteur;

DonneeCapteur acquerir_donnee(); 
void afficher_donnee(DonneeCapteur *d);

