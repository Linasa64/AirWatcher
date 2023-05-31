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

string Measurement::getAssociatedSensorId() const { return associatedSensorId; }

time_t Measurement::getTimestamp() const { return timestamp; }

float Measurement::getValue() const { return value; }

Attributes *Measurement::getAttributes() const { return attributes; }

float Measurement::GetATMOIndex() const
{
    if (attributes->GetAttributeId() == "O3")
    {
        if (value >= 0 && value <= 29) return 1;
        if (value > 29 && value <= 54) return 2;
        if (value > 54 && value <= 79) return 3;
        if (value > 79 && value <= 104) return 4;
        if (value > 104 && value <= 129) return 5;
        if (value > 129 && value <= 149) return 6;
        if (value > 149 && value <= 179) return 7;
        if (value > 179 && value <= 209) return 8;
        if (value > 209 && value <= 239) return 9;
        if (value > 239) return 10;
    }
    else if (attributes->GetAttributeId() == "SO2")
    {
        if (value >= 0 && value <= 39) return 1;
        if (value > 39 && value <= 79) return 2;
        if (value > 79 && value <= 119) return 3;
        if (value > 119 && value <= 159) return 4;
        if (value > 159 && value <= 199) return 5;
        if (value > 199 && value <= 249) return 6;
        if (value > 249 && value <= 299) return 7;
        if (value > 299 && value <= 399) return 8;
        if (value > 399 && value <= 499) return 9;
        if (value > 499) return 10;

    }
    else if (attributes->GetAttributeId() == "NO2")
    {
        if (value >= 0 && value <= 29) return 1;
        if (value > 29 && value <= 54) return 2;
        if (value > 54 && value <= 84) return 3;
        if (value > 84 && value <= 109) return 4;
        if (value > 109 && value <= 134) return 5;
        if (value > 134 && value <= 164) return 6;
        if (value > 164 && value <= 199) return 7;
        if (value > 199 && value <= 274) return 8;
        if (value > 274 && value <= 399) return 9;
        if (value > 399) return 10;

    }
    else if (attributes->GetAttributeId() == "PM10")
    {
        if (value >= 0 && value <= 6) return 1;
        if (value > 6 && value <= 13) return 2;
        if (value > 13 && value <= 20) return 3;
        if (value > 20 && value <= 27) return 4;
        if (value > 27 && value <= 34) return 5;
        if (value > 34 && value <= 41) return 6;
        if (value > 41 && value <= 49) return 7;
        if (value > 49 && value <= 64) return 8;
        if (value > 64 && value <= 79) return 9;
        if (value > 79) return 10;
    }
    return -1;
}

float Measurement::GetAQIIndex() const
{
    if (attributes->GetAttributeId() == "O3")
    {
        return value*(25.0/60.0);
    }
    else if (attributes->GetAttributeId() == "SO2")
    {
        if (value >= 0 && value <= 100) return value*(1.0/2.0);
        if (value > 100) return (value*(1.0/8.0)+37.5);
    }
    else if (attributes->GetAttributeId() == "NO2")
    {
        if (value >= 0 && value <= 100) return value*(1.0/2.0);
        if (value > 100 && value <= 200) return (value*(1.0/4.0)+25.0);
        if (value > 200) return (value*(1.0/8.0)+50.0);

    }
    else if (attributes->GetAttributeId() == "PM10")
    {
        if (value >= 0 && value <= 50) return value;
        if (value > 50 && value <= 90) return (value*(5.0/8.0)+18.75);
        if (value > 90) return (value*(5.0/18.0)+50);
    }
    return -1;
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
