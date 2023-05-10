/*************************************************************************
                           ControllerData  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ControllerData> (fichier ControllerData.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ControllerData.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ControllerData::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/* ControllerData & ControllerData::operator = ( const ControllerData & unControllerData )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
ControllerData::ControllerData ( const ControllerData & unControllerData )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ControllerData>" << endl;
#endif
} //----- Fin de ControllerData (constructeur de copie)


ControllerData::ControllerData ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ControllerData>" << endl;
#endif
} //----- Fin de ControllerData


ControllerData::~ControllerData ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ControllerData>" << endl;
#endif
} //----- Fin de ~ControllerData

static Database retrieveData(std::string path_sensors, std::string path_measurements, std::string path_attributes, std::string path_providers, std::string path_cleaners, std::string path_users) {
    Database d1 = Database();
    return d1;
}




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

