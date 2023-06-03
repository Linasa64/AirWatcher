/*************************************************************************
                           ControllerComputation  -  description
                             -------------------
    début                : 10/05/2023
    copyright            : (C) 2023 par Dominique, Lina, Mark, Raphaël et Rémy
    e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ControllerComputation> (fichier ControllerComputation.h) ----------------
#if !defined(CONTROLLERCOMPUTATION_H)
#define CONTROLLERCOMPUTATION_H

//--------------------------------------------------- Interfaces utilisées
#include "../model/Database.h"
#include "History.h"
#include <string>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <array>
#include <functional>
#include <ctime>
#include <shared_mutex>
//------------------------------------------------------------- Constantes
// const float EARTH_RADIUS = 6371.0;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ControllerComputation>
//
//
//------------------------------------------------------------------------

class ControllerComputation
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    History &GetHistory();

    float calculateMeanAirQualityATMO(const Database &sensorMeasurements, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    float calculateMeanAirQualityAQI(const Database &sensorMeasurements, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    vector<pair<Sensor *, float>> calculateSimilarityScores(const Database &database, const Sensor &selectedSensor, const string &startTime, const string &optionalEndTime = "");

    float calculatePreciseAirQualityATMO(const Database &database, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    float calculatePreciseAirQualityAQI(const Database &database, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    vector<Sensor *> kNearestSensors(const map<string, Sensor *> &sensors, float centerLat, float centerLong, const string &startTime, const string &endTime, int k);

    float calculateDistance(float lat1, float long1, float lat2, float long2);

    float calculateMeanATMO(const list<Measurement *> &measurements, const string &startTime, const string &endTime);

    float calculateMeanAQI(const list<Measurement *> &measurements, const string &startTime, const string &endTime);

    pair<vector<Sensor *>, vector<vector<float>>> detectDefectSensorsAndOutliers(const Database &database, const string &startTime, const string &optionalEndTime = "");

    // pair<vector<shared_ptr<Sensor>>, vector<vector<float>>> detectDefectSensorsAndOutliers2(const Database &database, const string &startTime, const string &endTime);

    void calculateMeanAndStdDev(const vector<float> &values, float &mean, float &stdDev);

    float calculatePercentile(const vector<float> &values, int percentile);

    float computeAlgoPerformanceMean(int idAlgo);

    // float calculatePercentileFromDatabase(const Database& database, int percentile, const string& startTime, const string& endTime);

    //------------------------------------------------- Surcharge d'opérateurs
    ControllerComputation &operator=(const ControllerComputation &unControllerComputation);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    ControllerComputation(const ControllerComputation &unControllerComputation);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ControllerComputation();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ControllerComputation();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    History history;

    const Measurement *findMeasurement(const list<Measurement *> &measurements, const time_t &timestamp) const;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ControllerComputation>

#endif // CONTROLLERCOMPUTATION_H
