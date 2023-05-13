/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sensor::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* Sensor & Sensor::operator = ( const Sensor & unSensor )
// Algorithme :
//
{
} //----- Fin de operator = */

ostream &operator<<(ostream &out, const Sensor &s)
{
    return out << "Sensor ID: " << s.sensorId << ", Latitude: " << s.latitude << ", Longitude: " << s.longitude << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor(const Sensor &unSensor)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::Sensor(string sensorId, float latitude, float longitude)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
    this->sensorId = sensorId;
    this->latitude = latitude;
    this->longitude = longitude;
} //----- Fin de Sensor

Sensor::~Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
    for (Measurement *measurement : measurements)
    {
        delete measurement;
    }
    measurements.clear();
} //----- Fin de ~Sensor

string Sensor::to_string() const
{
    stringstream strs;
    strs << "Sensor ID: " << sensorId << ", Latitude: " << latitude << ", Longitude: " << longitude << endl;
    return strs.str();
}

void Sensor::AddMeasurement(Measurement *measurement)
{
    measurements.push_back(measurement);
}

void Sensor::displayMeasurements()
{
    int i = 0;
    for (Measurement *measurement : measurements)
    {
        cout << *measurement;
        if (++i == 10)
            break;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
