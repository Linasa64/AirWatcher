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
// const float ControllerComputation::EARTH_RADIUS = 6371.0;
//----------------------------------------------------------------- PUBLIC
History &ControllerComputation::GetHistory() { return history; }
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

float ControllerComputation::calculateMeanAirQualityATMO(const Database &database, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime)
{
    float timeStart, timeEnd, timeDiff;

    // We store the initial time
    timeStart = clock();

    string endTime = optionalEndTime; // get rid of the const (necessary for a default value of the string)
    if (endTime == "")
        endTime = startTime; // if the endTime was not declared, it takes the same value as startTime

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
                    if (measurement->GetATMOIndex() > 0)
                    { // Verifying that the ATMO Index is valid (getATMOIndex returns -1 in error cases)
                        airQuality += measurement->GetATMOIndex();
                        count++;
                    } // If the ATMO Index was not valid we don't count the measurement
                }
            }
        }
    }
    if (count == 0)
    {
        // We store the final time
        timeEnd = clock();

        // We compute the difference final time - initial time and we convert it into ms
        timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
        cout << "Temps exécution : " << timeDiff << "ms" << endl;
        history.Push_Back(1, timeDiff);
        return 0.0;
    }
    else
    {
        // We store the final time
        timeEnd = clock();

        // We compute the difference final time - initial time and we convert it into ms
        timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
        cout << "Temps exécution : " << timeDiff << "ms" << endl;
        history.Push_Back(1, timeDiff);
        return airQuality / static_cast<float>(count);
    }
}

float ControllerComputation::calculateMeanAirQualityAQI(const Database &database, float radius, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime)
{
    float timeStart, timeEnd, timeDiff;

    // We store the initial time
    timeStart = clock();

    string endTime = optionalEndTime; // get rid of the const (necessary for a default value of the string)
    if (endTime == "")
        endTime = startTime; // if the endTime was not declared, it takes the same value as startTime

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
                    if (measurement->GetAQIIndex() > 0)
                    { // Verifying that the ATMO Index is valid (getATMOIndex returns -1 in error cases)
                        airQuality += measurement->GetAQIIndex();
                        count++;
                    } // If the ATMO Index was not valid we don't count the measurement
                }
            }
        }
    }
    if (count == 0)
    {
        // We store the final time
        timeEnd = clock();

        // We compute the difference final time - initial time and we convert it into ms
        timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
        cout << "Temps exécution : " << timeDiff << "ms" << endl;
        history.Push_Back(1, timeDiff);
        return 0.0;
    }
    else
    {
        // We store the final time
        timeEnd = clock();

        // We compute the difference final time - initial time and we convert it into ms
        timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
        cout << "Temps exécution : " << timeDiff << "ms" << endl;
        history.Push_Back(1, timeDiff);
        return airQuality / static_cast<float>(count);
    }
}

/*vector<Sensor> ControllerComputation::calculateSimilarityScores(const Database &database, Sensor selectedSensor, const string& startTime, const string& endTime)
{
    set<Sensor> sensors = database.GetSensors();
    vector<Sensor> similarityScores;
    for (auto sensor : sensors)
    {
        if (sensor.GetSensorId() != selectedSensor.GetSensorId()) {
            float costFunctionScore = 0.0;
            for (auto measurement : sensor.GetMeasurements())
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    costFunctionScore += abs(measurement->getValue() - selectedSensor.GetMeasurement()->getValue());
                    similarityScores.push_back({sensor.sensorId, costFunctionScore});
                }
            }
        }
    }
    sort(similarityScores.begin(), similarityScores.end(), [](const SensorMeasurement& a, const SensorMeasurement& b) {
        return a.value < b.value;
    });

    return similarityScores;
}*/

vector<pair<Sensor *, float>> ControllerComputation::calculateSimilarityScores(const Database &database, const Sensor &selectedSensor, const string &startTime, const string &endTime)
{
    map<string, Sensor *> sensors = database.GetSensors();
    vector<pair<Sensor *, float>> similarityScores;

    for (auto sensor : sensors)
    {
        if (sensor.second->GetSensorId() != selectedSensor.GetSensorId())
        {
            float costFunctionScore = 0.0;
            const list<Measurement *> &sensorMeasurements = sensor.second->GetMeasurements();
            const list<Measurement *> &selectedSensorMeasurements = selectedSensor.GetMeasurements();

            for (const Measurement *measurement : sensorMeasurements)
            {
                if (measurement->isWithinTimeRange(startTime, endTime))
                {
                    const Measurement *selectedMeasurement = findMeasurement(selectedSensorMeasurements, measurement->getTimestamp());
                    if (selectedMeasurement != nullptr)
                    {
                        costFunctionScore += abs(selectedMeasurement->getValue() - measurement->getValue());
                    }
                }
            }
            similarityScores.push_back(make_pair(sensor.second, costFunctionScore));
        }
    }
    sort(similarityScores.begin(), similarityScores.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });
    return similarityScores;
}

const Measurement *ControllerComputation::findMeasurement(const list<Measurement *> &measurements, const time_t &timestamp) const
{
    for (const Measurement *measurement : measurements)
    {
        if (measurement->getTimestamp() == timestamp)
        {
            return measurement;
        }
    }
    return nullptr;
}

float ControllerComputation::calculatePreciseAirQualityATMO(const Database &database, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime)
{
    float timeStart, timeEnd, timeDiff;

    // We store the initial time
    timeStart = clock();

    string endTime = optionalEndTime; // get rid of the const (necessary for a default value of the string)
    if (endTime == "")
        endTime = startTime; // if the endTime was not declared, it takes the same value as startTime

    bool sensorFound = false;
    const map<string, Sensor *> &sensors = database.GetSensors();

    for (auto sensor : sensors)
    {
        if (sensor.second->GetLatitude() == centerLat && sensor.second->GetLongitude() == centerLong)
        {
            sensorFound = true;
            float meanValue = calculateMeanATMO(sensor.second->GetMeasurements(), startTime, endTime);

            // We store the final time
            timeEnd = clock();

            // We compute the difference final time - initial time and we convert it into ms
            timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
            cout << "Temps exécution precise air quality atmo : " << timeDiff << "ms" << endl;
            history.Push_Back(2, timeDiff);

            return meanValue;
        }
    }

    if (!sensorFound)
    {
        vector<Sensor *> nearestSensors = kNearestSensors(sensors, centerLat, centerLong, startTime, endTime, 10);
        float weightedSum = 0.0;
        float totalWeight = 0.0;
        for (Sensor *sensor : nearestSensors)
        {
            for (Measurement *measurement : sensor->GetMeasurements())
            {
                float distance = calculateDistance(sensor->GetLatitude(), sensor->GetLongitude(), centerLat, centerLong);
                float weight = 1.0 / distance;
                weightedSum += weight * measurement->GetATMOIndex();
                totalWeight += weight;
            }
        }

        if (totalWeight != 0.0)
        {
            float weightedAverage = weightedSum / totalWeight;

            // We store the final time
            timeEnd = clock();

            // We compute the difference final time - initial time and we convert it into ms
            timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
            cout << "Temps exécution precise air quality atmo : " << timeDiff << "ms" << endl;
            history.Push_Back(2, timeDiff);

            return weightedAverage;
        }
    }

    return -1.0;
}

float ControllerComputation::calculatePreciseAirQualityAQI(const Database &database, float centerLat, float centerLong, const string &startTime, const string &optionalEndTime)
{
    float timeStart, timeEnd, timeDiff;

    // We store the initial time
    timeStart = clock();

    string endTime = optionalEndTime; // get rid of the const (necessary for a default value of the string)
    if (endTime == "")
        endTime = startTime; // if the endTime was not declared, it takes the same value as startTime

    bool sensorFound = false;
    const map<string, Sensor *> &sensors = database.GetSensors();

    for (auto sensor : sensors)
    {
        if (sensor.second->GetLatitude() == centerLat && sensor.second->GetLongitude() == centerLong)
        {
            sensorFound = true;
            float meanValue = calculateMeanAQI(sensor.second->GetMeasurements(), startTime, endTime);

            // We store the final time
            timeEnd = clock();

            // We compute the difference final time - initial time and we convert it into ms
            timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
            cout << "Temps exécution precise air quality aqi : " << timeDiff << "ms" << endl;
            history.Push_Back(2, timeDiff);

            return meanValue;
        }
    }

    if (!sensorFound)
    {
        vector<Sensor *> nearestSensors = kNearestSensors(sensors, centerLat, centerLong, startTime, endTime, 10);
        float weightedSum = 0.0;
        float totalWeight = 0.0;
        for (Sensor *sensor : nearestSensors)
        {
            for (Measurement *measurement : sensor->GetMeasurements())
            {
                float distance = calculateDistance(sensor->GetLatitude(), sensor->GetLongitude(), centerLat, centerLong);
                float weight = 1.0 / distance;
                weightedSum += weight * measurement->GetAQIIndex();
                totalWeight += weight;
            }
        }

        if (totalWeight != 0.0)
        {
            float weightedAverage = weightedSum / totalWeight;

            // We store the final time
            timeEnd = clock();

            // We compute the difference final time - initial time and we convert it into ms
            timeDiff = (timeEnd - timeStart) / (CLOCKS_PER_SEC / 1000);
            cout << "Temps exécution precise air quality aqi : " << timeDiff << "ms" << endl;
            history.Push_Back(2, timeDiff);

            return weightedAverage;
        }
    }

    return -1.0;
}

vector<Sensor *> ControllerComputation::kNearestSensors(const map<string, Sensor *> &sensors, float centerLat, float centerLong, const string &startTime, const string &endTime, int k)
{
    vector<pair<Sensor *, float>> sensordistances;

    for (auto sensor : sensors)
    {
        for (Measurement *measurement : sensor.second->GetMeasurements())
        {
            if (measurement->isWithinTimeRange(startTime, endTime))
            {
                float distance = calculateDistance(sensor.second->GetLatitude(), sensor.second->GetLongitude(), centerLat, centerLong);
                sensordistances.push_back({const_cast<Sensor *>(sensor.second), distance});
            }
        }
    }

    sort(sensordistances.begin(), sensordistances.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    vector<Sensor *> kNearestSensors;
    int numSensors = min(k, static_cast<int>(sensordistances.size()));

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

    float a = sin(dLat / 2) * sin(dLat / 2) +
              cos(degToRad(lat1)) * cos(degToRad(lat2)) *
                  sin(dLong / 2) * sin(dLong / 2);

    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = EARTH_RADIUS * c;

    return distance;
}

float ControllerComputation::calculateMeanATMO(const list<Measurement *> &measurements, const string &startTime, const string &endTime)
{
    int count = 0;
    float sum = 0.0;

    for (Measurement *measurement : measurements)
    {
        if (measurement->isWithinTimeRange(startTime, endTime))
        {
            sum += measurement->GetATMOIndex();
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

float ControllerComputation::calculateMeanAQI(const list<Measurement *> &measurements, const string &startTime, const string &endTime)
{
    int count = 0;
    float sum = 0.0;

    for (Measurement *measurement : measurements)
    {
        if (measurement->isWithinTimeRange(startTime, endTime))
        {
            sum += measurement->GetAQIIndex();
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

// version 2 -> ne pas effacer, l'autre version est encore en tests
pair<vector<Sensor *>, vector<vector<float>>> ControllerComputation::detectDefectSensorsAndOutliers(const Database &database, const string &startTime, const string &endTime)
{
    const map<string, Sensor *> &sensors = database.GetSensors();
    vector<Sensor *> defectSensors;
    vector<vector<float>> outliers;
    vector<float> allMeasurements;

    for (auto &sensor : sensors)
    {
        for (Measurement *measurement : sensor.second->GetMeasurements())
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
                // allMeasurements.push_back(measurement->getValue());
            }
        }
    }

    if (!allMeasurements.empty())
    {
        float mean, stdDev;
        calculateMeanAndStdDev(allMeasurements, mean, stdDev);

        const float lowerThreshold = calculatePercentile(allMeasurements, 1);
        const float upperThreshold = calculatePercentile(allMeasurements, 99);

        for (auto &sensor : sensors)
        {
            vector<float> filteredValues;
            vector<float> sensorOutliers;
            bool sensorDefect = false;
            for (Measurement *measurement : sensor.second->GetMeasurements())
            {
                if (!(startTime.empty()) && !(endTime.empty()))
                {
                    if (measurement->isWithinTimeRange(startTime, endTime))
                    {
                        float value = measurement->getValue();

                        if ((value < lowerThreshold || value > upperThreshold) && (value < mean - 4 * stdDev || value > mean + 4 * stdDev))
                        {
                            sensorOutliers.push_back(value);
                            sensorDefect = true;
                        }
                    }
                }
            }
            if (sensorDefect)
            {
                defectSensors.push_back(sensor.second);
                outliers.push_back(sensorOutliers);
            }
        }
    }
    return make_pair(defectSensors, outliers);
}
/*
//Pas encore fonctionnel mais pas necessaire pour le projet
pair<vector<shared_ptr<Sensor>>, vector<vector<float>>> ControllerComputation::detectDefectSensorsAndOutliers2(const Database &database, const string &startTime, const string &endTime)
{
    const map<string, shared_ptr<Sensor>>& sensors = database.GetSensors();
    vector<shared_ptr<Sensor>> defectSensors;
    vector<vector<float>> outliers;

    const float lowerThreshold = calculatePercentileFromDatabase(database, 2, startTime, endTime);
    const float upperThreshold = calculatePercentileFromDatabase(database, 98, startTime, endTime);

    for (const auto &sensorPair : sensors)
    {
        const shared_ptr<Sensor>& sensor = sensorPair.second;
        vector<float> outlierValues;
        bool sensorDefect = false;

        for (Measurement *measurement : sensor->GetMeasurements())
        {
            if (startTime.empty() || endTime.empty() || measurement->isWithinTimeRange(startTime, endTime))
            {
                float value = measurement->getValue();
                if (value < lowerThreshold || value > upperThreshold)
                {
                    outlierValues.push_back(value);
                    sensorDefect = true;
                }
            }
        }

        if (sensorDefect)
        {
            defectSensors.push_back(sensor);
            outliers.push_back(outlierValues);
        }
    }

    return make_pair(defectSensors, outliers);
}*/

/*
pair<vector<Sensor>, vector<vector<float>>> ControllerComputation::detectDefectSensorsAndOutliers(const Database& database, const optional<string>& startTime, const optional<string>& endTime)
{
    const set<Sensor>& sensors = database.GetSensors();
    vector<Sensor> defectSensors;
    vector<vector<float>> outliers;

    for (const Sensor& sensor : sensors)
    {
        vector<float> filteredValues;

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
            vector<float> sensorOutliers;

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

    return make_pair(defectSensors, outliers);
}
*/

void ControllerComputation::calculateMeanAndStdDev(const vector<float> &values, float &mean, float &stdDev)
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
        variance += pow(value - mean, 2);
    }

    stdDev = sqrt(variance / count);
}

float ControllerComputation::calculatePercentile(const vector<float> &values, int percentile)
{
    if (values.empty())
    {
        return 0.0;
    }

    vector<float> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());

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

/*
float ControllerComputation::calculatePercentileFromDatabase(const Database& database, int percentile, const string& startTime, const string& endTime)
{
    vector<float> allMeasurements;

    for (const auto& sensorPair : database.GetSensors())
    {
        const Sensor* sensor = sensorPair.second;
        for (const Measurement* measurement : sensor->GetMeasurements())
        {
            if (startTime.empty() || endTime.empty() || measurement->isWithinTimeRange(startTime, endTime))
            {
                allMeasurements.push_back(measurement->getValue());
            }
        }
    }

    if (allMeasurements.empty())
    {
        return 0.0f;
    }

    sort(allMeasurements.begin(), allMeasurements.end());

    int index = (percentile * (allMeasurements.size() - 1)) / 100;

    return allMeasurements[index];
}*/

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
