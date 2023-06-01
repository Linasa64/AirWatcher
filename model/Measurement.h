/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if !defined(MEASUREMENT_H)
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Attributes.h"
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------
time_t convertDateStringToTimestamp(const string date, const string &format = "%Y-%m-%d %H:%M:%S");
class Measurement
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getAssociatedSensorId() const;

    time_t getTimestamp() const;

    float getValue() const;

    Attributes *getAttributes() const;

    float GetATMOIndex() const;

    float GetAQIIndex() const;

    bool isWithinTimeRange(const string &startTime, const string &endTime) const;

    //------------------------------------------------- Surcharge d'opérateurs

    /*     Measurement & operator = ( const Measurement & unMeasurement );
        // Mode d'emploi :
        //
        // Contrat :
        // */
    friend ostream &operator<<(ostream &out, const Measurement &m);

    //-------------------------------------------- Constructeurs - destructeur
    Measurement(const Measurement &unMeasurement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Measurement(time_t timestamp, string associatedSensorId, Attributes *attributes, double value);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ToString() const;

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    time_t timestamp;
    float value;
    Attributes *attributes;
    string associatedSensorId;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // MEASUREMENT_H
