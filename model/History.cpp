/*************************************************************************
                           History  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <History> (fichier History.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "History.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type History::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
History & History::operator = ( const History & unHistory )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
History::History ( const History & unHistory )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <History>" << endl;
#endif
} //----- Fin de History (constructeur de copie)


History::History ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <History>" << endl;
#endif
} //----- Fin de History


History::~History ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <History>" << endl;
#endif
} //----- Fin de ~History


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

