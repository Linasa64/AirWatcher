/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Database> (fichier Database.h) ----------------
#if !defined(DATABASE_H)
#define DATABASE_H

//--------------------------------------------------- Interfaces utilisées
#include <sstream>
#include <map>

#include "User.h"
#include "Sensor.h"
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

    void SetUsers(map<string, User *> users);

    void SetSensors(map<string, Sensor *> sensors);

    void SetAttributes(map<string, Attributes *> attributes);

    map<string, User*> GetUsers() const;

    map<string, Sensor*> GetSensors() const;

    map<string, Attributes *> GetAttributes() const;
    
    Sensor* GetSensor(string id) const;

    //------------------------------------------------- Surcharge d'opérateurs
    Database &operator=(const Database &unDatabase);
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream &operator<<(ostream &out, const Database &d);
    //-------------------------------------------- Constructeurs - destructeur
    Database(const Database &unDatabase);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Database();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Database();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string to_string();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    map<string, User *> users;
    map<string, Sensor *> sensors;
    map<string, Attributes *> attributes;
};

//-------------------------------- Autres définitions dépendantes de <Database>

#endif // DATABASE_H
