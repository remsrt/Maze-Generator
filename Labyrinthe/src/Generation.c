/* Generation.c */

#include "../include/Generation.h"
#include "../include/FileAttente.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <MLV/MLV_all.h>

static void melange(int *liste, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = liste[j];
          liste[j] = liste[i];
          liste[i] = t;
        }
    }
}

static int remplitTab(tab_m liste[], int x, int y){
    int i, j, k;
    j = 0;
    i = 0;
    for(k = 0; k < 2 * x * y; k++) {
        liste[k].x = i;
        liste[k].y = j;
        liste[k].mur = k % 2;
        j += k % 2;
        if (j % y == 0 && k % 2 != 0) {
            i += 1;
            j = 0;
        }
    }
    return 1;
}

static int tabIndices(int list[], int n){
    int i;
    for (i = 0; i < n; i++)
    	list[i] = i;
    melange(list,n);
    melange(list,n);
    return 1;
}

static int estDejaVisitee(Unionfind_t ensembles_cel, Coordonnees_t cel){
	if(ensembles_cel.pere[cel.abscisse][cel.ordonnee].abscisse == cel.abscisse)
		if(ensembles_cel.pere[cel.abscisse][cel.ordonnee].ordonnee == cel.ordonnee)
			return 0;
	return 1;
}

static void enfilerVoisinHaut(Labyrinthe_t laby, Unionfind_t *ensembles_cel, FileAttente *file, Coordonnees_t cellule){
	Coordonnees_t cel_voisine;
	cel_voisine.abscisse = cellule.abscisse - 1;
	cel_voisine.ordonnee = cellule.ordonnee;
	if((laby.murs_hori[cellule.abscisse][cellule.ordonnee] == 0) && (!estDejaVisitee(*ensembles_cel, cel_voisine))){
		enfiler(cel_voisine, file);
		ensembles_cel->pere[cel_voisine.abscisse][cel_voisine.ordonnee] = cellule;
	}
}

static void enfilerVoisinBas(Labyrinthe_t laby, Unionfind_t *ensembles_cel, FileAttente *file, Coordonnees_t cellule){
	Coordonnees_t cel_voisine;
	cel_voisine.abscisse = cellule.abscisse + 1;
	cel_voisine.ordonnee = cellule.ordonnee;
	if((laby.murs_hori[cel_voisine.abscisse][cel_voisine.ordonnee] == 0) && (!estDejaVisitee(*ensembles_cel, cel_voisine))){
		enfiler(cel_voisine, file);
		ensembles_cel->pere[cel_voisine.abscisse][cel_voisine.ordonnee] = cellule;
	}
}

static void enfilerVoisinGauche(Labyrinthe_t laby, Unionfind_t *ensembles_cel, FileAttente *file, Coordonnees_t cellule){
	Coordonnees_t cel_voisine;
	cel_voisine.abscisse = cellule.abscisse;
	cel_voisine.ordonnee = cellule.ordonnee - 1;
	if((laby.murs_vert[cellule.abscisse][cellule.ordonnee] == 0) && (!estDejaVisitee(*ensembles_cel, cel_voisine))){
		enfiler(cel_voisine, file);
		ensembles_cel->pere[cel_voisine.abscisse][cel_voisine.ordonnee] = cellule;
	}
}

static void enfilerVoisinDroite(Labyrinthe_t laby, Unionfind_t *ensembles_cel, FileAttente *file, Coordonnees_t cellule){
	Coordonnees_t cel_voisine;
	cel_voisine.abscisse = cellule.abscisse;
	cel_voisine.ordonnee = cellule.ordonnee + 1;


	if((laby.murs_vert[cel_voisine.abscisse][cel_voisine.ordonnee] == 0) && (!estDejaVisitee(*ensembles_cel, cel_voisine))){
		enfiler(cel_voisine, file);
		ensembles_cel->pere[cel_voisine.abscisse][cel_voisine.ordonnee] = cellule;
	}
}

static void enfilerVoisins(Labyrinthe_t laby, Unionfind_t *ensembles_cel, FileAttente *file, Coordonnees_t cellule){
	int i, j;
	i = cellule.abscisse;
	j = cellule.ordonnee;

	/* Cellule collée en haut */
	if((i - 1) < 0){

		/* Coin supérieur gauche */
		if((j - 1) < 0){
			enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
			enfilerVoisinBas(laby, ensembles_cel, file, cellule);
		}
		/* Coin supérieur droit */
		else if((j + 1) >= laby.taille.ordonnee){
			enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
			enfilerVoisinBas(laby, ensembles_cel, file, cellule);
		}
		/* Juste collée en haut */
		else{
			enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
			enfilerVoisinBas(laby, ensembles_cel, file, cellule);
			enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
		}
	}
	/* Cellule collée en bas */
	else if(i + 1 >= laby.taille.abscisse){
		/* Coin inférieur gauche */
		if((j - 1) < 0){
			enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
			enfilerVoisinHaut(laby, ensembles_cel, file, cellule);

		}
		/* Coin inférieur droit */
		else if((j + 1) >= laby.taille.ordonnee){
			enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
			enfilerVoisinHaut(laby, ensembles_cel, file, cellule);

		}
		/* Juste collée en bas */
		else{
			enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
			enfilerVoisinHaut(laby, ensembles_cel, file, cellule);
			enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
		}
	}
	/* Cellule collée à gauche */
	else if((j - 1) < 0){
		enfilerVoisinHaut(laby, ensembles_cel, file, cellule);
		enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
		enfilerVoisinBas(laby, ensembles_cel, file, cellule);

	}
	/* Cellule collée à droite */
	else if(j + 1 >= laby.taille.ordonnee){
		enfilerVoisinHaut(laby, ensembles_cel, file, cellule);
		enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
		enfilerVoisinBas(laby, ensembles_cel, file, cellule);

	}
	/* Cellule au centre */
	else{
		enfilerVoisinHaut(laby, ensembles_cel, file, cellule);
		enfilerVoisinDroite(laby, ensembles_cel, file, cellule);
		enfilerVoisinBas(laby, ensembles_cel, file, cellule);
		enfilerVoisinGauche(laby, ensembles_cel, file, cellule);
	}
}

static void ajouterDebutListe(Liste *lst, Coordonnees_t cel){
	Cellule * tmp;
	if((tmp = alloueCellule(cel)) != NULL){
		tmp->suivant = *lst;
		(*lst) = tmp;
	}
}

static void colorierCellule(Labyrinthe_t laby, Coordonnees_t cellule, int largeur, int hauteur){
	float cel_abs, cel_ord, coord_abs, coord_ord;

	assert(laby.taille.abscisse > 0);
	assert(laby.taille.ordonnee > 0);

	cel_abs = (float) (largeur) / laby.taille.ordonnee;
	cel_ord = (float) (hauteur) / laby.taille.abscisse;
	coord_abs = (float) cellule.abscisse * cel_ord;
	coord_ord = (float) cellule.ordonnee * cel_abs;

	MLV_draw_filled_rectangle(coord_ord + 1, coord_abs + 1, cel_abs - 2, cel_ord - 2, MLV_COLOR_BLUE);
	MLV_actualise_window();
}

static void afficherChemin(Unionfind_t ensembles_cel, Labyrinthe_t laby, int largeur, int hauteur){
	Coordonnees_t cellule;
	Liste lst;
	cellule.abscisse = ensembles_cel.taille.abscisse - 1;
	cellule.ordonnee = ensembles_cel.taille.ordonnee - 1;

	if(ensembles_cel.pere[cellule.abscisse][cellule.ordonnee].abscisse == cellule.abscisse){
		if(ensembles_cel.pere[cellule.abscisse][cellule.ordonnee].ordonnee == cellule.ordonnee){
			printf("ERREUR plus court chemin\n");
			return;
		}
	}
	lst = NULL;
	while((cellule.abscisse != 0) || (cellule.ordonnee != 0)){
		ajouterDebutListe(&lst, cellule);
		cellule = ensembles_cel.pere[cellule.abscisse][cellule.ordonnee];
	}
	cellule.abscisse = 0;
	cellule.ordonnee = 0;
	ajouterDebutListe(&lst, cellule);

	while(lst != NULL){
		MLV_wait_milliseconds(1000 / (laby.taille.abscisse + laby.taille.ordonnee));
		colorierCellule(laby, lst->valeur, largeur, hauteur);
		lst = lst->suivant;
	}
}

Unionfind_t genererLabyrinthe(Labyrinthe_t *laby, OptionsArg options, int largeur, int hauteur){
	Unionfind_t ensembles_cel;
	Coordonnees_t entree, sortie, cellule_alea, cel_voisine;
	MLV_Keyboard_button sym;
	MLV_Keyboard_modifier mod;
	int entier_alea, x, y, unicode, index, *indices;
	tab_m mur, *liste;

	assert(laby->taille.abscisse > 0);
	assert(laby->taille.ordonnee > 0);
	assert(options.mode_texte == 0 || options.mode_texte == 1 || options.mode_texte == 2);

    index = 0;
	entree.abscisse = 0;
	entree.ordonnee = 0;
	sortie.abscisse = laby->taille.abscisse - 1;
	sortie.ordonnee = laby->taille.ordonnee - 1;
	x = 0, y = 0; unicode = 0;

	indices = (int*) malloc(((laby->taille.abscisse) * (laby->taille.ordonnee) * 2) * sizeof(int));
	liste = (tab_m*) malloc(((laby->taille.abscisse) * (laby->taille.ordonnee) * 2) * sizeof(tab_m));

    remplitTab(liste, laby->taille.abscisse, laby->taille.ordonnee);
    tabIndices(indices, ((laby->taille.abscisse)*(laby->taille.ordonnee)*2)-1);
	initialiserEnsembles(&ensembles_cel, laby->taille.abscisse, laby->taille.ordonnee);

	/* Tant que le labyrinthe n'est pas valide */
	while((options.acces) ? (!(ensembles_cel.cardinalite == 1)) : (!estDansMemeClasse(ensembles_cel, entree, sortie))){
		if((options.attente < 0)){ /* Si aucun délai n'a été précisé */
			if(options.mode_texte)
				getchar();
			else
				MLV_wait_keyboard_or_mouse(&sym, &mod, &unicode, &x, &y);
		}
		if(options.attente > 0){ /* Si un délai à été précisé */
			MLV_wait_milliseconds(options.attente);
		}
        mur = liste[indices[index]];
		cellule_alea.abscisse = mur.x;
		cellule_alea.ordonnee = mur.y;
		entier_alea = mur.mur;

		if(entier_alea == 0){ /* Suppression d'un mur horizontal */
			cel_voisine.abscisse = cellule_alea.abscisse - 1;
			cel_voisine.ordonnee = cellule_alea.ordonnee;
			if(cel_voisine.abscisse >= 0){ /* Si la cellule voisine ne dépasse pas le bord haut */

				if(options.unique == 1){ /* Si l'option unique est sélectionnée, on ne supprime le mur que si
								    les deux cellules ne sont pas dans la même classe */
					if(!estDansMemeClasse(ensembles_cel, cellule_alea, cel_voisine)){
						laby->murs_hori[cellule_alea.abscisse][cellule_alea.ordonnee] = 0;
						unirEnsembles(&ensembles_cel, cellule_alea, cel_voisine);
					}
				}
				else{
					laby->murs_hori[cellule_alea.abscisse][cellule_alea.ordonnee] = 0;
					unirEnsembles(&ensembles_cel, cellule_alea, cel_voisine);
				}
			}
		}

		if(entier_alea == 1){ /* Suppression d'un mur vertical */
			cel_voisine.abscisse = cellule_alea.abscisse;
			cel_voisine.ordonnee = cellule_alea.ordonnee - 1;
			if(cel_voisine.ordonnee >= 0){ /* Si la cellule voisine ne dépasse pas le bord gauche */

				if(options.unique == 1){/* Si l'option unique est sélectionnée, on ne supprime le mur que si
								    les deux cellules ne sont pas dans la même classe */
					if(!estDansMemeClasse(ensembles_cel, cellule_alea, cel_voisine)){
						laby->murs_vert[cellule_alea.abscisse][cellule_alea.ordonnee] = 0;
						unirEnsembles(&ensembles_cel, cellule_alea, cel_voisine);
					}
				}
				else{
					laby->murs_vert[cellule_alea.abscisse][cellule_alea.ordonnee] = 0;
					unirEnsembles(&ensembles_cel, cellule_alea, cel_voisine);
				}
			}
		}
		if((options.attente < 0) || (options.attente > 0)){ /* Actualisation de l'affichage si il le faut */
			if(options.mode_texte == 1){
				system("clear");
				afficherLabyrintheTexte(*laby);
			}
			else if(options.mode_texte == 2){
				system("clear");
				afficherLabyrintheTexteUtf8(*laby);
			}
			else{
				MLV_clear_window(MLV_COLOR_BLACK);
				afficherLabyrintheGraphique(*laby, largeur, hauteur);
			}
		}
        index += 1;
	}
	return ensembles_cel;
}

void afficherPlusCourtChemin(Labyrinthe_t laby, Unionfind_t ensembles_cel, int largeur, int hauteur){
	FileAttente file;
	Coordonnees_t cellule;

	initialiserFile(&file);

	initialiserEnsembles(&ensembles_cel, laby.taille.abscisse, laby.taille.ordonnee);

	cellule.abscisse = 0;
	cellule.ordonnee = 0;
	ensembles_cel.pere[0][0].abscisse = -1;
	ensembles_cel.pere[0][0].ordonnee = -1;

	enfilerVoisins(laby, &ensembles_cel, &file, cellule);

	while(!estFileVide(file)){
		cellule = (defiler(&file))->valeur;
		enfilerVoisins(laby, &ensembles_cel, &file, cellule);
	}

	afficherChemin(ensembles_cel, laby, largeur, hauteur);
}