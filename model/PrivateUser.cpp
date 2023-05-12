/*************************************************************************
                           PrivateUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PrivateUser> (fichier PrivateUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivateUser.h"
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PrivateUser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string PrivateUser::GetId() {
    return userId;
}

//------------------------------------------------- Surcharge d'opérateurs
/* PrivateUser & PrivateUser::operator = ( const PrivateUser & unPrivateUser )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
PrivateUser::PrivateUser ( const PrivateUser & unPrivateUser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateUser>" << endl;
#endif
} //----- Fin de PrivateUser (constructeur de copie)


PrivateUser::PrivateUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de PrivateUser

PrivateUser::PrivateUser ( string userId ) : User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif
    this->userId = userId;
    this -> reputationPoints = 0;
} //----- Fin de PrivateUser


PrivateUser::~PrivateUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de ~PrivateUser

string PrivateUser::to_string() const {
    stringstream strs;
    strs << "Cleaner ID: " << userId << ", Reputation points: " << reputationPoints << ", Nomber of sensors: " << sensors.size() << endl;
    return strs.str();
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

