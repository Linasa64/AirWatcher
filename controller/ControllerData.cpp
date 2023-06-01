/*************************************************************************
                           ControllerData  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
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
#include "../model/PrivateUser.h"
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

    Database database = Database();

    // =================================CLEANERS================================= //
    map<string, Cleaner *> cleanersMap;

    cout << "[1/6] Extraction des données de 'cleaners.csv' en cours..." << endl;
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
    fileCleaners.close();
    cout << "[1/6] Extraction des données de 'cleaners.csv' terminée !" << endl;

    /*     cout << "===========Tests sur les Cleaner===========" << endl;
        cout << "TAILLE MAP " << cleanersMap.size() << endl;
        for (const auto &kv : cleanersMap)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << *cleanersMap[key];
        } */

    // =================================PROVIDERS================================= //
    map<string, Provider *> providersMap;

    cout << "[2/6] Extraction des données de 'providers.csv' en cours..." << endl;
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
                // cleanersMap.erase(row[1]);
                cout << "The provider " << providersMap[row[0]]->GetId() << " owns a cleaner (" << row[1] << ") that is not provided in the cleaners.csv document.\n";
            }
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    fileProviders.close();
    cout << "[2/6] Extraction des données de 'providers.csv' terminée !" << endl;
    /*     cout << "===========Tests sur les Provider===========" << endl;
        cout << "TAILLE MAP " << providersMap.size() << endl;
        for (const auto &kv : providersMap)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << *providersMap[key];
        } */

    // =================================ATTRIBUTES================================= //
    map<string, Attributes *> attributesMap;

    cout << "[3/6] Extraction des données de 'attributes.csv' en cours..." << endl;
    fstream fileAttributes(path_attributes, ios::in);
    if (fileAttributes.is_open())
    {
        string line, word;
        vector<string> row;

        getline(fileAttributes, line); // on ignore la première ligne
        while (getline(fileAttributes, line))
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

            attributesMap[row[0]] = (new Attributes(row[0], row[1], row[2]));
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    fileAttributes.close();
    cout << "[3/6] Extraction des données de 'attributes.csv' terminée !" << endl;

    /*     cout << "===========Affichage liste Attributes===========" << endl;
        for (const auto &kv : attributesMap)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << attributesMap[key]->ToString();
        } */

    // =================================MEASUREMENTS================================= //
    list<Measurement *> measurementsList;

    cout << "[4/6] Extraction des données de 'measurements.csv' en cours..." << endl;
    fstream fileMeasurements(path_measurements, ios::in);
    if (fileMeasurements.is_open())
    {
        string line, word;
        vector<string> row;

        while (getline(fileMeasurements, line))
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

            // On vérifie bien que le Attributes renseigné existe
            if (attributesMap[row[2]] != nullptr)
            {
                measurementsList.push_back(new Measurement(convertDateStingToTimestamp(row[0]), row[1], attributesMap[row[2]], stof(row[3])));
            }
            else
            {
                // attributesMap.erase(row[2]);
                cout << "The measurement from " << row[0] << " for " << row[1] << " with a value of " << row[3] << " refers to an attribute (" << row[2] << ") that is not provided in the attributes.csv document.\n";
            }
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    fileMeasurements.close();
    cout << "[4/6] Extraction des données de 'measurements.csv' terminée !" << endl;
    /*     cout << "===========Affichage liste Measurements (10 premiers)===========" << endl;
        cout << "TAILLE LISTE : " << measurementsList.size() << endl;
        int i = 0;
        for (Measurement *measurement : measurementsList)
        {
            cout << *measurement;
            if (++i == 10)
                break;
        } */

    // =================================SENSORS================================= //
    map<string, Sensor *> sensorsMap;

    cout << "[5/6] Extraction des données de 'sensors.csv' en cours..." << endl;
    fstream fileSensors(path_sensors, ios::in);
    if (fileSensors.is_open())
    {
        string line, word;
        vector<string> row;

        while (getline(fileSensors, line))
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

            sensorsMap[row[0]] = new Sensor(row[0], stof(row[1]), stof(row[2]));
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    fileSensors.close();

    // On ajoute les Measurement aux Sensor
    int j = 0;
    for (Measurement *measurement : measurementsList)
    {
        // cout << ++j << endl;
        //  On vérifie bien que le sensor renseigné existe
        if (sensorsMap[measurement->getAssociatedSensorId()] != nullptr)
        {
            sensorsMap[measurement->getAssociatedSensorId()]->AddMeasurement(measurement);
        }
        else
        {
            // sensorsMap.erase(measurement->getAssociatedSensorId());
            cout << "The measurement " << *measurement << " refers to a sensor (" << measurement->getAssociatedSensorId() << ") that is not provided in the sensors.csv document.\n";
        }
    }
    cout << "[5/6] Extraction des données de 'sensors.csv' terminée !" << endl;

    /*     cout << "===========Affichage liste Sensor===========" << endl;
        cout << "TAILLE MAP " << sensorsMap.size() << endl;
        for (const auto &kv : sensorsMap)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << sensorsMap[key]->ToString();
        }
        cout << "TEST 10 PREMIERES MESURES DE Sensor0 : " << endl;
        sensorsMap["Sensor0"]->displayMeasurements(); */

    // =================================PRIVATE USERS================================= //
    map<string, PrivateUser *> privateUsersMap;

    cout << "[6/6] Extraction des données de 'users.csv' en cours..." << endl;
    fstream filePrivateUsers(path_users, ios::in);
    if (filePrivateUsers.is_open())
    {
        string line, word;
        vector<string> row;

        while (getline(filePrivateUsers, line))
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

            // Si le private user n'existe pas encore, on le créée et l'ajoute à la map
            if (privateUsersMap[row[0]] == nullptr)
            {
                privateUsersMap[row[0]] = new PrivateUser(row[0]);
            }
            // On vérifie bien que le cleaner renseigné existe
            if (sensorsMap[row[1]] != nullptr)
            {
                privateUsersMap[row[0]]->AddSensor(sensorsMap[row[1]]);
            }
            else
            {
                // sensorsMap.erase(row[1]);
                cout << "The private user " << privateUsersMap[row[0]]->GetId() << " owns a sensor (" << row[1] << ") that is not provided in the sensors.csv document.\n";
            }
        }
    }
    else
    {
        cout << "Could not open the file\n";
    }
    filePrivateUsers.close();
    cout << "[6/6] Extraction des données de 'users.csv' terminée !" << endl;

    /*     cout << "===========Affichage liste PrivateUser===========" << endl;
        cout << "TAILLE MAP " << privateUsersMap.size() << endl;
        for (const auto &kv : privateUsersMap)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << *privateUsersMap[key];
        } */

    // =================================USERS================================= //
    map<string, User *> users;
    users.insert(providersMap.begin(), providersMap.end());       // On ajoute tous les Provider
    users.insert(privateUsersMap.begin(), privateUsersMap.end()); // On ajoute tous les PrivateUser

    /*     cout << "===========Affichage liste User===========" << endl;
        cout << "TAILLE MAP : " << users.size() << endl;
        for (const auto &kv : users)
        {
            string key = kv.first; // clé
            cout << kv.first << " / " << users[key]->ToString();
        } */
    /*     cout << "TEST 41 : " << users["Provider0"]->ToString();
        Provider *precup = (Provider *)users["Provider0"];
        cout << "TEST 42 : " << *precup; */

    database.SetAttributes(attributesMap);
    database.SetSensors(sensorsMap);
    database.SetUsers(users);

    /*     // =================================DESTRUCTEURS================================= //
        // DESTRUCTEUR SENSORS
        for (const auto &kv : sensorsMap)
        {
            string key = kv.first; // clé
            // cout << "SUPPRESSION DE " << kv.first << " / " << sensorsMap[key]->ToString();

            delete kv.second;
        }

        // DESTRUCTEUR ATTRIBUTES
        for (const auto &kv : attributesMap)
        {
            string key = kv.first; // clé
            // cout << "SUPPRESSION DE " << kv.first << " / " << attributesMap[key]->ToString();

            delete kv.second;
        }

        // DESTRUCTEUR USERS
        for (const auto &kv : users)
        {
            string key = kv.first; // clé
            // cout << "SUPPRESSION DE " << kv.first << " / " << users[key]->ToString();

            delete kv.second;
        } */

    return database; // TODO: mettre toutes les listes/map dans une database et la renvoyer ici
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
