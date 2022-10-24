/* FileAttente.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020
 * Modification : 03/03/2020 */

#ifndef __FILE_ATTENTE__
#define __FILE_ATTENTE__
#include "Tableau.h"

typedef struct cellule {
	Coordonnees_t valeur;
	struct cellule *suivant;
} Cellule, *Liste;

typedef struct file {
	Liste debut;
	Liste fin;
} FileAttente;

/* Renvoie un pointeur sur l'espace mémoire necessaire
 * alloué pour une cellule contenant la coordonnée 'coord' */
Liste alloueCellule(Coordonnees_t coord);

/* Initialise la file 'fileAttente' (met les valeurs
 * de début et fin à NULL). */
void initialiserFile(FileAttente *fileAttente);

/* Enfile la coordonnée 'coord' dans la file 'fileAttente' */
void enfiler(Coordonnees_t coord, FileAttente *fileAttente);

/* Défile la file 'fileAttente' et renvoie la
 * coordonnée correspondante */
Liste defiler(FileAttente *fileAttente);

/* Renvoie 1 si la file d'attente 'fileAttente'
 * est vide et renvoie 0 sinon */
int estFileVide(FileAttente fileAttente);

/* Affiche la file 'fileAttente sur le terminal' */
void afficherFile(FileAttente fileAttente);

#endif