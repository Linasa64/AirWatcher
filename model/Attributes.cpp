/*************************************************************************
                           Attributes  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attributes> (fichier Attributes.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attributes.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attributes::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Attributes & Attributes::operator = ( const Attributes & unAttributes )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Attributes::Attributes ( const Attributes & unAttributes )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attributes>" << endl;
#endif
} //----- Fin de Attributes (constructeur de copie)


Attributes::Attributes ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attributes>" << endl;
#endif
} //----- Fin de Attributes

Attributes::Attributes ( string pAttributeId, string pUnit, string pDescription )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attributes>" << endl;
#endif
    this -> attributeId = pAttributeId;
    this -> unit = pUnit;
    this -> description = pDescription;
} //----- Fin de Attributes



Attributes::~Attributes ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attributes>" << endl;
#endif
} //----- Fin de ~Attributes

string Attributes::to_string()const {
    stringstream strs;
    strs << "Attribute ID: " << attributeId << ", Unit: " << unit << ", Description: " << description;
    //return strs.str();
    return "";
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

