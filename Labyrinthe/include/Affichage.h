/* Affichage.h
 * Auteurs : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __AFFICHAGE__
#define __AFFICHAGE__
#include "Labyrinthe.h"

/* Affiche le labyrinthe 'labyrinthe' sur le terminal en mode texte. */
void afficherLabyrintheTexte(Labyrinthe_t laby);

/* Affiche le labyrinthe 'labyrinthe' sur le terminal en mode texte utf8. */
void afficherLabyrintheTexteUtf8(Labyrinthe_t laby);

/* Affiche le labyrinthe 'labyrinthe' sur une interface
 * graphique de la librairie MLV. */
void afficherLabyrintheGraphique(Labyrinthe_t laby, int largeur, int hauteur);

#endif