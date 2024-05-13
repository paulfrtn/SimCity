#include "header.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////// INITIALISATIONS //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// SOUS PROGRAMME D'INITIALISATION DE TOUTES LES VARIABLE QUE L'ON TRANSPORTE DANS NOTRE "VALISE" :
void init_valise(t_valise* valise)
{
/// ---------------------------------- UPLOAD DES DIFFERENTES BITMAPS/MUSIQUES/FICHIERS NECESSAIRE AU GRAPHISME DE BULLY-CITY ----------------------------------

    /// CREATION DU DOUBLE BUFFER :
    valise->double_buffer = create_bitmap(SCREEN_W,SCREEN_H);
    valise->map_neige = load_bitmap("../images/map/map.bmp", NULL);

    /// UPLOAD DE LA MUSIQUE :
    valise->music_1= load_wav("../musique/newyork1.wav");
    valise->eau= load_wav("../musique/eau.wav");
    valise->zap= load_wav("../musique/zap.wav");
    valise->travaux= load_wav("../musique/travaux.wav");
    valise->boiteao= load_wav("../musique/bao.wav");

    /// UPLOAD DU FICHIER CONTENANT LA MAP DE BASE :
    valise->fic = valise->fic = fopen("../fichiers_texte/map1.txt", "r");

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES ROUTES :
    valise->route = load_bitmap("../images/constructions/routes/route.bmp", NULL);
    valise->route2 = load_bitmap("../images/constructions/routes/route2.bmp", NULL);
    valise->carrefour = load_bitmap("../images/constructions/routes/carrefour.bmp", NULL);
    valise->virageB = load_bitmap("../images/constructions/routes/virage_bas.bmp", NULL);
    valise->virageH = load_bitmap("../images/constructions/routes/virage_haut.bmp", NULL);
    valise->virageG = load_bitmap("../images/constructions/routes/virage_gauche.bmp", NULL);
    valise->virageD = load_bitmap("../images/constructions/routes/virage_droite.bmp", NULL);
    valise->route_casse = load_bitmap("../images/constructions/routes/route_casse.bmp", NULL);
    valise->stopB = load_bitmap("../images/constructions/routes/stop_bas.bmp", NULL);
    valise->stopH = load_bitmap("../images/constructions/routes/stop_haut.bmp", NULL);
    valise->stopG = load_bitmap("../images/constructions/routes/stop_gauche.bmp", NULL);
    valise->stopD = load_bitmap("../images/constructions/routes/stop_droite.bmp", NULL);
    valise->pont = load_bitmap("../images/constructions/routes/pont.bmp", NULL);

    /// DIFFERENTS SPRITES DE SLECTION (EX: CASE VERTE SI L'EMPLACEMENT EST POSSIBLE ET ROUGE SINON) :
    valise->curseur = load_bitmap("../images/objets/curseur.bmp", NULL);
    valise->bat_okey = load_bitmap("../images/map/cases_verte.bmp", NULL);
    valise->bat_nope = load_bitmap("../images/map/bat_nope.bmp", NULL);
    valise->cancel = load_bitmap("../images/map/cancel.bmp", NULL);
    valise->case_okey = load_bitmap("../images/constructions/routes/pre_route.bmp", NULL);
    valise->CE_nope = load_bitmap("../images/map/CE_nope.bmp", NULL);
    valise->CE_yes = load_bitmap("../images/map/CE_yes.bmp", NULL);
    valise->CE_cancel = load_bitmap("../images/map/CE_cancel.bmp", NULL);
    valise->CDO_nope = load_bitmap("../images/map/CDO_nope.bmp", NULL);
    valise->CDO_yes = load_bitmap("../images/map/CDO_yes.bmp", NULL);
    valise->CDO_cancel = load_bitmap("../images/map/CDO_cancel.bmp", NULL);
    valise->filtre = load_bitmap("../images/map/filtre.bmp", NULL);
    valise->filtre_CDO = load_bitmap("../images/map/filtre_CDO.bmp", NULL);
    valise->filtre_CE = load_bitmap("../images/map/filtre_CE.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES RESEAU ELECTRIQUES ET D'EAU :
    valise->reseau_eau1 = load_bitmap("../images/constructions/centrales_eau/reseau_eau1.bmp", NULL);
    valise->reseau_eau2 = load_bitmap("../images/constructions/centrales_eau/reseau_eau2.bmp", NULL);
    valise->reseau_eau3 = load_bitmap("../images/constructions/centrales_eau/reseau_eau3.bmp", NULL);
    valise->reseau_elec1 = load_bitmap("../images/constructions/centrales_elec/reseau_elec1.bmp", NULL);
    valise->reseau_elec2 = load_bitmap("../images/constructions/centrales_elec/reseau_elec2.bmp", NULL);
    valise->reseau_elec3 = load_bitmap("../images/constructions/centrales_elec/reseau_elec3.bmp", NULL);
    valise->centraleElec = load_bitmap("../images/constructions/centrales_elec/centraleElec.bmp", NULL);
    valise->centraleEau = load_bitmap("../images/constructions/centrales_eau/centraleEau.bmp", NULL);
    valise->bullydingIrrig = load_bitmap("../images/constructions/centrales_eau/bullyding_irrigue.bmp", NULL);
    valise->bullydingLuz = load_bitmap("../images/constructions/centrales_elec/bullyding_irrigue.bmp", NULL);
    valise->case_grise_eau = load_bitmap("../images/constructions/centrales_eau/case_grise.bmp", NULL);
    valise->case_grise_elec = load_bitmap("../images/constructions/centrales_elec/case_grise.bmp", NULL);
    valise->case_griseClair = load_bitmap("../images/constructions/centrales_eau/case_griseClaire.bmp", NULL);
    valise->CDO_1 = load_bitmap("../images/constructions/centrales_eau/CDO_1.bmp", NULL);
    valise->source_eau = load_bitmap("../images/constructions/centrales_eau/source_eau.bmp", NULL);
    valise->CE_2 = load_bitmap("../images/constructions/centrales_elec/CE_2.bmp", NULL);
    valise->source_elec = load_bitmap("../images/constructions/centrales_elec/source_elec.bmp", NULL);


    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DE LA BOITE A OUTILS :
    valise->bao_ouv = load_bitmap("../images/boite_a_outils/bao_ouv.bmp",NULL);
    valise->bao_fer = load_bitmap("../images/boite_a_outils/bao_fer.bmp",NULL);
    valise->rond_0 = load_bitmap("../images/boite_a_outils/rond_0.bmp",NULL);
    valise->rond_1 = load_bitmap("../images/boite_a_outils/rond_1.bmp",NULL);
    valise->rond_2 = load_bitmap("../images/boite_a_outils/rond_2.bmp",NULL);
    valise->croute = load_bitmap("../images/boite_a_outils/croute.bmp",NULL);
    valise->croute2 = load_bitmap("../images/boite_a_outils/croute2.bmp",NULL);
    valise->cmaison = load_bitmap("../images/boite_a_outils/cmaison.bmp",NULL);
    valise->cmaison2 = load_bitmap("../images/boite_a_outils/cmaison2.bmp",NULL);
    valise->cwattank = load_bitmap("../images/boite_a_outils/ccentrale.bmp",NULL);
    valise->cwattank2 = load_bitmap("../images/boite_a_outils/ccentrale2.bmp",NULL);
    valise->centrale = load_bitmap("../images/boite_a_outils/cwattank.bmp",NULL);
    valise->centrale2 = load_bitmap("../images/boite_a_outils/cwattank2.bmp",NULL);
    valise->coins2_vide = load_bitmap("../images/boite_a_outils/coins2_vide.bmp", NULL);
    valise->coins2_middle = load_bitmap("../images/boite_a_outils/coins2_middle.bmp", NULL);
    valise->coins2_pleine = load_bitmap("../images/boite_a_outils/coins2_pleine.bmp", NULL);
    valise->reserve_eau_vide = load_bitmap("../images/boite_a_outils/reserve_eau_vide.bmp", NULL);
    valise->reserve_eau_middle = load_bitmap("../images/boite_a_outils/reserve_eau_middle.bmp", NULL);
    valise->reserve_eau_pleine = load_bitmap("../images/boite_a_outils/reserve_eau_pleine.bmp", NULL);
    valise->reserve_elec_vide = load_bitmap("../images/boite_a_outils/reserve_elec_vide.bmp", NULL);
    valise->reserve_elec_middle = load_bitmap("../images/boite_a_outils/reserve_elec_middle.bmp", NULL);
    valise->reserve_elec_pleine = load_bitmap("../images/boite_a_outils/reserve_elec_pleine.bmp", NULL);
    valise->people = load_bitmap("../images/boite_a_outils/people.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES BATIMENTS :
    valise->chantier = load_bitmap("../images/constructions/batiments/chantier.bmp", NULL);
    valise->grue = load_bitmap("../images/constructions/batiments/grue.bmp", NULL);
    valise->cabane = load_bitmap("../images/constructions/batiments/cabane.bmp", NULL);
    valise->maison = load_bitmap("../images/constructions/batiments/maison.bmp", NULL);
    valise->bullyding = load_bitmap("../images/constructions/batiments/bullyding.bmp", NULL);
    valise->skyscrap = load_bitmap("../images/constructions/batiments/skyscrapper.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DE LA MAP EN GENERAL :
    valise->plateforme = load_bitmap("../images/map/neige.bmp",NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DU MENU PRINCIPAL :
    valise->bouton2 = load_bitmap("../images/bouton_menu/bouton1.bmp",NULL);
    valise->bouton1 = load_bitmap("../images/bouton_menu/bouton2.bmp",NULL);
    valise->bouton3 = load_bitmap("../images/bouton_menu/bouton3.bmp",NULL);
    valise->bouton4 = load_bitmap("../images/bouton_menu/bouton4.bmp",NULL);
    valise->bouton5 = load_bitmap("../images/bouton_menu/bouton5.bmp",NULL);
    valise->bouton6 = load_bitmap("../images/bouton_menu/bouton6.bmp",NULL);
    valise->bouton7 = load_bitmap("../images/bouton_menu/bouton7.bmp",NULL);
    valise->bouton8 = load_bitmap("../images/bouton_menu/bouton8.bmp",NULL);
    valise->boutonpause = load_bitmap("../images/bouton_menu/bouton_pause.bmp",NULL);
    valise->titre=load_bitmap("../images/cinematiques/fond_menu/titre.bmp",NULL);
    valise->fond = load_bitmap("../images/bouton_menu/fondmenu.bmp",NULL);
    valise->bouton9 = load_bitmap("../images/bouton_menu/bouton9.bmp",NULL);

    /// DIFFERENTS SPRITE POUR LES INFORMATIONS DES BATIMENTS
    valise->info_cabane = load_bitmap("../images/informations/Cabane.bmp", NULL);
    valise->info_maison = load_bitmap("../images/informations/Maison.bmp", NULL);
    valise->info_bullyding = load_bitmap("../images/informations/Bullyding.bmp", NULL);
    valise->info_skyscrapper = load_bitmap("../images/informations/Skyscrapper.bmp", NULL);
    valise->info_CDO = load_bitmap("../images/informations/chateau_eau.bmp", NULL);
    valise->info_CE = load_bitmap("../images/informations/centrale_elec.bmp", NULL);
    valise->info_chantier = load_bitmap("../images/informations/chantier.bmp", NULL);
    valise->etage_info = 0;
    valise->sprite_info_CDO = load_bitmap("../images/informations/CDO_info.bmp", NULL);
    valise->sprite_info_CE = load_bitmap("../images/informations/CE_info.bmp", NULL);
    valise->sprite_info_sky = load_bitmap("../images/informations/skyscrapper_info.bmp", NULL);
    valise->sprite_info_bullyding = load_bitmap("../images/informations/bullyding_info.bmp", NULL);
    valise->sprite_info_maison = load_bitmap("../images/informations/maison_info.bmp", NULL);
    valise->sprite_info_cabane = load_bitmap("../images/informations/cabane_info.bmp", NULL);
    valise->sprite_info_chantier = load_bitmap("../images/informations/chantier_info.bmp", NULL);

    /// DIFFERENTS SPRITES POUR LES MESSAGES :
    valise->tuto_route = load_bitmap("../images/message/tuto_routes.bmp", NULL);
    valise->tuto_eau = load_bitmap("../images/message/tuto_eau.bmp", NULL);
    valise->tuto_elec = load_bitmap("../images/message/message_elec.bmp", NULL);
    valise->message_argent = load_bitmap("../images/message/message_argent.bmp", NULL);
    valise->fleche = load_bitmap("../images/message/fleche.bmp", NULL);

/// ------------------------------------------------------------- INITIALISATION DES DIFFERENTES VARIABLES ----------------------------------------------------------

    /// VARIABLES NECESSAIRS AU MENU :
    valise->lancer=0;
    valise->lancer1=0;
    valise->lancer2=0;
    valise->lancer3=0;
    valise->lancer4=0;
    valise->lancer5=0;
    valise->lancerpause=0;
    valise->choix_menu=0;

    ///TIMER :
    valise->timer = 0;
    valise->seconde=0;
    valise->heure = 0;

    ///IMPOTS :
    valise->safe_impot = 1;

    /// VARIABLES NECESSAIRS A LA BOITE A OUTILS :
    valise->outil = 0;
    valise->etage = 0;
    valise->ouverture=0;
    valise->clic_1=1;
    valise->clic_2=0;
    valise->clic_3=0;
    valise->clic_4=0;
    valise->clic_5=0;
    valise->clic_6=0;
    valise->clic_7=0;

    /// VARIABLES D'OCCURENCE DES DIFFERENTES INFRASTRUCTURES :
    valise->nb_routes = 0;
    valise->nb_route_casse = 25;
    valise->nb_centrales_eau=0;
    valise->nb_centrales_elec=0;
    valise->nb_bat=0;

    /// VARIABLES CONCERNANT LES POSITIONS ET L'AFFICHAGE DES CASES :
    valise->ajout_x=0;
    valise->ajout_y=0;
    valise->pos_x=600;
    valise->pos_y=75;
    valise->pos_x_centre=valise->pos_x+DIAG_X/2;
    valise->pos_y_centre=valise->pos_y+DIAG_Y/2;
    valise->div=38;

    /// EXTRACTION DES BITMAPS POUR L'AFFICHAGE DE L'ARRIERE PLAN DU MENU :
    for(int i=0; i<10; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework00%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    for(int i=10; i<100; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework0%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    for(int i=100; i<373; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    valise->occu_cine_2=0;

    /// EXTRACTION DES BITMAPS POUR L'AFFICHAGE DE L'INTRO :
    for(int i=0; i<116; i++)
    {
        valise->cine_1[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_cine_1,"../images/cinematiques/ouverture/C%d.bmp",i);
        printf("%s\n", valise->nom_cine_1);
        valise->cine_1[i]=load_bitmap(valise->nom_cine_1,NULL);
    }
    valise->cinetique=0;
    valise->occu_cine_1=0;

    valise->taille=0;
    valise->ordre=0;
    valise->poids=1;

    valise->nb_fichier_gh=0;
    valise->extra_graphe=0;

    valise->play=0;
    valise->play_eau=0;
    valise->play_bao=0;
    valise->play_zap=0;
    valise->play_wo=0;


    /// MENU PAUSE ET REGLES DU JEU :
    valise->pose = load_bitmap("../images/bouton_menu/PAUSE.bmp",NULL);
    valise->r1 = load_bitmap("../images/regles/R1.bmp",NULL);
    valise->r2 = load_bitmap("../images/regles/R2.bmp",NULL);
    valise->r3 = load_bitmap("../images/regles/R3.bmp",NULL);
    valise->r4 = load_bitmap("../images/regles/R4.bmp",NULL);
    valise->r5 = load_bitmap("../images/regles/R5.bmp",NULL);
    valise->r6 = load_bitmap("../images/regles/R6.bmp",NULL);
    valise->r7 = load_bitmap("../images/regles/R7.bmp",NULL);
    valise->rules=0;
    valise->fleched =load_bitmap("../images/regles/FLECHE_D.bmp",NULL);
    valise->flecheg = load_bitmap("../images/regles/FLECHE_G.bmp",NULL);
    valise->retour = load_bitmap("../images/regles/retour.bmp",NULL);
    valise->rul1=0;
    valise->rul2=0;
    valise->choixret=0;
    valise->tiempo = 0;
}

void init_info(t_info* info)
{
    info->bullyding = 0;
    info->cabane = 0;
    info->centrale_electrique = 0;
    info->chateau_eau = 0;
    info->habitation = 0;
    info->irrigue = 0;
    info->maison = 0;
    info->skyscrapper = 0;
    info->chantier = 0;
}


/// SOUS PROGRAMME QUI INITIALISE LES DIFFERENTES VARIABLES DE LA MAIRIE
void init_mairie(t_mairie* mairie)
{
    mairie->bully_flouz = 500000; /// ARGENT
    mairie->cout_centrale=100000; /// COUT D'UNE CENTRALE ELEC
    mairie->capacite_CE = 5000; ///CAPACITE D'UNE CENTRALE ELECTRIQUE (5000 PERSONNES)
    mairie->capa_tot_elec = 0;
    mairie->cout_chateau_do=100000; /// COUT D'UN CHATEAU D'EAU
    mairie->capacite_CDO = 5000; ///CAPACITE D'UN CHATEAU D'EAU (5000 PERSONNES)
    mairie->capa_tot_eau = 0;
    mairie->cout_route=10; ///COUT D'UNE ROUTE
    mairie->cout_terrainV=1000; /// COUT D'UN TERRAIN VAGUE
    mairie->impots=10; /// IMPOTS
    mairie->nb_habitants = 0;
}

void crea_struct_cases(t_valise valise, t_cases cases[35][45])
{

    srand(time(NULL));


    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            sprintf(cases[i][j].numero_cases,"case ( %d , %d )",i,j);
            cases[i][j].pos_x= valise.pos_x+valise.ajout_x;
            cases[i][j].pos_y=valise.pos_y+valise.ajout_y;
            cases[i][j].pos_x_centre=valise.pos_x_centre+valise.ajout_x;
            cases[i][j].pos_y_centre=valise.pos_y_centre+valise.ajout_y;
            fscanf(valise.fic, "%d", &cases[i][j].type_cases);

            cases[i][j].numero_ligne=i;
            cases[i][j].numero_colonne=j;
            cases[i][j].avancement = 0;
            valise.compteur_cases+=1;
            cases[i][j].id = valise.compteur_cases;
            valise.ajout_x+=DIAG_X/2;
            valise.ajout_y+=DIAG_Y/2;
            cases[i][j].numero_route_graphe = -1;
        }
        valise.ajout_x=0;
        valise.ajout_y=0;
        valise.pos_x-=DIAG_X/2;
        valise.pos_y+=DIAG_Y/2;
        valise.pos_x_centre-=DIAG_X/2;
        valise.pos_y_centre+=DIAG_Y/2;
        valise.nb_routes = 0;

    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////// GRAPHES ///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// SOUS PROGRAMME QUI PERMET D'AFFICHER LES SUCCESSEUR D'UN SOMMET :
void afficher_successeurs(t_sommet** sommet, int num)
{

    printf(" sommet %d :\n",num);

    t_arc* arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("\t successeur: %d | poids : %d  \n",arc->sommet,arc->poids);
        arc=arc->arc_suivant;
    }

}

/// SOUS PROGRAMME QUI AJOUTE L'ARRETE ENTRE LES SOMMET S1 ET S2 DU GRAPHE :
t_sommet** CreerArete(t_sommet** sommet,int s1,int s2, int poids)
{
    if(sommet[s1]->arc==NULL)
    {
        t_arc* Newarc=(t_arc*)malloc(sizeof(t_arc));
        Newarc->sommet=s2;
        Newarc->poids=poids;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }
    else
    {
        t_arc* temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        t_arc* Newarc=(t_arc*)malloc(sizeof(t_arc));
        Newarc->sommet=s2;
        Newarc->poids=poids;
        Newarc->arc_suivant=NULL;

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

/// SOUS PROGRAMME QUI CREER LE GRAPHE :
t_graphe* creation_graphe(int ordre)
{
    t_graphe * Newgraphe=(t_graphe*)malloc(sizeof(t_graphe));
    Newgraphe->pSommet = (t_sommet**)malloc(ordre*sizeof(t_sommet*));

    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(t_sommet*)malloc(sizeof(t_sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->marquage=0;
        Newgraphe->pSommet[i]->degre=0;
        Newgraphe->pSommet[i]->predec=-1;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}

/// SOUS PROGRAMME QUI PERMET L'EXTRACTION D'UN GRAPHE DANS UN FICHIER TEXTE
/// (LE FICHIER CONTIENT : ORDRE, TAILLE, LISTE DES ARCS) :
t_graphe* extraire_graphe()
{
    t_graphe* graphe;
    FILE * ifs = fopen("../fichier_graphe/or_ta.txt","r");
    FILE * ifs2 = fopen("../fichier_graphe/graphe.txt","r");

    int taille, ordre, s1, s2, id1, id2, poids;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    if (!ifs2)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&taille);
    fscanf(ifs,"%d",&ordre);
    graphe=creation_graphe(ordre); /// CREER LE GRAPHE D'ORDRE SOMMETS
    graphe->ordre=ordre;

    /// CREER LES ARRETES DU GRAPHE
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs2,"%d %d %d %d %d", &s1, &id1, &s2, &id2, &poids);
        graphe->pSommet = CreerArete(graphe->pSommet, id1, id2,poids);
    }
    return graphe;
}

/// SOUS PROGRAMME QUI PERMET D'AFFICHER LE GRAPHE :
void afficher_graphe(t_graphe* graphe)
{
    printf("graphe\n");


    printf("ordre = %d\n",graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

/*
Ce sous programme permet de savoir si tout les sommets ont été visités
Le principe est de vérifier les sommets marqués, lorsqu'un sommet est marque on ajoute 1 dans un compteur
Lorsque ce compteur est égal aux nombre de sommets du graphe, alors ça signifie que tout les sommets ont été visités
*/

int sommet_all_visited(t_graphe* graphe)
{
    int total=0;
    for(int i=0; i<graphe->ordre; i++)
    {
        if(graphe->pSommet[i]->marquage==1)
        {
            total+=1;
        }
    }
    if(total==graphe->ordre)
    {
        return 1;
    }
}

/// SOUS PROGRAMME QUI PERMET LA RECHERCHE DU MINIMUM
int minimum(t_graphe* graphe)
{
    int minimum = 5000;  ///ICI MINIMUM VAUT LA VALEUR DE LA DISTANCE "INFINIE"
    int min =-1;  /// ON INITIALISE UN MIN A -1, POUR LE RENDRE AU PROG APPELANT ET L'UTILISER DANS DIJKSTRA

    for(int i=0; i<graphe->ordre; i++)
    {
        /// ON VERIFIE QUE LE SOMMET I N'EST PAS MARQUE ET QUE SA DISTANCE N'EST PAS INFINIE
        if( ( graphe->pSommet[i]->marquage != 1 ) && ( graphe->pSommet[i]->dist < minimum ))
        {
            minimum = graphe->pSommet[i]->dist; /// ON ASSOCIE A MINIMUM LA DISTANCE DU SOMMET I
            min=i; /// LA VARIABLE RENVOYEE PREND DONC LA VALEUR DE I
        }
    }
    return min; ///ON REND LE MINIMUM AU PROG APPELANT
}


void dijkstra(t_graphe* graphe, int sommet_init, int sommet_final)
{
    int min = -1;  ///EN LIEN AVEC LE SOUS PROGRAMME "MINIMUM" ON INITIALISE MIN A -1
    int var=0;

    /// ON INITIALISE NOS VARIABLES
    for(int i=0; i<graphe->ordre; i++)
    {
        graphe->pSommet[i]->dist=5000; /// ON INITIALISE LA DISTANCE A 5000 (DISTANCE INFINIE)
        graphe->pSommet[i]->predec=-1; /// -1 POUR PAS DE PREDECESSEUR, SINON : NUMERO DE PREDECESSEUR

    }
    graphe->pSommet[sommet_init]->dist=0;  ///LE SOMMET INITIAL EST A UNE DISTANCE NULLE DE LUI MEME
    graphe->pSommet[sommet_init]->predec=-2; /// PAS DE PREDECESSEUR NON PLUS

    do
    {
        /// ON CHERCHE, ON CHOISI ET MARQUE LE SOMMET NON MARQUE AYANT LA PLUS PETITE DISTANCE AVEC LE SOMMET INITIAL
        min = minimum(graphe);

        if(min != -1)
        {
            graphe->pSommet[min]->marquage = 1; ///ON MARQUE LE SOMMET

            t_arc* tempon = graphe->pSommet[min]->arc; ///CREATION D'UN ARC TAMPON
            while(tempon != NULL) ///TANT QU'IL YA ENCORE DES ARCS SUIVANTS
            {
                ///ON VERIFIE QUE NOTRE SOMMET N'EST PAS MARQUE ET QUE LA SOMME DE LA DISTANCE POUR ALLER A S0 ET LE POIDS EST INFERIEUR A LA DISTANCE MEMORISEE
                if( (graphe->pSommet[tempon->sommet]->marquage != 1 ) && (graphe->pSommet[min]->dist + tempon->poids < graphe->pSommet[tempon->sommet]->dist) )
                {
                    ///AINSI ON MET A JOUR LA DISTANCE ET ON NOTE LE PREDECESSEUR
                    graphe->pSommet[tempon->sommet]->dist = graphe->pSommet[min]->dist + tempon->poids;
                    graphe->pSommet[tempon->sommet]->predec = min;
                }
                tempon = tempon->arc_suivant;
            }
        }
    }
    while(sommet_all_visited( graphe)!=1); ///LA BOUCLE SE TERMINE QUAND ON A VIVITE TOUS LES SOMMETS


    ///AFFICHAGE DE LA DISTANCE ET DU CHEMIN DE POIDS MINIMAL
    printf("La distance minimale pour rejoindre le sommet %d depuis le sommet %d est  : %d",sommet_final,sommet_init,graphe->pSommet[sommet_final]->dist);
    printf("\n\n");

    printf("Le chemin de poids minimal est donc :  ");
    printf("%d", graphe->pSommet[sommet_final]->valeur);

    var = graphe->pSommet[sommet_final]->valeur;
    while(var != -2)
    {
        if(graphe->pSommet[var]->predec != -2)
        {
            printf(" <--- %d", graphe->pSommet[var]->predec);
        }
        var = graphe->pSommet[var]->predec;
    }
    printf("\n\n");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// AFFICHAGE D'UN CURSEUR STYLISE /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void affichage_curseur(t_valise valise)
{
    stretch_sprite(valise.double_buffer,valise.curseur,mouse_x,mouse_y,30,30);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// JOUER DE LA MUSIQUE //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void jouer_music(SAMPLE* sample)
{
    play_sample(sample,255,128,1000,0);
}

void notre_stop_music(SAMPLE* sample)
{
    stop_sample(sample);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////// FICHIERS ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void nombre_fic_grp(t_valise* valise)
{
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL; //Déclaration d'un pointeur vers la structure dirent.
    rep = opendir("fichier_graphe");


    if (rep == NULL)
        exit(1);

    fichierLu = readdir(rep); /* On lit le premier répertoire du dossier. */
    while ((fichierLu = readdir(rep)) != NULL)
    {

        if(strcmp(fichierLu->d_name,".")!=0&&strcmp(fichierLu->d_name,"..")!=0)
        {
            valise->nb_fichier_gh++;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// MAP, INFRASTRUCTURES, ... /////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void select_info(t_valise* valise, t_cases cases[35][45], t_info* info)
{
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            /// HABITATIONS :
            if(cases[i][j].type_cases == 3)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->filtre,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);
                    if(mouse_b &1 && valise->etage_info == 0)
                    {
                        if(cases[i][j].avancement == 0)
                        {
                            info->cabane = 0;
                            info->maison = 0;
                            info->bullyding = 0;
                            info->skyscrapper = 0;
                            info->habitation = 1;
                            info->centrale_electrique = 0;
                            info->chateau_eau = 0;
                            info->chantier = 1;
                        }
                        else if(cases[i][j].avancement == 1)
                        {
                            info->cabane = 1;
                            info->maison = 0;
                            info->bullyding = 0;
                            info->skyscrapper = 0;
                            info->habitation = 1;
                            info->centrale_electrique = 0;
                            info->chateau_eau = 0;
                            info->chantier = 0;
                        }
                        else if(cases[i][j].avancement == 2)
                        {
                            info->cabane = 0;
                            info->maison = 1;
                            info->bullyding = 0;
                            info->skyscrapper = 0;
                            info->habitation = 1;
                            info->centrale_electrique = 0;
                            info->chateau_eau = 0;
                            info->chantier = 0;
                        }
                        else if(cases[i][j].avancement == 3)
                        {
                            info->cabane = 0;
                            info->maison = 0;
                            info->bullyding = 1;
                            info->skyscrapper = 0;
                            info->habitation = 1;
                            info->centrale_electrique = 0;
                            info->chateau_eau = 0;
                            info->chantier = 0;
                        }
                        else if(cases[i][j].avancement == 4)
                        {
                            info->cabane = 0;
                            info->maison = 0;
                            info->bullyding = 0;
                            info->skyscrapper = 1;
                            info->habitation = 1;
                            info->centrale_electrique = 0;
                            info->chateau_eau = 0;
                            info->chantier = 0;
                        }
                        valise->etage_info = 1;
                        rest(100);
                    }
                }
                else if((mouse_x<250 || mouse_x>1150) || (mouse_y<45 || mouse_y>610))
                {
                    if(mouse_b &1 && valise->etage_info == 1)
                    {
                        valise->etage_info = 0;
                        rest(100);
                    }
                }
            }
            /// CHATEAU D'EAU :
            if(cases[i][j].type_cases == 12)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->filtre_CDO,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);
                    if(mouse_b &1 && valise->etage_info == 0)
                    {
                        info->cabane = 0;
                        info->maison = 0;
                        info->bullyding = 0;
                        info->skyscrapper = 0;
                        info->habitation = 0;
                        info->centrale_electrique = 0;
                        info->chateau_eau = 1;
                        info->chantier = 0;

                        valise->etage_info = 1;
                        rest(100);
                    }
                }
                else if((mouse_x<250 || mouse_x>1150) || (mouse_y<45 || mouse_y>610))
                {
                    if(mouse_b &1 && valise->etage_info == 1)
                    {
                        valise->etage_info = 0;
                        rest(100);
                    }
                }

            }
            /// CENTRALES ELECTRIQUES :
            if(cases[i][j].type_cases == 10)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->filtre_CE,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);
                    if(mouse_b &1 && valise->etage_info == 0)
                    {
                        info->cabane = 0;
                        info->maison = 0;
                        info->bullyding = 0;
                        info->skyscrapper = 0;
                        info->habitation = 0;
                        info->centrale_electrique = 1;
                        info->chateau_eau = 0;
                        info->chantier = 0;

                        valise->etage_info = 1;
                        rest(100);
                    }
                }
                else if((mouse_x<250 || mouse_x>1150) || (mouse_y<45 || mouse_y>610))
                {
                    if(mouse_b &1 && valise->etage_info == 1)
                    {
                        valise->etage_info = 0;
                        rest(100);
                    }
                }

            }
        }
    }
}

void information(t_valise valise, t_info info)
{
    if(info.cabane == 0 && info.maison == 0 && info.bullyding == 0 && info.skyscrapper == 0 && info.habitation == 1 && info.centrale_electrique == 0 &&
            info.chateau_eau == 0 && info.chantier == 1)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_chantier,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_chantier,735,285,SCREEN_W/3.5,SCREEN_H/3.5);
    }
    else if(info.cabane == 1 && info.maison == 0 && info.bullyding == 0 && info.skyscrapper == 0 && info.habitation == 1 && info.centrale_electrique == 0 &&
            info.chateau_eau == 0 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_cabane,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_cabane,735,285,SCREEN_W/3.5,SCREEN_H/3.5);
    }
    else if(info.cabane == 0 && info.maison == 1 && info.bullyding == 0 && info.skyscrapper == 0 && info.habitation == 1 && info.centrale_electrique == 0 &&
            info.chateau_eau == 0 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_maison,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_maison,650,235,SCREEN_W/2.5,SCREEN_H/2.5);
    }
    else if(info.cabane == 0 && info.maison == 0 && info.bullyding == 1 && info.skyscrapper == 0 && info.habitation == 1 && info.centrale_electrique == 0 &&
            info.chateau_eau == 0 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_bullyding,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_bullyding,585,215,SCREEN_W/2,SCREEN_H/2);
    }
    else if(info.cabane == 0 && info.maison == 0 && info.bullyding == 0 && info.skyscrapper == 1 && info.habitation == 1 && info.centrale_electrique == 0 &&
            info.chateau_eau == 0 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_skyscrapper,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_sky,585,235,SCREEN_W/2,SCREEN_H/2.5);
    }
    else if(info.cabane == 0 && info.maison == 0 && info.bullyding == 0 && info.skyscrapper == 0 && info.habitation == 0 && info.centrale_electrique == 0 &&
            info.chateau_eau == 1 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_CDO,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_CDO,705,235,SCREEN_W/3,SCREEN_H/2.5);
    }
    else if(info.cabane == 0 && info.maison == 0 && info.bullyding == 0 && info.skyscrapper == 0 && info.habitation == 0 && info.centrale_electrique == 1 &&
            info.chateau_eau == 0 && info.chantier == 0)
    {
        rectfill(valise.double_buffer,250,117,1150,682,makecol(180,180,180));
        stretch_sprite(valise.double_buffer,valise.info_CE,270,132,SCREEN_W/3,SCREEN_H/1.5);
        stretch_sprite(valise.double_buffer,valise.sprite_info_CE,705,235,SCREEN_W/3,SCREEN_H/2.5);
    }
}

void affichage_plateau(t_valise* valise, t_cases cases[35][45])
{
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            if(cases[i][j].type_cases==0 || cases[i][j].type_cases==12 ||
                    cases[i][j].type_cases==13 || cases[i][j].type_cases==10 || cases[i][j].type_cases==11)
            {
                stretch_sprite(valise->double_buffer,valise->plateforme,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                               SCREEN_W/valise->div,SCREEN_H/valise->div);
            }
            if(cases[i][j].type_cases==2 || cases[i][j].type_cases==3)
            {
                stretch_sprite(valise->double_buffer,valise->case_griseClair,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                               SCREEN_W/valise->div,SCREEN_H/valise->div);
            }

            ///ROUTE :
            else if(cases[i][j].type_cases==1)
            {
                if((cases[i][j+1].type_cases==1 && cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases!=1 || cases[i+1][j].type_cases!=1))
                {
                    stretch_sprite(valise->double_buffer,valise->route2,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if ((cases[i-1][j].type_cases==1 && cases[i+1][j].type_cases==1) && (cases[i][j+1].type_cases!=1 || cases[i][j-1].type_cases!=1) && (cases[i][j+1].type_cases!=6 || cases[i][j-1].type_cases!=6))
                {
                    stretch_sprite(valise->double_buffer,valise->route,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases==1))||((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->carrefour,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->virageB,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases==1)))
                {
                    stretch_sprite(valise->double_buffer,valise->virageH,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases==1)))
                {
                    stretch_sprite(valise->double_buffer,valise->virageD,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->virageG,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases==1)))
                {
                    stretch_sprite(valise->double_buffer,valise->stopH,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->stopB,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases!=1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->stopG,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases!=1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases!=1) && (cases[i+1][j].type_cases!=1)))
                {
                    stretch_sprite(valise->double_buffer,valise->stopD,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                else if(((cases[i][j+1].type_cases==6) && (cases[i][j-1].type_cases==6) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases==1)))
                {
                    stretch_sprite(valise->double_buffer,valise->pont,cases[i][j].pos_x,cases[i][j].pos_y,SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==7)
            {
                stretch_sprite(valise->double_buffer,valise->route_casse,cases[i][j].pos_x,cases[i][j].pos_y,SCREEN_W/valise->div,SCREEN_H/valise->div);
            }

            valise->ajout_x+=DIAG_X/2;
            valise->ajout_y+=DIAG_Y/2;
        }
        valise->ajout_x=0;
        valise->ajout_y=0;
        valise->pos_x-=DIAG_X/2;
        valise->pos_y+=DIAG_Y/2;
    }
}

void affichage_batiments(t_valise* valise, t_cases cases[35][45])
{
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {

            /// DIFFERENTES HABITATIONS :
            if(cases[i][j].type_cases==3 && cases[i][j].avancement == 0)
            {
                stretch_sprite(valise->double_buffer,valise->chantier,cases[i][j].pos_x-33,cases[i][j].pos_y-19,SCREEN_W/14,SCREEN_H/16.5);
            }
            if(cases[i][j].type_cases==3 && cases[i][j].avancement == 1)
            {
                stretch_sprite(valise->double_buffer,valise->cabane,cases[i][j].pos_x-29,cases[i][j].pos_y-26,SCREEN_W/14,SCREEN_H/13);
            }
            if(cases[i][j].type_cases==3 && cases[i][j].avancement == 2)
            {
                stretch_sprite(valise->double_buffer,valise->maison,cases[i][j].pos_x-34,cases[i][j].pos_y-38,SCREEN_W/13.5,SCREEN_H/11.5);
            }
            if(cases[i][j].type_cases==3 && cases[i][j].avancement == 3)
            {
                stretch_sprite(valise->double_buffer,valise->bullyding,cases[i][j].pos_x-27,cases[i][j].pos_y-91,SCREEN_W/16,SCREEN_H/7);
            }
            if(cases[i][j].type_cases==3 && cases[i][j].avancement == 4)
            {
                stretch_sprite(valise->double_buffer,valise->skyscrap,cases[i][j].pos_x-26,cases[i][j].pos_y-127,SCREEN_W/15.5,SCREEN_H/5.2);
            }
            ///AFFICHAGE DES CENTRALES ELEC ET DES CHATEAUX D'EAU :
            if (cases[i][j].type_cases==12)
            {
                stretch_sprite(valise->double_buffer,valise->centraleEau,cases[i][j].pos_x-71,cases[i][j].pos_y-48,SCREEN_W/8,SCREEN_H/9);
            }
            else if(cases[i][j].type_cases==10)
            {
                stretch_sprite(valise->double_buffer,valise->centraleElec,cases[i][j].pos_x-49,cases[i][j].pos_y-47.5,SCREEN_W/8,SCREEN_H/9);
            }
        }
    }
}
void affichage_ressources(t_valise* valise, t_mairie* mairie)
{
    ///AFFICHAGE BULLY FLOUZ
    if(mairie->bully_flouz<=300000)
    {
        stretch_sprite(valise->double_buffer,valise->coins2_vide,1185,20,SCREEN_W/8,SCREEN_H/22);
        textprintf_ex(valise->double_buffer,font,1270,38,makecol(0,0,0),-1,"%d", mairie->bully_flouz);

    }
    else if(mairie->bully_flouz>300000 && mairie->bully_flouz<=600000)
    {
        stretch_sprite(valise->double_buffer,valise->coins2_middle,1185,20,SCREEN_W/8,SCREEN_H/22);
        textprintf_ex(valise->double_buffer,font,1270,38,makecol(0,0,0),-1,"%ld", mairie->bully_flouz);
    }
    else if(mairie->bully_flouz>600000)
    {
        stretch_sprite(valise->double_buffer,valise->coins2_pleine,1185,20,SCREEN_W/8,SCREEN_H/22);
        textprintf_ex(valise->double_buffer,font,1270,38,makecol(0,0,0),-1,"%d", mairie->bully_flouz);
    }
    ///AFFICHAGE BULLY WATER
    if(mairie->capa_tot_eau<=5000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_eau_vide,1077,55,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,80,makecol(255,255,255),-1,"%d", mairie->capa_tot_eau);
    }
    else if(mairie->capa_tot_eau>5000 && mairie->capa_tot_eau<=10000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_eau_middle,1077,55,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,80,makecol(255,255,255),-1,"%d", mairie->capa_tot_eau);
    }
    else if(mairie->capa_tot_eau>10000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_eau_pleine,1077,55,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,80,makecol(255,255,255),-1,"%d", mairie->capa_tot_eau);
    }
    ///AFFICHAGE BULLY ELEC
    if(mairie->capa_tot_elec<=5000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_elec_vide,1084,98,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,122,makecol(0,0,0),-1,"%d", mairie->capa_tot_elec);
    }
    else if(mairie->capa_tot_elec>5000 && mairie->capa_tot_elec<=10000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_elec_middle,1084,98,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,122,makecol(0,0,0),-1,"%d", mairie->capa_tot_elec);
    }
    else if(mairie->capa_tot_elec>10000)
    {
        stretch_sprite(valise->double_buffer,valise->reserve_elec_pleine,1084,98,SCREEN_W/5,SCREEN_H/18);
        textprintf_ex(valise->double_buffer,font,1275,122,makecol(0,0,0),-1,"%d", mairie->capa_tot_elec);
    }
}

void creation_routes(t_valise* valise,t_mairie* mairie, t_cases cases[35][45])
{
    if(valise->nb_route_casse>0)
    {
        stretch_sprite(valise->double_buffer,valise->tuto_route,1020,380,SCREEN_W/4,SCREEN_H/2);
        stretch_sprite(valise->double_buffer,valise->fleche,415,115,SCREEN_W/16,SCREEN_H/16);
    }

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            if(is_in_case(cases[i][j])==1)
            {
                textprintf_ex(valise->double_buffer,font,50,800,makecol(255,255,255),-1,"%c", cases[i][j].numero_cases);
                textprintf_ex(valise->double_buffer,font,1000,90,makecol(0,200,255),-1," case : %d | type : %d",cases[i][j].id,cases[i][j].type_cases);
            }

            if(valise->nb_route_casse>0)
            {
                if(is_in_case(cases[i][j])==1 && cases[i][j].type_cases == 7)
                {

                    stretch_sprite(valise->double_buffer,valise->case_okey,cases[i][j].pos_x,cases[i][j].pos_y,SCREEN_W/valise->div,SCREEN_H/valise->div);

                    if(mouse_b & 1)
                    {

                        if(valise->nb_routes==0)
                        {
                            cases[i][j].numero_route_graphe=0;
                        }
                        if( ( cases[i][j+1].type_cases!=1 && cases[i][j-1].type_cases!=1)&& valise->nb_routes !=0 )
                        {
                            cases[i][j].numero_route_graphe=valise->nb_routes;
                        }
                        valise->nb_routes+=1;
                        valise->nb_route_casse-=1;
                        //cases[i][j].numero_route_graphe=valise->nb_routes;
                        if(cases[i-1][j].type_cases == 1 || cases[i-1][j].type_cases == 7)
                        {

                            valise->taille+=1;
                            valise->ordre=valise->nb_routes+valise->nb_bat+valise->nb_centrales_eau+valise->nb_centrales_elec;
                            nombre_fic_grp(valise);
                            if(cases[i-1][j].numero_route_graphe==-1)
                            {
                                cases[i-1][j].numero_route_graphe=valise->nb_routes+1;
                            }
                            if(valise->nb_fichier_gh==0)
                            {

                                FILE* fic1 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic2 = fopen("../fichier_graphe/graphe.txt", "w");

                                fprintf(fic1, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic2, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i-1][j].id, cases[i-1][j].numero_route_graphe,valise->poids);
                                fclose(fic1);
                                fclose(fic2);

                            }
                            if(valise->nb_fichier_gh>0)
                            {

                                FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");

                                fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i-1][j].id, cases[i-1][j].numero_route_graphe,valise->poids);
                                fclose(fic3);
                                fclose(fic4);

                            }
                            valise->nb_fichier_gh=0;
                            //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i-1][j].id);


                        }

                        if(cases[i][j-1].type_cases == 1 || cases[i][j-1].type_cases == 7)
                        {
                            valise->taille+=1;
                            valise->ordre=valise->nb_routes+valise->nb_bat+valise->nb_centrales_eau+valise->nb_centrales_elec;
                            nombre_fic_grp(valise);
                            if(cases[i][j-1].numero_route_graphe==-1)
                            {
                                cases[i][j-1].numero_route_graphe=valise->nb_routes+1;
                            }
                            if(valise->nb_fichier_gh==0)
                            {
                                FILE* fic1 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic2 = fopen("../fichier_graphe/graphe.txt", "w");
                                fprintf(fic1, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic2, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j-1].id, cases[i][j-1].numero_route_graphe,valise->poids);
                                fclose(fic1);
                                fclose(fic2);

                            }
                            if(valise->nb_fichier_gh>0)
                            {

                                FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j-1].id, cases[i][j-1].numero_route_graphe,valise->poids);
                                fclose(fic3);
                                fclose(fic4);
                                //printf("ah oui");

                            }
                            valise->nb_fichier_gh=0;
                            //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i][j-1].id);


                        }
                        if(cases[i+1][j].type_cases == 1 || cases[i+1][j].type_cases == 7)
                        {
                            valise->taille+=1;
                            valise->ordre=valise->nb_routes+valise->nb_bat+valise->nb_centrales_eau+valise->nb_centrales_elec;
                            nombre_fic_grp(valise);
                            if(cases[i+1][j].numero_route_graphe==-1)
                            {
                                cases[i+1][j].numero_route_graphe=valise->nb_routes;
                            }
                            if(valise->nb_fichier_gh==0)
                            {

                                FILE* fic1 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic2 = fopen("../fichier_graphe/graphe.txt", "w");
                                fprintf(fic1, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic2, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i+1][j].id, cases[i+1][j].numero_route_graphe,valise->poids);
                                fclose(fic1);
                                fclose(fic2);

                            }
                            if(valise->nb_fichier_gh>0)
                            {

                                FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i+1][j].id, cases[i+1][j].numero_route_graphe,valise->poids);
                                fclose(fic3);
                                fclose(fic4);

                            }
                            valise->nb_fichier_gh=0;
                            //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i+1][j].id);


                        }
                        if(cases[i][j+1].type_cases == 1 || cases[i][j+1].type_cases == 7)
                        {
                            valise->taille+=1;
                            valise->ordre=valise->nb_routes+valise->nb_bat+valise->nb_centrales_eau+valise->nb_centrales_elec;
                            nombre_fic_grp(valise);
                            if(cases[i][j+1].numero_route_graphe==-1)
                            {
                                cases[i][j+1].numero_route_graphe=valise->nb_routes;
                            }
                            if(valise->nb_fichier_gh==0)
                            {

                                FILE* fic1 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic2 = fopen("../fichier_graphe/graphe.txt", "w");
                                printf("j+1");
                                fprintf(fic1, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic2, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j+1].id, cases[i][j+1].numero_route_graphe,valise->poids);
                                fclose(fic1);
                                fclose(fic2);


                            }
                            if(valise->nb_fichier_gh>0)
                            {

                                FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j+1].id, cases[i][j+1].numero_route_graphe,valise->poids);
                                fclose(fic3);
                                fclose(fic4);

                            }
                            valise->nb_fichier_gh=0;

                            //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i][j+1].id);

                            //printf("j+1 : %d\n", cases[i][j+1].id);


                        }
                        cases[i][j].type_cases = 1;
                        mairie->bully_flouz-=mairie->cout_route;
                        valise->extra_graphe=1;
                    }


                }
            }
            else
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j+1].type_cases==1 || cases[i][j-1].type_cases==1 || cases[i-1][j].type_cases==1 || cases[i+1][j].type_cases==1))
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        stretch_sprite(valise->double_buffer,valise->case_okey,cases[i][j].pos_x,cases[i][j].pos_y,SCREEN_W/valise->div,SCREEN_H/valise->div);

                        if(mouse_b & 1)
                        {

                            if(mairie->bully_flouz<0)
                            {
                                textprintf_ex(valise->double_buffer,font,550,90,makecol(0,255,0),-1,"T AS PAS D ARGENT CA VA TE BULLY TOI !");
                            }
                            else
                            {
                                cases[i][j].numero_route_graphe=valise->nb_routes;
                                valise->nb_routes+=1;
                                valise->nb_route_casse-=1;
                                if(cases[i-1][j].type_cases == 1)
                                {

                                    valise->taille+=1;
                                    valise->ordre=valise->nb_routes;
                                    nombre_fic_grp(valise);
                                    if(cases[i-1][j].numero_route_graphe==-1)
                                    {
                                        cases[i-1][j].numero_route_graphe=valise->nb_routes;
                                    }

                                    FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                    FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                    fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                    fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i-1][j].id, cases[i-1][j].numero_route_graphe,valise->poids);
                                    fclose(fic3);
                                    fclose(fic4);
                                    valise->nb_fichier_gh=0;
                                    //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i-1][j].id);

                                    cases[i][j].type_cases = 1;
                                    mairie->bully_flouz-=mairie->cout_route;
                                }

                                if(cases[i][j-1].type_cases == 1 )
                                {
                                    valise->taille+=1;
                                    valise->ordre=valise->nb_routes;
                                    nombre_fic_grp(valise);
                                    if(cases[i][j-1].numero_route_graphe==-1)
                                    {
                                        cases[i][j-1].numero_route_graphe=valise->nb_routes;
                                    }
                                    FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                    FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                    fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                    fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j-1].id, cases[i][j-1].numero_route_graphe,valise->poids);
                                    fclose(fic3);
                                    fclose(fic4);
                                    valise->nb_fichier_gh=0;
                                    //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i][j-1].id);

                                    cases[i][j].type_cases = 1;
                                    mairie->bully_flouz-=mairie->cout_route;
                                    ("j-1 : %d\n", cases[i][j-1].id);
                                }
                                if(cases[i+1][j].type_cases == 1)
                                {
                                    valise->taille+=1;
                                    valise->ordre=valise->nb_routes;
                                    nombre_fic_grp(valise);
                                    if(cases[i+1][j].numero_route_graphe==-1)
                                    {
                                        cases[i+1][j].numero_route_graphe=valise->nb_routes;
                                    }
                                    FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                    FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                    fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                    fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i+1][j].id, cases[i][j].numero_route_graphe,valise->poids);
                                    fclose(fic3);
                                    fclose(fic4);
                                    valise->nb_fichier_gh=0;
                                    //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i+1][j].id);


                                    cases[i][j].type_cases = 1;
                                    mairie->bully_flouz-=mairie->cout_route;
                                }
                                if(cases[i][j+1].type_cases == 1 )
                                {
                                    valise->taille+=1;
                                    valise->ordre=valise->nb_routes;
                                    nombre_fic_grp(valise);
                                    if(cases[i][j+1].numero_route_graphe==-1)
                                    {
                                        cases[i][j+1].numero_route_graphe=valise->nb_routes;
                                    }
                                    FILE* fic3 = fopen("../fichier_graphe/or_ta.txt", "w");
                                    FILE* fic4 = fopen("../fichier_graphe/graphe.txt", "a+");
                                    fprintf(fic3, " %d %d\n", valise->taille,valise->ordre);
                                    fprintf(fic4, " %d %d %d %d %d\n", cases[i][j].id, cases[i][j].numero_route_graphe,cases[i][j+1].id, cases[i][j+1].numero_route_graphe,valise->poids);
                                    fclose(fic3);
                                    fclose(fic4);

                                    valise->nb_fichier_gh=0;

                                    //printf("Taille : %d | ordre : %d | poids : %d | case choisie :%d | case adjacente : %d\n\n",valise->taille,valise->ordre,valise->poids,cases[i][j].id,cases[i][j+1].id);

                                    cases[i][j].type_cases = 1;
                                    mairie->bully_flouz-=mairie->cout_route;
                                    ("j+1 : %d\n", cases[i][j+1].id);

                                }
                            }
                            valise->extra_graphe=1;
                        }
                    }
                }
                if(cases[i][j].type_cases == 1)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(key[KEY_SPACE])
                        {
                            stretch_sprite(valise->double_buffer,valise->cancel,cases[i][j].pos_x,cases[i][j].pos_y,SCREEN_W/valise->div,SCREEN_H/valise->div);

                            if(mouse_b & 1)
                            {
                                cases[i][j].type_cases = 0;
                                valise->nb_routes-=1;
                                mairie->bully_flouz+=10;
                            }
                        }
                    }
                }
            }
        }
    }
}

void creation_batiment(t_valise* valise, t_mairie* mairie, t_cases cases[35][45])
{
    if(valise->nb_route_casse>0)
    {
        stretch_sprite(valise->double_buffer,valise->tuto_route,1020,380,SCREEN_W/4,SCREEN_H/2);
        stretch_sprite(valise->double_buffer,valise->fleche,415,115,SCREEN_W/16,SCREEN_H/16);
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            if(valise->nb_routes==0)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->bat_nope,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);


                    if(mouse_b & 1)
                    {
                        textprintf_ex(valise->double_buffer,font,750,300,makecol(0,200,255),-1,"VOUS DEVEZ D ABORD CONSTRUIRE DES ROUTES !");
                    }
                }
            }
            else
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j+2].type_cases==1 ||cases[i][j-2].type_cases==1 || cases[i-2][j].type_cases==1 || cases[i+2][j].type_cases==1) && (cases[i][j+1].type_cases==0 && cases[i][j-1].type_cases==0 && cases[i-1][j].type_cases==0 && cases[i+1][j].type_cases==0))
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(mairie->bully_flouz<1000)
                        {
                            stretch_sprite(valise->double_buffer,valise->bat_nope,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);
                            textprintf_ex(valise->double_buffer,font,750,300,makecol(255,0,0),-1,"T'AS PAS DE THUNE CA VA TE BULLY TOI !");
                        }
                        if(mairie->bully_flouz>=1000)
                        {
                            stretch_sprite(valise->double_buffer,valise->bat_okey,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);

                            if(mouse_b & 1)
                            {
                                jouer_music(valise->travaux);
                                cases[i][j].type_cases = 3;
                                cases[i+1][j].type_cases = 2;
                                cases[i-1][j].type_cases = 2;
                                cases[i][j+1].type_cases = 2;
                                cases[i][j-1].type_cases = 2;

                                cases[i+1][j+1].type_cases = 2;
                                cases[i-1][j-1].type_cases = 2;
                                cases[i-1][j+1].type_cases = 2;
                                cases[i+1][j-1].type_cases = 2;

                                mairie->bully_flouz-=mairie->cout_terrainV;
                                valise->nb_bat+=1;
                            }
                        }
                    }
                }
                else
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        stretch_sprite(valise->double_buffer,valise->bat_nope,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);
                    }
                }
                ///SUPPRESSION D'UN BATIMENT
                if(cases[i][j].type_cases == 3)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(key[KEY_SPACE])
                        {
                            stretch_sprite(valise->double_buffer,valise->cancel,cases[i][j].pos_x-41,cases[i][j].pos_y-17,SCREEN_W/12,SCREEN_H/11);

                            if(mouse_b & 1)
                            {
                                cases[i][j].type_cases = 0;
                                cases[i+1][j].type_cases = 0;
                                cases[i-1][j].type_cases = 0;
                                cases[i][j+1].type_cases = 0;
                                cases[i][j-1].type_cases = 0;

                                cases[i+1][j+1].type_cases = 0;
                                cases[i-1][j-1].type_cases = 0;
                                cases[i-1][j+1].type_cases = 0;
                                cases[i+1][j-1].type_cases = 0;
                                valise->nb_bat-=1;
                                mairie->bully_flouz+=1000;

                                if(cases[i][j].avancement == 1)
                                {
                                    mairie->nb_habitants-=10;
                                }
                                if(cases[i][j].avancement == 2)
                                {
                                    mairie->nb_habitants-=50;
                                }
                                if(cases[i][j].avancement == 3)
                                {
                                    mairie->nb_habitants-=100;
                                }
                                if(cases[i][j].avancement == 4)
                                {
                                    mairie->nb_habitants-=1000;
                                }
                                rest(100);
                            }
                        }
                    }
                }
            }
        }
    }
}

void evolution_batiment(t_valise valise, t_cases cases[35][45], t_mairie* mairie)
{
    if((valise.nb_centrales_eau>0) && (valise.nb_centrales_elec))
    {
        for(int i=0; i<35; i++)
        {
            for(int j=0; j<45; j++)
            {
                if(cases[i][j].type_cases == 3)
                {
                    if(cases[i][j].avancement==0 && valise.seconde == 15)
                    {
                        cases[i][j].avancement = 1;
                        mairie->nb_habitants += 10;
                    }
                    if(cases[i][j].avancement==1 && valise.seconde == 30)
                    {
                        cases[i][j].avancement = 2;
                        mairie->nb_habitants += 40;
                    }
                    if(cases[i][j].avancement==2 && valise.seconde == 45)
                    {
                        cases[i][j].avancement = 3;
                        mairie->nb_habitants += 50;
                    }
                    if(cases[i][j].avancement==3 && valise.seconde == 0)
                    {
                        cases[i][j].avancement = 4;
                        mairie->nb_habitants += 900;
                    }
                }
            }
        }
    }
}

void impots(t_valise* valise, t_mairie* mairie)
{
    if(valise->seconde == 15 && valise->safe_impot == 1)
    {
        mairie->bully_flouz += (10*mairie->nb_habitants);
        valise->safe_impot = 2;
    }
    if(valise->seconde == 30 && valise->safe_impot == 2)
    {
        mairie->bully_flouz += (10*mairie->nb_habitants);
        valise->safe_impot = 3;
    }
    if(valise->seconde == 45 && valise->safe_impot == 3)
    {
        mairie->bully_flouz += (10*mairie->nb_habitants);
        valise->safe_impot = 4;
    }
    if(valise->seconde == 0 && valise->safe_impot == 4)
    {
        mairie->bully_flouz += (10*mairie->nb_habitants);
        valise->safe_impot = 1;
    }
}

void creation_centraleElec(t_valise* valise, t_mairie* mairie, t_cases cases[35][45])
{
    if(valise->nb_centrales_elec==0)
    {
        stretch_sprite(valise->double_buffer,valise->tuto_elec,1020,380,SCREEN_W/4,SCREEN_H/2);
        if(valise->nb_route_casse>0)
        {
            stretch_sprite(valise->double_buffer,valise->tuto_route,1020,380,SCREEN_W/4,SCREEN_H/2);
            stretch_sprite(valise->double_buffer,valise->fleche,415,115,SCREEN_W/16,SCREEN_H/16);
        }
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            if(valise->nb_routes==0)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->CE_nope,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);
                }
            }
            else if (valise->nb_centrales_elec==0)
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j].numero_ligne==2)
                        && (cases[i][j+1].type_cases==0 && cases[i][j-1].type_cases==0 && cases[i][j+2].type_cases==0 && cases[i][j-2].type_cases==0 && cases[i][j+3].type_cases==0))
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(cases[i+2][j].type_cases==1)
                        {
                            stretch_sprite(valise->double_buffer,valise->CE_yes,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);
                            if(mouse_b & 1)
                            {
                                jouer_music(valise->zap);
                                cases[i][j].type_cases = 10;
                                cases[i+1][j].type_cases = 11;
                                cases[i-1][j].type_cases = 11;
                                cases[i][j+1].type_cases = 11;
                                cases[i][j-1].type_cases = 11;

                                cases[i+1][j+1].type_cases = 11;
                                cases[i-1][j-1].type_cases = 11;
                                cases[i-1][j+1].type_cases = 11;
                                cases[i+1][j-1].type_cases = 11;

                                cases[i+1][j-2].type_cases = 11;
                                cases[i][j-2].type_cases = 11;
                                cases[i-1][j-2].type_cases = 11;
                                cases[i-2][j-2].type_cases = 11;

                                cases[i+1][j+2].type_cases = 11;
                                cases[i][j+2].type_cases = 11;
                                cases[i-1][j+2].type_cases = 11;
                                cases[i-2][j+2].type_cases = 11;

                                cases[i+1][j+3].type_cases = 11;
                                cases[i][j+3].type_cases = 11;
                                cases[i-1][j+3].type_cases = 11;
                                cases[i-2][j+3].type_cases = 11;

                                cases[i-2][j-1].type_cases = 11;
                                cases[i-2][j].type_cases = 11;
                                cases[i-2][j+1].type_cases = 11;

                                mairie->bully_flouz-=mairie->cout_centrale;
                                valise->nb_centrales_elec+=1;
                                mairie->capa_tot_elec+=mairie->capacite_CE;
                            }
                        }
                    }

                }
            }
            else if (valise->nb_centrales_elec>0)
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j].numero_ligne==2) && (cases[i][j+1].type_cases==0 && cases[i][j-1].type_cases==0
                        && cases[i][j+2].type_cases==0 && cases[i][j-2].type_cases==0 && cases[i][j+3].type_cases==0) && cases[i+2][j].type_cases==1)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(mairie->bully_flouz<100000)
                        {
                            stretch_sprite(valise->double_buffer,valise->CE_nope,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);
                            textprintf_ex(valise->double_buffer,font,750,300,makecol(255,0,0),-1,"T'AS PAS DE THUNE CA VA TE BULLY TOI !");
                        }
                        if(mairie->bully_flouz>=100000)
                        {
                            stretch_sprite(valise->double_buffer,valise->CE_yes,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);

                            if(mouse_b & 1)
                            {
                                jouer_music(valise->zap);
                                cases[i][j].type_cases = 10;
                                cases[i+1][j].type_cases = 11;
                                cases[i-1][j].type_cases = 11;
                                cases[i][j+1].type_cases = 11;
                                cases[i][j-1].type_cases = 11;

                                cases[i+1][j+1].type_cases = 11;
                                cases[i-1][j-1].type_cases = 11;
                                cases[i-1][j+1].type_cases = 11;
                                cases[i+1][j-1].type_cases = 11;

                                cases[i+1][j-2].type_cases = 11;
                                cases[i][j-2].type_cases = 11;
                                cases[i-1][j-2].type_cases = 11;
                                cases[i-2][j-2].type_cases = 11;

                                cases[i+1][j+2].type_cases = 11;
                                cases[i][j+2].type_cases = 11;
                                cases[i-1][j+2].type_cases = 11;
                                cases[i-2][j+2].type_cases = 11;

                                cases[i+1][j+3].type_cases = 11;
                                cases[i][j+3].type_cases = 11;
                                cases[i-1][j+3].type_cases = 11;
                                cases[i-2][j+3].type_cases = 11;

                                cases[i-2][j-1].type_cases = 11;
                                cases[i-2][j].type_cases = 11;
                                cases[i-2][j+1].type_cases = 11;

                                mairie->bully_flouz-=mairie->cout_centrale;
                                valise->nb_centrales_elec+=1;
                                mairie->capa_tot_elec+=mairie->capacite_CE;
                            }
                        }
                    }
                }
                else
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        stretch_sprite(valise->double_buffer,valise->CE_nope,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);
                    }
                }
                ///SUPPRESSION D'UNE CENTRALE ELECTRIQUE :
                if(cases[i][j].type_cases == 10)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(key[KEY_SPACE])
                        {
                            stretch_sprite(valise->double_buffer,valise->CE_cancel,cases[i][j].pos_x-48,cases[i][j].pos_y-27,SCREEN_W/8.6,SCREEN_H/12);

                            if(mouse_b & 1)
                            {
                                cases[i][j].type_cases = 0;
                                cases[i+1][j].type_cases = 0;
                                cases[i-1][j].type_cases = 0;
                                cases[i][j+1].type_cases = 0;
                                cases[i][j-1].type_cases = 0;

                                cases[i+1][j+1].type_cases = 0;
                                cases[i-1][j-1].type_cases = 0;
                                cases[i-1][j+1].type_cases = 0;
                                cases[i+1][j-1].type_cases = 0;

                                cases[i+1][j-2].type_cases = 0;
                                cases[i][j-2].type_cases = 0;
                                cases[i-1][j-2].type_cases = 0;
                                cases[i-2][j-2].type_cases = 0;

                                cases[i+1][j+2].type_cases = 0;
                                cases[i][j+2].type_cases = 0;
                                cases[i-1][j+2].type_cases = 0;
                                cases[i-2][j+2].type_cases = 0;

                                cases[i+1][j+3].type_cases = 0;
                                cases[i][j+3].type_cases = 0;
                                cases[i-1][j+3].type_cases = 0;
                                cases[i-2][j+3].type_cases = 0;

                                cases[i-2][j-1].type_cases = 0;
                                cases[i-2][j].type_cases = 0;
                                cases[i-2][j+1].type_cases = 0;

                                mairie->bully_flouz+=50000;
                                valise->nb_centrales_elec-=1;
                                mairie->capa_tot_elec-=mairie->capacite_CE;
                                rest(100);
                            }
                        }
                    }
                }
            }
        }
    }
}

void creation_centraleEau(t_valise* valise, t_mairie* mairie, t_cases cases[35][45])
{
    if(valise->nb_centrales_eau==0)
    {
        stretch_sprite(valise->double_buffer,valise->tuto_eau,1020,380,SCREEN_W/4,SCREEN_H/2);
        if(valise->nb_route_casse>0)
        {
            stretch_sprite(valise->double_buffer,valise->tuto_route,1020,380,SCREEN_W/4,SCREEN_H/2);
            stretch_sprite(valise->double_buffer,valise->fleche,415,115,SCREEN_W/16,SCREEN_H/16);
        }
    }
    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {
            if(valise->nb_routes==0)
            {
                if(is_in_case(cases[i][j])==1)
                {
                    stretch_sprite(valise->double_buffer,valise->CDO_nope,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);
                }
            }
            else if (valise->nb_centrales_eau==0)
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j].numero_colonne==2)
                        && (cases[i+1][j].type_cases==0 && cases[i+2][j].type_cases==0 && cases[i-1][j].type_cases==0 && cases[i-2][j].type_cases==0 && cases[i-3][j].type_cases==0))
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(cases[i][j+2].type_cases==1)
                        {
                            stretch_sprite(valise->double_buffer,valise->CDO_yes,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);
                            if(mouse_b & 1)
                            {
                                jouer_music(valise->eau);
                                cases[i][j].type_cases = 12;
                                cases[i+1][j].type_cases = 13;
                                cases[i-1][j].type_cases = 13;
                                cases[i][j+1].type_cases = 13;
                                cases[i][j-1].type_cases = 13;

                                cases[i+1][j+1].type_cases = 13;
                                cases[i-1][j-1].type_cases = 13;
                                cases[i-1][j+1].type_cases = 13;
                                cases[i+1][j-1].type_cases = 13;

                                cases[i+1][j-2].type_cases = 13;
                                cases[i][j-2].type_cases = 13;
                                cases[i-1][j-2].type_cases = 13;
                                cases[i-2][j-2].type_cases = 13;
                                cases[i-3][j-2].type_cases = 13;
                                cases[i+2][j-2].type_cases = 13;

                                cases[i+2][j].type_cases = 13;
                                cases[i-2][j].type_cases = 13;
                                cases[i-3][j].type_cases = 13;
                                cases[i-2][j+1].type_cases = 13;
                                cases[i-3][j+1].type_cases = 13;
                                cases[i+2][j+1].type_cases = 13;

                                cases[i+2][j-1].type_cases = 13;
                                cases[i-2][j-1].type_cases = 13;
                                cases[i-3][j-1].type_cases = 13;

                                mairie->bully_flouz-=mairie->cout_centrale;
                                valise->nb_centrales_eau+=1;
                                mairie->capa_tot_eau+=mairie->capacite_CDO;
                            }
                        }
                    }

                }
            }
            else if (valise->nb_centrales_eau>0)
            {
                if(cases[i][j].type_cases == 0 && (cases[i][j].numero_colonne==2) && (cases[i-1][j].type_cases==0 && cases[i-2][j].type_cases==0
                        && cases[i-3][j].type_cases==0 && cases[i+1][j].type_cases==0 && cases[i+2][j].type_cases==0) && cases[i][j+2].type_cases==1)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(mairie->bully_flouz<100000)
                        {
                            stretch_sprite(valise->double_buffer,valise->CDO_nope,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);
                            textprintf_ex(valise->double_buffer,font,750,300,makecol(255,0,0),-1,"T'AS PAS DE THUNE CA VA TE BULLY TOI !");
                        }
                        if(mairie->bully_flouz>=100000)
                        {
                            stretch_sprite(valise->double_buffer,valise->CDO_yes,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);

                            if(mouse_b & 1)
                            {
                                jouer_music(valise->eau);
                                cases[i][j].type_cases = 12;
                                cases[i+1][j].type_cases = 13;
                                cases[i-1][j].type_cases = 13;
                                cases[i][j+1].type_cases = 13;
                                cases[i][j-1].type_cases = 13;

                                cases[i+1][j+1].type_cases = 13;
                                cases[i-1][j-1].type_cases = 13;
                                cases[i-1][j+1].type_cases = 13;
                                cases[i+1][j-1].type_cases = 13;

                                cases[i+1][j-2].type_cases = 13;
                                cases[i][j-2].type_cases = 13;
                                cases[i-1][j-2].type_cases = 13;
                                cases[i-2][j-2].type_cases = 13;
                                cases[i-3][j-2].type_cases = 13;
                                cases[i+2][j-2].type_cases = 13;

                                cases[i+2][j].type_cases = 13;
                                cases[i-2][j].type_cases = 13;
                                cases[i-3][j].type_cases = 13;
                                cases[i-2][j+1].type_cases = 13;
                                cases[i-3][j+1].type_cases = 13;
                                cases[i+2][j+1].type_cases = 13;

                                cases[i+2][j-1].type_cases = 13;
                                cases[i-2][j-1].type_cases = 13;
                                cases[i-3][j-1].type_cases = 13;

                                mairie->bully_flouz-=mairie->cout_centrale;
                                valise->nb_centrales_eau+=1;
                                mairie->capa_tot_eau+=mairie->capacite_CDO;
                            }
                        }
                    }
                }
                else
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        stretch_sprite(valise->double_buffer,valise->CDO_nope,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);
                    }
                }
                ///SUPPRESSION D'UN CHATEAU D'EAU :
                if(cases[i][j].type_cases == 12)
                {
                    if(is_in_case(cases[i][j])==1)
                    {
                        if(key[KEY_SPACE])
                        {
                            stretch_sprite(valise->double_buffer,valise->CDO_cancel,cases[i][j].pos_x-65,cases[i][j].pos_y-34,SCREEN_W/8.6,SCREEN_H/12);

                            if(mouse_b & 1)
                            {
                                cases[i][j].type_cases = 0;
                                cases[i+1][j].type_cases = 0;
                                cases[i-1][j].type_cases = 0;
                                cases[i][j+1].type_cases = 0;
                                cases[i][j-1].type_cases = 0;

                                cases[i+1][j+1].type_cases = 0;
                                cases[i-1][j-1].type_cases = 0;
                                cases[i-1][j+1].type_cases = 0;
                                cases[i+1][j-1].type_cases = 0;

                                cases[i+1][j-2].type_cases = 0;
                                cases[i][j-2].type_cases = 0;
                                cases[i-1][j-2].type_cases = 0;
                                cases[i-2][j-2].type_cases = 0;
                                cases[i-3][j-2].type_cases = 0;
                                cases[i+2][j-2].type_cases = 0;

                                cases[i+2][j].type_cases = 0;
                                cases[i-2][j].type_cases = 0;
                                cases[i-3][j].type_cases = 0;
                                cases[i-2][j+1].type_cases = 0;
                                cases[i-3][j+1].type_cases = 0;
                                cases[i+2][j+1].type_cases = 0;

                                cases[i+2][j-1].type_cases = 0;
                                cases[i-2][j-1].type_cases = 0;
                                cases[i-3][j-1].type_cases = 0;

                                mairie->bully_flouz+=50000;
                                valise->nb_centrales_eau-=1;
                                mairie->capa_tot_eau-=mairie->capacite_CDO;
                                rest(100);
                            }
                        }
                    }
                }
            }
        }
    }
}

void affichage_reseau(t_valise* valise, t_cases cases[35][45])
{
    for(int i=0; i<35; i++)
    {

        for(int j=0; j<45; j++)
        {
            if(cases[i][j].type_cases!=1 && cases[i][j].type_cases!=10 && cases[i][j].type_cases!=11 && cases[i][j].type_cases!=3
                    && cases[i][j].type_cases!=2 && cases[i][j].type_cases!=12 && cases[i][j].type_cases!=13)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_eau,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_elec,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==1)
            {
                if(valise->etage==1)
                {
                    if(valise->nb_centrales_eau>0)
                    {
                        if((cases[i][j+1].type_cases==1 || cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases!=1 || cases[i+1][j].type_cases!=1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_eau2,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                           SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                        else if ((cases[i-1][j].type_cases==1 || cases[i+1][j].type_cases==1) && (cases[i][j+1].type_cases!=1 || cases[i][j-1].type_cases!=1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_eau1,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                           SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                        else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases==1))||(valise->nb_routes == 1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_eau3,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                    }
                    else
                    {
                        stretch_sprite(valise->double_buffer,valise->case_grise_eau,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }
                }
                if(valise->etage==2)
                {
                    if(valise->nb_centrales_elec>0)
                    {
                        if((cases[i][j+1].type_cases==1 || cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases!=1 || cases[i+1][j].type_cases!=1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_elec2,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                           SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                        else if ((cases[i-1][j].type_cases==1 || cases[i+1][j].type_cases==1) && (cases[i][j+1].type_cases!=1 || cases[i][j-1].type_cases!=1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_elec1,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                           SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                        else if(((cases[i][j+1].type_cases==1) && (cases[i][j-1].type_cases==1) && (cases[i-1][j].type_cases==1) && (cases[i+1][j].type_cases==1))||(valise->nb_routes == 1))
                        {
                            stretch_sprite(valise->double_buffer,valise->reseau_elec3,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y, SCREEN_W/valise->div,SCREEN_H/valise->div);
                        }
                    }
                    else
                    {
                        stretch_sprite(valise->double_buffer,valise->case_grise_elec,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }

                }
            }
            else if(cases[i][j].type_cases==3)
            {
                if(valise->etage==1)
                {
                    if((valise->nb_centrales_eau>0) &&
                            (cases[i+2][j].type_cases==1 || cases[i-2][j].type_cases==1 || cases[i][j+2].type_cases==1 || cases[i][j-2].type_cases==1))
                    {
                        stretch_sprite(valise->double_buffer,valise->bullydingIrrig,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }
                    else
                    {
                        stretch_sprite(valise->double_buffer,valise->case_griseClair,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }
                }
                if(valise->etage==2)
                {
                    if(valise->nb_centrales_elec>0 &&
                            (cases[i+2][j].type_cases==1 || cases[i-2][j].type_cases==1 || cases[i][j+2].type_cases==1 || cases[i][j-2].type_cases==1))
                    {
                        stretch_sprite(valise->double_buffer,valise->bullydingLuz,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }
                    else
                    {
                        stretch_sprite(valise->double_buffer,valise->case_griseClair,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                       SCREEN_W/valise->div,SCREEN_H/valise->div);
                    }
                }
            }
            else if(cases[i][j].type_cases==2)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->case_griseClair,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->case_griseClair,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==10)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_eau,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->source_elec,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==11)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_eau,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->CE_2,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==12)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->source_eau,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_elec,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            else if(cases[i][j].type_cases==13)
            {
                if(valise->etage==1)
                {
                    stretch_sprite(valise->double_buffer,valise->CDO_1,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
                if(valise->etage==2)
                {
                    stretch_sprite(valise->double_buffer,valise->case_grise_elec,valise->pos_x+valise->ajout_x,valise->pos_y+valise->ajout_y,
                                   SCREEN_W/valise->div,SCREEN_H/valise->div);
                }
            }
            valise->ajout_x+=DIAG_X/2;
            valise->ajout_y+=DIAG_Y/2;
        }
        valise->ajout_x=0;
        valise->ajout_y=0;
        valise->pos_x-=DIAG_X/2;
        valise->pos_y+=DIAG_Y/2;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// SAUVEGARDE ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sauvegarde(t_cases cases[35][45])
{

    FILE* fp= fopen("save/fichiersauvegarde.txt","w");

    fprintf(fp,"\n\n");

    for(int i=0; i<35; i++)
    {
        for(int j=0; j<45; j++)
        {

            fprintf(fp, " %d", cases[i][j].type_cases);


        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void sauvegarde2(t_mairie* mairie, t_valise* valise)
{
    FILE* fp1= fopen("save/fichiersauvegarde2.txt","w");

    fprintf(fp1,"\n%d\n",valise->nb_routes);
    fprintf(fp1,"%ld\n",mairie->bully_flouz);
    fprintf(fp1,"%ld\n",mairie->nb_habitants);
    fprintf(fp1,"%ld\n",mairie->capa_tot_elec);
    fprintf(fp1,"%ld\n",mairie->capa_tot_eau);
}

void liresauvegarde2(t_valise* valise, t_mairie* mairie)
{
    FILE* fp1= fopen("save/fichiersauvegarde2.txt","r");
    fscanf(fp1,"%d",&valise->nb_routes);
    fscanf(fp1,"%ld",&mairie->bully_flouz);
    fclose(fp1);

}

void chargmentsauv(t_valise* valise)
{
    valise->fic = fopen("save/fichiersauvegarde.txt", "r");


    /// CREATION DU DOUBLE BUFFER :
    valise->double_buffer = create_bitmap(SCREEN_W,SCREEN_H);

    /// UPLOAD DE LA MUSIQUE :
    valise->music_1= load_wav("../musique/newyork1.wav");
    valise->eau= load_wav("../musique/eau.wav");
    valise->zap= load_wav("../musique/zap.wav");
    valise->travaux= load_wav("../musique/travaux.wav");
    valise->boiteao= load_wav("../musique/bao.wav");


    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES ROUTES :
    valise->route = load_bitmap("../images/constructions/routes/route.bmp", NULL);
    valise->route2 = load_bitmap("../images/constructions/routes/route2.bmp", NULL);
    valise->carrefour = load_bitmap("../images/constructions/routes/carrefour.bmp", NULL);
    valise->virageB = load_bitmap("../images/constructions/routes/virage_bas.bmp", NULL);
    valise->virageH = load_bitmap("../images/constructions/routes/virage_haut.bmp", NULL);
    valise->virageG = load_bitmap("../images/constructions/routes/virage_gauche.bmp", NULL);
    valise->virageD = load_bitmap("../images/constructions/routes/virage_droite.bmp", NULL);
    valise->route_casse = load_bitmap("../images/constructions/routes/route_casse.bmp", NULL);
    valise->stopB = load_bitmap("../images/constructions/routes/stop_bas.bmp", NULL);
    valise->stopH = load_bitmap("../images/constructions/routes/stop_haut.bmp", NULL);
    valise->stopG = load_bitmap("../images/constructions/routes/stop_gauche.bmp", NULL);
    valise->stopD = load_bitmap("../images/constructions/routes/stop_droite.bmp", NULL);
    valise->pont = load_bitmap("../images/constructions/routes/pont.bmp", NULL);

    /// DIFFERENTS SPRITES DE SLECTION (EX: CASE VERTE SI L'EMPLACEMENT EST POSSIBLE ET ROUGE SINON) :
    valise->curseur = load_bitmap("../images/objets/curseur.bmp", NULL);
    valise->bat_okey = load_bitmap("../images/map/cases_verte.bmp", NULL);
    valise->bat_nope = load_bitmap("../images/map/bat_nope.bmp", NULL);
    valise->cancel = load_bitmap("../images/map/cancel.bmp", NULL);
    valise->case_okey = load_bitmap("../images/constructions/routes/pre_route.bmp", NULL);
    valise->CE_nope = load_bitmap("../images/map/CE_nope.bmp", NULL);
    valise->CE_yes = load_bitmap("../images/map/CE_yes.bmp", NULL);
    valise->CE_cancel = load_bitmap("../images/map/CE_cancel.bmp", NULL);
    valise->CDO_nope = load_bitmap("../images/map/CDO_nope.bmp", NULL);
    valise->CDO_yes = load_bitmap("../images/map/CDO_yes.bmp", NULL);
    valise->CDO_cancel = load_bitmap("../images/map/CDO_cancel.bmp", NULL);
    valise->filtre = load_bitmap("../images/map/filtre.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES RESEAU ELECTRIQUES ET D'EAU :
    valise->reseau_eau1 = load_bitmap("../images/constructions/centrales_eau/reseau_eau1.bmp", NULL);
    valise->reseau_eau2 = load_bitmap("../images/constructions/centrales_eau/reseau_eau2.bmp", NULL);
    valise->reseau_eau3 = load_bitmap("../images/constructions/centrales_eau/reseau_eau3.bmp", NULL);
    valise->reseau_elec1 = load_bitmap("../images/constructions/centrales_elec/reseau_elec1.bmp", NULL);
    valise->reseau_elec2 = load_bitmap("../images/constructions/centrales_elec/reseau_elec2.bmp", NULL);
    valise->reseau_elec3 = load_bitmap("../images/constructions/centrales_elec/reseau_elec3.bmp", NULL);
    valise->centraleElec = load_bitmap("../images/constructions/centrales_elec/centraleElec.bmp", NULL);
    valise->centraleEau = load_bitmap("../images/constructions/centrales_eau/centraleEau.bmp", NULL);
    valise->bullydingIrrig = load_bitmap("../images/constructions/centrales_eau/bullyding_irrigue.bmp", NULL);
    valise->bullydingLuz = load_bitmap("../images/constructions/centrales_elec/bullyding_irrigue.bmp", NULL);
    valise->case_grise_eau = load_bitmap("../images/constructions/centrales_eau/case_grise.bmp", NULL);
    valise->case_grise_elec = load_bitmap("../images/constructions/centrales_elec/case_grise.bmp", NULL);
    valise->case_griseClair = load_bitmap("../images/constructions/centrales_eau/case_griseClaire.bmp", NULL);
    valise->CDO_1 = load_bitmap("../images/constructions/centrales_eau/CDO_1.bmp", NULL);
    valise->source_eau = load_bitmap("../images/constructions/centrales_eau/source_eau.bmp", NULL);
    valise->CE_2 = load_bitmap("../images/constructions/centrales_elec/CE_2.bmp", NULL);
    valise->source_elec = load_bitmap("../images/constructions/centrales_elec/source_elec.bmp", NULL);


    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DE LA BOITE A OUTILS :
    valise->bao_ouv = load_bitmap("../images/boite_a_outils/bao_ouv.bmp",NULL);
    valise->bao_fer = load_bitmap("../images/boite_a_outils/bao_fer.bmp",NULL);
    valise->rond_0 = load_bitmap("../images/boite_a_outils/rond_0.bmp",NULL);
    valise->rond_1 = load_bitmap("../images/boite_a_outils/rond_1.bmp",NULL);
    valise->rond_2 = load_bitmap("../images/boite_a_outils/rond_2.bmp",NULL);
    valise->croute = load_bitmap("../images/boite_a_outils/croute.bmp",NULL);
    valise->croute2 = load_bitmap("../images/boite_a_outils/croute2.bmp",NULL);
    valise->cmaison = load_bitmap("../images/boite_a_outils/cmaison.bmp",NULL);
    valise->cmaison2 = load_bitmap("../images/boite_a_outils/cmaison2.bmp",NULL);
    valise->cwattank = load_bitmap("../images/boite_a_outils/ccentrale.bmp",NULL);
    valise->cwattank2 = load_bitmap("../images/boite_a_outils/ccentrale2.bmp",NULL);
    valise->centrale = load_bitmap("../images/boite_a_outils/cwattank.bmp",NULL);
    valise->centrale2 = load_bitmap("../images/boite_a_outils/cwattank2.bmp",NULL);
    valise->coins2_vide = load_bitmap("../images/boite_a_outils/coins2_vide.bmp", NULL);
    valise->coins2_middle = load_bitmap("../images/boite_a_outils/coins2_middle.bmp", NULL);
    valise->coins2_pleine = load_bitmap("../images/boite_a_outils/coins2_pleine.bmp", NULL);
    valise->reserve_eau_vide = load_bitmap("../images/boite_a_outils/reserve_eau_vide.bmp", NULL);
    valise->reserve_eau_middle = load_bitmap("../images/boite_a_outils/reserve_eau_middle.bmp", NULL);
    valise->reserve_eau_pleine = load_bitmap("../images/boite_a_outils/reserve_eau_pleine.bmp", NULL);
    valise->reserve_elec_vide = load_bitmap("../images/boite_a_outils/reserve_elec_vide.bmp", NULL);
    valise->reserve_elec_middle = load_bitmap("../images/boite_a_outils/reserve_elec_middle.bmp", NULL);
    valise->reserve_elec_pleine = load_bitmap("../images/boite_a_outils/reserve_elec_pleine.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DES BATIMENTS :
    valise->chantier = load_bitmap("../images/constructions/batiments/chantier.bmp", NULL);
    valise->grue = load_bitmap("../images/constructions/batiments/grue.bmp", NULL);
    valise->cabane = load_bitmap("../images/constructions/batiments/cabane.bmp", NULL);
    valise->maison = load_bitmap("../images/constructions/batiments/maison.bmp", NULL);
    valise->bullyding = load_bitmap("../images/constructions/batiments/bullyding.bmp", NULL);
    valise->skyscrap = load_bitmap("../images/constructions/batiments/skyscrapper.bmp", NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DE LA MAP EN GENERAL :
    valise->plateforme = load_bitmap("../images/map/neige.bmp",NULL);

    /// DIFFERENTS SPRITES POUR L'AFFICHAGE DU MENU PRINCIPAL :
    valise->bouton1 = load_bitmap("../images/bouton_menu/bouton1.bmp",NULL);
    valise->bouton2 = load_bitmap("../images/bouton_menu/bouton2.bmp",NULL);
    valise->bouton3 = load_bitmap("../images/bouton_menu/bouton3.bmp",NULL);
    valise->bouton4 = load_bitmap("../images/bouton_menu/bouton4.bmp",NULL);
    valise->bouton5 = load_bitmap("../images/bouton_menu/bouton5.bmp",NULL);
    valise->bouton6 = load_bitmap("../images/bouton_menu/bouton6.bmp",NULL);
    valise->bouton7 = load_bitmap("../images/bouton_menu/bouton7.bmp",NULL);
    valise->bouton8 = load_bitmap("../images/bouton_menu/bouton8.bmp",NULL);
    valise->boutonpause = load_bitmap("../images/bouton_menu/bouton_pause.bmp",NULL);
    valise->titre=load_bitmap("../images/cinematiques/fond_menu/titre.bmp",NULL);
    valise->bouton8 = load_bitmap("../images/bouton_menu/bouton9.bmp",NULL);


/// ------------------------------------------------------------- INITIALISATION DES DIFFERENTES VARIABLES ----------------------------------------------------------

    /// VARIABLES NECESSAIRS AU MENU :
    valise->lancer=0;
    valise->lancer1=0;
    valise->lancer2=0;
    valise->lancer3=0;
    valise->lancer4=0;
    valise->lancer5=0;
    valise->lancerpause=0;
    valise->choix_menu=0;

    ///TIMER :
    valise->timer = 0;
    valise->seconde=0;
    valise->heure = 0;

    ///IMPOTS :
    valise->safe_impot = 1;

    /// VARIABLES NECESSAIRS A LA BOITE A OUTILS :
    valise->outil = 0;
    valise->etage = 0;
    valise->ouverture=0;
    valise->clic_1=1;
    valise->clic_2=0;
    valise->clic_3=0;
    valise->clic_4=0;
    valise->clic_5=0;
    valise->clic_6=0;
    valise->clic_7=0;


    /// VARIABLES D'OCCURENCE DES DIFFERENTES INFRASTRUCTURES :
    valise->nb_routes = 0;
    valise->nb_route_casse = 25;
    valise->nb_centrales_eau=0;
    valise->nb_centrales_elec=0;
    valise->nb_bat=0;

    /// VARIABLES CONCERNANT LES POSITIONS ET L'AFFICHAGE DES CASES :
    valise->ajout_x=0;
    valise->ajout_y=0;
    valise->pos_x=600;
    valise->pos_y=75;
    valise->pos_x_centre=valise->pos_x+DIAG_X/2;
    valise->pos_y_centre=valise->pos_y+DIAG_Y/2;
    valise->div=38;

    /// EXTRACTION DES BITMAPS POUR L'AFFICHAGE DE L'ARRIERE PLAN DU MENU :
    for(int i=0; i<10; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework00%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    for(int i=10; i<100; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework0%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    for(int i=100; i<373; i++)
    {
        valise->fond_menu[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_fm,"../images/cinematiques/fond_menu/nework%d.bmp",i);
        valise->fond_menu[i]=load_bitmap(valise->nom_fm,NULL);
    }
    valise->occu_cine_2=0;

    /// EXTRACTION DES BITMAPS POUR L'AFFICHAGE DE L'INTRO :
    for(int i=0; i<116; i++)
    {
        valise->cine_1[i]=(BITMAP*)malloc(sizeof(BITMAP));
        sprintf(valise->nom_cine_1,"../images/cinematiques/ouverture/C%d.bmp",i);
        valise->cine_1[i]=load_bitmap(valise->nom_cine_1,NULL);
    }
    valise->cinetique=1;
    valise->occu_cine_1=2;

    valise->taille=0;
    valise->ordre=0;
    valise->poids=1;

    valise->nb_fichier_gh=0;
    valise->extra_graphe=0;

    valise->play=0;
    valise->play_eau=0;
    valise->play_bao=0;
    valise->play_zap=0;
    valise->play_wo=0;

    /// MENU PAUSE ET REGLES DU JEU :
    valise->pose = load_bitmap("../images/bouton_menu/PAUSE.bmp",NULL);
    valise->r1 = load_bitmap("../images/regles/R1.bmp",NULL);
    valise->r2 = load_bitmap("../images/regles/R2.bmp",NULL);
    valise->r3 = load_bitmap("../images/regles/R3.bmp",NULL);
    valise->r4 = load_bitmap("../images/regles/R4.bmp",NULL);
    valise->r5 = load_bitmap("../images/regles/R5.bmp",NULL);
    valise->r6 = load_bitmap("../images/regles/R6.bmp",NULL);
    valise->r7 = load_bitmap("../images/regles/R7.bmp",NULL);
    valise->rules=0;
    valise->fleched =load_bitmap("../images/regles/FLECHE_D.bmp",NULL);
    valise->flecheg = load_bitmap("../images/regles/FLECHE_G.bmp",NULL);
    valise->retour = load_bitmap("../images/regles/retour.bmp",NULL);
    valise->rul1=0;
    valise->rul2=0;
    valise->choixret=0;
    valise->tiempo =0;

}

void menu_pause(t_valise* valise,t_mairie* mairie, t_cases cases[35][45])
{

    if (valise->tiempo==0)
    {
        if(valise->lancerpause==0)
        {
            stretch_sprite(valise->double_buffer,valise->boutonpause,150,40,SCREEN_W/15-20,SCREEN_H/15);
        }

        if((pow(183-mouse_x,2))+(pow(66-mouse_y,2))<=pow(33,2))
        {
            stretch_sprite(valise->double_buffer,valise->boutonpause,148,39,SCREEN_W/13-20,SCREEN_H/13);

            if(mouse_b&1)
            {
                valise->lancerpause=1;
            }

        }
        if(valise->lancerpause==1)
        {
            stretch_sprite(valise->double_buffer,valise->fond,0,0,SCREEN_W,SCREEN_H);
            stretch_sprite(valise->double_buffer,valise->pose,78,50,SCREEN_W/3,SCREEN_H/20);
            if(valise->lancer==0)
            {
                stretch_sprite(valise->double_buffer,valise->bouton7,70,150,SCREEN_W/3,SCREEN_H/20);
            }
            if(valise->lancer1==0)
            {
                stretch_sprite(valise->double_buffer,valise->bouton8,70,210,SCREEN_W/3,SCREEN_H/20);
            }
            if(valise->lancer2==0)
            {
                stretch_sprite(valise->double_buffer,valise->bouton3,70,270,SCREEN_W/3,SCREEN_H/20);
            }
            if(valise->lancer3==0)
            {
                stretch_sprite(valise->double_buffer,valise->bouton4,70,330,SCREEN_W/3,SCREEN_H/20);
            }
            if(valise->lancer4==0)
            {
                stretch_sprite(valise->double_buffer,valise->bouton5,70,390,SCREEN_W/3,SCREEN_H/20);
            }

            if(((mouse_x>=70)&&(mouse_x<=539))&&((mouse_y>=150)&&(mouse_y<=189)))
            {
                valise->lancer=1;
                if(valise->lancer==1)
                {
                    stretch_sprite(valise->double_buffer,valise->bouton7,60,145,SCREEN_W/3+20,SCREEN_H/20+10);
                }
                if(mouse_b&1)
                {
                    valise->lancerpause=0;
                }
            }
            else
            {
                valise->lancer=0;
            }

            if(((mouse_x>=70)&&(mouse_x<=539))&&((mouse_y>=210)&&(mouse_y<=249)))
            {
                valise->lancer1=1;
                if(valise->lancer1==1)
                {
                    stretch_sprite(valise->double_buffer,valise->bouton8,60,205,SCREEN_W/3+20,SCREEN_H/20+10);
                }
                if(mouse_b&1)
                {
                    sauvegarde(cases);
                    sauvegarde2(mairie, valise);

                }
            }
            else
            {
                valise->lancer1=0;
            }


            if(((mouse_x>=70)&&(mouse_x<=539))&&((mouse_y>=270)&&(mouse_y<=309)))
            {
                valise->lancer2=1;
                if(valise->lancer2==1)
                {


                    stretch_sprite(valise->double_buffer,valise->bouton3,60,265,SCREEN_W/3+20,SCREEN_H/20+10);
                    if(mouse_b&1)
                    {
                        valise->rules =1;
                        valise->tiempo=1;
                    }
                }

            }
            else
            {
                valise->lancer2=0;
            }

            if(((mouse_x>=70)&&(mouse_x<=539))&&((mouse_y>=330)&&(mouse_y<=369)))
            {
                valise->lancer3=1;
                if(valise->lancer3==1)
                {
                    stretch_sprite(valise->double_buffer,valise->bouton4,60,325,SCREEN_W/3+20,SCREEN_H/20+10);
                }
            }
            else
            {
                valise->lancer3=0;
            }

            if(((mouse_x>=70)&&(mouse_x<=539))&&((mouse_y>=390)&&(mouse_y<=429)))
            {
                valise->lancer4=1;
                if(valise->lancer4==1)
                {
                    stretch_sprite(valise->double_buffer,valise->bouton5,60,385,SCREEN_W/3+20,SCREEN_H/20+10);
                }
                if(mouse_b&1)
                {
                    valise->lancerpause=0;
                    valise->choix_menu=0;
                }
            }
            else
            {
                valise->lancer4=0;
            }
        }
    }
    if (valise->tiempo==1)
    {
        reglespause(valise);
    }

}

int fichierON(t_valise* valise,t_mairie* mairie)
{
    printf("oui");
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL; //Déclaration d'un pointeur vers la structure dirent.
    rep = opendir("save");
    int nombrefichier=0;


    if (rep == NULL)
        exit(1);

    fichierLu = readdir(rep); /* On lit le premier répertoire du dossier. */
    while ((fichierLu = readdir(rep)) != NULL)
    {

        if(strcmp(fichierLu->d_name,".")!=0&&strcmp(fichierLu->d_name,"..")!=0)
        {
            //seekdir(rep,4);
            printf("Le fichier lu s'appelle '%s'\n", fichierLu->d_name);
            nombrefichier++;

        }
    }
    nombrefichier;
    printf("%d",nombrefichier);


    if(nombrefichier==0)
    {
        init_valise(valise);
    }
    else if(nombrefichier!=0)
    {
        liresauvegarde2(valise, mairie);
        chargmentsauv(valise);

    }
}

void reini()
{
    FILE* fp= fopen("save/fichiersauvegarde.txt","w");
    fprintf(fp,"\n\n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 6 6 6 6 6 6 6 6 6 1 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 1 6 6 6 6 6 6 6 6 6 6 6 6 \n 6 6 6 6 6 6 6 6 6 1 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 1 6 6 6 6 6 6 6 6 6 6 6 6 \n 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");
    fprintf(fp," 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n");

}

void reinii(t_mairie* mairie, t_valise* valise)
{
    FILE* fp1= fopen("save/fichiersauvegarde2.txt","w");

    fprintf(fp1,"\n0\n",valise->nb_routes);
    fprintf(fp1,"500000",mairie->bully_flouz);
    fprintf(fp1,"0\n",mairie->nb_habitants);
    fprintf(fp1,"0\n",mairie->capa_tot_elec);
    fprintf(fp1,"0\n",mairie->capa_tot_eau);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// CINEMATIQUE GRAPHIQUES ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cinematique_1(t_valise* valise)
{
    if(valise->occu_cine_1>=116)
    {
        printf("oui");
        rest(1000);
        valise->cinetique=1;
    }
    if(valise->occu_cine_1<116)
    {

        blit(valise->cine_1[valise->occu_cine_1],valise->double_buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        valise->occu_cine_1+=1;
        rest(100);
        printf("%d\n",valise->occu_cine_1);
    }

}

void cinematique_menu(t_valise* valise)
{
    if(valise->occu_cine_2<373)
    {
        stretch_blit(valise->fond_menu[valise->occu_cine_2],valise->double_buffer,0,0,
                     valise->fond_menu[valise->occu_cine_2]->w,valise->fond_menu[valise->occu_cine_2]->h,0,0,SCREEN_W,SCREEN_H);
        valise->occu_cine_2+=1;
        rest(15);
    }
    if(valise->occu_cine_2>=373)
    {
        valise->occu_cine_2=0;
        //rest(15);
    }
    stretch_sprite(valise->double_buffer,valise->titre,0,0,SCREEN_W,SCREEN_H);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// CHRONOMETRE /////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void compter(t_valise* valise)
{
    int tmp=0;
    int rest;
    tmp=(valise->timer++);
    valise->heure=tmp/3600;
    rest=tmp%3600;
    valise->seconde= rest/60;
    //textprintf(valise->double_buffer,font,30,70,makecol(255,255,255),"// %d : %d //",valise->heure,valise->seconde);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////// BOITE A OUTILS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////// BOITE A OUTILS ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void barre_a_outils(t_valise* valise)
{

    if(valise->ouverture==0)
    {
        stretch_sprite(valise->double_buffer,valise->bao_fer,34,711,SCREEN_W/15,SCREEN_H/11);
        if(valise->clic_7==1)
        {
            jouer_music(valise->boiteao);
            rest(100);
            valise->clic_7=0;
        }
        if(  (mouse_x> 35 && mouse_x<135) && (mouse_y > 713 && mouse_y <783) )
        {
            stretch_sprite(valise->double_buffer,valise->bao_fer,24,701,SCREEN_W/12,SCREEN_H/9);
            if(mouse_b&1)
            {
                valise->ouverture=1;
            }
        }
    }
    if(valise->ouverture==1)
    {
        stretch_sprite(valise->double_buffer,valise->bao_ouv,34,701,SCREEN_W/14,SCREEN_H/10);
        if(valise->clic_7==0)
        {
            jouer_music(valise->boiteao);
            rest(100);
            valise->clic_7=1;
        }
        if(  (mouse_x> 35 && mouse_x<135) && (mouse_y > 713 && mouse_y <783) )
        {
            stretch_sprite(valise->double_buffer,valise->bao_ouv,26,699,SCREEN_W/12,SCREEN_H/9);
            if(mouse_b&1)
            {

                valise->ouverture=0;
            }
        }
        if(valise->clic_1==0)
        {
            stretch_sprite(valise->double_buffer,valise->rond_0,170,715,SCREEN_W/13-40,SCREEN_H/13);
        }
        if(valise->clic_1==1)
        {
            stretch_sprite(valise->double_buffer,valise->rond_0,150,705,SCREEN_W/13,SCREEN_H/10);
        }
        if(valise->clic_2==0)
        {
            stretch_sprite(valise->double_buffer,valise->rond_1,250,711,SCREEN_W/13,SCREEN_H/10);
        }
        if(valise->clic_2==1)
        {
            stretch_sprite(valise->double_buffer,valise->rond_1,230,701,SCREEN_W/10,SCREEN_H/8);
        }
        if(valise->clic_3==0)
        {
            stretch_sprite(valise->double_buffer,valise->rond_2,385,711,SCREEN_W/16,SCREEN_H/11);
        }
        if(valise->clic_3==1)
        {
            stretch_sprite(valise->double_buffer,valise->rond_2,375,701,SCREEN_W/13,SCREEN_H/9);
        }
        stretch_sprite(valise->double_buffer,valise->croute,35,340,SCREEN_W/15,SCREEN_H/9);
        if(valise->outil==1)
        {
            stretch_sprite(valise->double_buffer,valise->croute2,35,340,SCREEN_W/15,SCREEN_H/9);
        }
        stretch_sprite(valise->double_buffer,valise->cmaison,15,420,SCREEN_W/10,SCREEN_H/7);
        if(valise->outil==2)
        {
            stretch_sprite(valise->double_buffer,valise->cmaison2,15,420,SCREEN_W/10,SCREEN_H/7);
        }
        stretch_sprite(valise->double_buffer,valise->centrale,25,615,SCREEN_W/12,SCREEN_H/10);
        if(valise->outil==4)
        {
            stretch_sprite(valise->double_buffer,valise->centrale2,25,615,SCREEN_W/12,SCREEN_H/10);
        }
        stretch_sprite(valise->double_buffer,valise->cwattank,25,528,SCREEN_W/12,SCREEN_H/10);
        if(valise->outil==3)
        {
            stretch_sprite(valise->double_buffer,valise->cwattank2,25,528,SCREEN_W/12,SCREEN_H/10);
        }
        if((pow(207-mouse_x,2))+(pow(738-mouse_y,2))<=pow(27,2))
        {
            stretch_sprite(valise->double_buffer,valise->rond_0,150,705,SCREEN_W/13,SCREEN_H/10);
            if(mouse_b&1)
            {
                rest(10);
                valise->clic_1=1;
                valise->clic_2=0;
                valise->clic_3=0;
                valise->etage = 0;
                //niveau_0;
            }
        }
        if( (mouse_x>272 && mouse_x <350  ) && ( mouse_y > 721 && mouse_y < 787) )
        {
            stretch_sprite(valise->double_buffer,valise->rond_1,230,701,SCREEN_W/10,SCREEN_H/8);

            if(mouse_b&1)
            {
                rest(10);
                valise->clic_1=0;
                valise->clic_2=1;
                valise->clic_3=0;
                valise->etage = 1; //niveau-1
            }
        }
        if((mouse_x > 389 && mouse_x < 471 ) && ( mouse_y >714 && mouse_x < 782))
        {
            stretch_sprite(valise->double_buffer,valise->rond_2,375,701,SCREEN_W/13,SCREEN_H/9);
            if(mouse_b&1)
            {
                rest(10);
                valise->clic_1=0;
                valise->clic_2=0;
                valise->clic_3=1;
                valise->etage = 2; //niv-2
            }
        }



        if( (mouse_x>=37 && mouse_x<=127)
                && (mouse_y>365 && mouse_y<412) )
        {
            if(valise->outil==1)
            {
                stretch_sprite(valise->double_buffer,valise->croute2,25,330,SCREEN_W/13,SCREEN_H/7);
            }
            if(valise->outil!=1)
            {
                stretch_sprite(valise->double_buffer,valise->croute,25,330,SCREEN_W/13,SCREEN_H/7);
            }
            if(valise->outil!=1 && mouse_b&1)
            {
                valise->outil = 1;
                rest(100);
            }
            if(valise->outil==1 && mouse_b&1)
            {
                valise->outil = 0;
                rest(100);  //routes
            }
        }
        if( (mouse_x>=50 && mouse_x<=112) && (mouse_y>420 && mouse_y<531))
        {
            if(valise->outil==2)
            {
                stretch_sprite(valise->double_buffer,valise->cmaison2,10,410,SCREEN_W/9,SCREEN_H/6);
            }
            if(valise->outil!=2)
            {
                stretch_sprite(valise->double_buffer,valise->cmaison,10,410,SCREEN_W/9,SCREEN_H/6);
            }
            if(valise->outil!=2 && mouse_b&1)
            {
                valise->outil = 2;
                rest(100);
            }
            if(valise->outil==2 && mouse_b&1)
            {
                valise->outil = 0;
                rest(100);  //Batiments
            }
        }

        if(( ((float)abs(mouse_x -82))/((float)56)+((float)abs(mouse_y -655))/((float)38) ) < (1.2) )
        {
            if(valise->outil==4)
            {
                stretch_sprite(valise->double_buffer,valise->centrale2,20,610,SCREEN_W/11,SCREEN_H/9);
            }
            if(valise->outil!=4)
            {
                stretch_sprite(valise->double_buffer,valise->centrale,20,610,SCREEN_W/11,SCREEN_H/9);
            }

            if(valise->outil!=4 && mouse_b&1)
            {
                valise->outil = 4;
                rest(100);
            }
            if(valise->outil==4 && mouse_b&1)
            {
                valise->outil = 0;
                rest(100);  //EAU
            }
        }

        if(( ((float)abs(mouse_x -82))/((float)58)+((float)abs(mouse_y -564))/((float)40) ) < (1.2) )
        {
            if(valise->outil==3)
            {
                stretch_sprite(valise->double_buffer,valise->cwattank2,20,523,SCREEN_W/11,SCREEN_H/9);
            }
            if(valise->outil!=3)
            {
                stretch_sprite(valise->double_buffer,valise->cwattank,20,523,SCREEN_W/11,SCREEN_H/9);
            }

            if(valise->outil!=3 && mouse_b&1)
            {
                valise->outil = 3;
                rest(100);
            }
            if(valise->outil==3 && mouse_b&1)
            {
                valise->outil = 0;
                rest(100);  //ELEC
            }
        }
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// SAVOIR SUR QUELLE CASE ON EST ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int is_in_case(t_cases cases)
{
    int difference_mx=0;
    int difference_my=0;
    float total;


    difference_mx = mouse_x - cases.pos_x_centre;
    difference_my = mouse_y - cases.pos_y_centre;

    difference_mx = abs(difference_mx);
    difference_my = abs(difference_my);
    total = (float)difference_mx/ (float)DIAG_X + (float)difference_my/(float)DIAG_Y;

    if(total  <(1./2) && (cases.type_cases!=6))
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// SAVOIR SUR QUELLE CASE ON EST ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu_principale(t_valise* valise)
{
    if(valise->lancer==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton1,890,340,SCREEN_W/3,SCREEN_H/20);
    }
    if(valise->lancer1==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton2,890,400,SCREEN_W/3,SCREEN_H/20);
    }
    if(valise->lancer5==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton9,890,460,SCREEN_W/3,SCREEN_H/20);
    }
    if(valise->lancer2==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton3,890,520,SCREEN_W/3,SCREEN_H/20);
    }
    if(valise->lancer3==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton4,890,580,SCREEN_W/3,SCREEN_H/20);
    }
    if(valise->lancer4==0)
    {
        stretch_sprite(valise->double_buffer,valise->bouton5,890,640,SCREEN_W/3,SCREEN_H/20);
    }

    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=340)&&(mouse_y<=379)))
    {
        valise->lancer=1;
        if(valise->lancer==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton1,880,335,SCREEN_W/3+20,SCREEN_H/20+10);
        }
        if(mouse_b&1)
        {
            valise->choix_menu=1;
            rest(100);
        }
    }
    else
    {
        valise->lancer=0;
    }
    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=400)&&(mouse_y<=439)))
    {
        valise->lancer1=1;
        if(valise->lancer1==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton2,880,395,SCREEN_W/3+20,SCREEN_H/20+10);
        }
    }
    else
    {
        valise->lancer1=0;
    }
    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=460)&&(mouse_y<=499)))
    {
        valise->lancer5=1;
        if(valise->lancer5==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton9,880,455,SCREEN_W/3+20,SCREEN_H/20+10);
        }
        if(mouse_b&1)
        {

            valise->choix_menu=5;
            rest(100);
        }
    }
    else
    {
        valise->lancer5=0;
    }

    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=520)&&(mouse_y<=559)))
    {
        valise->lancer2=1;
        if(valise->lancer2==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton3,880,515,SCREEN_W/3+20,SCREEN_H/20+10);
            if(mouse_b&1)
            {
                valise->rules =1;
                valise->choix_menu=3;
            }
        }
    }
    else
    {
        valise->lancer2=0;
    }

    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=580)&&(mouse_y<=609)))
    {
        valise->lancer3=1;
        if(valise->lancer3==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton4,880,575,SCREEN_W/3+20,SCREEN_H/20+10);
        }
    }
    else
    {
        valise->lancer3=0;
    }

    if(((mouse_x>=890)&&(mouse_x<=1239))&&((mouse_y>=635)&&(mouse_y<=674)))
    {
        valise->lancer4=1;
        if(valise->lancer4==1)
        {
            stretch_sprite(valise->double_buffer,valise->bouton5,880,635,SCREEN_W/3+20,SCREEN_H/20+10);
        }
    }
    else
    {
        valise->lancer4=0;
    }
}


void regles(t_valise* valise)
{
    valise->rul1=0;
    valise->rul2=0;
    valise->choixret=0;
    if (valise->rules==1)
    {
        stretch_sprite(valise->double_buffer,valise->r1,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }
        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }

        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }



        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=2;
                rest(100);
            }

        }

    }
    if(valise->rules==2)
    {
        stretch_sprite(valise->double_buffer,valise->r2,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=1;
                rest(100);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=3;
                rest(100);
            }

        }
    }
    if(valise->rules==3)
    {
        stretch_sprite(valise->double_buffer,valise->r3,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=2;
                rest(100);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=4;
                rest(100);
            }

        }
    }
    if(valise->rules==4)
    {
        stretch_sprite(valise->double_buffer,valise->r4,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=3;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=5;
                rest(100);
            }

        }
    }
    if(valise->rules==5)
    {
        stretch_sprite(valise->double_buffer,valise->r5,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=4;
                rest(100);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=6;
                rest(100);
            }

        }
    }
    if(valise->rules==6)
    {
        stretch_sprite(valise->double_buffer,valise->r6,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=5;
                rest(100);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=7;
                rest(100);
            }

        }
    }
    if(valise->rules==7)
    {
        stretch_sprite(valise->double_buffer,valise->r7,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                valise->choix_menu=0;
                rest(100);
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                valise->rules=6;
                rest(100);
            }
        }
    }
}

void reglespause(t_valise* valise)
{
    valise->rul1=0;
    valise->rul2=0;
    valise->choixret=0;
    if (valise->rules==1)
    {

        stretch_sprite(valise->double_buffer,valise->r1,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }
        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }

        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }



        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                valise->rules=2;
            }

        }

    }
    if(valise->rules==2)
    {

        stretch_sprite(valise->double_buffer,valise->r2,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=1;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                rest(100);
                valise->rules=3;
            }

        }
    }
    if(valise->rules==3)
    {

        stretch_sprite(valise->double_buffer,valise->r3,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=2;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                rest(100);
                valise->rules=4;
            }

        }
    }
    if(valise->rules==4)
    {

        stretch_sprite(valise->double_buffer,valise->r4,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=3;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                rest(100);
                valise->rules=5;
            }

        }
    }
    if(valise->rules==5)
    {

        stretch_sprite(valise->double_buffer,valise->r5,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=4;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                rest(100);
                valise->rules=6;
            }

        }
    }
    if(valise->rules==6)
    {

        stretch_sprite(valise->double_buffer,valise->r6,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(valise->rul2==0)
        {
            stretch_sprite(valise->double_buffer,valise->fleched,750,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=5;
            }
        }


        if(((mouse_x>=750)&&(mouse_x<=1000))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul2=1;
            if(valise->rul2==1)
            {
                stretch_sprite(valise->double_buffer,valise->fleched,740,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if (mouse_b&1)
            {
                rest(100);
                valise->rules=7;
            }

        }
    }
    if(valise->rules==7)
    {

        stretch_sprite(valise->double_buffer,valise->r7,0,0,SCREEN_W,SCREEN_H);
        if(valise->choixret==0)
        {
            stretch_sprite(valise->double_buffer,valise->retour,1190,7,SCREEN_W/12,SCREEN_H/12);
        }

        if(valise->rul1==0)
        {
            stretch_sprite(valise->double_buffer,valise->flecheg,350,720,SCREEN_W/4,SCREEN_H/12);
        }
        if(((mouse_x>=1190)&&(mouse_x<=1290))&&((mouse_y>=7)&&(mouse_y<=57)))
        {
            valise->choixret=1;
            if(valise->choixret==1)
            {
                stretch_sprite(valise->double_buffer,valise->retour,1180,2,SCREEN_W/12+20,SCREEN_H/+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->tiempo=0;
            }
        }

        if(((mouse_x>=350)&&(mouse_x<=700))&&((mouse_y>=710)&&(mouse_y<=760)))
        {
            valise->rul1=1;
            if(valise->rul1==1)
            {
                stretch_sprite(valise->double_buffer,valise->flecheg,340,715,SCREEN_W/4+20,SCREEN_H/12+10);
            }
            if(mouse_b&1)
            {
                rest(100);
                valise->rules=6;
            }
        }
    }
}
