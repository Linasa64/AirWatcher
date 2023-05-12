/*************************************************************************
                           ControllerPrivateUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ControllerPrivateUser> (fichier ControllerPrivateUser.h) ----------------
#if !defined(ControllerPrivateUser_H)
#define ControllerPrivateUser_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ControllerPrivateUser>
//
//
//------------------------------------------------------------------------

class ControllerPrivateUser
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
    ControllerPrivateUser &operator=(const ControllerPrivateUser &unControllerPrivateUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    ControllerPrivateUser(const ControllerPrivateUser &unControllerPrivateUser);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ControllerPrivateUser();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ControllerPrivateUser();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ControllerPrivateUser>

#endif // ControllerPrivateUser_H
