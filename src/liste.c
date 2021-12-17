#include "../include/liste.h"

#include <stdlib.h>
#include <string.h>

void liberer_liste(ListeNoeud liste) {
  ListeNoeud tmp = liste;
  while (tmp != NULL) {
    ListeNoeud tmp2 = tmp;
    tmp = tmp->prochain;
    free(tmp2->cle);
    free(tmp2->valeur);
    free(tmp2);
  }
}

void afficher_liste(ListeNoeud liste) {
  printf("%d", liste == NULL);
  ListeNoeud noeud = liste;
  int n = 0;
  while (noeud != NULL) {
    printf("%d == %s : %s\n", n, noeud->cle, noeud->valeur);
    noeud = noeud->prochain;
    n++;
  }
}

ListeNoeud inserer_liste(ListeNoeud liste, char *cle, char *valeur) {
  if (liste == NULL) {
    liste = (struct liste_noeud *)malloc(sizeof(struct liste_noeud));
    liste->cle = malloc(strlen(cle) + 1);
    strcpy(liste->cle, cle);
    liste->valeur = malloc(strlen(valeur) + 1);
    strcpy(liste->valeur, valeur);
    liste->prochain = NULL;
  }

  else {
    ListeNoeud noeud = (struct liste_noeud *)malloc(sizeof(struct liste_noeud));
    noeud->cle = malloc(strlen(cle) + 1);
    strcpy(noeud->cle, cle);
    noeud->valeur = malloc(strlen(valeur) + 1);
    strcpy(noeud->valeur, valeur);
    noeud->prochain = NULL;

    ListeNoeud dernier = liste;
    while (dernier->prochain != NULL) {
      dernier = dernier->prochain;
    }
    dernier->prochain = noeud;
  }

  return liste;
}

char *recuperer_liste(ListeNoeud liste, char *cle) {
  ListeNoeud noeud = liste;
  while (noeud != NULL) {
    if (strcmp(noeud->cle, cle) == 0) {
      return noeud->valeur;
    }
    noeud = noeud->prochain;
  }
  return "NULL";
}