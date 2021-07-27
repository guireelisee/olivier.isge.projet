#include<stdio.h>
#include<stdbool.h>

enum categorie {ALIMENTAIRE, MENAGE, ACCESSOIRES, JEUX};

typedef struct produit
{
  char nom_produit[50];
  float prix_produit;
  int nombre_produit;
  bool promo_produit;
  enum categorie categorie_produit;
}produit;

int main(int argc, char const *argv[])
{
  int choix;
  printf("\nMENU PRINCIPAL");
  printf("\nChoix: ");
  scanf("%d",&choix);
  return 0;
}

