/*************************************************************************
                           ControllerData  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ControllerData> (fichier ControllerData.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "../model/Cleaner.h"
#include "../model/Provider.h"
#include "../model/User.h"
#include <fstream>
#include <iomanip>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ControllerData.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ControllerData::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* ControllerData & ControllerData::operator = ( const ControllerData & unControllerData )
// Algorithme :
//
{
} //----- Fin de operator = */

//-------------------------------------------- Constructeurs - destructeur
ControllerData::ControllerData(const ControllerData &unControllerData)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ControllerData>" << endl;
#endif
} //----- Fin de ControllerData (constructeur de copie)

ControllerData::ControllerData()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ControllerData>" << endl;
#endif
} //----- Fin de ControllerData

ControllerData::~ControllerData()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ControllerData>" << endl;
#endif
} //----- Fin de ~ControllerData

time_t ControllerData::convertDateStingToTimestamp(string date, const string &format)
{
    tm t = {0};
    std::istringstream ss(date);
    ss >> get_time(&t, format.c_str());
    return mktime(&t);
}

Database ControllerData::retrieveData(string path_sensors, string path_measurements, string path_attributes, string path_providers, string path_cleaners, string path_users)
{

    Database d1 = Database();

    // =================================CLEANERS================================= //
    map<string, Cleaner *> cleanersMap;

    fstream fileCleaners(path_cleaners, ios::in);
    if (fileCleaners.is_open())
    {
        string line, word;
        vector<string> row;

        while (getline(fileCleaners, line))
        {
            row.clear();

            string delimiter = ";";

            size_t pos = 0;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                word = line.substr(0, pos);
                row.push_back(word);
                line.erase(0, pos + delimiter.length());
            }

            cleanersMap[row[0]] = (new Cleaner(row[0], stof(row[1]), stof(row[2]), convertDateStingToTimestamp(row[3]), convertDateStingToTimestamp(row[4])));
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }

    // =================================PROVIDERS================================= //
    map<string, Provider *> providersMap;
    fstream fileProviders(path_providers, ios::in);
    if (fileProviders.is_open())
    {
        string line, word;
        vector<string> row;

        while (getline(fileProviders, line))
        {
            row.clear();

            string delimiter = ";";

            size_t pos = 0;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                word = line.substr(0, pos);
                row.push_back(word);
                line.erase(0, pos + delimiter.length());
            }

            // Si le provider n'existe pas encore, on le créée et l'ajoute à la map
            if (providersMap[row[0]] == nullptr)
            {
                providersMap[row[0]] = new Provider(row[0]);
            }
            // On vérifie bien que le cleaner renseigné existe
            if (cleanersMap[row[1]] != nullptr)
            {
                providersMap[row[0]]->AddCleaner(cleanersMap[row[1]]);
            }
            else
            {
                cout << "The provider " << providersMap[row[0]]->GetId() << " owns a cleaner (" << row[1] << ") that is not provided in the cleaners.csv document.\n";
            }
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }

    map<string, User *> users;
    users.insert(providersMap.begin(), providersMap.end());

    cout << "===========Affichage de la liste totale des users===========" << endl;
    for (const auto &kv : users)
    {
        string key = kv.first; // clé
        cout << kv.first << " / " << users[key]->to_string();
    }
    // TESTS
    cout << "===========Tests sur les maps===========" << endl;
    cout << "TEST11 : " << *cleanersMap["Cleaner0"];
    cout << "TEST12 : " << *cleanersMap["Cleaner1"];

    cout << "TEST21 : " << *providersMap["Provider0"];
    cout << "TEST22 : " << *providersMap["Provider1"];

    cout << "TEST 31 : " << users["Provider0"]->to_string();
    Provider *precup = (Provider *)users["Provider0"];
    cout << "TEST 32 : " << *precup;

    // FUTUR DESTRUCTEUR DE DATABASE
    /*     for (const auto& kv : users) {
            string key = kv.first;   // clé
            cout << "SUPPRESSION DE " << kv.first << " / " << users[key]->to_string();

            delete kv.second;
        } */

    return d1;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
