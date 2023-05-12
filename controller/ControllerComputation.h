/*************************************************************************
                           ControllerComputation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ControllerComputation> (fichier ControllerComputation.h) ----------------
#if !defined(CONTROLLERCOMPUTATION_H)
#define CONTROLLERCOMPUTATION_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ControllerComputation>
//
//
//------------------------------------------------------------------------

class ControllerComputation
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
    ControllerComputation &operator=(const ControllerComputation &unControllerComputation);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    ControllerComputation(const ControllerComputation &unControllerComputation);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ControllerComputation();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ControllerComputation();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ControllerComputation>

#endif // CONTROLLERCOMPUTATION_H
