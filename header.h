#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////// BIBLIOTHEQUES ////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <dirent.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// CONSTANTES GLOBALES /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define Ligne 3
#define Colonne 3
#define DIAG_X 34
#define DIAG_Y 14

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// STRUCTURES //////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// ON CREER UNE STRUCTURE "VALISE" QUI COMPORTERA TOUTES LES VARIABLES DONT ON A BESOIN DANS LES DIFFERENTS PROGRAMMES :
typedef struct valise
{
    /// DOUBLE BUFFER :
    BITMAP* double_buffer;
    BITMAP* map_neige;

    ///MUSIQUE :
    SAMPLE* music_1;
    SAMPLE* eau;
    SAMPLE* zap;
    SAMPLE* boiteao;
    SAMPLE* travaux;

    ///ROUTES :
    BITMAP* route;
    BITMAP* route2;
    BITMAP* carrefour;
    BITMAP* virageH;
    BITMAP* virageB;
    BITMAP* virageG;
    BITMAP* virageD;
    BITMAP* route_casse;
    BITMAP* stopH;
    BITMAP* stopB;
    BITMAP* stopG;
    BITMAP* stopD;
    BITMAP* pont;
    int nb_route_casse;
    int nb_routes;

    ///CENTRALES ELECTRIQUES ET HYDROLIQUES :
    BITMAP* case_grise_eau;
    BITMAP* case_grise_elec;
    BITMAP* case_griseClair;
    BITMAP* reseau_eau1;
    BITMAP* reseau_eau2;
    BITMAP* reseau_eau3;
    BITMAP* reseau_elec1;
    BITMAP* reseau_elec2;
    BITMAP* reseau_elec3;
    BITMAP* centraleElec;
    BITMAP* centraleEau;
    BITMAP* bullydingIrrig;
    BITMAP* bullydingLuz;
    BITMAP* source_eau;
    BITMAP* source_elec;
    BITMAP* CDO_1;
    BITMAP* CE_2;
    int nb_centrales_eau;
    int nb_centrales_elec;

    ///BOITE A OUTILS
    BITMAP* bao_ouv;
    BITMAP* bao_fer;
    BITMAP* rond_0;
    BITMAP* rond_1;
    BITMAP* rond_2;
    BITMAP* croute;
    BITMAP* croute2;
    BITMAP* cmaison;
    BITMAP* cmaison2;
    BITMAP* centrale;
    BITMAP* centrale2;
    BITMAP* cwattank;
    BITMAP* cwattank2;
    int etage;
    int outil;
    int ouverture;
    int clic_1;
    int clic_2;
    int clic_3;
    int clic_4;
    int clic_5;
    int clic_6;
    int clic_7;

    /// SELECTIONS :
    BITMAP* curseur;
    BITMAP* bat_okey;
    BITMAP* bat_nope;
    BITMAP* case_okey;
    BITMAP* cancel;
    BITMAP* CE_nope;
    BITMAP* CE_yes;
    BITMAP* CE_cancel;
    BITMAP* CDO_nope;
    BITMAP* CDO_yes;
    BITMAP* CDO_cancel;
    BITMAP* filtre;
    BITMAP* filtre_CDO;
    BITMAP* filtre_CE;

    /// INFORMATIONS :
    BITMAP* info_cabane;
    BITMAP* info_maison;
    BITMAP* info_bullyding;
    BITMAP* info_skyscrapper;
    BITMAP* info_CDO;
    BITMAP* info_CE;
    BITMAP* info_chantier;
    BITMAP* sprite_info_CE;
    BITMAP* sprite_info_CDO;
    BITMAP* sprite_info_sky;
    BITMAP* sprite_info_bullyding;
    BITMAP* sprite_info_maison;
    BITMAP* sprite_info_cabane;
    BITMAP* sprite_info_chantier;

    /// MESSAGES :
    BITMAP* tuto_route;
    BITMAP* message_argent;
    BITMAP* tuto_eau;
    BITMAP* tuto_elec;
    BITMAP* fleche;

    /// BATIMENTS :
    BITMAP* chantier;
    BITMAP* cabane;
    BITMAP* maison;
    BITMAP* bullyding;
    BITMAP* skyscrap;
    BITMAP* grue;
    int nb_bat;
    int safe_impot;

    /// RESSOURCES :
    BITMAP* coins2_vide;
    BITMAP* coins2_middle;
    BITMAP* coins2_pleine;

    BITMAP* reserve_eau_vide;
    BITMAP* reserve_eau_middle;
    BITMAP* reserve_eau_pleine;

    BITMAP* reserve_elec_vide;
    BITMAP* reserve_elec_middle;
    BITMAP* reserve_elec_pleine;

    BITMAP* people;

    /// TIMER :
    int timer;
    int heure;
    int seconde;


    /// POSITIONS ET AFFICHAGE DES CASES :
    int pos_x;
    int pos_y;
    int div;
    int ajout_x;
    int ajout_y;
    int pos_x_centre;
    int pos_y_centre;
    BITMAP* plateforme;

    /// CINEMATIQUES GRAPHIQUES :
    int cinetique;
    BITMAP* cine_1[116];
    char nom_cine_1[50];
    int occu_cine_1;
    BITMAP* fond_menu[373];
    char nom_fm[50];
    int occu_cine_2;

    /// MENU PRINCIPAL :
    BITMAP* titre;
    int choix_menu;
    BITMAP* bouton1;
    BITMAP* bouton2;
    BITMAP* bouton3;
    BITMAP* bouton4;
    BITMAP* bouton5;
    BITMAP* bouton6;
    BITMAP* bouton7;
    BITMAP* bouton8;
    BITMAP* bouton9;

    BITMAP* boutonpause;
    BITMAP* fond;
    BITMAP* pause;
    int lancer;
    int lancer1;
    int lancer2;
    int lancer3;
    int lancer4;
    int lancer5;
    int lancerpause;


    ///FICHIER :
    FILE* fic;

    int ordre;
    int taille;
    int poids;

    int compteur_cases;

    int nb_fichier_gh;

    int extra_graphe;

    int play;
    int play_eau;
    int play_zap;
    int play_bao;
    int play_wo;
    bool etage_info;

    BITMAP* pose;
    BITMAP* r1;
    BITMAP* r2;
    BITMAP* r3;
    BITMAP* r4;
    BITMAP* r5;
    BITMAP* r6;
    BITMAP* r7;
    int rules;
    BITMAP* fleched;
    BITMAP* flecheg;
    int rul1;
    int rul2;
    BITMAP* slide1;
    BITMAP* slide2;
    BITMAP* slide3;
    BITMAP* slide4;
    BITMAP* slide5;
    BITMAP* slide6;
    BITMAP* slide7;
    BITMAP* retour;
    int choixret;
    int tiempo;

} t_valise;

/// STRUCTURE QUI PERMET DE STOCKER LES INFORMATIONS DES DIFFERENTES INFRASTRUCTURES :
typedef struct info
{
    bool centrale_electrique;
    bool chateau_eau;
    bool habitation;
    bool maison;
    bool cabane;
    bool bullyding;
    bool skyscrapper;
    bool irrigue;
    bool chantier;
}t_info;

/// STRUCTURE MAIRIE QUE REPERTORIE LES DIFFERENTS COUT DE PRODUCTION, L'ARGENT DE LA VILLE, ...
typedef struct mairie
{
    long int bully_flouz;
    long int cout_route;
    long int cout_terrainV;
    long int cout_chateau_do;
    long int capacite_CDO;
    long int capa_tot_eau;
    long int capacite_CE;
    long int capa_tot_elec;
    long int cout_centrale;
    long int impots;
    long int nb_habitants;

} t_mairie;

/// STRUCTURE CASE QUI REPERTORIE LE NUM DE LA CASE, SA POSITION, SON TYPE, ...
typedef struct cases
{
    char numero_cases[20];
    int pos_x;
    int pos_y;
    int pos_x_centre;
    int pos_y_centre;
    int type_cases;
    int avancement;
    int numero_ligne;
    int numero_colonne;
    int id;
    int numero_route_graphe;

}t_cases;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// THEORIE DES GRAPHES //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// STRUCTURE ARC, ELLE REPERTORIE LES DIFFERENTES INFOS PROPRE AUX ARRETES :
typedef struct arc
{
    int sommet;
    int valeur;
    int poids;
    struct t_arc* arc_suivant;
} t_arc;

/// STRUCTURE COMMET, ELLE REPERTORIE LES DIFFERENTES INFOS PROPRES AUX SOMMETS :
typedef struct sommet
{
    t_arc* arc;
    int valeur;
    int marquage;
    int predec;
    int dist;
    int degre;
    int id;
    int num;
}t_sommet;

/// STRUCTURE GRAPHE, ELLE REPERTORIE LES DIFFERENTES INFOS PROPRES AUX GRAPHE :

typedef struct Graphe
{
    int taille;
    int ordre;
    t_sommet** pSommet;
} t_graphe;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// PROTOTYPES DE FONCTIONS //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///FONCTIONS D'INITIALISATION :
void init_valise(t_valise* valise);
void init_mairie(t_mairie* mairie);

///FONCTIONS DES GRAPHES :
void afficher_successeurs(t_sommet** sommet, int num);
t_sommet** CreerArete(t_sommet** sommet,int s1,int s2, int poids);
t_graphe* creation_graphe(int ordre);
t_graphe* extraire_graphe();
void afficher_graphe(t_graphe* graphe);
int sommet_all_visited(t_graphe* graphe);
int minimum(t_graphe* graphe);
void dijkstra(t_graphe* graphe, int sommet_init, int sommet_final);

///FONCTIONS D'AFFICHAGES DES DIFFERENTS ELEMENTS DU JEU :
void affichage_curseur(t_valise valise);
//void affichage_plateau(t_valise* valise, t_cases cases[35][45]);
//void affichage_reseau(t_valise* valise, t_cases cases[35][45]);

///JOUER UNE MUSIQUE :
void jouer_music(SAMPLE* sample);
void notre_stop_music(SAMPLE* sample);

///FONCTIONS DES CINEMATIQUES :
void cinematique_1(t_valise* valise);
void cinematique_menu(t_valise* valise);

///FONCTIONS DE CREATIIONS DES INFRASTRUCTURES :
void crea_struct_cases(t_valise valise, t_cases cases[35][45]); ///CREATION DU PLATEAU DE JEU
void creation_routes(t_valise* valise, t_mairie* mairie, t_cases cases[35][45]);
void creation_batiment(t_valise* valise, t_mairie* mairie, t_cases cases[35][45]);
void creation_centraleElec(t_valise* valise, t_mairie* mairie, t_cases cases[35][45]);
void creation_centraleEau(t_valise* valise, t_mairie* mairie, t_cases cases[35][45]);

///FONCTION DE SELECTION DES DIFFERENTS ETAGES, MODES, ... :
void barre_a_outils(t_valise* valise);

///FONCTIONS QUI PERMET DE SAVOIR SUR QUELLE CASES EST NOTRE CURSEUR :
int is_in_case(t_cases cases);

///FONCTION DU MENU PRINCIPAL :
void menu_principale(t_valise* valise);

void reglespause(t_valise* valise);
void evolution_batiment(t_valise valise, t_cases cases[35][45], t_mairie* mairie);
void impots(t_valise* valise, t_mairie* mairie);
void affichage_plateau(t_valise* valise, t_cases cases[35][45]);
void affichage_batiments(t_valise* valise, t_cases cases[35][45]);
void select_info(t_valise* valise, t_cases cases[35][45], t_info* info);
void information(t_valise valise, t_info info);
void affichage_reseau(t_valise* valise, t_cases cases[35][45]);
void affichage_ressources(t_valise* valise, t_mairie* mairie);
void menu_pause(t_valise* valise,t_mairie* mairie, t_cases cases[35][45]);
void regles(t_valise* valise);
void reini();
void reinii(t_mairie* mairie, t_valise* valise);
void compter(t_valise* valise);

#endif // HEADER_H_INCLUDED
