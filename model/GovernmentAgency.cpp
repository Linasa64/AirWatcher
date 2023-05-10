/*************************************************************************
                           GovernmentAgency  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GovernmentAgency> (fichier GovernmentAgency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GovernmentAgency.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GovernmentAgency::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string GetId()
{
    return "Government";
}


//------------------------------------------------- Surcharge d'opérateurs
GovernmentAgency & GovernmentAgency::operator = ( const GovernmentAgency & unGovernmentAgency )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GovernmentAgency::GovernmentAgency ( const GovernmentAgency & unGovernmentAgency )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GovernmentAgency>" << endl;
#endif
} //----- Fin de GovernmentAgency (constructeur de copie)


GovernmentAgency::GovernmentAgency ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovernmentAgency>" << endl;
#endif
} //----- Fin de GovernmentAgency

GovernmentAgency::GovernmentAgency (string pLogin, string pPassword ) : User(pLogin, pPassword)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovernmentAgency>" << endl;
#endif
} //----- Fin de GovernmentAgency


GovernmentAgency::~GovernmentAgency ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GovernmentAgency>" << endl;
#endif
} //----- Fin de ~GovernmentAgency


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

