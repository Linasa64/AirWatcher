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

void Database::SetUsers(map<string, User *> users)
{
    this->users = users;
}

void Database::SetSensors(map<string, Sensor *> sensors)
{
    this->sensors = sensors;
}

void Database::SetAttributes(map<string, Attributes *> attributes)
{
    this->attributes = attributes;
}

map<string, Sensor*> Database::GetSensors() const
{
    return sensors;
}

Sensor* Database::GetSensor(string id) const
{
    return sensors.at(id);
}

map<string, User *> Database::GetUsers() const
{
    return users;
}


//------------------------------------------------- Surcharge d'opérateurs
/* Database & Database::operator = ( const Database & unDatabase )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream &operator<<(ostream &out, const Database &d)
{
    return out << "pas encore implémenté" << endl;
}

//-------------------------------------------- Constructeurs - destructeur
Database::Database(const Database &unDatabase)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Database>" << endl;
#endif
} //----- Fin de Database (constructeur de copie)

Database::Database()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Database>" << endl;
#endif
} //----- Fin de Database

Database::~Database()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Database>" << endl;
#endif
    // =================================DESTRUCTEURS================================= //
    // DESTRUCTEUR SENSORS
    for (const auto &kv : sensors)
    {
        string key = kv.first; // clé
        // cout << "SUPPRESSION DE " << kv.first << " / " << sensorsMap[key]->to_string();

        delete kv.second;
    }

    // DESTRUCTEUR ATTRIBUTES
    for (const auto &kv : attributes)
    {
        string key = kv.first; // clé
        // cout << "SUPPRESSION DE " << kv.first << " / " << attributesMap[key]->to_string();

        delete kv.second;
    }

    // DESTRUCTEUR USERS
    for (const auto &kv : users)
    {
        string key = kv.first; // clé
        // cout << "SUPPRESSION DE " << kv.first << " / " << users[key]->to_string();

        delete kv.second;
    }
} //----- Fin de ~Database

string Database::to_string()
{
    cout << "===========Affichage liste Sensor===========" << endl;
    cout << "TAILLE MAP " << sensors.size() << endl;
    for (const auto &kv : sensors)
    {
        string key = kv.first; // clé
        cout << kv.first << " / " << sensors[key]->to_string();
    }
    cout << "TEST 10 PREMIERES MESURES DE Sensor0 : " << endl;
    sensors["Sensor0"]->displayMeasurements();

    cout << "===========Affichage liste Attributes===========" << endl;
    for (const auto &kv : attributes)
    {
        string key = kv.first; // clé
        cout << kv.first << " / " << attributes[key]->to_string();
    }

    cout << "===========Affichage liste User===========" << endl;
    cout << "TAILLE MAP : " << users.size() << endl;
    for (const auto &kv : users)
    {
        string key = kv.first; // clé
        cout << kv.first << " / " << users[key]->to_string();
    }

    return "";
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
