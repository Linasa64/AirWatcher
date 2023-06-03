/*************************************************************************
                           AirWatcher  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AirWatcher> (fichier AirWatcher.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <locale>
#include <iomanip>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../model/Cleaner.h"
#include "../model/Measurement.h"
#include "../model/User.h"
#include "../model/GovernmentAgency.h"
#include "../model/Provider.h"
#include "../model/PrivateUser.h"
#include "../model/Sensor.h"
#include "../model/Attributes.h"
#include "../controller/ControllerData.h"
#include "../controller/ControllerComputation.h"
#include "../model/Database.h"

//------------------------------------------------------------- Constantes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

//----------------------------------------------------------------- PUBLIC
int main()
{
    string choixS;
    int choix, choix2;
    string tempsDebut;
    string tempsFin;

    ControllerData controllerData;
    ControllerComputation controllerComputation;

    cout << "===============================================================" << endl;
    cout << "Extraction des données en cours...\n" << endl;
    Database d = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");
    cout << "Extraction des données terminée !" << endl;
    cout << "===============================================================\n"
         << endl;
    cout << "\t\t   Bienvenue sur " << CYAN << BOLD << "AirWatcher" << RESET << " !" << endl
         << endl;

    while (1)
    {
    connexion:
        cout << "========================" << BOLD << "Qui êtes-vous ?" << RESET << "========================\n"
             << endl;
        cout << GREEN << BOLD << "\t1" << RESET << ": Agence gouvernementale" << endl;
        cout << GREEN << BOLD << "\t2" << RESET << ": Utilisateur privé" << endl;
        cout << GREEN << BOLD << "\t3" << RESET << ": Agence de purification de l'air" << endl;
        cout << GREEN << BOLD << "\t0" << RESET << ": Quitter\n"
             << endl;
        cin >> choixS;
        cout << endl;

        choix = atoi(choixS.c_str());

        switch (choix)
        {
        case 1:
            goto menu_gov;
        case 2:
            goto menu_user;
        case 3:
            goto menu_provider;
        case 0:
            goto fin;
        default:
        {
            cout << "Choix incorrect\n"
                 << endl;
            continue;
        }
        }
    menu_gov:
        while (1)
        {
            cout << "========================Menu (" << CYAN << BOLD << "Gouvernement" << RESET << ")========================\n"
                 << endl;
            cout << GREEN << BOLD << "\t1" << RESET << ": Consulter le niveau de qualité de l'air en un point" << endl;
            cout << GREEN << BOLD << "\t2" << RESET << ": Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << GREEN << BOLD << "\t3" << RESET << ": Observer des similarités entre des capteurs" << endl;
            cout << GREEN << BOLD << "\t4" << RESET << ": Vérifier la fiabilité des données des capteurs" << endl;
            cout << GREEN << BOLD << "\t5" << RESET << ": Consulter la performance des algorithmes de calcul" << endl;
            cout << GREEN << BOLD << "\t0" << RESET << ": Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            float latitude, longitude, rayon;
            string selectedSensor;
            vector<pair<Sensor *, float>> classement;
            int count, idAlgo;
            Sensor *s;
            pair<vector<Sensor *>, vector<vector<float>>> defectSensors;
            switch (choix)
            {
            case 1:
                cout << "==========Consultation de la qualité de l'air en un point==========\n";
                cout << "\nLatitude : ";
                cin >> latitude;
                cout << "\nLongitude : ";
                cin >> longitude;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                float indiceATMO, indiceAQI;
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut);
                }

                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;

                break;
            case 2:
                cout << "==========Consultation de la qualité de l'air dans un rayon==========\n";
                cout << "\nLatitude du centre : ";
                cin >> latitude;
                cout << "\nLongitude du centre : ";
                cin >> longitude;
                cout << "\nRayon de la zone (en km) : ";
                cin >> rayon;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut);
                }
                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;
                break;

            case 3:
                cout << "==========Observation de similarités entre capteurs==========\n";
                cout << "\nCapteur sélecionné (entre 0 et 99) : ";
                cin >> selectedSensor;
                s = d.GetSensor(("Sensor" + selectedSensor));

                int rankLimit;
                cout << "\nTaille du classement (entre 1 et 100) : ";
                cin >> rankLimit;

                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    classement = controllerComputation.calculateSimilarityScores(d, *s, tempsDebut, tempsFin);

                    break;
                default:
                    classement = controllerComputation.calculateSimilarityScores(d, *s, tempsDebut);
                }

                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Classement des capteurs similaires au capteur '" << ("Sensor" + selectedSensor) << "' : " << endl
                     << endl;
                count = 0;
                for (auto it = classement.begin(); it != classement.end() && count < rankLimit; ++it)
                {
                    cout << " • " << ++count << " - " << it->first->ToString() << "\t-> Score de différence : " << it->second << endl
                         << endl;
                }

                break;
            case 4:
                cout << "==========Vérification de la fiabilité des capteurs==========\n";

                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    defectSensors = controllerComputation.detectDefectSensorsAndOutliers(d, tempsDebut, tempsFin);
                    break;
                default:
                    defectSensors = controllerComputation.detectDefectSensorsAndOutliers(d, tempsDebut);
                }

                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Capteurs défectueux :\n"
                     << endl;
                for (auto it = defectSensors.first.begin(); it != defectSensors.first.end(); ++it)
                {
                    cout << " • " << (*it)->ToString() << endl;
                }
                cout << "Valeurs aberrantes :\n"
                     << endl;
                for (auto it = defectSensors.second.begin(); it != defectSensors.second.end(); ++it)
                {
                    for (auto it2 = it->begin(); it2 != it->end(); ++it2)
                    {
                        cout << *it2 << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                break;
            case 5:
                cout << "Quels performances voulez-vous consulter ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Performances d'un algorithme donné" << endl;
                cout << GREEN << BOLD << "\t2" << RESET << ": Performances de tous les algorithmes" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                switch (choix)
                {
                case 1:

                    cout << "\nID de l'algorithme :\n"
                         << endl;
                    cout << GREEN << BOLD << "\t1" << RESET << ": Calcul de la qualité de l'air en un point précis (ATMO/AQI)" << endl;
                    cout << GREEN << BOLD << "\t2" << RESET << ": Calcul de la qualité de l'air dans un rayon (ATMO/AQI)" << endl;
                    cout << GREEN << BOLD << "\t3" << RESET << ": Calcul des similarités entre capteurs" << endl;
                    cout << GREEN << BOLD << "\t4" << RESET << ": Analyse les données (mesures erronées)" << endl;
                    cin >> idAlgo;
                    cout << endl;

                    cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                         << endl;
                    cout << controllerComputation.GetHistory().AlgoToString(idAlgo);
                    break;
                case 2:
                    cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                         << endl;
                    cout << controllerComputation.GetHistory().ToString();
                    break;
                }
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    menu_user:
        while (1)
        {
            cout << "========================Menu (" << CYAN << BOLD << "Utilisateur privé" << RESET << ")========================\n"
                 << endl;
            cout << GREEN << BOLD << "\t1" << RESET << ": Consulter le niveau de qualité de l'air en un point" << endl;
            cout << GREEN << BOLD << "\t2" << RESET << ": Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << GREEN << BOLD << "\t0" << RESET << ": Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            float latitude, longitude, rayon;
            switch (choix)
            {
            case 1:
                cout << "==========Consultation de la qualité de l'air en un point==========\n";
                cout << "\nLatitude : ";
                cin >> latitude;
                cout << "\nLongitude : ";
                cin >> longitude;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                float indiceATMO, indiceAQI;
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut);
                }

                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;

                break;
            case 2:
                cout << "==========Consultation de la qualité de l'air dans un rayon==========\n";
                cout << "\nLatitude du centre : ";
                cin >> latitude;
                cout << "\nLongitude du centre : ";
                cin >> longitude;
                cout << "\nRayon de la zone (en km) : ";
                cin >> rayon;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut);
                }
                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    menu_provider:
        while (1)
        {
            cout << "========================Menu (" << CYAN << BOLD << "Agence de purification" << RESET << ")========================\n"
                 << endl;
            cout << GREEN << BOLD << "\t1" << RESET << ": Consulter le niveau de qualité de l'air en un point" << endl;
            cout << GREEN << BOLD << "\t2" << RESET << ": Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << GREEN << BOLD << "\t0" << RESET << ": Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            float latitude, longitude, rayon;
            switch (choix)
            {
            case 1:
                cout << "==========Consultation de la qualité de l'air en un point==========\n";
                cout << "\nLatitude : ";
                cin >> latitude;
                cout << "\nLongitude : ";
                cin >> longitude;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                float indiceATMO, indiceAQI;
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculatePreciseAirQualityATMO(d, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculatePreciseAirQualityAQI(d, latitude, longitude, tempsDebut);
                }

                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;

                break;
            case 2:
                cout << "==========Consultation de la qualité de l'air dans un rayon==========\n";
                cout << "\nLatitude du centre : ";
                cin >> latitude;
                cout << "\nLongitude du centre : ";
                cin >> longitude;
                cout << "\nRayon de la zone (en km) : ";
                cin >> rayon;
                cout << "\nTemps de début au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                getline(cin >> ws, tempsDebut);
                cout << "\nVoulez-vous préciser un temps de fin ?\n"
                     << endl;
                cout << GREEN << BOLD << "\t1" << RESET << ": Oui" << endl;
                cout << GREEN << BOLD << "\t0" << RESET << ": Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());
                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut, tempsFin);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut, tempsFin);

                    break;
                default:
                    indiceATMO = controllerComputation.calculateMeanAirQualityATMO(d, rayon, latitude, longitude, tempsDebut);
                    indiceAQI = controllerComputation.calculateMeanAirQualityAQI(d, rayon, latitude, longitude, tempsDebut);
                }
                cout << GREEN << BOLD << "==========Résultats==========\n" << RESET
                     << endl;
                cout << "Indice ATMO : " << indiceATMO << endl;
                cout << "Indice AQI : " << indiceAQI << endl
                     << endl;
                break;
            case 0:
                goto connexion;
            default:
            {
                cout << "Choix incorrect\n"
                     << endl;
                continue;
            }
            }
        }
    }
fin:
    cout << RED << "Fermeture de l'application" << RESET << endl;
    cout << "===============================================================\n";

    return 0;
}
