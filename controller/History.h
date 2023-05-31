/*************************************************************************
                           History  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <History> (fichier History.h) ----------------
#if !defined(HISTORY_H)
#define HISTORY_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <list>
#include <sstream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <History>
//
//
//------------------------------------------------------------------------

class History
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    map<int, list<float> > GetQueryDurationsHistory();

    void Push_Back(int key, float duration);

     float computeMean(int algoId);


    //------------------------------------------------- Surcharge d'opérateurs
    History &operator=(const History &unHistory);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    History(const History &unHistory);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    History();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~History();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string to_string();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    map<int, list<float>> queryDurationsHistory;
};

//-------------------------------- Autres définitions dépendantes de <History>

#endif // HISTORY_H
