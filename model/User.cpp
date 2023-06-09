/*************************************************************************
                           User  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type User::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* User & User::operator = ( const User & unUser )
// Algorithme :
//
{
} //----- Fin de operator = */
string User::GetLogin() const { return login; }

string User::GetPassword() const { return password; }

ostream &operator<<(ostream &out, const User &u) { return out; }

User &User::operator=(const User &unUser)
{
    this->login = unUser.login;
    this->password = unUser.password;
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur
User::User(const User &unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)

User::User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User

User::User(string pLogin, string pPassword)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif

    this->login = pLogin;
    this->password = pPassword;
} //----- Fin de User

User::~User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User
string User::ToString() const
{
    stringstream strs;
    strs << "User login: " << login << ", password: " << password << endl;
    return strs.str();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
