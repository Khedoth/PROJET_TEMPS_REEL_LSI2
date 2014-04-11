#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 *  forcageAlim*
 *  onOff*
 *  chargeBatterie
 *
 * Outputs :
 *  modeBatterie*
 *  choixDemux
 *  choixMux
 *
 */

BOOLEAN forcageAlim;
int etat;
int seuilRechargement;
int seuilUtilisation;

/*
 * Ensemble des états de la batterie selon les mux et démux :
 * 	Pour l'ensemble {Batterie, EDF} pour les mux et démux, on a ainsi 4 états possibles.
 */


/*
 * etat_Batterie_Batterie() :
 * PRECONDITIONS :
 * 	-
 */
void etat_Batterie_Batterie(){
	if(chargeBatterie == 100){
		etat = 1;
		choixDemux = 1;
	}

	else if(forcageALIM){
		etat = 3;
		choixMux = 1;
	}

	else if(chargeBatterie <= 15){
		etat = 5;
		choixMux = 1;
	}
}

void etat_Batterie_EDF_Forcage(){
	if(chargeBatterie == 100){
		etat = 4;
		choixDemux = 1;
	}

	else if (!forcageALIM){

		if(chargeBatterie <= seuilUtilisation){
			etat = 5;
		}

		else{
			etat = 2;
			choixMux = 0;
		}
	}
}

void etat_Batterie_EDF_Normal(){
	if(forcageALIM){
		etat = 3;
	}

	else if (chargeBatterie > seuilUtilisation){
		etat = 2;
		choixMux = 0;
	}

}

void etat_EDF_Batterie(){
	if (forcageALIM){
		etat = 4;
		choixMux = 1;
	}

	else if(chargeBatterie<=seuilRechargement){
		etat = 2;
		choixDemux = 0;
	}
}

void etat_EDF_EDF(){
	if (!forcageALIM){
		etat = 1;
		choixMux = 0;
	}
}

/*
 *
 */

void controleurBatterie(){

	while (1){
		switch(etat){
			case 1 : etat_EDF_Batterie();
				 break;
			case 2 : etat_Batterie_Batterie();
				 break;
			case 3 : etat_Batterie_EDF_Forcage();
				 break;
			case 4 : etat_EDF_EDF();
				 break;
			case 5 : etat_Batterie_EDF_Normal();
				 break;
			default : break;
		}

	chargeBatterie();
	}
}
