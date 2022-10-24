/* Generation.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __GENERATION__
#define __GENERATION__
#include "Affichage.h"
#include <unistd.h>

typedef struct OptionsArg {
	Coordonnees_t taille;
	int mode_texte;
	int graine;
	int attente;
	int unique;
	int acces;
	int victor;
} OptionsArg;

typedef struct ltab_m {
    int x;
    int y;
    int mur;
} tab_m;

/* Genère le labyrinthe 'laby' selon les options de génération 'options'.
 * Une fenetre MLV de taille 'largeur * 'hauteur' est lancée si l'affichage
 * graphique est sélectionné. */
Unionfind_t genererLabyrinthe(Labyrinthe_t *laby, OptionsArg options, int largeur, int hauteur);

/* Affiche selon le mode de jeu le plus court chemin
 * allant de l'entrée à la sortie */
void afficherPlusCourtChemin(Labyrinthe_t laby, Unionfind_t ensembles_cel, int largeur, int hauteur);

#endif
