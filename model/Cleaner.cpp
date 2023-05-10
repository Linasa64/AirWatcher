/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
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


//------------------------------------------------- Surcharge d'opérateurs
/* Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream & operator << (ostream &out, const Cleaner & c)
{
    return out << "Cleaner ID: " << c.cleanerId << ", Latitude: " << c.latitude << ", Longitude: " << c.longitude
        << ", Start Timestamp: " << c.timestampStart << ", Stop Timestamp: " << c.timestampStop << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner (constructeur de copie)


Cleaner::Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner

Cleaner::Cleaner ( int cleanerId, float latitude, float longitude, time_t timestampStart, time_t timestampStop )
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

Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner

string Cleaner::to_string() const {
    stringstream strs;
    strs << "Cleaner ID: " << cleanerId << ", Latitude: " << latitude << ", Longitude: " << longitude
        << ", Start Timestamp: " << timestampStart << ", Stop Timestamp: " << timestampStop;
    return strs.str();
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

