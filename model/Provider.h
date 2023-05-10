/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include<string>
#include <sstream>
#include "Cleaner.h"
#include <list>
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------
class Provider : public User
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
    Provider & operator = ( const Provider & unProvider );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Provider ( const Provider & unProvider );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Provider ( string pProviderId );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetId();

    string to_string() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string providerId;
    list<Cleaner> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H

