/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if !defined(CLEANER_H)
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getCleanerId() const;

    float getLatitude() const;

    float getLongitude() const;

    time_t getTimestampStart() const;

    time_t getTimestampStop() const;

    //------------------------------------------------- Surcharge d'opérateurs
    Cleaner &operator=(const Cleaner &unCleaner);
    // Mode d'emploi :
    //
    // Contrat :
    //
    friend ostream &operator<<(ostream &out, const Cleaner &c);

    //-------------------------------------------- Constructeurs - destructeur
    Cleaner(const Cleaner &unCleaner);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cleaner(string cleanerId, float latitude, float longitude, time_t timestampStart, time_t timestampStop);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cleaner();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ToString() const;
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string cleanerId;
    float latitude;
    float longitude;
    time_t timestampStart;
    time_t timestampStop;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H
