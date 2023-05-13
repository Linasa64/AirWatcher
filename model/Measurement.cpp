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

string Measurement::getAssociatedSensorId()
{
    return associatedSensorId;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
