/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if !defined(SENSOR_H)
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <string>
#include "Measurement.h"
#include <cmath>
using namespace std;
//------------------------------------------------------------- Constantes
const float EARTH_RADIUS = 6371.0;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetSensorId() const;

    float GetLatitude() const;

    float GetLongitude() const;

    list<Measurement *> GetMeasurements() const;

    bool isWithinDistance(float centerLat, float centerLong, float radius);

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &out, const Sensor &s);

    bool operator<(const Sensor &other) const;

    // Sensor &operator=(const Sensor &unSensor);
    //  Mode d'emploi :
    //
    //  Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Sensor(const Sensor &unSensor);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string sensorId, float latitude, float longitude);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ToString() const;

    void AddMeasurement(Measurement *measurement);

    void displayMeasurements();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string sensorId;
    float latitude;
    float longitude;
    list<Measurement *> measurements;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

float degToRad(float degrees);

#endif // SENSOR_H
