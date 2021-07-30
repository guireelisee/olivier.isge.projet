#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// Type enregistrement
typedef struct Etudiant
{
  char nom[50], prenom[50];
  int age, matricule;
  float moyenne_generale;
}Etudiant;

int tailleTableau(Etudiant etudiant[])
{
  int compteur = 0;
  while (etudiant[compteur].age != 0)
  {
    compteur++;
  }
  return compteur;
}

Etudiant inscription(int N)
{
  Etudiant etudiant[N];
  int i = 0;
  printf("\nINSCRIPTION D'UN ETUDIANT\n\n");
  while (i < N)
  {
    printf("Renseigner les information de l'étudiant n°%d: \n\n", i+1);
    printf("Nom: ");
    scanf("%s", etudiant[i].nom);
    printf("Prénom(s): ");
    scanf("%s", etudiant[i].prenom);
    printf("Age: ");
    scanf("%d", &etudiant[i].age);
    printf("Matricule: ");
    scanf("%d", &etudiant[i].matricule);
    printf("Moyenne générale: ");
    scanf("%f", &etudiant[i].moyenne_generale);
    i++;
    printf("\n");
  }
  return etudiant[N];
}

void classement(Etudiant etudiant[])
{
  int i, j;
  Etudiant tmp;
  // Tri à bulle par ordre décroissant
  for (j = 1; j <= tailleTableau(etudiant); j++)
  {
    for (i = 0; i < tailleTableau(etudiant) - 1; i++)
    {
      if (etudiant[i + 1].moyenne_generale > etudiant[i].moyenne_generale)
      {
        tmp = etudiant[i+1];
        etudiant[i+1] = etudiant[i];
        etudiant[i] = tmp;
      }
    }
  }
  i = 0;
  while (i < tailleTableau(etudiant))
  {
    printf("\nRang: %d\nNom: %s\nPrénom(s): %s\nAge: %d\nMatricule: %d\nMoyenne: %f", i+1,etudiant[i].nom, etudiant[i].prenom, etudiant[i].age, etudiant[i].matricule, etudiant[i].moyenne_generale);
    printf("\n");
    i++;
  }

}

void decisionJury(Etudiant etudiant[])
{
  int i = 0;
  while (i < tailleTableau(etudiant))
  {
    if (etudiant[i].moyenne_generale >= 12)
    {
      switch ((int)etudiant[i].moyenne_generale)
      {
      case 12:case 13:
        printf("\nL'étudiant %s %s a la mention ASSEZ-BIEN.", etudiant[i].nom, etudiant[i].prenom);
        break;
      case 14:case 15:
        printf("\nL'étudiant %s %s a la mention BIEN.", etudiant[i].nom, etudiant[i].prenom);
        break;
      case 16:case 17:
        printf("\nL'étudiant %s %s a la mention TRÈS BIEN.", etudiant[i].nom, etudiant[i].prenom);
        break;
      case 18:case 19:case 20:
        printf("\nL'étudiant %s %s a la mention EXCELLENT.", etudiant[i].nom, etudiant[i].prenom);
        break;
      default:
        break;
      }
    }
    else if (etudiant[i].moyenne_generale >= 7 && etudiant[i].moyenne_generale <= 9 )
    {
      printf("\nL'étudiant %s %s est autorisé à redoubler.", etudiant[i].nom, etudiant[i].prenom);
    }
    else if (etudiant[i].moyenne_generale < 7)
    {
      printf("\nL'étudiant %s %s est renvoyé.", etudiant[i].nom, etudiant[i].prenom);
    }
    i++;
  }
}

int main(int argc, char const *argv[])
{
  int choix, N;
  Etudiant etudiant[100];

  etudiant[0].age = 21;
  etudiant[0].moyenne_generale = 5;
  etudiant[1].age = 20;
  etudiant[1].moyenne_generale = 12;
  etudiant[2].age = 19;
  etudiant[2].moyenne_generale = 15;
  etudiant[3].age = 18;
  etudiant[3].moyenne_generale = 20;

  while (1)
  {
    printf("\nMENU PRINCIPAL\n");
    printf("\n1 - Inscription");
    printf("\n2 - Classement");
    printf("\n3 - Décision du jury");
    printf("\n4 - Quitter");
    printf("\n\nChoix: ");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
      printf("\nNombre d'étudiants à inscrire: ");
      scanf("%d",&N);
      etudiant[100] = inscription(N);
      break;
    case 2:
      classement(etudiant);
      break;
    case 3:
      decisionJury(etudiant);
      break;
    case 4:
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("\n\tChoix inexistant. Réessayer !\n");
      break;
    }
  };

  return 0;
}

