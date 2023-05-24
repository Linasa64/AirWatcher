/*************************************************************************
                           ControllerComputation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ControllerComputation> (fichier ControllerComputation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ControllerComputation.h"

//------------------------------------------------------------- Constantes
//const float ControllerComputation::EARTH_RADIUS = 6371.0;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ControllerComputation::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/* ControllerComputation & ControllerComputation::operator = ( const ControllerComputation & unControllerComputation )
// Algorithme :
//
{
} //----- Fin de operator = */

//-------------------------------------------- Constructeurs - destructeur
ControllerComputation::ControllerComputation(const ControllerComputation &unControllerComputation)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ControllerComputation>" << endl;
#endif
} //----- Fin de ControllerComputation (constructeur de copie)

ControllerComputation::ControllerComputation()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ControllerComputation>" << endl;
#endif
} //----- Fin de ControllerComputation

ControllerComputation::~ControllerComputation()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ControllerComputation>" << endl;
#endif
} //----- Fin de ~ControllerComputation

float ControllerComputation::calculateMeanAirQuality(const Database &database, float radius, float centerLat, float centerLong, const std::string &startTime, const std::string &endTime)
{
    map<string, Sensor *> sensors = database.GetSensors();
    float airQuality = 0;
    int count = 0;
    for (auto sensor : sensors)
    {
        if (sensor.second->isWithinDistance(centerLat, centerLong, radius))
        {
            for (auto measurement : sensor.second->GetMeasurements())
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    airQuality += measurement->getValue();
                    count++;
                }
            }
        }
    }
    if (count == 0)
    {
        return 0.0; 
    }
    else
    {
        return airQuality / static_cast<float>(count);
    }
}

/*std::vector<Sensor> ControllerComputation::calculateSimilarityScores(const Database &database, Sensor selectedSensor, const std::string& startTime, const std::string& endTime) 
{
    set<Sensor> sensors = database.GetSensors();
    std::vector<Sensor> similarityScores;
    for (auto sensor : sensors)
    {
        if (sensor.GetSensorId() != selectedSensor.GetSensorId()) {
            float costFunctionScore = 0.0;
            for (auto measurement : sensor.GetMeasurements())
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    costFunctionScore += std::abs(measurement->getValue() - selectedSensor.GetMeasurement()->getValue());
                    similarityScores.push_back({sensor.sensorId, costFunctionScore});
                }
            }
        }
    }
    std::sort(similarityScores.begin(), similarityScores.end(), [](const SensorMeasurement& a, const SensorMeasurement& b) {
        return a.value < b.value;
    });

    return similarityScores;
}*/

std::vector<std::pair<Sensor, float>> ControllerComputation::calculateSimilarityScores(const Database& database, const Sensor& selectedSensor, const std::string& startTime, const std::string& endTime)
{
    std::map<string, Sensor *> sensors = database.GetSensors();
    std::map<Sensor, float> similarityScores;

    for (auto sensor : sensors)
    {
        if (sensor.second->GetSensorId() != selectedSensor.GetSensorId())
        {
            float costFunctionScore = 0.0;
            const std::list<Measurement*>& sensorMeasurements = sensor.second->GetMeasurements();
            const std::list<Measurement*>& selectedSensorMeasurements = selectedSensor.GetMeasurements();

            for (const Measurement* measurement : sensorMeasurements)
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    const Measurement* selectedMeasurement = findMeasurement(selectedSensorMeasurements, measurement->getTimestamp());
                    if (selectedMeasurement != nullptr)
                    {
                        costFunctionScore += std::abs(measurement->getValue() - selectedMeasurement->getValue());
                    }
                }
            }
            similarityScores[*sensor.second] = costFunctionScore;
        }
    }

    std::vector<std::pair<Sensor, float>> sortedScores(similarityScores.begin(), similarityScores.end());

    std::sort(sortedScores.begin(), sortedScores.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    return sortedScores;
}

const Measurement* ControllerComputation::findMeasurement(const std::list<Measurement*>& measurements, const time_t& timestamp) const
{
    for (const Measurement* measurement : measurements)
    {
        if (measurement->getTimestamp() == timestamp)
        {
            return measurement;
        }
    }
    return nullptr;
}


float ControllerComputation::calculatePreciseAirQuality(const Database& database, float centerLat, float centerLong, const std::string& startTime, const std::string& endTime)
{
    bool sensorFound = false;
    const std::map<string, Sensor *>& sensors = database.GetSensors();

    for (auto sensor : sensors)
    {
        if (sensor.second->GetLatitude() == centerLat && sensor.second->GetLongitude() == centerLong)
        {
            sensorFound = true;
            float meanValue = calculateMean(sensor.second->GetMeasurements(), startTime, endTime);
            return meanValue;
        }
    }

    if (!sensorFound)
    {
        std::vector<Sensor*> nearestSensors = kNearestSensors(sensors, centerLat, centerLong, startTime, endTime, 10);
        float weightedSum = 0.0;
        float totalWeight = 0.0;
        for(Sensor * sensor : nearestSensors){
            for (Measurement* measurement : sensor->GetMeasurements())
            {
                float distance = calculateDistance(sensor->GetLatitude(),sensor->GetLongitude(), centerLat, centerLong);
                float weight = 1.0 / distance;
                weightedSum += weight * measurement->getValue();
                totalWeight += weight;
            }
        }

        if (totalWeight != 0.0)
        {
            float weightedAverage = weightedSum / totalWeight;
            return weightedAverage;
        }
    }

    return -1.0;
}

std::vector<Sensor*> ControllerComputation::kNearestSensors(const std::map<string, Sensor *>& sensors, float centerLat, float centerLong, const std::string& startTime, const std::string& endTime, int k)
{
    std::vector<std::pair<Sensor*, float> > sensordistances;

    for (auto sensor : sensors)
    {
        for (Measurement* measurement : sensor.second->GetMeasurements())
        {
            if (measurement->isWithinTimeRange(startTime, endTime))
            {
                float distance = calculateDistance(sensor.second->GetLatitude(), sensor.second->GetLongitude(), centerLat, centerLong);
                sensordistances.push_back({ const_cast<Sensor*>(sensor.second), distance });
            }
        }
    }

    std::sort(sensordistances.begin(), sensordistances.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::vector<Sensor*> kNearestSensors;
    int numSensors = std::min(k, static_cast<int>( sensordistances.size()));

    for (int i = 0; i < numSensors; ++i)
    {
        kNearestSensors.push_back(sensordistances[i].first);
    }

    return kNearestSensors;
}

float ControllerComputation::calculateDistance(float lat1, float long1, float lat2, float long2)
{
    float dLat = degToRad(lat2 - lat1);
    float dLong = degToRad(long2 - long1);

    float a = std::sin(dLat / 2) * std::sin(dLat / 2) +
        std::cos(degToRad(lat1)) * std::cos(degToRad(lat2)) *
        std::sin(dLong / 2) * std::sin(dLong / 2);

    float c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    float distance = EARTH_RADIUS * c;

    return distance;
}

float ControllerComputation::calculateMean(const std::list<Measurement*>& measurements, const std::string& startTime, const std::string& endTime)
{
    int count = 0;
    float sum = 0.0;

    for (Measurement* measurement : measurements)
    {
        if (measurement->isWithinTimeRange(startTime, endTime))
        {
            sum += measurement->getValue();
            count++;
        }
    }

    if (count > 0)
    {
        float meanValue = sum / count;
        return meanValue;
    }

    return -1.0;
}


std::pair<std::vector<Sensor>, std::vector<std::vector<float>>> ControllerComputation::detectDefectSensorsAndOutliers(const Database& database, const string& startTime, const string& endTime)
{
    const std::map<string, Sensor*>& sensors = database.GetSensors();
    std::vector<Sensor> defectSensors;
    std::vector<std::vector<float>> outliers;
    std::vector<float> allMeasurements;

    for (auto sensor : sensors)
    {
        for (Measurement* measurement : sensor.second->GetMeasurements())
        {
            if (!(startTime.empty()) && !(endTime.empty()))
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    allMeasurements.push_back(measurement->getValue());
                }
            }
            else
            {
                allMeasurements.push_back(measurement->getValue());
            }
        }
    }

    if (!allMeasurements.empty())
    {
        float mean, stdDev;
        calculateMeanAndStdDev(allMeasurements, mean, stdDev);

        const float lowerThreshold = calculatePercentile(allMeasurements, 5);
        const float upperThreshold = calculatePercentile(allMeasurements, 95);


        for (auto sensor : sensors)
        {
            std::vector<float> filteredValues;
            std::vector<float> sensorOutliers;
            bool sensorDefect = false;
            for (Measurement* measurement : sensor.second->GetMeasurements())
            {
                if (!(startTime.empty()) && !(endTime.empty()))
                {
                    if(measurement->isWithinTimeRange(startTime, endTime))
                    {
                        float value = measurement->getValue();

                        if (value < lowerThreshold || value > upperThreshold)
                        {
                            sensorOutliers.push_back(value);
                            sensorDefect = true;
                        }
                    }
                } 
            }
            if (sensorDefect)
            {
                defectSensors.push_back(*sensor.second);
                outliers.push_back(sensorOutliers);
            }
        }   
    }
    return std::make_pair(defectSensors, outliers);
}

/*
std::pair<std::vector<Sensor>, std::vector<std::vector<float>>> ControllerComputation::detectDefectSensorsAndOutliers(const Database& database, const std::optional<std::string>& startTime, const std::optional<std::string>& endTime)
{
    const std::set<Sensor>& sensors = database.GetSensors();
    std::vector<Sensor> defectSensors;
    std::vector<std::vector<float>> outliers;

    for (const Sensor& sensor : sensors)
    {
        std::vector<float> filteredValues;

        for (Measurement* measurement : sensor.GetMeasurements())
        {
            if (startTime && endTime)
            {
                if (measurement->isWithinTimeRange(startTime.value(), endTime.value()))
                {
                    filteredValues.push_back(measurement->GetValue());
                }
            }
            else
            {
                filteredValues.push_back(measurement->GetValue());
            }
        }

        if (!filteredValues.empty())
        {
            float mean, stdDev;
            calculateMeanAndStdDev(filteredValues, mean, stdDev);

            bool sensorDefect = false;
            std::vector<float> sensorOutliers;

            for (float value : filteredValues)
            {
                if (value < mean - 2 * stdDev || value > mean + 2 * stdDev)
                {
                    sensorOutliers.push_back(value);
                    sensorDefect = true;
                }
            }

            if (sensorDefect)
            {
                defectSensors.push_back(sensor);
                outliers.push_back(sensorOutliers);
            }
        }
    }

    return std::make_pair(defectSensors, outliers);
}
*/

void ControllerComputation::calculateMeanAndStdDev(const std::vector<float>& values, float& mean, float& stdDev)
{
    if (values.empty())
    {
        mean = 0.0;
        stdDev = 0.0;
        return;
    }

    float sum = 0.0;
    int count = values.size();

    for (float value : values)
    {
        sum += value;
    }

    mean = sum / count;

    float variance = 0.0;
    for (float value : values)
    {
        variance += std::pow(value - mean, 2);
    }

    stdDev = std::sqrt(variance / count);
}

float ControllerComputation::calculatePercentile(const std::vector<float>& values, int percentile)
{
    if (values.empty())
    {
        return 0.0;
    }

    std::vector<float> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());

    int index = (percentile * (sortedValues.size() - 1)) / 100;
    float fractionalPart = (percentile * (sortedValues.size() - 1)) % 100;

    if (index >= sortedValues.size() - 1)
    {
        return sortedValues.back();
    }
    else
    {
        return sortedValues[index] + fractionalPart * (sortedValues[index + 1] - sortedValues[index]) / 100;
    }
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

