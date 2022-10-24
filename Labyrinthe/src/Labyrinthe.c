/* Labyrinthe.c */

#include "../include/Labyrinthe.h"
#include "../include/FileAttente.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <MLV/MLV_all.h>

void initialiserLabyrinthe(Labyrinthe_t *laby, int n, int m) {
	int i, j;
	assert(n > 0);
	assert(m > 0);

	laby->taille.abscisse = n;
	laby->taille.ordonnee = m;

	laby->murs_hori = malloc((n + 1) * sizeof(int *));
	
	for(i = 0; i < n + 1; i ++){
		laby->murs_hori[i] = malloc(m * sizeof(int));
		for(j = 0; j < m; j ++)
			laby->murs_hori[i][j] = 1;
	}

	laby->murs_vert = malloc(n * sizeof(int *));
	
	for(i = 0; i < n; i ++){
		laby->murs_vert[i] = malloc((m + 1) * sizeof(int));
		for(j = 0; j < m + 1; j ++)
			if(((i == 0) & (j == 0)) || ((i == (n - 1)) & (j == m)))
				laby->murs_vert[i][j] = 0;
			else
				laby->murs_vert[i][j] = 1;
	}
}

void libererLabyrinthe(Labyrinthe_t laby){
	assert(laby.taille.abscisse > 0);
	assert(laby.taille.ordonnee > 0);

	libererTabInt(laby.murs_hori, laby.taille.abscisse + 1);
	libererTabInt(laby.murs_vert, laby.taille.abscisse);
}