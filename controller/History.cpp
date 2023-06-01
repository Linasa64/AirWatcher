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

float History::computeMean(int algoId)
{

    float sum = 0;
    int size = queryDurationsHistory[algoId].size();

    if (size == 0)
        return -1.0;

    for (const auto &duration : queryDurationsHistory[algoId])
    {
        sum += duration;
    }
    return (sum / size);
}
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

string History::AlgoToString(int idAlgo)
{
    stringstream strs;
    if (queryDurationsHistory[idAlgo].size() == 0)
    {
        strs << "Aucune requête valide utilisant l'algorithme " << idAlgo << " n'a été effecutée.\n"
             << endl;
        return strs.str();
    }
    strs << "Historique des performances de l'algorithme " << idAlgo << " :" << endl;
    for (const auto &duration : queryDurationsHistory[idAlgo])
    {
        strs << "   • " << duration << " ms" << endl;
    }
    strs << "   -> Moyenne : " << computeMean(idAlgo) << " ms" << endl
         << endl;
    return strs.str();
}

string History::ToString()
{
    stringstream strs;
    if (queryDurationsHistory.empty())
    {
        strs << "Aucune requête valide n'a encore été effecutée.\n"
             << endl;
        return strs.str();
    }
    /*strs << "===========Affichage map History===========" << endl;
    strs << "TAILLE MAP " << queryDurationsHistory.size() << endl;*/
    for (const auto &kv : queryDurationsHistory)
    {
        int key = kv.first; // clé
        if (queryDurationsHistory[key].size() == 0)
        {
            strs << "Aucune requête valide utilisant l'algorithme " << key << " n'a été effecutée.\n"
                 << endl;
            return strs.str();
        }
        else
        {
            strs << "Historique des performances de l'algorithme " << key << " : " << endl;
            for (const auto &duration : queryDurationsHistory[key])
            {
                strs << "   • " << kv.first << " / " << duration << " ms" << endl;
            }
            strs << "   -> Moyenne : " << computeMean(key) << " ms" << endl
                 << endl;
        }
    }
    return strs.str();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
