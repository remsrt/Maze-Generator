/* FileAttente.c */

#include "../include/FileAttente.h"
#include <stdlib.h>
#include <stdio.h>

Liste alloueCellule(Coordonnees_t coord){
	Cellule *tmp = (Cellule*) malloc(sizeof(Cellule)); 
	if(NULL == tmp)
		return NULL;
	tmp->valeur = coord;
	tmp->suivant = NULL;
	return tmp;
}

void afficherFile(FileAttente fileAttente){
	Liste tmp;
	if(NULL != fileAttente.debut){
		tmp = fileAttente.debut;
		while(tmp != NULL) {
			printf("(%d,%d)\n", tmp->valeur.abscisse, tmp->valeur.ordonnee);
			tmp = tmp->suivant;
		}
	}
	else
		printf("File vide !\n");
}

void initialiserFile(FileAttente *fileAttente){
	fileAttente->debut = NULL;
	fileAttente->fin = NULL;
}

void enfiler(Coordonnees_t coord, FileAttente *fileAttente){
	Cellule *tmp = alloueCellule(coord);
	if(NULL != tmp){
		if(NULL == fileAttente->debut)
			fileAttente->debut = tmp;
		else
			fileAttente->fin->suivant = tmp;
		fileAttente->fin = tmp;
	}
}

Liste defiler(FileAttente *fileAttente){
	Cellule *tmp;
	if(NULL == fileAttente){
		printf("File vide !\n");
		return NULL;
	}
	tmp = fileAttente->debut;
	fileAttente->debut = fileAttente->debut->suivant;
	return tmp;
}

int estFileVide(FileAttente fileAttente){
	if(NULL == fileAttente.debut)
		return 1;
	return 0;
}