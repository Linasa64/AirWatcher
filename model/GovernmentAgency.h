/*************************************************************************
                           GovernmentAgency  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GovernmentAgency> (fichier GovernmentAgency.h) ----------------
#if ! defined ( GOVERNMENTAGENCY_H )
#define GOVERNMENTAGENCY_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovernmentAgency>
//
//
//------------------------------------------------------------------------
class GovernmentAgency : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    GovernmentAgency & operator = ( const GovernmentAgency & unGovernmentAgency );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GovernmentAgency ( const GovernmentAgency & unGovernmentAgency );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GovernmentAgency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    GovernmentAgency ( string login, string password );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GovernmentAgency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetId();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GovernmentAgency>

#endif // GOVERNMENTAGENCY_H

