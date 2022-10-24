/* Main.c
 * Auteur : SURAT Rémi
 * Création : 17/02/2020 */

#include "include/Generation.h"
#include "include/Utilisation.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <getopt.h>
#include <MLV/MLV_all.h>

#define LARGEUR 800
#define HAUTEUR 800

static const struct option long_options[] = 
{
    {"mode", required_argument, NULL, 'm'},
    {"taille", required_argument, NULL, 't'},
    {"graine", required_argument, NULL, 'g'},
    {"attente", required_argument, NULL, 'a'},
    {"unique", no_argument, NULL, 'u'},
    {"acces", no_argument, NULL, 'c'},
    {"victor", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
};

int main(int argc, char *argv[]) {
	Labyrinthe_t laby;
	Unionfind_t ensembles_cel;
	Coordonnees_t souris;
	OptionsArg options;
	char tmp, str_opt[50];
	int opt;

	options.taille.abscisse = 10;
	options.taille.ordonnee = 10;
	options.mode_texte = 0;
	options.graine = 0;
	options.attente = -1;
	options.unique = 0;
	options.acces = 0;
	options.victor = 0;

	/* Parcours des options */
	while((opt = getopt_long(argc, argv, "m:t:g:a:uacv", long_options, NULL)) != -1) {
		switch(opt) {
			case 'm':
				if((sscanf(optarg, "%s", str_opt) != 1) || ((strcmp(str_opt, "texte") != 0) && (strcmp(str_opt, "utf8") != 0))){
					erreurModeTexte();
					exit(EXIT_FAILURE);
				}
				if((strcmp(str_opt, "texte") == 0))
					options.mode_texte = 1;
				if((strcmp(str_opt, "utf8") == 0))
					options.mode_texte = 2;
				break;
			case 't':
				if((sscanf(optarg, "%d%c%d", &options.taille.abscisse, &tmp, &options.taille.ordonnee) != 3) || (tmp != 'x')){
					erreurOptTaille();
					exit(EXIT_FAILURE);
				}
				break;
			case 'g':
				if((sscanf(optarg, "%d", &options.graine) != 1)){
					erreurOptGraine();
					exit(EXIT_FAILURE);
				}
				break;
			case 'a':
				if((sscanf(optarg, "%d", &options.attente) != 1)){
					erreurOptAttente();
					exit(EXIT_FAILURE);
				}
				break;
			case 'u':
				options.unique = 1;
				break;
			case 'c':
				options.acces = 1;
				break;
			case 'v':
				options.victor = 1;
				break;
			case 'h':
				utilisation();
				exit(EXIT_FAILURE);			
				break;
			default:
				utilisation();
				exit(EXIT_FAILURE);
		}
	}
	/* Message d'erreur si l'option victor est utilisée en mode texte */
	if((options.mode_texte != 0) && (options.victor == 1)){
		erreurOptVictor2();
		exit(EXIT_FAILURE);
	}

	/* Initialisation de la graine pseudo-aléatoire */
	if(options.graine == 0)
		srand(time(NULL));
	else
		srand(options.graine);

	/* Initialisation du labyrinthe */
	initialiserLabyrinthe(&laby, options.taille.abscisse, options.taille.ordonnee);

	/* Premier affichage du labyrinthe si l'option sans délai 
	 * n'est pas choisie */
	if((options.attente < 0) || (options.attente > 0)){
		if(options.mode_texte == 1){
			system("clear");
			afficherLabyrintheTexte(laby);
		}
		else if(options.mode_texte == 2){
			system("clear");
			afficherLabyrintheTexteUtf8(laby);
		}
		else{
			MLV_create_window("Labyrinthe", "SURAT Rémi - Février 2020", LARGEUR, HAUTEUR);
			afficherLabyrintheGraphique(laby, LARGEUR, HAUTEUR);
		}
	}

	/* Génération du labyrinthe */
	ensembles_cel = genererLabyrinthe(&laby, options, LARGEUR, HAUTEUR);
	
	/* Affichage une fois la génération terminée si l'option 
	 * sans délai est choisie */
	if(options.attente == 0){
		if(options.mode_texte == 1){
			system("clear");
			afficherLabyrintheTexte(laby);
		}
		else if(options.mode_texte == 2){
			system("clear");
			afficherLabyrintheTexteUtf8(laby);
		}
		else{
			MLV_create_window("Labyrinthe", "SURAT Rémi - Février 2020", LARGEUR, HAUTEUR);
			afficherLabyrintheGraphique(laby, LARGEUR, HAUTEUR);
		}
	}
	
	/* Affichage du plus court chemin */
	if(options.victor == 1)
		afficherPlusCourtChemin(laby, ensembles_cel, LARGEUR, HAUTEUR);

	libererEnsemblesCel(ensembles_cel);
	libererLabyrinthe(laby);
	
	if(options.mode_texte == 0){
		MLV_wait_mouse(&souris.abscisse, &souris.ordonnee);
		MLV_free_window();
	}

	return 0;
}