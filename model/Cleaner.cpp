/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Cleaner::getCleanerId() const { return cleanerId; }

float Cleaner::getLatitude() const { return latitude; }

float Cleaner::getLongitude() const { return longitude; }

time_t Cleaner::getTimestampStart() const { return timestampStart; }

time_t Cleaner::getTimestampStop() const { return timestampStop; }

//------------------------------------------------- Surcharge d'opérateurs
/* Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream &operator<<(ostream &out, const Cleaner &c)
{
    return out << "Cleaner ID: " << c.cleanerId << ", Latitude: " << c.latitude << ", Longitude: " << c.longitude
               << ", Start Timestamp: " << c.timestampStart << ", Stop Timestamp: " << c.timestampStop << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner(const Cleaner &unCleaner)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner (constructeur de copie)

Cleaner::Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner

Cleaner::Cleaner(string cleanerId, float latitude, float longitude, time_t timestampStart, time_t timestampStop)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    this->cleanerId = cleanerId;
    this->latitude = latitude;
    this->longitude = longitude;
    this->timestampStart = timestampStart;
    this->timestampStop = timestampStop;
} //----- Fin de Cleaner

Cleaner::~Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner

string Cleaner::ToString() const
{
    stringstream strs;
    strs << "Cleaner ID: " << cleanerId << ", Latitude: " << latitude << ", Longitude: " << longitude
         << ", Start Timestamp: " << timestampStart << ", Stop Timestamp: " << timestampStop;
    return strs.str();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
