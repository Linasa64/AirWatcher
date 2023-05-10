/*************************************************************************
                           ControllerComputation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ControllerComputation> (fichier ControllerComputation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ControllerComputation.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ControllerComputation::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/* ControllerComputation & ControllerComputation::operator = ( const ControllerComputation & unControllerComputation )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
ControllerComputation::ControllerComputation ( const ControllerComputation & unControllerComputation )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ControllerComputation>" << endl;
#endif
} //----- Fin de ControllerComputation (constructeur de copie)


ControllerComputation::ControllerComputation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ControllerComputation>" << endl;
#endif
} //----- Fin de ControllerComputation


ControllerComputation::~ControllerComputation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ControllerComputation>" << endl;
#endif
} //----- Fin de ~ControllerComputation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

