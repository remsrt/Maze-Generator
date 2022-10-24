/* Tableau.c */

#include "../include/Tableau.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void afficherTabCoord(Coordonnees_t **tab, int n, int m) {
	int i, j;
	assert(n >= 0);
	assert(m >= 0);
 	i = 0;

	printf("[");
	printf("[");
	for(j = 0; j < m - 1; j ++){
		printf("(%d, %d), ", tab[i][j].abscisse, tab[i][j].ordonnee);
	}
	printf("(%d, %d)]\n", tab[i][j].abscisse, tab[i][j].ordonnee);
	for(i = 1; i < n - 1; i ++){
		printf(" [");
		for(j = 0; j < m - 1; j ++){
			printf("(%d, %d), ", tab[i][j].abscisse, tab[i][j].ordonnee);
		}
		printf("(%d, %d)]\n", tab[i][j].abscisse, tab[i][j].ordonnee);
	}
	printf(" [");
	for(j = 0; j < m - 1; j ++){
		printf("(%d, %d), ", tab[i][j].abscisse, tab[i][j].ordonnee);
	}
	printf("(%d, %d)]", tab[i][j].abscisse, tab[i][j].ordonnee);
	printf("]\n\n");
}

void afficherTabInt(int **tab, int n, int m) {
	int i, j;
	assert(n >= 0);
	assert(m >= 0);
	i = 0;

	printf("[");
	printf("[");
	for(j = 0; j < m - 1; j ++){
		printf("%d, ", tab[i][j]);
	}

	printf("%d]\n", tab[i][j]);
	for(i = 1; i < n - 1; i ++){
		printf(" [");
		for(j = 0; j < m - 1; j ++){
			printf("%d, ", tab[i][j]);
		}
		printf("%d]\n", tab[i][j]);
	}
	printf(" [");
	for(j = 0; j < m - 1; j ++){
		printf("%d, ", tab[i][j]);
	}
	printf("%d]", tab[i][j]);
	printf("]\n\n");
}

void afficherTabUnsignedInt(unsigned int **tab, int n, int m) {
	int i, j;
	assert(n >= 0);
	assert(m >= 0);
	i = 0;

	printf("[");
	printf("[");
	for(j = 0; j < m - 1; j ++){
		printf("%d, ", tab[i][j]);
	}

	printf("%d]\n", tab[i][j]);
	for(i = 1; i < n - 1; i ++){
		printf(" [");
		for(j = 0; j < m - 1; j ++){
			printf("%d, ", tab[i][j]);
		}
		printf("%d]\n", tab[i][j]);
	}
	printf(" [");
	for(j = 0; j < m - 1; j ++){
		printf("%d, ", tab[i][j]);
	}
	printf("%d]", tab[i][j]);
	printf("]\n\n");
}

void libererTabCoord(Coordonnees_t **tab, int n) {
	int i;
	for(i = 0; i < n; i ++){
		free(tab[i]);
	}
	free(tab);
}

void libererTabInt(int **tab, int n) {
	int i;
	for(i = 0; i < n; i ++){
		free(tab[i]);
	}
	free(tab);
}

void libererTabUnsignedInt(unsigned int **tab, int n) {
	int i;
	for(i = 0; i < n; i ++){
		free(tab[i]);
	}
	free(tab);
}