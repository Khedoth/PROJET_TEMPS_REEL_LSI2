#include "stdlib.h"
#include "stdio.h"
#include "simulation.h"

/*
 * Inputs :
 *  alarme
 *  onOff
 *  arretUrgence
 *
 * Outputs :
 *  arretUrgence
 *  alarme
 *
 */

void arretUrgence() {
	arretUrgence = true;
}

void alarme() {
	//afficher alarme
}

void on_off() {
	
}

 /*
  * controleurEolienne() :
  */
void controleurEolienne(){
	
	semTake(sem_Eolienne[10], WAIT_FOREVER);
	
}
