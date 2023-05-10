/*************************************************************************
                           AirWatcher  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AirWatcher> (fichier AirWatcher.h) ----------------
#if ! defined ( AIRWATCHER_H )
#define AIRWATCHER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirWatcher>
//
//
//------------------------------------------------------------------------

class AirWatcher 
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
    AirWatcher & operator = ( const AirWatcher & unAirWatcher );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AirWatcher ( const AirWatcher & unAirWatcher );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AirWatcher ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AirWatcher ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AirWatcher>

#endif // AIRWATCHER_H

