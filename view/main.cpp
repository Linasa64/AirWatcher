/*
#include "Cleaner.h"
#include "Database.h""

 */
#include "../model/Measurement.h"
#include "../model/User.h"
#include "../model/GovernmentAgency.h"
#include "../model/Provider.h"
#include "../model/PrivateUser.h"
#include "../model/Sensor.h"
#include "../model/Attributes.h"
#include <ctime>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


int main() {

    // TEMPS
    float timeStart, timeEnd, timeDiff;

    // On stocke le temps initial
    timeStart = clock();

    Sensor* s = new Sensor(1, 44.0, -1.0);

    cout << *s;

    User *user[] =
    {
        new Provider("Provider0"),
        new PrivateUser("User1"),
        new GovernmentAgency()
    };

    for (int i = 0 ; i < 3 ; i++) {
        cout << "User " << i << ": " << user[i]->GetId() << endl;
    }

    

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

    Attributes* a = new Attributes("O3", "µg/m3", "concentration d'ozone");
    Measurement* m = new Measurement(now, 53.25, *a);

    cout << "Attributes a : " << *a;
    cout << "Measurement m : " << *m;

    // Utiliser le timestamp
    cout << "Le timestamp est : " << timestamp << endl;

    cout << "Maintenant : " << now << endl;

    cout << "hello new version here" << endl;

    // On stocke le temps final
    timeEnd = clock();

    // On fait la différence temps final - temps initial et on met en ms
    timeDiff = (timeEnd - timeStart)/(CLOCKS_PER_SEC/1000);
    cout << "Temps exécution : " << timeDiff << "ms" << endl;

    return 0;
}
