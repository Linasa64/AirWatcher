/*************************************************************************
                           Attributes  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attributes> (fichier Attributes.h) ----------------
#if ! defined ( ATTRIBUTES_H )
#define ATTRIBUTES_H

//--------------------------------------------------- Interfaces utilisées

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


//------------------------------------------------- Surcharge d'opérateurs
    Attributes & operator = ( const Attributes & unAttributes );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Attributes ( const Attributes & unAttributes );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attributes ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attributes ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Attributes>

#endif // ATTRIBUTES_H

