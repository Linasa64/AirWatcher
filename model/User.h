/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <sstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    // Permet de renvoyer l'ID d'un User sous forme de string
    virtual string GetId() = 0;


//------------------------------------------------- Surcharge d'opérateurs
    User & operator = ( const User & unUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    User ( string pLogin, string pPassword );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string to_string() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string login;
    string password;

};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H

