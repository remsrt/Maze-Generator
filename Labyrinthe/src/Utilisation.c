/* Utilisation.c */

#include "../include/Utilisation.h"
#include <stdlib.h>
#include <stdio.h>

void utilisation(){
	printf("LABYRINTHE                              Manuel utilisateur                             LABYRINTHE\n");
	printf("\n");
	printf("NAME\n");
	printf("       Labyrinthe\n");
	printf("\n");
	printf("SYNOPSIS\n");
	printf("       ./Labyrinthe [OPTION1] [OPTION2]...[OPTIONN]\n");
	printf("\n");
	printf("DESCRIPTION\n");
	printf("       Ce programme génère de façon pseudo aléatoire un labyrinthe.\n");
	printf("       Plusieurs options sont disponibles :\n");
	printf("\n");
	printf("       --mode=texte, --mode=utf8\n");
	printf("              modifie le mode d'affichage. Le mode texte produit un affichage utilisant les cara-\n");
	printf("              -ctères '+', '-' et '|' du clavier. Le mode utf8 utilise des caractères utf8.\n");
	printf("              Si l'option n'est pas définie, l'affiche par défaut est un affichage graphique uti-\n");
	printf("              -lisant la librairie MLV\n");
	printf("\n");
	printf("       --taille=['LARGEUR'x'HAUTEUR']\n");
	printf("              initialise la largeur et la hauteur du labyrinthe, par défaut le labyrinthe est de\n");
	printf("              taille 25x25\n");
	printf("\n");
	printf("       --graine=['graine']\n");
	printf("              initialise la graine pseudo aléatoire, par défaut la valeur est prise en fonction\n");
	printf("              du temps courant\n");
	printf("\n");
	printf("       --attente=['temps_ms']\n");
	printf("              modifie le délai d'attente de suppression des murs, par défaut le programme attends\n");
	printf("              un événement utilisateur entre chaque suppression. Si 'temps_ms' est initialisé à 0\n");
	printf("              l'affichage est produit directement\n");
	printf("\n");
	printf("       -u, --unique\n");
	printf("              affichage plus esthétique. Une suppression de mur ne s'effectue que si les deux\n");
	printf("              cellules n'appartiennent pas déjà au même ensemble\n");
	printf("\n");
	printf("       -c, --acces\n");
	printf("              accessibilité de toutes les cellules\n");
	printf("\n");
	printf("       -v, --victor\n");
	printf("              affiche le chemin de longeur minimale, disponible uniquement pour un affichage en\n");
	printf("              mode graphique\n");
	printf("\n");
	printf("       -h, --help\n");
	printf("              affiche le manuel utilisateur\n");
	printf("\n");
	printf("AUTHOR\n");
	printf("       Ecrit par KEHDR Nader et SURAT Rémi.\n");
	printf("\n");
	printf("REPORTING BUGS\n");
	printf("       L'option --victor ne fonctionne pas pour tous les labyrinthe.\n");
	printf("\n");
	printf("COPYRIGHT\n");
	printf("       Il s'agit d'un programme créé dans le cadre de notre deuxième année de licence informatique\n");
	printf("       à l'UPEM (Université Paris-Est Marne-la-vallée).\n");
	printf("       Copyright © 2020 KEHDR Nader et SURAT Rémi, tous droits réservés.\n");
}

void erreurModeTexte(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --mode\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptTaille(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --taille\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptGraine(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --graine\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptAttente(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --attente\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptUnique(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --unique\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptAcces(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --acces\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}

void erreurOptVictor(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --victor\n");
	
}

void erreurOptVictor2(){
	fprintf(stderr, "\nERREUR : Mauvaise utilisation de l'option --victor\n");
	fprintf(stderr, "Vous ne pouvez pas utiliser l'option --victor pour un affichage en mode texte\n");
	fprintf(stderr, "Pour plus d'information veuillez taper :\n");
	fprintf(stderr, "./Labyrinthe --help\n\n");
}


