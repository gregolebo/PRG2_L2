/*
 -----------------------------------------------------------------------------------
 Nom du fichier : calculs.c
 Auteur(s)      : Grégoire Guyot, Céline Roger, Pablo Urizar
 Date creation  : 26.05.2022
 Description    : Implémentation de la librairie calculs.h mettant à disposition
                  des fonctions qui permettent de :
                  - calculer la somme, la moyenne, la mediane et l'écart-type
                  - comparer les taxes de deux vehicules
                  - comparer des valeurs de type double
 Remarque(s)    : -
 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <math.h>
#include <assert.h>
#include <string.h>
#include "calculs.h"
#include "taxes.h"

double somme(const double tab[], size_t n) {
   if (n <= 0) {
      return NAN;
   }

   double somme = 0;
   for (size_t i = 0; i < n; ++i) {
      somme += tab[i];
   }
   return somme;
}

double moyenne(const double tab[], size_t n) {
   if (n <= 0) {
      return NAN;
   }

   return somme(tab, n) / (double) n;
}

// Fonction de comparaison utilisée dans le qsort() nécessaire pour le calcul de la médiane
int compareDouble(const void *x, const void *y) {
   if (*(double *) x > *(double *) y) {
      return 1;
   } else if (*(double *) x == *(double *) y) {
      return 0;
   } else {
      return -1;
   }
}

double mediane(const double tab[], size_t taille) {
   if (taille <= 0) {
      return NAN;
   }

   double* ptr = (double*) calloc(taille, sizeof(double));
   if (ptr) {
      memcpy(ptr, tab, taille);
   }

   double mediane;
   qsort(ptr, taille, sizeof(double), compareDouble);
   if (taille % 2) {
      mediane = tab[taille / 2];
   } else {
      mediane = (tab[(taille - 1) / 2] + tab[taille / 2]) / 2;
   }

   free(ptr);
   ptr = NULL;

   return mediane;
}

double ecartType(const double tab[], size_t n) {
   // Ecart-type nul s'il n'y a qu'un seul véhicule ou si le tableau est vide
   if (n == 1 || n <= 0) {
      return NAN;
   }

   double sommeCarres = 0, ecartType;
   for (size_t i = 0; i < n; ++i) {
      sommeCarres += pow(tab[i] - moyenne(tab, n), 2);
   }
   ecartType = sqrt(sommeCarres / (double) (n));
   return ecartType;
}

size_t compteurType(const Vehicule* parking, size_t tailleParking, Critere type) {
   assert(parking != NULL);
   assert(type != TYPE_INDEFINI);
   size_t cpt = 0;

   for (size_t i = 0; i < tailleParking; ++i) {
      if (quelType(&parking[i]) == type)
         ++cpt;
   }
   return cpt;
}

// Fonction de comparaison utilisée dans qsort() de la fonction afficherParking
int compareTaxes(const void* x, const void* y) {
   double fa = taxeAnnuelle((const Vehicule*)x);
   double fb = taxeAnnuelle((const Vehicule*)y);
   return (fa < fb) - (fa > fb);
}
