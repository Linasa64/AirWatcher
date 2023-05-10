/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Database> (fichier Database.h) ----------------
#if ! defined ( DATABASE_H )
#define DATABASE_H

//--------------------------------------------------- Interfaces utilisées
#include <sstream>
#include <set>

#include"User.h"
#include"Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Database>
//
//
//------------------------------------------------------------------------

class Database 
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
    Database & operator = ( const Database & unDatabase );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Database ( const Database & unDatabase );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Database ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Database ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string to_string() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
//set<User> users;
set<Sensor> sensors;


};

//-------------------------------- Autres définitions dépendantes de <Database>

#endif // DATABASE_H

