#include "capteurs.h"
#define MAX_BUFF_LEN 256
int sauvegarder_mesures(const char *nom_fichier, DonneeCapteur *tab, int n);
int lire_mesures(const char *nom_fichier, DonneeCapteur *tab, int max);