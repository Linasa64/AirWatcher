/*************************************************************************
                           ControllerComputation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ControllerComputation> (fichier ControllerComputation.h) ----------------
#if !defined(CONTROLLERCOMPUTATION_H)
#define CONTROLLERCOMPUTATION_H

//--------------------------------------------------- Interfaces utilisées
#include "../model/Database.h"
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <array>
#include <functional>
//------------------------------------------------------------- Constantes
//const float EARTH_RADIUS = 6371.0;
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

    float calculateMeanAirQualityATMO(const Database &sensorMeasurements, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    float calculateMeanAirQualityAQI(const Database &sensorMeasurements, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime = "");

    std::vector<std::pair<Sensor, float>> calculateSimilarityScores(const Database& database, const Sensor& selectedSensor, const std::string& startTime, const std::string& endTime);
    
    float calculatePreciseAirQuality(const Database& database, float centerLat, float centerLong, const std::string& startTime, const std::string& endTime);

    std::vector<Sensor*> kNearestSensors(const std::map<string, Sensor*>& sensors, float centerLat, float centerLong, const std::string& startTime, const std::string& endTime, int k);

    float calculateDistance(float lat1, float long1, float lat2, float long2);

    float calculateMean(const std::list<Measurement*>& measurements, const std::string& startTime, const std::string& endTime);

    std::pair<std::vector<Sensor>, std::vector<std::vector<float>>> detectDefectSensorsAndOutliers(const Database& database, const string& startTime, const string& endTime);

    void calculateMeanAndStdDev(const std::vector<float>& values, float& mean, float& stdDev);

    std::vector<float> filterMeasurementsByTime(const std::vector<float>& measurements, const std::string& startTime, const std::string& endTime);

    float calculatePercentile(const std::vector<float>& values, int percentile);


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
    //Database filterMeasurementsByTime(const Database &sensorMeasurements, const string &startTime, const string &endTime);
    //Database filterMeasurementsByDistance(const Database &sensorMeasurements, float centerLat, float centerLong, float radius);
    //bool isWithinTimeRange(const string &timestamp, const string &startTime, const string &endTime);
    //bool isWithinDistance(float measurementLat, float measurementLong, float centerLat, float centerLong, float radius);
    //time_t convertDateStingToTimestamp(const string &dateString);
    //float degToRad(float degrees);
    const Measurement* findMeasurement(const std::list<Measurement*>& measurements, const time_t& timestamp) const;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ControllerComputation>

#endif // CONTROLLERCOMPUTATION_H
