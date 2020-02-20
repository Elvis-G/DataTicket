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

// Structure Statut
typedef struct Statut statut_t;
struct Statut
{
  char prenom[30];
  int age;
  char sexe[15];
  char lieu[50];
  char nationalite[30];
  char religion[30];

};

// Structure lieux
typedef struct Ticket ticket_t;
struct Ticket
{
  statut_t leStatut;
  int intelligence;
  char secteur[50];
  int revenu;
  int innocence;
  int fidelite;
};

/* Degré d’intelligence (celui-ci est renouvelable, si souhaité, auprès de soi-disant spécialistes)
Statut social (âge, célibataire/couple, sexe, lieu et type d’habitation, nationalité, religion)
Secteur du travail (ce dernier se verra classer approfondissant encore plus les disparités)
Revenu mensuelle (sera affiche sous sa forme NET)
Degré d’innocence (le casier judiciaire et les actions de l’individu impacteront ce point)
Année Fidélité (depuis combien de temps la personne a obtenu son premier Data Ticket) */

int affichageTicket (ticket_t testTicket) {
	SetColor(2);
	printf ("|Pr\202nom       : %s\n", testTicket.leStatut.prenom);
	printf ("|Age          : %d\n", testTicket.leStatut.age);
	printf ("|S\x88xe         : %s\n", testTicket.leStatut.sexe);
	printf ("|Lieu         : %s\n", testTicket.leStatut.lieu);
	printf ("|Nationalit\202  : %s\n", testTicket.leStatut.nationalite);
	printf ("|Religion     : %s\n", testTicket.leStatut.religion);
	printf ("|Int\202lligence : %d\n", testTicket.intelligence);
	printf ("|Secteur      : %s\n", testTicket.secteur);
	printf ("|Revenu       : %d\n", testTicket.revenu);
	printf ("|Innocence    : %d\n", testTicket.innocence);
	printf ("|Fid\202lit\202     : %d\n", testTicket.fidelite);
	SetColor(15);
	printf ("\n%s\n\n", "--------------------------------");
};
  statut_t testStatut = {"Georges", 18, "Homme", "Liverpool", "Francais", "Ath\202e"};
  ticket_t testTicket = {"Georges", 18, "Homme", "Liverpool", "Francais", "Ath\202e", 115, "Data Keeper", 12000, 1, 5};



// Le #coffre toujours là
int coffre;
char coffreTexte[30];
int tuto = 0;
int jeu = 0;

int main (){

char prenomList[2][100] = {"Benoit", "Suzette"};

// NOM DU MONDE
  printf("\n%s\n", "                            ______________________________");
  printf("%s\n", "                           |                              |");
  printf("%s\n", "                           |          DATA TICKET         |");
  printf("%s\n\n", "                           |______________________________|");

/* strcpy(testTicket.leStatut.prenom, prenomList[1]);
  affichageTicket (testTicket); */

SetColor (8);
  printf("\n%s", "Lancer la partie [0]");
  printf("\n%s\n", "Options [1]");
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  while (coffre != 0 & coffre != 1) {
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  }

if (coffre == 1) {
  printf("\n%s\n", "Souhaitez-vous inclure le tutoriel pour cette partie ? Ce dernier est aussi recommend\x82 pour bien comprendre l'histoire");
  printf("\n%s\n", "Si oui entrer [0], si non entrer [1]");
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  if (coffre == 0){
  printf("\n%s\n", "Un tutoriel vous saura donc propos\x82 en debut de partie");
  tuto = 0;
  printf("\n%s\n", "Maintenant, pour lancer la partie, appuyer sur [0]");
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  while (coffre != 0) {
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  }
} else {
  printf("\n%s\n", "Vous n'aurez pas de tutoriel pour cette partie, c'est not\x82");
  tuto = 1;
  printf("\n%s\n", "Maintenant, pour lancer la partie, appuyer sur [0]");
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  while (coffre != 0) {
  printf("Votre choix : ");
  SetColor (3);
  scanf("%d", &coffre);
  SetColor (8);
  }
}
}

if (coffre == 0) {
  printf("\n%s\n", "La partie va se lancer...");
}

Sleep (3000);
system("cls");
SetColor (15);

printf("\n%s\n", "                            ______________________________________");
printf("%s\n", "                           |                                      |");
printf("%s\n", "                           |       CHAPITRE 0 : DATA KEEPER       |");
printf("%s\n\n", "                           |______________________________________|");

Sleep(1000);
  SetColor (8);
  printf("\n%s", "Vous \x88tes enfin arriv\x82 \x85 votre lieu de travail pour votre premiere journ\202e d'apprentissage.");
Sleep(4000);
  printf("\n%s", "Vous \x88tes extr\x8Amement stress\x82, et cela depuis hier soir, vous ayant fait passer l'une des pires nuits de votre vie.");
Sleep(3000);
  printf("\n[."); Sleep(1000); printf("."); Sleep(1000); printf(".]");
Sleep(3000);
  printf("\n%s", "30 minutes apr\x8As votre arriv\202e, dans ce qui pourrait s'apparenter \x85 une salle d'attente, personne n'est venu vous parler.");
Sleep(4000);
  printf("\n%s\n", "Et le manque de sommeil commence \x85 se faire terriblement ressentir, jusqu'\x85 ce que dernier vienne vous cueillir.");
  SetColor (4);
Sleep(4000);

  printf("\n%s", "- Hey le bleubite, tu te reveilles ?.");
Sleep(2000);
  SetColor (3);
  printf("\n[."); Sleep(1000); printf("."); Sleep(1000); printf(".]");
Sleep(2000);
  SetColor (4);
  printf("\n%s", "- OH bouge toi, j'ai pas toute la journ\202e.");
Sleep(2000);
  SetColor (3);
  printf("\n%s", "- Pardon, j'ai pas reussi \x85 dormir correctement cette nuit \x85 cause du stress.");
Sleep(2500);
  SetColor (4);
  printf("\n%s\n", "- Je m'en fou, l\x8Ave toi et suis moi.");
Sleep(2000);

  SetColor (8);
  printf("\n%s\n", "Vous le suivez jusqu'\x85 un guichet o\x97 un nombre important de documents y est entass\202s.");
Sleep(4000);
  SetColor (4);
  printf("\n%s", "Bon, tu dois s\x96rement savoir tr\x8As peu de choses au sujet du m\202tier que tu va effectuer et c'est normal.");
Sleep(4000);
  printf("\n%s\n", "Au vu de ton profil, et donc de ton ticket, le syst\x8Ame \x85 d\202cid\202 de t'attribuer ce job.");
Sleep(4000);
printf("\n%s", "Petit rappel, au cas o\x97, le TICKET correspond aux donn\202es d'un individu et est inscrit dans un registre international, utilis\202 par de nombreux pays, dont le notre.");
Sleep(6000);
  printf("\n%s", "Sa dur\202e de validit\202 est de 12 mois, et se doit donc d'\x88tre renouveler avant sa date d'invalidit\202, sous peine de santions. ");
Sleep(4000);
  printf("\n%s\n", "Il est \202videmment obligatoire d'apporter des documents pour justifier les informations se trouvant sur le TICKET ou pour y apporter des modifications si n\202cessaire.");
Sleep(5000);
  printf("\n%s", "Et c'est l\x85 que notre m\202tier, celui de Data Keeper, rentre en jeu. Celui de s'assurer de la conformit\202 entre les dires de l'individu et les informations pr\202sentes sur ces documents.");
Sleep(6000);
  printf("\n%s\n", "Il est d'ailleurs obligatoire avant d'effectuer une modification ou un renouvellement de s'assurer que chaque donn\202es pr\202sentent sur le TICKET est un document officiel les confirmant.");
Sleep(6000);
  printf("\n%s", "Cependant, on est beaucoup plus requis pour un autre type de demande, qui pourrait s'apparenter \x85 celui de r\202ptionniste.");
Sleep(4000);
  printf("\n%s", "Notre job pour ce genre de requ\x88te est de s'assurer de la conformit\202 des attentes du client en fonction du TICKET pr\202sent\202.");
Sleep(4500);
  printf("\n%s\n", "Si on prend l'exemple d'une soir\202e priv\202e, l'h\x93te donnera des donn\202es \x85 respecter \x85 la lettre amenant \x85 la d\202cision de faire rentrer ou non l'individu t'ayant pr\202sent\202 son TICKET.");
Sleep(6000);
  printf("\n%s\n", "Bon rien de vaut mieux qu'un exemple concret pour chaque situation et puis, certes y'a beaucoup d'informations \x85 assimiler, mais t'as vraiment l'air compl\x8Atement paum\202...");
  SetColor (4);
Sleep(5000);



  SetColor (3);
  printf("\n\n%s\n", "Exemple Ticket Affichage du cul : ");
  affichageTicket (testTicket);

return 0;
}
