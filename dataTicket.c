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

/* Degré d’intelligence (celui-ci est renouvelable, si souhaité, auprès de soi-disant spécialistes)
Statut social (âge, célibataire/couple, sexe, lieu et type d’habitation, nationalité, religion)
Secteur du travail (ce dernier se verra classer approfondissant encore plus les disparités)
Revenu mensuelle (sera affiche sous sa forme NET)
Degré d’innocence (le casier judiciaire et les actions de l’individu impacteront ce point)
Année Fidélité (depuis combien de temps la personne a obtenu son premier Data Ticket) */

// Structure Statut
typedef struct Statut statut_t;
struct Statut
{
  char prenom[30];
  int age;
  char sexe[15];
  char nationalite[30];
  char religion[30];

};

// Structure TICKET
typedef struct TicketBuild ticketBuild_t;
struct TicketBuild
{
  statut_t leStatut;
  int intelligence;
  char secteur[50];
  int revenu;
  int innocence;
  int fidelite;
};





char prenomList[51][100] = {"/0", "Eddy", "Charlotte", "Lilian", "Luc", "Paul", "Lucas", "Hugo", "Sabine", "Mathieu", "Alexia", "Enora", "Axel", "Guillaume", "Alice", "Paul",
"In\x8As", "Th\202o", "Marie", "Zo\202", "Ath\202na\x8Bs", "Ugo", "K\202vin", "Coline", "Joseph", "Margaux", "M\202lody", "Antoine", "No\202mie", "Pauline", "Tom", "Anais", "Arthur",
"Charlotte", "Anna", "Diego", "Gabin", "Claire", "Benjamin", "Luka", "Aurore", "Melvin", "Charlie", "Timoth\202e", "Mona","Henri", "Blandine", "Romuald", "Leon", "Irina", "Juliette"};

int ageList[69] = {0, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81};

char sexeList[8][100] = {"/0", "Homme", "Homme", "Homme", "Femme", "Femme", "Femme", "Autres"};

char nationList[38][100] = {"/0", "Fran\207ais", "Allemand", "Espagnol", "Suisse", "Anglais", "Belge", "Portugais", "Ecossais", "Irlandais", "Islandais", "Italien", "Hollandais",
 "Autrichien", "Polonais", "Roumain", "Am\202ricain", "Canadien", "Mexicain", "Colombien", "Br\202silien", "Argentin", "Ukrainien", "Russe", "Norv\202gien", "Su\202dois", "Finlandais",
"Chinois", "Japonais", "Cor\202en", "Indien", "Australien", "N\202o-Z\202landais", "Alg\202rien", "Turc", "Libanais", "Egyptien", "Nig\202rian"};

char religionList[7][100] = {"/0", "Ath\202e", "Christianisme ", "Juda\x8Bsme", "Islam", "Bouddhisme", "Hindouisme"};

int intelList[78] = {0, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104,
105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
140, 145, 150, 155, 160, 165, 170};

char secteurList[25][100] = {"Data Keeper", "Agriculture", "Architecture", "Arm\202e", "S\202curit\202", "Arts", "Artisanat", "Banque", "Audiovisuel", "Communication",
"B\x83timent", "Droit", "Economie", "Enseignement", "Recherche", "Transport", "Logistique", "H\x93tellerie", "Restauration", "Tourisme", "Industrie", "Informatique",
"Sant\202", "Sport", "Social"};

int revenuList[63] = {0, 8000, 8500, 9000, 9500, 10000, 10500, 11000, 11500, 12000, 12500, 13000, 13500, 14000, 14500, 15000, 16000, 17000, 18000, 19000, 20000,
22000, 24000, 26000, 28000, 30000, 32000, 34000, 36000, 38000, 40000, 42000, 44000, 46000, 48000, 50000, 60000, 70000, 80000, 90000, 100000, 120000, 140000, 160000,
180000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000, 2000000, 3000000, 4000000, 5000000, 7000000, 8000000, 9000000, 10000000};

int innocenceList[7] = {0, 0, 1, 2, 3, 4, 5};

int fidelList[27] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

ticketBuild_t ticket = {"Luc", 52, "Homme", "Francais", "Ath\202e", 112, "Banque", 12000, 0, 9};

int affichageTicket (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(6);
	printf ("|Pr\202nom       : %s\n", ticket.leStatut.prenom);
	printf ("|Age          : %d\n", ticket.leStatut.age);
	printf ("|Sexe         : %s\n", ticket.leStatut.sexe);
	printf ("|Nationalit\202  : %s\n", ticket.leStatut.nationalite);
	printf ("|Religion     : %s\n", ticket.leStatut.religion);
	printf ("|Intelligence : %d\n", ticket.intelligence);
	printf ("|Secteur      : %s\n", ticket.secteur);
	printf ("|Revenu       : %d\n", ticket.revenu);
	printf ("|Innocence    : %d\n", ticket.innocence);
	printf ("|Fid\202lit\202     : %d\n", ticket.fidelite);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

int justificatifStatut (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(14);
	printf ("°° Pr\202nom       : %s\n", ticket.leStatut.prenom);
	printf ("°° Age          : %d\n", ticket.leStatut.age);
	printf ("°° Sexe         : %s\n", ticket.leStatut.sexe);
	printf ("°° Nationalit\202  : %s\n", ticket.leStatut.nationalite);
	printf ("°° Religion     : %s\n", ticket.leStatut.religion);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

int justificatifIntel (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(14);
	printf ("@@ Intelligence : %d\n", ticket.intelligence);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

int justificatifTamponEco (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(14);
  printf ("$$ Secteur      : %s\n", ticket.secteur);
	printf ("$$ Revenu       : %d\n", ticket.revenu);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

int justificatifTamponJuridique (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(14);
  printf ("## Innocence    : %d\n", ticket.innocence);
	printf ("## Fid\202lit\202     : %d\n", ticket.fidelite);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

ticketBuild_t generationTicket(ticketBuild_t ticket, int coffre) {
  coffre = (rand() % (50 - 1 + 1)) + 1;
  strcpy(ticket.leStatut.prenom, prenomList[coffre]);

    coffre = (rand() % (68 - 1 + 1)) + 1;
  ticket.leStatut.age = ageList[coffre];

    coffre = (rand() % (7 - 1 + 1)) + 1;
  strcpy(ticket.leStatut.sexe, sexeList[coffre]);

    coffre = (rand() % (37 - 1 + 1)) + 1;
  strcpy(ticket.leStatut.nationalite, nationList[coffre]);

    coffre = (rand() % (6 - 1 + 1)) + 1;
  strcpy(ticket.leStatut.religion, religionList[coffre]);

    coffre = (rand() % (77 - 1 + 1)) + 1;
  ticket.intelligence = intelList[coffre];

    coffre = (rand() % (24 - 1 + 1)) + 1;
  strcpy(ticket.secteur, secteurList[coffre]);

    coffre = (rand() % (62 - 1 + 1)) + 1;
  ticket.revenu = revenuList[coffre];

    coffre = (rand() % (6 - 1 + 1)) + 1;
  ticket.innocence = innocenceList[coffre];

    coffre = (rand() % (26 - 1 + 1)) + 1;
  ticket.fidelite = fidelList[coffre];

  affichageTicket (ticket);
  return ticket;
}



/* LIGNE POUR LA GÉNÉRATION DES TICKETS
 ticket = generationTicket (ticket, coffre); */

// Le #coffre toujours là
int coffre;
int tuto = 0;
int jeu = 0;
int points = 0;

int compteur = 0;
int faute = 0;
int ticketFait = 0;
int tm_sec;

int main (){

// Pour le timer
time_t rawtime;
struct tm*  time_;

// NOM DE L'HISTOIRE
  printf("\n%s\n", "                            ______________________________");
  printf("%s\n", "                           |                              |");
  printf("%s\n", "                           |          DATA TICKET         |");
  printf("%s\n\n", "                           |______________________________|");





// MENU SIMPLE
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

// TUTO OU NON
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


// LE TUTORIEL + INTRODUCTION À L'HISTOIRE
if (tuto == 0) {

printf("\n%s\n", "                            ______________________________________");
printf("%s\n", "                           |                                      |");
printf("%s\n", "                           |       CHAPITRE 0 : DATA KEEPER       |");
printf("%s\n\n", "                           |______________________________________|");

Sleep(1000);
SetColor (8);
  printf("\n%s", "Vous \x88tes enfin arriv\x82 \x85 votre lieu de travail pour votre premiere journ\202e d'apprentissage. [25 F\202vrier 2045]");
Sleep(4000);
  printf("\n%s", "Vous \x88tes extr\x8Amement stress\x82, et cela depuis hier soir, vous ayant fait passer l'une des pires nuits de votre vie.");
Sleep(3000);
  printf("\n[."); Sleep(1000); printf("."); Sleep(1000); printf(".]");
Sleep(3000);
  printf("\n%s", "30 minutes apr\x8As votre arriv\202e, dans ce qui pourrait s'apparenter \x85 une salle d'attente, personne n'est venu vous parler.");
Sleep(4000);
  printf("\n%s\n", "Et le manque de sommeil commence \x85 se faire terriblement ressentir, jusqu'\x85 ce que dernier vienne vous cueillir.");
Sleep(4000);

SetColor (12);
  printf("\n%s", "- Hey le bleubite, tu te reveilles ?.");
Sleep(2000);
SetColor (3);
  printf("\n[."); Sleep(1000); printf("."); Sleep(1000); printf(".]");
Sleep(2000);
SetColor (12);
  printf("\n%s", "- OH bouge toi, j'ai pas toute la journ\202e.");
Sleep(2000);
SetColor (3);
  printf("\n%s", "- Pardon, j'ai pas reussi \x85 dormir correctement cette nuit \x85 cause du stress.");
Sleep(2500);
SetColor (12);
  printf("\n%s\n", "- Je m'en fou, l\x8Ave toi et suis moi.");
Sleep(2000);

SetColor (8);
  printf("\n%s\n", "Vous le suivez jusqu'\x85 un guichet o\x97 un nombre important de documents y est entass\202s.");
Sleep(4000);
SetColor (12);
  printf("\n%s", "- Bon, tu dois s\x96rement savoir tr\x8As peu de choses au sujet du m\202tier que tu va effectuer et c'est normal.");
Sleep(4000);
  printf("\n%s\n", "- Au vu de ton profil, et donc de ton ticket, le syst\x8Ame \x85 d\202cid\202 de t'attribuer ce job.");
Sleep(4000);
printf("\n%s", "- Petit rappel, au cas o\x97, le TICKET correspond aux donn\202es d'un individu et y est inscrit dans un registre international, utilis\202 par de nombreux pays, dont le notre.");
Sleep(6000);
  printf("\n%s", "- Sa dur\202e de validit\202 est de 12 mois, et se doit donc d'\x88tre renouveler avant sa date d'invalidit\202, sous peine de sanctions. ");
Sleep(4000);
  printf("\n%s\n", "- Il est \202videmment obligatoire d'apporter des documents pour justifier les informations se trouvant sur le TICKET ou pour y apporter des modifications si n\202cessaire.");
Sleep(5000);
  printf("\n%s", "- Et c'est l\x85 que notre m\202tier, celui de Data Keeper, rentre en jeu. Celui de s'assurer de la conformit\202 entre les dires de l'individu et les informations pr\202sentes sur ces documents.");
Sleep(6000);
  printf("\n%s\n", "- Il est d'ailleurs obligatoire avant d'effectuer une modification ou un renouvellement de s'assurer que chaque donn\202es pr\202sentent sur le TICKET est un document officiel les confirmant.");
Sleep(6000);
  printf("\n%s", "- Cependant, on est beaucoup plus requis pour un autre type de demande, qui pourrait s'apparenter \x85 celui de r\202ceptionniste.");
Sleep(4000);
  printf("\n%s", "- Notre job pour ce genre de requ\x88te est de s'assurer de la conformit\202 des attentes du client en fonction du TICKET pr\202sent\202.");
Sleep(4500);
  printf("\n%s\n", "- Si on prend l'exemple d'une soir\202e priv\202e, l'h\x93te donnera des donn\202es \x85 respecter \x85 la lettre amenant \x85 la d\202cision de faire rentrer ou non l'individu t'ayant pr\202sent\202 son TICKET.");
Sleep(6000);
  printf("\n%s\n", "- Bon rien de vaut mieux qu'un exemple concret pour chaque situation et puis, certes y'a beaucoup d'informations \x85 assimiler, mais t'as vraiment l'air compl\x8Atement paum\202...");
SetColor (4);
Sleep(10000);

SetColor (15);
  printf ("\n%s\n\n", "--------------------------------");

SetColor (8);
  printf("\n%s\n", "Il commence \x85 fouiller dans le tas de papiers sur le guichet avant de sortir un TICKET num\202rique d'une personne inconnu");
Sleep(4000);
SetColor (12);
  printf("\n%s\n", "- Tiens, prends le et regarde le bien.");
Sleep(3000);
//  ticket = {"Luc", "52", "Homme", "Francais", "Ath\202e", "112", "Banque", "12 000", "0", "9"};
  affichageTicket (ticket);
Sleep(10000);

SetColor (12);
  printf("\n%s\n", "- Bon comme tu peux le voir, plusieurs donn\202es sont recens\202s sur celui-ci.");
Sleep(3000);
  printf("%s\n", "- Je pense pas que ce soit n\202cessaire de s'attarder sur le pr\202nom, l'\x83ge, le sexe, la nationalit\202 ou encore la religion.");
Sleep(4000);
  printf("%s\n", "- Juste que ces derniers devront \x88tre confirm\202 \x85 l'aide d'une pi\212ce d'identit\202e.");
Sleep(3000);
  printf("\n%s\n", "- En ce qui concerne l'intelligence, elle est exprim\202e en QI (Quotient Intellectuel) et devra \x88tre justifier par un test officiel.");
Sleep(4000);
  printf("\n%s\n", "- Pour le secteur, qui porte sur le travail de l'individu, et son revenu annuel, ces deux aspects devront \x88tre confirm\202 par un TAMPON \202conomie.");
Sleep(4000);
  printf("\n%s\n", "- On a ensuite l'innocence qui se jauge de 0 \x85 5, 0 signifiant que l'humain est consid\202r\202 comme PURE et 5 comme ABJECTE. Cette derni\x8Are est jaug\202 en fonction des fautes qu'il a commise.");
Sleep(6000);
  printf("%s\n", "- Pour terminer, la fid\202lit\202 correspond au nombre d'ann\202es qu'une personne a maintenu \x85 jour son TICKET. Que ce soit l'innocence ou la fid\202lit\202, ces deux infos sont v\202rifi\202s par un TAMPON juridique.");
Sleep(6000);
  printf("%s\n", "- Maintenant que tu as les bases, on va faire un essai. Disons que tu as \202t\202 r\202quisitionn\202 pour une soir\202e et l'h\223 de celle-ci te demande de ne pas faire entrer les individus provenant de Chine");
Sleep(7000);
SetColor (3);
  printf("\n%s\n", "- Mais attends, c'est d\202gueulasse, pourquoi tu prends cet exemple ?");
Sleep(3000);
SetColor (12);
  printf("\n%s\n", "- Alors de 1, ce genre de cas arrivera plus souvent que tu ne le penses.");
Sleep(3000);
  printf("%s\n", "- Et de 2, je te forme pas et ils te payeront pas pour imposer ta vision des choses dans notre m\202tier.");
Sleep(3000);
  printf("%s\n", "- Si tu veux pas respecter les directives de ton employeur le temps venu, c'est toi qui d\202cide, mais soit pr\210t \x85 en subir les cons\202quences.");
Sleep(5000);
  printf("%s\n", "- Une fois vir\202 tu sais bien qu'il est impossible de retrouver du travail, du moins un travail te permettant de subvenir correctement \x85 tes besoins. Donc ferme l\x85 et on commence.");
Sleep(8000);


// MISE EN PRATIQUE DES MÉCANIQUES
// MISE EN PRATIQUE DES MÉCANIQUES
SetColor (15);
  printf ("\n%s\n", "--------------------------------");
  printf("\n%s\n", "D\202but mise en pratique");
  printf ("\n%s\n\n", "--------------------------------");
Sleep(3000);

SetColor (3);
printf("\n%s\n", "- Bonjour, Data Ticket s'il vous pla\x8Ct.");
Sleep(2000);
SetColor (12);
printf("\n%s\n", "- Tenez.");
Sleep(1000);

  affichageTicket (ticket);

Sleep(5000);
SetColor (3);
  printf("\n%s\n", "- [0] Vous pouvez entrer. ; [1] Vous ne pouvez pas entrer, d\202sol\202.");
Sleep(2000);
SetColor (15);
  printf("Votre choix : ");
SetColor (3);
  scanf("%d", &coffre);

if (coffre == 0 && strcmp(ticket.leStatut.nationalite, nationList[27]) != 0) {
SetColor (12);
  printf("\n%s\n", "- Ok bonne r\202ponse, esp\202rons que t'es pas d\202cid\202 au hasard. On va essayer avec un autre Ticket");
Sleep(2000);
} else if (coffre == 0 && strcmp(ticket.leStatut.nationalite, nationList[27]) == 0) {
  SetColor (12);
    printf("\n%s\n", "- Mais non, regarde bien, il est Chinois, il peut pas rentrer. Fait un effort quand m\210me... Bon on fait un deuxi\212me essai.");
  Sleep(2000);
} else if (coffre == 1 && strcmp(ticket.leStatut.nationalite, nationList[27]) == 0) {
  SetColor (12);
    printf("\n%s\n", "- Ok bonne r\202ponse, esp\202rons que t'es pas d\202cid\202 au hasard. On va essayer avec un autre Ticket");
  Sleep (2000);
} else if (coffre == 1 && strcmp(ticket.leStatut.nationalite, nationList[27]) != 0) {
  SetColor (12);
    printf("\n%s\n", "- Mais non, regarde bien, il est pas Chinois, il peut rentrer. Fait un effort quand m\210me... Bon on fait un deuxi\212me essai.");
  Sleep(2000);
}
Sleep(5000);

// TICKET généré pour le tuto spécialement
strcpy(ticket.leStatut.prenom, "Mana");
ticket.leStatut.age = 24;
strcpy(ticket.leStatut.sexe, "Femme");
strcpy(ticket.leStatut.nationalite, nationList[27]);
strcpy(ticket.leStatut.religion, religionList[2]);
ticket.intelligence = 126;
strcpy(ticket.secteur, secteurList[13]);
ticket.revenu = 17000;
ticket.innocence = 1;
ticket.fidelite = 4;
  affichageTicket (ticket);

Sleep(5000);
SetColor (3);
  printf("\n%s\n", "- Vous pouvez entrer. [0] ; Vous ne pouvez pas entrer, d\202sol\202. [1]");
Sleep(2000);
SetColor (15);
  printf("Votre choix : ");
SetColor (3);
  scanf("%d", &coffre);

if (coffre == 0 && strcmp(ticket.leStatut.nationalite, nationList[27]) != 0) {
SetColor (12);
  printf("\n%s\n", "- Ok parfait je pense t'as compris les bases.");
Sleep(2000);
} else if (coffre == 0 && strcmp(ticket.leStatut.nationalite, nationList[27]) == 0) {
  SetColor (12);
    printf("\n%s\n", "- Mais non, regarde bien, y'a marqu\202 Chinois, elle peut pas rentrer...");
  Sleep(2000);
} else if (coffre == 1 && strcmp(ticket.leStatut.nationalite, nationList[27]) == 0) {
  SetColor (12);
    printf("\n%s\n", "- Ok parfait je pense t'as compris les bases.");
  Sleep(2000);
} else if (coffre == 1 && strcmp(ticket.leStatut.nationalite, nationList[27]) != 0) {
  SetColor (12);
    printf("\n%s\n", "- Bon j'esp\212re pour toi que tu comprendras mieux lorsque se sera r\202el...");
  Sleep(2000);
}

SetColor (12);
  printf("\n%s\n", "- Bon le temps qui m'\202tait accord\202 pour te former est quasi termin\202. Donc avant de partir voil\x85 \x85 quoi ressemble les diff\202rents justificatifs : ");
Sleep(5000);
SetColor (12);
  printf("\n%s\n", "- Le Justificatif pour le pr\202nom, l'\x83ge, le sexe, la nationalit\202 et la religion (Pi\212ce d'identit\202) : ");
  justificatifStatut (ticket);
Sleep(5000);
SetColor (12);
  printf("\n%s\n", "- Le Justificatif pour l'intelligence (TEST officiel) : ");
  justificatifIntel (ticket);
Sleep(5000);
SetColor (12);
  printf("\n%s\n", "- Le Justificatif pour le Revenu et le secteur du travail (TAMPON \202conomique) : ");
  justificatifTamponEco (ticket);
Sleep(5000);
SetColor (12);
  printf("\n%s\n", "- Le Justificatif pour l'innocence et la fid\202lit\202 (TAMPON juridique) : ");
  justificatifTamponJuridique (ticket);
Sleep(5000);
SetColor (12);
  printf("\n%s\n", "- Ah et derni\212re chose, sache que tu es pay\202 \x85 la journ\202e et en fonction du nombre de TICKETS effectu\202s.");
Sleep(4000);
  printf("%s\n", "- Et il est \202vident que si tu commets des fautes, elles impacteront ton salaire pouvant aller jusqu'au licenciement si tu n'arr\210tes pas d'en faire.");
Sleep(5000);
  printf("%s\n", "- Bon il est l'heure, si tu as des questions pas le temps d'y r\202pondre, donc tu verras \207a sur le terrain. Allez bonne journ\202e");
Sleep(5000);

SetColor (15);
  printf ("\n%s\n", "--------------------------------");
  printf("\n%s\n", "  FIN CHAPITRE 0 : DATA KEEPER ");
  printf ("\n%s\n\n", "--------------------------------");
Sleep(3000);

system("cls");
}

// DÉBUT CHAPITRE 1
SetColor (15);
printf("\n%s\n", "                            ______________________________________");
printf("%s\n", "                           |                                      |");
printf("%s\n", "                           |         CHAPITRE 1 : VOISINAGE       |");
printf("%s\n\n", "                           |______________________________________|");


Sleep(1000);
SetColor (8);
  printf("\n%s", "[26 F\202vrier 2045] C'est votre premi\212re r\202el journ\202e de travail. Vous arrivez \x85 votre bureau de travail attitr\202 et vous le d\202couvrer aussi pour la premi\212re fois. ");
Sleep(5000);
  printf("\n%s", "Vous remarquez que dans une urne situ\202e en plein millieu de votre bureau, se trouve une enveloppe. Le contenu de celle-ci indique que vous avez \202t\202 r\202quisitionn\202 pour un \202v\212nement communautaire.");
Sleep(6000);
  printf("\n%s", "L'adresse du lieu y est indiqu\202 ainsi que la dur\202e de ce dernier (19H - 1h00). Situ\202 dans un quartier bourgeois, vous pressentez le genre de pr\202requis injuste que fera l'organisateur...");
Sleep(5000);
  printf("\n%s\n", "Vous installez vos affaires, vous vous renseignez un maximum sur le m\202tier de Data Keeper, votre m\202tier, avant de partir en direction de l'\202v\212nement...");
Sleep(5000);

SetColor(15);
printf ("\n%s\n", "--------------------------------");

Sleep(1000);
SetColor (8);
  printf("\n%s\n", "Arriv\202 \x85 destination, ce qui semble \210tre l'organisateur se dirige vers vous.");
Sleep(3000);
SetColor (7);
  printf("\n%s", "- Bonjour, au vu de votre accoutrement, vous devez certainement \210tre le Data Keeper que j'ai employ\202.");
Sleep(4000);
SetColor (3);
  printf("\n%s", "- En effet, c'est bien moi.");
Sleep(2000);
SetColor (7);
  printf("\n%s", "- Parfait, vous irez vous installez au devant de cette propri\202t\202 juste apr\212s notre conversation, puisque c'est dans cette derni\212re que va se d\202rouler la soir\212e d'ici 15 minutes.");
Sleep(8000);
  printf("\n%s", "- En ce qui concerne votre devoir, vous ne devez en aucun cas faire entrer un individu ayant un revenu inf\202rieur \x85 80 000 ainsi qu'un degr\202 d'innocence sup\202rieur \x85 2.");
Sleep(7000);
  printf("\n%s\n", "- Manquerait plus que des gueux ou des malfrats viennent se m\202ler au sein de notre communaut\202. **Vous lance un regard hautain** Sans vous manquez de respect.");
Sleep(6000);
SetColor (8);
  printf("\n%s", "Bien que travailler pour ce genre de personne vous donne l'envie de vomir, il faut bien d'une certaine mani\212re gagner sa vie...");
Sleep(4000);
  printf("\n[."); Sleep(1000); printf("."); Sleep(1000); printf(".]");
SetColor (8);
  printf("\n%s\n", "Il est 19H et les premiers potentiels int\202ress\202s commencent \x85 arriver.");
Sleep(10000);


// MISE EN PLACE TIMER
time(&rawtime);
time_ = localtime(&rawtime);

compteur = time_->tm_min;
if (compteur == 56) {
  compteur == -4;
} else if (compteur == 57) {
  compteur == -3;
} else if (compteur == 58) {
  compteur == -2;
} else if (compteur == 59) {
  compteur == -1;
}

while (compteur+4 != time_->tm_min){
system("cls");
SetColor(15);
  printf ("\n%s\n", "--------------------------------");
  printf("\n%s\n", "        TRAVAIL EN COURS ");
  printf("~ Ticket Effectu\202s : %d \n", ticketFait);
  printf("~ Fautes : %d \n", faute);
  printf ("\n%s\n\n", "--------------------------------");

SetColor (3);
  printf("\n%s\n", "- Bonsoir, Data Ticket s'il vous pla\x8Ct.");
Sleep(2000);
SetColor (7);
  printf("\n%s\n", "- Tenez.");
Sleep(1000);

ticket = generationTicket (ticket, coffre);

SetColor (3);
  printf("\n%s\n", "- [0] Vous pouvez entrer. ; [1] Vous ne pouvez pas entrer, d\202sol\202.");
Sleep(1000);
SetColor (15);
  printf("Votre choix : ");
SetColor (3);
  scanf("%d", &coffre);

if (coffre == 0 && ticket.revenu >= 80000 && ticket.innocence <= 2) {
SetColor (7);
  ticketFait++;
  compteur++;
  printf("\n%s\n", "- Merci, bonne soir\202e.");
Sleep(2000);
} else if (coffre == 0) {
SetColor (7);
  ticketFait++;
  faute++;
  compteur++;
  printf("\n%s\n", "- Merci beaucoup, merci, passez une bonne soir\202e.");
Sleep(2000);
}
if (coffre == 1 && ticket.innocence > 2 || coffre == 1 && ticket.revenu < 80000) {
SetColor (7);
  ticketFait++;
  compteur++;
  printf("\n%s\n", "- Vous pourriez au moins faire quelques exceptions...");
Sleep(2000);
} else if (coffre == 1) {
SetColor (7);
  ticketFait++;
  faute++;
  compteur++;
  printf("\n%s\n", "- Comment \207a !? Allez, encore quelqu'un incapable de faire correctement son travail.");
Sleep(2000);
}
time(&rawtime);
time_ = localtime(&rawtime);
}

SetColor (15);
  printf("\n%s\n", "Temps \220coul\202.");

return 0;
}
