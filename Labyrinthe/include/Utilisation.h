/* Utilisation.h
 * Auteur : SURAT Rémi & KEHDR Nader
 * Création : 17/02/2020 */

#ifndef __UTILISATION__
#define __UTILISATION__

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --mode=texte. */
void erreurModeTexte();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --taille=axb où 'a' et 'b' sont deux entiers. */
void erreurOptTaille();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --graine=a où 'a'est un entier. */
void erreurOptGraine();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --attente=a où 'a'est un entier. */
void erreurOptAttente();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --unique. */
void erreurOptUnique();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --acces. */
void erreurOptAcces();

/* Affichage d'une erreur lors d'une mauvaise utilisation
 * de l'option --victor. */
void erreurOptVictor();

/* Affichage d'une erreur lorsque l'option victor est utilisée
 * pour un affichage en mode texte. */
void erreurOptVictor2();

/* Affichage un manuel du programme expliquant comment
 * l'exécuter et quelles options sont disponibles. */
void utilisation();

#endif