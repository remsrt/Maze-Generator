/* Unionfind.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __UNIONFIND__
#define __UNIONFIND__
#include "Tableau.h"

typedef struct unionfind_t {
	Coordonnees_t taille;
	Coordonnees_t **pere;
	unsigned int **rang;
	int cardinalite;
} Unionfind_t;

/* Initialise 'n' * 'm' ensembles de couples disjoints dans
 * les ensembles de cellules 'ensembles_cel' */
void initialiserEnsembles(Unionfind_t *ensembles_cel, int n, int m);

/* Renvoie le représentant de l'ensemble auquel appartient la
 * cellule 'cellule' dans les ensembles de celulles 'ensembles_cel'*/
Coordonnees_t trouverRepresentant(Coordonnees_t **pere, Coordonnees_t cellule);

/* Réunit les ensembles contenant les cellules 'cellule_1' et
 * 'cellule_2' dans les ensembles de cellules 'ensemble_cel'
 * en incrémentant (si il le faut) le rang de l'ensemble contenant 
 * l'union des deux et renvoie 1. 
 * Sinon renvoie 0 si 'cellule_1' et 'cellule_2' étaient dèjà
 * dans le même ensemble */
int unirEnsembles(Unionfind_t *ensembles_cel, Coordonnees_t cel_1, Coordonnees_t cel_2);

/* Renvoie 1 si les cellules 'cel_1' et 'cel_2' sont dans
 * la même classe et 0 sinon. */
int estDansMemeClasse(Unionfind_t ensembles_cel, Coordonnees_t cel_1, Coordonnees_t cel_2);

/* Libere l'espace mémoire alloué pour les ensembles
 * de cellules 'ensembles_cel' */
void libererEnsemblesCel(Unionfind_t ensembles_cel);

#endif