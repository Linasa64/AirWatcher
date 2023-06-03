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

//-------------------------------------------------------- STATIC
static int tries = 0;
static int successes = 0;
static int globalTries = 0;
static int globalSuccesses = 0;

static ControllerData controllerData;
static ControllerComputation controllerComputation;
static Database database = controllerData.retrieveData("./dataset/sensors.csv", "./dataset/measurements.csv", "./dataset/attributes.csv", "./dataset/providers.csv", "./dataset/cleaners.csv", "./dataset/users.csv");
static Database dbTest1 = controllerData.retrieveData("./tests/datatests/test1/sensors.csv", "./tests/datatests/test1/measurements.csv", "./tests/datatests/test1/attributes.csv", "./tests/datatests/test1/providers.csv", "./tests/datatests/test1/cleaners.csv", "./tests/datatests/test1/users.csv");
static Database dbTest2 = controllerData.retrieveData("./tests/datatests/test2/sensors.csv", "./tests/datatests/test2/measurements.csv", "./tests/datatests/test2/attributes.csv", "./tests/datatests/test2/providers.csv", "./tests/datatests/test2/cleaners.csv", "./tests/datatests/test2/users.csv");

//==================Declarations==================//

// User class
void testUserClass();

void testGetId();

// History class
void testHistoryClass();

void testGetAlgoPerformanceHistory();
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

// Others
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
         << BOLD << "-> BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe HISTORY=====================\n"
         << RESET << endl;
    testHistoryClass();

    cout << endl
         << BOLD << "-> BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe CONTROLLER COMPUTATION=====================\n"
         << RESET << endl;
    testControllerComputationClass();

    cout << endl
         << BOLD << "-> BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "=====================Classe CONTROLLER DATA=====================\n"
         << RESET << endl;
    testControllerDataClass();

    cout << endl
         << BOLD << "-> BILAN : " << RESET << endl;
    displayTestsResults();
    cout << endl;

    cout << BOLD << "==========================BILAN FINAL==========================\n"
         << RESET << endl;
    displayFinalResults();

    return 0;
}

//==================Definitions==================//
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
    cout << CYAN << "[1/2]" << RESET << " TestGetAlgoPerformanceHistory() : ";
    testGetAlgoPerformanceHistory();

    cout << CYAN << "[2/2]" << RESET << " TestComputeMean() : ";
    testComputeMean();
}

void testGetAlgoPerformanceHistory()
{
    ++tries;
    bool success = false;

    History h1, h2, h3;
    for (int n = 1; n <= 20; n++)
    {
        h1.Push_Back(0, n);
        h1.Push_Back(1, 10);
        h2.Push_Back(0, 1);
    }

    if (h1.GetQueryDurationsHistory()[0].front() == 1 &&
        h1.GetQueryDurationsHistory()[0].back() == 20 &&
        h1.GetQueryDurationsHistory()[1].front() == 10 &&
        h1.GetQueryDurationsHistory()[1].back() == 10 &&
        h2.GetQueryDurationsHistory()[0].front() == 1 &&
        h2.GetQueryDurationsHistory()[0].back() == 1)
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