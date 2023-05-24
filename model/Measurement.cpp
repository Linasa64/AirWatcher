/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Measurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Measurement::getAssociatedSensorId() const
{
    return associatedSensorId;
}

time_t Measurement::getTimestamp() const
{
    return timestamp;
}

double Measurement::getValue() const
{
    return value;
}

Attributes *Measurement::getAttributes() const
{
    return attributes;
}

bool Measurement::isWithinTimeRange(const string &startTime, const string &endTime) const
{
    // Assuming timestamp format is "%Y-%m-%d %H:%M:%S"
    if (startTime.empty() && endTime.empty())
    {
        return true; // No time range specified, include all measurements
    }

    if (!startTime.empty())
    {
        time_t startTimestamp = convertDateStringToTimestamp(startTime);

        if (timestamp < startTimestamp)
        {
            return false; // Measurement timestamp is earlier than start time
        }
    }

    if (!endTime.empty())
    {
        time_t endTimestamp = convertDateStringToTimestamp(endTime);

        if (timestamp > endTimestamp)
        {
            return false; // Measurement timestamp is later than end time
        }
    }

    return true;
}

//------------------------------------------------- Surcharge d'opérateurs
/* Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream &operator<<(ostream &out, const Measurement &m)
{
    return out << "Timestamp: " << m.timestamp << ", Value: " << m.value << ", Associated sensor ID : " << m.associatedSensorId
               << ", Attributes: "
               << "{" << *m.attributes << "}" << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement(const Measurement &unMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)

Measurement::Measurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement

Measurement::Measurement(time_t timestamp, string associatedSensorId, Attributes *attributes, double value)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
    this->timestamp = timestamp;
    this->value = value;
    this->attributes = attributes;
    this->associatedSensorId = associatedSensorId;
} //----- Fin de Measurement

Measurement::~Measurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement

string Measurement::to_string() const
{
    stringstream strs;
    strs << "Timestamp: " << timestamp << ", Value: " << value << endl;
    return strs.str();
}

time_t convertDateStringToTimestamp(const string date, const string &format)
{
    tm t = {0};
    std::istringstream ss(date);
    ss >> get_time(&t, format.c_str());
    return mktime(&t);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
