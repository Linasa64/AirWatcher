/*************************************************************************
                           ControllerPrivateUser  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ControllerPrivateUser> (fichier ControllerPrivateUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ControllerPrivateUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ControllerPrivateUser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* ControllerPrivateUser & ControllerPrivateUser::operator = ( const ControllerPrivateUser & unControllerPrivateUser )
// Algorithme :
//
{
} //----- Fin de operator = */

//-------------------------------------------- Constructeurs - destructeur
ControllerPrivateUser::ControllerPrivateUser(const ControllerPrivateUser &unControllerPrivateUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ControllerPrivateUser>" << endl;
#endif
} //----- Fin de ControllerPrivateUser (constructeur de copie)

ControllerPrivateUser::ControllerPrivateUser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ControllerPrivateUser>" << endl;
#endif
} //----- Fin de ControllerPrivateUser

ControllerPrivateUser::~ControllerPrivateUser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ControllerPrivateUser>" << endl;
#endif
} //----- Fin de ~ControllerPrivateUser

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
