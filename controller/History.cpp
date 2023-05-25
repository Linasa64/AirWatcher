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

//------------------------------------------------------ Include personnel
#include "History.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
map<int, list<float>> History::GetQueryDurationsHistory() { return queryDurationsHistory; }

void History::Push_Back(int key, float duration) { queryDurationsHistory[key].push_back(duration); }
//----------------------------------------------------- Méthodes publiques
// type History::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* History & History::operator = ( const History & unHistory )
// Algorithme :
//
{
} //----- Fin de operator = */

//-------------------------------------------- Constructeurs - destructeur
History::History(const History &unHistory)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <History>" << endl;
#endif
} //----- Fin de History (constructeur de copie)

History::History()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <History>" << endl;
#endif
} //----- Fin de History

History::~History()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <History>" << endl;
#endif
} //----- Fin de ~History

string History::to_string()
{
    cout << "===========Affichage map History===========" << endl;
    cout << "TAILLE MAP " << queryDurationsHistory.size() << endl;
    for (const auto &kv : queryDurationsHistory)
    {
        int key = kv.first; // clé
        cout << "Liste pour l'algorithme " << key << " : " << endl;
        for (const auto &duration : queryDurationsHistory[key])
        {
            cout << "\t- " << kv.first << " / " << duration << endl;
        }
    }
    return "";
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
