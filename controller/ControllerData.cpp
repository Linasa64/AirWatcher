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
ControllerData & ControllerData::operator = ( const ControllerData & unControllerData )
// Algorithme :
//
{
} //----- Fin de operator =


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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

