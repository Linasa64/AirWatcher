/*************************************************************************
                           Database  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Database> (fichier Database.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Database.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Database::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/* Database & Database::operator = ( const Database & unDatabase )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
Database::Database ( const Database & unDatabase )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Database>" << endl;
#endif
} //----- Fin de Database (constructeur de copie)


Database::Database ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Database>" << endl;
#endif
} //----- Fin de Database


Database::~Database ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Database>" << endl;
#endif
} //----- Fin de ~Database

string Database::to_string()const {
/*         stringstream strs;
        strs << "Database:" << std::endl;
        strs << "Sensors:" << std::endl;
        for (const auto& sensor : sensors) {
            strs << sensor.to_string() << std::endl;
        }
        strs << "Users :" << std::endl;
            for (const auto& user : users) {
            strs << user.to_string() << std::endl;
            strs << "Sensors:" << std::endl;
        }
        return strs.str(); */
        return "";
    }


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

