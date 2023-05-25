/*************************************************************************
                           AirWatcher  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirWatcher> (fichier AirWatcher.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirWatcher.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
int main2()
{
    string choixS;
    int choix;

    cout << "--------------------------------------------------------" << endl;
    cout << "Bienvenue sur AirWatcher !" << endl
         << endl;

    while (1)
    {
    connexion:
        cout << "--------------------------Qui êtes-vous ?--------------------------\n"
             << endl;
        cout << "\t1: Agence gouvernementale" << endl;
        cout << "\t2: Utilisateur privé" << endl;
        cout << "\t3: Agence de purification de l'air" << endl;
        cout << "\t0: Quitter\n"
             << endl;
        cin >> choixS;
        cout << endl;

        choix = atoi(choixS.c_str());

        switch (choix)
        {
        case 1:
            goto menu_gov;
        case 2:
            goto menu_user;
        case 3:
            goto menu_provider;
        case 0:
            goto fin;
        default:
        {
            cout << "Choix incorrect\n"
                 << endl;
            continue;
        }
        }
    menu_gov:
        while (1)
        {
            cout << "--------------------------Menu (Gov)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    menu_user:
        while (1)
        {
            cout << "--------------------------Menu (Utilisateur privé)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    menu_provider:
        while (1)
        {
            cout << "--------------------------Menu (Agence)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    }
fin:
    cout << "Fermeture de l'application" << endl;
    cout << "--------------------------------------------------------\n";

    return 0;
}
