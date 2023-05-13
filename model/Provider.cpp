/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"
#include "User.h"
#include <list>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
string Provider::GetId()
{
    return providerId;
}
//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* Provider & Provider::operator = ( const Provider & unProvider )
// Algorithme :
//
{
} //----- Fin de operator = */
ostream &operator<<(ostream &out, const Provider &p)
{
    out << "Provider ID: " << p.providerId << ", Number of Cleaners: " << p.cleaners.size() << endl
        << "   Cleaners :" << endl;
    for (Cleaner *cleaner : p.cleaners)
    {
        out << "\t" << *cleaner;
    }
    return out;
}

string Provider::GetId() const
{
    return this->providerId;
}

bool Provider::operator<(const Provider &other) const
{
    return (this->providerId < other.providerId);
}

bool operator<(const Provider &p1, const Provider &p2)
{
    return p1.GetId() < p2.GetId();
}

bool Provider::operator==(const Provider &other) const
{
    return this->GetId() == other.GetId();
}
//-------------------------------------------- Constructeurs - destructeur
Provider::Provider(const Provider &unProvider)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)

Provider::Provider()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::Provider(string providerId) : User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif

    this->providerId = providerId;
} //----- Fin de Provider

Provider::~Provider()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
    for (Cleaner *cleaner : cleaners)
    {
        delete cleaner;
    }
    cleaners.clear();
} //----- Fin de ~Provider

string Provider::to_string() const
{
    stringstream strs;
    strs << "Provider ID: " << providerId << ", Number of Cleaners: " << cleaners.size() << endl
         << "   Cleaners :" << endl;
    for (Cleaner *cleaner : cleaners)
    {
        strs << "\t" << *cleaner;
    }
    return strs.str();
}

void Provider::AddCleaner(Cleaner *cleaner)
{
    cleaners.push_back(cleaner);
}

list<Cleaner *> Provider::GetCleaners()
{
    return this->cleaners;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
