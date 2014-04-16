#include "stdlib.h"
#include "stdio.h"
#define max(a,b) (a>=b?a:b)
/*
 * Inputs :
 * 	rotationRotor*
 * 	vitesseVent1
 *  vitesseVent2
 *  vitesseVent3
 *  arretUrgence
 * 
 * Outputs :
 *  imposerRegime
 *  freinerMiregime
 *  freinerMaxregime
 * 
 */

int etat;

int positionRotor; //*
int moyenneVents;
int differenceVents;


/*
 * calcul_Moyenne() : calcule la moyenne des vents détectés par les capteurs
 */
void calcul_Moyenne(){
	 moyenneVents = (vitesseVent[0][0] + vitesseVent[0][1] + vitesseVent[0][2])/3;
}

/*
 * difference_Vents : renvoie le max des différences des vitesse mesurées par chaque capteur de l'éolienne.
 */
void difference_Vents(){
	differenceVents = max(
					  	max(
							abs(vitesseVent[0][0]-vitesseVent[0][1]),
							abs(vitesseVent[0][1]-vitesseVent[0][2])
						),
						abs(vitesseVent[0][0]-vitesseVent[0][2])
					);
}

void etat_Arret(){
	if(moyenneVents>5) {
		etat = 1;
	}
	calcul_Moyenne();
	difference_Vents();
	//je suis a l'arret (envoyer etat)
}

void etat_Miregime(){
	if(moyenneVents<=5) {
		etat = 0;
	} else if(moyenneVents>15) {
		etat = 2;
	} else if(differenceVents>20) {
		etat = 3;
	}
	calcul_Moyenne();
	difference_Vents();
	//je suis en miregime (envoyer etat)
}

void etat_Maxregime(){
	if(moyenneVents<=15) {
		etat = 0;
	} else if(differenceVents>10) {
		etat = 1;
	} else if(moyenneVents>50) {
		etat = 3;
	}
	calcul_Moyenne();
	difference_Vents();
	//je suis en maxregime (envoyer etat)
}

void etat_Freinage(){
	while(1);
}


/*
 * imposerRegime() : modifie le régime courant de la rotation des pales de l'éolienne
 */
void imposerRegime(){
	calcul_Moyenne();
	difference_Vents();
	etat = 0;
	while(1){
		switch() {
			case 0 : etat_Arret(); 
				break;
			case 1 : etat_Miregime();
				break;
			case 2 : etat_Maxregime(); 
				break;
			case 3 : etat_Freinage();
				break;
			default :
				break;
		}
	}
}
