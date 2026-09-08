#pragma once
#include "capteurs.h"
#include "fichier.h"
#include "utils.h"



int main(){
	const int N = 3;
	DonneeCapteur tab[N];
	for (int i=0; i<N; i++){
		tab[i] = acquerir_donnee();
	}
	sauvegarder_mesures("breackpoint.cpt", tab, N);
	return 0;


}
