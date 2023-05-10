/*************************************************************************
                           PrivateUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PrivateUser> (fichier PrivateUser.h) ----------------
#if ! defined ( PRIVATEUSER_H )
#define PRIVATEUSER_H

//--------------------------------------------------- Interfaces utilisées
#include<string>
#include <list>
#include "Sensor.h"
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateUser>
//
//
//------------------------------------------------------------------------
class User;
class PrivateUser : public User
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
    PrivateUser & operator = ( const PrivateUser & unPrivateUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PrivateUser ( const PrivateUser & unPrivateUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateUser ( string pUserId, string pLogin, string pPassword );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrivateUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetId();

    string to_string();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string userId;
    int reputationPoint;
    list<Sensor> sensors;

};

//-------------------------------- Autres définitions dépendantes de <PrivateUser>

#endif // PRIVATEUSER_H

