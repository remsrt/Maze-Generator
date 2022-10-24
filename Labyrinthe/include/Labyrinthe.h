/* Labyrinthe.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __LABYRINTHE__
#define __LABYRINTHE__
#include "Unionfind.h"

typedef struct labyrinthe_t {
	Coordonnees_t taille;
	int **murs_hori;
	int **murs_vert;
} Labyrinthe_t;

/* Initialise le labyrinthe 'labyrinthe' de taille 'n' * 'm' */
void initialiserLabyrinthe(Labyrinthe_t *laby, int n, int m);

/* Libere l'espace mémoire alloué pour le labyrinthe 'laby' */
void libererLabyrinthe(Labyrinthe_t laby);

#endif