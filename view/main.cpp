/*
#include "Cleaner.h"
#include "Database.h""

 */
#include "../model/Cleaner.h"
#include "../model/Measurement.h"
#include "../model/User.h"
#include "../model/GovernmentAgency.h"
#include "../model/Provider.h"
#include "../model/PrivateUser.h"
#include "../model/Sensor.h"
#include "../model/Attributes.h"
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include "../controller/ControllerData.h"
#include "../controller/ControllerComputation.h"
#include "../model/Database.h"
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;

int main()
{
    ControllerData controllerData;
    ControllerComputation controllerComputation;

    Database d = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");

    // TESTS TEMPS time_t
    /* time_t t1, t2, t3;
    t1 = convertDateStingToTimestamp("2019-03-01 12:00:00");
    t2 = convertDateStingToTimestamp("2019-04-01 12:00:00");
    t3 = t2 - t1;
    cout << "DATE TEST : " << t3 << endl; */

    // TESTS2 TEMPS time_t
    /*
        float timeStart, timeEnd, timeDiff;

        // On stocke le temps initial
        timeStart = clock();

        // Créer une structure tm qui contient les informations sur la date et l'heure
        tm datetime = {};
        datetime.tm_year = 2022 - 1900; // année - 1900
        datetime.tm_mon = 0; // mois (janvier est 0)
        datetime.tm_mday = 1; // jour du mois (1-31)
        datetime.tm_hour = 12; // heure (0-23)
        datetime.tm_min = 30; // minute (0-59)
        datetime.tm_sec = 0; // seconde (0-60)

        // Convertir la structure tm en time_t
        time_t timestamp = mktime(&datetime);
        time_t now = time(0);

        // Utiliser le timestamp
        cout << "Le timestamp est : " << timestamp << endl;

        cout << "Maintenant : " << now << endl;

        cout << "hello new version here" << endl;

        // On stocke le temps final
        timeEnd = clock();

        // On fait la différence temps final - temps initial et on met en ms
        timeDiff = (timeEnd - timeStart)/(CLOCKS_PER_SEC/1000);
        cout << "Temps exécution : " << timeDiff << "ms" << endl; */

    // TEST STRUCTURE DE DONNEES CONTENANT DES USER*
    /*     User* user[] =
        {
            new Provider("Provider0"),
            new PrivateUser("User1"),
            new GovernmentAgency()
        };

        for (int i = 0 ; i < 3 ; i++) {
            cout << "User " << i << ": " << user[i]->to_string();
        } */

    // cout << d.to_string();

    // =================================TESTS================================= //

    // ================INDICES ATMO================ //
    // Avec durée
    float testATMO1 = controllerComputation.calculateMeanAirQualityATMO(d, 10, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << "Indice ATMO 1 : " << testATMO1 << endl;

    // Avec instant
    float testATMO2 = controllerComputation.calculateMeanAirQualityATMO(d, 10, 44, -1, "2019-01-01 12:00:00");
    cout << "Indice ATMO 2 : " << testATMO2 << endl;

    // ================INDICES AQI================ //
    // Avec durée
    float testAQI1 = controllerComputation.calculateMeanAirQualityAQI(d, 10, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    cout << "Indice AQI 1 : " << testAQI1 << endl;

    // Avec instant
    float testAQI2 = controllerComputation.calculateMeanAirQualityAQI(d, 10, 44, -1, "2019-01-01 12:00:00");
    cout << "Indice AQI 2 : " << testAQI2 << endl;

    cout << controllerComputation.GetHistory().to_string();

    return 0;
}
