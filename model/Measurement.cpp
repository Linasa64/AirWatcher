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
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement ( const Measurement & unMeasurement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement

Measurement::Measurement ( time_t timestamp, double value, Attributes attributes )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
    this->timestamp = timestamp;
    this->value = value;
    this->attributes = attributes;
} //----- Fin de Measurement


Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

