/*************************************************************************
                           ControllerData  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ControllerData> (fichier ControllerData.h) ----------------
#if !defined(CONTROLLERDATA_H)
#define CONTROLLERDATA_H

//--------------------------------------------------- Interfaces utilisées
#include "../model/Database.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ControllerData>
//
//
//------------------------------------------------------------------------

class ControllerData
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
    ControllerData &operator=(const ControllerData &unControllerData);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    ControllerData(const ControllerData &unControllerData);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ControllerData();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ControllerData();
    // Mode d'emploi :
    //
    // Contrat :
    //

    time_t convertDateStingToTimestamp(string date, const string &format = "%Y-%m-%d %H:%M:%S");

    Database retrieveData(string path_sensors, string path_measurements, string path_attributes, string path_providers, string path_cleaners, string path_users);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};
//-------------------------------- Autres définitions dépendantes de <ControllerData>

#endif // CONTROLLERDATA_H
