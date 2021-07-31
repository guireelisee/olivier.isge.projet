#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum categorie
{
  ALIMENTAIRE,
  MENAGE,
  ACCESSOIRES,
  JEUX
}; // Enumération des catégories de produit

int tmp;
int total;
// Type enregistrement
typedef struct produit
{
  char nom_produit[50];
  float prix_produit;
  int nombre_produit;
  bool promo_produit;
  enum categorie categorie_produit;
} produit;

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
  scanf("%s", p.nom_produit);
  printf("Prix du produit: ");
  scanf("%f", &p.prix_produit);
  printf("Nombre du produit: ");
  scanf("%d", &p.nombre_produit);
  printf("Catégories des produit ");

  // Lister toutes les catégories disponibles et faire un choix
  for (c = ALIMENTAIRE; c <= JEUX; c++)
  {
    printf("\n\t%d - ", c);
    afficher_categorie(c);
  }
  printf("\n\tFaites votre choix: ");
  scanf("%d", &choix_categorie);
  p.categorie_produit = affecter_categorie(choix_categorie);

  do
  {
    printf("\nCe produit est-il en promo ? [(O)ui / (N)on]: ");
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
void tri_categorie(int j)
{
    printf("\n\t ******** { AFFICHAGE SELON LA CATEGORIE } ********\t\n");

  printf("\n*********************** CATEGORIE : AIMENTAIRE ***********************\n");
  for (int i = 0; i < j-1; i++)
  {

    if (stock[i].categorie_produit == ALIMENTAIRE)
    {
      printf("\nNom du produit: %s\n", stock[i].nom_produit);
      printf("\nPrix du produit: %f\n", stock[i].prix_produit);
      printf("\nStock: %d\n", stock[i].nombre_produit);
      printf(stock[i].promo_produit == false ? "\nCe Article n'est pas en promo" : "\nCe article est en Promo\n");
      printf("\n***********\n");
    }
  }
  printf("\n");
  printf("\n*********************** CATEGORIE : MENAGE *************************\n");
  for (int i = 0; i < j - 1; i++)
  {

    if (stock[i].categorie_produit == MENAGE)
    {
      printf("\nNom du produit: %s\n", stock[i].nom_produit);
      printf("\nPrix du produit: %f\n", stock[i].prix_produit);
      printf("\nStock: %d\n", stock[i].nombre_produit);
      printf(stock[i].promo_produit == false ? "\nCe Article n'est pas en promo" : "\nCe article est en Promo\n");
      printf("\n***********\n");
    }
  }
  printf("\n");
  printf("\n********************** CATEGORIE : ACCESSOIRES ******************\n");

  for (int i = 0; i < j - 1; i++)
  {

    if (stock[i].categorie_produit == ACCESSOIRES)
    {
      printf("\nNom du produit: %s\n", stock[i].nom_produit);
      printf("Prix du produit: %f\n", stock[i].prix_produit);
      printf("Stock: %d\n", stock[i].nombre_produit);
      printf(stock[i].promo_produit == false ? "\nCe Article n'est pas en promo" : "\nCe article est en Promo\n");
      printf("\n***********\n");
    }
  }
  printf("\n");
  printf("\n********************** CATEGORIE : JEUX ****************\n");
  for (int i = 0; i < j - 1; i++)
  {

    if (stock[i].categorie_produit == JEUX)
    {
      printf("\nNom du produit: %s\n", stock[i].nom_produit);
      printf("Prix du produit: %f\n", stock[i].prix_produit);
      printf("Stock: %d\n", stock[i].nombre_produit);
      printf(stock[i].promo_produit == false ? "\nCe Article n'est pas en promo" : "\nCe article est en Promo\n");
      printf("\n***********\n");
    }
  }
}

void tri_selonPrix(int k)
{
  printf("\n\t ******** { AFFICHAGE SELON LE PRIX } ********\t\n");
  produit product;
  int i;
  bool order = false;
  while (!order)
  {
    order = true;
    for (int i = 0; i < k-1; i++)
    {
      if (stock[i].prix_produit > stock[i + 1].prix_produit)
      {
        tmp = stock[i].prix_produit;
        stock[i].prix_produit = stock[i + 1].prix_produit;
        stock[i + 1].prix_produit = tmp;
        order = false;
      }
    }
    
  }
  for (int i = 0; i < k - 1; i++)
  {
    printf("\nNom du produit: %s\n", stock[i].nom_produit);
    printf("\nPrix du produit: %f\n", stock[i].prix_produit);
    printf("\nStock: %d\n", stock[i].nombre_produit);
    printf(stock[i].promo_produit == false ? "Ce promo n'est pas en promo" : "Ce article est en Promo\n");
    printf("\n******************************************\n");
  }
}
int main(int argc, char const *argv[])
{
  int choix;
  while (1)
  {
    printf("\nMENU PRINCIPAL\n");
    printf("\n1 - Enregistrer un produit");
    printf("\n2 - Trier en fonction du prix");
    printf("\n3 - Trier en fonction de la catégorie");
    printf("\n4 - Quitter");
    printf("\n\nChoix: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      printf("\n Total des produits á ajouter : ");
      scanf("%d", &total);
      enregistrer_stock();
      break;
    case 2:
      tri_selonPrix(total);
      system("echo Appuyer sur ENTRER pour continuer . . . && ( read x 2> nul; rm nul || pause > nul )");
      break;
    case 3:


      tri_categorie(total);
      system("echo Appuyer sur ENTRER pour continuer . . . && ( read x 2> nul; rm nul || pause > nul )");
      break;
    case 4:
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("ok");
      break;
    }
  }

  return 0;
}
