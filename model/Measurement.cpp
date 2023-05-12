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
    return out << "Timestamp: " << m.timestamp << ", Value: " << m.value << ", Attributes: " << endl
               << "{" << endl
               << m.attributes << "}" << endl;
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

Measurement::Measurement(time_t timestamp, double value, Attributes &attributes)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
    this->timestamp = timestamp;
    this->value = value;
    cout << "ici, on a : " << attributes << endl;
    this->attributes = attributes;
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
