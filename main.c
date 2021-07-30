#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

enum categorie {ALIMENTAIRE, MENAGE, ACCESSOIRES, JEUX}; // Enumération des catégories de produit

// Type enregistrement
typedef struct produit
{
  char nom_produit[50];
  float prix_produit;
  int nombre_produit;
  bool promo_produit;
  enum categorie categorie_produit;
}produit;

produit stock[100];

// Procédure pour afficher la catégorie d'un produit
void afficher_categorie(enum categorie c)
{
  switch (c)
  {
  case ALIMENTAIRE:
    printf("ALIMENTAIRE");
    break;
  case MENAGE:
    printf("MENAGE");
    break;
  case ACCESSOIRES:
    printf("ACCESSOIRES");
    break;
  case JEUX:
    printf("JEUX");
    break;
  default:
    break;
  }
}

// Fonction pour retourner une catégorie en fonction du choix
enum categorie affecter_categorie(int choix)
{
  switch (choix)
  {
  case 0:
    return ALIMENTAIRE;
    break;
  case 1:
    return MENAGE;
    break;
  case 2:
    return ACCESSOIRES;
    break;
  case 3:
    return JEUX;
    break;
  default:
    break;
  }
}

void enregistrer_stock()
{
  produit p;
  char choix_promo[3], choix_encore[3];
  enum categorie c;
  int choix_categorie, i;
  printf("\nENREGISTREMENT STOCK\n\n");
  printf("Nom du produit: ");
  scanf("%s",p.nom_produit);
  printf("Prix du produit: ");
  scanf("%f",&p.prix_produit);
  printf("Nombre du produit: ");
  scanf("%d",&p.nombre_produit);
  printf("Catégories des produit ");

  // Lister toutes les catégories disponibles et faire un choix
  for (c = ALIMENTAIRE; c <= JEUX; c++)
  {
    printf("\n\t%d - ", c);
    afficher_categorie(c);
  }
  printf("\n\tFaites votre choix: ");
  scanf("%d",&choix_categorie);
  p.categorie_produit = affecter_categorie(choix_categorie);

  do
  {
    printf("Ce produit est-il en promo ? [(O)ui / (N)on]: ");
    scanf("%s", choix_promo);
    if (strcasecmp(choix_promo, "O") != 0 && strcasecmp(choix_promo, "N") != 0)
    {
      printf("\n\tVeuillez saisir la bonne lettre !\n\n");
    }

  } while (strcasecmp(choix_promo, "O") != 0 && strcasecmp(choix_promo, "N") != 0);

  p.promo_produit = (strcasecmp(choix_promo, "O") == 0) ? true : false;

  // Stockage de nouveau produit dans le tableau
  for (i = 0; i < 100; i++)
  {
    if (stock[i].nombre_produit == 0)
    {
      stock[i] = p;
      break;
    }
  }

  do
  {
    printf("\nVoulez-vous enregistrer un autre produit ? [ (O)ui / (N)on ]: ");
    scanf("%s", choix_encore);
    if (strcasecmp(choix_encore, "O") != 0 && strcasecmp(choix_encore, "N") != 0)
    {
      printf("\n\tVeuillez saisir la bonne lettre !\n");
    }
    if (strcasecmp(choix_encore, "O") == 0)
    {
      enregistrer_stock();
    }
  } while (strcasecmp(choix_encore, "O") != 0 && strcasecmp(choix_encore, "N") != 0);

}

void rechercher_par_prix(float prix)
{
  int i, compteur = 0;
  for (i = 0; i < 100; i++)
  {
    if (stock[i].nombre_produit != 0)
    {
      compteur++;
    }
  }


}

void tri_prix()
{
  float prix_tmp = 0;
  int i, j, compteur = 0, trouver = 0;
  produit produit_tmp;
  for (i = 0; i < 100; i++)
  {
    if (stock[i].nombre_produit != 0)
    {
      compteur++;
    }
  }

  // Tri à bulle
  for (j = 1; j <= compteur; j++)
  {
    for (i = 0; i < compteur - 1; i++)
    {
      if (stock[i].prix_produit > stock[i + 1].prix_produit)
      {
        produit_tmp = stock[i];
        stock[i] = stock[i + 1];
        stock[i + 1] = produit_tmp;
      }
    }
  }

  printf("\n");
  for ( i = 0; i < compteur; i++)
  {
    for (j = 0; j < compteur; j++)
    {
      if (j == 0)
      {
        printf("\nListe des produits qui font %f ", stock[i].prix_produit);
      }
      if (stock[j].prix_produit == stock[i].prix_produit)
      {
        trouver++;
      }
    }
    if (trouver != 0)
    {
      printf("\nNom: %s ", stock[i].nom_produit);
      printf("\nNombre: %d ", stock[i].nombre_produit);
      printf("\nCatégorie: ");
      afficher_categorie(stock[i].categorie_produit);
      printf("\nPromo: %s", (stock[i].promo_produit == true) ? "Oui" : "Non");
      printf("\n");
    }
  }
}

int main(int argc, char const *argv[])
{
  int choix;

  // stock[0].nom_produit[50] = "Produit 1";
  stock[0].nombre_produit = 1;
  stock[0].prix_produit = 25.00;
  stock[0].categorie_produit = ALIMENTAIRE;
  stock[0].promo_produit = 1;

  // stock[1].nom_produit[50] = "Produit 2";
  stock[1].nombre_produit = 2;
  stock[1].prix_produit = 50.00;
  stock[1].categorie_produit = JEUX;
  stock[1].promo_produit = 0;

  // stock[2].nom_produit[50] = "Produit 3";
  stock[2].nombre_produit = 3;
  stock[2].prix_produit = 100.00;
  stock[2].categorie_produit = ACCESSOIRES;
  stock[2].promo_produit = 1;

  // stock[3].nom_produit[50] = "Produit 4";
  stock[3].nombre_produit = 4;
  stock[3].prix_produit = 25.00;
  stock[3].categorie_produit = ACCESSOIRES;
  stock[3].promo_produit = 1;

  // stock[4].nom_produit[50] = "Produit 4";
  stock[4].nombre_produit = 5;
  stock[4].prix_produit = 50.00;
  stock[4].categorie_produit = ACCESSOIRES;
  stock[4].promo_produit = 0;

  while (1)
  {
    printf("\nMENU PRINCIPAL\n");
    printf("\n1 - Enregistrer un produit");
    printf("\n2 - Trier en fonction du prix");
    printf("\n3 - Trier en fonction de la catégorie");
    printf("\n4 - Quitter");
    printf("\n\nChoix: ");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
      enregistrer_stock();
      break;
    case 2:
      tri_prix();
      break;
    case 3:
      break;
    case 4:
      exit(EXIT_SUCCESS);
      break;
    default:
    printf("ok");
      break;
    }
  };

  return 0;
}

