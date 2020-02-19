#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void SetColor(int ForgC) {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

typedef struct Items Items_t;
struct Items
{
    char* nom;
    int prix;
    int poids;
    int quantite;
    int level;
    int durabilite;
};

typedef struct Inventaire Inventaire_t;
struct Inventaire
{
    int inventaire;
    int inventaireMax;
    int poids;
    int poidsMax;
    int argent;
    int level;
};


int main (){

int jeu = 0;
int visuelle = 0;
int coffre;
int choixQuantite;
char nomcoffre[20];
int nombreItem = 2;

// les données du héros liés à son inventaire
Inventaire_t herosInventaire ={0, 20, 0, 25, 150, 1};

// Les items pour le commerce
Items_t bouclier ={"Bouclier", 30, 4, 3, 1, 100};
Items_t epee ={"Epee", 50, 3, 5, 1, 100};
Items_t plastron ={"Plastron", 40, 5, 2, 1, 100};
Items_t potiondeSoin ={"Potion de Soin", 30, 1, 15, 1, 100};
Items_t potiondeRez ={"Potion de Resurrection", 200, 1, 5, 1, 100};
Items_t monItem ={"Mon Item", 0, 0, 0, 0, 100};
Items_t itemCoffre ={"Item Exemple", 0, 0, 0, 0, 100};

// Pour le shop du commercant
Items_t shop[6];
shop[0] = bouclier;
shop[1] = epee;
shop[2] = plastron;
shop[3] = potiondeSoin;
shop[4] = potiondeRez;
shop[5] = monItem;

// Pour l'inventaire
Items_t slot[20];
slot[0] = bouclier;
slot[0].prix = slot[0].prix/5;
slot[1] = potiondeRez;
slot[1].prix = slot[1].prix/5;
slot[2] = itemCoffre;

Inventaire_t inventaireVisuel[1];
inventaireVisuel[0] = herosInventaire;

// Permet de trier grâce à l'alphabet
int i;
int j;
Items_t shopTemp[1];
shopTemp[0] = shop[0];

while (jeu == 0) {

coffre = 0;

// Affichage shop comemrcant
SetColor(8);

printf("\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                       SHOP DU COMMERCANT                    |");
printf("%s\n\n", "                           |_____________________________________________________________|");

printf("\n%s", "                _______________________________________________________________________________________\n");
printf("%s", "               |                                                                                      |");
printf("\n%s", "               |            ***********             ******       *******      **********     *******  |");
printf("\n%s", "               |           *   ITEMS   *           * PRIX *     * POIDS *    * QUANTITE *   * LEVEL * |");
printf("\n%s", "               |            ***********             ******       *******      **********     *******  |");
printf("\n%s", "               |                                                                                      |");
printf("\n""               |     %s                   |     %d      |     %d     |      x%d       |     %d     |", shop[0]);
printf("\n""               |     %s                       |     %d      |     %d     |      x%d       |     %d     |", shop[1]);
printf("\n""               |     %s                   |     %d      |     %d     |      x%d       |     %d     |", shop[2]);
printf("\n""               |     %s             |     %d      |     %d     |      x%d      |     %d     |", shop[3]);
printf("\n""               |     %s     |     %d     |     %d     |      x%d       |     %d     |", shop[4]);
printf("\n""               |     %s                   |     %d       |     %d     |      x%d       |     %d     |\n", shop[5]);
printf("%s\n", "               |                                                                                      |");
printf("%s\n", "               |______________________________________________________________________________________|");


SetColor(15);

Sleep(2000);

// affichage Inventaire Heros
SetColor(3);

printf("\n\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                        VOTRE INVENTAIRE                     |");
printf("%s\n\n", "                           |_____________________________________________________________|");

printf("\n%s", "      _____________________________________________________________________________________________________________________________\n");
printf("\n%s", "              *************************          **************************          *************          ************");
printf("\n" "             * ESPACE INVENTAIRE : %d/%d *       * POIDS INVENTAIRE : %d/%d  *        * ARGENT : %d *       * LEVEL : %d  *", inventaireVisuel[0]);
printf("\n%s", "              *************************          **************************          *************          ************");
printf("\n%s", "                                                                                                 ");
printf("\n""     |   %s                  |   Vente : %d    |   Poids : %d   |   Quantite : x%d   |   Level : %d   |   Durabilite : %d/100   |", slot[0]);
printf("\n""     |   %s    |   Vente : %d   |   Poids : %d   |   Quantite : x%d   |   Level : %d   |   Durabilite : %d/100   |", slot[1]);
printf("\n""     |   %s    |   Vente : %d   |   Poids : %d   |   Quantite : x%d   |   Level : %d   |   Durabilite : %d/100   |\n", slot[2]);
printf("%s\n", "                                                                               ");
printf("%s\n\n", "      _____________________________________________________________________________________________________________________________");

SetColor(15);

// Choix de l'item à acheter ou à fabriquer
Sleep(1000);
printf("\n%s\n\n", "----------------------------------------------------");
printf("%s\n", "Avant de choisir les items que vous souhaitez acheter, desirez-vous trier dans l'ordre les objets ? Il est important de vous notifiez que si vous effectuez ce tri, l'interface graphique sera moins lisible");
printf("%s\n", "Tapez [0] pour garder l'interface actuelle ; Tapez [1] pour trier dans l'ordre alphabetique ; Tapez [2] pour trier dans l'ordre croissant des prix ; Tapez [3] pour trier dans l'ordre croissant des levels");
printf("Votre choix : ");
SetColor (3);
scanf("%d", &visuelle);
SetColor (15);

if (visuelle == 0) {
printf("%s\n", "vous avez decide de garder l'interface actuelle [MERCI]");
} else if (visuelle == 1) {
  for (i = 0; i < 6; i++) {
    for (j=i+1 ; j < 6; j++) {
      if (strcmp(shop[i].nom, shop[j].nom) > 0) {
  shopTemp[0] = shop[i];
  shop[i] = shop[j];
  shop[j] = shopTemp[0];
      }
    }
  }
} else if (visuelle == 2) {
  for (i = 0; i < 6; i++) {
    for (j=i+1 ; j < 6; j++) {
      if (shop[i].prix < shop[j].prix) {
  shopTemp[0] = shop[i];
  shop[i] = shop[j];
  shop[j] = shopTemp[0];
      }
    }
  }
} else if (visuelle == 3) {
  for (i = 0; i < 6; i++) {
    for (j=i+1 ; j < 6; j++) {
      if (shop[i].level, shop[j].level) {
  shopTemp[0] = shop[i];
  shop[i] = shop[j];
  shop[j] = shopTemp[0];
      }
    }
  }
}


printf("\n\n%s\n\n", "----------------------------------------------------");
SetColor(8);
printf("%s\n", "Avez vous un items qui correspond a vos attentes ? Si oui entrer le numero de l'objet souhaite ci-dessous, si non, entrer [-1]");
printf("\n" "[0 = %s] ", shop[0]); printf("[1 = %s] ", shop[1]); printf("[2 = %s] ", shop[2]); printf("[3 = %s] ", shop[3]); printf("[4 = %s] ", shop[4]); printf("[5 = %s]\n", shop[5]);
printf("Item : ");
SetColor (3);
scanf("%d", &coffre);
SetColor (15);

// Si l'item n'est plus disponible dans le shop
SetColor (4);
if (coffre == 0 && shop[0].quantite == 0){
  printf("\n%s\n", "L'item n'est plus disponible");
} else if (coffre == 1 && shop[1].quantite == 0){
  printf("\n%s\n", "L'item n'est plus disponible ");
}  else if (coffre == 2 && shop[2].quantite == 0){
  printf("\n%s\n", "L'item n'est plus disponible");
}  else if (coffre == 3 && shop[3].quantite == 0){
  printf("\n%s\n", "L'item n'est plus disponible");
}  else if (coffre == 4 && shop[4].quantite == 0){
  printf("\n%s\n", "L'item n'est plus disponible");
}
SetColor (15);

// Si le joueur n'a plus d'argent
SetColor (4);
if (coffre == 0 && inventaireVisuel[0].argent < shop[0].prix){
  printf("\n%s\n", "Vous n'avez pas assez d'argent pour acheter cet item");
} else if (coffre == 1 && inventaireVisuel[0].argent < shop[1].prix){
  printf("\n%s\n", "Vous n'avez pas assez d'argent pour acheter cet item");
}  else if (coffre == 2 && inventaireVisuel[0].argent < shop[2].prix){
  printf("\n%s\n", "Vous n'avez pas assez d'argent pour acheter cet item");
}  else if (coffre == 3 && inventaireVisuel[0].argent < shop[3].prix){
  printf("\n%s\n", "Vous n'avez pas assez d'argent pour acheter cet item");
}  else if (coffre == 4 && inventaireVisuel[0].argent < shop[4].prix){
  printf("\n%s\n", "Vous n'avez pas assez d'argent pour acheter cet item");
}
SetColor (15);

// Si le joueur n'a plus de place dans son inventaire
SetColor (4);
if (coffre == 0 && inventaireVisuel[0].inventaire > inventaireVisuel[0].inventaireMax){
  printf("\n%s\n", "Vous n'avez pas assez de place dans votre inventaire pour acheter cet item");
} else if (coffre == 1 && inventaireVisuel[0].inventaire > inventaireVisuel[0].inventaireMax){
  printf("\n%s\n", "Vous n'avez pas assez de place dans votre inventaire pour acheter cet item");
}  else if (coffre == 2 && inventaireVisuel[0].inventaire > inventaireVisuel[0].inventaireMax){
  printf("\n%s\n", "Vous n'avez pas assez de place dans votre inventaire pour acheter cet item");
}  else if (coffre == 3 && inventaireVisuel[0].inventaire > inventaireVisuel[0].inventaireMax){
  printf("\n%s\n", "Vous n'avez pas assez de place dans votre inventaire pour acheter cet item");
}  else if (coffre == 4 && inventaireVisuel[0].inventaire > inventaireVisuel[0].inventaireMax){
  printf("\n%s\n", "Vous n'avez pas assez de place dans votre inventaire pour acheter cet item");
}
SetColor (15);

// Si le poids de l'inventaire est trop élevé
SetColor (4);
if (coffre == 0 && inventaireVisuel[0].poids + shop[0].poids > inventaireVisuel[0].poidsMax){
  printf("\n%s\n", "Votre inventaire est trop lourd pour acheter cet item");
} else if (coffre == 1 && inventaireVisuel[0].poids + shop[1].poids > inventaireVisuel[0].poidsMax){
  printf("\n%s\n", "Votre inventaire est trop lourd pour acheter cet item");
}  else if (coffre == 2 && inventaireVisuel[0].poids + shop[2].poids > inventaireVisuel[0].poidsMax){
  printf("\n%s\n", "Votre inventaire est trop lourd pour acheter cet item");
}  else if (coffre == 3 && inventaireVisuel[0].poids + shop[3].poids > inventaireVisuel[0].poidsMax){
  printf("\n%s\n", "Votre inventaire est trop lourd pour acheter cet item");
}  else if (coffre == 4 && inventaireVisuel[0].poids + shop[4].poids > inventaireVisuel[0].poidsMax){
  printf("\n%s\n", "Votre inventaire est trop lourd pour acheter cet item");
}
SetColor (15);

// CHOIX DES ITEMS ET LEURS QUANTITÉS
// CHOIX DES ITEMS ET LEURS QUANTITÉS
Sleep(2000);
SetColor (8);
if (coffre == 0 && shop[0].quantite > 0 && inventaireVisuel[0].argent > shop[0].prix) {
  printf("\nCombien voulez vous acheter de %s ? \nNombre : ", shop[0].nom);
SetColor (3);
  scanf("%d", &coffre);
SetColor (8);
    if (coffre*shop[0].prix > inventaireVisuel[0].argent || inventaireVisuel[0].inventaire + coffre > inventaireVisuel[0].inventaireMax || inventaireVisuel[0].poids + shop[0].poids*coffre > inventaireVisuel[0].poidsMax || shop[0].quantite < coffre) {
        SetColor (4);
        printf("\nLa quantite demande est impossible ou vous n'avez pas assez d'argent/de place dans votre inventaire pour acheter autant de %ss\n", shop[0].nom);
        SetColor (15);
    } else {
      printf("\nVous venez d'acheter %d %ss\n", coffre, shop[0].nom);
      shop[0].quantite = shop[0].quantite - coffre;
      inventaireVisuel[0].inventaire = inventaireVisuel[0].inventaire + coffre;
      inventaireVisuel[0].argent = inventaireVisuel[0].argent - shop[0].prix*coffre;
      inventaireVisuel[0].poids = inventaireVisuel[0].poids + shop[0].poids*coffre;
      // Exemple de l'ajout d'un l'item dans l'inventaire
      slot[nombreItem].nom = shop[0].nom; slot[nombreItem].prix = shop[0].prix*coffre/5 ; slot[nombreItem].poids = shop[0].poids*coffre ; slot[nombreItem].quantite = coffre ; slot[nombreItem].level = shop[0].level ;
      ++nombreItem;
    }

} else if (coffre == 1 && shop[1].quantite > 0 && inventaireVisuel[0].argent > shop[1].prix) {
  printf("\nCombien voulez vous acheter de %s ? \nNombre : ", shop[1].nom);
SetColor (3);
  scanf("%d", &coffre);
SetColor (8);
    if (coffre*shop[1].prix > inventaireVisuel[0].argent || inventaireVisuel[0].inventaire + coffre > inventaireVisuel[0].inventaireMax || inventaireVisuel[0].poids + shop[1].poids*coffre > inventaireVisuel[0].poidsMax || shop[1].quantite < coffre) {
      SetColor (4);
        printf("\nLa quantite demande est impossible ou vous n'avez pas assez d'argent/de place dans votre inventaire pour acheter autant de %ss\n", shop[1].nom);
      SetColor (15);
    } else {
      printf("\nVous venez d'acheter %d %ss\n", coffre, shop[1].nom);
      shop[1].quantite = shop[1].quantite - coffre;
      inventaireVisuel[0].inventaire = inventaireVisuel[0].inventaire + coffre;
      inventaireVisuel[0].argent = inventaireVisuel[0].argent - shop[1].prix*coffre;
      inventaireVisuel[0].poids = inventaireVisuel[0].poids + shop[1].poids*coffre;
    }

} else if (coffre == 2 && shop[2].quantite > 0 && inventaireVisuel[0].argent > shop[2].prix) {
  printf("\nCombien voulez vous acheter de %s ? \nNombre : ", shop[2].nom);
SetColor (3);
  scanf("%d", &coffre);
SetColor (8);
    if (coffre*shop[2].prix > inventaireVisuel[0].argent || inventaireVisuel[0].inventaire + coffre > inventaireVisuel[0].inventaireMax || inventaireVisuel[0].poids + shop[2].poids*coffre > inventaireVisuel[0].poidsMax || shop[2].quantite < coffre) {
      SetColor (4);
        printf("\nLa quantite demande est impossible ou vous n'avez pas assez d'argent/de place dans votre inventaire pour acheter autant de %ss\n", shop[2].nom);
      SetColor (15);
    } else {
      printf("\nVous venez d'acheter %d %ss\n", coffre, shop[2].nom);
      shop[2].quantite = shop[2].quantite - coffre;
      inventaireVisuel[0].inventaire = inventaireVisuel[0].inventaire + coffre;
      inventaireVisuel[0].argent = inventaireVisuel[0].argent - shop[2].prix*coffre;
      inventaireVisuel[0].poids = inventaireVisuel[0].poids + shop[2].poids*coffre;
    }

} else if (coffre == 3 && shop[3].quantite > 0 && inventaireVisuel[0].argent > shop[3].prix) {
  printf("\nCombien voulez vous acheter de %s ? \nNombre : ", shop[3].nom);
SetColor (3);
  scanf("%d", &coffre);
SetColor (8);
    if (coffre*shop[3].prix > inventaireVisuel[0].argent || inventaireVisuel[0].inventaire + coffre > inventaireVisuel[0].inventaireMax || inventaireVisuel[0].poids + shop[3].poids*coffre > inventaireVisuel[0].poidsMax || shop[3].quantite < coffre) {
      SetColor (4);
        printf("\nLa quantite demande est impossible ou vous n'avez pas assez d'argent/de place dans votre inventaire pour acheter autant de %ss\n", shop[3].nom);
      SetColor (15);
    } else {
      printf("\nVous venez d'acheter %d %ss\n", coffre, shop[3].nom);
      shop[3].quantite = shop[3].quantite - coffre;
      inventaireVisuel[0].inventaire = inventaireVisuel[0].inventaire + coffre;
      inventaireVisuel[0].argent = inventaireVisuel[0].argent - shop[3].prix*coffre;
      inventaireVisuel[0].poids = inventaireVisuel[0].poids + shop[3].poids*coffre;
    }

} else if (coffre == 4 && shop[4].quantite > 0 && inventaireVisuel[0].argent > shop[4].prix) {
  printf("\nCombien voulez vous acheter de %s ? \nNombre : ", shop[4].nom);
SetColor (3);
  scanf("%d", &coffre);
SetColor (8);
    if (coffre*shop[4].prix > inventaireVisuel[0].argent || inventaireVisuel[0].inventaire + coffre > inventaireVisuel[0].inventaireMax || inventaireVisuel[0].poids + shop[4].poids*coffre > inventaireVisuel[0].poidsMax || shop[4].quantite < coffre) {
      SetColor (4);
        printf("\nLa quantite demande est impossible ou vous n'avez pas assez d'argent/de place dans votre inventaire pour acheter autant de %ss\n", shop[4].nom);
      SetColor (15);
    } else {
      printf("\nVous venez d'acheter %d %ss\n", coffre, shop[4].nom);
      shop[4].quantite = shop[4].quantite - coffre;
      inventaireVisuel[0].inventaire = inventaireVisuel[0].inventaire + coffre;
      inventaireVisuel[0].argent = inventaireVisuel[0].argent - shop[4].prix*coffre;
      inventaireVisuel[0].poids = inventaireVisuel[0].poids + shop[4].poids*coffre;
    }

// ITEM À FABRIQUER
} else if (coffre == 5) {
printf("\n%s\n", "Vous avez decide de creer un item pour l'implemanter dans le shop du commercant");
  printf("%s\n", "Quel nom souhaitez-vous donnez a l'item ?");
  printf("%s", "Item : ");
SetColor (3);
  scanf("%s", &nomcoffre);
  monItem.nom = nomcoffre;
SetColor (8);
Sleep(1000);
  printf("\n%s\n", "D'accord, c'est note ");
  printf("%s", "Son prix : ");
SetColor (3);
  scanf("%d", &coffre);
  monItem.prix = coffre;
SetColor (8);
Sleep(1000);
  printf("\n%s\n", "D'accord, c'est note ");
  printf("%s", "Et pour terminer, son poids : ");
SetColor (3);
  scanf("%d", &coffre);
  monItem.poids = coffre;
Sleep(1000);
SetColor (8);
  printf("\n%s\n", "Voici l'item qui sera ajoute au shop");
  monItem.quantite = 1;
  monItem.level = 1;
  shop[5] = monItem;
  printf("| %s |   Vente : %d   |   Poids : %d   |   Quantite : x%d   |   Level : %d   |", shop[5]);
} else if (coffre == -1) {
  printf("\n%s\n", "Merci de votre visite, au revoir");
  jeu = 1;
}

Sleep(2000);
SetColor (15);
system("cls");

}

SetColor(15);
return 0;
}
