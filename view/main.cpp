/*#include "Attributes.h"
#include "Cleaner.h"
#include "Database.h"
#include "GovernmentAgency.h"
#include "Measurement.h"
#include "PrivateUser.h"
#include "Provider.h"
#include "Sensor.h"
#include "User.h" */
#include "../model/Sensor.h"
#include "../model/Attributes.h"
#include <ctime>
#include <iostream>
#include <cstring>
#include<string>

using namespace std;


int main() {

    Sensor* s = new Sensor(1, 44.0, -1.0);

    //Measurement* m = new Measurement();

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

    // Utiliser le timestamp
    cout << "Le timestamp est : " << timestamp << endl;

    cout << "hello new version here" << endl;

    return 0;
}
