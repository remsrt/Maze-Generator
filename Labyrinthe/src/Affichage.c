/* Affichage.c */

#include "../include/Affichage.h"
#include <stdio.h>
#include <assert.h>
#include <MLV/MLV_all.h>

char* intersections[2][2][2][2] = 
   { {{{" ","╶"},{"╴","─"}},{{"╵","└"},{"┘","┴"}}},
     {{{"╷","┌"},{"┐","┬"}},{{"│","├"},{"┤","┼"}}} };

void afficherLabyrintheTexte(Labyrinthe_t laby){
	int i, j;
	assert(laby.taille.abscisse > 0);
	assert(laby.taille.ordonnee > 0);

	for(i = 0; i < laby.taille.abscisse; i ++){
		for(j = 0; j < laby.taille.ordonnee; j ++){
			if(j == (laby.taille.ordonnee - 1)){
				if(laby.murs_hori[i][j] == 1)
					printf("+--+");
				else
					printf("+  +");
			}
			else if(laby.murs_hori[i][j] == 1)
				printf("+--");
			else
				printf("+  ");
		}
		printf("\n");
		for(j = 0; j < laby.taille.ordonnee + 1; j ++){
			if(laby.murs_vert[i][j] == 1)
				printf("|  ");
			else
				printf("   ");
		}
		printf("\n");
	}
	for(j = 0; j < laby.taille.ordonnee; j ++)
		printf("+--");	
	printf("+\n");
}

void afficherLabyrintheTexteUtf8(Labyrinthe_t laby){
	int i, j;
    for (i = 0 ; i <= laby.taille.abscisse; i++){
        j = 0;
        if(i == 0)
            printf("%s", intersections[laby.murs_vert[i][j]][0][0][laby.murs_hori[i][j]]);
        else if(i == laby.taille.abscisse)
            printf("%s", intersections[0][laby.murs_vert[i-1][j]][0][laby.murs_hori[i][j]]);
        else
            printf("%s", intersections[laby.murs_vert[i][j]][laby.murs_vert[i-1][j]][0][laby.murs_hori[i][j]]);
        printf("%s", intersections[0][0][laby.murs_hori[i][j]][laby.murs_hori[i][j]]);
        printf("%s", intersections[0][0][laby.murs_hori[i][j]][laby.murs_hori[i][j]]);

        for(j = 1; j < laby.taille.ordonnee; j++){
            if(i == 0)
                printf("%s", intersections[laby.murs_vert[i][j]][0][laby.murs_hori[i][j - 1]][laby.murs_hori[i][j]]);
            else if(i == laby.taille.abscisse)
                printf("%s", intersections[0][laby.murs_vert[i-1][j]][laby.murs_hori[i][j - 1]][laby.murs_hori[i][j]]);
            else
                printf("%s", intersections[laby.murs_vert[i][j]][laby.murs_vert[i-1][j]][laby.murs_hori[i][j - 1]][laby.murs_hori[i][j]]);
            printf("%s", intersections[0][0][laby.murs_hori[i][j]][laby.murs_hori[i][j]]);
            printf("%s", intersections[0][0][laby.murs_hori[i][j]][laby.murs_hori[i][j]]);
        }
        if(i == 0)
            printf("%s", intersections[laby.murs_vert[i][j]][0][laby.murs_hori[i][j - 1]][0]);
        else if(i == laby.taille.abscisse)
            printf("%s", intersections[0][laby.murs_vert[i-1][j]][laby.murs_hori[i][j - 1]][0]);
        else
            printf("%s", intersections[laby.murs_vert[i][j]][laby.murs_vert[i-1][j]][laby.murs_hori[i][j - 1]][0]);
        
        printf("\n");
        if(i != laby.taille.abscisse){
            for(j = 0; j < laby.taille.ordonnee; j++){
                printf("%s", intersections[laby.murs_vert[i][j]][laby.murs_vert[i][j]][0][0]);
                printf("  ");
            }
            if(i != laby.taille.abscisse -1 )
                printf("%s", intersections[laby.murs_vert[i][j]][laby.murs_vert[i][j]][0][0]);
            printf("\n");
        }
    }
    printf("\n");
} 

void afficherLabyrintheGraphique(Labyrinthe_t laby, int largeur, int hauteur){
	int i, j;
	float coord_abs, coord_ord, cel_abs, cel_ord;

	assert(laby.taille.abscisse > 0);
	assert(laby.taille.ordonnee > 0);

	cel_abs = (float) (largeur) / laby.taille.ordonnee;
	cel_ord = (float) (hauteur) / laby.taille.abscisse;

	for(i = 0; i < laby.taille.abscisse; i ++){
		coord_ord = cel_ord * i;
		for(j = 0; j < laby.taille.ordonnee; j ++){
			if(laby.murs_hori[i][j] == 1){
				coord_abs = cel_abs * j;
				MLV_draw_line(coord_abs, coord_ord, coord_abs + cel_abs, coord_ord, MLV_COLOR_WHITE);
			}
		}
		for(j = 0; j < laby.taille.ordonnee + 1; j ++){
			if(laby.murs_vert[i][j] == 1){
				coord_abs = cel_abs * j;
				MLV_draw_line(coord_abs, coord_ord, coord_abs, coord_ord + cel_ord, MLV_COLOR_WHITE);	
			}
		}
	}
	MLV_draw_line(0, hauteur - 1,  largeur - 1, hauteur - 1, MLV_COLOR_WHITE);
	MLV_draw_line(largeur - 1, 0,  largeur - 1, hauteur - 1 - cel_ord, MLV_COLOR_WHITE);

	MLV_actualise_window();
}