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
 * Variables Globales
 */

int positionEolienne[NB_EOL];
int positionRotor[NB_EOL];
int directionVentMoyen;
int vitesseVent[NB_EOL][NB_CAP];
int choixMux;
int choixDemux;
int regimeEolienne[NB_EOL];
int tensionOnduleur;
int eclairageGlobal;
int chargeBatterie;
int variatonCharge;
int temps;
int alimEol;
int consoLamp;
BOOLEAN etatSysteme;



void routineIT_RMH1() {
	positionEolienne[0]=(positionEolienne[0]+1)%360;
	//semGive();
}
void routineIT_RMH2() {
	positionEolienne[1]=(positionEolienne[1]+1)%360;
	//semGive();
}
void routineIT_RMH3() {
	positionEolienne[1]=(positionEolienne[1]+1)%360;
	//semGive();
}

void routineIT_RMAH1() {
	positionEolienne[0]=(positionEolienne[0]-1)%360;
	//semGive();
}
void routineIT_RMAH2()  {
	positionEolienne[1]=(positionEolienne[1]-1)%360;
	//semGive();
}
void routineIT_RMAH3() {
	positionEolienne[2]=(positionEolienne[2]-1)%360;
	//semGive();
}

void routineIT_DVM() {
	int coefVar = rand()*50;

	if(rand()==0) {
		directionVentMoyen=(directionVentMoyen-ceofVar)%360
	} else {
		directionVentMoyen=(directionVentMoyen+coefVar)%360;
	}
	//semGive();
}

void routineIT_RR1() {
	positionRotor[0]=(positionRotor[0]+10)%360;
	//semGive();
}

void routineIT_RR2()  {
	positionRotor[1]=(positionRotor[1]+10)%360;
	//semGive();
}
void routineIT_RR3()  {
	positionRotor[2]=(positionRotor[2]+10)%360;
	//semGive();
}

void routineIT_VV1_1() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[0][0]-ceofVar)<=0) {
			vitesseVent[0][0]=0;
		} else {
			vitesseVent[0][0]-=ceofVar;
		}

	} else {
		vitesseVent[0][0]+=ceofVar;
	}
	//semGive();
}
void routineIT_VV1_2() 	{
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[1][0]-ceofVar)<=0) {
			vitesseVent[1][0]=0;
		} else {
			vitesseVent[1][0]-=ceofVar;
		}

	} else {
		vitesseVent[1][0]+=ceofVar;
	}
	//semGive();
}
void routineIT_VV1_3() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[2][0]-ceofVar)<=0) {
			vitesseVent[2][0]=0;
		} else {
			vitesseVent[2][0]-=ceofVar;
		}

	} else {
		vitesseVent[2][0]+=ceofVar;
	}
	//semGive();
}

void routineIT_VV2_1() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[0][1]-ceofVar)<=0) {
			vitesseVent[0][1]=0;
		} else {
			vitesseVent[0][1]-=ceofVar;
		}

	} else {
		vitesseVent[0][1]+=ceofVar;
	}
	//semGive();
}
void routineIT_VV2_2() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[1][1]-ceofVar)<=0) {
			vitesseVent[1][1]=0;
		} else {
			vitesseVent[1][1]-=ceofVar;
		}

	} else {
		vitesseVent[1][1]+=ceofVar;
	}
	//semGive();
}
void routineIT_VV2_3() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[2][1]-ceofVar)<=0) {
			vitesseVent[2][1]=0;
		} else {
			vitesseVent[2][1]-=ceofVar;
		}

	} else {
		vitesseVent[2][1]+=ceofVar;
	}
	//semGive();
}

void routineIT_VV3_1() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[0][2]-ceofVar)<=0) {
			vitesseVent[0][2]=0;
		} else {
			vitesseVent[0][2]-=ceofVar;
		}

	} else {
		vitesseVent[0][2]+=ceofVar;
	}
	//semGive();
}
void routineIT_VV3_2() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[1][2]-coefVar)<=0) {
			vitesseVent[1][2]=0;
		} else {
			vitesseVent[1][2]-=coefVar;
		}

	} else {
		vitesseVent[1][2]+=coefVar;
	}
	//semGive();
}
void routineIT_VV3_3() {
	int coefVar = rand()*50;

	if(rand()==0) {
		if((vitesseVent[2][2]-coefVar)<=0) {
			vitesseVent[2][2]=0;
		} else {
			vitesseVent[2][2]-=coefVar;
		}

	} else {
		vitesseVent[2][2]+=coefVar;
	}
	//semGive();
}

void routineIT_CB() {
	chargeBatterie+=charge;;
	//semGive();
}

void routineIT_EG() {
	int eclairageNaturel;
	int eclairageLampadaire;

	eclairageNaturel = rand()*50; // achanger

	// eclairageLampadaire = tensionOnduleur*coef; a changer

	eclairageGlobal = (eclairageNaturel + eclairageLampadaire) / puissance;
	//semGive
}

void routineIT_T() {
	temps=(temps+1)%86400;
	//semGive
}

void initSignaux(){
			/*
			 * Rotation Mât sens horaire
			 */
		if(signal(SRMH1, routineIT_RMH1) == SIG_ERR){
			printf("Problème signal RMH1\n");
		}

		if(signal(SRMH2, routineIT_RMH2) == SIG_ERR){
			printf("Problème signal RMH2\n");
		}

		if(signal(SRMH3, routineIT_RMH3) == SIG_ERR){
			printf("Problème signal RMH3\n");
		}

			/*
			 * Rotation Mât sens anti-horaire
			 */
		if(signal(SRMAH1, routineIT_RMAH1) == SIG_ERR){
			printf("Problème signal RMAH1\n");
		}

		if(signal(SRMAH2, routineIT_RMAH2) == SIG_ERR){
			printf("Problème signal RMAH2\n");
		}

		if(signal(SRMAH3, routineIT_RMAH3) == SIG_ERR){
			printf("Problème signal RMAH3\n");
		}

			/*
			 * Direction du vent moyen
			 */
		if(signal(SDVM, routineIT_DVM) == SIG_ERR){
			printf("Problème signal DVM\n");
		}

			/*
			 * Rotation Rotor
			 */
		if(signal(SRR1, routineIT_RR1) == SIG_ERR){
			printf("Problème signal RR1\n");
		}

		if(signal(SRR2, routineIT_RR2) == SIG_ERR){
			printf("Problème signal RR2\n");
		}

		if(signal(SRR3, routineIT_RR3) == SIG_ERR){
			printf("Problème signal RR3\n");
		}

			/*
			 * Vitesse du vent
			 */
		if(signal(SVV1_1, routineIT_VV1_1) == SIG_ERR){
			printf("Problème signal VV1_1\n");
		}

		if(signal(SVV1_2, routineIT_VV1_2) == SIG_ERR){
			printf("Problème signal VV1_2\n");
		}

		if(signal(SVV1_3, routineIT_VV1_3) == SIG_ERR){
			printf("Problème signal VV1_3\n");
		}


		if(signal(SVV2_1, routineIT_VV2_1) == SIG_ERR){
			printf("Problème signal VV2_1\n");
		}

		if(signal(SVV2_2, routineIT_VV2_2) == SIG_ERR){
			printf("Problème signal VV2_2\n");
		}

		if(signal(SVV2_3, routineIT_VV2_3) == SIG_ERR){
			printf("Problème signal VV2_3\n");
		}


		if(signal(SVV3_1, routineIT_VV3_1) == SIG_ERR){
			printf("Problème signal VV3_1\n");
		}

		if(signal(SVV3_2, routineIT_VV3_2) == SIG_ERR){
			printf("Problème signal VV3_2\n");
		}

		if(signal(SVV3_3, routineIT_VV3_3) == SIG_ERR){
			printf("Problème signal VV3_3\n");
		}

		/*
		 * Charge Batterie
		 */
		if(signal(SCB, routineIT_CB) == SIG_ERR){
			printf("Problème signal CB\n");
		}

		/*
		 * Eclairage Global
		 */
		if(signal(SEG, routineIT_EG) == SIG_ERR){
			printf("Problème signal EG\n");
		}

		/*
		 * Temps
		 */
		if(signal(ST, routineIT_T) == SIG_ERR){
			printf("Problème signal T\n");
		}
}

/*
 * rotationMatH_i : simule les signaux des capteurs de rotation des mâts dans le sens horaire
 * de l'éolienne i
 *
 * void -> void
 */
void rotationMatH_1(int arg) {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0&etatSysteme) {
			raise(SRMH1)
			//attendre t
			temp--;
		}
	}
}
void rotationMatH_2(int arg) {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0&etatSysteme) {
			raise(SRMH2);
			//attendre t
			temp--;
		}
	}
}
void rotationMatH_3(int arg)  {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0&etatSysteme) {
			raise(SRMH3);
			//attendre t
			temp--;
		}
	}
}

/*
 * rotationMatH_i : simule les signaux des capteurs de rotation des mâts dans le sens inverse du sens horaire
 * de l'éolienne i
 *
 * void -> void
 */
void rotationMatAH_1(int arg)  {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0&etatSysteme) {
			raise(SRMAH1);
			//attendre t
			temp--;
		}
	}
}
void rotationMatAH_2(int arg)  {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0&etatSysteme) {
			raise(SRMAH2);
			//attendre t
			temp--;
		}
	}
}
void rotationMatAH_3(int arg)  {
	if(!etatSysteme) {
		int temp = arg;
		while(temp!=0) {
			raise(SRMAH3);
			//attendre t
			temp--;
		}
	}
}

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
void vitesseVent1_1(void) {
	while(etatSysteme) {
		raise(SVV1_1);
		//attendre t
	}
}
void vitesseVent1_2(void) {
	while(etatSysteme) {
		raise(SVV1_2);
		//attendre t
	}
}
void vitesseVent1_3(void) {
	while(etatSysteme) {
		raise(SVV1_3);
		//attendre t
	}
}

void vitesseVent2_1(void) {
	while(etatSysteme) {
		raise(SVV2_1);
		//attendre t
	}
}
void vitesseVent2_2(void) {
	while(etatSysteme) {
		raise(SVV2_2);
		//attendre t
	}
}
void vitesseVent2_3(void) {
	while(etatSysteme) {
		raise(SVV2_3);
		//attendre t
	}
}

void vitesseVent3_1(void) {
	while(etatSysteme) {
		raise(SVV3_1);
		//attendre t
	}
}
void vitesseVent3_2(void) {
	while(etatSysteme) {
		raise(SVV3_2);
		//attendre t
	}
}
void vitesseVent3_3(void) {
	while(tatSysteme) {
		raise(SVV3_3);
		//attendre t
	}
}

/*
 * rotationRotor_i : simule les signaux envoyés par le capteur de rotation du rotor de l'éolienne i
 *
 * void -> void
 */
void rotationRotor_1() {
	while(etatSysteme1) {
		raise(SRR1);
		//attendre t
	}
}
void rotationRotor_2(void) {
	while(etatSysteme) {
		raise(SRR2);
		//attendre t
	}
}
void rotationRotor_3(void) {
	while(etatSysteme) {
		raise(SRR3);
		//attendre t
	}
}

/*
 * directionVent : simule le signal envoyé par le capteur de direction du vent moyen.
 *
 * void -> void
 */
void directionVent(void) {
	while(etatSysteme) {
		raise(SDVM);
		//attendre t
	}
}

/*
 * chargeBatterie : simule le signal envoyé par le capteur de niveau de charge de la batterie
 *
 * void -> void
 */
void chargeBatterie(void) {
	if(!etatSysteme) {
		variationCharge = 0;
		int edf;
		int temps;

		while(1) {
			var = 0;

			for(i=0;i<=2;i++) {
				switch(regimeEolienne[i]) {
					case 0 : break;
					case 1 : alimEol = alimEol + 12*temps;break;
					case 2 : alimEol = alimEol + 20*temps;break;
					default:break;
				}
			}

			consoLamp=tensionOnduleur*temps;

			switch(choixDemux) {

		 		case 0 : variationCharge = variationCharge + alimEol;break; // à adpater pour % charge
		 		case 1 : edf = edf + alimEol;break;
		 		default:break;
			}

			switch(choixMux) {
		 	 	case 0 : variationCharge = variationCharge - consoLamp;break;// à adpater pour % charge
		 	 	case 1 : edf = edf - consoLamp;break;
		 	 	default:break;
			}

			raise(SCB);
			//attendre temps
		}
	}
}

/*
 * eclairageGlobal : simule le signal envoyé par le capteur d'éclairage global.
 *
 * void -> void
 */
void eclairageGlobal(int puissance) {
	while(etatSysteme) {
		raise(SEG);
		//attendre t
	}
}

/*
 * temps : simule le signal envoyé par l'horloge.
 *
 * void -> void
 */
void temps(void) {
	while(etatSysteme) {
		raise(ST);
		//attendre 1 sec
	}
}




