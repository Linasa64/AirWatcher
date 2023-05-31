/*************************************************************************
                           AirWatcher  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    int choix;

    cout << "--------------------------------------------------------" << endl;
    cout << "Bienvenue sur AirWatcher !" << endl
         << endl;

    while (1)
    {
    connexion:
        cout << "--------------------------Qui êtes-vous ?--------------------------\n"
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
            cout << "--------------------------Menu (Gov)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
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
            cout << "--------------------------Menu (Utilisateur privé)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
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
            cout << "--------------------------Menu (Agence)--------------------------\n"
                 << endl;
            cout << "\t1: Action1" << endl;
            cout << "\t2: Action2" << endl;
            cout << "\t3: Action3" << endl;
            cout << "\t0: Se déconnecter\n"
                 << endl;
            cin >> choixS;
            cout << endl;

            choix = atoi(choixS.c_str());

            switch (choix)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
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
    cout << "--------------------------------------------------------\n";

    ControllerData controllerData;
    ControllerComputation controllerComputation;

    Database d = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");

    // =================================TESTS================================= //

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
    // Avec durée
    // calculateSimilarityScores(const Database &database, const Sensor &selectedSensor, const string &startTime, const string &endTime);
    Sensor *s = d.GetSensor("Sensor1");
    vector<pair<Sensor *, float>> classement = controllerComputation.calculateSimilarityScores(d, *s, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << " ====================TESTS SCORES SIMILARITÈ CAPTEURS==================== " << endl;
    cout << "Classement : " << endl;
    for (auto it = classement.begin(); it != classement.end(); ++it)
    {
        cout << it->first->to_string() << " : " << it->second << endl;
    }

    // ================TESTS PRECISE QUALITY================ //
    // Avec durée
    cout << " ====================TESTS QUALITÈ PRÈCISE==================== " << endl;
    float testPreciseQualityATMO = controllerComputation.calculatePreciseAirQualityATMO(d, 44, -1, "2019-01-01 12:00:00");
    float testPreciseQualityAQI = controllerComputation.calculatePreciseAirQualityAQI(d, 44, -1, "2019-01-01 12:00:00");
    cout << "Qualité précise ATMO : " << testPreciseQualityATMO << endl;
    cout << "Qualité précise AQI : " << testPreciseQualityAQI << endl;

    // ================TESTS DEFECT SENSORS================ //
    // Avec durée
    cout << " ====================TESTS CAPTEURS DÉFECTUEUX==================== " << endl;
    pair<vector<Sensor *>, vector<vector<float>>> testDefectSensors2 = controllerComputation.detectDefectSensorsAndOutliers(d, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << "Capteurs défectueux : " << endl;
    for (auto it = testDefectSensors2.first.begin(); it != testDefectSensors2.first.end(); ++it)
    {
        cout << (*it)->to_string() << endl;
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

    // ====================TESTS==================== //
    cout << controllerComputation.GetHistory().to_string() << endl;
    cout << "Moyenne algo 1 : " << controllerComputation.computeAlgoPerformanceMean(1) << endl;
    cout << "Moyenne algo 2 : " << controllerComputation.computeAlgoPerformanceMean(2) << endl;
    cout << "Moyenne algo 3 : " << controllerComputation.computeAlgoPerformanceMean(3) << endl;
    cout << "Moyenne algo 4 : " << controllerComputation.computeAlgoPerformanceMean(4) << endl;

    cout << "Test distance : " << controllerComputation.calculateDistance(45.77849365407452, 4.871326879873561, 45.778733098569106, 4.91003651992487) << endl;

    return 0;
}
