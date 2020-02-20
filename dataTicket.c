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
  char age[50];
  char sexe[15];
  char nationalite[30];
  char religion[30];

};

// Structure lieux
typedef struct TicketBuild ticketBuild_t;
struct TicketBuild
{
  statut_t leStatut;
  char intelligence[50];
  char secteur[50];
  char revenu[50];
  char innocence[50];
  char fidelite[50];
};

/* Degré d’intelligence (celui-ci est renouvelable, si souhaité, auprès de soi-disant spécialistes)
Statut social (âge, célibataire/couple, sexe, lieu et type d’habitation, nationalité, religion)
Secteur du travail (ce dernier se verra classer approfondissant encore plus les disparités)
Revenu mensuelle (sera affiche sous sa forme NET)
Degré d’innocence (le casier judiciaire et les actions de l’individu impacteront ce point)
Année Fidélité (depuis combien de temps la personne a obtenu son premier Data Ticket) */

int affichageTicket (ticketBuild_t ticket) {
  SetColor(15);
	printf ("\n%s\n", "--------------------------------");
  SetColor(6);
	printf ("|Pr\202nom       : %s\n", ticket.leStatut.prenom);
	printf ("|Age          : %s\n", ticket.leStatut.age);
	printf ("|S\x88xe         : %s\n", ticket.leStatut.sexe);
	printf ("|Nationalit\202  : %s\n", ticket.leStatut.nationalite);
	printf ("|Religion     : %s\n", ticket.leStatut.religion);
	printf ("|Intelligence : %s\n", ticket.intelligence);
	printf ("|Secteur      : %s\n", ticket.secteur);
	printf ("|Revenu       : %s\n", ticket.revenu);
	printf ("|Innocence    : %s\n", ticket.innocence);
	printf ("|Fid\202lit\202     : %s\n", ticket.fidelite);
	SetColor(15);
	printf ("%s\n", "--------------------------------");
};

// Le #coffre toujours là
int coffre;
char coffreTexte[30];
int tuto = 0;
int jeu = 0;
int compteur = 0;

int main (){


char prenomList[51][100] = {"/0", "Eddy", "Charlotte", "Lilian", "Luc", "Paul", "Lucas", "Hugo", "Sabine", "Mathieu", "Alexia", "Enora", "Axel", "Guillaume", "Alice", "Paul",
"In\x8As", "Th\202o", "Marie", "Zo\202", "Ath\202na\x8Bs", "Ugo", "K\202vin", "Coline", "Joseph", "Margaux", "M\202lody", "Antoine", "No\202mie", "Pauline", "Tom", "Anais", "Arthur",
"Charlotte", "Anna", "Diego", "Gabin", "Claire", "Benjamin", "Luka", "Aurore", "Melvin", "Charlie", "Timoth\202e", "Mona","Henri", "Blandine", "Romuald", "Leon", "Irina", "Juliette"};

char ageList[69][100] = {"0", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37",
"38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66",
"67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81"};

char sexeList[8][100] = {"/0", "Homme", "Homme", "Homme", "Femme", "Femme", "Femme", "Autres"};

char nationList[38][100] = {"/0", "Fran\207ais", "Allemand", "Espagnol", "Suisse", "Anglais", "Belge", "Portugais", "Ecossais", "Irlandais", "Islandais", "Italien", "Hollandais",
 "Autrichien", "Polonais", "Roumain", "Am\202ricain", "Canadien", "Mexicain", "Colombien", "Br\202silien", "Argentin", "Ukrainien", "Russe", "Norv\202gien", "Su\202dois", "Finlandais",
"Chinois", "Japonais", "Cor\202en", "Indien", "Australien", "N\202o-Z\202landais", "Alg\202rien", "Turc", "Libanais", "Egyptien", "Nig\202rian"};

char religionList[7][100] = {"/0", "Ath\202e", "Christianisme ", "Juda\x8Bsme", "Islam", "Bouddhisme", "Hindouisme"};

char intelList[78][100] = {"0", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94",
"95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
"121", "122", "123", "124", "125", "126", "127", "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140", "145", "150", "155", "160", "165", "170"};

char secteurList[25][100] = {"Data Keeper", "Agriculture", "Architecture", "Arm\202e", "S\202curit\202", "Arts", "Artisanat", "Banque", "Audiovisuel", "Communication",
"B\x83timent", "Droit", "Economie", "Enseignement", "Recherche", "Transport", "Logistique", "H\x93tellerie", "Restauration", "Tourisme", "Industrie", "Informatique",
"Sant\202", "Sport", "Social"};

char revenuList[63][100] = {"0", "8000", "8500", "9000", "9500", "10 000", "10 500", "11 000", "11 500", "12 000", "12 500", "13 000", "13 500", "14 000", "14 500", "15 000",
"16 000", "17 000", "18 000", "19 000",  "20 000", "22 000", "24 000", "26 000", "28 000", "30 000", "32 000", "34 000", "36 000", "38 000", "40 000", "42 000", "44 000", "46 000",
"48 000", "50 000", "60 000", "70 000", "80 000", "90 000", "100 000", "120 000", "140 000", "160 000", "180 000", "200 000", "300 000", "400 000", "500 000", "600 000", "700 000",
"800 000", "900 000", "1 000 000", "2 000 000", "3 000 000", "4 000 000", "5 000 000", "6 000 000", "7 000 000", "8 000 000", "9 000 000", "10 000 000"};

char innocenceList[7][100] = {"0", "0", "1", "2", "3", "4", "5"};

char fidelList[27][100] = {"0", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"};

// NOM DU MONDE
  printf("\n%s\n", "                            ______________________________");
  printf("%s\n", "                           |                              |");
  printf("%s\n", "                           |          DATA TICKET         |");
  printf("%s\n\n", "                           |______________________________|");



/*  coffre = (rand() % (50 - 1 + 1)) + 1;
strcpy(ticket.leStatut.prenom, prenomList[coffre]);
  coffre = (rand() % (68 - 1 + 1)) + 1;
strcpy(ticket.leStatut.age, ageList[coffre]);
  coffre = (rand() % (7 - 1 + 1)) + 1;
strcpy(ticket.leStatut.sexe, sexeList[coffre]);
  coffre = (rand() % (37 - 1 + 1)) + 1;
strcpy(ticket.leStatut.nationalite, nationList[coffre]);
  coffre = (rand() % (6 - 1 + 1)) + 1;
strcpy(ticket.leStatut.religion, religionList[coffre]);
  coffre = (rand() % (77 - 1 + 1)) + 1;
strcpy(ticket.intelligence, intelList[coffre]);
  coffre = (rand() % (24 - 1 + 1)) + 1;
strcpy(ticket.secteur, secteurList[coffre]);
  coffre = (rand() % (62 - 1 + 1)) + 1;
strcpy(ticket.revenu, revenuList[coffre]);
  coffre = (rand() % (6 - 1 + 1)) + 1;
strcpy(ticket.innocence, innocenceList[coffre]);
  coffre = (rand() % (26 - 1 + 1)) + 1;
strcpy(ticket.fidelite, fidelList[coffre]);
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
  printf("\n%s\n", "- Tiens, prends le et regarde le bien, on va commencer la mise en sc\x8Ane.");
Sleep(3000);
  ticketBuild_t ticket = {"Luc", "52", "Homme", "Francais", "Ath\202e", "112", "Banque", "12 000", "0", "9"};
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


return 0;
}
