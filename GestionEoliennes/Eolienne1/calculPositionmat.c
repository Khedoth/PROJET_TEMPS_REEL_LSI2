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
 */

/*
 * calculPositionMat() : calcule la position du mat en fonction des signaux provenant des capteurs du mât.
 */

void calculPositionMat(){
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
