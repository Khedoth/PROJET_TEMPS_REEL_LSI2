#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 * 	directionVent
 * 	positionEolienne
 * 
 * Outputs :
 *  orienterMat
 *  commencerTimer
 *  resetTimer
 * 
 */

int etat;

void etat_Arret() {
	while(abs(positionEolienne[0]-directionVentMoyen)<10);
	if(positionEolienne[0]-directionVentMoyen>0) {
		rotationMatH_1();
	} else {
		rotationMatAH_1();	
	}
	commencerTimer();
	etat = 1;
}

void etat_Rotation() {
	while(abs(positionEolienne[0]-directionVentMoyen)<20);
		resetTimer();
		while(abs(positionEolienne[0]-directionVentMoyen)<10);
		etat = 0;
}

void orienterMat() {
	etat = 0;
	
	while(1) {
		switch(etat) {
		case 0 : etat_Arret();
			break;
		case 1 : etat_Rotation();
			break;
		default : break;
		}
	}
}
