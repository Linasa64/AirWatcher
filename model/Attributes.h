/*************************************************************************
                           Attributes  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attributes> (fichier Attributes.h) ----------------
#if !defined(ATTRIBUTES_H)
#define ATTRIBUTES_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <string>
#include <sstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attributes>
//
//
//------------------------------------------------------------------------

class Attributes
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    string GetAttributeId();
    string GetUnit();
    string GetDescription();

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &out, const Attributes &a);

    Attributes &operator=(const Attributes &unAttributes);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Attributes(const Attributes &unAttributes);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attributes();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Attributes(string pAttributeId, string pUnit, string pDescription);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attributes();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string to_string() const;

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string attributeId;
    string unit;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <Attributes>

#endif // ATTRIBUTES_H
