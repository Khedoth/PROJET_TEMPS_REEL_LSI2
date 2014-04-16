#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 * 	temps
 *  eclairageGlobal
 *  onOff*
 *  modeBatterie
 * 
 * Outputs :
 *  reglageTension
 * 
 */

/*
 *
 */

int puissance;
int etat;
int modeOnduleur;

void calculPuissance() {
	switch(modeOnduleur) {
		case 0 : reglageTension = 0;
			break;
		case 1 : reglageTension = 80;
			break;
		case 2 : reglageTension = 120;
			break;
		case 3 : reglageTension = 160;
			break;
		case 4 : reglageTension = 180;
			break;
		case 5 : reglageTension = 220;
			break;
		default : break;
	}
}


void etat_Nuit_Eco(){
	while(temps <= 21600||modeBatterie == 0) {
		if(eclairageGlobal <= 60 && modeOnduleur != 5) {
			modeOnduleur++;
		}
		
		calculPuissance();
		eclairageGlobal(reglageTension);
	}
	if(temps >= 21600) {
		etat = 2;
	} else if(modeBatterie == 0) {
		etat = 1;
	}
}

void etat_Nuit(){
	while(temps <= 21600||modeBatterie == 1) {
		if(eclairageGlobal <= 60 && modeOnduleur != 5) {
			modeOnduleur++;
		}
		
		calculPuissance();
		eclairageGlobal(reglageTension);
	}
	if(temps >= 21600) {
		etat = 2;
	} else if(modeBatterie == 0) {
		etat = 0;
	}
}

void etat_Matin(){
	while(temps <= 32400) {
		if(eclairageGlobal <= 80 && modeOnduleur != 5) {
			modeOnduleur++;
		}
		
		calculPuissance();
		eclairageGlobal(reglageTension);
	}
	
	etat = 3;
}

void etat_Journee(){
	while(temps <= 64800) {
		modeOnduleur==0;
	}
	
	etat = 4;
}

void etat_Soir(){
	while(temps <= 75600) {
		if(eclairageGlobal <= 60 && modeOnduleur != 5) {
			modeOnduleur++;
		}
		
		calculPuissance();
		eclairageGlobal(reglageTension);
	}
	
	if(modeBatterie == 1) {
		etat = 1;
	}
	else {
		etat = 0;
	}
}

void controleurLampadaire(){
	generationTemps();
	
	while (1){
		switch(etat){
			case 0 : etat_Nuit_Eco();
				break;
			case 1 : etat_Nuit();
				break;
			case 2 : etat_Matin();
				break;
			case 3 : etat_Journee();
				break;
			case 4 : etat_Soir();
				break;
			default : break;
		}
	}
}

void generationTemps() {
	while(1) {
		wait(1); //a verifier
		temps();
	}
}