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
    cout << "Extraction des données en cours..." << endl;
    Database d = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");
    cout << "Extraction des données terminée !" << endl;
    cout << "===============================================================\n"
         << endl;
    cout << "\t\t   Bienvenue sur AirWatcher !" << endl
         << endl;

    while (1)
    {
    connexion:
        cout << "========================Qui êtes-vous ?========================\n"
             << endl;
        cout << "\t1: Agence gouvernementale" << endl;
        cout << "\t2: Utilisateur privé" << endl;
        cout << "\t3: Agence de purification de l'air" << endl;
        cout << "\t0: Quitter\n"
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
            cout << "========================Menu (Gouvernement)========================\n"
                 << endl;
            cout << "\t1: Consulter le niveau de qualité de l'air en un point" << endl;
            cout << "\t2: Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << "\t3: Observer des similarités entre des capteurs" << endl;
            cout << "\t4: Vérifier la fiabilité des données des capteurs" << endl;
            cout << "\t5: Consulter la performance des algorithmes de calcul" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            float latitude, longitude, rayon;
            string selectedSensor;
            vector<pair<Sensor *, float>> classement;
            int count, idAlgo;
            Sensor *s;
            pair<vector<Sensor *>, vector<vector<float>>> testDefectSensors2;
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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

                cout << "==========Résultats==========\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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
                cout << "==========Résultats==========\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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

                cout << "==========Résultats==========\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                switch (choix)
                {
                case 1:
                    cout << "\nTemps de fin au format yyyy-MM-dd hh-mm-ss (exemple : '2019-01-01 12:00:00') : ";
                    getline(cin >> ws, tempsFin);
                    cout << endl;

                    testDefectSensors2 = controllerComputation.detectDefectSensorsAndOutliers(d, tempsDebut, tempsFin);
                    break;
                default:
                    testDefectSensors2 = controllerComputation.detectDefectSensorsAndOutliers(d, tempsDebut);
                }

                cout << "==========Résultats==========\n"
                     << endl;
                cout << "Capteurs défectueux :\n"
                     << endl;
                for (auto it = testDefectSensors2.first.begin(); it != testDefectSensors2.first.end(); ++it)
                {
                    cout << " • " << (*it)->ToString() << endl;
                }
                cout << "Valeurs aberrantes :\n"
                     << endl;
                for (auto it = testDefectSensors2.second.begin(); it != testDefectSensors2.second.end(); ++it)
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
                cout << "\t1: Performances d'un algorithme donné" << endl;
                cout << "\t2: Performances de tous les algorithmes" << endl;

                cin >> choixS;
                cout << endl;

                choix = atoi(choixS.c_str());

                switch (choix)
                {
                case 1:

                    cout << "\nID de l'algorithme :\n"
                         << endl;
                    cout << "\t1: Calcul de la qualité de l'air en un point précis (ATMO/AQI)" << endl;
                    cout << "\t2: Calcul de la qualité de l'air dans un rayon (ATMO/AQI)" << endl;
                    cout << "\t3: Calcul des similarités entre capteurs" << endl;
                    cout << "\t4: Analyse les données (mesures erronées)" << endl;
                    cin >> idAlgo;
                    cout << endl;

                    cout << "==========Résultats==========\n"
                         << endl;
                    cout << controllerComputation.GetHistory().AlgoToString(idAlgo);
                    break;
                case 2:
                    cout << "==========Résultats==========\n"
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
            cout << "========================Menu (Utilisateur privé)========================\n"
                 << endl;
            cout << "\t1: Consulter le niveau de qualité de l'air en un point" << endl;
            cout << "\t2: Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << "\t0: Se déconnecter\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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

                cout << "==========Résultats==========\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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
                cout << "==========Résultats==========\n"
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
            cout << "========================Menu (Agence de purification)========================\n"
                 << endl;
            cout << "\t1: Consulter le niveau de qualité de l'air en un point" << endl;
            cout << "\t2: Consulter le niveau moyen de qualité de l'air dans un rayon" << endl;
            cout << "\t0: Se déconnecter\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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

                cout << "==========Résultats==========\n"
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
                cout << "\t1: Oui" << endl;
                cout << "\t0: Non" << endl;

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
                cout << "==========Résultats==========\n"
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
    cout << "Fermeture de l'application" << endl;
    cout << "===============================================================\n";

    cout << "\n=================================TESTS=================================\n";
    // ================INDICES ATMO================ //
    // Avec durée
    float testATMO1 = controllerComputation.calculateMeanAirQualityATMO(d, 10, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << "Indice ATMO 1 : " << testATMO1 << endl;

    // Avec instant
    float testATMO2 = controllerComputation.calculateMeanAirQualityATMO(d, 0.1, 44.2, -1.2, "2019-01-01 12:00:00");
    cout << "Indice ATMO 2 : " << testATMO2 << endl;

    // ================INDICES AQI================ //
    // Avec durée
    float testAQI1 = controllerComputation.calculateMeanAirQualityAQI(d, 10, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << "Indice AQI 1 : " << testAQI1 << endl;

    // Avec instant
    float testAQI2 = controllerComputation.calculateMeanAirQualityAQI(d, 10, 44, -1, "2019-01-01 12:00:00");
    cout << "Indice AQI 2 : " << testAQI2 << endl;

    // ================TEST SIMILARITY SCORES================ //
    // calculateSimilarityScores(const Database &database, const Sensor &selectedSensor, const string &startTime, const string &endTime);
    Sensor *s = d.GetSensor("Sensor1");
    vector<pair<Sensor *, float>> classement = controllerComputation.calculateSimilarityScores(d, *s, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << " ====================TESTS SCORES SIMILARITÉ CAPTEURS==================== " << endl;
    cout << "Classement : " << endl;
    int rankLimit = 10;
    int count = 0;
    for (auto it = classement.begin(); it != classement.end() && count < rankLimit; ++it)
    {
        cout << "\t" << ++count << " - " << it->first->ToString() << "\t-> " << it->second << endl
             << endl;
    }

    // ================TESTS PRECISE QUALITY================ //
    cout << " ====================TESTS QUALITÉ PRÉCISE==================== " << endl;
    float testPreciseQualityATMO = controllerComputation.calculatePreciseAirQualityATMO(d, 44, -1, "2019-01-01 12:00:00");
    float testPreciseQualityAQI = controllerComputation.calculatePreciseAirQualityAQI(d, 44, -1, "2019-01-01 12:00:00");
    cout << "Qualité précise ATMO : " << testPreciseQualityATMO << endl;
    cout << "Qualité précise AQI : " << testPreciseQualityAQI << endl;

    // ================TESTS DEFECT SENSORS================ //
    cout << " ====================TESTS CAPTEURS DÉFECTUEUX==================== " << endl;
    pair<vector<Sensor *>, vector<vector<float>>> testDefectSensors2 = controllerComputation.detectDefectSensorsAndOutliers(d, "2019-01-01 12:00:00");
    cout << "Capteurs défectueux : " << endl;
    for (auto it = testDefectSensors2.first.begin(); it != testDefectSensors2.first.end(); ++it)
    {
        cout << (*it)->ToString() << endl;
    }
    cout << "Valeurs aberrantes : " << endl;
    for (auto it = testDefectSensors2.second.begin(); it != testDefectSensors2.second.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }

    // ====================TESTS AUTRES==================== //
    cout << controllerComputation.GetHistory().ToString() << endl;

    cout << "Moyenne algo 1 : " << controllerComputation.computeAlgoPerformanceMean(1) << endl;
    cout << "Moyenne algo 2 : " << controllerComputation.computeAlgoPerformanceMean(2) << endl;
    cout << "Moyenne algo 3 : " << controllerComputation.computeAlgoPerformanceMean(3) << endl;
    cout << "Moyenne algo 4 : " << controllerComputation.computeAlgoPerformanceMean(4) << endl;

    cout << "Test distance : " << controllerComputation.calculateDistance(45.77849365407452, 4.871326879873561, 45.778733098569106, 4.91003651992487) << endl;
    cout << controllerComputation.GetHistory().AlgoToString(1) << endl;
    return 0;
}
