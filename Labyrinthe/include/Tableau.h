/* Tableau.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __TABLEAU__
#define __TABLEAU__

typedef struct coordonnees_t {
	int abscisse;
	int ordonnee;
} Coordonnees_t;

/* Affiche le tableau de coordonnées 'tab' de taille
 * 'n' * 'm' sur le terminal */
void afficherTabCoord(Coordonnees_t **tab, int n, int m);

/* Affiche le tableau d'entiers 'tab' de taille
 * 'n' * 'm' sur le terminal */
void afficherTabInt(int **tab, int n, int m);

/* Affiche le tableau d'entiers non signés 'tab' de taille
 * 'n' * 'm' sur le terminal */
void afficherTabUnsignedInt(unsigned int **tab, int n, int m);

/* Libere l'espace mémoire alloué pour le tableau de coordonnées 
 * à deux dimensions 'tab' de taille 'n' */
void libererTabCoord(Coordonnees_t **tab, int n);

/* Libere l'espace mémoire alloué pour le tableau d'entiers 
 * à deux dimensions 'tab' de taille 'n' */
void libererTabInt(int **tab, int n);

/* Libere l'espace mémoire alloué pour le tableau d'entiers 
 * non signés à deux dimensions 'tab' de taille 'n' */
void libererTabUnsignedInt(unsigned int **tab, int n);

#endif