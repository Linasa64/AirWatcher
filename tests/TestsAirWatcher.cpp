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

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

static int tries = 0;
static int successes = 0;
static int globalTries = 0;
static int globalSuccesses = 0;

static ControllerData controllerData;
static ControllerComputation controllerComputation;
static Database database = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");
static Database dbTest1 = controllerData.retrieveData("./tests/datatests/test1/sensors.csv", "./tests/datatests/test1/measurements.csv", "./tests/datatests/test1/attributes.csv", "./tests/datatests/test1/providers.csv", "./tests/datatests/test1/cleaners.csv", "./tests/datatests/test1/users.csv");
static Database dbTest2 = controllerData.retrieveData("./tests/datatests/test2/sensors.csv", "./tests/datatests/test2/measurements.csv", "./tests/datatests/test2/attributes.csv", "./tests/datatests/test2/providers.csv", "./tests/datatests/test2/cleaners.csv", "./tests/datatests/test2/users.csv");

// User class
void testUserClass();

void testGetId();

// History class
void testHistoryClass();

void testComputeMean();

// ControllerComputation class
void testControllerComputationClass();

void testCalculateMeanAirQualityATMO();
void testCalculateMeanAirQualityAQI();
void testCalculatePreciseAirQualityATMO();
void testCalculatePreciseAirQualityAQI();
void testCalculateSimilarityScores();
void testDetectDefectSensorsAndOutliers();
void testCalculateDistance();

// ControllerData class
void testControllerDataClass();

void testRetrieveData();


// Other functions
void resetTriesSuccesses();

void displayTestsResults();

void displayFinalResults();

// Main
int main()
{
    cout << "Extraction des données terminée !" << endl;
    cout << "===============================================================\n"
         << endl;

    cout << BOLD << "=====================Classe USER=====================\n"
         << RESET << endl;
    testUserClass();

    cout << endl
         << BOLD << "BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe HISTORY=====================\n"
         << RESET << endl;
    testHistoryClass();

    cout << endl
         << BOLD << "BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe CONTROLLER COMPUTATION=====================\n"
         << RESET << endl;
    testControllerComputationClass();

    cout << endl
         << BOLD << "BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe CONTROLLER DATA=====================\n"
         << RESET << endl;
    testControllerDataClass();

    cout << endl
         << BOLD << "BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "==========================BILAN FINAL==========================\n"
         << RESET << endl;
    displayFinalResults();

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
            cout << "User " << i << ": " << user[i]->ToString();
        } */

    // cout << d.ToString();

    /*     // =================================TESTS================================= //

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

        // ================TEST SIMILARITY SCORES================ //
        // Avec durée
        // calculateSimilarityScores(const Database &database, const Sensor &selectedSensor, const std::string &startTime, const std::string &endTime);
        Sensor *s = d.GetSensor("Sensor1");
        std::vector<std::pair<Sensor *, float>> classement = controllerComputation.calculateSimilarityScores(d, *s, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
        cout << " ====================TESTS SCORES SIMILARITÈ CAPTEURS==================== " << endl;
        cout << "Classement : " << endl;
        for (auto it = classement.begin(); it != classement.end(); ++it)
        {
            cout << it->first->ToString() << " : " << it->second << endl;
        }

        // ================TESTS PRECISE QUALITY================ //
        // Avec durée
        cout << " ====================TESTS QUALITÈ PRÈCISE==================== " << endl;
        float testPreciseQualityATMO = controllerComputation.calculatePreciseAirQualityATMO(d, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
        float testPreciseQualityAQI = controllerComputation.calculatePreciseAirQualityAQI(d, 44, -1, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
        cout << "Qualité précise ATMO : " << testPreciseQualityATMO << endl;
        cout << "Qualité précise AQI : " << testPreciseQualityAQI << endl;

        // ================TESTS DEFECT SENSORS================ //
        // Avec durée
        cout << " ====================TESTS CAPTEURS DÉFECTUEUX==================== " << endl;
        std::pair<std::vector<Sensor *>, std::vector<std::vector<float>>> testDefectSensors2 = controllerComputation.detectDefectSensorsAndOutliers(d, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
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

        // ====================TESTS==================== //
        cout << controllerComputation.GetHistory().ToString(); */

    return 0;
}

// Definitions
void resetTriesSuccesses()
{
    globalTries += tries;
    globalSuccesses += successes;

    tries = 0;
    successes = 0;
}

void displayTestsResults()
{
    float successRate;

    successRate = ((float)successes / tries) * 100;

    cout << "Tests effectués : " << BOLD << tries << RESET << " / Tests réussis : " << BOLD << successes << RESET << endl;
    cout << "Taux de réussite : " << BOLD << successRate << "%" << RESET << endl;
}

void displayFinalResults()
{
    resetTriesSuccesses();

    float globalSuccessRate;

    globalSuccessRate = ((float)globalSuccesses / globalTries) * 100;

    cout << "Total de tests effectués : " << BOLD << globalTries << RESET << " / Total de tests réussis : " << BOLD << globalSuccesses << RESET << endl;
    cout << "Taux de réussite total : " << BOLD << globalSuccessRate << RESET << "%" << endl;
    cout << "===============================================================\n";
}

void testUserClass()
{
    resetTriesSuccesses();
    cout << CYAN << CYAN << "[1/1]" << RESET << " TestGetId() : ";
    testGetId();
}

void testGetId()
{
    ++tries;
    bool success = false;

    User *user = database.GetUsers()["User0"];

    User *gouv = new GovernmentAgency();

    User *provider = database.GetUsers()["Provider0"];

    if (user->GetId() == "User0" &&
        gouv->GetId() == "Government" &&
        provider->GetId() == "Provider0")
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testHistoryClass()
{
    resetTriesSuccesses();
    cout << CYAN << "[1/1]" << RESET << " TestComputeMean() : ";
    testComputeMean();
}

void testComputeMean()
{
    ++tries;
    bool success = false;

    History h1, h2, h3;
    for (int n = 1; n <= 20; n++)
    {
        h1.Push_Back(0, n);
        h2.Push_Back(0, 1);
    }

    if (h1.computeMean(0) == 10.5 &&
        h2.computeMean(0) == 1 &&
        h3.computeMean(0) == -1 &&
        h3.computeMean(42) == -1)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testControllerComputationClass()
{
    resetTriesSuccesses();
    cout << CYAN << "[1/7]" << RESET << " TestCalculateMeanAirQualityATMO() : ";
    testCalculateMeanAirQualityATMO();
    cout << CYAN << "[2/7]" << RESET << " TestCalculateMeanAirQualityAQI() : ";
    testCalculateMeanAirQualityAQI();
    cout << CYAN << "[3/7]" << RESET << " TestCalculatePreciseAirQualityATMO() : ";
    testCalculatePreciseAirQualityATMO();
    cout << CYAN << "[4/7]" << RESET << " TestCalculatePreciseAirQualityAQI() : ";
    testCalculatePreciseAirQualityAQI();
    cout << CYAN << "[5/7]" << RESET << " TestCalculateSimilarityScores() : ";
    testCalculateSimilarityScores();
    cout << CYAN << "[6/7]" << RESET << " TestDetectDefectSensorsAndOutliers() : ";
    testDetectDefectSensorsAndOutliers();
    cout << CYAN << "[7/7]" << RESET << " TestCalculateDistance() : ";
    testCalculateDistance();
}

void testCalculateMeanAirQualityATMO()
{
    ++tries;
    bool success = false;

    if (controllerComputation.calculateMeanAirQualityATMO(database, 10, 44, -1, "2019-01-01 12:00:00") == 3.5)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testCalculateMeanAirQualityAQI()
{
    ++tries;
    bool success = false;

    if (controllerComputation.calculateMeanAirQualityAQI(dbTest1, 10, 44, -1, "2019-01-01 12:00:00") == 25 &&
        controllerComputation.calculateMeanAirQualityAQI(dbTest1, 10, 44, -0.3, "2019-01-01 12:00:00") == 50 &&
        controllerComputation.calculateMeanAirQualityAQI(dbTest1, 10, 44, 0.4, "2019-01-01 12:00:00") == 75 &&
        controllerComputation.calculateMeanAirQualityAQI(dbTest1, 200, 44, -1, "2019-01-01 12:00:00") == 50)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testCalculatePreciseAirQualityATMO()
{
    ++tries;
    bool success = false;

    if (controllerComputation.calculatePreciseAirQualityATMO(database, 44, -1, "2019-01-01 12:00:00") == 3.5)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testCalculatePreciseAirQualityAQI()
{
    ++tries;
    bool success = false;

    if (controllerComputation.calculatePreciseAirQualityAQI(dbTest1, 44, -1, "2019-01-01 12:00:00") == 25 &&
        controllerComputation.calculatePreciseAirQualityAQI(dbTest1, 44, -0.3, "2019-01-01 12:00:00") == 50 &&
        controllerComputation.calculatePreciseAirQualityAQI(dbTest1, 44, 0.4, "2019-01-01 12:00:00") == 75)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testCalculateSimilarityScores()
{
    ++tries;
    bool success = false;

    Sensor *s = dbTest2.GetSensor(("Sensor0"));

    vector<pair<Sensor *, float>> ranking = controllerComputation.calculateSimilarityScores(dbTest2, *s, "2019-01-01 12:00:00", "2019-01-02 12:00:00");
    if (ranking[0].first->GetSensorId() == "Sensor1")
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testDetectDefectSensorsAndOutliers()
{
    ++tries;
    bool success = false;

    pair<vector<Sensor *>, vector<vector<float>>> defectSensors = controllerComputation.detectDefectSensorsAndOutliers(database, "2019-01-01 12:00:00", "2019-01-02 12:00:00");

    if (defectSensors.first[0]->GetSensorId() == "Sensor36")
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testCalculateDistance()
{
    ++tries;
    bool success = false;

    if (controllerComputation.calculateDistance(45.77849365407452,
                                                4.871326879873561,
                                                45.778733098569106,
                                                4.91003651992487) == 3.00208950042724609375)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}

void testControllerDataClass()
{
    resetTriesSuccesses();
    cout << CYAN << "[1/1]" << RESET << " TestRetrieveData() : ";
    testRetrieveData();
}

void testRetrieveData()
{
    ++tries;
    bool success = false;

    if (database.GetAttributes().size() == 4 &&
        database.GetSensors().size() == 100 &&
        database.GetUsers().size() == 4)
        success = true;

    if (success)
    {
        ++successes;
        cout << GREEN << "succès" << RESET << endl;
    }
    else
    {
        cout << RED << "échec" << RESET << endl;
    }
}


/*     cout << "===============================================================\n";

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
    pair<vector<Sensor *>, vector<vector<float>>> defectSensors = controllerComputation.detectDefectSensorsAndOutliers(d, "2019-01-01 12:00:00");
    cout << "Capteurs défectueux : " << endl;
    for (auto it = defectSensors.first.begin(); it != defectSensors.first.end(); ++it)
    {
        cout << (*it)->ToString() << endl;
    }
    cout << "Valeurs aberrantes : " << endl;
    for (auto it = defectSensors.second.begin(); it != defectSensors.second.end(); ++it)
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
    cout << controllerComputation.GetHistory().AlgoToString(1) << endl; */