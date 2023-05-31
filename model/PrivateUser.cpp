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

string PrivateUser::GetId() const { return privateUserId; }

int PrivateUser::GetReputationPoints() const { return reputationPoints; }

list<Sensor *> PrivateUser::GetSensors() const { return sensors; }

//------------------------------------------------- Surcharge d'opérateurs
/* PrivateUser & PrivateUser::operator = ( const PrivateUser & unPrivateUser )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream &operator<<(ostream &out, const PrivateUser &p)
{
    out << "PrivateUser ID: " << p.privateUserId << ", Number of Sensors: " << p.sensors.size() << endl
        << "   Sensors :" << endl;
    for (Sensor *sensor : p.sensors)
    {
        out << "\t" << *sensor;
    }
    return out;
}
//-------------------------------------------- Constructeurs - destructeur
PrivateUser::PrivateUser(const PrivateUser &unPrivateUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateUser>" << endl;
#endif
} //----- Fin de PrivateUser (constructeur de copie)

PrivateUser::PrivateUser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de PrivateUser

PrivateUser::PrivateUser(string privateUserId) : User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif
    this->privateUserId = privateUserId;
    this->reputationPoints = 0;
} //----- Fin de PrivateUser

PrivateUser::~PrivateUser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de ~PrivateUser

string PrivateUser::to_string() const
{
    stringstream strs;
    strs << "PrivateUser ID: " << privateUserId << ", Reputation points: " << reputationPoints << ", Number of sensors: " << sensors.size() << endl
         << "   Sensors :" << endl;
    for (Sensor *sensor : sensors)
    {
        strs << "\t" << *sensor;
    }
    return strs.str();
}

void PrivateUser::AddSensor(Sensor *sensor) { sensors.push_back(sensor); }
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
