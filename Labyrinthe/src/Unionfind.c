/* Unionfind.c */

#include "../include/Unionfind.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void initialiserEnsembles(Unionfind_t *ensembles_cel, int n, int m) {
	int i, j;
	Coordonnees_t cellule;
	assert(n > 0);
	assert(m > 0);

	ensembles_cel->taille.abscisse = n;
	ensembles_cel->taille.ordonnee = m;
	ensembles_cel->cardinalite = n * m;

	ensembles_cel->pere = malloc(n * sizeof(Coordonnees_t*));

	for(i = 0; i < n; i++){
		ensembles_cel->pere[i] = malloc(m * sizeof(Coordonnees_t));
		for(j = 0; j < m; j ++){
			cellule.abscisse = i;
			cellule.ordonnee = j;
			ensembles_cel->pere[i][j] = cellule;
		}
	}

	ensembles_cel->rang = malloc(n * sizeof(unsigned int*));

	for(i = 0; i < n; i++){
		ensembles_cel->rang[i] = malloc(m * sizeof(unsigned int));
		for(j = 0; j < m; j ++)
			ensembles_cel->rang[i][j] = 0;
	}
}

Coordonnees_t trouverRepresentant(Coordonnees_t **pere, Coordonnees_t cellule) {
	Coordonnees_t pere_cel;
	assert(cellule.abscisse >= 0);
	assert(cellule.ordonnee >= 0);

	pere_cel.abscisse = pere[cellule.abscisse][cellule.ordonnee].abscisse;
	pere_cel.ordonnee = pere[cellule.abscisse][cellule.ordonnee].ordonnee;
	
	if((pere_cel.abscisse != cellule.abscisse) || (pere_cel.ordonnee != cellule.ordonnee)){
		pere_cel = trouverRepresentant(pere, pere_cel);
	}
	return pere_cel;
}

int unirEnsembles(Unionfind_t *ensembles_cel, Coordonnees_t cel_1, Coordonnees_t cel_2) {
	Coordonnees_t repre_cel_1, repre_cel_2; 
	int rang_ens_cel_1, rang_ens_cel_2;

	assert(cel_1.abscisse >= 0);
	assert(cel_1.ordonnee >= 0);
	assert(cel_2.abscisse >= 0);
	assert(cel_2.ordonnee >= 0);
	assert(ensembles_cel->taille.abscisse >= 0);
	assert(ensembles_cel->taille.ordonnee >= 0);

	repre_cel_1 = trouverRepresentant(ensembles_cel->pere, cel_1);
	repre_cel_2 = trouverRepresentant(ensembles_cel->pere, cel_2);
	rang_ens_cel_1 = ensembles_cel->rang[cel_1.abscisse][cel_1.ordonnee];
	rang_ens_cel_2 = ensembles_cel->rang[cel_2.abscisse][cel_2.ordonnee];

	if((repre_cel_1.abscisse == repre_cel_2.abscisse) && (repre_cel_1.ordonnee == repre_cel_2.ordonnee)){
		return 0;
	}

	if(rang_ens_cel_1 > rang_ens_cel_2){
		ensembles_cel->pere[repre_cel_2.abscisse][repre_cel_2.ordonnee].abscisse = repre_cel_1.abscisse;
		ensembles_cel->pere[repre_cel_2.abscisse][repre_cel_2.ordonnee].ordonnee = repre_cel_1.ordonnee;
		if(rang_ens_cel_1 < (rang_ens_cel_2 + 1))
			ensembles_cel->rang[repre_cel_1.abscisse][repre_cel_1.ordonnee] += 1;
		ensembles_cel->cardinalite -=1;
		return 1;
	}

	ensembles_cel->pere[repre_cel_1.abscisse][repre_cel_1.ordonnee].abscisse = repre_cel_2.abscisse;
	ensembles_cel->pere[repre_cel_1.abscisse][repre_cel_1.ordonnee].ordonnee = repre_cel_2.ordonnee;
	if(rang_ens_cel_2 < (rang_ens_cel_1 + 1))
		ensembles_cel->rang[repre_cel_2.abscisse][repre_cel_2.ordonnee] += 1;
	ensembles_cel->cardinalite -=1;
	return 1;
}

int estDansMemeClasse(Unionfind_t ensembles_cel, Coordonnees_t cel_1, Coordonnees_t cel_2){
	Coordonnees_t repre_cel_1;
	Coordonnees_t repre_cel_2;

	assert(cel_1.abscisse >= 0);
	assert(cel_1.ordonnee >= 0);
	assert(cel_2.abscisse >= 0);
	assert(cel_2.ordonnee >= 0);
	assert(ensembles_cel.taille.abscisse >= 0);
	assert(ensembles_cel.taille.ordonnee >= 0);

	repre_cel_1 = trouverRepresentant(ensembles_cel.pere, cel_1);
	repre_cel_2 = trouverRepresentant(ensembles_cel.pere, cel_2);

	if((repre_cel_1.abscisse == repre_cel_2.abscisse) && (repre_cel_1.ordonnee == repre_cel_2.ordonnee))
		return 1;
	return 0;
}

void libererEnsemblesCel(Unionfind_t ensembles_cel){
	assert(ensembles_cel.taille.abscisse > 0);
	assert(ensembles_cel.taille.ordonnee > 0);

	libererTabCoord(ensembles_cel.pere, ensembles_cel.taille.abscisse);
	libererTabUnsignedInt(ensembles_cel.rang, ensembles_cel.taille.abscisse);
}