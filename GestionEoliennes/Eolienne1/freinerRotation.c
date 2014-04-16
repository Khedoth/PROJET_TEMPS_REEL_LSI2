#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 *  freinerMiregime
 *  freinerMaxregime
 *
 * Outputs :
 *  freiner
 *
 */

int freinerMiregime;
int freinerMaxregime;
int position;


/*
 * etat_Attente() : ne freine pas.
 */

void etat_Attente(){
	printf("Je suis en position 1");
}

/*
 * etat_Freiner_Maxregime() : freine le rotor jusqu'à atteindre la moitié du régime max.
 */

void etat_Freiner_Maxregime(){
	if(freinerMaxregime){
		etat = 3;
		/* freiner(); // freiner = position
		 * JE SUIS EN POSITION 2
		 */
		wait(600); //attente de 10mn
	}
}

/*
 * etat_Freiner_Miregime() : freine le rotor jusqu'à l'arrêt.
 */

void etat_Freiner_Miregime(){
	if(freinerMiregime){
		etat = 3;
		/* freiner(); //freiner = position
		 * JE SUIS EN POSITION 2
		 */
		wait(240); // attente de 4mn
	}

/*
 * etat_Freiner_Arret() : maintient le rotor à l'arrêt.
 */

void etat_Freiner_Arret(){
	/* freiner(); //freiner = position
	 * JE SUIS A L'ARRET (POSITION 3)
	 */
	while(1); //attente en position 3
}


/*
 * freinerRotation() : envoie un signal freiner() dont la valeur dépend de la valeur du signal reçu du module "Imposer Régime"
 */
void freinerRotation(){
	etat = 0;

	while(1){

		switch(etat){
			case 0 : etat_Attente();
				 break;

			case 1 : etat_Freiner_Miregime();
				 break;

			case 2 : etat_Freiner_Maxregime();
				 break;

			case 3 : etat_Freiner_Arret();
				 break;

			default : etat_Attente();
				  break;

	}
}

