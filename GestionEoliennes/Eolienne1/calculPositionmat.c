#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 *  positionEolienne
 *  rotationMatH
 *  rotationMatAH
 *
 * Outputs :
 *  positionEolienne
 * 
 * Ressource critique : positionEolienne => semaphore sur positionEolienne
 * 
 * Informations des capteurs reçues toutes les secondes => file de message pour accumuler les infos
 * 
 */

/*
 * calculPositionMat() : calcule la position du mat en fonction des signaux provenant des capteurs du mât.
 */

void calculPositionMat(){
	int fileMessage[100];
	
	while(1){
		if(rotationMatH){
			positionEolienne[0]=(positionEolienne[0]-1)%360;
			//semGive();
		}

		else if (rotationMatAH){
			positionEolienne[0]=(positionEolienne[0]+1)%360;
			//semGive();
		}
	}

}
