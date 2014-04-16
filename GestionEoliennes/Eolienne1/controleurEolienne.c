#include "stdlib.h"
#include "stdio.h"

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


 /*
  *
  */
void controleurEolienne(){
	while(1){
		if(alarme()){
			arretUrgence();
		}
}
