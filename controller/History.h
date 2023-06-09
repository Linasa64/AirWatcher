/*************************************************************************
                           History  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
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
    map<int, list<float>> GetQueryDurationsHistory();

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

    string AlgoToString(int idAlgo);

    string ToString();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    map<int, list<float>> queryDurationsHistory;
};

//-------------------------------- Autres définitions dépendantes de <History>

#endif // HISTORY_H
