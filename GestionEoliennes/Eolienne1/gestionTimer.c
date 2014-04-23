#include "stdlib.h"
#include "stdio.h"

/*
 * Inputs :
 * 	resetTimer
 * 	commencerTimer
 * 
 * Outputs :
 *  alarme
 * 
 */

int secondes;
BOOLEAN start;

void commencerTimer(){
	start = true;
	while(start || secondes <= 900) {
		wait(1000);
		secondes++;
	}
	
	if(secondes >= 900) {
		alarme();
	}
	
	secondes = 0;
}

void resetTimer(){
	start = false;
}

void gestionTimer(){
	secondes = 0;
	start = false;
}