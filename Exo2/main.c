#include "utils.h"
#include "fichier.h"
#include "capteurs.h"
#include "stats.h"


int main(){
    DonneeCapteur capteur[3];
    for(int i=0; i<3; i++){

	capteur[i] = acquerir_donnee();
	}
	
	sauvegarder_mesures("save_mes.cpt", capteur, 3);
	return 0;


}
