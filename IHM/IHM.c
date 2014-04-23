#include "stdlib.h"
#include "stdio.h"
#include "simulation.h"
#include "gestionSysteme.h"

/*
 * IHM
 * 
 * input :
 * 
 * 
 * output :
 * 		- on/off
 * 		- arretUrgence
 * 		- alarme
 */

int id[3];
int idgestionclavier;
SEM_ID sem_Eolienne[6];
SEM_ID sem_Batterie[6];
SEM_ID sem_Lampadaires[6];

void main() {
	initSignaux();
	for(int i=0;i<6;i++) {
		sem_Eolienne[i] = semBCreate(SEM_Q_FIFO,SEM_EMPTY);
		sem_Batterie[i] = semBCreate(SEM_Q_FIFO,SEM_EMPTY);
		sem_Lampadaires[i] = semBCreate(SEM_Q_FIFO,SEM_EMPTY);
	}
	
	taskRtpLock();
	id[0] = taskSpawn("controleurBatterie",101,0,5000,(FUNCPTR)controleurBatterie,0,0,0,0,0,0,0,0,0,0);
	id[1] = taskSpawn("controleurEolienne",101,0,5000,(FUNCPTR)controleurEolienne,0,0,0,0,0,0,0,0,0,0);
	id[2] = taskSpawn("controleurLampadaires",101,0,5000,(FUNCPTR)controleurLampadaires,0,0,0,0,0,0,0,0,0,0);
	taskRtpUnlock();
	
	gestionclavier();
}

void gestionClavier() {
	boolean fin = false;
	while(!fin) {
		printf("Tapez : \"O\", \"A\" ou \"F\"\nO:Bouton On/Off | A:Arrêt d'Urgence | F:Forçage Alimentation\n");
		//car=getchar();
		scanf("%c", car);
		printf("Commande %c\b",car);
		switch(car) {
			case 'O' : break;
			case 'A' : break;
			case 'F' : break;
			default : ;
		}
		
	}
	
}