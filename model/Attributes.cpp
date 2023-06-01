/*************************************************************************
                           Attributes  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
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
string Attributes::GetAttributeId() const { return this->attributeId; }
string Attributes::GetUnit() const { return this->unit; }
string Attributes::GetDescription() const { return this->description; }

//------------------------------------------------- Surcharge d'opérateurs
Attributes &Attributes::operator=(const Attributes &unAttributes)
// Algorithme :
//
{
    if (this != &unAttributes)
    {
        attributeId = unAttributes.attributeId;
        unit = unAttributes.unit;
        description = unAttributes.description;
    }
    return *this;
} //----- Fin de operator =

ostream &operator<<(ostream &out, const Attributes &a)
{
    return out << "Attribute ID: " << a.attributeId << ", Unit: " << a.unit << ", Description: " << a.description;
}

//-------------------------------------------- Constructeurs - destructeur
Attributes::Attributes(const Attributes &unAttributes)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attributes>" << endl;
#endif
} //----- Fin de Attributes (constructeur de copie)

Attributes::Attributes()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attributes>" << endl;
#endif
} //----- Fin de Attributes

Attributes::Attributes(string pAttributeId, string pUnit, string pDescription)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attributes>" << endl;
#endif
    this->attributeId = pAttributeId;
    this->unit = pUnit;
    this->description = pDescription;
} //----- Fin de Attributes

Attributes::~Attributes()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attributes>" << endl;
#endif
} //----- Fin de ~Attributes

string Attributes::ToString() const
{
    stringstream strs;
    strs << "Attribute ID: " << attributeId << ", Unit: " << unit << ", Description: " << description << endl;
    return strs.str();
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
