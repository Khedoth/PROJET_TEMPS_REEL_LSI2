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
 * attente() : ne freine pas.
 */

void attente(){
	printf("Je suis en position 1");
}

/*
 * freinerMaxregime() : freine le rotor jusqu'à atteindre la moitié du régime max.
 */

void freiner_Maxregime(){
	if(freinerMaxregime){
		etat = 3;
		/* freiner(); // freiner = position
		 * JE SUIS EN POSITION 2
		 */
		wait(600); //attente de 10mn
	}
}

/*
 * freinerMiregime() : freine le rotor jusqu'à l'arrêt.
 */

void freiner_Miregime(){
	if(freinerMiregime){
		etat = 3;
		/* freiner(); //freiner = position
		 * JE SUIS EN POSITION 2
		 */
		wait(240); // attente de 4mn
	}

/*
 * freiner_Arret() : maintient le rotor à l'arrêt.
 */

void freiner_Arret(){
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
			case 0 : attente();
				 break;

			case 1 : freiner_Miregime();
				 break;

			case 2 : freiner_Maxregime();
				 break;

			case 3 : freiner_Arret();
				 break;

			default : attente();
				  break;

	}
}

