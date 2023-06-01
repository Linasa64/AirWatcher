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
bool Sensor::operator<(const Sensor &other) const
{
    return (this->sensorId < other.sensorId);
}

string Sensor::GetSensorId() const
{
    return sensorId;
}

float Sensor::GetLatitude() const
{
    return latitude;
}

float Sensor::GetLongitude() const
{
    return longitude;
}

list<Measurement *> Sensor::GetMeasurements() const
{
    return measurements;
}

bool Sensor::isWithinDistance(float centerLat, float centerLong, float radius)
{
    // Assuming latitudes and longitudes are in decimal degrees
    // Using the haversine formula to calculate the great-circle distance between two points

    float lat1Rad = degToRad(centerLat);
    float lat2Rad = degToRad(latitude);
    float deltaLatRad = degToRad(latitude - centerLat);
    float deltaLongRad = degToRad(longitude - centerLong);

    float a = sin(deltaLatRad / 2) * sin(deltaLatRad / 2) + cos(lat1Rad) * cos(lat2Rad) * sin(deltaLongRad / 2) * sin(deltaLongRad / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = EARTH_RADIUS * c;

    return distance <= radius;
}

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
    /*for (Measurement *measurement : measurements)
    {
        delete measurement;
    }
    measurements.clear();*/
    for (std::list<Measurement *>::iterator it = measurements.begin(); it != measurements.end(); ++it)
    {
        delete *it;
    }
    measurements.clear();
} //----- Fin de ~Sensor

string Sensor::ToString() const
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
    /*for (Measurement *measurement : measurements)
    {
        cout << *measurement;
        if (++i == 10)
            break;
    }*/
    for (std::list<Measurement *>::iterator it = measurements.begin(); it != measurements.end(); ++it)
    {
        std::cout << **it;
        if (++i == 10)
            break;
    }
}

float degToRad(float degrees) { return degrees * M_PI / 180.0; }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
