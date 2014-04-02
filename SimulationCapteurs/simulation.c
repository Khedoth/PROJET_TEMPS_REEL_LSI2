/*
 * Simulation.h : 
 * 		liste des prototypes simulant les signaux provenant des capteurs et de l'horloge.
 * 
 * 		==== calculPositionMat.c ====
 * 
 * 			rotationMatH_i
 * 			rotationMatAH_i
 * 		 
 * 		==== imposerRegime.c ====
 * 
 * 			vitesseVentj_i
 * 			rotationRotor_i
 * 	
 * 		==== orienterMat.c ====
 * 	
 * 			directionVent
 * 
 * 		==== controleurBatterie.c ====	
 * 
 * 			chargeBatterie
 *	
 * 		==== controleurLampadaires.c ====		
 * 		
 * 			eclairageGlobal
 * 			temps
 */

#include "simulation.h"



/*
 * rotationMatH_i : simule les signaux des capteurs de rotation des mâts dans le sens horaire
 * de l'éolienne i
 * 
 * void -> void
 */
void rotationMatH_1(void){
	
}
void rotationMatH_2(void);
void rotationMatH_3(void);

/*
 * rotationMatH_i : simule les signaux des capteurs de rotation des mâts dans le sens inverse du sens horaire
 * de l'éolienne i
 * 
 * void -> void
 */
void rotationMatAH_1(void);
void rotationMatAH_2(void);
void rotationMatAH_3(void);

/*
 * vitesseVentj_i : simule les signaux des capteurs de vitesse du vent en position j pour l'éolienne i.
 * 
 * pour j :
 * 		1 -> 2 mètres du sol
 * 		2 -> milieu du mât
 * 		3 -> sommet du mât
 * 
 * void -> void
 */
void vitesseVent1_1(void);
void vitesseVent1_2(void);
void vitesseVent1_3(void);

void vitesseVent2_1(void);
void vitesseVent2_2(void);
void vitesseVent2_3(void);

void vitesseVent3_1(void);
void vitesseVent3_2(void);
void vitesseVent3_3(void);

/*
 * rotationRotor_i : simule les signaux envoyés par le capteur de rotation du rotor de l'éolienne i
 * 
 * void -> void
 */
void rotationRotor_1(void);
void rotationRotor_2(void);
void rotationRotor_3(void);

/*
 * directionVent : simule le signal envoyé par le capteur de direction du vent moyen.
 * 
 * void -> void
 */
void directionVent(void);

/*
 * chargeBatterie : simule le signal envoyé par le capteur de niveau de charge de la batterie
 * 
 * void -> void
 */
void chargeBatterie(void);

/*
 * eclairageGlobal : simule le signal envoyé par le capteur d'éclairage global.
 * 
 * void -> void
 */
void eclairageGlobal(void);

/*
 * temps : simule le signal envoyé par l'horloge.
 * 
 * void -> void
 */
void temps(void);




