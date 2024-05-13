#include "header.h"

int main()
{
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////// INITIALISATION DU MODE GRAPHIQUE //////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,800,0,0)!=0)
    {
        allegro_message("Probleme avec gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////// INITIALISATION DU MODE MUSIQUE ////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    install_sound(DIGI_AUTODETECT,MIDI_NONE,0);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////// DECLARATION VARIABLES ET INITIALISATIONS //////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    t_graphe* graphe;
    t_valise valise;
    t_info info;
    t_mairie mairie;
    init_valise(&valise);
    init_mairie(&mairie);
    t_cases cases[35][45];
    crea_struct_cases(valise, cases);
    //fichierON(&valise,&mairie);
    //chargmentsauv(&valise);
    jouer_music(valise.music_1);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////// BOUCLE PRINCIPALE //////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(!key[KEY_ESC])
    {
        clear_bitmap(valise.double_buffer);

        if(valise.extra_graphe==1)
        {
            ///graphe = extraire_graphe();
            valise.extra_graphe = 0;
        }
        /*if(key[KEY_SPACE])
        {
            graphe = extraire_graphe(graphe);
            afficher_graphe(graphe);
        }*/

        if(key[KEY_UP] && valise.play_eau==0)
        {
            jouer_music(valise.eau);
            //notre_stop_music(valise.eau);
            valise.play_eau=1;
        }
        if(key[KEY_DOWN] && valise.play_zap==0)
        {
            jouer_music(valise.zap);
            //notre_stop_music(valise.eau);
            valise.play_zap=1;
        }
        if(key[KEY_RIGHT] && valise.play_wo==0)
        {
            jouer_music(valise.travaux);
            //notre_stop_music(valise.eau);
            valise.play_wo=1;
        }
        if(key[KEY_LEFT] && valise.play_bao==0)
        {
            jouer_music(valise.boiteao);
            //notre_stop_music(valise.eau);
            valise.play_bao=1;
        }

        if(valise.cinetique==0) /// CONDITION POUR LANCER LA CINEMATIQUE D'INTRO == 0
        {
            //stretch_sprite(valise.double_buffer,valise.info_maison,270,132,SCREEN_W/3,SCREEN_H/1.5);
            //rotate_sprite(valise.double_buffer, valise.info_maison, 270, 132,50);

            cinematique_1(&valise);
        }
        else if(valise.cinetique==1) ///LANCEMENT DE LA BOUCLE DE JEU == 1
        {
            //rectfill(valise.double_buffer,0,0,1400,800,makecol(0,255,255)); ///RECTANGLE BLEU CIEL DE FOND
            blit(valise.map_neige,valise.double_buffer,0,0,0,0,SCREEN_W,SCREEN_H);

            compter(&valise);

            /* if(key[KEY_RIGHT])
             {
                 valise.pos_x+=10;
             }
             if(key[KEY_LEFT])
             {
                 valise.pos_x-=10;
             }
             if(key[KEY_UP])
             {
                 valise.pos_y-=10;
             }
             if(key[KEY_DOWN])
             {
                 valise.pos_y+=10;
             }*/
            /*if(key[KEY_SPACE])
            {
                valise.div-=2;
            }*/
            if(valise.choix_menu==0)/// SI LE CHOIX DU MENU EST A 0, ON AFFICHE LE MENU PRINCIPAL
            {
                cinematique_menu(&valise); ///ANIMATION DE FOND
                menu_principale(&valise); /// APPEL DU MENU PRINCIPAL
            }
            if(valise.choix_menu==1)/// CHOIX DU MENU == 1 -> LANCEMENT PARTIE CAPITALISTE
            {
                evolution_batiment(valise, cases, &mairie);
                impots(&valise, &mairie);
                if(valise.etage == 0)/// NIVEAU 0, LA OU L'ON PEUT CONSTRUIRE, ETC...
                {
                    affichage_plateau(&valise, cases);
                    affichage_batiments(&valise, cases);

                    if(valise.outil == 0) /// INFORMATIONS
                    {
                        select_info(&valise, cases, &info);
                        if(valise.etage_info == 1)
                        {
                            information(valise, info);
                        }
                    }
                    else if(valise.outil == 1) /// CONSTRUCTION DE ROUTES
                    {
                        creation_routes(&valise,&mairie,cases);
                    }
                    else if(valise.outil == 2) /// CONSTRUCTION DE BATIMENTS
                    {

                        creation_batiment(&valise,&mairie, cases);
                    }
                    else if(valise.outil == 3)/// CONSTRUCTION DE CENTRALES ELECTRIQUES
                    {

                        creation_centraleElec(&valise,&mairie, cases);
                    }
                    else if(valise.outil == 4)/// CONSTRUCTION DE CHATEAU D'EAU
                    {
                        creation_centraleEau(&valise,&mairie, cases);
                    }
                    barre_a_outils(&valise);///DERNIER APPEL DE LA BOUCLE POUR QUE LA BARRE D'OUTIL S'AFFICHE EN PREMIER PLAN
                }

                else if (valise.etage == 1 || valise.etage == 2) /// NIVEAU -1, RESEAU D'EAU OU NIVEAU -2, RESEAU ELECTRIQUE
                {
                    affichage_reseau(&valise, cases);
                    barre_a_outils(&valise);
                }
                affichage_ressources(&valise, &mairie);

               // stretch_sprite(valise.double_buffer,valise.people,50,100,SCREEN_W/4,SCREEN_H/2);
                rectfill(valise.double_buffer,600,0, 800,25,makecol(150,150,150));
                textprintf_ex(valise.double_buffer,font,620,10,makecol(0,0,0),-1,"POPULATION : %d",mairie.nb_habitants);

                /*textprintf_ex(valise.double_buffer,font,50,10,makecol(0,0,0),-1,"NOMBRE DE BATIMENTS : %d", valise.nb_bat);
                textprintf_ex(valise.double_buffer,font,50,20,makecol(0,0,0),-1,"NOMBRE DE ROUTES : %d", valise.nb_routes);
                textprintf_ex(valise.double_buffer,font,50,30,makecol(0,0,0),-1,"NOMBRE DE CHATEAU D'EAU : %d", valise.nb_centrales_eau);
                textprintf_ex(valise.double_buffer,font,50,40,makecol(0,0,0),-1,"NOMBRE DE CENTRALES ELEC : %d", valise.nb_centrales_elec);
                textprintf_ex(valise.double_buffer,font,50,50,makecol(0,0,0),-1,"NOMBRE D'HABITANTS : %d", mairie.nb_habitants);
                textprintf_ex(valise.double_buffer,font,50,10,makecol(0,0,0),-1,"ETAGE INFO : %d", valise.etage_info);
                textprintf_ex(valise.double_buffer,font,50,20,makecol(0,0,0),-1,"HABITATION : %d", info.habitation);
                textprintf_ex(valise.double_buffer,font,50,30,makecol(0,0,0),-1,"CHANTIER : %d",info.chantier );
                textprintf_ex(valise.double_buffer,font,50,40,makecol(0,0,0),-1,"CABANE : %d", info.cabane);
                textprintf_ex(valise.double_buffer,font,50,50,makecol(0,0,0),-1,"MAISON : %d", info.maison);
                textprintf_ex(valise.double_buffer,font,50,60,makecol(0,0,0),-1,"BULLYDING : %d",info.bullyding );
                textprintf_ex(valise.double_buffer,font,50,70,makecol(0,0,0),-1,"SKYSCRAPPER : %d",info.skyscrapper );
                textprintf_ex(valise.double_buffer,font,50,80,makecol(0,0,0),-1,"CENTRALE ELEC : %d",info.centrale_electrique);
                textprintf_ex(valise.double_buffer,font,50,90,makecol(0,0,0),-1,"CHATEAU EAU : %d", info.chateau_eau);
                textprintf_ex(valise.double_buffer,font,50,100,makecol(0,0,0),-1,"IRRIGUE: %d",info.irrigue );*/
                textprintf_ex(valise.double_buffer,font,50,120,makecol(0,0,0),-1,"x:%d / y :%d",mouse_x, mouse_y);

                menu_pause(&valise, &mairie, cases);


            }
            if(valise.choix_menu==3)
            {
                regles(&valise);
            }
            if(valise.choix_menu==5)
            {
                reini();
                reinii(&mairie,&valise);
                valise.choix_menu=0;
            }

            affichage_curseur(valise);
        }
        blit(valise.double_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    return 0;
}
END_OF_MAIN();
