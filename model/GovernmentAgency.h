/*************************************************************************
                           GovernmentAgency  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GovernmentAgency> (fichier GovernmentAgency.h) ----------------
#if !defined(GOVERNMENTAGENCY_H)
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
    string GetId() const;
    
    //------------------------------------------------- Surcharge d'opérateurs
    GovernmentAgency &operator=(const GovernmentAgency &unGovernmentAgency);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    GovernmentAgency(const GovernmentAgency &unGovernmentAgency);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GovernmentAgency();
    // Mode d'emploi :
    //
    // Contrat :
    //

    GovernmentAgency(string login, string password);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GovernmentAgency();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ToString() const;

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <GovernmentAgency>

#endif // GOVERNMENTAGENCY_H
