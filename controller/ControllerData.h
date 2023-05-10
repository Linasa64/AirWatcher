/*************************************************************************
                           ControllerData  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ControllerData> (fichier ControllerData.h) ----------------
#if ! defined ( CONTROLLERDATA_H )
#define CONTROLLERDATA_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ControllerData>
//
//
//------------------------------------------------------------------------

class ControllerData 
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
    ControllerData & operator = ( const ControllerData & unControllerData );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ControllerData ( const ControllerData & unControllerData );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ControllerData ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ControllerData ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ControllerData>

#endif // CONTROLLERDATA_H

